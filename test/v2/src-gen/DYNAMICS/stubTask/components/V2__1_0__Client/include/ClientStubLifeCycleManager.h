#ifndef CLIENTSTUBLIFECYCLEMANAGER_H_
#define CLIENTSTUBLIFECYCLEMANAGER_H_

#include "V2_StateMachineController.h"
#include "V2StubAdapter.h"
#include "EventViewer.h"

#ifdef SSCF_CLIENT_STUB_ADAPTER
//#include "V2.h"
#include "V2.h"
#include "SSCFClientConnection.h"
#endif

#ifdef SSCF_CLIENT_STUB_ADAPTER
namespace UNDEFINED {
	
	// Record Type Definitions for SSCF
	
//namespace SscfV2 {
#endif

// This class owns the client stub and provides a handle to raise notifications
#ifndef SSCF_CLIENT_STUB_ADAPTER
class ClientStubLifeCycleManager
#endif
#ifdef SSCF_CLIENT_STUB_ADAPTER
class ClientStubLifeCycleManager : public SscfTs1::EventHandler
#endif
{
public:
	#ifndef SSCF_CLIENT_STUB_ADAPTER
	ClientStubLifeCycleManager()
	#endif
	#ifdef SSCF_CLIENT_STUB_ADAPTER
	ClientStubLifeCycleManager(SscfTs1::EventLoop& eventLoop, std::string network, std::string serviceResourceName) : m_connection(eventLoop, network, serviceResourceName)
	#endif	
	{
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		std::cout << "Connecting to server..." << std::endl;
		m_connection.Connect();

		do {
			//std::cout << "Connecting to server..." << std::endl;
		} while (!m_connection.IsConnected());

		if (m_connection.IsConnected())
		{
			std::cout << "Connected to server" << std::endl;
		}
		#endif
		
		sim_mode = CLIENT_STUB;

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
		
		#ifndef SSCF_CLIENT_STUB_ADAPTER
		smc = new StateMachineController::V2_StateMachineController(er, sim_mode);
		m_niHandler = new StateMachineController::NiHandler(*smc);
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		smc = new StateMachineController::V2_StateMachineController(er, sim_mode, m_connection);
		#endif
		
		#ifndef SSCF_CLIENT_STUB_ADAPTER
		// Register call backs to the state machine controller
		m_niHandler->register_outTRp1_2_12_CBHandler(&StateMachineController::V2_StateMachineController::outTRp1_2_12_clHandler);
		m_niHandler->register_outTRp1_1_15_CBHandler(&StateMachineController::V2_StateMachineController::outTRp1_1_15_clHandler);
		m_niHandler->register_outTRp1_1_16_CBHandler(&StateMachineController::V2_StateMachineController::outTRp1_1_16_clHandler);
		m_niHandler->register_outTRp1_6_19_CBHandler(&StateMachineController::V2_StateMachineController::outTRp1_6_19_clHandler);
		m_niHandler->register_outTRp1_8_21_CBHandler(&StateMachineController::V2_StateMachineController::outTRp1_8_21_clHandler);
		m_niHandler->register_outTRp1_6_22_CBHandler(&StateMachineController::V2_StateMachineController::outTRp1_6_22_clHandler);
		m_niHandler->register_outTRp1_9_23_CBHandler(&StateMachineController::V2_StateMachineController::outTRp1_9_23_clHandler);
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp1_2_12_CBHandler(&StateMachineController::V2_StateMachineController::outTRp1_2_12_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp1_1_15_CBHandler(&StateMachineController::V2_StateMachineController::outTRp1_1_15_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp1_1_16_CBHandler(&StateMachineController::V2_StateMachineController::outTRp1_1_16_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp1_6_19_CBHandler(&StateMachineController::V2_StateMachineController::outTRp1_6_19_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp1_8_21_CBHandler(&StateMachineController::V2_StateMachineController::outTRp1_8_21_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp1_6_22_CBHandler(&StateMachineController::V2_StateMachineController::outTRp1_6_22_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp1_9_23_CBHandler(&StateMachineController::V2_StateMachineController::outTRp1_9_23_clHandler);
		#endif

		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp1_2_12, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp1_2_12 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp1_2_12();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp1_1_15, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp1_1_15 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp1_1_15();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp1_1_16, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp1_1_16 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp1_1_16();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp1_6_19, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp1_6_19 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp1_6_19();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp1_8_21, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp1_8_21 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp1_8_21();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp1_6_22, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp1_6_22 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp1_6_22();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp1_9_23, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp1_9_23 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp1_9_23();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
	}
	

	#ifndef SSCF_CLIENT_STUB_ADAPTER
	StateMachineController::NiHandler& getNIHandler() { return *m_niHandler; }
	#endif

	~ClientStubLifeCycleManager()
	{
		delete smc;
		delete er;
		delete ev;
		#ifndef SSCF_CLIENT_STUB_ADAPTER
		delete m_niHandler;
		#endif
	}

	StateMachineController::V2_StateMachineController* getSmc() { return smc; }

private:
	int sim_mode;
	std::list<std::string> commandInitlist;
	std::list<std::string> signalInitlist;
	std::list<std::string> notificationInitlist;

	#ifdef SSCF_CLIENT_STUB_ADAPTER
	SscfClientConnection<V2Proxy, V2> m_connection;
	//std::mutex m_mutex;
	#endif

	StateMachineController::EventViewer *ev;
	StateMachineController::EventRepository *er;
	StateMachineController::V2_StateMachineController *smc;
	#ifndef SSCF_CLIENT_STUB_ADAPTER
	StateMachineController::NiHandler *m_niHandler;
	#endif
};
#ifdef SSCF_CLIENT_STUB_ADAPTER
}
#endif

#endif
