#include "V2StubAdapter.h"

std::mutex NotificationEventHandler::mtx;
std::condition_variable NotificationEventHandler::cv;
StateMachineController::outTRp1_2_12_Handler NotificationEventHandler::m_outTRp1_2_12CB;
StateMachineController::outTRp1_1_15_Handler NotificationEventHandler::m_outTRp1_1_15CB;
StateMachineController::outTRp1_1_16_Handler NotificationEventHandler::m_outTRp1_1_16CB;
StateMachineController::outTRp1_6_19_Handler NotificationEventHandler::m_outTRp1_6_19CB;
StateMachineController::outTRp1_8_21_Handler NotificationEventHandler::m_outTRp1_8_21CB;
StateMachineController::outTRp1_6_22_Handler NotificationEventHandler::m_outTRp1_6_22CB;
StateMachineController::outTRp1_9_23_Handler NotificationEventHandler::m_outTRp1_9_23CB;

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
	if(m_outTRp1_2_12CB != nullptr) m_outTRp1_2_12CB = nullptr;
	if(m_outTRp1_1_15CB != nullptr) m_outTRp1_1_15CB = nullptr;
	if(m_outTRp1_1_16CB != nullptr) m_outTRp1_1_16CB = nullptr;
	if(m_outTRp1_6_19CB != nullptr) m_outTRp1_6_19CB = nullptr;
	if(m_outTRp1_8_21CB != nullptr) m_outTRp1_8_21CB = nullptr;
	if(m_outTRp1_6_22CB != nullptr) m_outTRp1_6_22CB = nullptr;
	if(m_outTRp1_9_23CB != nullptr) m_outTRp1_9_23CB = nullptr;
}

EventAPI::EventAPI()
{
	srand(time(0));
	sim_mode = SERVER_STUB;
	signalInitlist.push_back("V2_inTRp1_1_11");
	signalInitlist.push_back("V2_inTRp1_3_13");
	signalInitlist.push_back("V2_inTRp1_4_14");
	signalInitlist.push_back("V2_inTRp2_1_17");
	signalInitlist.push_back("V2_inTRp3_1_18");
	notificationInitlist.push_back("V2_outTRp1_2_12");
	notificationInitlist.push_back("V2_outTRp1_1_15");
	notificationInitlist.push_back("V2_outTRp1_1_16");
	notificationInitlist.push_back("V2_outTRp1_6_19");
	notificationInitlist.push_back("V2_outTRp1_8_21");
	notificationInitlist.push_back("V2_outTRp1_6_22");
	notificationInitlist.push_back("V2_outTRp1_9_23");
	
	ev = new StateMachineController::EventViewer(sim_mode);
	er = new StateMachineController::EventRepository(commandInitlist, signalInitlist, notificationInitlist);
	er->RegisterDataChangeHandler(&StateMachineController::EventViewer::updateAvailableEvents);
	smc = new StateMachineController::V2_StateMachineController(er, sim_mode);
	StateMachineController::SimulatorConfiguration sc;
	
	// TODO DEBUG ONLY; REMOVE.
	// smc->RegisterNIHandler(&NotificationEventHandler::niEvt);
	
	smc->register_outTRp1_2_12_Handler(&NotificationEventHandler::outTRp1_2_12);
	smc->register_outTRp1_1_15_Handler(&NotificationEventHandler::outTRp1_1_15);
	smc->register_outTRp1_1_16_Handler(&NotificationEventHandler::outTRp1_1_16);
	smc->register_outTRp1_6_19_Handler(&NotificationEventHandler::outTRp1_6_19);
	smc->register_outTRp1_8_21_Handler(&NotificationEventHandler::outTRp1_8_21);
	smc->register_outTRp1_6_22_Handler(&NotificationEventHandler::outTRp1_6_22);
	smc->register_outTRp1_9_23_Handler(&NotificationEventHandler::outTRp1_9_23);
	
	srand((unsigned int)time(NULL));
}






void EventAPI::inTRp1_1_11()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp1_1_11" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp1_1_11(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V2_inTRp1_1_11();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp1_1_11(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV2_inTRp1_1_11(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp1_1_11(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp1_1_11 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp1_1_11" << std::endl;
		smc->_V2_inTRp1_1_11(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp1_3_13()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp1_3_13" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp1_3_13(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V2_inTRp1_3_13();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp1_3_13(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV2_inTRp1_3_13(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp1_3_13(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp1_3_13 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp1_3_13" << std::endl;
		smc->_V2_inTRp1_3_13(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp1_4_14()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp1_4_14" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp1_4_14(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V2_inTRp1_4_14();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp1_4_14(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV2_inTRp1_4_14(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp1_4_14(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp1_4_14 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp1_4_14" << std::endl;
		smc->_V2_inTRp1_4_14(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp2_1_17()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp2_1_17" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp2_1_17(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V2_inTRp2_1_17();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp2_1_17(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV2_inTRp2_1_17(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp2_1_17(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp2_1_17 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp2_1_17" << std::endl;
		smc->_V2_inTRp2_1_17(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp3_1_18()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp3_1_18" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp3_1_18(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V2_inTRp3_1_18();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp3_1_18(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV2_inTRp3_1_18(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp3_1_18(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp3_1_18 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp3_1_18" << std::endl;
		smc->_V2_inTRp3_1_18(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}
