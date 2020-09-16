#ifndef CLIENTSTUBLIFECYCLEMANAGER_H_
#define CLIENTSTUBLIFECYCLEMANAGER_H_

#include "V1_StateMachineController.h"
#include "V1StubAdapter.h"
#include "EventViewer.h"

#ifdef SSCF_CLIENT_STUB_ADAPTER
//#include "V1.h"
#include "V1.h"
#include "SSCFClientConnection.h"
#endif

#ifdef SSCF_CLIENT_STUB_ADAPTER
namespace UNDEFINED {
	
	// Record Type Definitions for SSCF
	
//namespace SscfV1 {
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
		
		#ifndef SSCF_CLIENT_STUB_ADAPTER
		smc = new StateMachineController::V1_StateMachineController(er, sim_mode);
		m_niHandler = new StateMachineController::NiHandler(*smc);
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		smc = new StateMachineController::V1_StateMachineController(er, sim_mode, m_connection);
		#endif
		
		#ifndef SSCF_CLIENT_STUB_ADAPTER
		// Register call backs to the state machine controller
		m_niHandler->register_outTRp1_2_25_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_2_25_clHandler);
		m_niHandler->register_outTRp1_3_26_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_3_26_clHandler);
		m_niHandler->register_outTRp1_5_28_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_5_28_clHandler);
		m_niHandler->register_outTRp1_6_29_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_6_29_clHandler);
		m_niHandler->register_outTRp1_6_30_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_6_30_clHandler);
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp1_2_25_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_2_25_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp1_3_26_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_3_26_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp1_5_28_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_5_28_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp1_6_29_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_6_29_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp1_6_30_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_6_30_clHandler);
		#endif

		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp1_2_25, [&]()
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
			std::cout << "received NI: outTRp1_2_25 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp1_2_25();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp1_3_26, [&]()
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
			std::cout << "received NI: outTRp1_3_26 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp1_3_26();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp1_5_28, [&]()
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
			std::cout << "received NI: outTRp1_5_28 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp1_5_28();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp1_6_29, [&]()
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
			std::cout << "received NI: outTRp1_6_29 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp1_6_29();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp1_6_30, [&]()
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
			std::cout << "received NI: outTRp1_6_30 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp1_6_30();
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

	StateMachineController::V1_StateMachineController* getSmc() { return smc; }

private:
	int sim_mode;
	std::list<std::string> commandInitlist;
	std::list<std::string> signalInitlist;
	std::list<std::string> notificationInitlist;

	#ifdef SSCF_CLIENT_STUB_ADAPTER
	SscfClientConnection<V1Proxy, V1> m_connection;
	//std::mutex m_mutex;
	#endif

	StateMachineController::EventViewer *ev;
	StateMachineController::EventRepository *er;
	StateMachineController::V1_StateMachineController *smc;
	#ifndef SSCF_CLIENT_STUB_ADAPTER
	StateMachineController::NiHandler *m_niHandler;
	#endif
};
#ifdef SSCF_CLIENT_STUB_ADAPTER
}
#endif

#endif
