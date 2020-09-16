#include "NotificationCallbackThread.h"

namespace StateMachineController {

/*NotificationCallbackThread::NotificationCallbackThread(class V2_StateMachineController *smc, int sim_mode)
	: _smc(smc), _running(false), _isSingleShot(false), _sim_mode(sim_mode) {
}*/

NotificationCallbackThread::NotificationCallbackThread(class V2_StateMachineController& smc, int sim_mode)
	: _smc(smc), _running(false), _isSingleShot(false), _sim_mode(sim_mode) {
}


NotificationCallbackThread::~NotificationCallbackThread()
{
	if(_thread.joinable())
	{
		cout<<"Joining the Thread..."<<endl;
		_thread.join();
	}
}

void NotificationCallbackThread::start(bool multiThread)
{
    if (this->running() == true)
        return;

    _running = true;

    if (multiThread == true) {
        _thread = std::thread(
                    &NotificationCallbackThread::_temporize, this);
    }
    else{
        this->_temporize();
    }
}

void NotificationCallbackThread::stop()
{
    _running = false;
if(_thread.joinable())
{
	cout<<"Joining the Thread..."<<endl;
	_thread.join();
}
}

bool NotificationCallbackThread::running() const
{
    return _running;
}

void NotificationCallbackThread::setSingleShot(bool singleShot)
{
    if (this->running() == true)
       return;

    _isSingleShot = singleShot;
}

bool NotificationCallbackThread::isSingleShot() const
{
    return _isSingleShot;
}

void NotificationCallbackThread::setInterval(const NotificationCallbackThread::Interval &interval)
{
    if (this->running() == true)
       return;

    _interval = interval;
}

const NotificationCallbackThread::Interval &NotificationCallbackThread::interval() const
{
    return _interval;
}

void NotificationCallbackThread::_temporize()
{
    if (_isSingleShot == true) {
        this->_sleepThenTimeout();
    }
    else {
        while (this->running() == true) {
            this->_sleepThenTimeout();
        }
    }
}

/*void NotificationCallbackThread::_sleepThenTimeout()
{
    std::this_thread::sleep_for(_interval);
    
	if(_sim_mode == SERVER_STUB) {
		if (this->running() == true) {
			// This has no use until notifications are also in the input params.
			_smc->c.selectParameterContext();
			_smc->executeInternalTransitions();
		}
	}
	else if(_sim_mode == CLIENT_STUB) {
		if (this->running() == true) {
			_smc->c.selectParameterContext();
			_smc->executeAvailableCommandsAndSignalsInState();
		}
	}
	else
	{
		if (this->running() == true)
		{
			//_smc->executeAvailableCommandsAndSignalsInState();
			//_smc->executeInternalTransitions();
		}
	}
}*/

void NotificationCallbackThread::_sleepThenTimeout()
{
    std::this_thread::sleep_for(_interval);
    
	if(_sim_mode == SERVER_STUB) {
		if (this->running() == true) {
			// This has no use until notifications are also in the input params.
			//_smc->c.selectParameterContext();
			//_smc->executeInternalTransitions();
			_smc.c.selectParameterContext();
			_smc.executeInternalTransitions();
		}
	}
	else if(_sim_mode == CLIENT_STUB) {
		if (this->running() == true) {
			_smc.c.selectParameterContext();
			_smc.executeAvailableCommandsAndSignalsInState();
		}
	}
	else
	{
		if (this->running() == true)
		{
			//_smc->executeAvailableCommandsAndSignalsInState();
			//_smc->executeInternalTransitions();
		}
	}
}
}
