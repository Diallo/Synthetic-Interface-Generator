#include "V2_StateMachineController.h"
#ifdef CLIENT_STUB_API
#include "V2StubAdapterImpl.h"
#endif

namespace StateMachineController {

#ifdef SSCF_VERSION
V2_StateMachineController::V2_StateMachineController(
					class EventRepository *er,
					class UNDEFINED::V2Server *srv, int sim_mode) {
	m_eventRepo = er;
	m_serverPtr = srv;
	current = new p1_1();
	
	publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_niHandler = nullptr;




	// timer = new NotificationCallbackThread(this);
	timer = new NotificationCallbackThread(*this, sim_mode);
	timer->setSingleShot(false);
	timer->setInterval(NotificationCallbackThread::Interval(10*1000));
	timer->start(true);
	
	#ifdef CLIENT_STUB_API
	client_api_handler = new EventAPIHandlerImpl(*this);
	// isCBActive = false;
	
	// Register call backs to the state machine controller
	client_api_handler->getNIHandler().register_outTRp1_2_12_CBHandler(&StateMachineController::V2_StateMachineController::outTRp1_2_12_clHandler);
	client_api_handler->getNIHandler().register_outTRp1_1_15_CBHandler(&StateMachineController::V2_StateMachineController::outTRp1_1_15_clHandler);
	client_api_handler->getNIHandler().register_outTRp1_1_16_CBHandler(&StateMachineController::V2_StateMachineController::outTRp1_1_16_clHandler);
	client_api_handler->getNIHandler().register_outTRp1_6_19_CBHandler(&StateMachineController::V2_StateMachineController::outTRp1_6_19_clHandler);
	client_api_handler->getNIHandler().register_outTRp1_8_21_CBHandler(&StateMachineController::V2_StateMachineController::outTRp1_8_21_clHandler);
	client_api_handler->getNIHandler().register_outTRp1_6_22_CBHandler(&StateMachineController::V2_StateMachineController::outTRp1_6_22_clHandler);
	client_api_handler->getNIHandler().register_outTRp1_9_23_CBHandler(&StateMachineController::V2_StateMachineController::outTRp1_9_23_clHandler);
	#endif
	
	run_simulation = true;
	// std::cout<<std::endl<<"INFO: State Machine Controller has been Constructed!"<<std::endl;
	// std::cout<<"INFO: Notification Callback Thread is Running..."<<std::endl;
}
#endif
#ifndef SSCF_VERSION
#ifdef SSCF_CLIENT_STUB_ADAPTER
V2_StateMachineController::V2_StateMachineController(class EventRepository *er, int sim_mode, 
	SscfClientConnection<UNDEFINED::V2Proxy, UNDEFINED::V2>& m_connection) {
#endif
#ifndef SSCF_CLIENT_STUB_ADAPTER
V2_StateMachineController::V2_StateMachineController(class EventRepository *er, int sim_mode) {
#endif
	m_eventRepo = er;
	current = new p1_1();
	
	publishToEventRepo(m_eventRepo);

	m_idle = true;
	m_niHandler = nullptr;


	// timer = new NotificationCallbackThread(this, sim_mode);
	timer = new NotificationCallbackThread(*this, sim_mode);
	timer->setSingleShot(false);
	timer->setInterval(NotificationCallbackThread::Interval(10*1000));
	timer->start(true);

	#ifdef CLIENT_STUB_API
	
	#ifndef SSCF_CLIENT_STUB_ADAPTER
	client_api_handler = new EventAPIHandlerImpl(*this);
	// isCBActive = false;
	#endif
	
	#ifdef SSCF_CLIENT_STUB_ADAPTER
	client_api_handler = new EventAPIHandlerImpl(*this, m_connection);
	// isCBActive = false;
	#endif
	
	// Register call backs to the state machine controller
	client_api_handler->getNIHandler().register_outTRp1_2_12_CBHandler(&StateMachineController::V2_StateMachineController::outTRp1_2_12_clHandler);
	client_api_handler->getNIHandler().register_outTRp1_1_15_CBHandler(&StateMachineController::V2_StateMachineController::outTRp1_1_15_clHandler);
	client_api_handler->getNIHandler().register_outTRp1_1_16_CBHandler(&StateMachineController::V2_StateMachineController::outTRp1_1_16_clHandler);
	client_api_handler->getNIHandler().register_outTRp1_6_19_CBHandler(&StateMachineController::V2_StateMachineController::outTRp1_6_19_clHandler);
	client_api_handler->getNIHandler().register_outTRp1_8_21_CBHandler(&StateMachineController::V2_StateMachineController::outTRp1_8_21_clHandler);
	client_api_handler->getNIHandler().register_outTRp1_6_22_CBHandler(&StateMachineController::V2_StateMachineController::outTRp1_6_22_clHandler);
	client_api_handler->getNIHandler().register_outTRp1_9_23_CBHandler(&StateMachineController::V2_StateMachineController::outTRp1_9_23_clHandler);
	#endif

	run_simulation = true;
	// std::cout<<std::endl<<"INFO: State Machine Controller has been Constructed!"<<std::endl;
	// std::cout<<"INFO: Notification Callback Thread has been Constructed!"<<std::endl;
}
#endif
#ifdef QT_GUI
V2_StateMachineController::V2_StateMachineController(class EventRepository *er, class MainWindow *mw, int sim_mode) {
	m_eventRepo = er;
	m_mw = mw; 
	current = new p1_1();
	
	//publishToEventRepo(m_eventRepo);

	m_idle = true;
	m_niHandler = nullptr;

			
	//timer = new NotificationCallbackThread(this, sim_mode);
	timer = new NotificationCallbackThread(*this, sim_mode);
	timer->setSingleShot(false);
	timer->setInterval(NotificationCallbackThread::Interval(10*1000));
	timer->start(true);

	#ifdef CLIENT_STUB_API
	client_api_handler = new EventAPIHandlerImpl(*this);
	// isCBActive = false;
	
	// Register call backs to the state machine controller
	client_api_handler->getNIHandler().register_outTRp1_2_12_CBHandler(&StateMachineController::V2_StateMachineController::outTRp1_2_12_clHandler);
	client_api_handler->getNIHandler().register_outTRp1_1_15_CBHandler(&StateMachineController::V2_StateMachineController::outTRp1_1_15_clHandler);
	client_api_handler->getNIHandler().register_outTRp1_1_16_CBHandler(&StateMachineController::V2_StateMachineController::outTRp1_1_16_clHandler);
	client_api_handler->getNIHandler().register_outTRp1_6_19_CBHandler(&StateMachineController::V2_StateMachineController::outTRp1_6_19_clHandler);
	client_api_handler->getNIHandler().register_outTRp1_8_21_CBHandler(&StateMachineController::V2_StateMachineController::outTRp1_8_21_clHandler);
	client_api_handler->getNIHandler().register_outTRp1_6_22_CBHandler(&StateMachineController::V2_StateMachineController::outTRp1_6_22_clHandler);
	client_api_handler->getNIHandler().register_outTRp1_9_23_CBHandler(&StateMachineController::V2_StateMachineController::outTRp1_9_23_clHandler);
	#endif

	run_simulation = true;
	// std::cout<<std::endl<<"INFO: State Machine Controller has been Constructed!"<<std::endl;
	// std::cout<<"INFO: Notification Callback Thread has been Constructed!"<<std::endl;
}		
#endif
V2_StateMachineController::~V2_StateMachineController() 
{
	// TODO delete all state machine variables! Memory Leak
	timer->stop();
	if(timer != nullptr)
	{
		std::cout<< std::endl <<"Destroying Callback Thread Instance! "<<std::endl;
		delete timer;
		timer = nullptr;
	}
	delete current;
	std::cout<< std::endl <<"Destroyed State Machine Controller! "<<std::endl;
}

void V2_StateMachineController::setSimMode(int sim_mode) 
{ 
	timer->setSimMode(sim_mode);
	publishToEventRepo(m_eventRepo);
}

void V2_StateMachineController::toggleSimulation(bool print_vars)
{
	if(run_simulation) { 
		run_simulation = false;
		std::cout<<std::endl<<"Stopping Simulation..."<<std::endl;
		if(print_vars) displaySMVars();
	}
	else {
		run_simulation = true;
		std::cout<<std::endl<<"Starting Simulation..."<<std::endl;
		#ifndef QT_GUI
		publishToEventRepo(m_eventRepo);
		//event_status_msg.clear();
		#endif
	}
}

void V2_StateMachineController::setTextColor(string col)
{
}

string V2_StateMachineController::getCurrentState()
{
	return current->getCurrentState();
}

list<string> V2_StateMachineController::getCurrentCommandStatusList()
{
	return current->getCurrentCommandStatusList();
}

list<string> V2_StateMachineController::getCurrentSignalStatusList()
{
	return current->getCurrentSignalStatusList();
}

list<string> V2_StateMachineController::getCurrentNotificationStatusList()
{
	return current->getCurrentNotificationStatusList();
}

void V2_StateMachineController::publishToEventRepo(EventRepository *er)
{
	if(er!=nullptr)
	{
		er->setEventsMap(	getCurrentCommandStatusList(),
							getCurrentSignalStatusList(),
							getCurrentNotificationStatusList(),
							event_status_msg
							);
	}
	#ifdef QT_GUI
	if(m_mw!=nullptr)
	{
		m_mw->setEventsMap(	getCurrentState(),
							c.getLoggedGUIMsgs(),
							getCurrentCommandStatusList(),
							getCurrentSignalStatusList(),
							getCurrentNotificationStatusList(),
							event_status_msg
							);
		
	}
	#endif
}

void V2_StateMachineController::executeAvailableCommandsAndSignalsInState()
{
	if(run_simulation)
	{
		// std::cout<<"INFO@Thread_Callback_Method: Checking Lock Available..."<<std::endl;
		std::unique_lock<std::mutex> mlock(m_mutex);
		if (!isIdle())
		{
			m_condVar.wait(mlock, std::bind(&V2_StateMachineController::isIdle, this));
		}
		// std::cout<<"INFO@Thread_Callback_Method: Acquired Lock!"<<std::endl;
		
		#ifdef CLIENT_STUB_API
		// isCBActive = true;
		// Added: DB
		// m_idle = false;
		// m_condVar.notify_all();

		if(isNotificationExpected)
		{
			std::cout << "FATAL: The Controller has Detected a Race Condition!" << std::endl;
			//throw (StubException("EXCEPTION: RACE CONDITION DETECTED!", RACE_CONDITION));
		}
		if(isNotificationInProcess)
		{
			std::cout << "BUSY: Notification is being Processed, Skipping Event Call!" << std::endl;
			return;
		}
		#endif
		
		if(current->checkEnabledCommandAndSignalInState(this))
		{
			// std::cout << std::endl << "INFO@Thread_Callback_Method: Possible Commands/Signals in State!" << std::endl;
			event_status_msg.clear();
			try {
				current->executeAvailableCommandsAndSignalsInState(this);
			} catch (const StateMachineController::StubException& e) {
				// so that future notifications can be processed.
				std::cout<< "Clearing All Pending Notifications..." << std::endl;
				#ifdef CLIENT_STUB_API
				client_api_handler->closeEventContext();
				#endif
				std::cout << e.what() << std::endl;
			}
			publishToEventRepo(m_eventRepo);
		}
		// else std::cout<<"INFO: No possible notifications in State!"<<std::endl;
		
		#ifdef CLIENT_STUB_API
		// Added: DB
		// m_idle = true;
		// m_condVar.notify_all();
		// isCBActive = false;
		#endif
	}
}

void V2_StateMachineController::executeInternalTransitions()
{
	if(run_simulation) 
	{
		// std::cout<<"INFO@Thread_Callback_Method: Checking Lock Available..."<<std::endl;
		std::unique_lock<std::mutex> mlock(m_mutex);
		if(!isIdle())
		{
			m_condVar.wait(mlock, std::bind(&V2_StateMachineController::isIdle, this));
		}
		// std::cout<<"INFO@Thread_Callback_Method: Acquired Lock!"<<std::endl;
		
		if(current->isNotificationPossibleInState(this))
		{
			// std::cout<<std::endl<<"INFO@Thread_Callback_Method: Possible notifications in State!"<<std::endl;
			event_status_msg.clear();
			current->executeInternalTransitions(this);
			// This prevents UI output when an excluded notification was found!
			if(!event_status_msg.empty()) publishToEventRepo(m_eventRepo);
		}
		// else std::cout<<"INFO: No possible notifications in State!"<<std::endl;
	}
}

bool V2_StateMachineController::isIdle()
{
	return m_idle;
}

void V2_StateMachineController::displaySMVars()
{
	setTextColor("EVENT");
	std::cout<<"---------------------------------------------"<<std::endl;
	std::cout<<"CURRENT STATE: "<<getCurrentState()<<std::endl;
	std::cout<<"---------------------------------------------"<<std::endl;


	setTextColor("DATA");
	std::cout<<"---------------------------------------------"<<std::endl;
	std::cout<<"No State Variables to Display..."<<std::endl;
	std::cout<<"---------------------------------------------"<<std::endl;
    #ifdef QT_GUI
    event_status_msg.clear();
    c.clearLoggedMsgs();
    #endif
	setTextColor("ANY");
	#ifdef QT_GUI
	publishToEventRepo(m_eventRepo);
	event_status_msg.clear();
	#endif
}

// Command Definition

// Signal Definition
void V2_StateMachineController::_V2_inTRp1_1_11()
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	current->V2_inTRp1_1_11(this);
	publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
}

void V2_StateMachineController::_V2_inTRp1_1_11(int instance_id, int clause_id)
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	current->V2_inTRp1_1_11(this, instance_id, clause_id);
	publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
}

bool V2_StateMachineController::isEnabledV2_inTRp1_1_11(int instance_id)
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();

	event_status_msg.clear();

	bool is_instance_enabled = current->isEnabledV2_inTRp1_1_11(this, instance_id);

	event_status_msg.clear();
	//publishToEventRepo(m_eventRepo);

	m_idle = true;
	m_condVar.notify_one();

	return is_instance_enabled;
	}
void V2_StateMachineController::_V2_inTRp1_3_13()
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	current->V2_inTRp1_3_13(this);
	publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
}

void V2_StateMachineController::_V2_inTRp1_3_13(int instance_id, int clause_id)
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	current->V2_inTRp1_3_13(this, instance_id, clause_id);
	publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
}

bool V2_StateMachineController::isEnabledV2_inTRp1_3_13(int instance_id)
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();

	event_status_msg.clear();

	bool is_instance_enabled = current->isEnabledV2_inTRp1_3_13(this, instance_id);

	event_status_msg.clear();
	//publishToEventRepo(m_eventRepo);

	m_idle = true;
	m_condVar.notify_one();

	return is_instance_enabled;
	}
void V2_StateMachineController::_V2_inTRp1_4_14()
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	current->V2_inTRp1_4_14(this);
	publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
}

void V2_StateMachineController::_V2_inTRp1_4_14(int instance_id, int clause_id)
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	current->V2_inTRp1_4_14(this, instance_id, clause_id);
	publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
}

bool V2_StateMachineController::isEnabledV2_inTRp1_4_14(int instance_id)
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();

	event_status_msg.clear();

	bool is_instance_enabled = current->isEnabledV2_inTRp1_4_14(this, instance_id);

	event_status_msg.clear();
	//publishToEventRepo(m_eventRepo);

	m_idle = true;
	m_condVar.notify_one();

	return is_instance_enabled;
	}
void V2_StateMachineController::_V2_inTRp2_1_17()
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	current->V2_inTRp2_1_17(this);
	publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
}

void V2_StateMachineController::_V2_inTRp2_1_17(int instance_id, int clause_id)
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	current->V2_inTRp2_1_17(this, instance_id, clause_id);
	publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
}

bool V2_StateMachineController::isEnabledV2_inTRp2_1_17(int instance_id)
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();

	event_status_msg.clear();

	bool is_instance_enabled = current->isEnabledV2_inTRp2_1_17(this, instance_id);

	event_status_msg.clear();
	//publishToEventRepo(m_eventRepo);

	m_idle = true;
	m_condVar.notify_one();

	return is_instance_enabled;
	}
void V2_StateMachineController::_V2_inTRp3_1_18()
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	current->V2_inTRp3_1_18(this);
	publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
}

void V2_StateMachineController::_V2_inTRp3_1_18(int instance_id, int clause_id)
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	current->V2_inTRp3_1_18(this, instance_id, clause_id);
	publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
}

bool V2_StateMachineController::isEnabledV2_inTRp3_1_18(int instance_id)
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();

	event_status_msg.clear();

	bool is_instance_enabled = current->isEnabledV2_inTRp3_1_18(this, instance_id);

	event_status_msg.clear();
	//publishToEventRepo(m_eventRepo);

	m_idle = true;
	m_condVar.notify_one();

	return is_instance_enabled;
	}
// Notifications: This should only be used by Server GUI
// Extension Feature for Client State Machine
void V2_StateMachineController::_V2_outTRp1_2_12()
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	current->V2_outTRp1_2_12(this);
	publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
}
void V2_StateMachineController::_V2_outTRp1_1_15()
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	current->V2_outTRp1_1_15(this);
	publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
}
void V2_StateMachineController::_V2_outTRp1_1_16()
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	current->V2_outTRp1_1_16(this);
	publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
}
void V2_StateMachineController::_V2_outTRp1_6_19()
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	current->V2_outTRp1_6_19(this);
	publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
}
void V2_StateMachineController::_V2_outTRp1_8_21()
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	current->V2_outTRp1_8_21(this);
	publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
}
void V2_StateMachineController::_V2_outTRp1_6_22()
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	current->V2_outTRp1_6_22(this);
	publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
}
void V2_StateMachineController::_V2_outTRp1_9_23()
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	current->V2_outTRp1_9_23(this);
	publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
}

void V2_StateMachineController::_V2_outTRp1_2_12(int instance_id, int clause_id)
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	current->V2_outTRp1_2_12(this, instance_id, clause_id);
	publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
}
void V2_StateMachineController::_V2_outTRp1_1_15(int instance_id, int clause_id)
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	current->V2_outTRp1_1_15(this, instance_id, clause_id);
	publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
}
void V2_StateMachineController::_V2_outTRp1_1_16(int instance_id, int clause_id)
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	current->V2_outTRp1_1_16(this, instance_id, clause_id);
	publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
}
void V2_StateMachineController::_V2_outTRp1_6_19(int instance_id, int clause_id)
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	current->V2_outTRp1_6_19(this, instance_id, clause_id);
	publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
}
void V2_StateMachineController::_V2_outTRp1_8_21(int instance_id, int clause_id)
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	current->V2_outTRp1_8_21(this, instance_id, clause_id);
	publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
}
void V2_StateMachineController::_V2_outTRp1_6_22(int instance_id, int clause_id)
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	current->V2_outTRp1_6_22(this, instance_id, clause_id);
	publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
}
void V2_StateMachineController::_V2_outTRp1_9_23(int instance_id, int clause_id)
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	current->V2_outTRp1_9_23(this, instance_id, clause_id);
	publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
}

std::vector<int> V2_StateMachineController::_match_V2_outTRp1_2_12(std::vector<std::string>  list_of_rcvd_notifications)
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	std::vector<int> matched_instance_clause_id = current->match_V2_outTRp1_2_12(this, list_of_rcvd_notifications);
	event_status_msg.clear();
	//publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
	return matched_instance_clause_id;
}
std::vector<int> V2_StateMachineController::_match_V2_outTRp1_1_15(std::vector<std::string>  list_of_rcvd_notifications)
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	std::vector<int> matched_instance_clause_id = current->match_V2_outTRp1_1_15(this, list_of_rcvd_notifications);
	event_status_msg.clear();
	//publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
	return matched_instance_clause_id;
}
std::vector<int> V2_StateMachineController::_match_V2_outTRp1_1_16(std::vector<std::string>  list_of_rcvd_notifications)
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	std::vector<int> matched_instance_clause_id = current->match_V2_outTRp1_1_16(this, list_of_rcvd_notifications);
	event_status_msg.clear();
	//publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
	return matched_instance_clause_id;
}
std::vector<int> V2_StateMachineController::_match_V2_outTRp1_6_19(std::vector<std::string>  list_of_rcvd_notifications)
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	std::vector<int> matched_instance_clause_id = current->match_V2_outTRp1_6_19(this, list_of_rcvd_notifications);
	event_status_msg.clear();
	//publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
	return matched_instance_clause_id;
}
std::vector<int> V2_StateMachineController::_match_V2_outTRp1_8_21(std::vector<std::string>  list_of_rcvd_notifications)
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	std::vector<int> matched_instance_clause_id = current->match_V2_outTRp1_8_21(this, list_of_rcvd_notifications);
	event_status_msg.clear();
	//publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
	return matched_instance_clause_id;
}
std::vector<int> V2_StateMachineController::_match_V2_outTRp1_6_22(std::vector<std::string>  list_of_rcvd_notifications)
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	std::vector<int> matched_instance_clause_id = current->match_V2_outTRp1_6_22(this, list_of_rcvd_notifications);
	event_status_msg.clear();
	//publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
	return matched_instance_clause_id;
}
std::vector<int> V2_StateMachineController::_match_V2_outTRp1_9_23(std::vector<std::string>  list_of_rcvd_notifications)
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	std::vector<int> matched_instance_clause_id = current->match_V2_outTRp1_9_23(this, list_of_rcvd_notifications);
	event_status_msg.clear();
	//publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
	return matched_instance_clause_id;
}




/*********** Concrete State Class: p1_1 ***********/

list<string> p1_1::getCurrentCommandStatusList() 
{
	list<string> retStr;
	return retStr;
}

list<string> p1_1::getCurrentSignalStatusList()
{
	list<string> retStr;
	return retStr;
}
		
list<string> p1_1::getCurrentNotificationStatusList()
{
	list<string> retStr;
	retStr.push_back("V2_outTRp1_1_16");
	retStr.push_back("V2_outTRp1_1_15");
	return retStr;
}

string p1_1::getCurrentState() { return name; }

list<string> p1_1::isAtleastOneEnabledCommand(V2_StateMachineController *smc)
{
	list<string> list_of_enabled_commands;
	//StateMachineController::InputParametersContainer c;
	return list_of_enabled_commands;
}
list<string> p1_1::isAtleastOneEnabledSignal(V2_StateMachineController *smc)
{
	list<string> list_of_enabled_signals;
	//StateMachineController::InputParametersContainer c;
	return list_of_enabled_signals;
}

void p1_1::executeAvailableCommandsAndSignalsInState(V2_StateMachineController *smc)
{
	//StateMachineController::InputParametersContainer c;
	list<string> list_of_enabled_commands_and_signals = determineEnabledCommandAndSignalInState(smc);
	if(checkEnabledCommandAndSignalInState(smc))
	{
		std::list<string>::iterator it = list_of_enabled_commands_and_signals.begin();
		
		// Choose a random element from the list
		std::advance(it, rand() %list_of_enabled_commands_and_signals.size());

		// TODO: Do not match reply(*). Find out how to do this.
		#ifdef CLIENT_STUB_API

		#endif
		
		#ifndef CLIENT_STUB_API
		#endif
	}
	else
	{
		std::cout<<std::endl<<"ERROR: No Enabled Commands or Signals in State: p1_1"<<std::endl;
		//throw (StubException("EXCEPTION: No Enabled Commands or Signals in State: p1_1", NO_ENABLED_GUARDS));
	}
}

bool p1_1::checkEnabledCommandAndSignalInState(V2_StateMachineController *smc)
{
	if(determineEnabledCommandAndSignalInState(smc).empty())
			return false;
		else
			return true;
}

list<string> p1_1::determineEnabledCommandAndSignalInState(V2_StateMachineController *smc)
{
	list<string> enabled_commands_and_signals_list = isAtleastOneEnabledCommand(smc);
	enabled_commands_and_signals_list.splice(enabled_commands_and_signals_list.end(), isAtleastOneEnabledSignal(smc));
	return enabled_commands_and_signals_list;
}


bool p1_1::isAtleastOneEnabledNotification(V2_StateMachineController *smc)
{
	if( true ||   true )
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Concrete Deterministic Notification Handler: V2_outTRp1_1_16
void p1_1::V2_outTRp1_1_16(V2_StateMachineController *smc, int instance_id, int clause_id)
{
	bool isAtleastOneGuardEnabled = false;
	int instance_choice = instance_id;
	switch(instance_choice)
	{
		case 0: 
			// Guard Expression
			if(true)
			{
				isAtleastOneGuardEnabled = true;
				int clause_choice = clause_id;
					switch(clause_choice)
					{
					case 0:
							{
							// std::cout<<"Raising Notification: V2_outTRp1_1_16 -> Going From p1_1 to p3_1"<<std::endl;
							// smc->event_status_msg.push_back("State Changed: p1_1 => p3_1");
							#ifdef QT_GUI
								smc->event_status_msg.push_back(" <<<<<<<< Notification Raised: V2_outTRp1_1_16");
								smc->event_status_msg.push_back(" <!> State Update: p1_1 => p3_1");
							#endif
							smc->setTextColor("EVENT");
							std::cout<<std::endl<<" <<<<<<<< Notification Raised: V2_outTRp1_1_16"<<std::endl;
							std::cout<<" <!> State Update: p1_1 => p3_1"<<std::endl;
							smc->setTextColor("DATA");
							smc->setTextColor("ANY");
							smc->setCurrent(new p3_1());
							delete this;
							break;
							}
					default: 	std::cout<<"ERROR: Invalid random choice of Notification Clause!"<<std::endl;
								//throw (StubException("EXCEPTION: Invalid random choice of Notification Clause!", LOGICAL_ERROR));
								break;
					}// End of clause switch-case
			}
			break;
		default: 	std::cout<<"ERROR: Invalid random choice of Notification Instance!"<<std::endl;
					//throw (StubException("EXCEPTION: Invalid random choice of Notification Instance!", LOGICAL_ERROR));
					break;
	}// End of instance switch-case
	
	if(!isAtleastOneGuardEnabled)
	{
		smc->setTextColor("EVENT");
		std::cout<<"ERROR: NO GUARDS OF THIS NOTIFICATION ARE ENABLED!"<<std::endl;
		smc->event_status_msg.push_back("ERROR: NO GUARDS OF THIS NOTIFICATION ARE ENABLED in STATE: p1_1");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS OF THIS NOTIFICATION ARE ENABLED!", NO_ENABLED_GUARDS));
	}
}
// Concrete Deterministic Notification Handler: V2_outTRp1_1_15
void p1_1::V2_outTRp1_1_15(V2_StateMachineController *smc, int instance_id, int clause_id)
{
	bool isAtleastOneGuardEnabled = false;
	int instance_choice = instance_id;
	switch(instance_choice)
	{
		case 0: 
			// Guard Expression
			if(true)
			{
				isAtleastOneGuardEnabled = true;
				int clause_choice = clause_id;
					switch(clause_choice)
					{
					case 0:
							{
							// std::cout<<"Raising Notification: V2_outTRp1_1_15 -> Going From p1_1 to p2_1"<<std::endl;
							// smc->event_status_msg.push_back("State Changed: p1_1 => p2_1");
							#ifdef QT_GUI
								smc->event_status_msg.push_back(" <<<<<<<< Notification Raised: V2_outTRp1_1_15");
								smc->event_status_msg.push_back(" <!> State Update: p1_1 => p2_1");
							#endif
							smc->setTextColor("EVENT");
							std::cout<<std::endl<<" <<<<<<<< Notification Raised: V2_outTRp1_1_15"<<std::endl;
							std::cout<<" <!> State Update: p1_1 => p2_1"<<std::endl;
							smc->setTextColor("DATA");
							smc->setTextColor("ANY");
							smc->setCurrent(new p2_1());
							delete this;
							break;
							}
					default: 	std::cout<<"ERROR: Invalid random choice of Notification Clause!"<<std::endl;
								//throw (StubException("EXCEPTION: Invalid random choice of Notification Clause!", LOGICAL_ERROR));
								break;
					}// End of clause switch-case
			}
			break;
		default: 	std::cout<<"ERROR: Invalid random choice of Notification Instance!"<<std::endl;
					//throw (StubException("EXCEPTION: Invalid random choice of Notification Instance!", LOGICAL_ERROR));
					break;
	}// End of instance switch-case
	
	if(!isAtleastOneGuardEnabled)
	{
		smc->setTextColor("EVENT");
		std::cout<<"ERROR: NO GUARDS OF THIS NOTIFICATION ARE ENABLED!"<<std::endl;
		smc->event_status_msg.push_back("ERROR: NO GUARDS OF THIS NOTIFICATION ARE ENABLED in STATE: p1_1");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS OF THIS NOTIFICATION ARE ENABLED!", NO_ENABLED_GUARDS));
	}
}
// Concrete Notification Validator: V2_outTRp1_1_16
std::vector<int> p1_1::match_V2_outTRp1_1_16(V2_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
{
	std::vector<std::string> observed_notifications;
	std::vector<int> matched_instance_clause_id;
	bool is_equal = false;
	bool isAtleastOneGuardEnabled = true;
	bool isAtleastOneInstanceExecuted = false;
	
	for(int instance_choice = 0; instance_choice < 1; instance_choice++)
	{
	switch(instance_choice)
	{
		case 0: 
			// Guard Expression
			if(true)
			{
				isAtleastOneGuardEnabled = true;
				isAtleastOneInstanceExecuted = true;
				
				for(int clause_choice = 0; clause_choice < 1; clause_choice++)
				{
					switch(clause_choice)
					{
					case 0:	{
									const StateMachineController::V2_StateMachineController& smcRef = *smc;
									StateMachineController::smVarContainer var_copy(smcRef);
									observed_notifications.push_back("V2_outTRp1_1_16");
									bool is_equal = false;
									if (observed_notifications.size() == list_of_rcvd_notifications.size())
										is_equal = std::equal(observed_notifications.begin(), observed_notifications.end(), list_of_rcvd_notifications.begin());
									if (is_equal) { matched_instance_clause_id.push_back(0); matched_instance_clause_id.push_back(0); return matched_instance_clause_id; }
									else { observed_notifications.clear(); }		
									break;
								}
					default: 	std::cout<<"ERROR: Invalid random choice of Notification Clause"<<std::endl;
								//throw (StubException("EXCEPTION: Invalid random choice of Notification Clause!", LOGICAL_ERROR));
								break;
					}// End of clause switch-case
				}// End of clause selector for-loop
			}
			break;
		default: 	std::cout<<"ERROR: Invalid random choice of Notification Instance"<<std::endl;
					//throw (StubException("EXCEPTION: Invalid random choice of Notification Instance!", LOGICAL_ERROR));
					break;
	}// End of instance switch-case
	}// End of instance selector for-loop
	
	if(!isAtleastOneGuardEnabled)
	{
		smc->setTextColor("EVENT");
		std::cout<<"ERROR: NO GUARDS OF THIS NOTIFICATION ARE ENABLED!"<<std::endl;
		smc->event_status_msg.push_back("ERROR: NO GUARDS OF THIS NOTIFICATION ARE ENABLED in STATE: p1_1");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS OF THIS NOTIFICATION ARE ENABLED!", NO_ENABLED_GUARDS));
	}
	
	matched_instance_clause_id.push_back(UNDEFINED_CHOICE); 
	matched_instance_clause_id.push_back(UNDEFINED_CHOICE); 
	return matched_instance_clause_id;
}
// Concrete Notification Validator: V2_outTRp1_1_15
std::vector<int> p1_1::match_V2_outTRp1_1_15(V2_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
{
	std::vector<std::string> observed_notifications;
	std::vector<int> matched_instance_clause_id;
	bool is_equal = false;
	bool isAtleastOneGuardEnabled = true;
	bool isAtleastOneInstanceExecuted = false;
	
	for(int instance_choice = 0; instance_choice < 1; instance_choice++)
	{
	switch(instance_choice)
	{
		case 0: 
			// Guard Expression
			if(true)
			{
				isAtleastOneGuardEnabled = true;
				isAtleastOneInstanceExecuted = true;
				
				for(int clause_choice = 0; clause_choice < 1; clause_choice++)
				{
					switch(clause_choice)
					{
					case 0:	{
									const StateMachineController::V2_StateMachineController& smcRef = *smc;
									StateMachineController::smVarContainer var_copy(smcRef);
									observed_notifications.push_back("V2_outTRp1_1_15");
									bool is_equal = false;
									if (observed_notifications.size() == list_of_rcvd_notifications.size())
										is_equal = std::equal(observed_notifications.begin(), observed_notifications.end(), list_of_rcvd_notifications.begin());
									if (is_equal) { matched_instance_clause_id.push_back(0); matched_instance_clause_id.push_back(0); return matched_instance_clause_id; }
									else { observed_notifications.clear(); }		
									break;
								}
					default: 	std::cout<<"ERROR: Invalid random choice of Notification Clause"<<std::endl;
								//throw (StubException("EXCEPTION: Invalid random choice of Notification Clause!", LOGICAL_ERROR));
								break;
					}// End of clause switch-case
				}// End of clause selector for-loop
			}
			break;
		default: 	std::cout<<"ERROR: Invalid random choice of Notification Instance"<<std::endl;
					//throw (StubException("EXCEPTION: Invalid random choice of Notification Instance!", LOGICAL_ERROR));
					break;
	}// End of instance switch-case
	}// End of instance selector for-loop
	
	if(!isAtleastOneGuardEnabled)
	{
		smc->setTextColor("EVENT");
		std::cout<<"ERROR: NO GUARDS OF THIS NOTIFICATION ARE ENABLED!"<<std::endl;
		smc->event_status_msg.push_back("ERROR: NO GUARDS OF THIS NOTIFICATION ARE ENABLED in STATE: p1_1");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS OF THIS NOTIFICATION ARE ENABLED!", NO_ENABLED_GUARDS));
	}
	
	matched_instance_clause_id.push_back(UNDEFINED_CHOICE); 
	matched_instance_clause_id.push_back(UNDEFINED_CHOICE); 
	return matched_instance_clause_id;
}
// Concrete Notification Handler: V2_outTRp1_1_16
void p1_1::V2_outTRp1_1_16(V2_StateMachineController *smc)
{
	bool isAtleastOneGuardEnabled = true;
	bool isAtleastOneInstanceExecuted = false;
		// Guard Expression
		if(true && !isAtleastOneInstanceExecuted)
		{
			isAtleastOneGuardEnabled = true;
			isAtleastOneInstanceExecuted = true;
			int clause_choice = rand() %1;
			switch(clause_choice)
			{
			case 0:	{
						// std::cout<<"Raising Notification: V2_outTRp1_1_16 -> Going From p1_1 to p3_1"<<std::endl;
						// smc->event_status_msg.push_back("State Changed: p1_1 => p3_1");
						#ifdef QT_GUI
							smc->event_status_msg.push_back(" <<<<<<<< Notification Raised: V2_outTRp1_1_16");
							smc->event_status_msg.push_back(" <!> State Update: p1_1 => p3_1");
						#endif
						smc->setTextColor("EVENT");
						std::cout<<std::endl<<" <<<<<<<< Notification Raised: V2_outTRp1_1_16"<<std::endl;
						std::cout<<" <!> State Update: p1_1 => p3_1"<<std::endl;
						smc->setTextColor("DATA");
						smc->setTextColor("ANY");
						smc->setCurrent(new p3_1());
						delete this;
						return;
			}
			default: 	std::cout<<"ERROR: Invalid random choice of Notification Clause!"<<std::endl;
						//throw (StubException("EXCEPTION: Invalid random choice of Notification Clause!", LOGICAL_ERROR));
						break;
			}// End of clause switch-case
		}
	if(!isAtleastOneGuardEnabled)
	{
		smc->setTextColor("EVENT");
		std::cout<<"ERROR: NO GUARDS OF THIS NOTIFICATION ARE ENABLED!"<<std::endl;
		smc->event_status_msg.push_back("ERROR: NO GUARDS OF THIS NOTIFICATION ARE ENABLED in STATE: p1_1");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS OF THIS NOTIFICATION ARE ENABLED!", NO_ENABLED_GUARDS));
	}
}
// Concrete Notification Handler: V2_outTRp1_1_15
void p1_1::V2_outTRp1_1_15(V2_StateMachineController *smc)
{
	bool isAtleastOneGuardEnabled = true;
	bool isAtleastOneInstanceExecuted = false;
		// Guard Expression
		if(true && !isAtleastOneInstanceExecuted)
		{
			isAtleastOneGuardEnabled = true;
			isAtleastOneInstanceExecuted = true;
			int clause_choice = rand() %1;
			switch(clause_choice)
			{
			case 0:	{
						// std::cout<<"Raising Notification: V2_outTRp1_1_15 -> Going From p1_1 to p2_1"<<std::endl;
						// smc->event_status_msg.push_back("State Changed: p1_1 => p2_1");
						#ifdef QT_GUI
							smc->event_status_msg.push_back(" <<<<<<<< Notification Raised: V2_outTRp1_1_15");
							smc->event_status_msg.push_back(" <!> State Update: p1_1 => p2_1");
						#endif
						smc->setTextColor("EVENT");
						std::cout<<std::endl<<" <<<<<<<< Notification Raised: V2_outTRp1_1_15"<<std::endl;
						std::cout<<" <!> State Update: p1_1 => p2_1"<<std::endl;
						smc->setTextColor("DATA");
						smc->setTextColor("ANY");
						smc->setCurrent(new p2_1());
						delete this;
						return;
			}
			default: 	std::cout<<"ERROR: Invalid random choice of Notification Clause!"<<std::endl;
						//throw (StubException("EXCEPTION: Invalid random choice of Notification Clause!", LOGICAL_ERROR));
						break;
			}// End of clause switch-case
		}
	if(!isAtleastOneGuardEnabled)
	{
		smc->setTextColor("EVENT");
		std::cout<<"ERROR: NO GUARDS OF THIS NOTIFICATION ARE ENABLED!"<<std::endl;
		smc->event_status_msg.push_back("ERROR: NO GUARDS OF THIS NOTIFICATION ARE ENABLED in STATE: p1_1");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS OF THIS NOTIFICATION ARE ENABLED!", NO_ENABLED_GUARDS));
	}
}

void p1_1::executeInternalTransitions(V2_StateMachineController *smc)
{
	bool found_enabled_notification = false;
	if( true ||   true )
	{
	while(!found_enabled_notification)
	{
	int choice = rand() %2; //%END;
	switch(choice)
	{
		case 0:
					found_enabled_notification = true;
					// found_enabled_notification = true;
					#ifdef QT_GUI
					smc->event_status_msg.push_back(" <<<<<<<< Notification Raised: V2_outTRp1_1_15");
					smc->event_status_msg.push_back(" <!> State Update: p1_1 => p2_1");
					#endif
					smc->setTextColor("EVENT");
					std::cout<<std::endl<<" <<<<<<<< Notification Raised: V2_outTRp1_1_15"<<std::endl;
					std::cout<<" <!> State Update: p1_1 => p2_1"<<std::endl;
					smc->setTextColor("DATA");
					smc->setTextColor("ANY");
					// Note: For SSCF push the notification out here...
					#ifdef SSCF_VERSION
					
					smc->m_serverPtr->raiseNotification_outTRp1_1_15();
					#endif
					#ifndef SSCF_VERSION
					if(smc->m_niHandler != nullptr) smc->m_niHandler("V2_outTRp1_1_15");
					if(smc->m_outTRp1_1_15_Handler != nullptr)
					{
						smc->m_outTRp1_1_15_Handler();
					}
					#endif
					// smc->event_status_msg.push_back("State Changed: p1_1 => p2_1");
					smc->setCurrent(new p2_1());
					delete this;
					break;
		case 1:
					found_enabled_notification = true;
					// found_enabled_notification = true;
					#ifdef QT_GUI
					smc->event_status_msg.push_back(" <<<<<<<< Notification Raised: V2_outTRp1_1_16");
					smc->event_status_msg.push_back(" <!> State Update: p1_1 => p3_1");
					#endif
					smc->setTextColor("EVENT");
					std::cout<<std::endl<<" <<<<<<<< Notification Raised: V2_outTRp1_1_16"<<std::endl;
					std::cout<<" <!> State Update: p1_1 => p3_1"<<std::endl;
					smc->setTextColor("DATA");
					smc->setTextColor("ANY");
					// Note: For SSCF push the notification out here...
					#ifdef SSCF_VERSION
					
					smc->m_serverPtr->raiseNotification_outTRp1_1_16();
					#endif
					#ifndef SSCF_VERSION
					if(smc->m_niHandler != nullptr) smc->m_niHandler("V2_outTRp1_1_16");
					if(smc->m_outTRp1_1_16_Handler != nullptr)
					{
						smc->m_outTRp1_1_16_Handler();
					}
					#endif
					// smc->event_status_msg.push_back("State Changed: p1_1 => p3_1");
					smc->setCurrent(new p3_1());
					delete this;
					break;
		default: 	std::cout<<"ERROR: Invalid random choice of target state"<<std::endl;
					//throw (StubException("EXCEPTION: Invalid random choice of target state!", LOGICAL_ERROR));
					break;
	}
	}
	}
	else
	{
		// NO ENABLED GUARDS
		smc->setTextColor("EVENT");
		std::cout<<"ERROR: NONE OF THE NOTIFICATION GUARDS ARE ENABLED!"<<std::endl;
		smc->event_status_msg.push_back("ERROR: NONE OF THE NOTIFICATION GUARDS ARE ENABLED in STATE: p1_1");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NONE OF THE NOTIFICATION GUARDS ARE ENABLED in STATE: p1_1!", NO_ENABLED_GUARDS));
	}
}



/*********** Concrete State Class: p1_4 ***********/

list<string> p1_4::getCurrentCommandStatusList() 
{
	list<string> retStr;
	return retStr;
}

list<string> p1_4::getCurrentSignalStatusList()
{
	list<string> retStr;
	return retStr;
}
		
list<string> p1_4::getCurrentNotificationStatusList()
{
	list<string> retStr;
	retStr.push_back("V2_outTRp1_2_12");
	return retStr;
}

string p1_4::getCurrentState() { return name; }

list<string> p1_4::isAtleastOneEnabledCommand(V2_StateMachineController *smc)
{
	list<string> list_of_enabled_commands;
	//StateMachineController::InputParametersContainer c;
	return list_of_enabled_commands;
}
list<string> p1_4::isAtleastOneEnabledSignal(V2_StateMachineController *smc)
{
	list<string> list_of_enabled_signals;
	//StateMachineController::InputParametersContainer c;
	return list_of_enabled_signals;
}

void p1_4::executeAvailableCommandsAndSignalsInState(V2_StateMachineController *smc)
{
	//StateMachineController::InputParametersContainer c;
	list<string> list_of_enabled_commands_and_signals = determineEnabledCommandAndSignalInState(smc);
	if(checkEnabledCommandAndSignalInState(smc))
	{
		std::list<string>::iterator it = list_of_enabled_commands_and_signals.begin();
		
		// Choose a random element from the list
		std::advance(it, rand() %list_of_enabled_commands_and_signals.size());

		// TODO: Do not match reply(*). Find out how to do this.
		#ifdef CLIENT_STUB_API

		#endif
		
		#ifndef CLIENT_STUB_API
		#endif
	}
	else
	{
		std::cout<<std::endl<<"ERROR: No Enabled Commands or Signals in State: p1_4"<<std::endl;
		//throw (StubException("EXCEPTION: No Enabled Commands or Signals in State: p1_4", NO_ENABLED_GUARDS));
	}
}

bool p1_4::checkEnabledCommandAndSignalInState(V2_StateMachineController *smc)
{
	if(determineEnabledCommandAndSignalInState(smc).empty())
			return false;
		else
			return true;
}

list<string> p1_4::determineEnabledCommandAndSignalInState(V2_StateMachineController *smc)
{
	list<string> enabled_commands_and_signals_list = isAtleastOneEnabledCommand(smc);
	enabled_commands_and_signals_list.splice(enabled_commands_and_signals_list.end(), isAtleastOneEnabledSignal(smc));
	return enabled_commands_and_signals_list;
}


bool p1_4::isAtleastOneEnabledNotification(V2_StateMachineController *smc)
{
	if( true )
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Concrete Deterministic Notification Handler: V2_outTRp1_2_12
void p1_4::V2_outTRp1_2_12(V2_StateMachineController *smc, int instance_id, int clause_id)
{
	bool isAtleastOneGuardEnabled = false;
	int instance_choice = instance_id;
	switch(instance_choice)
	{
		case 0: 
			// Guard Expression
			if(true)
			{
				isAtleastOneGuardEnabled = true;
				int clause_choice = clause_id;
					switch(clause_choice)
					{
					case 0:
							{
							// std::cout<<"Raising Notification: V2_outTRp1_2_12 -> Going From p1_4 to p1_5"<<std::endl;
							// smc->event_status_msg.push_back("State Changed: p1_4 => p1_5");
							#ifdef QT_GUI
								smc->event_status_msg.push_back(" <<<<<<<< Notification Raised: V2_outTRp1_2_12");
								smc->event_status_msg.push_back(" <!> State Update: p1_4 => p1_5");
							#endif
							smc->setTextColor("EVENT");
							std::cout<<std::endl<<" <<<<<<<< Notification Raised: V2_outTRp1_2_12"<<std::endl;
							std::cout<<" <!> State Update: p1_4 => p1_5"<<std::endl;
							smc->setTextColor("DATA");
							smc->setTextColor("ANY");
							smc->setCurrent(new p1_5());
							delete this;
							break;
							}
					default: 	std::cout<<"ERROR: Invalid random choice of Notification Clause!"<<std::endl;
								//throw (StubException("EXCEPTION: Invalid random choice of Notification Clause!", LOGICAL_ERROR));
								break;
					}// End of clause switch-case
			}
			break;
		default: 	std::cout<<"ERROR: Invalid random choice of Notification Instance!"<<std::endl;
					//throw (StubException("EXCEPTION: Invalid random choice of Notification Instance!", LOGICAL_ERROR));
					break;
	}// End of instance switch-case
	
	if(!isAtleastOneGuardEnabled)
	{
		smc->setTextColor("EVENT");
		std::cout<<"ERROR: NO GUARDS OF THIS NOTIFICATION ARE ENABLED!"<<std::endl;
		smc->event_status_msg.push_back("ERROR: NO GUARDS OF THIS NOTIFICATION ARE ENABLED in STATE: p1_4");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS OF THIS NOTIFICATION ARE ENABLED!", NO_ENABLED_GUARDS));
	}
}
// Concrete Notification Validator: V2_outTRp1_2_12
std::vector<int> p1_4::match_V2_outTRp1_2_12(V2_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
{
	std::vector<std::string> observed_notifications;
	std::vector<int> matched_instance_clause_id;
	bool is_equal = false;
	bool isAtleastOneGuardEnabled = true;
	bool isAtleastOneInstanceExecuted = false;
	
	for(int instance_choice = 0; instance_choice < 1; instance_choice++)
	{
	switch(instance_choice)
	{
		case 0: 
			// Guard Expression
			if(true)
			{
				isAtleastOneGuardEnabled = true;
				isAtleastOneInstanceExecuted = true;
				
				for(int clause_choice = 0; clause_choice < 1; clause_choice++)
				{
					switch(clause_choice)
					{
					case 0:	{
									const StateMachineController::V2_StateMachineController& smcRef = *smc;
									StateMachineController::smVarContainer var_copy(smcRef);
									observed_notifications.push_back("V2_outTRp1_2_12");
									bool is_equal = false;
									if (observed_notifications.size() == list_of_rcvd_notifications.size())
										is_equal = std::equal(observed_notifications.begin(), observed_notifications.end(), list_of_rcvd_notifications.begin());
									if (is_equal) { matched_instance_clause_id.push_back(0); matched_instance_clause_id.push_back(0); return matched_instance_clause_id; }
									else { observed_notifications.clear(); }		
									break;
								}
					default: 	std::cout<<"ERROR: Invalid random choice of Notification Clause"<<std::endl;
								//throw (StubException("EXCEPTION: Invalid random choice of Notification Clause!", LOGICAL_ERROR));
								break;
					}// End of clause switch-case
				}// End of clause selector for-loop
			}
			break;
		default: 	std::cout<<"ERROR: Invalid random choice of Notification Instance"<<std::endl;
					//throw (StubException("EXCEPTION: Invalid random choice of Notification Instance!", LOGICAL_ERROR));
					break;
	}// End of instance switch-case
	}// End of instance selector for-loop
	
	if(!isAtleastOneGuardEnabled)
	{
		smc->setTextColor("EVENT");
		std::cout<<"ERROR: NO GUARDS OF THIS NOTIFICATION ARE ENABLED!"<<std::endl;
		smc->event_status_msg.push_back("ERROR: NO GUARDS OF THIS NOTIFICATION ARE ENABLED in STATE: p1_4");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS OF THIS NOTIFICATION ARE ENABLED!", NO_ENABLED_GUARDS));
	}
	
	matched_instance_clause_id.push_back(UNDEFINED_CHOICE); 
	matched_instance_clause_id.push_back(UNDEFINED_CHOICE); 
	return matched_instance_clause_id;
}
// Concrete Notification Handler: V2_outTRp1_2_12
void p1_4::V2_outTRp1_2_12(V2_StateMachineController *smc)
{
	bool isAtleastOneGuardEnabled = true;
	bool isAtleastOneInstanceExecuted = false;
		// Guard Expression
		if(true && !isAtleastOneInstanceExecuted)
		{
			isAtleastOneGuardEnabled = true;
			isAtleastOneInstanceExecuted = true;
			int clause_choice = rand() %1;
			switch(clause_choice)
			{
			case 0:	{
						// std::cout<<"Raising Notification: V2_outTRp1_2_12 -> Going From p1_4 to p1_5"<<std::endl;
						// smc->event_status_msg.push_back("State Changed: p1_4 => p1_5");
						#ifdef QT_GUI
							smc->event_status_msg.push_back(" <<<<<<<< Notification Raised: V2_outTRp1_2_12");
							smc->event_status_msg.push_back(" <!> State Update: p1_4 => p1_5");
						#endif
						smc->setTextColor("EVENT");
						std::cout<<std::endl<<" <<<<<<<< Notification Raised: V2_outTRp1_2_12"<<std::endl;
						std::cout<<" <!> State Update: p1_4 => p1_5"<<std::endl;
						smc->setTextColor("DATA");
						smc->setTextColor("ANY");
						smc->setCurrent(new p1_5());
						delete this;
						return;
			}
			default: 	std::cout<<"ERROR: Invalid random choice of Notification Clause!"<<std::endl;
						//throw (StubException("EXCEPTION: Invalid random choice of Notification Clause!", LOGICAL_ERROR));
						break;
			}// End of clause switch-case
		}
	if(!isAtleastOneGuardEnabled)
	{
		smc->setTextColor("EVENT");
		std::cout<<"ERROR: NO GUARDS OF THIS NOTIFICATION ARE ENABLED!"<<std::endl;
		smc->event_status_msg.push_back("ERROR: NO GUARDS OF THIS NOTIFICATION ARE ENABLED in STATE: p1_4");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS OF THIS NOTIFICATION ARE ENABLED!", NO_ENABLED_GUARDS));
	}
}

void p1_4::executeInternalTransitions(V2_StateMachineController *smc)
{
	bool found_enabled_notification = false;
	if( true )
	{
	while(!found_enabled_notification)
	{
	int choice = rand() %1; //%END;
	switch(choice)
	{
		case 0:
					found_enabled_notification = true;
					// found_enabled_notification = true;
					#ifdef QT_GUI
					smc->event_status_msg.push_back(" <<<<<<<< Notification Raised: V2_outTRp1_2_12");
					smc->event_status_msg.push_back(" <!> State Update: p1_4 => p1_5");
					#endif
					smc->setTextColor("EVENT");
					std::cout<<std::endl<<" <<<<<<<< Notification Raised: V2_outTRp1_2_12"<<std::endl;
					std::cout<<" <!> State Update: p1_4 => p1_5"<<std::endl;
					smc->setTextColor("DATA");
					smc->setTextColor("ANY");
					// Note: For SSCF push the notification out here...
					#ifdef SSCF_VERSION
					
					smc->m_serverPtr->raiseNotification_outTRp1_2_12();
					#endif
					#ifndef SSCF_VERSION
					if(smc->m_niHandler != nullptr) smc->m_niHandler("V2_outTRp1_2_12");
					if(smc->m_outTRp1_2_12_Handler != nullptr)
					{
						smc->m_outTRp1_2_12_Handler();
					}
					#endif
					// smc->event_status_msg.push_back("State Changed: p1_4 => p1_5");
					smc->setCurrent(new p1_5());
					delete this;
					break;
		default: 	std::cout<<"ERROR: Invalid random choice of target state"<<std::endl;
					//throw (StubException("EXCEPTION: Invalid random choice of target state!", LOGICAL_ERROR));
					break;
	}
	}
	}
	else
	{
		// NO ENABLED GUARDS
		smc->setTextColor("EVENT");
		std::cout<<"ERROR: NONE OF THE NOTIFICATION GUARDS ARE ENABLED!"<<std::endl;
		smc->event_status_msg.push_back("ERROR: NONE OF THE NOTIFICATION GUARDS ARE ENABLED in STATE: p1_4");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NONE OF THE NOTIFICATION GUARDS ARE ENABLED in STATE: p1_4!", NO_ENABLED_GUARDS));
	}
}



/*********** Concrete State Class: p1_6 ***********/

list<string> p1_6::getCurrentCommandStatusList() 
{
	list<string> retStr;
	return retStr;
}

list<string> p1_6::getCurrentSignalStatusList()
{
	list<string> retStr;
	return retStr;
}
		
list<string> p1_6::getCurrentNotificationStatusList()
{
	list<string> retStr;
	retStr.push_back("V2_outTRp1_6_22");
	return retStr;
}

string p1_6::getCurrentState() { return name; }

list<string> p1_6::isAtleastOneEnabledCommand(V2_StateMachineController *smc)
{
	list<string> list_of_enabled_commands;
	//StateMachineController::InputParametersContainer c;
	return list_of_enabled_commands;
}
list<string> p1_6::isAtleastOneEnabledSignal(V2_StateMachineController *smc)
{
	list<string> list_of_enabled_signals;
	//StateMachineController::InputParametersContainer c;
	return list_of_enabled_signals;
}

void p1_6::executeAvailableCommandsAndSignalsInState(V2_StateMachineController *smc)
{
	//StateMachineController::InputParametersContainer c;
	list<string> list_of_enabled_commands_and_signals = determineEnabledCommandAndSignalInState(smc);
	if(checkEnabledCommandAndSignalInState(smc))
	{
		std::list<string>::iterator it = list_of_enabled_commands_and_signals.begin();
		
		// Choose a random element from the list
		std::advance(it, rand() %list_of_enabled_commands_and_signals.size());

		// TODO: Do not match reply(*). Find out how to do this.
		#ifdef CLIENT_STUB_API

		#endif
		
		#ifndef CLIENT_STUB_API
		#endif
	}
	else
	{
		std::cout<<std::endl<<"ERROR: No Enabled Commands or Signals in State: p1_6"<<std::endl;
		//throw (StubException("EXCEPTION: No Enabled Commands or Signals in State: p1_6", NO_ENABLED_GUARDS));
	}
}

bool p1_6::checkEnabledCommandAndSignalInState(V2_StateMachineController *smc)
{
	if(determineEnabledCommandAndSignalInState(smc).empty())
			return false;
		else
			return true;
}

list<string> p1_6::determineEnabledCommandAndSignalInState(V2_StateMachineController *smc)
{
	list<string> enabled_commands_and_signals_list = isAtleastOneEnabledCommand(smc);
	enabled_commands_and_signals_list.splice(enabled_commands_and_signals_list.end(), isAtleastOneEnabledSignal(smc));
	return enabled_commands_and_signals_list;
}


bool p1_6::isAtleastOneEnabledNotification(V2_StateMachineController *smc)
{
	if( true )
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Concrete Deterministic Notification Handler: V2_outTRp1_6_22
void p1_6::V2_outTRp1_6_22(V2_StateMachineController *smc, int instance_id, int clause_id)
{
	bool isAtleastOneGuardEnabled = false;
	int instance_choice = instance_id;
	switch(instance_choice)
	{
		case 0: 
			// Guard Expression
			if(true)
			{
				isAtleastOneGuardEnabled = true;
				int clause_choice = clause_id;
					switch(clause_choice)
					{
					case 0:
							{
							// std::cout<<"Raising Notification: V2_outTRp1_6_22 -> Going From p1_6 to p1_7"<<std::endl;
							// smc->event_status_msg.push_back("State Changed: p1_6 => p1_7");
							#ifdef QT_GUI
								smc->event_status_msg.push_back(" <<<<<<<< Notification Raised: V2_outTRp1_6_22");
								smc->event_status_msg.push_back(" <!> State Update: p1_6 => p1_7");
							#endif
							smc->setTextColor("EVENT");
							std::cout<<std::endl<<" <<<<<<<< Notification Raised: V2_outTRp1_6_22"<<std::endl;
							std::cout<<" <!> State Update: p1_6 => p1_7"<<std::endl;
							smc->setTextColor("DATA");
							smc->setTextColor("ANY");
							smc->setCurrent(new p1_7());
							delete this;
							break;
							}
					default: 	std::cout<<"ERROR: Invalid random choice of Notification Clause!"<<std::endl;
								//throw (StubException("EXCEPTION: Invalid random choice of Notification Clause!", LOGICAL_ERROR));
								break;
					}// End of clause switch-case
			}
			break;
		default: 	std::cout<<"ERROR: Invalid random choice of Notification Instance!"<<std::endl;
					//throw (StubException("EXCEPTION: Invalid random choice of Notification Instance!", LOGICAL_ERROR));
					break;
	}// End of instance switch-case
	
	if(!isAtleastOneGuardEnabled)
	{
		smc->setTextColor("EVENT");
		std::cout<<"ERROR: NO GUARDS OF THIS NOTIFICATION ARE ENABLED!"<<std::endl;
		smc->event_status_msg.push_back("ERROR: NO GUARDS OF THIS NOTIFICATION ARE ENABLED in STATE: p1_6");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS OF THIS NOTIFICATION ARE ENABLED!", NO_ENABLED_GUARDS));
	}
}
// Concrete Notification Validator: V2_outTRp1_6_22
std::vector<int> p1_6::match_V2_outTRp1_6_22(V2_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
{
	std::vector<std::string> observed_notifications;
	std::vector<int> matched_instance_clause_id;
	bool is_equal = false;
	bool isAtleastOneGuardEnabled = true;
	bool isAtleastOneInstanceExecuted = false;
	
	for(int instance_choice = 0; instance_choice < 1; instance_choice++)
	{
	switch(instance_choice)
	{
		case 0: 
			// Guard Expression
			if(true)
			{
				isAtleastOneGuardEnabled = true;
				isAtleastOneInstanceExecuted = true;
				
				for(int clause_choice = 0; clause_choice < 1; clause_choice++)
				{
					switch(clause_choice)
					{
					case 0:	{
									const StateMachineController::V2_StateMachineController& smcRef = *smc;
									StateMachineController::smVarContainer var_copy(smcRef);
									observed_notifications.push_back("V2_outTRp1_6_22");
									bool is_equal = false;
									if (observed_notifications.size() == list_of_rcvd_notifications.size())
										is_equal = std::equal(observed_notifications.begin(), observed_notifications.end(), list_of_rcvd_notifications.begin());
									if (is_equal) { matched_instance_clause_id.push_back(0); matched_instance_clause_id.push_back(0); return matched_instance_clause_id; }
									else { observed_notifications.clear(); }		
									break;
								}
					default: 	std::cout<<"ERROR: Invalid random choice of Notification Clause"<<std::endl;
								//throw (StubException("EXCEPTION: Invalid random choice of Notification Clause!", LOGICAL_ERROR));
								break;
					}// End of clause switch-case
				}// End of clause selector for-loop
			}
			break;
		default: 	std::cout<<"ERROR: Invalid random choice of Notification Instance"<<std::endl;
					//throw (StubException("EXCEPTION: Invalid random choice of Notification Instance!", LOGICAL_ERROR));
					break;
	}// End of instance switch-case
	}// End of instance selector for-loop
	
	if(!isAtleastOneGuardEnabled)
	{
		smc->setTextColor("EVENT");
		std::cout<<"ERROR: NO GUARDS OF THIS NOTIFICATION ARE ENABLED!"<<std::endl;
		smc->event_status_msg.push_back("ERROR: NO GUARDS OF THIS NOTIFICATION ARE ENABLED in STATE: p1_6");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS OF THIS NOTIFICATION ARE ENABLED!", NO_ENABLED_GUARDS));
	}
	
	matched_instance_clause_id.push_back(UNDEFINED_CHOICE); 
	matched_instance_clause_id.push_back(UNDEFINED_CHOICE); 
	return matched_instance_clause_id;
}
// Concrete Notification Handler: V2_outTRp1_6_22
void p1_6::V2_outTRp1_6_22(V2_StateMachineController *smc)
{
	bool isAtleastOneGuardEnabled = true;
	bool isAtleastOneInstanceExecuted = false;
		// Guard Expression
		if(true && !isAtleastOneInstanceExecuted)
		{
			isAtleastOneGuardEnabled = true;
			isAtleastOneInstanceExecuted = true;
			int clause_choice = rand() %1;
			switch(clause_choice)
			{
			case 0:	{
						// std::cout<<"Raising Notification: V2_outTRp1_6_22 -> Going From p1_6 to p1_7"<<std::endl;
						// smc->event_status_msg.push_back("State Changed: p1_6 => p1_7");
						#ifdef QT_GUI
							smc->event_status_msg.push_back(" <<<<<<<< Notification Raised: V2_outTRp1_6_22");
							smc->event_status_msg.push_back(" <!> State Update: p1_6 => p1_7");
						#endif
						smc->setTextColor("EVENT");
						std::cout<<std::endl<<" <<<<<<<< Notification Raised: V2_outTRp1_6_22"<<std::endl;
						std::cout<<" <!> State Update: p1_6 => p1_7"<<std::endl;
						smc->setTextColor("DATA");
						smc->setTextColor("ANY");
						smc->setCurrent(new p1_7());
						delete this;
						return;
			}
			default: 	std::cout<<"ERROR: Invalid random choice of Notification Clause!"<<std::endl;
						//throw (StubException("EXCEPTION: Invalid random choice of Notification Clause!", LOGICAL_ERROR));
						break;
			}// End of clause switch-case
		}
	if(!isAtleastOneGuardEnabled)
	{
		smc->setTextColor("EVENT");
		std::cout<<"ERROR: NO GUARDS OF THIS NOTIFICATION ARE ENABLED!"<<std::endl;
		smc->event_status_msg.push_back("ERROR: NO GUARDS OF THIS NOTIFICATION ARE ENABLED in STATE: p1_6");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS OF THIS NOTIFICATION ARE ENABLED!", NO_ENABLED_GUARDS));
	}
}

void p1_6::executeInternalTransitions(V2_StateMachineController *smc)
{
	bool found_enabled_notification = false;
	if( true )
	{
	while(!found_enabled_notification)
	{
	int choice = rand() %1; //%END;
	switch(choice)
	{
		case 0:
					found_enabled_notification = true;
					// found_enabled_notification = true;
					#ifdef QT_GUI
					smc->event_status_msg.push_back(" <<<<<<<< Notification Raised: V2_outTRp1_6_22");
					smc->event_status_msg.push_back(" <!> State Update: p1_6 => p1_7");
					#endif
					smc->setTextColor("EVENT");
					std::cout<<std::endl<<" <<<<<<<< Notification Raised: V2_outTRp1_6_22"<<std::endl;
					std::cout<<" <!> State Update: p1_6 => p1_7"<<std::endl;
					smc->setTextColor("DATA");
					smc->setTextColor("ANY");
					// Note: For SSCF push the notification out here...
					#ifdef SSCF_VERSION
					
					smc->m_serverPtr->raiseNotification_outTRp1_6_22();
					#endif
					#ifndef SSCF_VERSION
					if(smc->m_niHandler != nullptr) smc->m_niHandler("V2_outTRp1_6_22");
					if(smc->m_outTRp1_6_22_Handler != nullptr)
					{
						smc->m_outTRp1_6_22_Handler();
					}
					#endif
					// smc->event_status_msg.push_back("State Changed: p1_6 => p1_7");
					smc->setCurrent(new p1_7());
					delete this;
					break;
		default: 	std::cout<<"ERROR: Invalid random choice of target state"<<std::endl;
					//throw (StubException("EXCEPTION: Invalid random choice of target state!", LOGICAL_ERROR));
					break;
	}
	}
	}
	else
	{
		// NO ENABLED GUARDS
		smc->setTextColor("EVENT");
		std::cout<<"ERROR: NONE OF THE NOTIFICATION GUARDS ARE ENABLED!"<<std::endl;
		smc->event_status_msg.push_back("ERROR: NONE OF THE NOTIFICATION GUARDS ARE ENABLED in STATE: p1_6");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NONE OF THE NOTIFICATION GUARDS ARE ENABLED in STATE: p1_6!", NO_ENABLED_GUARDS));
	}
}



/*********** Concrete State Class: p1_5 ***********/

list<string> p1_5::getCurrentCommandStatusList() 
{
	list<string> retStr;
	return retStr;
}

list<string> p1_5::getCurrentSignalStatusList()
{
	list<string> retStr;
	retStr.push_back("V2_inTRp1_3_13");
	return retStr;
}
		
list<string> p1_5::getCurrentNotificationStatusList()
{
	list<string> retStr;
	return retStr;
}

string p1_5::getCurrentState() { return name; }

list<string> p1_5::isAtleastOneEnabledCommand(V2_StateMachineController *smc)
{
	list<string> list_of_enabled_commands;
	//StateMachineController::InputParametersContainer c;
	return list_of_enabled_commands;
}
list<string> p1_5::isAtleastOneEnabledSignal(V2_StateMachineController *smc)
{
	list<string> list_of_enabled_signals;
	//StateMachineController::InputParametersContainer c;
	// Signal Name: V2_inTRp1_3_13
	{
	list_of_enabled_signals.push_back("V2_inTRp1_3_13");
	}
	return list_of_enabled_signals;
}

void p1_5::executeAvailableCommandsAndSignalsInState(V2_StateMachineController *smc)
{
	//StateMachineController::InputParametersContainer c;
	list<string> list_of_enabled_commands_and_signals = determineEnabledCommandAndSignalInState(smc);
	if(checkEnabledCommandAndSignalInState(smc))
	{
		std::list<string>::iterator it = list_of_enabled_commands_and_signals.begin();
		
		// Choose a random element from the list
		std::advance(it, rand() %list_of_enabled_commands_and_signals.size());

		// TODO: Do not match reply(*). Find out how to do this.
		#ifdef CLIENT_STUB_API

		if(!(*it).compare("V2_inTRp1_3_13"))
		{
			// #1. Call the interface function
			smc->client_api_handler->openEventContext();
			smc->client_api_handler->inTRp1_3_13();

			// #1a. Get the list of received notification and close the context.
			std::vector<string> list_of_rcvd_notifications = smc->client_api_handler->getListOfReceivedNotifications();
			//smc->client_api_handler->closeEventContext();
			std::cout << "[INFO] Number of Notifications Received in Context: " << list_of_rcvd_notifications.size() << std::endl;
			
			vector<int> instance_clause_id = V2_inTRp1_3_13( smc, list_of_rcvd_notifications);
			std::cout << std::endl << "Notifications List matched to Instance ID: " << instance_clause_id.at(0) << " and Clause ID: " << instance_clause_id.at(1) << std::endl;

			// #3. Call the the signal method
			V2_inTRp1_3_13( smc, instance_clause_id.at(0), instance_clause_id.at(1));
			smc->client_api_handler->closeEventContext();
		}
		#endif
		
		#ifndef CLIENT_STUB_API
		if(!(*it).compare("V2_inTRp1_3_13"))
		{
			
			std::cout << "Checking Instance-Clause Preferences for Signal: inTRp1_3_13" << std::endl;
			std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp1_3_13(smc->getCurrentState(), false);
			if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
			{
				// Call the function with Parameters Only
				std::cout << "No preferences found for Signal: inTRp1_3_13" << std::endl;
				
				// Call the function with Parameters
				V2_inTRp1_3_13( smc);
				smc->setTextColor("EVENT");
				std::cout<<std::endl<<" <<<<<<<< Command inTRp1_3_13 has been Executed!"<<std::endl;
				smc->setTextColor("ANY");
			}
			else
			{
				std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp1_3_13(smc->getCurrentState(), false);
				bool isAtleastOneInstanceEnabled = false;
				for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
				{
					if (isEnabledV2_inTRp1_3_13(smc, list_of_instance_id.at(i)))
					{
						instance_clause_id.at(0) = list_of_instance_id.at(i);
						std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp1_3_13(smc->getCurrentState(), list_of_instance_id.at(i), false);
						instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
						isAtleastOneInstanceEnabled = true;
					}
				}
				if(!isAtleastOneInstanceEnabled)
				{
					std::cout << "EXCEPTION: None of the instances of command: inTRp1_3_13 specified in the input file are enabled. Check the parameter set, if any!" << std::endl;
					//throw (StateMachineController::StubException("EXCEPTION: None of the instances of command: inTRp1_3_13 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));
				}
					
				// Call function with Parameters and Instance-Clause ID
				std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Command: inTRp1_3_13" << std::endl;
				
				// Call the function with Parameters
				V2_inTRp1_3_13( smc, instance_clause_id.at(0), instance_clause_id.at(1));
				smc->setTextColor("EVENT");
				std::cout<<std::endl<<" <<<<<<<< Command inTRp1_3_13 has been Executed!"<<std::endl;
				smc->setTextColor("ANY");
			}
		}
		#endif
	}
	else
	{
		std::cout<<std::endl<<"ERROR: No Enabled Commands or Signals in State: p1_5"<<std::endl;
		//throw (StubException("EXCEPTION: No Enabled Commands or Signals in State: p1_5", NO_ENABLED_GUARDS));
	}
}

bool p1_5::checkEnabledCommandAndSignalInState(V2_StateMachineController *smc)
{
	if(determineEnabledCommandAndSignalInState(smc).empty())
			return false;
		else
			return true;
}

list<string> p1_5::determineEnabledCommandAndSignalInState(V2_StateMachineController *smc)
{
	list<string> enabled_commands_and_signals_list = isAtleastOneEnabledCommand(smc);
	enabled_commands_and_signals_list.splice(enabled_commands_and_signals_list.end(), isAtleastOneEnabledSignal(smc));
	return enabled_commands_and_signals_list;
}


bool p1_5::isAtleastOneEnabledNotification(V2_StateMachineController *smc)
{
	UNREF_PARAM(smc);
	// Means there is no notification?
	return false;
}

// Enabling Test for Signal: V2_inTRp1_3_13
bool p1_5::isEnabledV2_inTRp1_3_13(V2_StateMachineController *smc, int instance_choice)
{
	// Switch Block for Signal Instances
	switch(instance_choice)
	{
		case 0: //Signal Instance
				// Guard Expression
				if(true)
				{
					return true;
				} // End of Guarded Block
				else
				{
					return false;
				}
				break;
		default: smc->setTextColor("EVENT");
				 std::cout<<"ERROR: Invalid Random Choice of Transition Instance [Enabling]"<<std::endl;
				 smc->setTextColor("ANY");
				 //throw (StubException("EXCEPTION: Invalid Random Choice of Transition Instance [Enabling]!", LOGICAL_ERROR));
				 break;
	} // End of Switch Block

	return false;
}
// Concrete Signal Context NI Validator: V2_inTRp1_3_13
std::vector<int> p1_5::V2_inTRp1_3_13(V2_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications)
{
	bool isAtleastOneGuardEnabled = true;
	bool isAtleastOneInstanceExecuted = false;
	
	std::vector<int> instance_clause_id;
	std::vector<std::string> observed_notifications;

	// Switch Block for Signal Instances
	for(int instance_choice = 0; instance_choice < 1; instance_choice++)
	{
	switch(instance_choice)
	{
		case 0: //Signal Instance
				// Guard Expression
				if(true)
				{
					isAtleastOneGuardEnabled = true;
					isAtleastOneInstanceExecuted = true;
					// Switch Block for Signal Clauses
					for(int choice = 0; choice < 1; choice++)
					{
					const StateMachineController::V2_StateMachineController& smcRef = *smc;
					StateMachineController::smVarContainer var_copy(smcRef);
					switch(choice)
					{
					case 0: // Signal Clause
							{
							smc->setTextColor("EVENT");
							#ifdef QT_GUI
							smc->event_status_msg.push_back(" >>>>>>>> Received Signal: inTRp1_3_13");
							smc->event_status_msg.push_back(" <!> State Update: p1_5 => p1_6");
							#endif
							// std::cout<<std::endl<<" >>>>>>>> Received Signal: inTRp1_3_13"<<std::endl;
							// std::cout<<" <!> State Update: From p1_5 => p1_6"<<std::endl;
							// smc->event_status_msg.push_back("State Changed: p1_5 => p1_6");
							smc->setTextColor("ANY");
							bool is_equal = false;
							if (observed_notifications.size() == list_of_rcvd_notifications.size())
								is_equal = std::equal(observed_notifications.begin(), observed_notifications.end(), list_of_rcvd_notifications.begin());
							if (is_equal) { instance_clause_id.push_back(0); instance_clause_id.push_back(0); return instance_clause_id; }
							else { observed_notifications.clear(); }
							smc->setTextColor("EVENT");
							// std::cout<<std::endl<<" <<<<<<<< Signal inTRp1_3_13 has been Executed!"<<std::endl;
							smc->setTextColor("ANY");
							break;
							}
					default: smc->setTextColor("EVENT");
							 std::cout<<"ERROR: Invalid random choice of Signal Clause"<<std::endl;
							 smc->setTextColor("ANY");
							 //throw (StubException("EXCEPTION: Invalid random choice of Signal Clause!", LOGICAL_ERROR));
							 break;
					} // End of Switch Block
					} // End of Clause For-Loop
				} // End of Guarded Block
				else {
					//smc->setTextColor("EVENT");
					//std::cout<<"FATAL: Choice of Signal Transition Instance and Clause in a Deterministic Context has Disabled Guards!"<<std::endl;
					//smc->setTextColor("ANY");
					////throw (StubException("EXCEPTION: Choice of Signal Transition Instance and Clause in a Deterministic Context has Disabled Guards!", INPUT_PARAMS_ERROR));
				}
				break;
		default: smc->setTextColor("EVENT");
				 std::cout<<"ERROR: Invalid random choice of Transition Instance"<<std::endl;
				 smc->setTextColor("ANY");
				 //throw (StubException("EXCEPTION: Invalid random choice of Transition Instance!", LOGICAL_ERROR));
				 break;
	} // End of Switch Block
	} // End of Instance For-Loop
	
	// To reach here means either none of the guards were true, or the reply did not match!
	if(!isAtleastOneGuardEnabled)
	{
		smc->setTextColor("EVENT");
		std::cout<<"ERROR: NO GUARDS FOR THIS SIGNAL ARE ENABLED!"<<std::endl;
		smc->event_status_msg.push_back("ERROR: NO GUARDS FOR THIS SIGNAL ARE ENABLED in STATE: p1_5");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS FOR THIS SIGNAL ARE ENABLED in STATE: p1_5!", NO_ENABLED_GUARDS));
		
	}
	else 
	{
		smc->setTextColor("EVENT");
		std::cout << "FATAL: THE RECEIVED NOTIFICATIONS IN CONTEXT OF SIGNAL COULD NOT BE MATCHED!" << std::endl;
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: THE RECEIVED NOTIFICATIONS IN CONTEXT OF SIGNAL COULD NOT BE MATCHED!", LOGICAL_ERROR));
	}
	// UNREACHABLE CODE. To be removed..
	instance_clause_id.push_back(UNDEFINED_CHOICE);
	instance_clause_id.push_back(UNDEFINED_CHOICE);
	return instance_clause_id;
}
// Concrete Deterministic Signal Handler: V2_inTRp1_3_13
void p1_5::V2_inTRp1_3_13(V2_StateMachineController *smc, int instance_id, int clause_id)
{
	bool isAtleastOneGuardEnabled = true;
	bool isAtleastOneInstanceExecuted = false;

	// Switch Block for Signal Clauses
	int instance_choice = instance_id; //rand() %1;
	switch(instance_choice)
	{
		case 0: //Signal Instance
				// Guard Expression
				if(true)
				{
					isAtleastOneGuardEnabled = true;
					isAtleastOneInstanceExecuted = true;
					// Switch Block for Signal Clauses
					int choice = clause_id; //rand() %1;
					switch(choice)
					{
					case 0: // Signal Clause
							smc->setTextColor("EVENT");
							#ifdef QT_GUI
							smc->event_status_msg.push_back(" >>>>>>>> Received Signal: inTRp1_3_13");
							smc->event_status_msg.push_back(" <!> State Update: p1_5 => p1_6");
							#endif
							std::cout<<std::endl<<" >>>>>>>> Received Signal: inTRp1_3_13"<<std::endl;
							std::cout<<" <!> State Update: From p1_5 => p1_6"<<std::endl;
							// smc->event_status_msg.push_back("State Changed: p1_5 => p1_6");
							smc->setTextColor("ANY");
							smc->setCurrent(new p1_6());
							delete this;
							smc->setTextColor("EVENT");
							std::cout<<std::endl<<" <<<<<<<< Signal inTRp1_3_13 has been Executed!"<<std::endl;
							smc->setTextColor("ANY");
							break;
					default: smc->setTextColor("EVENT");
							 std::cout<<"ERROR: Invalid random choice of target state"<<std::endl;
							 smc->setTextColor("ANY");
							 //throw (StubException("EXCEPTION: Invalid random choice of target state!", LOGICAL_ERROR));
							 break;
					} // End of Switch Block
				} // End of Guarded Block
				else {
					smc->setTextColor("EVENT");
					std::cout<<"FATAL: Choice of Signal Transition Instance and Clause in a Deterministic Context has Disabled Guards!"<<std::endl;
					smc->setTextColor("ANY");
					//throw (StubException("EXCEPTION: Choice of Signal Transition Instance and Clause in a Deterministic Context has Disabled Guards!", INPUT_PARAMS_ERROR));
				}
				break;
		default: smc->setTextColor("EVENT");
				 std::cout<<"ERROR: Invalid random choice of target state"<<std::endl;
				 smc->setTextColor("ANY");
				 //throw (StubException("EXCEPTION: Invalid random choice of target state!", LOGICAL_ERROR));
				 break;
	}
	if(!isAtleastOneGuardEnabled)
	{
		smc->setTextColor("EVENT");
		std::cout<<"ERROR: NO GUARDS FOR THIS SIGNAL ARE ENABLED!"<<std::endl;
		smc->event_status_msg.push_back("ERROR: NO GUARDS FOR THIS SIGNAL ARE ENABLED in STATE: p1_5");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS FOR THIS SIGNAL ARE ENABLED in STATE: p1_5!", NO_ENABLED_GUARDS));
		
	}
}
// Concrete Signal Handler: V2_inTRp1_3_13
void p1_5::V2_inTRp1_3_13(V2_StateMachineController *smc)
{
	bool isAtleastOneGuardEnabled = true;
	bool isAtleastOneInstanceExecuted = false;
	// Guard Expression
	if(true && !isAtleastOneInstanceExecuted)
	{
		isAtleastOneGuardEnabled = true;
		isAtleastOneInstanceExecuted = true;
		// Switch Block for Signal Clauses
		int choice = rand() %1;
		switch(choice)
		{
		case 0: // Signal Clause
				smc->setTextColor("EVENT");
				#ifdef QT_GUI
				smc->event_status_msg.push_back(" >>>>>>>> Received Signal: inTRp1_3_13");
				smc->event_status_msg.push_back(" <!> State Update: p1_5 => p1_6");
				#endif
				std::cout<<std::endl<<" >>>>>>>> Received Signal: inTRp1_3_13"<<std::endl;
				std::cout<<" <!> State Update: From p1_5 => p1_6"<<std::endl;
				// smc->event_status_msg.push_back("State Changed: p1_5 => p1_6");
				smc->setTextColor("ANY");
				smc->setCurrent(new p1_6());
				delete this;
				smc->setTextColor("EVENT");
				std::cout<<std::endl<<" <<<<<<<< Signal inTRp1_3_13 has been Executed!"<<std::endl;
				smc->setTextColor("ANY");
				break;
		default: smc->setTextColor("EVENT");
				 std::cout<<"ERROR: Invalid random choice of target state"<<std::endl;
				 smc->setTextColor("ANY");
				 //throw (StubException("EXCEPTION: Invalid random choice of target state!", LOGICAL_ERROR));
				 break;
		} // End of Switch Block
	} // End of Guarded Block
	if(!isAtleastOneGuardEnabled)
	{
		smc->setTextColor("EVENT");
		std::cout<<"ERROR: NO GUARDS FOR THIS SIGNAL ARE ENABLED!"<<std::endl;
		smc->event_status_msg.push_back("ERROR: NO GUARDS FOR THIS SIGNAL ARE ENABLED in STATE: p1_5");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS FOR THIS SIGNAL ARE ENABLED in STATE: p1_5!", NO_ENABLED_GUARDS));
		
	}
}




/*********** Concrete State Class: p1_8 ***********/

list<string> p1_8::getCurrentCommandStatusList() 
{
	list<string> retStr;
	return retStr;
}

list<string> p1_8::getCurrentSignalStatusList()
{
	list<string> retStr;
	return retStr;
}
		
list<string> p1_8::getCurrentNotificationStatusList()
{
	list<string> retStr;
	retStr.push_back("V2_outTRp1_6_19");
	return retStr;
}

string p1_8::getCurrentState() { return name; }

list<string> p1_8::isAtleastOneEnabledCommand(V2_StateMachineController *smc)
{
	list<string> list_of_enabled_commands;
	//StateMachineController::InputParametersContainer c;
	return list_of_enabled_commands;
}
list<string> p1_8::isAtleastOneEnabledSignal(V2_StateMachineController *smc)
{
	list<string> list_of_enabled_signals;
	//StateMachineController::InputParametersContainer c;
	return list_of_enabled_signals;
}

void p1_8::executeAvailableCommandsAndSignalsInState(V2_StateMachineController *smc)
{
	//StateMachineController::InputParametersContainer c;
	list<string> list_of_enabled_commands_and_signals = determineEnabledCommandAndSignalInState(smc);
	if(checkEnabledCommandAndSignalInState(smc))
	{
		std::list<string>::iterator it = list_of_enabled_commands_and_signals.begin();
		
		// Choose a random element from the list
		std::advance(it, rand() %list_of_enabled_commands_and_signals.size());

		// TODO: Do not match reply(*). Find out how to do this.
		#ifdef CLIENT_STUB_API

		#endif
		
		#ifndef CLIENT_STUB_API
		#endif
	}
	else
	{
		std::cout<<std::endl<<"ERROR: No Enabled Commands or Signals in State: p1_8"<<std::endl;
		//throw (StubException("EXCEPTION: No Enabled Commands or Signals in State: p1_8", NO_ENABLED_GUARDS));
	}
}

bool p1_8::checkEnabledCommandAndSignalInState(V2_StateMachineController *smc)
{
	if(determineEnabledCommandAndSignalInState(smc).empty())
			return false;
		else
			return true;
}

list<string> p1_8::determineEnabledCommandAndSignalInState(V2_StateMachineController *smc)
{
	list<string> enabled_commands_and_signals_list = isAtleastOneEnabledCommand(smc);
	enabled_commands_and_signals_list.splice(enabled_commands_and_signals_list.end(), isAtleastOneEnabledSignal(smc));
	return enabled_commands_and_signals_list;
}


bool p1_8::isAtleastOneEnabledNotification(V2_StateMachineController *smc)
{
	if( true )
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Concrete Deterministic Notification Handler: V2_outTRp1_6_19
void p1_8::V2_outTRp1_6_19(V2_StateMachineController *smc, int instance_id, int clause_id)
{
	bool isAtleastOneGuardEnabled = false;
	int instance_choice = instance_id;
	switch(instance_choice)
	{
		case 0: 
			// Guard Expression
			if(true)
			{
				isAtleastOneGuardEnabled = true;
				int clause_choice = clause_id;
					switch(clause_choice)
					{
					case 0:
							{
							// std::cout<<"Raising Notification: V2_outTRp1_6_19 -> Going From p1_8 to p1_1"<<std::endl;
							// smc->event_status_msg.push_back("State Changed: p1_8 => p1_1");
							#ifdef QT_GUI
								smc->event_status_msg.push_back(" <<<<<<<< Notification Raised: V2_outTRp1_6_19");
								smc->event_status_msg.push_back(" <!> State Update: p1_8 => p1_1");
							#endif
							smc->setTextColor("EVENT");
							std::cout<<std::endl<<" <<<<<<<< Notification Raised: V2_outTRp1_6_19"<<std::endl;
							std::cout<<" <!> State Update: p1_8 => p1_1"<<std::endl;
							smc->setTextColor("DATA");
							smc->setTextColor("ANY");
							smc->setCurrent(new p1_1());
							delete this;
							break;
							}
					default: 	std::cout<<"ERROR: Invalid random choice of Notification Clause!"<<std::endl;
								//throw (StubException("EXCEPTION: Invalid random choice of Notification Clause!", LOGICAL_ERROR));
								break;
					}// End of clause switch-case
			}
			break;
		default: 	std::cout<<"ERROR: Invalid random choice of Notification Instance!"<<std::endl;
					//throw (StubException("EXCEPTION: Invalid random choice of Notification Instance!", LOGICAL_ERROR));
					break;
	}// End of instance switch-case
	
	if(!isAtleastOneGuardEnabled)
	{
		smc->setTextColor("EVENT");
		std::cout<<"ERROR: NO GUARDS OF THIS NOTIFICATION ARE ENABLED!"<<std::endl;
		smc->event_status_msg.push_back("ERROR: NO GUARDS OF THIS NOTIFICATION ARE ENABLED in STATE: p1_8");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS OF THIS NOTIFICATION ARE ENABLED!", NO_ENABLED_GUARDS));
	}
}
// Concrete Notification Validator: V2_outTRp1_6_19
std::vector<int> p1_8::match_V2_outTRp1_6_19(V2_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
{
	std::vector<std::string> observed_notifications;
	std::vector<int> matched_instance_clause_id;
	bool is_equal = false;
	bool isAtleastOneGuardEnabled = true;
	bool isAtleastOneInstanceExecuted = false;
	
	for(int instance_choice = 0; instance_choice < 1; instance_choice++)
	{
	switch(instance_choice)
	{
		case 0: 
			// Guard Expression
			if(true)
			{
				isAtleastOneGuardEnabled = true;
				isAtleastOneInstanceExecuted = true;
				
				for(int clause_choice = 0; clause_choice < 1; clause_choice++)
				{
					switch(clause_choice)
					{
					case 0:	{
									const StateMachineController::V2_StateMachineController& smcRef = *smc;
									StateMachineController::smVarContainer var_copy(smcRef);
									observed_notifications.push_back("V2_outTRp1_6_19");
									bool is_equal = false;
									if (observed_notifications.size() == list_of_rcvd_notifications.size())
										is_equal = std::equal(observed_notifications.begin(), observed_notifications.end(), list_of_rcvd_notifications.begin());
									if (is_equal) { matched_instance_clause_id.push_back(0); matched_instance_clause_id.push_back(0); return matched_instance_clause_id; }
									else { observed_notifications.clear(); }		
									break;
								}
					default: 	std::cout<<"ERROR: Invalid random choice of Notification Clause"<<std::endl;
								//throw (StubException("EXCEPTION: Invalid random choice of Notification Clause!", LOGICAL_ERROR));
								break;
					}// End of clause switch-case
				}// End of clause selector for-loop
			}
			break;
		default: 	std::cout<<"ERROR: Invalid random choice of Notification Instance"<<std::endl;
					//throw (StubException("EXCEPTION: Invalid random choice of Notification Instance!", LOGICAL_ERROR));
					break;
	}// End of instance switch-case
	}// End of instance selector for-loop
	
	if(!isAtleastOneGuardEnabled)
	{
		smc->setTextColor("EVENT");
		std::cout<<"ERROR: NO GUARDS OF THIS NOTIFICATION ARE ENABLED!"<<std::endl;
		smc->event_status_msg.push_back("ERROR: NO GUARDS OF THIS NOTIFICATION ARE ENABLED in STATE: p1_8");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS OF THIS NOTIFICATION ARE ENABLED!", NO_ENABLED_GUARDS));
	}
	
	matched_instance_clause_id.push_back(UNDEFINED_CHOICE); 
	matched_instance_clause_id.push_back(UNDEFINED_CHOICE); 
	return matched_instance_clause_id;
}
// Concrete Notification Handler: V2_outTRp1_6_19
void p1_8::V2_outTRp1_6_19(V2_StateMachineController *smc)
{
	bool isAtleastOneGuardEnabled = true;
	bool isAtleastOneInstanceExecuted = false;
		// Guard Expression
		if(true && !isAtleastOneInstanceExecuted)
		{
			isAtleastOneGuardEnabled = true;
			isAtleastOneInstanceExecuted = true;
			int clause_choice = rand() %1;
			switch(clause_choice)
			{
			case 0:	{
						// std::cout<<"Raising Notification: V2_outTRp1_6_19 -> Going From p1_8 to p1_1"<<std::endl;
						// smc->event_status_msg.push_back("State Changed: p1_8 => p1_1");
						#ifdef QT_GUI
							smc->event_status_msg.push_back(" <<<<<<<< Notification Raised: V2_outTRp1_6_19");
							smc->event_status_msg.push_back(" <!> State Update: p1_8 => p1_1");
						#endif
						smc->setTextColor("EVENT");
						std::cout<<std::endl<<" <<<<<<<< Notification Raised: V2_outTRp1_6_19"<<std::endl;
						std::cout<<" <!> State Update: p1_8 => p1_1"<<std::endl;
						smc->setTextColor("DATA");
						smc->setTextColor("ANY");
						smc->setCurrent(new p1_1());
						delete this;
						return;
			}
			default: 	std::cout<<"ERROR: Invalid random choice of Notification Clause!"<<std::endl;
						//throw (StubException("EXCEPTION: Invalid random choice of Notification Clause!", LOGICAL_ERROR));
						break;
			}// End of clause switch-case
		}
	if(!isAtleastOneGuardEnabled)
	{
		smc->setTextColor("EVENT");
		std::cout<<"ERROR: NO GUARDS OF THIS NOTIFICATION ARE ENABLED!"<<std::endl;
		smc->event_status_msg.push_back("ERROR: NO GUARDS OF THIS NOTIFICATION ARE ENABLED in STATE: p1_8");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS OF THIS NOTIFICATION ARE ENABLED!", NO_ENABLED_GUARDS));
	}
}

void p1_8::executeInternalTransitions(V2_StateMachineController *smc)
{
	bool found_enabled_notification = false;
	if( true )
	{
	while(!found_enabled_notification)
	{
	int choice = rand() %1; //%END;
	switch(choice)
	{
		case 0:
					found_enabled_notification = true;
					// found_enabled_notification = true;
					#ifdef QT_GUI
					smc->event_status_msg.push_back(" <<<<<<<< Notification Raised: V2_outTRp1_6_19");
					smc->event_status_msg.push_back(" <!> State Update: p1_8 => p1_1");
					#endif
					smc->setTextColor("EVENT");
					std::cout<<std::endl<<" <<<<<<<< Notification Raised: V2_outTRp1_6_19"<<std::endl;
					std::cout<<" <!> State Update: p1_8 => p1_1"<<std::endl;
					smc->setTextColor("DATA");
					smc->setTextColor("ANY");
					// Note: For SSCF push the notification out here...
					#ifdef SSCF_VERSION
					
					smc->m_serverPtr->raiseNotification_outTRp1_6_19();
					#endif
					#ifndef SSCF_VERSION
					if(smc->m_niHandler != nullptr) smc->m_niHandler("V2_outTRp1_6_19");
					if(smc->m_outTRp1_6_19_Handler != nullptr)
					{
						smc->m_outTRp1_6_19_Handler();
					}
					#endif
					// smc->event_status_msg.push_back("State Changed: p1_8 => p1_1");
					smc->setCurrent(new p1_1());
					delete this;
					break;
		default: 	std::cout<<"ERROR: Invalid random choice of target state"<<std::endl;
					//throw (StubException("EXCEPTION: Invalid random choice of target state!", LOGICAL_ERROR));
					break;
	}
	}
	}
	else
	{
		// NO ENABLED GUARDS
		smc->setTextColor("EVENT");
		std::cout<<"ERROR: NONE OF THE NOTIFICATION GUARDS ARE ENABLED!"<<std::endl;
		smc->event_status_msg.push_back("ERROR: NONE OF THE NOTIFICATION GUARDS ARE ENABLED in STATE: p1_8");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NONE OF THE NOTIFICATION GUARDS ARE ENABLED in STATE: p1_8!", NO_ENABLED_GUARDS));
	}
}



/*********** Concrete State Class: p1_2 ***********/

list<string> p1_2::getCurrentCommandStatusList() 
{
	list<string> retStr;
	return retStr;
}

list<string> p1_2::getCurrentSignalStatusList()
{
	list<string> retStr;
	retStr.push_back("V2_inTRp1_1_11");
	return retStr;
}
		
list<string> p1_2::getCurrentNotificationStatusList()
{
	list<string> retStr;
	return retStr;
}

string p1_2::getCurrentState() { return name; }

list<string> p1_2::isAtleastOneEnabledCommand(V2_StateMachineController *smc)
{
	list<string> list_of_enabled_commands;
	//StateMachineController::InputParametersContainer c;
	return list_of_enabled_commands;
}
list<string> p1_2::isAtleastOneEnabledSignal(V2_StateMachineController *smc)
{
	list<string> list_of_enabled_signals;
	//StateMachineController::InputParametersContainer c;
	// Signal Name: V2_inTRp1_1_11
	{
	list_of_enabled_signals.push_back("V2_inTRp1_1_11");
	}
	return list_of_enabled_signals;
}

void p1_2::executeAvailableCommandsAndSignalsInState(V2_StateMachineController *smc)
{
	//StateMachineController::InputParametersContainer c;
	list<string> list_of_enabled_commands_and_signals = determineEnabledCommandAndSignalInState(smc);
	if(checkEnabledCommandAndSignalInState(smc))
	{
		std::list<string>::iterator it = list_of_enabled_commands_and_signals.begin();
		
		// Choose a random element from the list
		std::advance(it, rand() %list_of_enabled_commands_and_signals.size());

		// TODO: Do not match reply(*). Find out how to do this.
		#ifdef CLIENT_STUB_API

		if(!(*it).compare("V2_inTRp1_1_11"))
		{
			// #1. Call the interface function
			smc->client_api_handler->openEventContext();
			smc->client_api_handler->inTRp1_1_11();

			// #1a. Get the list of received notification and close the context.
			std::vector<string> list_of_rcvd_notifications = smc->client_api_handler->getListOfReceivedNotifications();
			//smc->client_api_handler->closeEventContext();
			std::cout << "[INFO] Number of Notifications Received in Context: " << list_of_rcvd_notifications.size() << std::endl;
			
			vector<int> instance_clause_id = V2_inTRp1_1_11( smc, list_of_rcvd_notifications);
			std::cout << std::endl << "Notifications List matched to Instance ID: " << instance_clause_id.at(0) << " and Clause ID: " << instance_clause_id.at(1) << std::endl;

			// #3. Call the the signal method
			V2_inTRp1_1_11( smc, instance_clause_id.at(0), instance_clause_id.at(1));
			smc->client_api_handler->closeEventContext();
		}
		#endif
		
		#ifndef CLIENT_STUB_API
		if(!(*it).compare("V2_inTRp1_1_11"))
		{
			
			std::cout << "Checking Instance-Clause Preferences for Signal: inTRp1_1_11" << std::endl;
			std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp1_1_11(smc->getCurrentState(), false);
			if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
			{
				// Call the function with Parameters Only
				std::cout << "No preferences found for Signal: inTRp1_1_11" << std::endl;
				
				// Call the function with Parameters
				V2_inTRp1_1_11( smc);
				smc->setTextColor("EVENT");
				std::cout<<std::endl<<" <<<<<<<< Command inTRp1_1_11 has been Executed!"<<std::endl;
				smc->setTextColor("ANY");
			}
			else
			{
				std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp1_1_11(smc->getCurrentState(), false);
				bool isAtleastOneInstanceEnabled = false;
				for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
				{
					if (isEnabledV2_inTRp1_1_11(smc, list_of_instance_id.at(i)))
					{
						instance_clause_id.at(0) = list_of_instance_id.at(i);
						std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp1_1_11(smc->getCurrentState(), list_of_instance_id.at(i), false);
						instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
						isAtleastOneInstanceEnabled = true;
					}
				}
				if(!isAtleastOneInstanceEnabled)
				{
					std::cout << "EXCEPTION: None of the instances of command: inTRp1_1_11 specified in the input file are enabled. Check the parameter set, if any!" << std::endl;
					//throw (StateMachineController::StubException("EXCEPTION: None of the instances of command: inTRp1_1_11 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));
				}
					
				// Call function with Parameters and Instance-Clause ID
				std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Command: inTRp1_1_11" << std::endl;
				
				// Call the function with Parameters
				V2_inTRp1_1_11( smc, instance_clause_id.at(0), instance_clause_id.at(1));
				smc->setTextColor("EVENT");
				std::cout<<std::endl<<" <<<<<<<< Command inTRp1_1_11 has been Executed!"<<std::endl;
				smc->setTextColor("ANY");
			}
		}
		#endif
	}
	else
	{
		std::cout<<std::endl<<"ERROR: No Enabled Commands or Signals in State: p1_2"<<std::endl;
		//throw (StubException("EXCEPTION: No Enabled Commands or Signals in State: p1_2", NO_ENABLED_GUARDS));
	}
}

bool p1_2::checkEnabledCommandAndSignalInState(V2_StateMachineController *smc)
{
	if(determineEnabledCommandAndSignalInState(smc).empty())
			return false;
		else
			return true;
}

list<string> p1_2::determineEnabledCommandAndSignalInState(V2_StateMachineController *smc)
{
	list<string> enabled_commands_and_signals_list = isAtleastOneEnabledCommand(smc);
	enabled_commands_and_signals_list.splice(enabled_commands_and_signals_list.end(), isAtleastOneEnabledSignal(smc));
	return enabled_commands_and_signals_list;
}


bool p1_2::isAtleastOneEnabledNotification(V2_StateMachineController *smc)
{
	UNREF_PARAM(smc);
	// Means there is no notification?
	return false;
}

// Enabling Test for Signal: V2_inTRp1_1_11
bool p1_2::isEnabledV2_inTRp1_1_11(V2_StateMachineController *smc, int instance_choice)
{
	// Switch Block for Signal Instances
	switch(instance_choice)
	{
		case 0: //Signal Instance
				// Guard Expression
				if(true)
				{
					return true;
				} // End of Guarded Block
				else
				{
					return false;
				}
				break;
		default: smc->setTextColor("EVENT");
				 std::cout<<"ERROR: Invalid Random Choice of Transition Instance [Enabling]"<<std::endl;
				 smc->setTextColor("ANY");
				 //throw (StubException("EXCEPTION: Invalid Random Choice of Transition Instance [Enabling]!", LOGICAL_ERROR));
				 break;
	} // End of Switch Block

	return false;
}
// Concrete Signal Context NI Validator: V2_inTRp1_1_11
std::vector<int> p1_2::V2_inTRp1_1_11(V2_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications)
{
	bool isAtleastOneGuardEnabled = true;
	bool isAtleastOneInstanceExecuted = false;
	
	std::vector<int> instance_clause_id;
	std::vector<std::string> observed_notifications;

	// Switch Block for Signal Instances
	for(int instance_choice = 0; instance_choice < 1; instance_choice++)
	{
	switch(instance_choice)
	{
		case 0: //Signal Instance
				// Guard Expression
				if(true)
				{
					isAtleastOneGuardEnabled = true;
					isAtleastOneInstanceExecuted = true;
					// Switch Block for Signal Clauses
					for(int choice = 0; choice < 1; choice++)
					{
					const StateMachineController::V2_StateMachineController& smcRef = *smc;
					StateMachineController::smVarContainer var_copy(smcRef);
					switch(choice)
					{
					case 0: // Signal Clause
							{
							smc->setTextColor("EVENT");
							#ifdef QT_GUI
							smc->event_status_msg.push_back(" >>>>>>>> Received Signal: inTRp1_1_11");
							smc->event_status_msg.push_back(" <!> State Update: p1_2 => p1_4");
							#endif
							// std::cout<<std::endl<<" >>>>>>>> Received Signal: inTRp1_1_11"<<std::endl;
							// std::cout<<" <!> State Update: From p1_2 => p1_4"<<std::endl;
							// smc->event_status_msg.push_back("State Changed: p1_2 => p1_4");
							smc->setTextColor("ANY");
							bool is_equal = false;
							if (observed_notifications.size() == list_of_rcvd_notifications.size())
								is_equal = std::equal(observed_notifications.begin(), observed_notifications.end(), list_of_rcvd_notifications.begin());
							if (is_equal) { instance_clause_id.push_back(0); instance_clause_id.push_back(0); return instance_clause_id; }
							else { observed_notifications.clear(); }
							smc->setTextColor("EVENT");
							// std::cout<<std::endl<<" <<<<<<<< Signal inTRp1_1_11 has been Executed!"<<std::endl;
							smc->setTextColor("ANY");
							break;
							}
					default: smc->setTextColor("EVENT");
							 std::cout<<"ERROR: Invalid random choice of Signal Clause"<<std::endl;
							 smc->setTextColor("ANY");
							 //throw (StubException("EXCEPTION: Invalid random choice of Signal Clause!", LOGICAL_ERROR));
							 break;
					} // End of Switch Block
					} // End of Clause For-Loop
				} // End of Guarded Block
				else {
					//smc->setTextColor("EVENT");
					//std::cout<<"FATAL: Choice of Signal Transition Instance and Clause in a Deterministic Context has Disabled Guards!"<<std::endl;
					//smc->setTextColor("ANY");
					////throw (StubException("EXCEPTION: Choice of Signal Transition Instance and Clause in a Deterministic Context has Disabled Guards!", INPUT_PARAMS_ERROR));
				}
				break;
		default: smc->setTextColor("EVENT");
				 std::cout<<"ERROR: Invalid random choice of Transition Instance"<<std::endl;
				 smc->setTextColor("ANY");
				 //throw (StubException("EXCEPTION: Invalid random choice of Transition Instance!", LOGICAL_ERROR));
				 break;
	} // End of Switch Block
	} // End of Instance For-Loop
	
	// To reach here means either none of the guards were true, or the reply did not match!
	if(!isAtleastOneGuardEnabled)
	{
		smc->setTextColor("EVENT");
		std::cout<<"ERROR: NO GUARDS FOR THIS SIGNAL ARE ENABLED!"<<std::endl;
		smc->event_status_msg.push_back("ERROR: NO GUARDS FOR THIS SIGNAL ARE ENABLED in STATE: p1_2");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS FOR THIS SIGNAL ARE ENABLED in STATE: p1_2!", NO_ENABLED_GUARDS));
		
	}
	else 
	{
		smc->setTextColor("EVENT");
		std::cout << "FATAL: THE RECEIVED NOTIFICATIONS IN CONTEXT OF SIGNAL COULD NOT BE MATCHED!" << std::endl;
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: THE RECEIVED NOTIFICATIONS IN CONTEXT OF SIGNAL COULD NOT BE MATCHED!", LOGICAL_ERROR));
	}
	// UNREACHABLE CODE. To be removed..
	instance_clause_id.push_back(UNDEFINED_CHOICE);
	instance_clause_id.push_back(UNDEFINED_CHOICE);
	return instance_clause_id;
}
// Concrete Deterministic Signal Handler: V2_inTRp1_1_11
void p1_2::V2_inTRp1_1_11(V2_StateMachineController *smc, int instance_id, int clause_id)
{
	bool isAtleastOneGuardEnabled = true;
	bool isAtleastOneInstanceExecuted = false;

	// Switch Block for Signal Clauses
	int instance_choice = instance_id; //rand() %1;
	switch(instance_choice)
	{
		case 0: //Signal Instance
				// Guard Expression
				if(true)
				{
					isAtleastOneGuardEnabled = true;
					isAtleastOneInstanceExecuted = true;
					// Switch Block for Signal Clauses
					int choice = clause_id; //rand() %1;
					switch(choice)
					{
					case 0: // Signal Clause
							smc->setTextColor("EVENT");
							#ifdef QT_GUI
							smc->event_status_msg.push_back(" >>>>>>>> Received Signal: inTRp1_1_11");
							smc->event_status_msg.push_back(" <!> State Update: p1_2 => p1_4");
							#endif
							std::cout<<std::endl<<" >>>>>>>> Received Signal: inTRp1_1_11"<<std::endl;
							std::cout<<" <!> State Update: From p1_2 => p1_4"<<std::endl;
							// smc->event_status_msg.push_back("State Changed: p1_2 => p1_4");
							smc->setTextColor("ANY");
							smc->setCurrent(new p1_4());
							delete this;
							smc->setTextColor("EVENT");
							std::cout<<std::endl<<" <<<<<<<< Signal inTRp1_1_11 has been Executed!"<<std::endl;
							smc->setTextColor("ANY");
							break;
					default: smc->setTextColor("EVENT");
							 std::cout<<"ERROR: Invalid random choice of target state"<<std::endl;
							 smc->setTextColor("ANY");
							 //throw (StubException("EXCEPTION: Invalid random choice of target state!", LOGICAL_ERROR));
							 break;
					} // End of Switch Block
				} // End of Guarded Block
				else {
					smc->setTextColor("EVENT");
					std::cout<<"FATAL: Choice of Signal Transition Instance and Clause in a Deterministic Context has Disabled Guards!"<<std::endl;
					smc->setTextColor("ANY");
					//throw (StubException("EXCEPTION: Choice of Signal Transition Instance and Clause in a Deterministic Context has Disabled Guards!", INPUT_PARAMS_ERROR));
				}
				break;
		default: smc->setTextColor("EVENT");
				 std::cout<<"ERROR: Invalid random choice of target state"<<std::endl;
				 smc->setTextColor("ANY");
				 //throw (StubException("EXCEPTION: Invalid random choice of target state!", LOGICAL_ERROR));
				 break;
	}
	if(!isAtleastOneGuardEnabled)
	{
		smc->setTextColor("EVENT");
		std::cout<<"ERROR: NO GUARDS FOR THIS SIGNAL ARE ENABLED!"<<std::endl;
		smc->event_status_msg.push_back("ERROR: NO GUARDS FOR THIS SIGNAL ARE ENABLED in STATE: p1_2");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS FOR THIS SIGNAL ARE ENABLED in STATE: p1_2!", NO_ENABLED_GUARDS));
		
	}
}
// Concrete Signal Handler: V2_inTRp1_1_11
void p1_2::V2_inTRp1_1_11(V2_StateMachineController *smc)
{
	bool isAtleastOneGuardEnabled = true;
	bool isAtleastOneInstanceExecuted = false;
	// Guard Expression
	if(true && !isAtleastOneInstanceExecuted)
	{
		isAtleastOneGuardEnabled = true;
		isAtleastOneInstanceExecuted = true;
		// Switch Block for Signal Clauses
		int choice = rand() %1;
		switch(choice)
		{
		case 0: // Signal Clause
				smc->setTextColor("EVENT");
				#ifdef QT_GUI
				smc->event_status_msg.push_back(" >>>>>>>> Received Signal: inTRp1_1_11");
				smc->event_status_msg.push_back(" <!> State Update: p1_2 => p1_4");
				#endif
				std::cout<<std::endl<<" >>>>>>>> Received Signal: inTRp1_1_11"<<std::endl;
				std::cout<<" <!> State Update: From p1_2 => p1_4"<<std::endl;
				// smc->event_status_msg.push_back("State Changed: p1_2 => p1_4");
				smc->setTextColor("ANY");
				smc->setCurrent(new p1_4());
				delete this;
				smc->setTextColor("EVENT");
				std::cout<<std::endl<<" <<<<<<<< Signal inTRp1_1_11 has been Executed!"<<std::endl;
				smc->setTextColor("ANY");
				break;
		default: smc->setTextColor("EVENT");
				 std::cout<<"ERROR: Invalid random choice of target state"<<std::endl;
				 smc->setTextColor("ANY");
				 //throw (StubException("EXCEPTION: Invalid random choice of target state!", LOGICAL_ERROR));
				 break;
		} // End of Switch Block
	} // End of Guarded Block
	if(!isAtleastOneGuardEnabled)
	{
		smc->setTextColor("EVENT");
		std::cout<<"ERROR: NO GUARDS FOR THIS SIGNAL ARE ENABLED!"<<std::endl;
		smc->event_status_msg.push_back("ERROR: NO GUARDS FOR THIS SIGNAL ARE ENABLED in STATE: p1_2");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS FOR THIS SIGNAL ARE ENABLED in STATE: p1_2!", NO_ENABLED_GUARDS));
		
	}
}




/*********** Concrete State Class: p2_1 ***********/

list<string> p2_1::getCurrentCommandStatusList() 
{
	list<string> retStr;
	return retStr;
}

list<string> p2_1::getCurrentSignalStatusList()
{
	list<string> retStr;
	retStr.push_back("V2_inTRp2_1_17");
	return retStr;
}
		
list<string> p2_1::getCurrentNotificationStatusList()
{
	list<string> retStr;
	return retStr;
}

string p2_1::getCurrentState() { return name; }

list<string> p2_1::isAtleastOneEnabledCommand(V2_StateMachineController *smc)
{
	list<string> list_of_enabled_commands;
	//StateMachineController::InputParametersContainer c;
	return list_of_enabled_commands;
}
list<string> p2_1::isAtleastOneEnabledSignal(V2_StateMachineController *smc)
{
	list<string> list_of_enabled_signals;
	//StateMachineController::InputParametersContainer c;
	// Signal Name: V2_inTRp2_1_17
	{
	list_of_enabled_signals.push_back("V2_inTRp2_1_17");
	}
	return list_of_enabled_signals;
}

void p2_1::executeAvailableCommandsAndSignalsInState(V2_StateMachineController *smc)
{
	//StateMachineController::InputParametersContainer c;
	list<string> list_of_enabled_commands_and_signals = determineEnabledCommandAndSignalInState(smc);
	if(checkEnabledCommandAndSignalInState(smc))
	{
		std::list<string>::iterator it = list_of_enabled_commands_and_signals.begin();
		
		// Choose a random element from the list
		std::advance(it, rand() %list_of_enabled_commands_and_signals.size());

		// TODO: Do not match reply(*). Find out how to do this.
		#ifdef CLIENT_STUB_API

		if(!(*it).compare("V2_inTRp2_1_17"))
		{
			// #1. Call the interface function
			smc->client_api_handler->openEventContext();
			smc->client_api_handler->inTRp2_1_17();

			// #1a. Get the list of received notification and close the context.
			std::vector<string> list_of_rcvd_notifications = smc->client_api_handler->getListOfReceivedNotifications();
			//smc->client_api_handler->closeEventContext();
			std::cout << "[INFO] Number of Notifications Received in Context: " << list_of_rcvd_notifications.size() << std::endl;
			
			vector<int> instance_clause_id = V2_inTRp2_1_17( smc, list_of_rcvd_notifications);
			std::cout << std::endl << "Notifications List matched to Instance ID: " << instance_clause_id.at(0) << " and Clause ID: " << instance_clause_id.at(1) << std::endl;

			// #3. Call the the signal method
			V2_inTRp2_1_17( smc, instance_clause_id.at(0), instance_clause_id.at(1));
			smc->client_api_handler->closeEventContext();
		}
		#endif
		
		#ifndef CLIENT_STUB_API
		if(!(*it).compare("V2_inTRp2_1_17"))
		{
			
			std::cout << "Checking Instance-Clause Preferences for Signal: inTRp2_1_17" << std::endl;
			std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp2_1_17(smc->getCurrentState(), false);
			if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
			{
				// Call the function with Parameters Only
				std::cout << "No preferences found for Signal: inTRp2_1_17" << std::endl;
				
				// Call the function with Parameters
				V2_inTRp2_1_17( smc);
				smc->setTextColor("EVENT");
				std::cout<<std::endl<<" <<<<<<<< Command inTRp2_1_17 has been Executed!"<<std::endl;
				smc->setTextColor("ANY");
			}
			else
			{
				std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp2_1_17(smc->getCurrentState(), false);
				bool isAtleastOneInstanceEnabled = false;
				for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
				{
					if (isEnabledV2_inTRp2_1_17(smc, list_of_instance_id.at(i)))
					{
						instance_clause_id.at(0) = list_of_instance_id.at(i);
						std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp2_1_17(smc->getCurrentState(), list_of_instance_id.at(i), false);
						instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
						isAtleastOneInstanceEnabled = true;
					}
				}
				if(!isAtleastOneInstanceEnabled)
				{
					std::cout << "EXCEPTION: None of the instances of command: inTRp2_1_17 specified in the input file are enabled. Check the parameter set, if any!" << std::endl;
					//throw (StateMachineController::StubException("EXCEPTION: None of the instances of command: inTRp2_1_17 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));
				}
					
				// Call function with Parameters and Instance-Clause ID
				std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Command: inTRp2_1_17" << std::endl;
				
				// Call the function with Parameters
				V2_inTRp2_1_17( smc, instance_clause_id.at(0), instance_clause_id.at(1));
				smc->setTextColor("EVENT");
				std::cout<<std::endl<<" <<<<<<<< Command inTRp2_1_17 has been Executed!"<<std::endl;
				smc->setTextColor("ANY");
			}
		}
		#endif
	}
	else
	{
		std::cout<<std::endl<<"ERROR: No Enabled Commands or Signals in State: p2_1"<<std::endl;
		//throw (StubException("EXCEPTION: No Enabled Commands or Signals in State: p2_1", NO_ENABLED_GUARDS));
	}
}

bool p2_1::checkEnabledCommandAndSignalInState(V2_StateMachineController *smc)
{
	if(determineEnabledCommandAndSignalInState(smc).empty())
			return false;
		else
			return true;
}

list<string> p2_1::determineEnabledCommandAndSignalInState(V2_StateMachineController *smc)
{
	list<string> enabled_commands_and_signals_list = isAtleastOneEnabledCommand(smc);
	enabled_commands_and_signals_list.splice(enabled_commands_and_signals_list.end(), isAtleastOneEnabledSignal(smc));
	return enabled_commands_and_signals_list;
}


bool p2_1::isAtleastOneEnabledNotification(V2_StateMachineController *smc)
{
	UNREF_PARAM(smc);
	// Means there is no notification?
	return false;
}

// Enabling Test for Signal: V2_inTRp2_1_17
bool p2_1::isEnabledV2_inTRp2_1_17(V2_StateMachineController *smc, int instance_choice)
{
	// Switch Block for Signal Instances
	switch(instance_choice)
	{
		case 0: //Signal Instance
				// Guard Expression
				if(true)
				{
					return true;
				} // End of Guarded Block
				else
				{
					return false;
				}
				break;
		default: smc->setTextColor("EVENT");
				 std::cout<<"ERROR: Invalid Random Choice of Transition Instance [Enabling]"<<std::endl;
				 smc->setTextColor("ANY");
				 //throw (StubException("EXCEPTION: Invalid Random Choice of Transition Instance [Enabling]!", LOGICAL_ERROR));
				 break;
	} // End of Switch Block

	return false;
}
// Concrete Signal Context NI Validator: V2_inTRp2_1_17
std::vector<int> p2_1::V2_inTRp2_1_17(V2_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications)
{
	bool isAtleastOneGuardEnabled = true;
	bool isAtleastOneInstanceExecuted = false;
	
	std::vector<int> instance_clause_id;
	std::vector<std::string> observed_notifications;

	// Switch Block for Signal Instances
	for(int instance_choice = 0; instance_choice < 1; instance_choice++)
	{
	switch(instance_choice)
	{
		case 0: //Signal Instance
				// Guard Expression
				if(true)
				{
					isAtleastOneGuardEnabled = true;
					isAtleastOneInstanceExecuted = true;
					// Switch Block for Signal Clauses
					for(int choice = 0; choice < 1; choice++)
					{
					const StateMachineController::V2_StateMachineController& smcRef = *smc;
					StateMachineController::smVarContainer var_copy(smcRef);
					switch(choice)
					{
					case 0: // Signal Clause
							{
							smc->setTextColor("EVENT");
							#ifdef QT_GUI
							smc->event_status_msg.push_back(" >>>>>>>> Received Signal: inTRp2_1_17");
							smc->event_status_msg.push_back(" <!> State Update: p2_1 => p1_2");
							#endif
							// std::cout<<std::endl<<" >>>>>>>> Received Signal: inTRp2_1_17"<<std::endl;
							// std::cout<<" <!> State Update: From p2_1 => p1_2"<<std::endl;
							// smc->event_status_msg.push_back("State Changed: p2_1 => p1_2");
							smc->setTextColor("ANY");
							bool is_equal = false;
							if (observed_notifications.size() == list_of_rcvd_notifications.size())
								is_equal = std::equal(observed_notifications.begin(), observed_notifications.end(), list_of_rcvd_notifications.begin());
							if (is_equal) { instance_clause_id.push_back(0); instance_clause_id.push_back(0); return instance_clause_id; }
							else { observed_notifications.clear(); }
							smc->setTextColor("EVENT");
							// std::cout<<std::endl<<" <<<<<<<< Signal inTRp2_1_17 has been Executed!"<<std::endl;
							smc->setTextColor("ANY");
							break;
							}
					default: smc->setTextColor("EVENT");
							 std::cout<<"ERROR: Invalid random choice of Signal Clause"<<std::endl;
							 smc->setTextColor("ANY");
							 //throw (StubException("EXCEPTION: Invalid random choice of Signal Clause!", LOGICAL_ERROR));
							 break;
					} // End of Switch Block
					} // End of Clause For-Loop
				} // End of Guarded Block
				else {
					//smc->setTextColor("EVENT");
					//std::cout<<"FATAL: Choice of Signal Transition Instance and Clause in a Deterministic Context has Disabled Guards!"<<std::endl;
					//smc->setTextColor("ANY");
					////throw (StubException("EXCEPTION: Choice of Signal Transition Instance and Clause in a Deterministic Context has Disabled Guards!", INPUT_PARAMS_ERROR));
				}
				break;
		default: smc->setTextColor("EVENT");
				 std::cout<<"ERROR: Invalid random choice of Transition Instance"<<std::endl;
				 smc->setTextColor("ANY");
				 //throw (StubException("EXCEPTION: Invalid random choice of Transition Instance!", LOGICAL_ERROR));
				 break;
	} // End of Switch Block
	} // End of Instance For-Loop
	
	// To reach here means either none of the guards were true, or the reply did not match!
	if(!isAtleastOneGuardEnabled)
	{
		smc->setTextColor("EVENT");
		std::cout<<"ERROR: NO GUARDS FOR THIS SIGNAL ARE ENABLED!"<<std::endl;
		smc->event_status_msg.push_back("ERROR: NO GUARDS FOR THIS SIGNAL ARE ENABLED in STATE: p2_1");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS FOR THIS SIGNAL ARE ENABLED in STATE: p2_1!", NO_ENABLED_GUARDS));
		
	}
	else 
	{
		smc->setTextColor("EVENT");
		std::cout << "FATAL: THE RECEIVED NOTIFICATIONS IN CONTEXT OF SIGNAL COULD NOT BE MATCHED!" << std::endl;
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: THE RECEIVED NOTIFICATIONS IN CONTEXT OF SIGNAL COULD NOT BE MATCHED!", LOGICAL_ERROR));
	}
	// UNREACHABLE CODE. To be removed..
	instance_clause_id.push_back(UNDEFINED_CHOICE);
	instance_clause_id.push_back(UNDEFINED_CHOICE);
	return instance_clause_id;
}
// Concrete Deterministic Signal Handler: V2_inTRp2_1_17
void p2_1::V2_inTRp2_1_17(V2_StateMachineController *smc, int instance_id, int clause_id)
{
	bool isAtleastOneGuardEnabled = true;
	bool isAtleastOneInstanceExecuted = false;

	// Switch Block for Signal Clauses
	int instance_choice = instance_id; //rand() %1;
	switch(instance_choice)
	{
		case 0: //Signal Instance
				// Guard Expression
				if(true)
				{
					isAtleastOneGuardEnabled = true;
					isAtleastOneInstanceExecuted = true;
					// Switch Block for Signal Clauses
					int choice = clause_id; //rand() %1;
					switch(choice)
					{
					case 0: // Signal Clause
							smc->setTextColor("EVENT");
							#ifdef QT_GUI
							smc->event_status_msg.push_back(" >>>>>>>> Received Signal: inTRp2_1_17");
							smc->event_status_msg.push_back(" <!> State Update: p2_1 => p1_2");
							#endif
							std::cout<<std::endl<<" >>>>>>>> Received Signal: inTRp2_1_17"<<std::endl;
							std::cout<<" <!> State Update: From p2_1 => p1_2"<<std::endl;
							// smc->event_status_msg.push_back("State Changed: p2_1 => p1_2");
							smc->setTextColor("ANY");
							smc->setCurrent(new p1_2());
							delete this;
							smc->setTextColor("EVENT");
							std::cout<<std::endl<<" <<<<<<<< Signal inTRp2_1_17 has been Executed!"<<std::endl;
							smc->setTextColor("ANY");
							break;
					default: smc->setTextColor("EVENT");
							 std::cout<<"ERROR: Invalid random choice of target state"<<std::endl;
							 smc->setTextColor("ANY");
							 //throw (StubException("EXCEPTION: Invalid random choice of target state!", LOGICAL_ERROR));
							 break;
					} // End of Switch Block
				} // End of Guarded Block
				else {
					smc->setTextColor("EVENT");
					std::cout<<"FATAL: Choice of Signal Transition Instance and Clause in a Deterministic Context has Disabled Guards!"<<std::endl;
					smc->setTextColor("ANY");
					//throw (StubException("EXCEPTION: Choice of Signal Transition Instance and Clause in a Deterministic Context has Disabled Guards!", INPUT_PARAMS_ERROR));
				}
				break;
		default: smc->setTextColor("EVENT");
				 std::cout<<"ERROR: Invalid random choice of target state"<<std::endl;
				 smc->setTextColor("ANY");
				 //throw (StubException("EXCEPTION: Invalid random choice of target state!", LOGICAL_ERROR));
				 break;
	}
	if(!isAtleastOneGuardEnabled)
	{
		smc->setTextColor("EVENT");
		std::cout<<"ERROR: NO GUARDS FOR THIS SIGNAL ARE ENABLED!"<<std::endl;
		smc->event_status_msg.push_back("ERROR: NO GUARDS FOR THIS SIGNAL ARE ENABLED in STATE: p2_1");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS FOR THIS SIGNAL ARE ENABLED in STATE: p2_1!", NO_ENABLED_GUARDS));
		
	}
}
// Concrete Signal Handler: V2_inTRp2_1_17
void p2_1::V2_inTRp2_1_17(V2_StateMachineController *smc)
{
	bool isAtleastOneGuardEnabled = true;
	bool isAtleastOneInstanceExecuted = false;
	// Guard Expression
	if(true && !isAtleastOneInstanceExecuted)
	{
		isAtleastOneGuardEnabled = true;
		isAtleastOneInstanceExecuted = true;
		// Switch Block for Signal Clauses
		int choice = rand() %1;
		switch(choice)
		{
		case 0: // Signal Clause
				smc->setTextColor("EVENT");
				#ifdef QT_GUI
				smc->event_status_msg.push_back(" >>>>>>>> Received Signal: inTRp2_1_17");
				smc->event_status_msg.push_back(" <!> State Update: p2_1 => p1_2");
				#endif
				std::cout<<std::endl<<" >>>>>>>> Received Signal: inTRp2_1_17"<<std::endl;
				std::cout<<" <!> State Update: From p2_1 => p1_2"<<std::endl;
				// smc->event_status_msg.push_back("State Changed: p2_1 => p1_2");
				smc->setTextColor("ANY");
				smc->setCurrent(new p1_2());
				delete this;
				smc->setTextColor("EVENT");
				std::cout<<std::endl<<" <<<<<<<< Signal inTRp2_1_17 has been Executed!"<<std::endl;
				smc->setTextColor("ANY");
				break;
		default: smc->setTextColor("EVENT");
				 std::cout<<"ERROR: Invalid random choice of target state"<<std::endl;
				 smc->setTextColor("ANY");
				 //throw (StubException("EXCEPTION: Invalid random choice of target state!", LOGICAL_ERROR));
				 break;
		} // End of Switch Block
	} // End of Guarded Block
	if(!isAtleastOneGuardEnabled)
	{
		smc->setTextColor("EVENT");
		std::cout<<"ERROR: NO GUARDS FOR THIS SIGNAL ARE ENABLED!"<<std::endl;
		smc->event_status_msg.push_back("ERROR: NO GUARDS FOR THIS SIGNAL ARE ENABLED in STATE: p2_1");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS FOR THIS SIGNAL ARE ENABLED in STATE: p2_1!", NO_ENABLED_GUARDS));
		
	}
}




/*********** Concrete State Class: p3_1 ***********/

list<string> p3_1::getCurrentCommandStatusList() 
{
	list<string> retStr;
	return retStr;
}

list<string> p3_1::getCurrentSignalStatusList()
{
	list<string> retStr;
	retStr.push_back("V2_inTRp3_1_18");
	return retStr;
}
		
list<string> p3_1::getCurrentNotificationStatusList()
{
	list<string> retStr;
	return retStr;
}

string p3_1::getCurrentState() { return name; }

list<string> p3_1::isAtleastOneEnabledCommand(V2_StateMachineController *smc)
{
	list<string> list_of_enabled_commands;
	//StateMachineController::InputParametersContainer c;
	return list_of_enabled_commands;
}
list<string> p3_1::isAtleastOneEnabledSignal(V2_StateMachineController *smc)
{
	list<string> list_of_enabled_signals;
	//StateMachineController::InputParametersContainer c;
	// Signal Name: V2_inTRp3_1_18
	{
	list_of_enabled_signals.push_back("V2_inTRp3_1_18");
	}
	return list_of_enabled_signals;
}

void p3_1::executeAvailableCommandsAndSignalsInState(V2_StateMachineController *smc)
{
	//StateMachineController::InputParametersContainer c;
	list<string> list_of_enabled_commands_and_signals = determineEnabledCommandAndSignalInState(smc);
	if(checkEnabledCommandAndSignalInState(smc))
	{
		std::list<string>::iterator it = list_of_enabled_commands_and_signals.begin();
		
		// Choose a random element from the list
		std::advance(it, rand() %list_of_enabled_commands_and_signals.size());

		// TODO: Do not match reply(*). Find out how to do this.
		#ifdef CLIENT_STUB_API

		if(!(*it).compare("V2_inTRp3_1_18"))
		{
			// #1. Call the interface function
			smc->client_api_handler->openEventContext();
			smc->client_api_handler->inTRp3_1_18();

			// #1a. Get the list of received notification and close the context.
			std::vector<string> list_of_rcvd_notifications = smc->client_api_handler->getListOfReceivedNotifications();
			//smc->client_api_handler->closeEventContext();
			std::cout << "[INFO] Number of Notifications Received in Context: " << list_of_rcvd_notifications.size() << std::endl;
			
			vector<int> instance_clause_id = V2_inTRp3_1_18( smc, list_of_rcvd_notifications);
			std::cout << std::endl << "Notifications List matched to Instance ID: " << instance_clause_id.at(0) << " and Clause ID: " << instance_clause_id.at(1) << std::endl;

			// #3. Call the the signal method
			V2_inTRp3_1_18( smc, instance_clause_id.at(0), instance_clause_id.at(1));
			smc->client_api_handler->closeEventContext();
		}
		#endif
		
		#ifndef CLIENT_STUB_API
		if(!(*it).compare("V2_inTRp3_1_18"))
		{
			
			std::cout << "Checking Instance-Clause Preferences for Signal: inTRp3_1_18" << std::endl;
			std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp3_1_18(smc->getCurrentState(), false);
			if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
			{
				// Call the function with Parameters Only
				std::cout << "No preferences found for Signal: inTRp3_1_18" << std::endl;
				
				// Call the function with Parameters
				V2_inTRp3_1_18( smc);
				smc->setTextColor("EVENT");
				std::cout<<std::endl<<" <<<<<<<< Command inTRp3_1_18 has been Executed!"<<std::endl;
				smc->setTextColor("ANY");
			}
			else
			{
				std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp3_1_18(smc->getCurrentState(), false);
				bool isAtleastOneInstanceEnabled = false;
				for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
				{
					if (isEnabledV2_inTRp3_1_18(smc, list_of_instance_id.at(i)))
					{
						instance_clause_id.at(0) = list_of_instance_id.at(i);
						std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp3_1_18(smc->getCurrentState(), list_of_instance_id.at(i), false);
						instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
						isAtleastOneInstanceEnabled = true;
					}
				}
				if(!isAtleastOneInstanceEnabled)
				{
					std::cout << "EXCEPTION: None of the instances of command: inTRp3_1_18 specified in the input file are enabled. Check the parameter set, if any!" << std::endl;
					//throw (StateMachineController::StubException("EXCEPTION: None of the instances of command: inTRp3_1_18 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));
				}
					
				// Call function with Parameters and Instance-Clause ID
				std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Command: inTRp3_1_18" << std::endl;
				
				// Call the function with Parameters
				V2_inTRp3_1_18( smc, instance_clause_id.at(0), instance_clause_id.at(1));
				smc->setTextColor("EVENT");
				std::cout<<std::endl<<" <<<<<<<< Command inTRp3_1_18 has been Executed!"<<std::endl;
				smc->setTextColor("ANY");
			}
		}
		#endif
	}
	else
	{
		std::cout<<std::endl<<"ERROR: No Enabled Commands or Signals in State: p3_1"<<std::endl;
		//throw (StubException("EXCEPTION: No Enabled Commands or Signals in State: p3_1", NO_ENABLED_GUARDS));
	}
}

bool p3_1::checkEnabledCommandAndSignalInState(V2_StateMachineController *smc)
{
	if(determineEnabledCommandAndSignalInState(smc).empty())
			return false;
		else
			return true;
}

list<string> p3_1::determineEnabledCommandAndSignalInState(V2_StateMachineController *smc)
{
	list<string> enabled_commands_and_signals_list = isAtleastOneEnabledCommand(smc);
	enabled_commands_and_signals_list.splice(enabled_commands_and_signals_list.end(), isAtleastOneEnabledSignal(smc));
	return enabled_commands_and_signals_list;
}


bool p3_1::isAtleastOneEnabledNotification(V2_StateMachineController *smc)
{
	UNREF_PARAM(smc);
	// Means there is no notification?
	return false;
}

// Enabling Test for Signal: V2_inTRp3_1_18
bool p3_1::isEnabledV2_inTRp3_1_18(V2_StateMachineController *smc, int instance_choice)
{
	// Switch Block for Signal Instances
	switch(instance_choice)
	{
		case 0: //Signal Instance
				// Guard Expression
				if(true)
				{
					return true;
				} // End of Guarded Block
				else
				{
					return false;
				}
				break;
		default: smc->setTextColor("EVENT");
				 std::cout<<"ERROR: Invalid Random Choice of Transition Instance [Enabling]"<<std::endl;
				 smc->setTextColor("ANY");
				 //throw (StubException("EXCEPTION: Invalid Random Choice of Transition Instance [Enabling]!", LOGICAL_ERROR));
				 break;
	} // End of Switch Block

	return false;
}
// Concrete Signal Context NI Validator: V2_inTRp3_1_18
std::vector<int> p3_1::V2_inTRp3_1_18(V2_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications)
{
	bool isAtleastOneGuardEnabled = true;
	bool isAtleastOneInstanceExecuted = false;
	
	std::vector<int> instance_clause_id;
	std::vector<std::string> observed_notifications;

	// Switch Block for Signal Instances
	for(int instance_choice = 0; instance_choice < 1; instance_choice++)
	{
	switch(instance_choice)
	{
		case 0: //Signal Instance
				// Guard Expression
				if(true)
				{
					isAtleastOneGuardEnabled = true;
					isAtleastOneInstanceExecuted = true;
					// Switch Block for Signal Clauses
					for(int choice = 0; choice < 1; choice++)
					{
					const StateMachineController::V2_StateMachineController& smcRef = *smc;
					StateMachineController::smVarContainer var_copy(smcRef);
					switch(choice)
					{
					case 0: // Signal Clause
							{
							smc->setTextColor("EVENT");
							#ifdef QT_GUI
							smc->event_status_msg.push_back(" >>>>>>>> Received Signal: inTRp3_1_18");
							smc->event_status_msg.push_back(" <!> State Update: p3_1 => p1_2");
							#endif
							// std::cout<<std::endl<<" >>>>>>>> Received Signal: inTRp3_1_18"<<std::endl;
							// std::cout<<" <!> State Update: From p3_1 => p1_2"<<std::endl;
							// smc->event_status_msg.push_back("State Changed: p3_1 => p1_2");
							smc->setTextColor("ANY");
							bool is_equal = false;
							if (observed_notifications.size() == list_of_rcvd_notifications.size())
								is_equal = std::equal(observed_notifications.begin(), observed_notifications.end(), list_of_rcvd_notifications.begin());
							if (is_equal) { instance_clause_id.push_back(0); instance_clause_id.push_back(0); return instance_clause_id; }
							else { observed_notifications.clear(); }
							smc->setTextColor("EVENT");
							// std::cout<<std::endl<<" <<<<<<<< Signal inTRp3_1_18 has been Executed!"<<std::endl;
							smc->setTextColor("ANY");
							break;
							}
					default: smc->setTextColor("EVENT");
							 std::cout<<"ERROR: Invalid random choice of Signal Clause"<<std::endl;
							 smc->setTextColor("ANY");
							 //throw (StubException("EXCEPTION: Invalid random choice of Signal Clause!", LOGICAL_ERROR));
							 break;
					} // End of Switch Block
					} // End of Clause For-Loop
				} // End of Guarded Block
				else {
					//smc->setTextColor("EVENT");
					//std::cout<<"FATAL: Choice of Signal Transition Instance and Clause in a Deterministic Context has Disabled Guards!"<<std::endl;
					//smc->setTextColor("ANY");
					////throw (StubException("EXCEPTION: Choice of Signal Transition Instance and Clause in a Deterministic Context has Disabled Guards!", INPUT_PARAMS_ERROR));
				}
				break;
		default: smc->setTextColor("EVENT");
				 std::cout<<"ERROR: Invalid random choice of Transition Instance"<<std::endl;
				 smc->setTextColor("ANY");
				 //throw (StubException("EXCEPTION: Invalid random choice of Transition Instance!", LOGICAL_ERROR));
				 break;
	} // End of Switch Block
	} // End of Instance For-Loop
	
	// To reach here means either none of the guards were true, or the reply did not match!
	if(!isAtleastOneGuardEnabled)
	{
		smc->setTextColor("EVENT");
		std::cout<<"ERROR: NO GUARDS FOR THIS SIGNAL ARE ENABLED!"<<std::endl;
		smc->event_status_msg.push_back("ERROR: NO GUARDS FOR THIS SIGNAL ARE ENABLED in STATE: p3_1");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS FOR THIS SIGNAL ARE ENABLED in STATE: p3_1!", NO_ENABLED_GUARDS));
		
	}
	else 
	{
		smc->setTextColor("EVENT");
		std::cout << "FATAL: THE RECEIVED NOTIFICATIONS IN CONTEXT OF SIGNAL COULD NOT BE MATCHED!" << std::endl;
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: THE RECEIVED NOTIFICATIONS IN CONTEXT OF SIGNAL COULD NOT BE MATCHED!", LOGICAL_ERROR));
	}
	// UNREACHABLE CODE. To be removed..
	instance_clause_id.push_back(UNDEFINED_CHOICE);
	instance_clause_id.push_back(UNDEFINED_CHOICE);
	return instance_clause_id;
}
// Concrete Deterministic Signal Handler: V2_inTRp3_1_18
void p3_1::V2_inTRp3_1_18(V2_StateMachineController *smc, int instance_id, int clause_id)
{
	bool isAtleastOneGuardEnabled = true;
	bool isAtleastOneInstanceExecuted = false;

	// Switch Block for Signal Clauses
	int instance_choice = instance_id; //rand() %1;
	switch(instance_choice)
	{
		case 0: //Signal Instance
				// Guard Expression
				if(true)
				{
					isAtleastOneGuardEnabled = true;
					isAtleastOneInstanceExecuted = true;
					// Switch Block for Signal Clauses
					int choice = clause_id; //rand() %1;
					switch(choice)
					{
					case 0: // Signal Clause
							smc->setTextColor("EVENT");
							#ifdef QT_GUI
							smc->event_status_msg.push_back(" >>>>>>>> Received Signal: inTRp3_1_18");
							smc->event_status_msg.push_back(" <!> State Update: p3_1 => p1_2");
							#endif
							std::cout<<std::endl<<" >>>>>>>> Received Signal: inTRp3_1_18"<<std::endl;
							std::cout<<" <!> State Update: From p3_1 => p1_2"<<std::endl;
							// smc->event_status_msg.push_back("State Changed: p3_1 => p1_2");
							smc->setTextColor("ANY");
							smc->setCurrent(new p1_2());
							delete this;
							smc->setTextColor("EVENT");
							std::cout<<std::endl<<" <<<<<<<< Signal inTRp3_1_18 has been Executed!"<<std::endl;
							smc->setTextColor("ANY");
							break;
					default: smc->setTextColor("EVENT");
							 std::cout<<"ERROR: Invalid random choice of target state"<<std::endl;
							 smc->setTextColor("ANY");
							 //throw (StubException("EXCEPTION: Invalid random choice of target state!", LOGICAL_ERROR));
							 break;
					} // End of Switch Block
				} // End of Guarded Block
				else {
					smc->setTextColor("EVENT");
					std::cout<<"FATAL: Choice of Signal Transition Instance and Clause in a Deterministic Context has Disabled Guards!"<<std::endl;
					smc->setTextColor("ANY");
					//throw (StubException("EXCEPTION: Choice of Signal Transition Instance and Clause in a Deterministic Context has Disabled Guards!", INPUT_PARAMS_ERROR));
				}
				break;
		default: smc->setTextColor("EVENT");
				 std::cout<<"ERROR: Invalid random choice of target state"<<std::endl;
				 smc->setTextColor("ANY");
				 //throw (StubException("EXCEPTION: Invalid random choice of target state!", LOGICAL_ERROR));
				 break;
	}
	if(!isAtleastOneGuardEnabled)
	{
		smc->setTextColor("EVENT");
		std::cout<<"ERROR: NO GUARDS FOR THIS SIGNAL ARE ENABLED!"<<std::endl;
		smc->event_status_msg.push_back("ERROR: NO GUARDS FOR THIS SIGNAL ARE ENABLED in STATE: p3_1");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS FOR THIS SIGNAL ARE ENABLED in STATE: p3_1!", NO_ENABLED_GUARDS));
		
	}
}
// Concrete Signal Handler: V2_inTRp3_1_18
void p3_1::V2_inTRp3_1_18(V2_StateMachineController *smc)
{
	bool isAtleastOneGuardEnabled = true;
	bool isAtleastOneInstanceExecuted = false;
	// Guard Expression
	if(true && !isAtleastOneInstanceExecuted)
	{
		isAtleastOneGuardEnabled = true;
		isAtleastOneInstanceExecuted = true;
		// Switch Block for Signal Clauses
		int choice = rand() %1;
		switch(choice)
		{
		case 0: // Signal Clause
				smc->setTextColor("EVENT");
				#ifdef QT_GUI
				smc->event_status_msg.push_back(" >>>>>>>> Received Signal: inTRp3_1_18");
				smc->event_status_msg.push_back(" <!> State Update: p3_1 => p1_2");
				#endif
				std::cout<<std::endl<<" >>>>>>>> Received Signal: inTRp3_1_18"<<std::endl;
				std::cout<<" <!> State Update: From p3_1 => p1_2"<<std::endl;
				// smc->event_status_msg.push_back("State Changed: p3_1 => p1_2");
				smc->setTextColor("ANY");
				smc->setCurrent(new p1_2());
				delete this;
				smc->setTextColor("EVENT");
				std::cout<<std::endl<<" <<<<<<<< Signal inTRp3_1_18 has been Executed!"<<std::endl;
				smc->setTextColor("ANY");
				break;
		default: smc->setTextColor("EVENT");
				 std::cout<<"ERROR: Invalid random choice of target state"<<std::endl;
				 smc->setTextColor("ANY");
				 //throw (StubException("EXCEPTION: Invalid random choice of target state!", LOGICAL_ERROR));
				 break;
		} // End of Switch Block
	} // End of Guarded Block
	if(!isAtleastOneGuardEnabled)
	{
		smc->setTextColor("EVENT");
		std::cout<<"ERROR: NO GUARDS FOR THIS SIGNAL ARE ENABLED!"<<std::endl;
		smc->event_status_msg.push_back("ERROR: NO GUARDS FOR THIS SIGNAL ARE ENABLED in STATE: p3_1");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS FOR THIS SIGNAL ARE ENABLED in STATE: p3_1!", NO_ENABLED_GUARDS));
		
	}
}




/*********** Concrete State Class: p1_11 ***********/

list<string> p1_11::getCurrentCommandStatusList() 
{
	list<string> retStr;
	return retStr;
}

list<string> p1_11::getCurrentSignalStatusList()
{
	list<string> retStr;
	return retStr;
}
		
list<string> p1_11::getCurrentNotificationStatusList()
{
	list<string> retStr;
	return retStr;
}

string p1_11::getCurrentState() { return name; }

list<string> p1_11::isAtleastOneEnabledCommand(V2_StateMachineController *smc)
{
	list<string> list_of_enabled_commands;
	//StateMachineController::InputParametersContainer c;
	return list_of_enabled_commands;
}
list<string> p1_11::isAtleastOneEnabledSignal(V2_StateMachineController *smc)
{
	list<string> list_of_enabled_signals;
	//StateMachineController::InputParametersContainer c;
	return list_of_enabled_signals;
}

void p1_11::executeAvailableCommandsAndSignalsInState(V2_StateMachineController *smc)
{
	//StateMachineController::InputParametersContainer c;
	list<string> list_of_enabled_commands_and_signals = determineEnabledCommandAndSignalInState(smc);
	if(checkEnabledCommandAndSignalInState(smc))
	{
		std::list<string>::iterator it = list_of_enabled_commands_and_signals.begin();
		
		// Choose a random element from the list
		std::advance(it, rand() %list_of_enabled_commands_and_signals.size());

		// TODO: Do not match reply(*). Find out how to do this.
		#ifdef CLIENT_STUB_API

		#endif
		
		#ifndef CLIENT_STUB_API
		#endif
	}
	else
	{
		std::cout<<std::endl<<"ERROR: No Enabled Commands or Signals in State: p1_11"<<std::endl;
		//throw (StubException("EXCEPTION: No Enabled Commands or Signals in State: p1_11", NO_ENABLED_GUARDS));
	}
}

bool p1_11::checkEnabledCommandAndSignalInState(V2_StateMachineController *smc)
{
	if(determineEnabledCommandAndSignalInState(smc).empty())
			return false;
		else
			return true;
}

list<string> p1_11::determineEnabledCommandAndSignalInState(V2_StateMachineController *smc)
{
	list<string> enabled_commands_and_signals_list = isAtleastOneEnabledCommand(smc);
	enabled_commands_and_signals_list.splice(enabled_commands_and_signals_list.end(), isAtleastOneEnabledSignal(smc));
	return enabled_commands_and_signals_list;
}


bool p1_11::isAtleastOneEnabledNotification(V2_StateMachineController *smc)
{
	UNREF_PARAM(smc);
	// Means there is no notification?
	return false;
}





/*********** Concrete State Class: p1_7 ***********/

list<string> p1_7::getCurrentCommandStatusList() 
{
	list<string> retStr;
	return retStr;
}

list<string> p1_7::getCurrentSignalStatusList()
{
	list<string> retStr;
	retStr.push_back("V2_inTRp1_4_14");
	return retStr;
}
		
list<string> p1_7::getCurrentNotificationStatusList()
{
	list<string> retStr;
	return retStr;
}

string p1_7::getCurrentState() { return name; }

list<string> p1_7::isAtleastOneEnabledCommand(V2_StateMachineController *smc)
{
	list<string> list_of_enabled_commands;
	//StateMachineController::InputParametersContainer c;
	return list_of_enabled_commands;
}
list<string> p1_7::isAtleastOneEnabledSignal(V2_StateMachineController *smc)
{
	list<string> list_of_enabled_signals;
	//StateMachineController::InputParametersContainer c;
	// Signal Name: V2_inTRp1_4_14
	{
	list_of_enabled_signals.push_back("V2_inTRp1_4_14");
	}
	return list_of_enabled_signals;
}

void p1_7::executeAvailableCommandsAndSignalsInState(V2_StateMachineController *smc)
{
	//StateMachineController::InputParametersContainer c;
	list<string> list_of_enabled_commands_and_signals = determineEnabledCommandAndSignalInState(smc);
	if(checkEnabledCommandAndSignalInState(smc))
	{
		std::list<string>::iterator it = list_of_enabled_commands_and_signals.begin();
		
		// Choose a random element from the list
		std::advance(it, rand() %list_of_enabled_commands_and_signals.size());

		// TODO: Do not match reply(*). Find out how to do this.
		#ifdef CLIENT_STUB_API

		if(!(*it).compare("V2_inTRp1_4_14"))
		{
			// #1. Call the interface function
			smc->client_api_handler->openEventContext();
			smc->client_api_handler->inTRp1_4_14();

			// #1a. Get the list of received notification and close the context.
			std::vector<string> list_of_rcvd_notifications = smc->client_api_handler->getListOfReceivedNotifications();
			//smc->client_api_handler->closeEventContext();
			std::cout << "[INFO] Number of Notifications Received in Context: " << list_of_rcvd_notifications.size() << std::endl;
			
			vector<int> instance_clause_id = V2_inTRp1_4_14( smc, list_of_rcvd_notifications);
			std::cout << std::endl << "Notifications List matched to Instance ID: " << instance_clause_id.at(0) << " and Clause ID: " << instance_clause_id.at(1) << std::endl;

			// #3. Call the the signal method
			V2_inTRp1_4_14( smc, instance_clause_id.at(0), instance_clause_id.at(1));
			smc->client_api_handler->closeEventContext();
		}
		#endif
		
		#ifndef CLIENT_STUB_API
		if(!(*it).compare("V2_inTRp1_4_14"))
		{
			
			std::cout << "Checking Instance-Clause Preferences for Signal: inTRp1_4_14" << std::endl;
			std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp1_4_14(smc->getCurrentState(), false);
			if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
			{
				// Call the function with Parameters Only
				std::cout << "No preferences found for Signal: inTRp1_4_14" << std::endl;
				
				// Call the function with Parameters
				V2_inTRp1_4_14( smc);
				smc->setTextColor("EVENT");
				std::cout<<std::endl<<" <<<<<<<< Command inTRp1_4_14 has been Executed!"<<std::endl;
				smc->setTextColor("ANY");
			}
			else
			{
				std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp1_4_14(smc->getCurrentState(), false);
				bool isAtleastOneInstanceEnabled = false;
				for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
				{
					if (isEnabledV2_inTRp1_4_14(smc, list_of_instance_id.at(i)))
					{
						instance_clause_id.at(0) = list_of_instance_id.at(i);
						std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp1_4_14(smc->getCurrentState(), list_of_instance_id.at(i), false);
						instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
						isAtleastOneInstanceEnabled = true;
					}
				}
				if(!isAtleastOneInstanceEnabled)
				{
					std::cout << "EXCEPTION: None of the instances of command: inTRp1_4_14 specified in the input file are enabled. Check the parameter set, if any!" << std::endl;
					//throw (StateMachineController::StubException("EXCEPTION: None of the instances of command: inTRp1_4_14 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));
				}
					
				// Call function with Parameters and Instance-Clause ID
				std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Command: inTRp1_4_14" << std::endl;
				
				// Call the function with Parameters
				V2_inTRp1_4_14( smc, instance_clause_id.at(0), instance_clause_id.at(1));
				smc->setTextColor("EVENT");
				std::cout<<std::endl<<" <<<<<<<< Command inTRp1_4_14 has been Executed!"<<std::endl;
				smc->setTextColor("ANY");
			}
		}
		#endif
	}
	else
	{
		std::cout<<std::endl<<"ERROR: No Enabled Commands or Signals in State: p1_7"<<std::endl;
		//throw (StubException("EXCEPTION: No Enabled Commands or Signals in State: p1_7", NO_ENABLED_GUARDS));
	}
}

bool p1_7::checkEnabledCommandAndSignalInState(V2_StateMachineController *smc)
{
	if(determineEnabledCommandAndSignalInState(smc).empty())
			return false;
		else
			return true;
}

list<string> p1_7::determineEnabledCommandAndSignalInState(V2_StateMachineController *smc)
{
	list<string> enabled_commands_and_signals_list = isAtleastOneEnabledCommand(smc);
	enabled_commands_and_signals_list.splice(enabled_commands_and_signals_list.end(), isAtleastOneEnabledSignal(smc));
	return enabled_commands_and_signals_list;
}


bool p1_7::isAtleastOneEnabledNotification(V2_StateMachineController *smc)
{
	UNREF_PARAM(smc);
	// Means there is no notification?
	return false;
}

// Enabling Test for Signal: V2_inTRp1_4_14
bool p1_7::isEnabledV2_inTRp1_4_14(V2_StateMachineController *smc, int instance_choice)
{
	// Switch Block for Signal Instances
	switch(instance_choice)
	{
		case 0: //Signal Instance
				// Guard Expression
				if(true)
				{
					return true;
				} // End of Guarded Block
				else
				{
					return false;
				}
				break;
		default: smc->setTextColor("EVENT");
				 std::cout<<"ERROR: Invalid Random Choice of Transition Instance [Enabling]"<<std::endl;
				 smc->setTextColor("ANY");
				 //throw (StubException("EXCEPTION: Invalid Random Choice of Transition Instance [Enabling]!", LOGICAL_ERROR));
				 break;
	} // End of Switch Block

	return false;
}
// Concrete Signal Context NI Validator: V2_inTRp1_4_14
std::vector<int> p1_7::V2_inTRp1_4_14(V2_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications)
{
	bool isAtleastOneGuardEnabled = true;
	bool isAtleastOneInstanceExecuted = false;
	
	std::vector<int> instance_clause_id;
	std::vector<std::string> observed_notifications;

	// Switch Block for Signal Instances
	for(int instance_choice = 0; instance_choice < 1; instance_choice++)
	{
	switch(instance_choice)
	{
		case 0: //Signal Instance
				// Guard Expression
				if(true)
				{
					isAtleastOneGuardEnabled = true;
					isAtleastOneInstanceExecuted = true;
					// Switch Block for Signal Clauses
					for(int choice = 0; choice < 1; choice++)
					{
					const StateMachineController::V2_StateMachineController& smcRef = *smc;
					StateMachineController::smVarContainer var_copy(smcRef);
					switch(choice)
					{
					case 0: // Signal Clause
							{
							smc->setTextColor("EVENT");
							#ifdef QT_GUI
							smc->event_status_msg.push_back(" >>>>>>>> Received Signal: inTRp1_4_14");
							smc->event_status_msg.push_back(" <!> State Update: p1_7 => p1_8");
							#endif
							// std::cout<<std::endl<<" >>>>>>>> Received Signal: inTRp1_4_14"<<std::endl;
							// std::cout<<" <!> State Update: From p1_7 => p1_8"<<std::endl;
							// smc->event_status_msg.push_back("State Changed: p1_7 => p1_8");
							smc->setTextColor("ANY");
							bool is_equal = false;
							if (observed_notifications.size() == list_of_rcvd_notifications.size())
								is_equal = std::equal(observed_notifications.begin(), observed_notifications.end(), list_of_rcvd_notifications.begin());
							if (is_equal) { instance_clause_id.push_back(0); instance_clause_id.push_back(0); return instance_clause_id; }
							else { observed_notifications.clear(); }
							smc->setTextColor("EVENT");
							// std::cout<<std::endl<<" <<<<<<<< Signal inTRp1_4_14 has been Executed!"<<std::endl;
							smc->setTextColor("ANY");
							break;
							}
					default: smc->setTextColor("EVENT");
							 std::cout<<"ERROR: Invalid random choice of Signal Clause"<<std::endl;
							 smc->setTextColor("ANY");
							 //throw (StubException("EXCEPTION: Invalid random choice of Signal Clause!", LOGICAL_ERROR));
							 break;
					} // End of Switch Block
					} // End of Clause For-Loop
				} // End of Guarded Block
				else {
					//smc->setTextColor("EVENT");
					//std::cout<<"FATAL: Choice of Signal Transition Instance and Clause in a Deterministic Context has Disabled Guards!"<<std::endl;
					//smc->setTextColor("ANY");
					////throw (StubException("EXCEPTION: Choice of Signal Transition Instance and Clause in a Deterministic Context has Disabled Guards!", INPUT_PARAMS_ERROR));
				}
				break;
		default: smc->setTextColor("EVENT");
				 std::cout<<"ERROR: Invalid random choice of Transition Instance"<<std::endl;
				 smc->setTextColor("ANY");
				 //throw (StubException("EXCEPTION: Invalid random choice of Transition Instance!", LOGICAL_ERROR));
				 break;
	} // End of Switch Block
	} // End of Instance For-Loop
	
	// To reach here means either none of the guards were true, or the reply did not match!
	if(!isAtleastOneGuardEnabled)
	{
		smc->setTextColor("EVENT");
		std::cout<<"ERROR: NO GUARDS FOR THIS SIGNAL ARE ENABLED!"<<std::endl;
		smc->event_status_msg.push_back("ERROR: NO GUARDS FOR THIS SIGNAL ARE ENABLED in STATE: p1_7");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS FOR THIS SIGNAL ARE ENABLED in STATE: p1_7!", NO_ENABLED_GUARDS));
		
	}
	else 
	{
		smc->setTextColor("EVENT");
		std::cout << "FATAL: THE RECEIVED NOTIFICATIONS IN CONTEXT OF SIGNAL COULD NOT BE MATCHED!" << std::endl;
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: THE RECEIVED NOTIFICATIONS IN CONTEXT OF SIGNAL COULD NOT BE MATCHED!", LOGICAL_ERROR));
	}
	// UNREACHABLE CODE. To be removed..
	instance_clause_id.push_back(UNDEFINED_CHOICE);
	instance_clause_id.push_back(UNDEFINED_CHOICE);
	return instance_clause_id;
}
// Concrete Deterministic Signal Handler: V2_inTRp1_4_14
void p1_7::V2_inTRp1_4_14(V2_StateMachineController *smc, int instance_id, int clause_id)
{
	bool isAtleastOneGuardEnabled = true;
	bool isAtleastOneInstanceExecuted = false;

	// Switch Block for Signal Clauses
	int instance_choice = instance_id; //rand() %1;
	switch(instance_choice)
	{
		case 0: //Signal Instance
				// Guard Expression
				if(true)
				{
					isAtleastOneGuardEnabled = true;
					isAtleastOneInstanceExecuted = true;
					// Switch Block for Signal Clauses
					int choice = clause_id; //rand() %1;
					switch(choice)
					{
					case 0: // Signal Clause
							smc->setTextColor("EVENT");
							#ifdef QT_GUI
							smc->event_status_msg.push_back(" >>>>>>>> Received Signal: inTRp1_4_14");
							smc->event_status_msg.push_back(" <!> State Update: p1_7 => p1_8");
							#endif
							std::cout<<std::endl<<" >>>>>>>> Received Signal: inTRp1_4_14"<<std::endl;
							std::cout<<" <!> State Update: From p1_7 => p1_8"<<std::endl;
							// smc->event_status_msg.push_back("State Changed: p1_7 => p1_8");
							smc->setTextColor("ANY");
							smc->setCurrent(new p1_8());
							delete this;
							smc->setTextColor("EVENT");
							std::cout<<std::endl<<" <<<<<<<< Signal inTRp1_4_14 has been Executed!"<<std::endl;
							smc->setTextColor("ANY");
							break;
					default: smc->setTextColor("EVENT");
							 std::cout<<"ERROR: Invalid random choice of target state"<<std::endl;
							 smc->setTextColor("ANY");
							 //throw (StubException("EXCEPTION: Invalid random choice of target state!", LOGICAL_ERROR));
							 break;
					} // End of Switch Block
				} // End of Guarded Block
				else {
					smc->setTextColor("EVENT");
					std::cout<<"FATAL: Choice of Signal Transition Instance and Clause in a Deterministic Context has Disabled Guards!"<<std::endl;
					smc->setTextColor("ANY");
					//throw (StubException("EXCEPTION: Choice of Signal Transition Instance and Clause in a Deterministic Context has Disabled Guards!", INPUT_PARAMS_ERROR));
				}
				break;
		default: smc->setTextColor("EVENT");
				 std::cout<<"ERROR: Invalid random choice of target state"<<std::endl;
				 smc->setTextColor("ANY");
				 //throw (StubException("EXCEPTION: Invalid random choice of target state!", LOGICAL_ERROR));
				 break;
	}
	if(!isAtleastOneGuardEnabled)
	{
		smc->setTextColor("EVENT");
		std::cout<<"ERROR: NO GUARDS FOR THIS SIGNAL ARE ENABLED!"<<std::endl;
		smc->event_status_msg.push_back("ERROR: NO GUARDS FOR THIS SIGNAL ARE ENABLED in STATE: p1_7");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS FOR THIS SIGNAL ARE ENABLED in STATE: p1_7!", NO_ENABLED_GUARDS));
		
	}
}
// Concrete Signal Handler: V2_inTRp1_4_14
void p1_7::V2_inTRp1_4_14(V2_StateMachineController *smc)
{
	bool isAtleastOneGuardEnabled = true;
	bool isAtleastOneInstanceExecuted = false;
	// Guard Expression
	if(true && !isAtleastOneInstanceExecuted)
	{
		isAtleastOneGuardEnabled = true;
		isAtleastOneInstanceExecuted = true;
		// Switch Block for Signal Clauses
		int choice = rand() %1;
		switch(choice)
		{
		case 0: // Signal Clause
				smc->setTextColor("EVENT");
				#ifdef QT_GUI
				smc->event_status_msg.push_back(" >>>>>>>> Received Signal: inTRp1_4_14");
				smc->event_status_msg.push_back(" <!> State Update: p1_7 => p1_8");
				#endif
				std::cout<<std::endl<<" >>>>>>>> Received Signal: inTRp1_4_14"<<std::endl;
				std::cout<<" <!> State Update: From p1_7 => p1_8"<<std::endl;
				// smc->event_status_msg.push_back("State Changed: p1_7 => p1_8");
				smc->setTextColor("ANY");
				smc->setCurrent(new p1_8());
				delete this;
				smc->setTextColor("EVENT");
				std::cout<<std::endl<<" <<<<<<<< Signal inTRp1_4_14 has been Executed!"<<std::endl;
				smc->setTextColor("ANY");
				break;
		default: smc->setTextColor("EVENT");
				 std::cout<<"ERROR: Invalid random choice of target state"<<std::endl;
				 smc->setTextColor("ANY");
				 //throw (StubException("EXCEPTION: Invalid random choice of target state!", LOGICAL_ERROR));
				 break;
		} // End of Switch Block
	} // End of Guarded Block
	if(!isAtleastOneGuardEnabled)
	{
		smc->setTextColor("EVENT");
		std::cout<<"ERROR: NO GUARDS FOR THIS SIGNAL ARE ENABLED!"<<std::endl;
		smc->event_status_msg.push_back("ERROR: NO GUARDS FOR THIS SIGNAL ARE ENABLED in STATE: p1_7");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS FOR THIS SIGNAL ARE ENABLED in STATE: p1_7!", NO_ENABLED_GUARDS));
		
	}
}




/*********** Concrete State Class: p1_10 ***********/

list<string> p1_10::getCurrentCommandStatusList() 
{
	list<string> retStr;
	return retStr;
}

list<string> p1_10::getCurrentSignalStatusList()
{
	list<string> retStr;
	return retStr;
}
		
list<string> p1_10::getCurrentNotificationStatusList()
{
	list<string> retStr;
	retStr.push_back("V2_outTRp1_8_21");
	return retStr;
}

string p1_10::getCurrentState() { return name; }

list<string> p1_10::isAtleastOneEnabledCommand(V2_StateMachineController *smc)
{
	list<string> list_of_enabled_commands;
	//StateMachineController::InputParametersContainer c;
	return list_of_enabled_commands;
}
list<string> p1_10::isAtleastOneEnabledSignal(V2_StateMachineController *smc)
{
	list<string> list_of_enabled_signals;
	//StateMachineController::InputParametersContainer c;
	return list_of_enabled_signals;
}

void p1_10::executeAvailableCommandsAndSignalsInState(V2_StateMachineController *smc)
{
	//StateMachineController::InputParametersContainer c;
	list<string> list_of_enabled_commands_and_signals = determineEnabledCommandAndSignalInState(smc);
	if(checkEnabledCommandAndSignalInState(smc))
	{
		std::list<string>::iterator it = list_of_enabled_commands_and_signals.begin();
		
		// Choose a random element from the list
		std::advance(it, rand() %list_of_enabled_commands_and_signals.size());

		// TODO: Do not match reply(*). Find out how to do this.
		#ifdef CLIENT_STUB_API

		#endif
		
		#ifndef CLIENT_STUB_API
		#endif
	}
	else
	{
		std::cout<<std::endl<<"ERROR: No Enabled Commands or Signals in State: p1_10"<<std::endl;
		//throw (StubException("EXCEPTION: No Enabled Commands or Signals in State: p1_10", NO_ENABLED_GUARDS));
	}
}

bool p1_10::checkEnabledCommandAndSignalInState(V2_StateMachineController *smc)
{
	if(determineEnabledCommandAndSignalInState(smc).empty())
			return false;
		else
			return true;
}

list<string> p1_10::determineEnabledCommandAndSignalInState(V2_StateMachineController *smc)
{
	list<string> enabled_commands_and_signals_list = isAtleastOneEnabledCommand(smc);
	enabled_commands_and_signals_list.splice(enabled_commands_and_signals_list.end(), isAtleastOneEnabledSignal(smc));
	return enabled_commands_and_signals_list;
}


bool p1_10::isAtleastOneEnabledNotification(V2_StateMachineController *smc)
{
	if( true )
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Concrete Deterministic Notification Handler: V2_outTRp1_8_21
void p1_10::V2_outTRp1_8_21(V2_StateMachineController *smc, int instance_id, int clause_id)
{
	bool isAtleastOneGuardEnabled = false;
	int instance_choice = instance_id;
	switch(instance_choice)
	{
		case 0: 
			// Guard Expression
			if(true)
			{
				isAtleastOneGuardEnabled = true;
				int clause_choice = clause_id;
					switch(clause_choice)
					{
					case 0:
							{
							// std::cout<<"Raising Notification: V2_outTRp1_8_21 -> Going From p1_10 to p1_11"<<std::endl;
							// smc->event_status_msg.push_back("State Changed: p1_10 => p1_11");
							#ifdef QT_GUI
								smc->event_status_msg.push_back(" <<<<<<<< Notification Raised: V2_outTRp1_8_21");
								smc->event_status_msg.push_back(" <!> State Update: p1_10 => p1_11");
							#endif
							smc->setTextColor("EVENT");
							std::cout<<std::endl<<" <<<<<<<< Notification Raised: V2_outTRp1_8_21"<<std::endl;
							std::cout<<" <!> State Update: p1_10 => p1_11"<<std::endl;
							smc->setTextColor("DATA");
							smc->setTextColor("ANY");
							smc->setCurrent(new p1_11());
							delete this;
							break;
							}
					default: 	std::cout<<"ERROR: Invalid random choice of Notification Clause!"<<std::endl;
								//throw (StubException("EXCEPTION: Invalid random choice of Notification Clause!", LOGICAL_ERROR));
								break;
					}// End of clause switch-case
			}
			break;
		default: 	std::cout<<"ERROR: Invalid random choice of Notification Instance!"<<std::endl;
					//throw (StubException("EXCEPTION: Invalid random choice of Notification Instance!", LOGICAL_ERROR));
					break;
	}// End of instance switch-case
	
	if(!isAtleastOneGuardEnabled)
	{
		smc->setTextColor("EVENT");
		std::cout<<"ERROR: NO GUARDS OF THIS NOTIFICATION ARE ENABLED!"<<std::endl;
		smc->event_status_msg.push_back("ERROR: NO GUARDS OF THIS NOTIFICATION ARE ENABLED in STATE: p1_10");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS OF THIS NOTIFICATION ARE ENABLED!", NO_ENABLED_GUARDS));
	}
}
// Concrete Notification Validator: V2_outTRp1_8_21
std::vector<int> p1_10::match_V2_outTRp1_8_21(V2_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
{
	std::vector<std::string> observed_notifications;
	std::vector<int> matched_instance_clause_id;
	bool is_equal = false;
	bool isAtleastOneGuardEnabled = true;
	bool isAtleastOneInstanceExecuted = false;
	
	for(int instance_choice = 0; instance_choice < 1; instance_choice++)
	{
	switch(instance_choice)
	{
		case 0: 
			// Guard Expression
			if(true)
			{
				isAtleastOneGuardEnabled = true;
				isAtleastOneInstanceExecuted = true;
				
				for(int clause_choice = 0; clause_choice < 1; clause_choice++)
				{
					switch(clause_choice)
					{
					case 0:	{
									const StateMachineController::V2_StateMachineController& smcRef = *smc;
									StateMachineController::smVarContainer var_copy(smcRef);
									observed_notifications.push_back("V2_outTRp1_8_21");
									bool is_equal = false;
									if (observed_notifications.size() == list_of_rcvd_notifications.size())
										is_equal = std::equal(observed_notifications.begin(), observed_notifications.end(), list_of_rcvd_notifications.begin());
									if (is_equal) { matched_instance_clause_id.push_back(0); matched_instance_clause_id.push_back(0); return matched_instance_clause_id; }
									else { observed_notifications.clear(); }		
									break;
								}
					default: 	std::cout<<"ERROR: Invalid random choice of Notification Clause"<<std::endl;
								//throw (StubException("EXCEPTION: Invalid random choice of Notification Clause!", LOGICAL_ERROR));
								break;
					}// End of clause switch-case
				}// End of clause selector for-loop
			}
			break;
		default: 	std::cout<<"ERROR: Invalid random choice of Notification Instance"<<std::endl;
					//throw (StubException("EXCEPTION: Invalid random choice of Notification Instance!", LOGICAL_ERROR));
					break;
	}// End of instance switch-case
	}// End of instance selector for-loop
	
	if(!isAtleastOneGuardEnabled)
	{
		smc->setTextColor("EVENT");
		std::cout<<"ERROR: NO GUARDS OF THIS NOTIFICATION ARE ENABLED!"<<std::endl;
		smc->event_status_msg.push_back("ERROR: NO GUARDS OF THIS NOTIFICATION ARE ENABLED in STATE: p1_10");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS OF THIS NOTIFICATION ARE ENABLED!", NO_ENABLED_GUARDS));
	}
	
	matched_instance_clause_id.push_back(UNDEFINED_CHOICE); 
	matched_instance_clause_id.push_back(UNDEFINED_CHOICE); 
	return matched_instance_clause_id;
}
// Concrete Notification Handler: V2_outTRp1_8_21
void p1_10::V2_outTRp1_8_21(V2_StateMachineController *smc)
{
	bool isAtleastOneGuardEnabled = true;
	bool isAtleastOneInstanceExecuted = false;
		// Guard Expression
		if(true && !isAtleastOneInstanceExecuted)
		{
			isAtleastOneGuardEnabled = true;
			isAtleastOneInstanceExecuted = true;
			int clause_choice = rand() %1;
			switch(clause_choice)
			{
			case 0:	{
						// std::cout<<"Raising Notification: V2_outTRp1_8_21 -> Going From p1_10 to p1_11"<<std::endl;
						// smc->event_status_msg.push_back("State Changed: p1_10 => p1_11");
						#ifdef QT_GUI
							smc->event_status_msg.push_back(" <<<<<<<< Notification Raised: V2_outTRp1_8_21");
							smc->event_status_msg.push_back(" <!> State Update: p1_10 => p1_11");
						#endif
						smc->setTextColor("EVENT");
						std::cout<<std::endl<<" <<<<<<<< Notification Raised: V2_outTRp1_8_21"<<std::endl;
						std::cout<<" <!> State Update: p1_10 => p1_11"<<std::endl;
						smc->setTextColor("DATA");
						smc->setTextColor("ANY");
						smc->setCurrent(new p1_11());
						delete this;
						return;
			}
			default: 	std::cout<<"ERROR: Invalid random choice of Notification Clause!"<<std::endl;
						//throw (StubException("EXCEPTION: Invalid random choice of Notification Clause!", LOGICAL_ERROR));
						break;
			}// End of clause switch-case
		}
	if(!isAtleastOneGuardEnabled)
	{
		smc->setTextColor("EVENT");
		std::cout<<"ERROR: NO GUARDS OF THIS NOTIFICATION ARE ENABLED!"<<std::endl;
		smc->event_status_msg.push_back("ERROR: NO GUARDS OF THIS NOTIFICATION ARE ENABLED in STATE: p1_10");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS OF THIS NOTIFICATION ARE ENABLED!", NO_ENABLED_GUARDS));
	}
}

void p1_10::executeInternalTransitions(V2_StateMachineController *smc)
{
	bool found_enabled_notification = false;
	if( true )
	{
	while(!found_enabled_notification)
	{
	int choice = rand() %1; //%END;
	switch(choice)
	{
		case 0:
					found_enabled_notification = true;
					// found_enabled_notification = true;
					#ifdef QT_GUI
					smc->event_status_msg.push_back(" <<<<<<<< Notification Raised: V2_outTRp1_8_21");
					smc->event_status_msg.push_back(" <!> State Update: p1_10 => p1_11");
					#endif
					smc->setTextColor("EVENT");
					std::cout<<std::endl<<" <<<<<<<< Notification Raised: V2_outTRp1_8_21"<<std::endl;
					std::cout<<" <!> State Update: p1_10 => p1_11"<<std::endl;
					smc->setTextColor("DATA");
					smc->setTextColor("ANY");
					// Note: For SSCF push the notification out here...
					#ifdef SSCF_VERSION
					
					smc->m_serverPtr->raiseNotification_outTRp1_8_21();
					#endif
					#ifndef SSCF_VERSION
					if(smc->m_niHandler != nullptr) smc->m_niHandler("V2_outTRp1_8_21");
					if(smc->m_outTRp1_8_21_Handler != nullptr)
					{
						smc->m_outTRp1_8_21_Handler();
					}
					#endif
					// smc->event_status_msg.push_back("State Changed: p1_10 => p1_11");
					smc->setCurrent(new p1_11());
					delete this;
					break;
		default: 	std::cout<<"ERROR: Invalid random choice of target state"<<std::endl;
					//throw (StubException("EXCEPTION: Invalid random choice of target state!", LOGICAL_ERROR));
					break;
	}
	}
	}
	else
	{
		// NO ENABLED GUARDS
		smc->setTextColor("EVENT");
		std::cout<<"ERROR: NONE OF THE NOTIFICATION GUARDS ARE ENABLED!"<<std::endl;
		smc->event_status_msg.push_back("ERROR: NONE OF THE NOTIFICATION GUARDS ARE ENABLED in STATE: p1_10");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NONE OF THE NOTIFICATION GUARDS ARE ENABLED in STATE: p1_10!", NO_ENABLED_GUARDS));
	}
}

}
