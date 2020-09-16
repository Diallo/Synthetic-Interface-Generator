#include "V1StubAdapter.h"

std::mutex NotificationEventHandler::mtx;
std::condition_variable NotificationEventHandler::cv;
StateMachineController::outTRp1_2_25_Handler NotificationEventHandler::m_outTRp1_2_25CB;
StateMachineController::outTRp1_3_26_Handler NotificationEventHandler::m_outTRp1_3_26CB;
StateMachineController::outTRp1_5_28_Handler NotificationEventHandler::m_outTRp1_5_28CB;
StateMachineController::outTRp1_6_29_Handler NotificationEventHandler::m_outTRp1_6_29CB;
StateMachineController::outTRp1_6_30_Handler NotificationEventHandler::m_outTRp1_6_30CB;

void NotificationEventHandler::waitForEvent()
{
	std::cout << std::endl;
	std::cout << "[INFO] @STUB_ADAPTER: !!!!! Waiting for Notification from State Machine Controller... " << std::endl;
	std::cout << std::endl;

	isTimeOut = std::cv_status::no_timeout;

	// Critical Section: Implementation of Wait For Notification!
	{
		std::unique_lock<std::mutex> lck(NotificationEventHandler::mtx);
		// cv.wait(lck);
		isTimeOut = NotificationEventHandler::cv.wait_for(lck, std::chrono::seconds(NI_TIMEOUT));
	}
	if (isTimeOut == std::cv_status::timeout)
	{
		// timeout occured!
		std::cout << "[WARN] @STUB_ADAPTER: Time out has occured!!" << std::endl;
	}
}

NotificationEventHandler::~NotificationEventHandler()
{
	// De-register all the client callbacks
	if(m_outTRp1_2_25CB != nullptr) m_outTRp1_2_25CB = nullptr;
	if(m_outTRp1_3_26CB != nullptr) m_outTRp1_3_26CB = nullptr;
	if(m_outTRp1_5_28CB != nullptr) m_outTRp1_5_28CB = nullptr;
	if(m_outTRp1_6_29CB != nullptr) m_outTRp1_6_29CB = nullptr;
	if(m_outTRp1_6_30CB != nullptr) m_outTRp1_6_30CB = nullptr;
}

EventAPI::EventAPI()
{
	srand(time(0));
	sim_mode = SERVER_STUB;
	signalInitlist.push_back("V1_inTRp1_1_24");
	signalInitlist.push_back("V1_inTRp1_1_27");
	signalInitlist.push_back("V1_inTRp2_1_31");
	signalInitlist.push_back("V1_inTRp3_1_32");
	signalInitlist.push_back("V1_inTRp3_1_33");
	notificationInitlist.push_back("V1_outTRp1_2_25");
	notificationInitlist.push_back("V1_outTRp1_3_26");
	notificationInitlist.push_back("V1_outTRp1_5_28");
	notificationInitlist.push_back("V1_outTRp1_6_29");
	notificationInitlist.push_back("V1_outTRp1_6_30");
	
	ev = new StateMachineController::EventViewer(sim_mode);
	er = new StateMachineController::EventRepository(commandInitlist, signalInitlist, notificationInitlist);
	er->RegisterDataChangeHandler(&StateMachineController::EventViewer::updateAvailableEvents);
	smc = new StateMachineController::V1_StateMachineController(er, sim_mode);
	StateMachineController::SimulatorConfiguration sc;
	
	// TODO DEBUG ONLY; REMOVE.
	// smc->RegisterNIHandler(&NotificationEventHandler::niEvt);
	
	smc->register_outTRp1_2_25_Handler(&NotificationEventHandler::outTRp1_2_25);
	smc->register_outTRp1_3_26_Handler(&NotificationEventHandler::outTRp1_3_26);
	smc->register_outTRp1_5_28_Handler(&NotificationEventHandler::outTRp1_5_28);
	smc->register_outTRp1_6_29_Handler(&NotificationEventHandler::outTRp1_6_29);
	smc->register_outTRp1_6_30_Handler(&NotificationEventHandler::outTRp1_6_30);
	
	srand((unsigned int)time(NULL));
}






void EventAPI::inTRp1_1_24()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp1_1_24" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp1_1_24(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp1_1_24();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp1_1_24(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp1_1_24(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp1_1_24(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp1_1_24 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp1_1_24" << std::endl;
		smc->_V1_inTRp1_1_24(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp1_1_27()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp1_1_27" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp1_1_27(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp1_1_27();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp1_1_27(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp1_1_27(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp1_1_27(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp1_1_27 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp1_1_27" << std::endl;
		smc->_V1_inTRp1_1_27(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp2_1_31()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp2_1_31" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp2_1_31(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp2_1_31();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp2_1_31(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp2_1_31(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp2_1_31(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp2_1_31 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp2_1_31" << std::endl;
		smc->_V1_inTRp2_1_31(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp3_1_32()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp3_1_32" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp3_1_32(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp3_1_32();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp3_1_32(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp3_1_32(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp3_1_32(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp3_1_32 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp3_1_32" << std::endl;
		smc->_V1_inTRp3_1_32(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp3_1_33()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp3_1_33" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp3_1_33(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp3_1_33();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp3_1_33(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp3_1_33(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp3_1_33(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp3_1_33 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp3_1_33" << std::endl;
		smc->_V1_inTRp3_1_33(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}
