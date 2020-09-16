#ifndef V2_STATEMACHINECONTROLLER_H_
#define V2_STATEMACHINECONTROLLER_H_

#include "common.h"
#include "EventRepository.h"
#include "NotificationCallbackThread.h"
#include "InputParametersContainer.h"

#ifdef SSCF_VERSION
#include "V2_SMCServerAdapter.h"
#endif

#ifdef QT_GUI
#include "mainwindow.h"
#endif

#include <mutex>
#include <condition_variable>

#ifdef SSCF_VERSION
namespace UNDEFINED { class V2Server; }
#endif

#ifdef QT_GUI
class MainWindow;
#endif

#ifdef CLIENT_STUB_API
#include "V2StubAdapter.h"

#ifdef SSCF_CLIENT_STUB_ADAPTER
//#include "V2.h"
#include "V2.h"
#include "SSCFClientConnection.h"
#endif

#endif

namespace StateMachineController {

/*********** State Machine Controller Class ***********/

class V2_StateMachineController {
	public:
		#ifdef SSCF_VERSION
		V2_StateMachineController(class EventRepository *er, 
						class UNDEFINED::V2Server *srv, int sim_mode);
		#endif
		
		#ifndef SSCF_VERSION
		
		#ifndef SSCF_CLIENT_STUB_ADAPTER
		V2_StateMachineController(class EventRepository *er, int sim_mode);
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		V2_StateMachineController(class EventRepository *er, int sim_mode, 
			SscfClientConnection<UNDEFINED::V2Proxy, UNDEFINED::V2>& _m_connection);
		#endif
		
		#endif
		
		#ifdef QT_GUI
		V2_StateMachineController(class EventRepository *er, 
						class MainWindow *mw, int sim_mode);
		#endif 
		
		virtual ~V2_StateMachineController();
		
		
		
		
		class V2_State *current;
		#ifdef SSCF_VERSION
		class UNDEFINED::V2Server *m_serverPtr;
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
		static bool outTRp1_2_12_clHandler(StateMachineController::V2_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_2_12!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_2_12!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp1_2_12!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V2_outTRp1_2_12(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp1_2_12 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp1_2_12: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V2_outTRp1_2_12(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp1_1_15_clHandler(StateMachineController::V2_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_1_15!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_1_15!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp1_1_15!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V2_outTRp1_1_15(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp1_1_15 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp1_1_15: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V2_outTRp1_1_15(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp1_1_16_clHandler(StateMachineController::V2_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_1_16!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_1_16!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp1_1_16!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V2_outTRp1_1_16(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp1_1_16 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp1_1_16: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V2_outTRp1_1_16(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp1_6_19_clHandler(StateMachineController::V2_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_6_19!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_6_19!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp1_6_19!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V2_outTRp1_6_19(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp1_6_19 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp1_6_19: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V2_outTRp1_6_19(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp1_8_21_clHandler(StateMachineController::V2_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_8_21!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_8_21!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp1_8_21!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V2_outTRp1_8_21(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp1_8_21 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp1_8_21: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V2_outTRp1_8_21(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp1_6_22_clHandler(StateMachineController::V2_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_6_22!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_6_22!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp1_6_22!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V2_outTRp1_6_22(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp1_6_22 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp1_6_22: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V2_outTRp1_6_22(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp1_9_23_clHandler(StateMachineController::V2_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_9_23!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_9_23!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp1_9_23!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V2_outTRp1_9_23(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp1_9_23 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp1_9_23: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V2_outTRp1_9_23(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		
		outTRp1_2_12_Handler m_outTRp1_2_12_Handler;
		void register_outTRp1_2_12_Handler(outTRp1_2_12_Handler _outTRp1_2_12_Handler) { this->m_outTRp1_2_12_Handler = _outTRp1_2_12_Handler; }
		outTRp1_1_15_Handler m_outTRp1_1_15_Handler;
		void register_outTRp1_1_15_Handler(outTRp1_1_15_Handler _outTRp1_1_15_Handler) { this->m_outTRp1_1_15_Handler = _outTRp1_1_15_Handler; }
		outTRp1_1_16_Handler m_outTRp1_1_16_Handler;
		void register_outTRp1_1_16_Handler(outTRp1_1_16_Handler _outTRp1_1_16_Handler) { this->m_outTRp1_1_16_Handler = _outTRp1_1_16_Handler; }
		outTRp1_6_19_Handler m_outTRp1_6_19_Handler;
		void register_outTRp1_6_19_Handler(outTRp1_6_19_Handler _outTRp1_6_19_Handler) { this->m_outTRp1_6_19_Handler = _outTRp1_6_19_Handler; }
		outTRp1_8_21_Handler m_outTRp1_8_21_Handler;
		void register_outTRp1_8_21_Handler(outTRp1_8_21_Handler _outTRp1_8_21_Handler) { this->m_outTRp1_8_21_Handler = _outTRp1_8_21_Handler; }
		outTRp1_6_22_Handler m_outTRp1_6_22_Handler;
		void register_outTRp1_6_22_Handler(outTRp1_6_22_Handler _outTRp1_6_22_Handler) { this->m_outTRp1_6_22_Handler = _outTRp1_6_22_Handler; }
		outTRp1_9_23_Handler m_outTRp1_9_23_Handler;
		void register_outTRp1_9_23_Handler(outTRp1_9_23_Handler _outTRp1_9_23_Handler) { this->m_outTRp1_9_23_Handler = _outTRp1_9_23_Handler; }
		
		string getCurrentState();
		void setCurrent(V2_State *s) { current = s; }
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
		void _V2_inTRp1_1_11();
		void _V2_inTRp1_1_11(int instance_id, int clause_id);
		bool isEnabledV2_inTRp1_1_11(int instance_id);
		void _V2_inTRp1_3_13();
		void _V2_inTRp1_3_13(int instance_id, int clause_id);
		bool isEnabledV2_inTRp1_3_13(int instance_id);
		void _V2_inTRp1_4_14();
		void _V2_inTRp1_4_14(int instance_id, int clause_id);
		bool isEnabledV2_inTRp1_4_14(int instance_id);
		void _V2_inTRp2_1_17();
		void _V2_inTRp2_1_17(int instance_id, int clause_id);
		bool isEnabledV2_inTRp2_1_17(int instance_id);
		void _V2_inTRp3_1_18();
		void _V2_inTRp3_1_18(int instance_id, int clause_id);
		bool isEnabledV2_inTRp3_1_18(int instance_id);
		
		
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
		void _V2_outTRp1_2_12();
		void _V2_outTRp1_2_12(int instance_id, int clause_id);
		std::vector<int> _match_V2_outTRp1_2_12(std::vector<std::string>  list_of_rcvd_notifications);
		void _V2_outTRp1_1_15();
		void _V2_outTRp1_1_15(int instance_id, int clause_id);
		std::vector<int> _match_V2_outTRp1_1_15(std::vector<std::string>  list_of_rcvd_notifications);
		void _V2_outTRp1_1_16();
		void _V2_outTRp1_1_16(int instance_id, int clause_id);
		std::vector<int> _match_V2_outTRp1_1_16(std::vector<std::string>  list_of_rcvd_notifications);
		void _V2_outTRp1_6_19();
		void _V2_outTRp1_6_19(int instance_id, int clause_id);
		std::vector<int> _match_V2_outTRp1_6_19(std::vector<std::string>  list_of_rcvd_notifications);
		void _V2_outTRp1_8_21();
		void _V2_outTRp1_8_21(int instance_id, int clause_id);
		std::vector<int> _match_V2_outTRp1_8_21(std::vector<std::string>  list_of_rcvd_notifications);
		void _V2_outTRp1_6_22();
		void _V2_outTRp1_6_22(int instance_id, int clause_id);
		std::vector<int> _match_V2_outTRp1_6_22(std::vector<std::string>  list_of_rcvd_notifications);
		void _V2_outTRp1_9_23();
		void _V2_outTRp1_9_23(int instance_id, int clause_id);
		std::vector<int> _match_V2_outTRp1_9_23(std::vector<std::string>  list_of_rcvd_notifications);
};

/*********** Abstract State Class ***********/

class V2_State {
public:
	
	virtual ~V2_State(){};
	virtual list<string> getCurrentCommandStatusList() = 0;
	virtual list<string> getCurrentSignalStatusList() = 0;
	virtual list<string> getCurrentNotificationStatusList() = 0;
	virtual string getCurrentState() = 0;
	
	virtual bool isNotificationPossibleInState(V2_StateMachineController *smc) {
		UNREF_PARAM(smc);
		return false;
	}
	
	virtual bool checkEnabledCommandAndSignalInState(V2_StateMachineController *smc) {
		UNREF_PARAM(smc);
		return false;
	}
	
	virtual void executeAvailableCommandsAndSignalsInState(V2_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("INFO: No Available Commands and Signals in State!");
		std::cout<<"INFO: No Available Commands and Signals in State!"<<std::endl;
	}
	virtual void executeInternalTransitions(V2_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("INFO: No Notifications to Raise!");
		std::cout<<"INFO: No Notifications to Raise!"<<std::endl;
	}
	// Commands
	
	// Signals
	
	virtual bool isEnabledV2_inTRp1_1_11(V2_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V2_inTRp1_1_11(V2_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_1_11!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_1_11!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_1_11!", UNEXPECTED_EVENT));
	}
	
	virtual void V2_inTRp1_1_11(V2_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_1_11!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_1_11!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_1_11!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV2_inTRp1_3_13(V2_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V2_inTRp1_3_13(V2_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_3_13!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_3_13!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_3_13!", UNEXPECTED_EVENT));
	}
	
	virtual void V2_inTRp1_3_13(V2_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_3_13!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_3_13!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_3_13!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV2_inTRp1_4_14(V2_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V2_inTRp1_4_14(V2_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_4_14!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_4_14!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_4_14!", UNEXPECTED_EVENT));
	}
	
	virtual void V2_inTRp1_4_14(V2_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_4_14!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_4_14!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_4_14!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV2_inTRp2_1_17(V2_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V2_inTRp2_1_17(V2_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp2_1_17!");
		std::cout<<"ERROR: Unexpected Signal inTRp2_1_17!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp2_1_17!", UNEXPECTED_EVENT));
	}
	
	virtual void V2_inTRp2_1_17(V2_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp2_1_17!");
		std::cout<<"ERROR: Unexpected Signal inTRp2_1_17!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp2_1_17!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV2_inTRp3_1_18(V2_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V2_inTRp3_1_18(V2_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_1_18!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_1_18!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_1_18!", UNEXPECTED_EVENT));
	}
	
	virtual void V2_inTRp3_1_18(V2_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_1_18!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_1_18!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_1_18!", UNEXPECTED_EVENT));
	}
	
	// Notifications
	virtual void V2_outTRp1_2_12(V2_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_2_12!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_2_12!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_2_12!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V2_outTRp1_2_12(V2_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_2_12 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_2_12 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_2_12 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V2_outTRp1_2_12(V2_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_2_12 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_2_12 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_2_12 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V2_outTRp1_1_15(V2_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_1_15!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_1_15!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_1_15!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V2_outTRp1_1_15(V2_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_1_15 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_1_15 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_1_15 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V2_outTRp1_1_15(V2_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_1_15 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_1_15 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_1_15 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V2_outTRp1_1_16(V2_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_1_16!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_1_16!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_1_16!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V2_outTRp1_1_16(V2_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_1_16 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_1_16 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_1_16 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V2_outTRp1_1_16(V2_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_1_16 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_1_16 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_1_16 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V2_outTRp1_6_19(V2_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_6_19!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_6_19!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_6_19!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V2_outTRp1_6_19(V2_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_6_19 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_6_19 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_6_19 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V2_outTRp1_6_19(V2_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_6_19 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_6_19 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_6_19 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V2_outTRp1_8_21(V2_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_8_21!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_8_21!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_8_21!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V2_outTRp1_8_21(V2_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_8_21 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_8_21 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_8_21 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V2_outTRp1_8_21(V2_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_8_21 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_8_21 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_8_21 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V2_outTRp1_6_22(V2_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_6_22!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_6_22!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_6_22!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V2_outTRp1_6_22(V2_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_6_22 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_6_22 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_6_22 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V2_outTRp1_6_22(V2_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_6_22 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_6_22 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_6_22 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V2_outTRp1_9_23(V2_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_9_23!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_9_23!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_9_23!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V2_outTRp1_9_23(V2_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_9_23 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_9_23 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_9_23 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V2_outTRp1_9_23(V2_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_9_23 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_9_23 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_9_23 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
};

/********** State Machine Variables Container ************/

class smVarContainer {
public:
	smVarContainer(const V2_StateMachineController& smc)
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

class p1_1: public V2_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_1(){ name = "p1_1"; expected_ni_list = { {  "V2_outTRp1_1_15"  } , {  "V2_outTRp1_1_16"  }  }; }
	~p1_1(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V2_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V2_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V2_StateMachineController *smc);

	// Possible Notification in State: p1_1
	void V2_outTRp1_1_16(V2_StateMachineController *smc);
	std::vector<int> match_V2_outTRp1_1_16(V2_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V2_outTRp1_1_16(V2_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V2_outTRp1_1_16
	// Possible Notification in State: p1_1
	void V2_outTRp1_1_15(V2_StateMachineController *smc);
	std::vector<int> match_V2_outTRp1_1_15(V2_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V2_outTRp1_1_15(V2_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V2_outTRp1_1_15

	//enum notifications { _V2_outTRp1_1_15,  _V2_outTRp1_1_16, END };

	// For Server Stub
	void executeInternalTransitions(V2_StateMachineController *smc);	
	bool isNotificationPossibleInState(V2_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V2_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V2_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V2_StateMachineController *smc);
};

class p1_4: public V2_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_4(){ name = "p1_4"; expected_ni_list = { {  "V2_outTRp1_2_12"  }  }; }
	~p1_4(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V2_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V2_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V2_StateMachineController *smc);

	// Possible Notification in State: p1_4
	void V2_outTRp1_2_12(V2_StateMachineController *smc);
	std::vector<int> match_V2_outTRp1_2_12(V2_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V2_outTRp1_2_12(V2_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V2_outTRp1_2_12

	//enum notifications { _V2_outTRp1_2_12, END };

	// For Server Stub
	void executeInternalTransitions(V2_StateMachineController *smc);	
	bool isNotificationPossibleInState(V2_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V2_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V2_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V2_StateMachineController *smc);
};

class p1_6: public V2_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_6(){ name = "p1_6"; expected_ni_list = { {  "V2_outTRp1_6_22"  }  }; }
	~p1_6(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V2_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V2_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V2_StateMachineController *smc);

	// Possible Notification in State: p1_6
	void V2_outTRp1_6_22(V2_StateMachineController *smc);
	std::vector<int> match_V2_outTRp1_6_22(V2_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V2_outTRp1_6_22(V2_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V2_outTRp1_6_22

	//enum notifications { _V2_outTRp1_6_22, END };

	// For Server Stub
	void executeInternalTransitions(V2_StateMachineController *smc);	
	bool isNotificationPossibleInState(V2_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V2_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V2_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V2_StateMachineController *smc);
};

class p1_5: public V2_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_5(){ name = "p1_5"; expected_ni_list = { }; }
	~p1_5(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V2_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V2_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V2_StateMachineController *smc);

	// Enabled Signal in State: p1_5
	void V2_inTRp1_3_13(V2_StateMachineController *smc);
	bool isEnabledV2_inTRp1_3_13(V2_StateMachineController *smc, int instance_choice);
	void V2_inTRp1_3_13(V2_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V2_inTRp1_3_13(V2_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V2_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V2_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V2_StateMachineController *smc);
};

class p1_8: public V2_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_8(){ name = "p1_8"; expected_ni_list = { {  "V2_outTRp1_6_19"  }  }; }
	~p1_8(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V2_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V2_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V2_StateMachineController *smc);

	// Possible Notification in State: p1_8
	void V2_outTRp1_6_19(V2_StateMachineController *smc);
	std::vector<int> match_V2_outTRp1_6_19(V2_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V2_outTRp1_6_19(V2_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V2_outTRp1_6_19

	//enum notifications { _V2_outTRp1_6_19, END };

	// For Server Stub
	void executeInternalTransitions(V2_StateMachineController *smc);	
	bool isNotificationPossibleInState(V2_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V2_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V2_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V2_StateMachineController *smc);
};

class p1_2: public V2_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_2(){ name = "p1_2"; expected_ni_list = { }; }
	~p1_2(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V2_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V2_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V2_StateMachineController *smc);

	// Enabled Signal in State: p1_2
	void V2_inTRp1_1_11(V2_StateMachineController *smc);
	bool isEnabledV2_inTRp1_1_11(V2_StateMachineController *smc, int instance_choice);
	void V2_inTRp1_1_11(V2_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V2_inTRp1_1_11(V2_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V2_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V2_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V2_StateMachineController *smc);
};

class p2_1: public V2_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p2_1(){ name = "p2_1"; expected_ni_list = { }; }
	~p2_1(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V2_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V2_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V2_StateMachineController *smc);

	// Enabled Signal in State: p2_1
	void V2_inTRp2_1_17(V2_StateMachineController *smc);
	bool isEnabledV2_inTRp2_1_17(V2_StateMachineController *smc, int instance_choice);
	void V2_inTRp2_1_17(V2_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V2_inTRp2_1_17(V2_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V2_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V2_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V2_StateMachineController *smc);
};

class p3_1: public V2_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_1(){ name = "p3_1"; expected_ni_list = { }; }
	~p3_1(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V2_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V2_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V2_StateMachineController *smc);

	// Enabled Signal in State: p3_1
	void V2_inTRp3_1_18(V2_StateMachineController *smc);
	bool isEnabledV2_inTRp3_1_18(V2_StateMachineController *smc, int instance_choice);
	void V2_inTRp3_1_18(V2_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V2_inTRp3_1_18(V2_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V2_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V2_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V2_StateMachineController *smc);
};

class p1_11: public V2_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_11(){ name = "p1_11"; expected_ni_list = { }; }
	~p1_11(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V2_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V2_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V2_StateMachineController *smc);


	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V2_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V2_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V2_StateMachineController *smc);
};

class p1_7: public V2_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_7(){ name = "p1_7"; expected_ni_list = { }; }
	~p1_7(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V2_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V2_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V2_StateMachineController *smc);

	// Enabled Signal in State: p1_7
	void V2_inTRp1_4_14(V2_StateMachineController *smc);
	bool isEnabledV2_inTRp1_4_14(V2_StateMachineController *smc, int instance_choice);
	void V2_inTRp1_4_14(V2_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V2_inTRp1_4_14(V2_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V2_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V2_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V2_StateMachineController *smc);
};

class p1_10: public V2_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_10(){ name = "p1_10"; expected_ni_list = { {  "V2_outTRp1_8_21"  }  }; }
	~p1_10(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V2_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V2_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V2_StateMachineController *smc);

	// Possible Notification in State: p1_10
	void V2_outTRp1_8_21(V2_StateMachineController *smc);
	std::vector<int> match_V2_outTRp1_8_21(V2_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V2_outTRp1_8_21(V2_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V2_outTRp1_8_21

	//enum notifications { _V2_outTRp1_8_21, END };

	// For Server Stub
	void executeInternalTransitions(V2_StateMachineController *smc);	
	bool isNotificationPossibleInState(V2_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V2_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V2_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V2_StateMachineController *smc);
};

}

#endif /*V2_STATEMACHINECONTROLLER_H_ */
