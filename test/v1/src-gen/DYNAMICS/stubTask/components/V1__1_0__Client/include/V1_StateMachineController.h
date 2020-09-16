#ifndef V1_STATEMACHINECONTROLLER_H_
#define V1_STATEMACHINECONTROLLER_H_

#include "common.h"
#include "EventRepository.h"
#include "NotificationCallbackThread.h"
#include "InputParametersContainer.h"

#ifdef SSCF_VERSION
#include "V1_SMCServerAdapter.h"
#endif

#ifdef QT_GUI
#include "mainwindow.h"
#endif

#include <mutex>
#include <condition_variable>

#ifdef SSCF_VERSION
namespace UNDEFINED { class V1Server; }
#endif

#ifdef QT_GUI
class MainWindow;
#endif

#ifdef CLIENT_STUB_API
#include "V1StubAdapter.h"

#ifdef SSCF_CLIENT_STUB_ADAPTER
//#include "V1.h"
#include "V1.h"
#include "SSCFClientConnection.h"
#endif

#endif

namespace StateMachineController {

/*********** State Machine Controller Class ***********/

class V1_StateMachineController {
	public:
		#ifdef SSCF_VERSION
		V1_StateMachineController(class EventRepository *er, 
						class UNDEFINED::V1Server *srv, int sim_mode);
		#endif
		
		#ifndef SSCF_VERSION
		
		#ifndef SSCF_CLIENT_STUB_ADAPTER
		V1_StateMachineController(class EventRepository *er, int sim_mode);
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		V1_StateMachineController(class EventRepository *er, int sim_mode, 
			SscfClientConnection<UNDEFINED::V1Proxy, UNDEFINED::V1>& _m_connection);
		#endif
		
		#endif
		
		#ifdef QT_GUI
		V1_StateMachineController(class EventRepository *er, 
						class MainWindow *mw, int sim_mode);
		#endif 
		
		virtual ~V1_StateMachineController();
		
		
		
		
		class V1_State *current;
		#ifdef SSCF_VERSION
		class UNDEFINED::V1Server *m_serverPtr;
		#endif
		
		#ifdef QT_GUI
		class MainWindow *m_mw;
		#endif
		
		class NotificationCallbackThread *timer;
		
		StateMachineController::InputParametersContainer c;
		
		#ifdef CLIENT_STUB_API
		class EventAPIHandler *client_api_handler;
		#endif
		
		list<string> event_status_msg;
		
		// TODO: Added for Test Main subscriptions to Notifications. To be Extended for Server Stubs. DONE. Remove.
		niHandler m_niHandler;
		void RegisterNIHandler(niHandler _niHandler) { this->m_niHandler = _niHandler; }
		
		#ifdef CLIENT_STUB_API
		bool isNotificationExpected = false;
		bool isNotificationInProcess = false;
		// client stub feature to receive notifications
		static bool outTRp1_2_25_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_2_25!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_2_25!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp1_2_25!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp1_2_25(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp1_2_25 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp1_2_25: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp1_2_25(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
					smc.isNotificationExpected = false;
					smc.isNotificationInProcess = false;
					return true;
				}
			}
			else {
				std::cout<<"FATAL: Incorrect construction of instance-clause pair!"<<std::endl;
				//throw (StubException("EXCEPTION: Incorrect construction of instance-clause pair!", LOGICAL_ERROR));
			}
			smc.isNotificationInProcess = false;
			return false;
		}
		static bool outTRp1_3_26_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_3_26!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_3_26!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp1_3_26!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp1_3_26(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp1_3_26 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp1_3_26: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp1_3_26(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
					smc.isNotificationExpected = false;
					smc.isNotificationInProcess = false;
					return true;
				}
			}
			else {
				std::cout<<"FATAL: Incorrect construction of instance-clause pair!"<<std::endl;
				//throw (StubException("EXCEPTION: Incorrect construction of instance-clause pair!", LOGICAL_ERROR));
			}
			smc.isNotificationInProcess = false;
			return false;
		}
		static bool outTRp1_5_28_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_5_28!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_5_28!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp1_5_28!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp1_5_28(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp1_5_28 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp1_5_28: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp1_5_28(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
					smc.isNotificationExpected = false;
					smc.isNotificationInProcess = false;
					return true;
				}
			}
			else {
				std::cout<<"FATAL: Incorrect construction of instance-clause pair!"<<std::endl;
				//throw (StubException("EXCEPTION: Incorrect construction of instance-clause pair!", LOGICAL_ERROR));
			}
			smc.isNotificationInProcess = false;
			return false;
		}
		static bool outTRp1_6_29_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_6_29!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_6_29!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp1_6_29!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp1_6_29(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp1_6_29 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp1_6_29: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp1_6_29(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
					smc.isNotificationExpected = false;
					smc.isNotificationInProcess = false;
					return true;
				}
			}
			else {
				std::cout<<"FATAL: Incorrect construction of instance-clause pair!"<<std::endl;
				//throw (StubException("EXCEPTION: Incorrect construction of instance-clause pair!", LOGICAL_ERROR));
			}
			smc.isNotificationInProcess = false;
			return false;
		}
		static bool outTRp1_6_30_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_6_30!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_6_30!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp1_6_30!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp1_6_30(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp1_6_30 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp1_6_30: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp1_6_30(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
					smc.isNotificationExpected = false;
					smc.isNotificationInProcess = false;
					return true;
				}
			}
			else {
				std::cout<<"FATAL: Incorrect construction of instance-clause pair!"<<std::endl;
				//throw (StubException("EXCEPTION: Incorrect construction of instance-clause pair!", LOGICAL_ERROR));
			}
			smc.isNotificationInProcess = false;
			return false;
		}
		#endif
		
		outTRp1_2_25_Handler m_outTRp1_2_25_Handler;
		void register_outTRp1_2_25_Handler(outTRp1_2_25_Handler _outTRp1_2_25_Handler) { this->m_outTRp1_2_25_Handler = _outTRp1_2_25_Handler; }
		outTRp1_3_26_Handler m_outTRp1_3_26_Handler;
		void register_outTRp1_3_26_Handler(outTRp1_3_26_Handler _outTRp1_3_26_Handler) { this->m_outTRp1_3_26_Handler = _outTRp1_3_26_Handler; }
		outTRp1_5_28_Handler m_outTRp1_5_28_Handler;
		void register_outTRp1_5_28_Handler(outTRp1_5_28_Handler _outTRp1_5_28_Handler) { this->m_outTRp1_5_28_Handler = _outTRp1_5_28_Handler; }
		outTRp1_6_29_Handler m_outTRp1_6_29_Handler;
		void register_outTRp1_6_29_Handler(outTRp1_6_29_Handler _outTRp1_6_29_Handler) { this->m_outTRp1_6_29_Handler = _outTRp1_6_29_Handler; }
		outTRp1_6_30_Handler m_outTRp1_6_30_Handler;
		void register_outTRp1_6_30_Handler(outTRp1_6_30_Handler _outTRp1_6_30_Handler) { this->m_outTRp1_6_30_Handler = _outTRp1_6_30_Handler; }
		
		string getCurrentState();
		void setCurrent(V1_State *s) { current = s; }
		list<string> getCurrentCommandStatusList();
		list<string> getCurrentSignalStatusList();
		list<string> getCurrentNotificationStatusList();
		void publishToEventRepo(EventRepository *er);
		bool isIdle();
		void displaySMVars();
		void setSimMode(int sim_mode);
		
		void setTextColor(string col);
		
		bool run_simulation;
		void toggleSimulation(bool print_vars);
		
		// For Client Stub
		void executeAvailableCommandsAndSignalsInState();
		
		//For Server Stub
		void executeInternalTransitions();
		
		// Commands Signature
		
		// Signals Signature
		void _V1_inTRp1_1_24();
		void _V1_inTRp1_1_24(int instance_id, int clause_id);
		bool isEnabledV1_inTRp1_1_24(int instance_id);
		void _V1_inTRp1_1_27();
		void _V1_inTRp1_1_27(int instance_id, int clause_id);
		bool isEnabledV1_inTRp1_1_27(int instance_id);
		void _V1_inTRp2_1_31();
		void _V1_inTRp2_1_31(int instance_id, int clause_id);
		bool isEnabledV1_inTRp2_1_31(int instance_id);
		void _V1_inTRp3_1_32();
		void _V1_inTRp3_1_32(int instance_id, int clause_id);
		bool isEnabledV1_inTRp3_1_32(int instance_id);
		void _V1_inTRp3_1_33();
		void _V1_inTRp3_1_33(int instance_id, int clause_id);
		bool isEnabledV1_inTRp3_1_33(int instance_id);
		
		
		#ifdef CLIENT_STUB_API
		//std::mutex& getMutex() { return m_mutex; }
		//std::condition_variable& getCondVar() { return m_condVar; }
		//bool isCBActive;
		#endif
	private:
		EventRepository *m_eventRepo;
		std::mutex m_mutex;
		std::condition_variable m_condVar;
		bool m_idle;
	
	public:	
		
		// Notifications: This should only be used by Server GUI
		// Extension Feature for Client State Machine
		void _V1_outTRp1_2_25();
		void _V1_outTRp1_2_25(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp1_2_25(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp1_3_26();
		void _V1_outTRp1_3_26(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp1_3_26(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp1_5_28();
		void _V1_outTRp1_5_28(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp1_5_28(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp1_6_29();
		void _V1_outTRp1_6_29(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp1_6_29(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp1_6_30();
		void _V1_outTRp1_6_30(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp1_6_30(std::vector<std::string>  list_of_rcvd_notifications);
};

/*********** Abstract State Class ***********/

class V1_State {
public:
	
	virtual ~V1_State(){};
	virtual list<string> getCurrentCommandStatusList() = 0;
	virtual list<string> getCurrentSignalStatusList() = 0;
	virtual list<string> getCurrentNotificationStatusList() = 0;
	virtual string getCurrentState() = 0;
	
	virtual bool isNotificationPossibleInState(V1_StateMachineController *smc) {
		UNREF_PARAM(smc);
		return false;
	}
	
	virtual bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc) {
		UNREF_PARAM(smc);
		return false;
	}
	
	virtual void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("INFO: No Available Commands and Signals in State!");
		std::cout<<"INFO: No Available Commands and Signals in State!"<<std::endl;
	}
	virtual void executeInternalTransitions(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("INFO: No Notifications to Raise!");
		std::cout<<"INFO: No Notifications to Raise!"<<std::endl;
	}
	// Commands
	
	// Signals
	
	virtual bool isEnabledV1_inTRp1_1_24(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp1_1_24(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_1_24!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_1_24!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_1_24!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp1_1_24(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_1_24!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_1_24!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_1_24!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp1_1_27(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp1_1_27(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_1_27!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_1_27!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_1_27!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp1_1_27(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_1_27!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_1_27!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_1_27!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp2_1_31(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp2_1_31(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp2_1_31!");
		std::cout<<"ERROR: Unexpected Signal inTRp2_1_31!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp2_1_31!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp2_1_31(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp2_1_31!");
		std::cout<<"ERROR: Unexpected Signal inTRp2_1_31!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp2_1_31!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp3_1_32(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp3_1_32(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_1_32!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_1_32!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_1_32!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp3_1_32(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_1_32!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_1_32!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_1_32!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp3_1_33(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp3_1_33(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_1_33!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_1_33!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_1_33!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp3_1_33(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_1_33!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_1_33!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_1_33!", UNEXPECTED_EVENT));
	}
	
	// Notifications
	virtual void V1_outTRp1_2_25(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_2_25!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_2_25!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_2_25!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp1_2_25(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_2_25 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_2_25 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_2_25 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp1_2_25(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_2_25 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_2_25 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_2_25 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp1_3_26(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_3_26!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_3_26!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_3_26!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp1_3_26(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_3_26 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_3_26 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_3_26 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp1_3_26(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_3_26 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_3_26 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_3_26 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp1_5_28(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_5_28!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_5_28!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_5_28!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp1_5_28(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_5_28 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_5_28 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_5_28 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp1_5_28(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_5_28 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_5_28 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_5_28 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp1_6_29(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_6_29!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_6_29!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_6_29!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp1_6_29(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_6_29 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_6_29 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_6_29 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp1_6_29(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_6_29 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_6_29 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_6_29 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp1_6_30(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_6_30!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_6_30!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_6_30!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp1_6_30(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_6_30 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_6_30 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_6_30 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp1_6_30(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_6_30 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_6_30 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_6_30 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
};

/********** State Machine Variables Container ************/

class smVarContainer {
public:
	smVarContainer(const V1_StateMachineController& smc)
	{
		// Initialize the Vars with values of State Machine Controller
	}

	bool operator==(const smVarContainer &var)
	{
		// iterate over all fields. For vector type just use ==
		return true;
	}
	
};

/*********** Concrete State Classes ***********/

class p1_1: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_1(){ name = "p1_1"; expected_ni_list = { }; }
	~p1_1(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p1_1
	void V1_inTRp1_1_27(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp1_1_27(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp1_1_27(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp1_1_27(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p1_4: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_4(){ name = "p1_4"; expected_ni_list = { {  "V1_outTRp1_3_26"  }  }; }
	~p1_4(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p1_4
	void V1_outTRp1_3_26(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp1_3_26(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp1_3_26(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp1_3_26

	//enum notifications { _V1_outTRp1_3_26, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p1_3: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_3(){ name = "p1_3"; expected_ni_list = { {  "V1_outTRp1_2_25"  }  }; }
	~p1_3(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p1_3
	void V1_outTRp1_2_25(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp1_2_25(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp1_2_25(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp1_2_25

	//enum notifications { _V1_outTRp1_2_25, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p1_5: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_5(){ name = "p1_5"; expected_ni_list = { {  "V1_outTRp1_5_28"  }  }; }
	~p1_5(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p1_5
	void V1_outTRp1_5_28(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp1_5_28(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp1_5_28(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp1_5_28

	//enum notifications { _V1_outTRp1_5_28, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p1_2: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_2(){ name = "p1_2"; expected_ni_list = { }; }
	~p1_2(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p1_2
	void V1_inTRp1_1_24(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp1_1_24(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp1_1_24(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp1_1_24(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p1_6: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_6(){ name = "p1_6"; expected_ni_list = { {  "V1_outTRp1_6_29"  } , {  "V1_outTRp1_6_30"  }  }; }
	~p1_6(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p1_6
	void V1_outTRp1_6_30(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp1_6_30(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp1_6_30(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp1_6_30
	// Possible Notification in State: p1_6
	void V1_outTRp1_6_29(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp1_6_29(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp1_6_29(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp1_6_29

	//enum notifications { _V1_outTRp1_6_29,  _V1_outTRp1_6_30, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p2_1: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p2_1(){ name = "p2_1"; expected_ni_list = { }; }
	~p2_1(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p2_1
	void V1_inTRp2_1_31(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp2_1_31(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp2_1_31(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp2_1_31(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_1: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_1(){ name = "p3_1"; expected_ni_list = { }; }
	~p3_1(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p3_1
	void V1_inTRp3_1_33(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp3_1_33(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp3_1_33(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp3_1_33(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_2: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_2(){ name = "p3_2"; expected_ni_list = { }; }
	~p3_2(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p3_2
	void V1_inTRp3_1_32(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp3_1_32(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp3_1_32(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp3_1_32(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

}

#endif /*V1_STATEMACHINECONTROLLER_H_ */
