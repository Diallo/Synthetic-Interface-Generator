#include "V1_StateMachineController.h"
#ifdef CLIENT_STUB_API
#include "V1StubAdapterImpl.h"
#endif

namespace StateMachineController {

#ifdef SSCF_VERSION
V1_StateMachineController::V1_StateMachineController(
					class EventRepository *er,
					class UNDEFINED::V1Server *srv, int sim_mode) {
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
	client_api_handler->getNIHandler().register_outTRp1_2_25_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_2_25_clHandler);
	client_api_handler->getNIHandler().register_outTRp1_3_26_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_3_26_clHandler);
	client_api_handler->getNIHandler().register_outTRp1_5_28_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_5_28_clHandler);
	client_api_handler->getNIHandler().register_outTRp1_6_29_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_6_29_clHandler);
	client_api_handler->getNIHandler().register_outTRp1_6_30_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_6_30_clHandler);
	#endif
	
	run_simulation = true;
	// std::cout<<std::endl<<"INFO: State Machine Controller has been Constructed!"<<std::endl;
	// std::cout<<"INFO: Notification Callback Thread is Running..."<<std::endl;
}
#endif
#ifndef SSCF_VERSION
#ifdef SSCF_CLIENT_STUB_ADAPTER
V1_StateMachineController::V1_StateMachineController(class EventRepository *er, int sim_mode, 
	SscfClientConnection<UNDEFINED::V1Proxy, UNDEFINED::V1>& m_connection) {
#endif
#ifndef SSCF_CLIENT_STUB_ADAPTER
V1_StateMachineController::V1_StateMachineController(class EventRepository *er, int sim_mode) {
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
	client_api_handler->getNIHandler().register_outTRp1_2_25_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_2_25_clHandler);
	client_api_handler->getNIHandler().register_outTRp1_3_26_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_3_26_clHandler);
	client_api_handler->getNIHandler().register_outTRp1_5_28_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_5_28_clHandler);
	client_api_handler->getNIHandler().register_outTRp1_6_29_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_6_29_clHandler);
	client_api_handler->getNIHandler().register_outTRp1_6_30_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_6_30_clHandler);
	#endif

	run_simulation = true;
	// std::cout<<std::endl<<"INFO: State Machine Controller has been Constructed!"<<std::endl;
	// std::cout<<"INFO: Notification Callback Thread has been Constructed!"<<std::endl;
}
#endif
#ifdef QT_GUI
V1_StateMachineController::V1_StateMachineController(class EventRepository *er, class MainWindow *mw, int sim_mode) {
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
	client_api_handler->getNIHandler().register_outTRp1_2_25_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_2_25_clHandler);
	client_api_handler->getNIHandler().register_outTRp1_3_26_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_3_26_clHandler);
	client_api_handler->getNIHandler().register_outTRp1_5_28_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_5_28_clHandler);
	client_api_handler->getNIHandler().register_outTRp1_6_29_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_6_29_clHandler);
	client_api_handler->getNIHandler().register_outTRp1_6_30_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_6_30_clHandler);
	#endif

	run_simulation = true;
	// std::cout<<std::endl<<"INFO: State Machine Controller has been Constructed!"<<std::endl;
	// std::cout<<"INFO: Notification Callback Thread has been Constructed!"<<std::endl;
}		
#endif
V1_StateMachineController::~V1_StateMachineController() 
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

void V1_StateMachineController::setSimMode(int sim_mode) 
{ 
	timer->setSimMode(sim_mode);
	publishToEventRepo(m_eventRepo);
}

void V1_StateMachineController::toggleSimulation(bool print_vars)
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

void V1_StateMachineController::setTextColor(string col)
{
}

string V1_StateMachineController::getCurrentState()
{
	return current->getCurrentState();
}

list<string> V1_StateMachineController::getCurrentCommandStatusList()
{
	return current->getCurrentCommandStatusList();
}

list<string> V1_StateMachineController::getCurrentSignalStatusList()
{
	return current->getCurrentSignalStatusList();
}

list<string> V1_StateMachineController::getCurrentNotificationStatusList()
{
	return current->getCurrentNotificationStatusList();
}

void V1_StateMachineController::publishToEventRepo(EventRepository *er)
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

void V1_StateMachineController::executeAvailableCommandsAndSignalsInState()
{
	if(run_simulation)
	{
		// std::cout<<"INFO@Thread_Callback_Method: Checking Lock Available..."<<std::endl;
		std::unique_lock<std::mutex> mlock(m_mutex);
		if (!isIdle())
		{
			m_condVar.wait(mlock, std::bind(&V1_StateMachineController::isIdle, this));
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

void V1_StateMachineController::executeInternalTransitions()
{
	if(run_simulation) 
	{
		// std::cout<<"INFO@Thread_Callback_Method: Checking Lock Available..."<<std::endl;
		std::unique_lock<std::mutex> mlock(m_mutex);
		if(!isIdle())
		{
			m_condVar.wait(mlock, std::bind(&V1_StateMachineController::isIdle, this));
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

bool V1_StateMachineController::isIdle()
{
	return m_idle;
}

void V1_StateMachineController::displaySMVars()
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
void V1_StateMachineController::_V1_inTRp1_1_24()
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	current->V1_inTRp1_1_24(this);
	publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
}

void V1_StateMachineController::_V1_inTRp1_1_24(int instance_id, int clause_id)
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	current->V1_inTRp1_1_24(this, instance_id, clause_id);
	publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
}

bool V1_StateMachineController::isEnabledV1_inTRp1_1_24(int instance_id)
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();

	event_status_msg.clear();

	bool is_instance_enabled = current->isEnabledV1_inTRp1_1_24(this, instance_id);

	event_status_msg.clear();
	//publishToEventRepo(m_eventRepo);

	m_idle = true;
	m_condVar.notify_one();

	return is_instance_enabled;
	}
void V1_StateMachineController::_V1_inTRp1_1_27()
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	current->V1_inTRp1_1_27(this);
	publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
}

void V1_StateMachineController::_V1_inTRp1_1_27(int instance_id, int clause_id)
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	current->V1_inTRp1_1_27(this, instance_id, clause_id);
	publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
}

bool V1_StateMachineController::isEnabledV1_inTRp1_1_27(int instance_id)
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();

	event_status_msg.clear();

	bool is_instance_enabled = current->isEnabledV1_inTRp1_1_27(this, instance_id);

	event_status_msg.clear();
	//publishToEventRepo(m_eventRepo);

	m_idle = true;
	m_condVar.notify_one();

	return is_instance_enabled;
	}
void V1_StateMachineController::_V1_inTRp2_1_31()
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	current->V1_inTRp2_1_31(this);
	publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
}

void V1_StateMachineController::_V1_inTRp2_1_31(int instance_id, int clause_id)
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	current->V1_inTRp2_1_31(this, instance_id, clause_id);
	publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
}

bool V1_StateMachineController::isEnabledV1_inTRp2_1_31(int instance_id)
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();

	event_status_msg.clear();

	bool is_instance_enabled = current->isEnabledV1_inTRp2_1_31(this, instance_id);

	event_status_msg.clear();
	//publishToEventRepo(m_eventRepo);

	m_idle = true;
	m_condVar.notify_one();

	return is_instance_enabled;
	}
void V1_StateMachineController::_V1_inTRp3_1_32()
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	current->V1_inTRp3_1_32(this);
	publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
}

void V1_StateMachineController::_V1_inTRp3_1_32(int instance_id, int clause_id)
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	current->V1_inTRp3_1_32(this, instance_id, clause_id);
	publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
}

bool V1_StateMachineController::isEnabledV1_inTRp3_1_32(int instance_id)
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();

	event_status_msg.clear();

	bool is_instance_enabled = current->isEnabledV1_inTRp3_1_32(this, instance_id);

	event_status_msg.clear();
	//publishToEventRepo(m_eventRepo);

	m_idle = true;
	m_condVar.notify_one();

	return is_instance_enabled;
	}
void V1_StateMachineController::_V1_inTRp3_1_33()
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	current->V1_inTRp3_1_33(this);
	publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
}

void V1_StateMachineController::_V1_inTRp3_1_33(int instance_id, int clause_id)
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	current->V1_inTRp3_1_33(this, instance_id, clause_id);
	publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
}

bool V1_StateMachineController::isEnabledV1_inTRp3_1_33(int instance_id)
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();

	event_status_msg.clear();

	bool is_instance_enabled = current->isEnabledV1_inTRp3_1_33(this, instance_id);

	event_status_msg.clear();
	//publishToEventRepo(m_eventRepo);

	m_idle = true;
	m_condVar.notify_one();

	return is_instance_enabled;
	}
// Notifications: This should only be used by Server GUI
// Extension Feature for Client State Machine
void V1_StateMachineController::_V1_outTRp1_2_25()
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	current->V1_outTRp1_2_25(this);
	publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
}
void V1_StateMachineController::_V1_outTRp1_3_26()
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	current->V1_outTRp1_3_26(this);
	publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
}
void V1_StateMachineController::_V1_outTRp1_5_28()
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	current->V1_outTRp1_5_28(this);
	publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
}
void V1_StateMachineController::_V1_outTRp1_6_29()
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	current->V1_outTRp1_6_29(this);
	publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
}
void V1_StateMachineController::_V1_outTRp1_6_30()
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	current->V1_outTRp1_6_30(this);
	publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
}

void V1_StateMachineController::_V1_outTRp1_2_25(int instance_id, int clause_id)
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	current->V1_outTRp1_2_25(this, instance_id, clause_id);
	publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
}
void V1_StateMachineController::_V1_outTRp1_3_26(int instance_id, int clause_id)
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	current->V1_outTRp1_3_26(this, instance_id, clause_id);
	publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
}
void V1_StateMachineController::_V1_outTRp1_5_28(int instance_id, int clause_id)
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	current->V1_outTRp1_5_28(this, instance_id, clause_id);
	publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
}
void V1_StateMachineController::_V1_outTRp1_6_29(int instance_id, int clause_id)
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	current->V1_outTRp1_6_29(this, instance_id, clause_id);
	publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
}
void V1_StateMachineController::_V1_outTRp1_6_30(int instance_id, int clause_id)
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	current->V1_outTRp1_6_30(this, instance_id, clause_id);
	publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
}

std::vector<int> V1_StateMachineController::_match_V1_outTRp1_2_25(std::vector<std::string>  list_of_rcvd_notifications)
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	std::vector<int> matched_instance_clause_id = current->match_V1_outTRp1_2_25(this, list_of_rcvd_notifications);
	event_status_msg.clear();
	//publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
	return matched_instance_clause_id;
}
std::vector<int> V1_StateMachineController::_match_V1_outTRp1_3_26(std::vector<std::string>  list_of_rcvd_notifications)
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	std::vector<int> matched_instance_clause_id = current->match_V1_outTRp1_3_26(this, list_of_rcvd_notifications);
	event_status_msg.clear();
	//publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
	return matched_instance_clause_id;
}
std::vector<int> V1_StateMachineController::_match_V1_outTRp1_5_28(std::vector<std::string>  list_of_rcvd_notifications)
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	std::vector<int> matched_instance_clause_id = current->match_V1_outTRp1_5_28(this, list_of_rcvd_notifications);
	event_status_msg.clear();
	//publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
	return matched_instance_clause_id;
}
std::vector<int> V1_StateMachineController::_match_V1_outTRp1_6_29(std::vector<std::string>  list_of_rcvd_notifications)
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	std::vector<int> matched_instance_clause_id = current->match_V1_outTRp1_6_29(this, list_of_rcvd_notifications);
	event_status_msg.clear();
	//publishToEventRepo(m_eventRepo);
	
	m_idle = true;
	m_condVar.notify_one();
	return matched_instance_clause_id;
}
std::vector<int> V1_StateMachineController::_match_V1_outTRp1_6_30(std::vector<std::string>  list_of_rcvd_notifications)
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_idle = false;
	m_condVar.notify_one();
	
	event_status_msg.clear();
	std::vector<int> matched_instance_clause_id = current->match_V1_outTRp1_6_30(this, list_of_rcvd_notifications);
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
	retStr.push_back("V1_inTRp1_1_27");
	return retStr;
}
		
list<string> p1_1::getCurrentNotificationStatusList()
{
	list<string> retStr;
	return retStr;
}

string p1_1::getCurrentState() { return name; }

list<string> p1_1::isAtleastOneEnabledCommand(V1_StateMachineController *smc)
{
	list<string> list_of_enabled_commands;
	//StateMachineController::InputParametersContainer c;
	return list_of_enabled_commands;
}
list<string> p1_1::isAtleastOneEnabledSignal(V1_StateMachineController *smc)
{
	list<string> list_of_enabled_signals;
	//StateMachineController::InputParametersContainer c;
	// Signal Name: V1_inTRp1_1_27
	{
	list_of_enabled_signals.push_back("V1_inTRp1_1_27");
	}
	return list_of_enabled_signals;
}

void p1_1::executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc)
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

		if(!(*it).compare("V1_inTRp1_1_27"))
		{
			// #1. Call the interface function
			smc->client_api_handler->openEventContext();
			smc->client_api_handler->inTRp1_1_27();

			// #1a. Get the list of received notification and close the context.
			std::vector<string> list_of_rcvd_notifications = smc->client_api_handler->getListOfReceivedNotifications();
			//smc->client_api_handler->closeEventContext();
			std::cout << "[INFO] Number of Notifications Received in Context: " << list_of_rcvd_notifications.size() << std::endl;
			
			vector<int> instance_clause_id = V1_inTRp1_1_27( smc, list_of_rcvd_notifications);
			std::cout << std::endl << "Notifications List matched to Instance ID: " << instance_clause_id.at(0) << " and Clause ID: " << instance_clause_id.at(1) << std::endl;

			// #3. Call the the signal method
			V1_inTRp1_1_27( smc, instance_clause_id.at(0), instance_clause_id.at(1));
			smc->client_api_handler->closeEventContext();
		}
		#endif
		
		#ifndef CLIENT_STUB_API
		if(!(*it).compare("V1_inTRp1_1_27"))
		{
			
			std::cout << "Checking Instance-Clause Preferences for Signal: inTRp1_1_27" << std::endl;
			std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp1_1_27(smc->getCurrentState(), false);
			if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
			{
				// Call the function with Parameters Only
				std::cout << "No preferences found for Signal: inTRp1_1_27" << std::endl;
				
				// Call the function with Parameters
				V1_inTRp1_1_27( smc);
				smc->setTextColor("EVENT");
				std::cout<<std::endl<<" <<<<<<<< Command inTRp1_1_27 has been Executed!"<<std::endl;
				smc->setTextColor("ANY");
			}
			else
			{
				std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp1_1_27(smc->getCurrentState(), false);
				bool isAtleastOneInstanceEnabled = false;
				for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
				{
					if (isEnabledV1_inTRp1_1_27(smc, list_of_instance_id.at(i)))
					{
						instance_clause_id.at(0) = list_of_instance_id.at(i);
						std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp1_1_27(smc->getCurrentState(), list_of_instance_id.at(i), false);
						instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
						isAtleastOneInstanceEnabled = true;
					}
				}
				if(!isAtleastOneInstanceEnabled)
				{
					std::cout << "EXCEPTION: None of the instances of command: inTRp1_1_27 specified in the input file are enabled. Check the parameter set, if any!" << std::endl;
					//throw (StateMachineController::StubException("EXCEPTION: None of the instances of command: inTRp1_1_27 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));
				}
					
				// Call function with Parameters and Instance-Clause ID
				std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Command: inTRp1_1_27" << std::endl;
				
				// Call the function with Parameters
				V1_inTRp1_1_27( smc, instance_clause_id.at(0), instance_clause_id.at(1));
				smc->setTextColor("EVENT");
				std::cout<<std::endl<<" <<<<<<<< Command inTRp1_1_27 has been Executed!"<<std::endl;
				smc->setTextColor("ANY");
			}
		}
		#endif
	}
	else
	{
		std::cout<<std::endl<<"ERROR: No Enabled Commands or Signals in State: p1_1"<<std::endl;
		//throw (StubException("EXCEPTION: No Enabled Commands or Signals in State: p1_1", NO_ENABLED_GUARDS));
	}
}

bool p1_1::checkEnabledCommandAndSignalInState(V1_StateMachineController *smc)
{
	if(determineEnabledCommandAndSignalInState(smc).empty())
			return false;
		else
			return true;
}

list<string> p1_1::determineEnabledCommandAndSignalInState(V1_StateMachineController *smc)
{
	list<string> enabled_commands_and_signals_list = isAtleastOneEnabledCommand(smc);
	enabled_commands_and_signals_list.splice(enabled_commands_and_signals_list.end(), isAtleastOneEnabledSignal(smc));
	return enabled_commands_and_signals_list;
}


bool p1_1::isAtleastOneEnabledNotification(V1_StateMachineController *smc)
{
	UNREF_PARAM(smc);
	// Means there is no notification?
	return false;
}

// Enabling Test for Signal: V1_inTRp1_1_27
bool p1_1::isEnabledV1_inTRp1_1_27(V1_StateMachineController *smc, int instance_choice)
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
// Concrete Signal Context NI Validator: V1_inTRp1_1_27
std::vector<int> p1_1::V1_inTRp1_1_27(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications)
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
					const StateMachineController::V1_StateMachineController& smcRef = *smc;
					StateMachineController::smVarContainer var_copy(smcRef);
					switch(choice)
					{
					case 0: // Signal Clause
							{
							smc->setTextColor("EVENT");
							#ifdef QT_GUI
							smc->event_status_msg.push_back(" >>>>>>>> Received Signal: inTRp1_1_27");
							smc->event_status_msg.push_back(" <!> State Update: p1_1 => p1_2");
							#endif
							// std::cout<<std::endl<<" >>>>>>>> Received Signal: inTRp1_1_27"<<std::endl;
							// std::cout<<" <!> State Update: From p1_1 => p1_2"<<std::endl;
							// smc->event_status_msg.push_back("State Changed: p1_1 => p1_2");
							smc->setTextColor("ANY");
							bool is_equal = false;
							if (observed_notifications.size() == list_of_rcvd_notifications.size())
								is_equal = std::equal(observed_notifications.begin(), observed_notifications.end(), list_of_rcvd_notifications.begin());
							if (is_equal) { instance_clause_id.push_back(0); instance_clause_id.push_back(0); return instance_clause_id; }
							else { observed_notifications.clear(); }
							smc->setTextColor("EVENT");
							// std::cout<<std::endl<<" <<<<<<<< Signal inTRp1_1_27 has been Executed!"<<std::endl;
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
		smc->event_status_msg.push_back("ERROR: NO GUARDS FOR THIS SIGNAL ARE ENABLED in STATE: p1_1");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS FOR THIS SIGNAL ARE ENABLED in STATE: p1_1!", NO_ENABLED_GUARDS));
		
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
// Concrete Deterministic Signal Handler: V1_inTRp1_1_27
void p1_1::V1_inTRp1_1_27(V1_StateMachineController *smc, int instance_id, int clause_id)
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
							smc->event_status_msg.push_back(" >>>>>>>> Received Signal: inTRp1_1_27");
							smc->event_status_msg.push_back(" <!> State Update: p1_1 => p1_2");
							#endif
							std::cout<<std::endl<<" >>>>>>>> Received Signal: inTRp1_1_27"<<std::endl;
							std::cout<<" <!> State Update: From p1_1 => p1_2"<<std::endl;
							// smc->event_status_msg.push_back("State Changed: p1_1 => p1_2");
							smc->setTextColor("ANY");
							smc->setCurrent(new p1_2());
							delete this;
							smc->setTextColor("EVENT");
							std::cout<<std::endl<<" <<<<<<<< Signal inTRp1_1_27 has been Executed!"<<std::endl;
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
		smc->event_status_msg.push_back("ERROR: NO GUARDS FOR THIS SIGNAL ARE ENABLED in STATE: p1_1");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS FOR THIS SIGNAL ARE ENABLED in STATE: p1_1!", NO_ENABLED_GUARDS));
		
	}
}
// Concrete Signal Handler: V1_inTRp1_1_27
void p1_1::V1_inTRp1_1_27(V1_StateMachineController *smc)
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
				smc->event_status_msg.push_back(" >>>>>>>> Received Signal: inTRp1_1_27");
				smc->event_status_msg.push_back(" <!> State Update: p1_1 => p1_2");
				#endif
				std::cout<<std::endl<<" >>>>>>>> Received Signal: inTRp1_1_27"<<std::endl;
				std::cout<<" <!> State Update: From p1_1 => p1_2"<<std::endl;
				// smc->event_status_msg.push_back("State Changed: p1_1 => p1_2");
				smc->setTextColor("ANY");
				smc->setCurrent(new p1_2());
				delete this;
				smc->setTextColor("EVENT");
				std::cout<<std::endl<<" <<<<<<<< Signal inTRp1_1_27 has been Executed!"<<std::endl;
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
		smc->event_status_msg.push_back("ERROR: NO GUARDS FOR THIS SIGNAL ARE ENABLED in STATE: p1_1");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS FOR THIS SIGNAL ARE ENABLED in STATE: p1_1!", NO_ENABLED_GUARDS));
		
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
	retStr.push_back("V1_outTRp1_3_26");
	return retStr;
}

string p1_4::getCurrentState() { return name; }

list<string> p1_4::isAtleastOneEnabledCommand(V1_StateMachineController *smc)
{
	list<string> list_of_enabled_commands;
	//StateMachineController::InputParametersContainer c;
	return list_of_enabled_commands;
}
list<string> p1_4::isAtleastOneEnabledSignal(V1_StateMachineController *smc)
{
	list<string> list_of_enabled_signals;
	//StateMachineController::InputParametersContainer c;
	return list_of_enabled_signals;
}

void p1_4::executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc)
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

bool p1_4::checkEnabledCommandAndSignalInState(V1_StateMachineController *smc)
{
	if(determineEnabledCommandAndSignalInState(smc).empty())
			return false;
		else
			return true;
}

list<string> p1_4::determineEnabledCommandAndSignalInState(V1_StateMachineController *smc)
{
	list<string> enabled_commands_and_signals_list = isAtleastOneEnabledCommand(smc);
	enabled_commands_and_signals_list.splice(enabled_commands_and_signals_list.end(), isAtleastOneEnabledSignal(smc));
	return enabled_commands_and_signals_list;
}


bool p1_4::isAtleastOneEnabledNotification(V1_StateMachineController *smc)
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

// Concrete Deterministic Notification Handler: V1_outTRp1_3_26
void p1_4::V1_outTRp1_3_26(V1_StateMachineController *smc, int instance_id, int clause_id)
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
							// std::cout<<"Raising Notification: V1_outTRp1_3_26 -> Going From p1_4 to p1_5"<<std::endl;
							// smc->event_status_msg.push_back("State Changed: p1_4 => p1_5");
							#ifdef QT_GUI
								smc->event_status_msg.push_back(" <<<<<<<< Notification Raised: V1_outTRp1_3_26");
								smc->event_status_msg.push_back(" <!> State Update: p1_4 => p1_5");
							#endif
							smc->setTextColor("EVENT");
							std::cout<<std::endl<<" <<<<<<<< Notification Raised: V1_outTRp1_3_26"<<std::endl;
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
// Concrete Notification Validator: V1_outTRp1_3_26
std::vector<int> p1_4::match_V1_outTRp1_3_26(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
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
									const StateMachineController::V1_StateMachineController& smcRef = *smc;
									StateMachineController::smVarContainer var_copy(smcRef);
									observed_notifications.push_back("V1_outTRp1_3_26");
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
// Concrete Notification Handler: V1_outTRp1_3_26
void p1_4::V1_outTRp1_3_26(V1_StateMachineController *smc)
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
						// std::cout<<"Raising Notification: V1_outTRp1_3_26 -> Going From p1_4 to p1_5"<<std::endl;
						// smc->event_status_msg.push_back("State Changed: p1_4 => p1_5");
						#ifdef QT_GUI
							smc->event_status_msg.push_back(" <<<<<<<< Notification Raised: V1_outTRp1_3_26");
							smc->event_status_msg.push_back(" <!> State Update: p1_4 => p1_5");
						#endif
						smc->setTextColor("EVENT");
						std::cout<<std::endl<<" <<<<<<<< Notification Raised: V1_outTRp1_3_26"<<std::endl;
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

void p1_4::executeInternalTransitions(V1_StateMachineController *smc)
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
					smc->event_status_msg.push_back(" <<<<<<<< Notification Raised: V1_outTRp1_3_26");
					smc->event_status_msg.push_back(" <!> State Update: p1_4 => p1_5");
					#endif
					smc->setTextColor("EVENT");
					std::cout<<std::endl<<" <<<<<<<< Notification Raised: V1_outTRp1_3_26"<<std::endl;
					std::cout<<" <!> State Update: p1_4 => p1_5"<<std::endl;
					smc->setTextColor("DATA");
					smc->setTextColor("ANY");
					// Note: For SSCF push the notification out here...
					#ifdef SSCF_VERSION
					
					smc->m_serverPtr->raiseNotification_outTRp1_3_26();
					#endif
					#ifndef SSCF_VERSION
					if(smc->m_niHandler != nullptr) smc->m_niHandler("V1_outTRp1_3_26");
					if(smc->m_outTRp1_3_26_Handler != nullptr)
					{
						smc->m_outTRp1_3_26_Handler();
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



/*********** Concrete State Class: p1_3 ***********/

list<string> p1_3::getCurrentCommandStatusList() 
{
	list<string> retStr;
	return retStr;
}

list<string> p1_3::getCurrentSignalStatusList()
{
	list<string> retStr;
	return retStr;
}
		
list<string> p1_3::getCurrentNotificationStatusList()
{
	list<string> retStr;
	retStr.push_back("V1_outTRp1_2_25");
	return retStr;
}

string p1_3::getCurrentState() { return name; }

list<string> p1_3::isAtleastOneEnabledCommand(V1_StateMachineController *smc)
{
	list<string> list_of_enabled_commands;
	//StateMachineController::InputParametersContainer c;
	return list_of_enabled_commands;
}
list<string> p1_3::isAtleastOneEnabledSignal(V1_StateMachineController *smc)
{
	list<string> list_of_enabled_signals;
	//StateMachineController::InputParametersContainer c;
	return list_of_enabled_signals;
}

void p1_3::executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc)
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
		std::cout<<std::endl<<"ERROR: No Enabled Commands or Signals in State: p1_3"<<std::endl;
		//throw (StubException("EXCEPTION: No Enabled Commands or Signals in State: p1_3", NO_ENABLED_GUARDS));
	}
}

bool p1_3::checkEnabledCommandAndSignalInState(V1_StateMachineController *smc)
{
	if(determineEnabledCommandAndSignalInState(smc).empty())
			return false;
		else
			return true;
}

list<string> p1_3::determineEnabledCommandAndSignalInState(V1_StateMachineController *smc)
{
	list<string> enabled_commands_and_signals_list = isAtleastOneEnabledCommand(smc);
	enabled_commands_and_signals_list.splice(enabled_commands_and_signals_list.end(), isAtleastOneEnabledSignal(smc));
	return enabled_commands_and_signals_list;
}


bool p1_3::isAtleastOneEnabledNotification(V1_StateMachineController *smc)
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

// Concrete Deterministic Notification Handler: V1_outTRp1_2_25
void p1_3::V1_outTRp1_2_25(V1_StateMachineController *smc, int instance_id, int clause_id)
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
							// std::cout<<"Raising Notification: V1_outTRp1_2_25 -> Going From p1_3 to p1_4"<<std::endl;
							// smc->event_status_msg.push_back("State Changed: p1_3 => p1_4");
							#ifdef QT_GUI
								smc->event_status_msg.push_back(" <<<<<<<< Notification Raised: V1_outTRp1_2_25");
								smc->event_status_msg.push_back(" <!> State Update: p1_3 => p1_4");
							#endif
							smc->setTextColor("EVENT");
							std::cout<<std::endl<<" <<<<<<<< Notification Raised: V1_outTRp1_2_25"<<std::endl;
							std::cout<<" <!> State Update: p1_3 => p1_4"<<std::endl;
							smc->setTextColor("DATA");
							smc->setTextColor("ANY");
							smc->setCurrent(new p1_4());
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
		smc->event_status_msg.push_back("ERROR: NO GUARDS OF THIS NOTIFICATION ARE ENABLED in STATE: p1_3");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS OF THIS NOTIFICATION ARE ENABLED!", NO_ENABLED_GUARDS));
	}
}
// Concrete Notification Validator: V1_outTRp1_2_25
std::vector<int> p1_3::match_V1_outTRp1_2_25(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
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
									const StateMachineController::V1_StateMachineController& smcRef = *smc;
									StateMachineController::smVarContainer var_copy(smcRef);
									observed_notifications.push_back("V1_outTRp1_2_25");
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
		smc->event_status_msg.push_back("ERROR: NO GUARDS OF THIS NOTIFICATION ARE ENABLED in STATE: p1_3");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS OF THIS NOTIFICATION ARE ENABLED!", NO_ENABLED_GUARDS));
	}
	
	matched_instance_clause_id.push_back(UNDEFINED_CHOICE); 
	matched_instance_clause_id.push_back(UNDEFINED_CHOICE); 
	return matched_instance_clause_id;
}
// Concrete Notification Handler: V1_outTRp1_2_25
void p1_3::V1_outTRp1_2_25(V1_StateMachineController *smc)
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
						// std::cout<<"Raising Notification: V1_outTRp1_2_25 -> Going From p1_3 to p1_4"<<std::endl;
						// smc->event_status_msg.push_back("State Changed: p1_3 => p1_4");
						#ifdef QT_GUI
							smc->event_status_msg.push_back(" <<<<<<<< Notification Raised: V1_outTRp1_2_25");
							smc->event_status_msg.push_back(" <!> State Update: p1_3 => p1_4");
						#endif
						smc->setTextColor("EVENT");
						std::cout<<std::endl<<" <<<<<<<< Notification Raised: V1_outTRp1_2_25"<<std::endl;
						std::cout<<" <!> State Update: p1_3 => p1_4"<<std::endl;
						smc->setTextColor("DATA");
						smc->setTextColor("ANY");
						smc->setCurrent(new p1_4());
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
		smc->event_status_msg.push_back("ERROR: NO GUARDS OF THIS NOTIFICATION ARE ENABLED in STATE: p1_3");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS OF THIS NOTIFICATION ARE ENABLED!", NO_ENABLED_GUARDS));
	}
}

void p1_3::executeInternalTransitions(V1_StateMachineController *smc)
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
					smc->event_status_msg.push_back(" <<<<<<<< Notification Raised: V1_outTRp1_2_25");
					smc->event_status_msg.push_back(" <!> State Update: p1_3 => p1_4");
					#endif
					smc->setTextColor("EVENT");
					std::cout<<std::endl<<" <<<<<<<< Notification Raised: V1_outTRp1_2_25"<<std::endl;
					std::cout<<" <!> State Update: p1_3 => p1_4"<<std::endl;
					smc->setTextColor("DATA");
					smc->setTextColor("ANY");
					// Note: For SSCF push the notification out here...
					#ifdef SSCF_VERSION
					
					smc->m_serverPtr->raiseNotification_outTRp1_2_25();
					#endif
					#ifndef SSCF_VERSION
					if(smc->m_niHandler != nullptr) smc->m_niHandler("V1_outTRp1_2_25");
					if(smc->m_outTRp1_2_25_Handler != nullptr)
					{
						smc->m_outTRp1_2_25_Handler();
					}
					#endif
					// smc->event_status_msg.push_back("State Changed: p1_3 => p1_4");
					smc->setCurrent(new p1_4());
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
		smc->event_status_msg.push_back("ERROR: NONE OF THE NOTIFICATION GUARDS ARE ENABLED in STATE: p1_3");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NONE OF THE NOTIFICATION GUARDS ARE ENABLED in STATE: p1_3!", NO_ENABLED_GUARDS));
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
	return retStr;
}
		
list<string> p1_5::getCurrentNotificationStatusList()
{
	list<string> retStr;
	retStr.push_back("V1_outTRp1_5_28");
	return retStr;
}

string p1_5::getCurrentState() { return name; }

list<string> p1_5::isAtleastOneEnabledCommand(V1_StateMachineController *smc)
{
	list<string> list_of_enabled_commands;
	//StateMachineController::InputParametersContainer c;
	return list_of_enabled_commands;
}
list<string> p1_5::isAtleastOneEnabledSignal(V1_StateMachineController *smc)
{
	list<string> list_of_enabled_signals;
	//StateMachineController::InputParametersContainer c;
	return list_of_enabled_signals;
}

void p1_5::executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc)
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
		std::cout<<std::endl<<"ERROR: No Enabled Commands or Signals in State: p1_5"<<std::endl;
		//throw (StubException("EXCEPTION: No Enabled Commands or Signals in State: p1_5", NO_ENABLED_GUARDS));
	}
}

bool p1_5::checkEnabledCommandAndSignalInState(V1_StateMachineController *smc)
{
	if(determineEnabledCommandAndSignalInState(smc).empty())
			return false;
		else
			return true;
}

list<string> p1_5::determineEnabledCommandAndSignalInState(V1_StateMachineController *smc)
{
	list<string> enabled_commands_and_signals_list = isAtleastOneEnabledCommand(smc);
	enabled_commands_and_signals_list.splice(enabled_commands_and_signals_list.end(), isAtleastOneEnabledSignal(smc));
	return enabled_commands_and_signals_list;
}


bool p1_5::isAtleastOneEnabledNotification(V1_StateMachineController *smc)
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

// Concrete Deterministic Notification Handler: V1_outTRp1_5_28
void p1_5::V1_outTRp1_5_28(V1_StateMachineController *smc, int instance_id, int clause_id)
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
							// std::cout<<"Raising Notification: V1_outTRp1_5_28 -> Going From p1_5 to p1_6"<<std::endl;
							// smc->event_status_msg.push_back("State Changed: p1_5 => p1_6");
							#ifdef QT_GUI
								smc->event_status_msg.push_back(" <<<<<<<< Notification Raised: V1_outTRp1_5_28");
								smc->event_status_msg.push_back(" <!> State Update: p1_5 => p1_6");
							#endif
							smc->setTextColor("EVENT");
							std::cout<<std::endl<<" <<<<<<<< Notification Raised: V1_outTRp1_5_28"<<std::endl;
							std::cout<<" <!> State Update: p1_5 => p1_6"<<std::endl;
							smc->setTextColor("DATA");
							smc->setTextColor("ANY");
							smc->setCurrent(new p1_6());
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
		smc->event_status_msg.push_back("ERROR: NO GUARDS OF THIS NOTIFICATION ARE ENABLED in STATE: p1_5");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS OF THIS NOTIFICATION ARE ENABLED!", NO_ENABLED_GUARDS));
	}
}
// Concrete Notification Validator: V1_outTRp1_5_28
std::vector<int> p1_5::match_V1_outTRp1_5_28(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
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
									const StateMachineController::V1_StateMachineController& smcRef = *smc;
									StateMachineController::smVarContainer var_copy(smcRef);
									observed_notifications.push_back("V1_outTRp1_5_28");
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
		smc->event_status_msg.push_back("ERROR: NO GUARDS OF THIS NOTIFICATION ARE ENABLED in STATE: p1_5");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS OF THIS NOTIFICATION ARE ENABLED!", NO_ENABLED_GUARDS));
	}
	
	matched_instance_clause_id.push_back(UNDEFINED_CHOICE); 
	matched_instance_clause_id.push_back(UNDEFINED_CHOICE); 
	return matched_instance_clause_id;
}
// Concrete Notification Handler: V1_outTRp1_5_28
void p1_5::V1_outTRp1_5_28(V1_StateMachineController *smc)
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
						// std::cout<<"Raising Notification: V1_outTRp1_5_28 -> Going From p1_5 to p1_6"<<std::endl;
						// smc->event_status_msg.push_back("State Changed: p1_5 => p1_6");
						#ifdef QT_GUI
							smc->event_status_msg.push_back(" <<<<<<<< Notification Raised: V1_outTRp1_5_28");
							smc->event_status_msg.push_back(" <!> State Update: p1_5 => p1_6");
						#endif
						smc->setTextColor("EVENT");
						std::cout<<std::endl<<" <<<<<<<< Notification Raised: V1_outTRp1_5_28"<<std::endl;
						std::cout<<" <!> State Update: p1_5 => p1_6"<<std::endl;
						smc->setTextColor("DATA");
						smc->setTextColor("ANY");
						smc->setCurrent(new p1_6());
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
		smc->event_status_msg.push_back("ERROR: NO GUARDS OF THIS NOTIFICATION ARE ENABLED in STATE: p1_5");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS OF THIS NOTIFICATION ARE ENABLED!", NO_ENABLED_GUARDS));
	}
}

void p1_5::executeInternalTransitions(V1_StateMachineController *smc)
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
					smc->event_status_msg.push_back(" <<<<<<<< Notification Raised: V1_outTRp1_5_28");
					smc->event_status_msg.push_back(" <!> State Update: p1_5 => p1_6");
					#endif
					smc->setTextColor("EVENT");
					std::cout<<std::endl<<" <<<<<<<< Notification Raised: V1_outTRp1_5_28"<<std::endl;
					std::cout<<" <!> State Update: p1_5 => p1_6"<<std::endl;
					smc->setTextColor("DATA");
					smc->setTextColor("ANY");
					// Note: For SSCF push the notification out here...
					#ifdef SSCF_VERSION
					
					smc->m_serverPtr->raiseNotification_outTRp1_5_28();
					#endif
					#ifndef SSCF_VERSION
					if(smc->m_niHandler != nullptr) smc->m_niHandler("V1_outTRp1_5_28");
					if(smc->m_outTRp1_5_28_Handler != nullptr)
					{
						smc->m_outTRp1_5_28_Handler();
					}
					#endif
					// smc->event_status_msg.push_back("State Changed: p1_5 => p1_6");
					smc->setCurrent(new p1_6());
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
		smc->event_status_msg.push_back("ERROR: NONE OF THE NOTIFICATION GUARDS ARE ENABLED in STATE: p1_5");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NONE OF THE NOTIFICATION GUARDS ARE ENABLED in STATE: p1_5!", NO_ENABLED_GUARDS));
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
	retStr.push_back("V1_inTRp1_1_24");
	return retStr;
}
		
list<string> p1_2::getCurrentNotificationStatusList()
{
	list<string> retStr;
	return retStr;
}

string p1_2::getCurrentState() { return name; }

list<string> p1_2::isAtleastOneEnabledCommand(V1_StateMachineController *smc)
{
	list<string> list_of_enabled_commands;
	//StateMachineController::InputParametersContainer c;
	return list_of_enabled_commands;
}
list<string> p1_2::isAtleastOneEnabledSignal(V1_StateMachineController *smc)
{
	list<string> list_of_enabled_signals;
	//StateMachineController::InputParametersContainer c;
	// Signal Name: V1_inTRp1_1_24
	{
	list_of_enabled_signals.push_back("V1_inTRp1_1_24");
	}
	return list_of_enabled_signals;
}

void p1_2::executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc)
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

		if(!(*it).compare("V1_inTRp1_1_24"))
		{
			// #1. Call the interface function
			smc->client_api_handler->openEventContext();
			smc->client_api_handler->inTRp1_1_24();

			// #1a. Get the list of received notification and close the context.
			std::vector<string> list_of_rcvd_notifications = smc->client_api_handler->getListOfReceivedNotifications();
			//smc->client_api_handler->closeEventContext();
			std::cout << "[INFO] Number of Notifications Received in Context: " << list_of_rcvd_notifications.size() << std::endl;
			
			vector<int> instance_clause_id = V1_inTRp1_1_24( smc, list_of_rcvd_notifications);
			std::cout << std::endl << "Notifications List matched to Instance ID: " << instance_clause_id.at(0) << " and Clause ID: " << instance_clause_id.at(1) << std::endl;

			// #3. Call the the signal method
			V1_inTRp1_1_24( smc, instance_clause_id.at(0), instance_clause_id.at(1));
			smc->client_api_handler->closeEventContext();
		}
		#endif
		
		#ifndef CLIENT_STUB_API
		if(!(*it).compare("V1_inTRp1_1_24"))
		{
			
			std::cout << "Checking Instance-Clause Preferences for Signal: inTRp1_1_24" << std::endl;
			std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp1_1_24(smc->getCurrentState(), false);
			if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
			{
				// Call the function with Parameters Only
				std::cout << "No preferences found for Signal: inTRp1_1_24" << std::endl;
				
				// Call the function with Parameters
				V1_inTRp1_1_24( smc);
				smc->setTextColor("EVENT");
				std::cout<<std::endl<<" <<<<<<<< Command inTRp1_1_24 has been Executed!"<<std::endl;
				smc->setTextColor("ANY");
			}
			else
			{
				std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp1_1_24(smc->getCurrentState(), false);
				bool isAtleastOneInstanceEnabled = false;
				for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
				{
					if (isEnabledV1_inTRp1_1_24(smc, list_of_instance_id.at(i)))
					{
						instance_clause_id.at(0) = list_of_instance_id.at(i);
						std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp1_1_24(smc->getCurrentState(), list_of_instance_id.at(i), false);
						instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
						isAtleastOneInstanceEnabled = true;
					}
				}
				if(!isAtleastOneInstanceEnabled)
				{
					std::cout << "EXCEPTION: None of the instances of command: inTRp1_1_24 specified in the input file are enabled. Check the parameter set, if any!" << std::endl;
					//throw (StateMachineController::StubException("EXCEPTION: None of the instances of command: inTRp1_1_24 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));
				}
					
				// Call function with Parameters and Instance-Clause ID
				std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Command: inTRp1_1_24" << std::endl;
				
				// Call the function with Parameters
				V1_inTRp1_1_24( smc, instance_clause_id.at(0), instance_clause_id.at(1));
				smc->setTextColor("EVENT");
				std::cout<<std::endl<<" <<<<<<<< Command inTRp1_1_24 has been Executed!"<<std::endl;
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

bool p1_2::checkEnabledCommandAndSignalInState(V1_StateMachineController *smc)
{
	if(determineEnabledCommandAndSignalInState(smc).empty())
			return false;
		else
			return true;
}

list<string> p1_2::determineEnabledCommandAndSignalInState(V1_StateMachineController *smc)
{
	list<string> enabled_commands_and_signals_list = isAtleastOneEnabledCommand(smc);
	enabled_commands_and_signals_list.splice(enabled_commands_and_signals_list.end(), isAtleastOneEnabledSignal(smc));
	return enabled_commands_and_signals_list;
}


bool p1_2::isAtleastOneEnabledNotification(V1_StateMachineController *smc)
{
	UNREF_PARAM(smc);
	// Means there is no notification?
	return false;
}

// Enabling Test for Signal: V1_inTRp1_1_24
bool p1_2::isEnabledV1_inTRp1_1_24(V1_StateMachineController *smc, int instance_choice)
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
// Concrete Signal Context NI Validator: V1_inTRp1_1_24
std::vector<int> p1_2::V1_inTRp1_1_24(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications)
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
					const StateMachineController::V1_StateMachineController& smcRef = *smc;
					StateMachineController::smVarContainer var_copy(smcRef);
					switch(choice)
					{
					case 0: // Signal Clause
							{
							smc->setTextColor("EVENT");
							#ifdef QT_GUI
							smc->event_status_msg.push_back(" >>>>>>>> Received Signal: inTRp1_1_24");
							smc->event_status_msg.push_back(" <!> State Update: p1_2 => p1_3");
							#endif
							// std::cout<<std::endl<<" >>>>>>>> Received Signal: inTRp1_1_24"<<std::endl;
							// std::cout<<" <!> State Update: From p1_2 => p1_3"<<std::endl;
							// smc->event_status_msg.push_back("State Changed: p1_2 => p1_3");
							smc->setTextColor("ANY");
							bool is_equal = false;
							if (observed_notifications.size() == list_of_rcvd_notifications.size())
								is_equal = std::equal(observed_notifications.begin(), observed_notifications.end(), list_of_rcvd_notifications.begin());
							if (is_equal) { instance_clause_id.push_back(0); instance_clause_id.push_back(0); return instance_clause_id; }
							else { observed_notifications.clear(); }
							smc->setTextColor("EVENT");
							// std::cout<<std::endl<<" <<<<<<<< Signal inTRp1_1_24 has been Executed!"<<std::endl;
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
// Concrete Deterministic Signal Handler: V1_inTRp1_1_24
void p1_2::V1_inTRp1_1_24(V1_StateMachineController *smc, int instance_id, int clause_id)
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
							smc->event_status_msg.push_back(" >>>>>>>> Received Signal: inTRp1_1_24");
							smc->event_status_msg.push_back(" <!> State Update: p1_2 => p1_3");
							#endif
							std::cout<<std::endl<<" >>>>>>>> Received Signal: inTRp1_1_24"<<std::endl;
							std::cout<<" <!> State Update: From p1_2 => p1_3"<<std::endl;
							// smc->event_status_msg.push_back("State Changed: p1_2 => p1_3");
							smc->setTextColor("ANY");
							smc->setCurrent(new p1_3());
							delete this;
							smc->setTextColor("EVENT");
							std::cout<<std::endl<<" <<<<<<<< Signal inTRp1_1_24 has been Executed!"<<std::endl;
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
// Concrete Signal Handler: V1_inTRp1_1_24
void p1_2::V1_inTRp1_1_24(V1_StateMachineController *smc)
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
				smc->event_status_msg.push_back(" >>>>>>>> Received Signal: inTRp1_1_24");
				smc->event_status_msg.push_back(" <!> State Update: p1_2 => p1_3");
				#endif
				std::cout<<std::endl<<" >>>>>>>> Received Signal: inTRp1_1_24"<<std::endl;
				std::cout<<" <!> State Update: From p1_2 => p1_3"<<std::endl;
				// smc->event_status_msg.push_back("State Changed: p1_2 => p1_3");
				smc->setTextColor("ANY");
				smc->setCurrent(new p1_3());
				delete this;
				smc->setTextColor("EVENT");
				std::cout<<std::endl<<" <<<<<<<< Signal inTRp1_1_24 has been Executed!"<<std::endl;
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
	retStr.push_back("V1_outTRp1_6_30");
	retStr.push_back("V1_outTRp1_6_29");
	return retStr;
}

string p1_6::getCurrentState() { return name; }

list<string> p1_6::isAtleastOneEnabledCommand(V1_StateMachineController *smc)
{
	list<string> list_of_enabled_commands;
	//StateMachineController::InputParametersContainer c;
	return list_of_enabled_commands;
}
list<string> p1_6::isAtleastOneEnabledSignal(V1_StateMachineController *smc)
{
	list<string> list_of_enabled_signals;
	//StateMachineController::InputParametersContainer c;
	return list_of_enabled_signals;
}

void p1_6::executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc)
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

bool p1_6::checkEnabledCommandAndSignalInState(V1_StateMachineController *smc)
{
	if(determineEnabledCommandAndSignalInState(smc).empty())
			return false;
		else
			return true;
}

list<string> p1_6::determineEnabledCommandAndSignalInState(V1_StateMachineController *smc)
{
	list<string> enabled_commands_and_signals_list = isAtleastOneEnabledCommand(smc);
	enabled_commands_and_signals_list.splice(enabled_commands_and_signals_list.end(), isAtleastOneEnabledSignal(smc));
	return enabled_commands_and_signals_list;
}


bool p1_6::isAtleastOneEnabledNotification(V1_StateMachineController *smc)
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

// Concrete Deterministic Notification Handler: V1_outTRp1_6_30
void p1_6::V1_outTRp1_6_30(V1_StateMachineController *smc, int instance_id, int clause_id)
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
							// std::cout<<"Raising Notification: V1_outTRp1_6_30 -> Going From p1_6 to p3_1"<<std::endl;
							// smc->event_status_msg.push_back("State Changed: p1_6 => p3_1");
							#ifdef QT_GUI
								smc->event_status_msg.push_back(" <<<<<<<< Notification Raised: V1_outTRp1_6_30");
								smc->event_status_msg.push_back(" <!> State Update: p1_6 => p3_1");
							#endif
							smc->setTextColor("EVENT");
							std::cout<<std::endl<<" <<<<<<<< Notification Raised: V1_outTRp1_6_30"<<std::endl;
							std::cout<<" <!> State Update: p1_6 => p3_1"<<std::endl;
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
		smc->event_status_msg.push_back("ERROR: NO GUARDS OF THIS NOTIFICATION ARE ENABLED in STATE: p1_6");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS OF THIS NOTIFICATION ARE ENABLED!", NO_ENABLED_GUARDS));
	}
}
// Concrete Deterministic Notification Handler: V1_outTRp1_6_29
void p1_6::V1_outTRp1_6_29(V1_StateMachineController *smc, int instance_id, int clause_id)
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
							// std::cout<<"Raising Notification: V1_outTRp1_6_29 -> Going From p1_6 to p2_1"<<std::endl;
							// smc->event_status_msg.push_back("State Changed: p1_6 => p2_1");
							#ifdef QT_GUI
								smc->event_status_msg.push_back(" <<<<<<<< Notification Raised: V1_outTRp1_6_29");
								smc->event_status_msg.push_back(" <!> State Update: p1_6 => p2_1");
							#endif
							smc->setTextColor("EVENT");
							std::cout<<std::endl<<" <<<<<<<< Notification Raised: V1_outTRp1_6_29"<<std::endl;
							std::cout<<" <!> State Update: p1_6 => p2_1"<<std::endl;
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
		smc->event_status_msg.push_back("ERROR: NO GUARDS OF THIS NOTIFICATION ARE ENABLED in STATE: p1_6");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS OF THIS NOTIFICATION ARE ENABLED!", NO_ENABLED_GUARDS));
	}
}
// Concrete Notification Validator: V1_outTRp1_6_30
std::vector<int> p1_6::match_V1_outTRp1_6_30(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
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
									const StateMachineController::V1_StateMachineController& smcRef = *smc;
									StateMachineController::smVarContainer var_copy(smcRef);
									observed_notifications.push_back("V1_outTRp1_6_30");
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
// Concrete Notification Validator: V1_outTRp1_6_29
std::vector<int> p1_6::match_V1_outTRp1_6_29(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
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
									const StateMachineController::V1_StateMachineController& smcRef = *smc;
									StateMachineController::smVarContainer var_copy(smcRef);
									observed_notifications.push_back("V1_outTRp1_6_29");
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
// Concrete Notification Handler: V1_outTRp1_6_30
void p1_6::V1_outTRp1_6_30(V1_StateMachineController *smc)
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
						// std::cout<<"Raising Notification: V1_outTRp1_6_30 -> Going From p1_6 to p3_1"<<std::endl;
						// smc->event_status_msg.push_back("State Changed: p1_6 => p3_1");
						#ifdef QT_GUI
							smc->event_status_msg.push_back(" <<<<<<<< Notification Raised: V1_outTRp1_6_30");
							smc->event_status_msg.push_back(" <!> State Update: p1_6 => p3_1");
						#endif
						smc->setTextColor("EVENT");
						std::cout<<std::endl<<" <<<<<<<< Notification Raised: V1_outTRp1_6_30"<<std::endl;
						std::cout<<" <!> State Update: p1_6 => p3_1"<<std::endl;
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
		smc->event_status_msg.push_back("ERROR: NO GUARDS OF THIS NOTIFICATION ARE ENABLED in STATE: p1_6");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS OF THIS NOTIFICATION ARE ENABLED!", NO_ENABLED_GUARDS));
	}
}
// Concrete Notification Handler: V1_outTRp1_6_29
void p1_6::V1_outTRp1_6_29(V1_StateMachineController *smc)
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
						// std::cout<<"Raising Notification: V1_outTRp1_6_29 -> Going From p1_6 to p2_1"<<std::endl;
						// smc->event_status_msg.push_back("State Changed: p1_6 => p2_1");
						#ifdef QT_GUI
							smc->event_status_msg.push_back(" <<<<<<<< Notification Raised: V1_outTRp1_6_29");
							smc->event_status_msg.push_back(" <!> State Update: p1_6 => p2_1");
						#endif
						smc->setTextColor("EVENT");
						std::cout<<std::endl<<" <<<<<<<< Notification Raised: V1_outTRp1_6_29"<<std::endl;
						std::cout<<" <!> State Update: p1_6 => p2_1"<<std::endl;
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
		smc->event_status_msg.push_back("ERROR: NO GUARDS OF THIS NOTIFICATION ARE ENABLED in STATE: p1_6");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS OF THIS NOTIFICATION ARE ENABLED!", NO_ENABLED_GUARDS));
	}
}

void p1_6::executeInternalTransitions(V1_StateMachineController *smc)
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
					smc->event_status_msg.push_back(" <<<<<<<< Notification Raised: V1_outTRp1_6_29");
					smc->event_status_msg.push_back(" <!> State Update: p1_6 => p2_1");
					#endif
					smc->setTextColor("EVENT");
					std::cout<<std::endl<<" <<<<<<<< Notification Raised: V1_outTRp1_6_29"<<std::endl;
					std::cout<<" <!> State Update: p1_6 => p2_1"<<std::endl;
					smc->setTextColor("DATA");
					smc->setTextColor("ANY");
					// Note: For SSCF push the notification out here...
					#ifdef SSCF_VERSION
					
					smc->m_serverPtr->raiseNotification_outTRp1_6_29();
					#endif
					#ifndef SSCF_VERSION
					if(smc->m_niHandler != nullptr) smc->m_niHandler("V1_outTRp1_6_29");
					if(smc->m_outTRp1_6_29_Handler != nullptr)
					{
						smc->m_outTRp1_6_29_Handler();
					}
					#endif
					// smc->event_status_msg.push_back("State Changed: p1_6 => p2_1");
					smc->setCurrent(new p2_1());
					delete this;
					break;
		case 1:
					found_enabled_notification = true;
					// found_enabled_notification = true;
					#ifdef QT_GUI
					smc->event_status_msg.push_back(" <<<<<<<< Notification Raised: V1_outTRp1_6_30");
					smc->event_status_msg.push_back(" <!> State Update: p1_6 => p3_1");
					#endif
					smc->setTextColor("EVENT");
					std::cout<<std::endl<<" <<<<<<<< Notification Raised: V1_outTRp1_6_30"<<std::endl;
					std::cout<<" <!> State Update: p1_6 => p3_1"<<std::endl;
					smc->setTextColor("DATA");
					smc->setTextColor("ANY");
					// Note: For SSCF push the notification out here...
					#ifdef SSCF_VERSION
					
					smc->m_serverPtr->raiseNotification_outTRp1_6_30();
					#endif
					#ifndef SSCF_VERSION
					if(smc->m_niHandler != nullptr) smc->m_niHandler("V1_outTRp1_6_30");
					if(smc->m_outTRp1_6_30_Handler != nullptr)
					{
						smc->m_outTRp1_6_30_Handler();
					}
					#endif
					// smc->event_status_msg.push_back("State Changed: p1_6 => p3_1");
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
		smc->event_status_msg.push_back("ERROR: NONE OF THE NOTIFICATION GUARDS ARE ENABLED in STATE: p1_6");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NONE OF THE NOTIFICATION GUARDS ARE ENABLED in STATE: p1_6!", NO_ENABLED_GUARDS));
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
	retStr.push_back("V1_inTRp2_1_31");
	return retStr;
}
		
list<string> p2_1::getCurrentNotificationStatusList()
{
	list<string> retStr;
	return retStr;
}

string p2_1::getCurrentState() { return name; }

list<string> p2_1::isAtleastOneEnabledCommand(V1_StateMachineController *smc)
{
	list<string> list_of_enabled_commands;
	//StateMachineController::InputParametersContainer c;
	return list_of_enabled_commands;
}
list<string> p2_1::isAtleastOneEnabledSignal(V1_StateMachineController *smc)
{
	list<string> list_of_enabled_signals;
	//StateMachineController::InputParametersContainer c;
	// Signal Name: V1_inTRp2_1_31
	{
	list_of_enabled_signals.push_back("V1_inTRp2_1_31");
	}
	return list_of_enabled_signals;
}

void p2_1::executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc)
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

		if(!(*it).compare("V1_inTRp2_1_31"))
		{
			// #1. Call the interface function
			smc->client_api_handler->openEventContext();
			smc->client_api_handler->inTRp2_1_31();

			// #1a. Get the list of received notification and close the context.
			std::vector<string> list_of_rcvd_notifications = smc->client_api_handler->getListOfReceivedNotifications();
			//smc->client_api_handler->closeEventContext();
			std::cout << "[INFO] Number of Notifications Received in Context: " << list_of_rcvd_notifications.size() << std::endl;
			
			vector<int> instance_clause_id = V1_inTRp2_1_31( smc, list_of_rcvd_notifications);
			std::cout << std::endl << "Notifications List matched to Instance ID: " << instance_clause_id.at(0) << " and Clause ID: " << instance_clause_id.at(1) << std::endl;

			// #3. Call the the signal method
			V1_inTRp2_1_31( smc, instance_clause_id.at(0), instance_clause_id.at(1));
			smc->client_api_handler->closeEventContext();
		}
		#endif
		
		#ifndef CLIENT_STUB_API
		if(!(*it).compare("V1_inTRp2_1_31"))
		{
			
			std::cout << "Checking Instance-Clause Preferences for Signal: inTRp2_1_31" << std::endl;
			std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp2_1_31(smc->getCurrentState(), false);
			if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
			{
				// Call the function with Parameters Only
				std::cout << "No preferences found for Signal: inTRp2_1_31" << std::endl;
				
				// Call the function with Parameters
				V1_inTRp2_1_31( smc);
				smc->setTextColor("EVENT");
				std::cout<<std::endl<<" <<<<<<<< Command inTRp2_1_31 has been Executed!"<<std::endl;
				smc->setTextColor("ANY");
			}
			else
			{
				std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp2_1_31(smc->getCurrentState(), false);
				bool isAtleastOneInstanceEnabled = false;
				for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
				{
					if (isEnabledV1_inTRp2_1_31(smc, list_of_instance_id.at(i)))
					{
						instance_clause_id.at(0) = list_of_instance_id.at(i);
						std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp2_1_31(smc->getCurrentState(), list_of_instance_id.at(i), false);
						instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
						isAtleastOneInstanceEnabled = true;
					}
				}
				if(!isAtleastOneInstanceEnabled)
				{
					std::cout << "EXCEPTION: None of the instances of command: inTRp2_1_31 specified in the input file are enabled. Check the parameter set, if any!" << std::endl;
					//throw (StateMachineController::StubException("EXCEPTION: None of the instances of command: inTRp2_1_31 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));
				}
					
				// Call function with Parameters and Instance-Clause ID
				std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Command: inTRp2_1_31" << std::endl;
				
				// Call the function with Parameters
				V1_inTRp2_1_31( smc, instance_clause_id.at(0), instance_clause_id.at(1));
				smc->setTextColor("EVENT");
				std::cout<<std::endl<<" <<<<<<<< Command inTRp2_1_31 has been Executed!"<<std::endl;
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

bool p2_1::checkEnabledCommandAndSignalInState(V1_StateMachineController *smc)
{
	if(determineEnabledCommandAndSignalInState(smc).empty())
			return false;
		else
			return true;
}

list<string> p2_1::determineEnabledCommandAndSignalInState(V1_StateMachineController *smc)
{
	list<string> enabled_commands_and_signals_list = isAtleastOneEnabledCommand(smc);
	enabled_commands_and_signals_list.splice(enabled_commands_and_signals_list.end(), isAtleastOneEnabledSignal(smc));
	return enabled_commands_and_signals_list;
}


bool p2_1::isAtleastOneEnabledNotification(V1_StateMachineController *smc)
{
	UNREF_PARAM(smc);
	// Means there is no notification?
	return false;
}

// Enabling Test for Signal: V1_inTRp2_1_31
bool p2_1::isEnabledV1_inTRp2_1_31(V1_StateMachineController *smc, int instance_choice)
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
// Concrete Signal Context NI Validator: V1_inTRp2_1_31
std::vector<int> p2_1::V1_inTRp2_1_31(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications)
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
					const StateMachineController::V1_StateMachineController& smcRef = *smc;
					StateMachineController::smVarContainer var_copy(smcRef);
					switch(choice)
					{
					case 0: // Signal Clause
							{
							smc->setTextColor("EVENT");
							#ifdef QT_GUI
							smc->event_status_msg.push_back(" >>>>>>>> Received Signal: inTRp2_1_31");
							smc->event_status_msg.push_back(" <!> State Update: p2_1 => p1_1");
							#endif
							// std::cout<<std::endl<<" >>>>>>>> Received Signal: inTRp2_1_31"<<std::endl;
							// std::cout<<" <!> State Update: From p2_1 => p1_1"<<std::endl;
							// smc->event_status_msg.push_back("State Changed: p2_1 => p1_1");
							smc->setTextColor("ANY");
							bool is_equal = false;
							if (observed_notifications.size() == list_of_rcvd_notifications.size())
								is_equal = std::equal(observed_notifications.begin(), observed_notifications.end(), list_of_rcvd_notifications.begin());
							if (is_equal) { instance_clause_id.push_back(0); instance_clause_id.push_back(0); return instance_clause_id; }
							else { observed_notifications.clear(); }
							smc->setTextColor("EVENT");
							// std::cout<<std::endl<<" <<<<<<<< Signal inTRp2_1_31 has been Executed!"<<std::endl;
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
// Concrete Deterministic Signal Handler: V1_inTRp2_1_31
void p2_1::V1_inTRp2_1_31(V1_StateMachineController *smc, int instance_id, int clause_id)
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
							smc->event_status_msg.push_back(" >>>>>>>> Received Signal: inTRp2_1_31");
							smc->event_status_msg.push_back(" <!> State Update: p2_1 => p1_1");
							#endif
							std::cout<<std::endl<<" >>>>>>>> Received Signal: inTRp2_1_31"<<std::endl;
							std::cout<<" <!> State Update: From p2_1 => p1_1"<<std::endl;
							// smc->event_status_msg.push_back("State Changed: p2_1 => p1_1");
							smc->setTextColor("ANY");
							smc->setCurrent(new p1_1());
							delete this;
							smc->setTextColor("EVENT");
							std::cout<<std::endl<<" <<<<<<<< Signal inTRp2_1_31 has been Executed!"<<std::endl;
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
// Concrete Signal Handler: V1_inTRp2_1_31
void p2_1::V1_inTRp2_1_31(V1_StateMachineController *smc)
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
				smc->event_status_msg.push_back(" >>>>>>>> Received Signal: inTRp2_1_31");
				smc->event_status_msg.push_back(" <!> State Update: p2_1 => p1_1");
				#endif
				std::cout<<std::endl<<" >>>>>>>> Received Signal: inTRp2_1_31"<<std::endl;
				std::cout<<" <!> State Update: From p2_1 => p1_1"<<std::endl;
				// smc->event_status_msg.push_back("State Changed: p2_1 => p1_1");
				smc->setTextColor("ANY");
				smc->setCurrent(new p1_1());
				delete this;
				smc->setTextColor("EVENT");
				std::cout<<std::endl<<" <<<<<<<< Signal inTRp2_1_31 has been Executed!"<<std::endl;
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
	retStr.push_back("V1_inTRp3_1_33");
	return retStr;
}
		
list<string> p3_1::getCurrentNotificationStatusList()
{
	list<string> retStr;
	return retStr;
}

string p3_1::getCurrentState() { return name; }

list<string> p3_1::isAtleastOneEnabledCommand(V1_StateMachineController *smc)
{
	list<string> list_of_enabled_commands;
	//StateMachineController::InputParametersContainer c;
	return list_of_enabled_commands;
}
list<string> p3_1::isAtleastOneEnabledSignal(V1_StateMachineController *smc)
{
	list<string> list_of_enabled_signals;
	//StateMachineController::InputParametersContainer c;
	// Signal Name: V1_inTRp3_1_33
	{
	list_of_enabled_signals.push_back("V1_inTRp3_1_33");
	}
	return list_of_enabled_signals;
}

void p3_1::executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc)
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

		if(!(*it).compare("V1_inTRp3_1_33"))
		{
			// #1. Call the interface function
			smc->client_api_handler->openEventContext();
			smc->client_api_handler->inTRp3_1_33();

			// #1a. Get the list of received notification and close the context.
			std::vector<string> list_of_rcvd_notifications = smc->client_api_handler->getListOfReceivedNotifications();
			//smc->client_api_handler->closeEventContext();
			std::cout << "[INFO] Number of Notifications Received in Context: " << list_of_rcvd_notifications.size() << std::endl;
			
			vector<int> instance_clause_id = V1_inTRp3_1_33( smc, list_of_rcvd_notifications);
			std::cout << std::endl << "Notifications List matched to Instance ID: " << instance_clause_id.at(0) << " and Clause ID: " << instance_clause_id.at(1) << std::endl;

			// #3. Call the the signal method
			V1_inTRp3_1_33( smc, instance_clause_id.at(0), instance_clause_id.at(1));
			smc->client_api_handler->closeEventContext();
		}
		#endif
		
		#ifndef CLIENT_STUB_API
		if(!(*it).compare("V1_inTRp3_1_33"))
		{
			
			std::cout << "Checking Instance-Clause Preferences for Signal: inTRp3_1_33" << std::endl;
			std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp3_1_33(smc->getCurrentState(), false);
			if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
			{
				// Call the function with Parameters Only
				std::cout << "No preferences found for Signal: inTRp3_1_33" << std::endl;
				
				// Call the function with Parameters
				V1_inTRp3_1_33( smc);
				smc->setTextColor("EVENT");
				std::cout<<std::endl<<" <<<<<<<< Command inTRp3_1_33 has been Executed!"<<std::endl;
				smc->setTextColor("ANY");
			}
			else
			{
				std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp3_1_33(smc->getCurrentState(), false);
				bool isAtleastOneInstanceEnabled = false;
				for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
				{
					if (isEnabledV1_inTRp3_1_33(smc, list_of_instance_id.at(i)))
					{
						instance_clause_id.at(0) = list_of_instance_id.at(i);
						std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp3_1_33(smc->getCurrentState(), list_of_instance_id.at(i), false);
						instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
						isAtleastOneInstanceEnabled = true;
					}
				}
				if(!isAtleastOneInstanceEnabled)
				{
					std::cout << "EXCEPTION: None of the instances of command: inTRp3_1_33 specified in the input file are enabled. Check the parameter set, if any!" << std::endl;
					//throw (StateMachineController::StubException("EXCEPTION: None of the instances of command: inTRp3_1_33 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));
				}
					
				// Call function with Parameters and Instance-Clause ID
				std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Command: inTRp3_1_33" << std::endl;
				
				// Call the function with Parameters
				V1_inTRp3_1_33( smc, instance_clause_id.at(0), instance_clause_id.at(1));
				smc->setTextColor("EVENT");
				std::cout<<std::endl<<" <<<<<<<< Command inTRp3_1_33 has been Executed!"<<std::endl;
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

bool p3_1::checkEnabledCommandAndSignalInState(V1_StateMachineController *smc)
{
	if(determineEnabledCommandAndSignalInState(smc).empty())
			return false;
		else
			return true;
}

list<string> p3_1::determineEnabledCommandAndSignalInState(V1_StateMachineController *smc)
{
	list<string> enabled_commands_and_signals_list = isAtleastOneEnabledCommand(smc);
	enabled_commands_and_signals_list.splice(enabled_commands_and_signals_list.end(), isAtleastOneEnabledSignal(smc));
	return enabled_commands_and_signals_list;
}


bool p3_1::isAtleastOneEnabledNotification(V1_StateMachineController *smc)
{
	UNREF_PARAM(smc);
	// Means there is no notification?
	return false;
}

// Enabling Test for Signal: V1_inTRp3_1_33
bool p3_1::isEnabledV1_inTRp3_1_33(V1_StateMachineController *smc, int instance_choice)
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
// Concrete Signal Context NI Validator: V1_inTRp3_1_33
std::vector<int> p3_1::V1_inTRp3_1_33(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications)
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
					const StateMachineController::V1_StateMachineController& smcRef = *smc;
					StateMachineController::smVarContainer var_copy(smcRef);
					switch(choice)
					{
					case 0: // Signal Clause
							{
							smc->setTextColor("EVENT");
							#ifdef QT_GUI
							smc->event_status_msg.push_back(" >>>>>>>> Received Signal: inTRp3_1_33");
							smc->event_status_msg.push_back(" <!> State Update: p3_1 => p3_2");
							#endif
							// std::cout<<std::endl<<" >>>>>>>> Received Signal: inTRp3_1_33"<<std::endl;
							// std::cout<<" <!> State Update: From p3_1 => p3_2"<<std::endl;
							// smc->event_status_msg.push_back("State Changed: p3_1 => p3_2");
							smc->setTextColor("ANY");
							bool is_equal = false;
							if (observed_notifications.size() == list_of_rcvd_notifications.size())
								is_equal = std::equal(observed_notifications.begin(), observed_notifications.end(), list_of_rcvd_notifications.begin());
							if (is_equal) { instance_clause_id.push_back(0); instance_clause_id.push_back(0); return instance_clause_id; }
							else { observed_notifications.clear(); }
							smc->setTextColor("EVENT");
							// std::cout<<std::endl<<" <<<<<<<< Signal inTRp3_1_33 has been Executed!"<<std::endl;
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
// Concrete Deterministic Signal Handler: V1_inTRp3_1_33
void p3_1::V1_inTRp3_1_33(V1_StateMachineController *smc, int instance_id, int clause_id)
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
							smc->event_status_msg.push_back(" >>>>>>>> Received Signal: inTRp3_1_33");
							smc->event_status_msg.push_back(" <!> State Update: p3_1 => p3_2");
							#endif
							std::cout<<std::endl<<" >>>>>>>> Received Signal: inTRp3_1_33"<<std::endl;
							std::cout<<" <!> State Update: From p3_1 => p3_2"<<std::endl;
							// smc->event_status_msg.push_back("State Changed: p3_1 => p3_2");
							smc->setTextColor("ANY");
							smc->setCurrent(new p3_2());
							delete this;
							smc->setTextColor("EVENT");
							std::cout<<std::endl<<" <<<<<<<< Signal inTRp3_1_33 has been Executed!"<<std::endl;
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
// Concrete Signal Handler: V1_inTRp3_1_33
void p3_1::V1_inTRp3_1_33(V1_StateMachineController *smc)
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
				smc->event_status_msg.push_back(" >>>>>>>> Received Signal: inTRp3_1_33");
				smc->event_status_msg.push_back(" <!> State Update: p3_1 => p3_2");
				#endif
				std::cout<<std::endl<<" >>>>>>>> Received Signal: inTRp3_1_33"<<std::endl;
				std::cout<<" <!> State Update: From p3_1 => p3_2"<<std::endl;
				// smc->event_status_msg.push_back("State Changed: p3_1 => p3_2");
				smc->setTextColor("ANY");
				smc->setCurrent(new p3_2());
				delete this;
				smc->setTextColor("EVENT");
				std::cout<<std::endl<<" <<<<<<<< Signal inTRp3_1_33 has been Executed!"<<std::endl;
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




/*********** Concrete State Class: p3_2 ***********/

list<string> p3_2::getCurrentCommandStatusList() 
{
	list<string> retStr;
	return retStr;
}

list<string> p3_2::getCurrentSignalStatusList()
{
	list<string> retStr;
	retStr.push_back("V1_inTRp3_1_32");
	return retStr;
}
		
list<string> p3_2::getCurrentNotificationStatusList()
{
	list<string> retStr;
	return retStr;
}

string p3_2::getCurrentState() { return name; }

list<string> p3_2::isAtleastOneEnabledCommand(V1_StateMachineController *smc)
{
	list<string> list_of_enabled_commands;
	//StateMachineController::InputParametersContainer c;
	return list_of_enabled_commands;
}
list<string> p3_2::isAtleastOneEnabledSignal(V1_StateMachineController *smc)
{
	list<string> list_of_enabled_signals;
	//StateMachineController::InputParametersContainer c;
	// Signal Name: V1_inTRp3_1_32
	{
	list_of_enabled_signals.push_back("V1_inTRp3_1_32");
	}
	return list_of_enabled_signals;
}

void p3_2::executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc)
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

		if(!(*it).compare("V1_inTRp3_1_32"))
		{
			// #1. Call the interface function
			smc->client_api_handler->openEventContext();
			smc->client_api_handler->inTRp3_1_32();

			// #1a. Get the list of received notification and close the context.
			std::vector<string> list_of_rcvd_notifications = smc->client_api_handler->getListOfReceivedNotifications();
			//smc->client_api_handler->closeEventContext();
			std::cout << "[INFO] Number of Notifications Received in Context: " << list_of_rcvd_notifications.size() << std::endl;
			
			vector<int> instance_clause_id = V1_inTRp3_1_32( smc, list_of_rcvd_notifications);
			std::cout << std::endl << "Notifications List matched to Instance ID: " << instance_clause_id.at(0) << " and Clause ID: " << instance_clause_id.at(1) << std::endl;

			// #3. Call the the signal method
			V1_inTRp3_1_32( smc, instance_clause_id.at(0), instance_clause_id.at(1));
			smc->client_api_handler->closeEventContext();
		}
		#endif
		
		#ifndef CLIENT_STUB_API
		if(!(*it).compare("V1_inTRp3_1_32"))
		{
			
			std::cout << "Checking Instance-Clause Preferences for Signal: inTRp3_1_32" << std::endl;
			std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp3_1_32(smc->getCurrentState(), false);
			if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
			{
				// Call the function with Parameters Only
				std::cout << "No preferences found for Signal: inTRp3_1_32" << std::endl;
				
				// Call the function with Parameters
				V1_inTRp3_1_32( smc);
				smc->setTextColor("EVENT");
				std::cout<<std::endl<<" <<<<<<<< Command inTRp3_1_32 has been Executed!"<<std::endl;
				smc->setTextColor("ANY");
			}
			else
			{
				std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp3_1_32(smc->getCurrentState(), false);
				bool isAtleastOneInstanceEnabled = false;
				for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
				{
					if (isEnabledV1_inTRp3_1_32(smc, list_of_instance_id.at(i)))
					{
						instance_clause_id.at(0) = list_of_instance_id.at(i);
						std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp3_1_32(smc->getCurrentState(), list_of_instance_id.at(i), false);
						instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
						isAtleastOneInstanceEnabled = true;
					}
				}
				if(!isAtleastOneInstanceEnabled)
				{
					std::cout << "EXCEPTION: None of the instances of command: inTRp3_1_32 specified in the input file are enabled. Check the parameter set, if any!" << std::endl;
					//throw (StateMachineController::StubException("EXCEPTION: None of the instances of command: inTRp3_1_32 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));
				}
					
				// Call function with Parameters and Instance-Clause ID
				std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Command: inTRp3_1_32" << std::endl;
				
				// Call the function with Parameters
				V1_inTRp3_1_32( smc, instance_clause_id.at(0), instance_clause_id.at(1));
				smc->setTextColor("EVENT");
				std::cout<<std::endl<<" <<<<<<<< Command inTRp3_1_32 has been Executed!"<<std::endl;
				smc->setTextColor("ANY");
			}
		}
		#endif
	}
	else
	{
		std::cout<<std::endl<<"ERROR: No Enabled Commands or Signals in State: p3_2"<<std::endl;
		//throw (StubException("EXCEPTION: No Enabled Commands or Signals in State: p3_2", NO_ENABLED_GUARDS));
	}
}

bool p3_2::checkEnabledCommandAndSignalInState(V1_StateMachineController *smc)
{
	if(determineEnabledCommandAndSignalInState(smc).empty())
			return false;
		else
			return true;
}

list<string> p3_2::determineEnabledCommandAndSignalInState(V1_StateMachineController *smc)
{
	list<string> enabled_commands_and_signals_list = isAtleastOneEnabledCommand(smc);
	enabled_commands_and_signals_list.splice(enabled_commands_and_signals_list.end(), isAtleastOneEnabledSignal(smc));
	return enabled_commands_and_signals_list;
}


bool p3_2::isAtleastOneEnabledNotification(V1_StateMachineController *smc)
{
	UNREF_PARAM(smc);
	// Means there is no notification?
	return false;
}

// Enabling Test for Signal: V1_inTRp3_1_32
bool p3_2::isEnabledV1_inTRp3_1_32(V1_StateMachineController *smc, int instance_choice)
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
// Concrete Signal Context NI Validator: V1_inTRp3_1_32
std::vector<int> p3_2::V1_inTRp3_1_32(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications)
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
					const StateMachineController::V1_StateMachineController& smcRef = *smc;
					StateMachineController::smVarContainer var_copy(smcRef);
					switch(choice)
					{
					case 0: // Signal Clause
							{
							smc->setTextColor("EVENT");
							#ifdef QT_GUI
							smc->event_status_msg.push_back(" >>>>>>>> Received Signal: inTRp3_1_32");
							smc->event_status_msg.push_back(" <!> State Update: p3_2 => p1_1");
							#endif
							// std::cout<<std::endl<<" >>>>>>>> Received Signal: inTRp3_1_32"<<std::endl;
							// std::cout<<" <!> State Update: From p3_2 => p1_1"<<std::endl;
							// smc->event_status_msg.push_back("State Changed: p3_2 => p1_1");
							smc->setTextColor("ANY");
							bool is_equal = false;
							if (observed_notifications.size() == list_of_rcvd_notifications.size())
								is_equal = std::equal(observed_notifications.begin(), observed_notifications.end(), list_of_rcvd_notifications.begin());
							if (is_equal) { instance_clause_id.push_back(0); instance_clause_id.push_back(0); return instance_clause_id; }
							else { observed_notifications.clear(); }
							smc->setTextColor("EVENT");
							// std::cout<<std::endl<<" <<<<<<<< Signal inTRp3_1_32 has been Executed!"<<std::endl;
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
		smc->event_status_msg.push_back("ERROR: NO GUARDS FOR THIS SIGNAL ARE ENABLED in STATE: p3_2");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS FOR THIS SIGNAL ARE ENABLED in STATE: p3_2!", NO_ENABLED_GUARDS));
		
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
// Concrete Deterministic Signal Handler: V1_inTRp3_1_32
void p3_2::V1_inTRp3_1_32(V1_StateMachineController *smc, int instance_id, int clause_id)
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
							smc->event_status_msg.push_back(" >>>>>>>> Received Signal: inTRp3_1_32");
							smc->event_status_msg.push_back(" <!> State Update: p3_2 => p1_1");
							#endif
							std::cout<<std::endl<<" >>>>>>>> Received Signal: inTRp3_1_32"<<std::endl;
							std::cout<<" <!> State Update: From p3_2 => p1_1"<<std::endl;
							// smc->event_status_msg.push_back("State Changed: p3_2 => p1_1");
							smc->setTextColor("ANY");
							smc->setCurrent(new p1_1());
							delete this;
							smc->setTextColor("EVENT");
							std::cout<<std::endl<<" <<<<<<<< Signal inTRp3_1_32 has been Executed!"<<std::endl;
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
		smc->event_status_msg.push_back("ERROR: NO GUARDS FOR THIS SIGNAL ARE ENABLED in STATE: p3_2");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS FOR THIS SIGNAL ARE ENABLED in STATE: p3_2!", NO_ENABLED_GUARDS));
		
	}
}
// Concrete Signal Handler: V1_inTRp3_1_32
void p3_2::V1_inTRp3_1_32(V1_StateMachineController *smc)
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
				smc->event_status_msg.push_back(" >>>>>>>> Received Signal: inTRp3_1_32");
				smc->event_status_msg.push_back(" <!> State Update: p3_2 => p1_1");
				#endif
				std::cout<<std::endl<<" >>>>>>>> Received Signal: inTRp3_1_32"<<std::endl;
				std::cout<<" <!> State Update: From p3_2 => p1_1"<<std::endl;
				// smc->event_status_msg.push_back("State Changed: p3_2 => p1_1");
				smc->setTextColor("ANY");
				smc->setCurrent(new p1_1());
				delete this;
				smc->setTextColor("EVENT");
				std::cout<<std::endl<<" <<<<<<<< Signal inTRp3_1_32 has been Executed!"<<std::endl;
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
		smc->event_status_msg.push_back("ERROR: NO GUARDS FOR THIS SIGNAL ARE ENABLED in STATE: p3_2");
		smc->setTextColor("ANY");
		//throw (StubException("EXCEPTION: NO GUARDS FOR THIS SIGNAL ARE ENABLED in STATE: p3_2!", NO_ENABLED_GUARDS));
		
	}
}


}
