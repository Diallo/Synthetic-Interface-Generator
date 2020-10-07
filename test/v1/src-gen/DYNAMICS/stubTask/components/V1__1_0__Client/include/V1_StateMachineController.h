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
		static bool outTRp1_1_3398718_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_1_3398718!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_1_3398718!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp1_1_3398718!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp1_1_3398718(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp1_1_3398718 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp1_1_3398718: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp1_1_3398718(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp1_1_3398719_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_1_3398719!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_1_3398719!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp1_1_3398719!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp1_1_3398719(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp1_1_3398719 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp1_1_3398719: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp1_1_3398719(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp1_1_3398720_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_1_3398720!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_1_3398720!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp1_1_3398720!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp1_1_3398720(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp1_1_3398720 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp1_1_3398720: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp1_1_3398720(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp3_1_3398724_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_1_3398724!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_1_3398724!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp3_1_3398724!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp3_1_3398724(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp3_1_3398724 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp3_1_3398724: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp3_1_3398724(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp1_4_3398725_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_4_3398725!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_4_3398725!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp1_4_3398725!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp1_4_3398725(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp1_4_3398725 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp1_4_3398725: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp1_4_3398725(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp3_3_3398727_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_3_3398727!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_3_3398727!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp3_3_3398727!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp3_3_3398727(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp3_3_3398727 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp3_3_3398727: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp3_3_3398727(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp3_5_3398730_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_5_3398730!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_5_3398730!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp3_5_3398730!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp3_5_3398730(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp3_5_3398730 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp3_5_3398730: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp3_5_3398730(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp3_4_3398731_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_4_3398731!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_4_3398731!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp3_4_3398731!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp3_4_3398731(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp3_4_3398731 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp3_4_3398731: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp3_4_3398731(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp3_5_3398733_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_5_3398733!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_5_3398733!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp3_5_3398733!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp3_5_3398733(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp3_5_3398733 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp3_5_3398733: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp3_5_3398733(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp3_2_3398735_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_2_3398735!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_2_3398735!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp3_2_3398735!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp3_2_3398735(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp3_2_3398735 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp3_2_3398735: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp3_2_3398735(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp3_3_3398736_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_3_3398736!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_3_3398736!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp3_3_3398736!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp3_3_3398736(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp3_3_3398736 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp3_3_3398736: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp3_3_3398736(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp1_1_3398738_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_1_3398738!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_1_3398738!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp1_1_3398738!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp1_1_3398738(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp1_1_3398738 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp1_1_3398738: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp1_1_3398738(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp2_3_3398740_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp2_3_3398740!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp2_3_3398740!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp2_3_3398740!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp2_3_3398740(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp2_3_3398740 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp2_3_3398740: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp2_3_3398740(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp4_1_3398744_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp4_1_3398744!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp4_1_3398744!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp4_1_3398744!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp4_1_3398744(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp4_1_3398744 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp4_1_3398744: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp4_1_3398744(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp5_1_3398745_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp5_1_3398745!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp5_1_3398745!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp5_1_3398745!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp5_1_3398745(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp5_1_3398745 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp5_1_3398745: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp5_1_3398745(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp3_10_3398748_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_10_3398748!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_10_3398748!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp3_10_3398748!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp3_10_3398748(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp3_10_3398748 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp3_10_3398748: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp3_10_3398748(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp1_6_3398756_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_6_3398756!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_6_3398756!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp1_6_3398756!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp1_6_3398756(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp1_6_3398756 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp1_6_3398756: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp1_6_3398756(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp1_4_3398759_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_4_3398759!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_4_3398759!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp1_4_3398759!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp1_4_3398759(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp1_4_3398759 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp1_4_3398759: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp1_4_3398759(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp3_6_3398761_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_6_3398761!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_6_3398761!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp3_6_3398761!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp3_6_3398761(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp3_6_3398761 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp3_6_3398761: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp3_6_3398761(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp2_6_3398762_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp2_6_3398762!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp2_6_3398762!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp2_6_3398762!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp2_6_3398762(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp2_6_3398762 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp2_6_3398762: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp2_6_3398762(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp3_4_3398763_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_4_3398763!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_4_3398763!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp3_4_3398763!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp3_4_3398763(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp3_4_3398763 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp3_4_3398763: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp3_4_3398763(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp3_11_3398764_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_11_3398764!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_11_3398764!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp3_11_3398764!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp3_11_3398764(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp3_11_3398764 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp3_11_3398764: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp3_11_3398764(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp3_8_3398766_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_8_3398766!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_8_3398766!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp3_8_3398766!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp3_8_3398766(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp3_8_3398766 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp3_8_3398766: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp3_8_3398766(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp1_10_3398769_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_10_3398769!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_10_3398769!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp1_10_3398769!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp1_10_3398769(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp1_10_3398769 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp1_10_3398769: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp1_10_3398769(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp3_12_3398771_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_12_3398771!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_12_3398771!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp3_12_3398771!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp3_12_3398771(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp3_12_3398771 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp3_12_3398771: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp3_12_3398771(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp6_1_3398773_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp6_1_3398773!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp6_1_3398773!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp6_1_3398773!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp6_1_3398773(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp6_1_3398773 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp6_1_3398773: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp6_1_3398773(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp7_1_3398775_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp7_1_3398775!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp7_1_3398775!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp7_1_3398775!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp7_1_3398775(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp7_1_3398775 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp7_1_3398775: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp7_1_3398775(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp5_2_3398777_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp5_2_3398777!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp5_2_3398777!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp5_2_3398777!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp5_2_3398777(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp5_2_3398777 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp5_2_3398777: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp5_2_3398777(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp1_6_3398778_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_6_3398778!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_6_3398778!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp1_6_3398778!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp1_6_3398778(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp1_6_3398778 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp1_6_3398778: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp1_6_3398778(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp3_7_3398779_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_7_3398779!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_7_3398779!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp3_7_3398779!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp3_7_3398779(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp3_7_3398779 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp3_7_3398779: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp3_7_3398779(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp1_14_3398782_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_14_3398782!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_14_3398782!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp1_14_3398782!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp1_14_3398782(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp1_14_3398782 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp1_14_3398782: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp1_14_3398782(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp1_3_3398784_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_3_3398784!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_3_3398784!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp1_3_3398784!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp1_3_3398784(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp1_3_3398784 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp1_3_3398784: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp1_3_3398784(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp8_1_3398788_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp8_1_3398788!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp8_1_3398788!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp8_1_3398788!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp8_1_3398788(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp8_1_3398788 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp8_1_3398788: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp8_1_3398788(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp9_1_3398789_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp9_1_3398789!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp9_1_3398789!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp9_1_3398789!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp9_1_3398789(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp9_1_3398789 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp9_1_3398789: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp9_1_3398789(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp1_17_3398791_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_17_3398791!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_17_3398791!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp1_17_3398791!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp1_17_3398791(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp1_17_3398791 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp1_17_3398791: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp1_17_3398791(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp1_7_3398793_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_7_3398793!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_7_3398793!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp1_7_3398793!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp1_7_3398793(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp1_7_3398793 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp1_7_3398793: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp1_7_3398793(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp1_7_3398794_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_7_3398794!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_7_3398794!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp1_7_3398794!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp1_7_3398794(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp1_7_3398794 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp1_7_3398794: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp1_7_3398794(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp1_4_3398797_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_4_3398797!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_4_3398797!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp1_4_3398797!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp1_4_3398797(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp1_4_3398797 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp1_4_3398797: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp1_4_3398797(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp3_29_3398799_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_29_3398799!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_29_3398799!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp3_29_3398799!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp3_29_3398799(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp3_29_3398799 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp3_29_3398799: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp3_29_3398799(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp9_2_3398801_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp9_2_3398801!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp9_2_3398801!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp9_2_3398801!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp9_2_3398801(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp9_2_3398801 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp9_2_3398801: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp9_2_3398801(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp3_13_3398802_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_13_3398802!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_13_3398802!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp3_13_3398802!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp3_13_3398802(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp3_13_3398802 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp3_13_3398802: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp3_13_3398802(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp1_7_3398804_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_7_3398804!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_7_3398804!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp1_7_3398804!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp1_7_3398804(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp1_7_3398804 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp1_7_3398804: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp1_7_3398804(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp3_32_3398806_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_32_3398806!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_32_3398806!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp3_32_3398806!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp3_32_3398806(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp3_32_3398806 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp3_32_3398806: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp3_32_3398806(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp1_20_3398809_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_20_3398809!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_20_3398809!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp1_20_3398809!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp1_20_3398809(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp1_20_3398809 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp1_20_3398809: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp1_20_3398809(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp9_3_3398810_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp9_3_3398810!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp9_3_3398810!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp9_3_3398810!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp9_3_3398810(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp9_3_3398810 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp9_3_3398810: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp9_3_3398810(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp1_1_3398811_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_1_3398811!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_1_3398811!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp1_1_3398811!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp1_1_3398811(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp1_1_3398811 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp1_1_3398811: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp1_1_3398811(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp1_9_3398815_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_9_3398815!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_9_3398815!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp1_9_3398815!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp1_9_3398815(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp1_9_3398815 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp1_9_3398815: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp1_9_3398815(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp5_4_3398816_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp5_4_3398816!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp5_4_3398816!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp5_4_3398816!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp5_4_3398816(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp5_4_3398816 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp5_4_3398816: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp5_4_3398816(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp5_4_3398817_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp5_4_3398817!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp5_4_3398817!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp5_4_3398817!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp5_4_3398817(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp5_4_3398817 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp5_4_3398817: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp5_4_3398817(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp1_25_3398820_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_25_3398820!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_25_3398820!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp1_25_3398820!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp1_25_3398820(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp1_25_3398820 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp1_25_3398820: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp1_25_3398820(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp2_10_3398821_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp2_10_3398821!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp2_10_3398821!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp2_10_3398821!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp2_10_3398821(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp2_10_3398821 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp2_10_3398821: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp2_10_3398821(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp1_26_3398822_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_26_3398822!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_26_3398822!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp1_26_3398822!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp1_26_3398822(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp1_26_3398822 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp1_26_3398822: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp1_26_3398822(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp11_1_3398824_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp11_1_3398824!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp11_1_3398824!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp11_1_3398824!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp11_1_3398824(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp11_1_3398824 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp11_1_3398824: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp11_1_3398824(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp9_1_3398829_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp9_1_3398829!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp9_1_3398829!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp9_1_3398829!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp9_1_3398829(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp9_1_3398829 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp9_1_3398829: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp9_1_3398829(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp3_2_3398830_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_2_3398830!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_2_3398830!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp3_2_3398830!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp3_2_3398830(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp3_2_3398830 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp3_2_3398830: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp3_2_3398830(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp9_5_3398831_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp9_5_3398831!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp9_5_3398831!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp9_5_3398831!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp9_5_3398831(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp9_5_3398831 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp9_5_3398831: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp9_5_3398831(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp1_21_3398832_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_21_3398832!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_21_3398832!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp1_21_3398832!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp1_21_3398832(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp1_21_3398832 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp1_21_3398832: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp1_21_3398832(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp3_29_3398835_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_29_3398835!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_29_3398835!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp3_29_3398835!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp3_29_3398835(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp3_29_3398835 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp3_29_3398835: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp3_29_3398835(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp3_21_3398836_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_21_3398836!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_21_3398836!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp3_21_3398836!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp3_21_3398836(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp3_21_3398836 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp3_21_3398836: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp3_21_3398836(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp1_20_3398837_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_20_3398837!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_20_3398837!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp1_20_3398837!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp1_20_3398837(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp1_20_3398837 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp1_20_3398837: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp1_20_3398837(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp4_2_3398839_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp4_2_3398839!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp4_2_3398839!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp4_2_3398839!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp4_2_3398839(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp4_2_3398839 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp4_2_3398839: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp4_2_3398839(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp3_8_3398840_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_8_3398840!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_8_3398840!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp3_8_3398840!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp3_8_3398840(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp3_8_3398840 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp3_8_3398840: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp3_8_3398840(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp3_4_3398843_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_4_3398843!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_4_3398843!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp3_4_3398843!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp3_4_3398843(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp3_4_3398843 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp3_4_3398843: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp3_4_3398843(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp1_5_3398844_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_5_3398844!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_5_3398844!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp1_5_3398844!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp1_5_3398844(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp1_5_3398844 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp1_5_3398844: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp1_5_3398844(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp3_44_3398845_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_44_3398845!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_44_3398845!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp3_44_3398845!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp3_44_3398845(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp3_44_3398845 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp3_44_3398845: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp3_44_3398845(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp1_12_3398846_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_12_3398846!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_12_3398846!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp1_12_3398846!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp1_12_3398846(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp1_12_3398846 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp1_12_3398846: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp1_12_3398846(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp2_9_3398848_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp2_9_3398848!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp2_9_3398848!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp2_9_3398848!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp2_9_3398848(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp2_9_3398848 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp2_9_3398848: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp2_9_3398848(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp2_7_3398851_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp2_7_3398851!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp2_7_3398851!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp2_7_3398851!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp2_7_3398851(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp2_7_3398851 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp2_7_3398851: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp2_7_3398851(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp3_13_3398852_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_13_3398852!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_13_3398852!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp3_13_3398852!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp3_13_3398852(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp3_13_3398852 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp3_13_3398852: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp3_13_3398852(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp3_40_3398853_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_40_3398853!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_40_3398853!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp3_40_3398853!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp3_40_3398853(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp3_40_3398853 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp3_40_3398853: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp3_40_3398853(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp3_40_3398855_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_40_3398855!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_40_3398855!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp3_40_3398855!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp3_40_3398855(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp3_40_3398855 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp3_40_3398855: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp3_40_3398855(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp3_6_3398857_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_6_3398857!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_6_3398857!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp3_6_3398857!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp3_6_3398857(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp3_6_3398857 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp3_6_3398857: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp3_6_3398857(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp17_1_3398863_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp17_1_3398863!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp17_1_3398863!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp17_1_3398863!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp17_1_3398863(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp17_1_3398863 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp17_1_3398863: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp17_1_3398863(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp1_3_3398866_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_3_3398866!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_3_3398866!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp1_3_3398866!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp1_3_3398866(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp1_3_3398866 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp1_3_3398866: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp1_3_3398866(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp3_10_3398867_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_10_3398867!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp3_10_3398867!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp3_10_3398867!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp3_10_3398867(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp3_10_3398867 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp3_10_3398867: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp3_10_3398867(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp4_3_3398869_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp4_3_3398869!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp4_3_3398869!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp4_3_3398869!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp4_3_3398869(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp4_3_3398869 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp4_3_3398869: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp4_3_3398869(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp9_1_3398870_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp9_1_3398870!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp9_1_3398870!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp9_1_3398870!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp9_1_3398870(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp9_1_3398870 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp9_1_3398870: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp9_1_3398870(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp4_2_3398873_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp4_2_3398873!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp4_2_3398873!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp4_2_3398873!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp4_2_3398873(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp4_2_3398873 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp4_2_3398873: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp4_2_3398873(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp2_1_3398874_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp2_1_3398874!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp2_1_3398874!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp2_1_3398874!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp2_1_3398874(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp2_1_3398874 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp2_1_3398874: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp2_1_3398874(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp19_1_3398877_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp19_1_3398877!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp19_1_3398877!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp19_1_3398877!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp19_1_3398877(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp19_1_3398877 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp19_1_3398877: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp19_1_3398877(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		static bool outTRp1_10_3398879_clHandler(StateMachineController::V1_StateMachineController& smc, std::vector<std::string> list_of_rcvd_notifications) 
		{
			smc.isNotificationInProcess = true;
			std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_10_3398879!!" << std::endl;
		
			//std::cout << std::endl <<"[INFO] State Machine Controller triggered with Notification: outTRp1_10_3398879!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			//std::reverse(list_of_rcvd_notifications.begin(), list_of_rcvd_notifications.end());
			//std::cout << std::endl << "[INFO] State Machine Controller triggered with Notification:outTRp1_10_3398879!!" << list_of_rcvd_notifications.at(0) << ": " << list_of_rcvd_notifications.at(1) << std::endl;
			std::vector<int> matched_instance_clause_id = smc._match_V1_outTRp1_10_3398879(list_of_rcvd_notifications);
			if (matched_instance_clause_id.size() > 1)
			{
				if (matched_instance_clause_id.at(0) == UNDEFINED_CHOICE || matched_instance_clause_id.at(1) == UNDEFINED_CHOICE) {
					std::cout << "No Match For Notification: outTRp1_10_3398879 Yet!" << std::endl;
					smc.isNotificationExpected = true;
				}
				else
				{
					std::cout << "Matched Notification: outTRp1_10_3398879: with InstanceID: " << matched_instance_clause_id.at(0) << " and ClauseID: " << matched_instance_clause_id.at(1) << std::endl;
					smc._V1_outTRp1_10_3398879(matched_instance_clause_id.at(0), matched_instance_clause_id.at(1));
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
		
		outTRp1_1_3398718_Handler m_outTRp1_1_3398718_Handler;
		void register_outTRp1_1_3398718_Handler(outTRp1_1_3398718_Handler _outTRp1_1_3398718_Handler) { this->m_outTRp1_1_3398718_Handler = _outTRp1_1_3398718_Handler; }
		outTRp1_1_3398719_Handler m_outTRp1_1_3398719_Handler;
		void register_outTRp1_1_3398719_Handler(outTRp1_1_3398719_Handler _outTRp1_1_3398719_Handler) { this->m_outTRp1_1_3398719_Handler = _outTRp1_1_3398719_Handler; }
		outTRp1_1_3398720_Handler m_outTRp1_1_3398720_Handler;
		void register_outTRp1_1_3398720_Handler(outTRp1_1_3398720_Handler _outTRp1_1_3398720_Handler) { this->m_outTRp1_1_3398720_Handler = _outTRp1_1_3398720_Handler; }
		outTRp3_1_3398724_Handler m_outTRp3_1_3398724_Handler;
		void register_outTRp3_1_3398724_Handler(outTRp3_1_3398724_Handler _outTRp3_1_3398724_Handler) { this->m_outTRp3_1_3398724_Handler = _outTRp3_1_3398724_Handler; }
		outTRp1_4_3398725_Handler m_outTRp1_4_3398725_Handler;
		void register_outTRp1_4_3398725_Handler(outTRp1_4_3398725_Handler _outTRp1_4_3398725_Handler) { this->m_outTRp1_4_3398725_Handler = _outTRp1_4_3398725_Handler; }
		outTRp3_3_3398727_Handler m_outTRp3_3_3398727_Handler;
		void register_outTRp3_3_3398727_Handler(outTRp3_3_3398727_Handler _outTRp3_3_3398727_Handler) { this->m_outTRp3_3_3398727_Handler = _outTRp3_3_3398727_Handler; }
		outTRp3_5_3398730_Handler m_outTRp3_5_3398730_Handler;
		void register_outTRp3_5_3398730_Handler(outTRp3_5_3398730_Handler _outTRp3_5_3398730_Handler) { this->m_outTRp3_5_3398730_Handler = _outTRp3_5_3398730_Handler; }
		outTRp3_4_3398731_Handler m_outTRp3_4_3398731_Handler;
		void register_outTRp3_4_3398731_Handler(outTRp3_4_3398731_Handler _outTRp3_4_3398731_Handler) { this->m_outTRp3_4_3398731_Handler = _outTRp3_4_3398731_Handler; }
		outTRp3_5_3398733_Handler m_outTRp3_5_3398733_Handler;
		void register_outTRp3_5_3398733_Handler(outTRp3_5_3398733_Handler _outTRp3_5_3398733_Handler) { this->m_outTRp3_5_3398733_Handler = _outTRp3_5_3398733_Handler; }
		outTRp3_2_3398735_Handler m_outTRp3_2_3398735_Handler;
		void register_outTRp3_2_3398735_Handler(outTRp3_2_3398735_Handler _outTRp3_2_3398735_Handler) { this->m_outTRp3_2_3398735_Handler = _outTRp3_2_3398735_Handler; }
		outTRp3_3_3398736_Handler m_outTRp3_3_3398736_Handler;
		void register_outTRp3_3_3398736_Handler(outTRp3_3_3398736_Handler _outTRp3_3_3398736_Handler) { this->m_outTRp3_3_3398736_Handler = _outTRp3_3_3398736_Handler; }
		outTRp1_1_3398738_Handler m_outTRp1_1_3398738_Handler;
		void register_outTRp1_1_3398738_Handler(outTRp1_1_3398738_Handler _outTRp1_1_3398738_Handler) { this->m_outTRp1_1_3398738_Handler = _outTRp1_1_3398738_Handler; }
		outTRp2_3_3398740_Handler m_outTRp2_3_3398740_Handler;
		void register_outTRp2_3_3398740_Handler(outTRp2_3_3398740_Handler _outTRp2_3_3398740_Handler) { this->m_outTRp2_3_3398740_Handler = _outTRp2_3_3398740_Handler; }
		outTRp4_1_3398744_Handler m_outTRp4_1_3398744_Handler;
		void register_outTRp4_1_3398744_Handler(outTRp4_1_3398744_Handler _outTRp4_1_3398744_Handler) { this->m_outTRp4_1_3398744_Handler = _outTRp4_1_3398744_Handler; }
		outTRp5_1_3398745_Handler m_outTRp5_1_3398745_Handler;
		void register_outTRp5_1_3398745_Handler(outTRp5_1_3398745_Handler _outTRp5_1_3398745_Handler) { this->m_outTRp5_1_3398745_Handler = _outTRp5_1_3398745_Handler; }
		outTRp3_10_3398748_Handler m_outTRp3_10_3398748_Handler;
		void register_outTRp3_10_3398748_Handler(outTRp3_10_3398748_Handler _outTRp3_10_3398748_Handler) { this->m_outTRp3_10_3398748_Handler = _outTRp3_10_3398748_Handler; }
		outTRp1_6_3398756_Handler m_outTRp1_6_3398756_Handler;
		void register_outTRp1_6_3398756_Handler(outTRp1_6_3398756_Handler _outTRp1_6_3398756_Handler) { this->m_outTRp1_6_3398756_Handler = _outTRp1_6_3398756_Handler; }
		outTRp1_4_3398759_Handler m_outTRp1_4_3398759_Handler;
		void register_outTRp1_4_3398759_Handler(outTRp1_4_3398759_Handler _outTRp1_4_3398759_Handler) { this->m_outTRp1_4_3398759_Handler = _outTRp1_4_3398759_Handler; }
		outTRp3_6_3398761_Handler m_outTRp3_6_3398761_Handler;
		void register_outTRp3_6_3398761_Handler(outTRp3_6_3398761_Handler _outTRp3_6_3398761_Handler) { this->m_outTRp3_6_3398761_Handler = _outTRp3_6_3398761_Handler; }
		outTRp2_6_3398762_Handler m_outTRp2_6_3398762_Handler;
		void register_outTRp2_6_3398762_Handler(outTRp2_6_3398762_Handler _outTRp2_6_3398762_Handler) { this->m_outTRp2_6_3398762_Handler = _outTRp2_6_3398762_Handler; }
		outTRp3_4_3398763_Handler m_outTRp3_4_3398763_Handler;
		void register_outTRp3_4_3398763_Handler(outTRp3_4_3398763_Handler _outTRp3_4_3398763_Handler) { this->m_outTRp3_4_3398763_Handler = _outTRp3_4_3398763_Handler; }
		outTRp3_11_3398764_Handler m_outTRp3_11_3398764_Handler;
		void register_outTRp3_11_3398764_Handler(outTRp3_11_3398764_Handler _outTRp3_11_3398764_Handler) { this->m_outTRp3_11_3398764_Handler = _outTRp3_11_3398764_Handler; }
		outTRp3_8_3398766_Handler m_outTRp3_8_3398766_Handler;
		void register_outTRp3_8_3398766_Handler(outTRp3_8_3398766_Handler _outTRp3_8_3398766_Handler) { this->m_outTRp3_8_3398766_Handler = _outTRp3_8_3398766_Handler; }
		outTRp1_10_3398769_Handler m_outTRp1_10_3398769_Handler;
		void register_outTRp1_10_3398769_Handler(outTRp1_10_3398769_Handler _outTRp1_10_3398769_Handler) { this->m_outTRp1_10_3398769_Handler = _outTRp1_10_3398769_Handler; }
		outTRp3_12_3398771_Handler m_outTRp3_12_3398771_Handler;
		void register_outTRp3_12_3398771_Handler(outTRp3_12_3398771_Handler _outTRp3_12_3398771_Handler) { this->m_outTRp3_12_3398771_Handler = _outTRp3_12_3398771_Handler; }
		outTRp6_1_3398773_Handler m_outTRp6_1_3398773_Handler;
		void register_outTRp6_1_3398773_Handler(outTRp6_1_3398773_Handler _outTRp6_1_3398773_Handler) { this->m_outTRp6_1_3398773_Handler = _outTRp6_1_3398773_Handler; }
		outTRp7_1_3398775_Handler m_outTRp7_1_3398775_Handler;
		void register_outTRp7_1_3398775_Handler(outTRp7_1_3398775_Handler _outTRp7_1_3398775_Handler) { this->m_outTRp7_1_3398775_Handler = _outTRp7_1_3398775_Handler; }
		outTRp5_2_3398777_Handler m_outTRp5_2_3398777_Handler;
		void register_outTRp5_2_3398777_Handler(outTRp5_2_3398777_Handler _outTRp5_2_3398777_Handler) { this->m_outTRp5_2_3398777_Handler = _outTRp5_2_3398777_Handler; }
		outTRp1_6_3398778_Handler m_outTRp1_6_3398778_Handler;
		void register_outTRp1_6_3398778_Handler(outTRp1_6_3398778_Handler _outTRp1_6_3398778_Handler) { this->m_outTRp1_6_3398778_Handler = _outTRp1_6_3398778_Handler; }
		outTRp3_7_3398779_Handler m_outTRp3_7_3398779_Handler;
		void register_outTRp3_7_3398779_Handler(outTRp3_7_3398779_Handler _outTRp3_7_3398779_Handler) { this->m_outTRp3_7_3398779_Handler = _outTRp3_7_3398779_Handler; }
		outTRp1_14_3398782_Handler m_outTRp1_14_3398782_Handler;
		void register_outTRp1_14_3398782_Handler(outTRp1_14_3398782_Handler _outTRp1_14_3398782_Handler) { this->m_outTRp1_14_3398782_Handler = _outTRp1_14_3398782_Handler; }
		outTRp1_3_3398784_Handler m_outTRp1_3_3398784_Handler;
		void register_outTRp1_3_3398784_Handler(outTRp1_3_3398784_Handler _outTRp1_3_3398784_Handler) { this->m_outTRp1_3_3398784_Handler = _outTRp1_3_3398784_Handler; }
		outTRp8_1_3398788_Handler m_outTRp8_1_3398788_Handler;
		void register_outTRp8_1_3398788_Handler(outTRp8_1_3398788_Handler _outTRp8_1_3398788_Handler) { this->m_outTRp8_1_3398788_Handler = _outTRp8_1_3398788_Handler; }
		outTRp9_1_3398789_Handler m_outTRp9_1_3398789_Handler;
		void register_outTRp9_1_3398789_Handler(outTRp9_1_3398789_Handler _outTRp9_1_3398789_Handler) { this->m_outTRp9_1_3398789_Handler = _outTRp9_1_3398789_Handler; }
		outTRp1_17_3398791_Handler m_outTRp1_17_3398791_Handler;
		void register_outTRp1_17_3398791_Handler(outTRp1_17_3398791_Handler _outTRp1_17_3398791_Handler) { this->m_outTRp1_17_3398791_Handler = _outTRp1_17_3398791_Handler; }
		outTRp1_7_3398793_Handler m_outTRp1_7_3398793_Handler;
		void register_outTRp1_7_3398793_Handler(outTRp1_7_3398793_Handler _outTRp1_7_3398793_Handler) { this->m_outTRp1_7_3398793_Handler = _outTRp1_7_3398793_Handler; }
		outTRp1_7_3398794_Handler m_outTRp1_7_3398794_Handler;
		void register_outTRp1_7_3398794_Handler(outTRp1_7_3398794_Handler _outTRp1_7_3398794_Handler) { this->m_outTRp1_7_3398794_Handler = _outTRp1_7_3398794_Handler; }
		outTRp1_4_3398797_Handler m_outTRp1_4_3398797_Handler;
		void register_outTRp1_4_3398797_Handler(outTRp1_4_3398797_Handler _outTRp1_4_3398797_Handler) { this->m_outTRp1_4_3398797_Handler = _outTRp1_4_3398797_Handler; }
		outTRp3_29_3398799_Handler m_outTRp3_29_3398799_Handler;
		void register_outTRp3_29_3398799_Handler(outTRp3_29_3398799_Handler _outTRp3_29_3398799_Handler) { this->m_outTRp3_29_3398799_Handler = _outTRp3_29_3398799_Handler; }
		outTRp9_2_3398801_Handler m_outTRp9_2_3398801_Handler;
		void register_outTRp9_2_3398801_Handler(outTRp9_2_3398801_Handler _outTRp9_2_3398801_Handler) { this->m_outTRp9_2_3398801_Handler = _outTRp9_2_3398801_Handler; }
		outTRp3_13_3398802_Handler m_outTRp3_13_3398802_Handler;
		void register_outTRp3_13_3398802_Handler(outTRp3_13_3398802_Handler _outTRp3_13_3398802_Handler) { this->m_outTRp3_13_3398802_Handler = _outTRp3_13_3398802_Handler; }
		outTRp1_7_3398804_Handler m_outTRp1_7_3398804_Handler;
		void register_outTRp1_7_3398804_Handler(outTRp1_7_3398804_Handler _outTRp1_7_3398804_Handler) { this->m_outTRp1_7_3398804_Handler = _outTRp1_7_3398804_Handler; }
		outTRp3_32_3398806_Handler m_outTRp3_32_3398806_Handler;
		void register_outTRp3_32_3398806_Handler(outTRp3_32_3398806_Handler _outTRp3_32_3398806_Handler) { this->m_outTRp3_32_3398806_Handler = _outTRp3_32_3398806_Handler; }
		outTRp1_20_3398809_Handler m_outTRp1_20_3398809_Handler;
		void register_outTRp1_20_3398809_Handler(outTRp1_20_3398809_Handler _outTRp1_20_3398809_Handler) { this->m_outTRp1_20_3398809_Handler = _outTRp1_20_3398809_Handler; }
		outTRp9_3_3398810_Handler m_outTRp9_3_3398810_Handler;
		void register_outTRp9_3_3398810_Handler(outTRp9_3_3398810_Handler _outTRp9_3_3398810_Handler) { this->m_outTRp9_3_3398810_Handler = _outTRp9_3_3398810_Handler; }
		outTRp1_1_3398811_Handler m_outTRp1_1_3398811_Handler;
		void register_outTRp1_1_3398811_Handler(outTRp1_1_3398811_Handler _outTRp1_1_3398811_Handler) { this->m_outTRp1_1_3398811_Handler = _outTRp1_1_3398811_Handler; }
		outTRp1_9_3398815_Handler m_outTRp1_9_3398815_Handler;
		void register_outTRp1_9_3398815_Handler(outTRp1_9_3398815_Handler _outTRp1_9_3398815_Handler) { this->m_outTRp1_9_3398815_Handler = _outTRp1_9_3398815_Handler; }
		outTRp5_4_3398816_Handler m_outTRp5_4_3398816_Handler;
		void register_outTRp5_4_3398816_Handler(outTRp5_4_3398816_Handler _outTRp5_4_3398816_Handler) { this->m_outTRp5_4_3398816_Handler = _outTRp5_4_3398816_Handler; }
		outTRp5_4_3398817_Handler m_outTRp5_4_3398817_Handler;
		void register_outTRp5_4_3398817_Handler(outTRp5_4_3398817_Handler _outTRp5_4_3398817_Handler) { this->m_outTRp5_4_3398817_Handler = _outTRp5_4_3398817_Handler; }
		outTRp1_25_3398820_Handler m_outTRp1_25_3398820_Handler;
		void register_outTRp1_25_3398820_Handler(outTRp1_25_3398820_Handler _outTRp1_25_3398820_Handler) { this->m_outTRp1_25_3398820_Handler = _outTRp1_25_3398820_Handler; }
		outTRp2_10_3398821_Handler m_outTRp2_10_3398821_Handler;
		void register_outTRp2_10_3398821_Handler(outTRp2_10_3398821_Handler _outTRp2_10_3398821_Handler) { this->m_outTRp2_10_3398821_Handler = _outTRp2_10_3398821_Handler; }
		outTRp1_26_3398822_Handler m_outTRp1_26_3398822_Handler;
		void register_outTRp1_26_3398822_Handler(outTRp1_26_3398822_Handler _outTRp1_26_3398822_Handler) { this->m_outTRp1_26_3398822_Handler = _outTRp1_26_3398822_Handler; }
		outTRp11_1_3398824_Handler m_outTRp11_1_3398824_Handler;
		void register_outTRp11_1_3398824_Handler(outTRp11_1_3398824_Handler _outTRp11_1_3398824_Handler) { this->m_outTRp11_1_3398824_Handler = _outTRp11_1_3398824_Handler; }
		outTRp9_1_3398829_Handler m_outTRp9_1_3398829_Handler;
		void register_outTRp9_1_3398829_Handler(outTRp9_1_3398829_Handler _outTRp9_1_3398829_Handler) { this->m_outTRp9_1_3398829_Handler = _outTRp9_1_3398829_Handler; }
		outTRp3_2_3398830_Handler m_outTRp3_2_3398830_Handler;
		void register_outTRp3_2_3398830_Handler(outTRp3_2_3398830_Handler _outTRp3_2_3398830_Handler) { this->m_outTRp3_2_3398830_Handler = _outTRp3_2_3398830_Handler; }
		outTRp9_5_3398831_Handler m_outTRp9_5_3398831_Handler;
		void register_outTRp9_5_3398831_Handler(outTRp9_5_3398831_Handler _outTRp9_5_3398831_Handler) { this->m_outTRp9_5_3398831_Handler = _outTRp9_5_3398831_Handler; }
		outTRp1_21_3398832_Handler m_outTRp1_21_3398832_Handler;
		void register_outTRp1_21_3398832_Handler(outTRp1_21_3398832_Handler _outTRp1_21_3398832_Handler) { this->m_outTRp1_21_3398832_Handler = _outTRp1_21_3398832_Handler; }
		outTRp3_29_3398835_Handler m_outTRp3_29_3398835_Handler;
		void register_outTRp3_29_3398835_Handler(outTRp3_29_3398835_Handler _outTRp3_29_3398835_Handler) { this->m_outTRp3_29_3398835_Handler = _outTRp3_29_3398835_Handler; }
		outTRp3_21_3398836_Handler m_outTRp3_21_3398836_Handler;
		void register_outTRp3_21_3398836_Handler(outTRp3_21_3398836_Handler _outTRp3_21_3398836_Handler) { this->m_outTRp3_21_3398836_Handler = _outTRp3_21_3398836_Handler; }
		outTRp1_20_3398837_Handler m_outTRp1_20_3398837_Handler;
		void register_outTRp1_20_3398837_Handler(outTRp1_20_3398837_Handler _outTRp1_20_3398837_Handler) { this->m_outTRp1_20_3398837_Handler = _outTRp1_20_3398837_Handler; }
		outTRp4_2_3398839_Handler m_outTRp4_2_3398839_Handler;
		void register_outTRp4_2_3398839_Handler(outTRp4_2_3398839_Handler _outTRp4_2_3398839_Handler) { this->m_outTRp4_2_3398839_Handler = _outTRp4_2_3398839_Handler; }
		outTRp3_8_3398840_Handler m_outTRp3_8_3398840_Handler;
		void register_outTRp3_8_3398840_Handler(outTRp3_8_3398840_Handler _outTRp3_8_3398840_Handler) { this->m_outTRp3_8_3398840_Handler = _outTRp3_8_3398840_Handler; }
		outTRp3_4_3398843_Handler m_outTRp3_4_3398843_Handler;
		void register_outTRp3_4_3398843_Handler(outTRp3_4_3398843_Handler _outTRp3_4_3398843_Handler) { this->m_outTRp3_4_3398843_Handler = _outTRp3_4_3398843_Handler; }
		outTRp1_5_3398844_Handler m_outTRp1_5_3398844_Handler;
		void register_outTRp1_5_3398844_Handler(outTRp1_5_3398844_Handler _outTRp1_5_3398844_Handler) { this->m_outTRp1_5_3398844_Handler = _outTRp1_5_3398844_Handler; }
		outTRp3_44_3398845_Handler m_outTRp3_44_3398845_Handler;
		void register_outTRp3_44_3398845_Handler(outTRp3_44_3398845_Handler _outTRp3_44_3398845_Handler) { this->m_outTRp3_44_3398845_Handler = _outTRp3_44_3398845_Handler; }
		outTRp1_12_3398846_Handler m_outTRp1_12_3398846_Handler;
		void register_outTRp1_12_3398846_Handler(outTRp1_12_3398846_Handler _outTRp1_12_3398846_Handler) { this->m_outTRp1_12_3398846_Handler = _outTRp1_12_3398846_Handler; }
		outTRp2_9_3398848_Handler m_outTRp2_9_3398848_Handler;
		void register_outTRp2_9_3398848_Handler(outTRp2_9_3398848_Handler _outTRp2_9_3398848_Handler) { this->m_outTRp2_9_3398848_Handler = _outTRp2_9_3398848_Handler; }
		outTRp2_7_3398851_Handler m_outTRp2_7_3398851_Handler;
		void register_outTRp2_7_3398851_Handler(outTRp2_7_3398851_Handler _outTRp2_7_3398851_Handler) { this->m_outTRp2_7_3398851_Handler = _outTRp2_7_3398851_Handler; }
		outTRp3_13_3398852_Handler m_outTRp3_13_3398852_Handler;
		void register_outTRp3_13_3398852_Handler(outTRp3_13_3398852_Handler _outTRp3_13_3398852_Handler) { this->m_outTRp3_13_3398852_Handler = _outTRp3_13_3398852_Handler; }
		outTRp3_40_3398853_Handler m_outTRp3_40_3398853_Handler;
		void register_outTRp3_40_3398853_Handler(outTRp3_40_3398853_Handler _outTRp3_40_3398853_Handler) { this->m_outTRp3_40_3398853_Handler = _outTRp3_40_3398853_Handler; }
		outTRp3_40_3398855_Handler m_outTRp3_40_3398855_Handler;
		void register_outTRp3_40_3398855_Handler(outTRp3_40_3398855_Handler _outTRp3_40_3398855_Handler) { this->m_outTRp3_40_3398855_Handler = _outTRp3_40_3398855_Handler; }
		outTRp3_6_3398857_Handler m_outTRp3_6_3398857_Handler;
		void register_outTRp3_6_3398857_Handler(outTRp3_6_3398857_Handler _outTRp3_6_3398857_Handler) { this->m_outTRp3_6_3398857_Handler = _outTRp3_6_3398857_Handler; }
		outTRp17_1_3398863_Handler m_outTRp17_1_3398863_Handler;
		void register_outTRp17_1_3398863_Handler(outTRp17_1_3398863_Handler _outTRp17_1_3398863_Handler) { this->m_outTRp17_1_3398863_Handler = _outTRp17_1_3398863_Handler; }
		outTRp1_3_3398866_Handler m_outTRp1_3_3398866_Handler;
		void register_outTRp1_3_3398866_Handler(outTRp1_3_3398866_Handler _outTRp1_3_3398866_Handler) { this->m_outTRp1_3_3398866_Handler = _outTRp1_3_3398866_Handler; }
		outTRp3_10_3398867_Handler m_outTRp3_10_3398867_Handler;
		void register_outTRp3_10_3398867_Handler(outTRp3_10_3398867_Handler _outTRp3_10_3398867_Handler) { this->m_outTRp3_10_3398867_Handler = _outTRp3_10_3398867_Handler; }
		outTRp4_3_3398869_Handler m_outTRp4_3_3398869_Handler;
		void register_outTRp4_3_3398869_Handler(outTRp4_3_3398869_Handler _outTRp4_3_3398869_Handler) { this->m_outTRp4_3_3398869_Handler = _outTRp4_3_3398869_Handler; }
		outTRp9_1_3398870_Handler m_outTRp9_1_3398870_Handler;
		void register_outTRp9_1_3398870_Handler(outTRp9_1_3398870_Handler _outTRp9_1_3398870_Handler) { this->m_outTRp9_1_3398870_Handler = _outTRp9_1_3398870_Handler; }
		outTRp4_2_3398873_Handler m_outTRp4_2_3398873_Handler;
		void register_outTRp4_2_3398873_Handler(outTRp4_2_3398873_Handler _outTRp4_2_3398873_Handler) { this->m_outTRp4_2_3398873_Handler = _outTRp4_2_3398873_Handler; }
		outTRp2_1_3398874_Handler m_outTRp2_1_3398874_Handler;
		void register_outTRp2_1_3398874_Handler(outTRp2_1_3398874_Handler _outTRp2_1_3398874_Handler) { this->m_outTRp2_1_3398874_Handler = _outTRp2_1_3398874_Handler; }
		outTRp19_1_3398877_Handler m_outTRp19_1_3398877_Handler;
		void register_outTRp19_1_3398877_Handler(outTRp19_1_3398877_Handler _outTRp19_1_3398877_Handler) { this->m_outTRp19_1_3398877_Handler = _outTRp19_1_3398877_Handler; }
		outTRp1_10_3398879_Handler m_outTRp1_10_3398879_Handler;
		void register_outTRp1_10_3398879_Handler(outTRp1_10_3398879_Handler _outTRp1_10_3398879_Handler) { this->m_outTRp1_10_3398879_Handler = _outTRp1_10_3398879_Handler; }
		
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
		void _V1_inTRp2_1_3398721();
		void _V1_inTRp2_1_3398721(int instance_id, int clause_id);
		bool isEnabledV1_inTRp2_1_3398721(int instance_id);
		void _V1_inTRp3_1_3398722();
		void _V1_inTRp3_1_3398722(int instance_id, int clause_id);
		bool isEnabledV1_inTRp3_1_3398722(int instance_id);
		void _V1_inTRp1_1_3398723();
		void _V1_inTRp1_1_3398723(int instance_id, int clause_id);
		bool isEnabledV1_inTRp1_1_3398723(int instance_id);
		void _V1_inTRp3_2_3398726();
		void _V1_inTRp3_2_3398726(int instance_id, int clause_id);
		bool isEnabledV1_inTRp3_2_3398726(int instance_id);
		void _V1_inTRp2_1_3398728();
		void _V1_inTRp2_1_3398728(int instance_id, int clause_id);
		bool isEnabledV1_inTRp2_1_3398728(int instance_id);
		void _V1_inTRp3_4_3398729();
		void _V1_inTRp3_4_3398729(int instance_id, int clause_id);
		bool isEnabledV1_inTRp3_4_3398729(int instance_id);
		void _V1_inTRp2_1_3398732();
		void _V1_inTRp2_1_3398732(int instance_id, int clause_id);
		bool isEnabledV1_inTRp2_1_3398732(int instance_id);
		void _V1_inTRp3_5_3398734();
		void _V1_inTRp3_5_3398734(int instance_id, int clause_id);
		bool isEnabledV1_inTRp3_5_3398734(int instance_id);
		void _V1_inTRp3_4_3398737();
		void _V1_inTRp3_4_3398737(int instance_id, int clause_id);
		bool isEnabledV1_inTRp3_4_3398737(int instance_id);
		void _V1_inTRp2_2_3398739();
		void _V1_inTRp2_2_3398739(int instance_id, int clause_id);
		bool isEnabledV1_inTRp2_2_3398739(int instance_id);
		void _V1_inTRp3_10_3398741();
		void _V1_inTRp3_10_3398741(int instance_id, int clause_id);
		bool isEnabledV1_inTRp3_10_3398741(int instance_id);
		void _V1_inTRp1_2_3398742();
		void _V1_inTRp1_2_3398742(int instance_id, int clause_id);
		bool isEnabledV1_inTRp1_2_3398742(int instance_id);
		void _V1_inTRp1_2_3398743();
		void _V1_inTRp1_2_3398743(int instance_id, int clause_id);
		bool isEnabledV1_inTRp1_2_3398743(int instance_id);
		void _V1_inTRp1_4_3398746();
		void _V1_inTRp1_4_3398746(int instance_id, int clause_id);
		bool isEnabledV1_inTRp1_4_3398746(int instance_id);
		void _V1_inTRp3_9_3398747();
		void _V1_inTRp3_9_3398747(int instance_id, int clause_id);
		bool isEnabledV1_inTRp3_9_3398747(int instance_id);
		void _V1_inTRp3_5_3398749();
		void _V1_inTRp3_5_3398749(int instance_id, int clause_id);
		bool isEnabledV1_inTRp3_5_3398749(int instance_id);
		void _V1_inTRp3_4_3398750();
		void _V1_inTRp3_4_3398750(int instance_id, int clause_id);
		bool isEnabledV1_inTRp3_4_3398750(int instance_id);
		void _V1_inTRp3_9_3398751();
		void _V1_inTRp3_9_3398751(int instance_id, int clause_id);
		bool isEnabledV1_inTRp3_9_3398751(int instance_id);
		void _V1_inTRp3_8_3398752();
		void _V1_inTRp3_8_3398752(int instance_id, int clause_id);
		bool isEnabledV1_inTRp3_8_3398752(int instance_id);
		void _V1_inTRp2_1_3398753();
		void _V1_inTRp2_1_3398753(int instance_id, int clause_id);
		bool isEnabledV1_inTRp2_1_3398753(int instance_id);
		void _V1_inTRp2_3_3398754();
		void _V1_inTRp2_3_3398754(int instance_id, int clause_id);
		bool isEnabledV1_inTRp2_3_3398754(int instance_id);
		void _V1_inTRp1_5_3398755();
		void _V1_inTRp1_5_3398755(int instance_id, int clause_id);
		bool isEnabledV1_inTRp1_5_3398755(int instance_id);
		void _V1_inTRp2_1_3398757();
		void _V1_inTRp2_1_3398757(int instance_id, int clause_id);
		bool isEnabledV1_inTRp2_1_3398757(int instance_id);
		void _V1_inTRp1_3_3398758();
		void _V1_inTRp1_3_3398758(int instance_id, int clause_id);
		bool isEnabledV1_inTRp1_3_3398758(int instance_id);
		void _V1_inTRp3_5_3398760();
		void _V1_inTRp3_5_3398760(int instance_id, int clause_id);
		bool isEnabledV1_inTRp3_5_3398760(int instance_id);
		void _V1_inTRp3_12_3398765();
		void _V1_inTRp3_12_3398765(int instance_id, int clause_id);
		bool isEnabledV1_inTRp3_12_3398765(int instance_id);
		void _V1_inTRp1_8_3398767();
		void _V1_inTRp1_8_3398767(int instance_id, int clause_id);
		bool isEnabledV1_inTRp1_8_3398767(int instance_id);
		void _V1_inTRp3_9_3398768();
		void _V1_inTRp3_9_3398768(int instance_id, int clause_id);
		bool isEnabledV1_inTRp3_9_3398768(int instance_id);
		void _V1_inTRp3_11_3398770();
		void _V1_inTRp3_11_3398770(int instance_id, int clause_id);
		bool isEnabledV1_inTRp3_11_3398770(int instance_id);
		void _V1_inTRp2_4_3398772();
		void _V1_inTRp2_4_3398772(int instance_id, int clause_id);
		bool isEnabledV1_inTRp2_4_3398772(int instance_id);
		void _V1_inTRp3_26_3398774();
		void _V1_inTRp3_26_3398774(int instance_id, int clause_id);
		bool isEnabledV1_inTRp3_26_3398774(int instance_id);
		void _V1_inTRp5_1_3398776();
		void _V1_inTRp5_1_3398776(int instance_id, int clause_id);
		bool isEnabledV1_inTRp5_1_3398776(int instance_id);
		void _V1_inTRp3_8_3398780();
		void _V1_inTRp3_8_3398780(int instance_id, int clause_id);
		bool isEnabledV1_inTRp3_8_3398780(int instance_id);
		void _V1_inTRp2_3_3398781();
		void _V1_inTRp2_3_3398781(int instance_id, int clause_id);
		bool isEnabledV1_inTRp2_3_3398781(int instance_id);
		void _V1_inTRp1_2_3398783();
		void _V1_inTRp1_2_3398783(int instance_id, int clause_id);
		bool isEnabledV1_inTRp1_2_3398783(int instance_id);
		void _V1_inTRp1_14_3398785();
		void _V1_inTRp1_14_3398785(int instance_id, int clause_id);
		bool isEnabledV1_inTRp1_14_3398785(int instance_id);
		void _V1_inTRp3_12_3398786();
		void _V1_inTRp3_12_3398786(int instance_id, int clause_id);
		bool isEnabledV1_inTRp3_12_3398786(int instance_id);
		void _V1_inTRp3_12_3398787();
		void _V1_inTRp3_12_3398787(int instance_id, int clause_id);
		bool isEnabledV1_inTRp3_12_3398787(int instance_id);
		void _V1_inTRp1_16_3398790();
		void _V1_inTRp1_16_3398790(int instance_id, int clause_id);
		bool isEnabledV1_inTRp1_16_3398790(int instance_id);
		void _V1_inTRp3_13_3398792();
		void _V1_inTRp3_13_3398792(int instance_id, int clause_id);
		bool isEnabledV1_inTRp3_13_3398792(int instance_id);
		void _V1_inTRp10_1_3398795();
		void _V1_inTRp10_1_3398795(int instance_id, int clause_id);
		bool isEnabledV1_inTRp10_1_3398795(int instance_id);
		void _V1_inTRp11_1_3398796();
		void _V1_inTRp11_1_3398796(int instance_id, int clause_id);
		bool isEnabledV1_inTRp11_1_3398796(int instance_id);
		void _V1_inTRp3_18_3398798();
		void _V1_inTRp3_18_3398798(int instance_id, int clause_id);
		bool isEnabledV1_inTRp3_18_3398798(int instance_id);
		void _V1_inTRp9_1_3398800();
		void _V1_inTRp9_1_3398800(int instance_id, int clause_id);
		bool isEnabledV1_inTRp9_1_3398800(int instance_id);
		void _V1_inTRp3_14_3398803();
		void _V1_inTRp3_14_3398803(int instance_id, int clause_id);
		bool isEnabledV1_inTRp3_14_3398803(int instance_id);
		void _V1_inTRp10_1_3398805();
		void _V1_inTRp10_1_3398805(int instance_id, int clause_id);
		bool isEnabledV1_inTRp10_1_3398805(int instance_id);
		void _V1_inTRp5_3_3398807();
		void _V1_inTRp5_3_3398807(int instance_id, int clause_id);
		bool isEnabledV1_inTRp5_3_3398807(int instance_id);
		void _V1_inTRp1_9_3398808();
		void _V1_inTRp1_9_3398808(int instance_id, int clause_id);
		bool isEnabledV1_inTRp1_9_3398808(int instance_id);
		void _V1_inTRp1_2_3398812();
		void _V1_inTRp1_2_3398812(int instance_id, int clause_id);
		bool isEnabledV1_inTRp1_2_3398812(int instance_id);
		void _V1_inTRp3_10_3398813();
		void _V1_inTRp3_10_3398813(int instance_id, int clause_id);
		bool isEnabledV1_inTRp3_10_3398813(int instance_id);
		void _V1_inTRp3_17_3398814();
		void _V1_inTRp3_17_3398814(int instance_id, int clause_id);
		bool isEnabledV1_inTRp3_17_3398814(int instance_id);
		void _V1_inTRp12_1_3398818();
		void _V1_inTRp12_1_3398818(int instance_id, int clause_id);
		bool isEnabledV1_inTRp12_1_3398818(int instance_id);
		void _V1_inTRp13_1_3398819();
		void _V1_inTRp13_1_3398819(int instance_id, int clause_id);
		bool isEnabledV1_inTRp13_1_3398819(int instance_id);
		void _V1_inTRp1_27_3398823();
		void _V1_inTRp1_27_3398823(int instance_id, int clause_id);
		bool isEnabledV1_inTRp1_27_3398823(int instance_id);
		void _V1_inTRp1_5_3398825();
		void _V1_inTRp1_5_3398825(int instance_id, int clause_id);
		bool isEnabledV1_inTRp1_5_3398825(int instance_id);
		void _V1_inTRp2_5_3398826();
		void _V1_inTRp2_5_3398826(int instance_id, int clause_id);
		bool isEnabledV1_inTRp2_5_3398826(int instance_id);
		void _V1_inTRp3_15_3398827();
		void _V1_inTRp3_15_3398827(int instance_id, int clause_id);
		bool isEnabledV1_inTRp3_15_3398827(int instance_id);
		void _V1_inTRp1_31_3398828();
		void _V1_inTRp1_31_3398828(int instance_id, int clause_id);
		bool isEnabledV1_inTRp1_31_3398828(int instance_id);
		void _V1_inTRp1_14_3398833();
		void _V1_inTRp1_14_3398833(int instance_id, int clause_id);
		bool isEnabledV1_inTRp1_14_3398833(int instance_id);
		void _V1_inTRp1_32_3398834();
		void _V1_inTRp1_32_3398834(int instance_id, int clause_id);
		bool isEnabledV1_inTRp1_32_3398834(int instance_id);
		void _V1_inTRp4_1_3398838();
		void _V1_inTRp4_1_3398838(int instance_id, int clause_id);
		bool isEnabledV1_inTRp4_1_3398838(int instance_id);
		void _V1_inTRp14_1_3398841();
		void _V1_inTRp14_1_3398841(int instance_id, int clause_id);
		bool isEnabledV1_inTRp14_1_3398841(int instance_id);
		void _V1_inTRp3_3_3398842();
		void _V1_inTRp3_3_3398842(int instance_id, int clause_id);
		bool isEnabledV1_inTRp3_3_3398842(int instance_id);
		void _V1_inTRp2_8_3398847();
		void _V1_inTRp2_8_3398847(int instance_id, int clause_id);
		bool isEnabledV1_inTRp2_8_3398847(int instance_id);
		void _V1_inTRp1_10_3398849();
		void _V1_inTRp1_10_3398849(int instance_id, int clause_id);
		bool isEnabledV1_inTRp1_10_3398849(int instance_id);
		void _V1_inTRp2_6_3398850();
		void _V1_inTRp2_6_3398850(int instance_id, int clause_id);
		bool isEnabledV1_inTRp2_6_3398850(int instance_id);
		void _V1_inTRp15_1_3398854();
		void _V1_inTRp15_1_3398854(int instance_id, int clause_id);
		bool isEnabledV1_inTRp15_1_3398854(int instance_id);
		void _V1_inTRp16_1_3398856();
		void _V1_inTRp16_1_3398856(int instance_id, int clause_id);
		bool isEnabledV1_inTRp16_1_3398856(int instance_id);
		void _V1_inTRp17_1_3398858();
		void _V1_inTRp17_1_3398858(int instance_id, int clause_id);
		bool isEnabledV1_inTRp17_1_3398858(int instance_id);
		void _V1_inTRp1_15_3398859();
		void _V1_inTRp1_15_3398859(int instance_id, int clause_id);
		bool isEnabledV1_inTRp1_15_3398859(int instance_id);
		void _V1_inTRp3_34_3398860();
		void _V1_inTRp3_34_3398860(int instance_id, int clause_id);
		bool isEnabledV1_inTRp3_34_3398860(int instance_id);
		void _V1_inTRp1_24_3398861();
		void _V1_inTRp1_24_3398861(int instance_id, int clause_id);
		bool isEnabledV1_inTRp1_24_3398861(int instance_id);
		void _V1_inTRp1_7_3398862();
		void _V1_inTRp1_7_3398862(int instance_id, int clause_id);
		bool isEnabledV1_inTRp1_7_3398862(int instance_id);
		void _V1_inTRp17_2_3398864();
		void _V1_inTRp17_2_3398864(int instance_id, int clause_id);
		bool isEnabledV1_inTRp17_2_3398864(int instance_id);
		void _V1_inTRp3_27_3398865();
		void _V1_inTRp3_27_3398865(int instance_id, int clause_id);
		bool isEnabledV1_inTRp3_27_3398865(int instance_id);
		void _V1_inTRp4_2_3398868();
		void _V1_inTRp4_2_3398868(int instance_id, int clause_id);
		bool isEnabledV1_inTRp4_2_3398868(int instance_id);
		void _V1_inTRp18_1_3398871();
		void _V1_inTRp18_1_3398871(int instance_id, int clause_id);
		bool isEnabledV1_inTRp18_1_3398871(int instance_id);
		void _V1_inTRp3_22_3398872();
		void _V1_inTRp3_22_3398872(int instance_id, int clause_id);
		bool isEnabledV1_inTRp3_22_3398872(int instance_id);
		void _V1_inTRp2_2_3398875();
		void _V1_inTRp2_2_3398875(int instance_id, int clause_id);
		bool isEnabledV1_inTRp2_2_3398875(int instance_id);
		void _V1_inTRp4_1_3398876();
		void _V1_inTRp4_1_3398876(int instance_id, int clause_id);
		bool isEnabledV1_inTRp4_1_3398876(int instance_id);
		void _V1_inTRp3_28_3398878();
		void _V1_inTRp3_28_3398878(int instance_id, int clause_id);
		bool isEnabledV1_inTRp3_28_3398878(int instance_id);
		
		
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
		void _V1_outTRp1_1_3398718();
		void _V1_outTRp1_1_3398718(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp1_1_3398718(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp1_1_3398719();
		void _V1_outTRp1_1_3398719(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp1_1_3398719(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp1_1_3398720();
		void _V1_outTRp1_1_3398720(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp1_1_3398720(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp3_1_3398724();
		void _V1_outTRp3_1_3398724(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp3_1_3398724(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp1_4_3398725();
		void _V1_outTRp1_4_3398725(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp1_4_3398725(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp3_3_3398727();
		void _V1_outTRp3_3_3398727(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp3_3_3398727(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp3_5_3398730();
		void _V1_outTRp3_5_3398730(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp3_5_3398730(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp3_4_3398731();
		void _V1_outTRp3_4_3398731(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp3_4_3398731(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp3_5_3398733();
		void _V1_outTRp3_5_3398733(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp3_5_3398733(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp3_2_3398735();
		void _V1_outTRp3_2_3398735(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp3_2_3398735(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp3_3_3398736();
		void _V1_outTRp3_3_3398736(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp3_3_3398736(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp1_1_3398738();
		void _V1_outTRp1_1_3398738(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp1_1_3398738(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp2_3_3398740();
		void _V1_outTRp2_3_3398740(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp2_3_3398740(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp4_1_3398744();
		void _V1_outTRp4_1_3398744(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp4_1_3398744(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp5_1_3398745();
		void _V1_outTRp5_1_3398745(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp5_1_3398745(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp3_10_3398748();
		void _V1_outTRp3_10_3398748(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp3_10_3398748(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp1_6_3398756();
		void _V1_outTRp1_6_3398756(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp1_6_3398756(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp1_4_3398759();
		void _V1_outTRp1_4_3398759(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp1_4_3398759(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp3_6_3398761();
		void _V1_outTRp3_6_3398761(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp3_6_3398761(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp2_6_3398762();
		void _V1_outTRp2_6_3398762(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp2_6_3398762(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp3_4_3398763();
		void _V1_outTRp3_4_3398763(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp3_4_3398763(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp3_11_3398764();
		void _V1_outTRp3_11_3398764(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp3_11_3398764(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp3_8_3398766();
		void _V1_outTRp3_8_3398766(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp3_8_3398766(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp1_10_3398769();
		void _V1_outTRp1_10_3398769(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp1_10_3398769(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp3_12_3398771();
		void _V1_outTRp3_12_3398771(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp3_12_3398771(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp6_1_3398773();
		void _V1_outTRp6_1_3398773(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp6_1_3398773(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp7_1_3398775();
		void _V1_outTRp7_1_3398775(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp7_1_3398775(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp5_2_3398777();
		void _V1_outTRp5_2_3398777(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp5_2_3398777(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp1_6_3398778();
		void _V1_outTRp1_6_3398778(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp1_6_3398778(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp3_7_3398779();
		void _V1_outTRp3_7_3398779(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp3_7_3398779(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp1_14_3398782();
		void _V1_outTRp1_14_3398782(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp1_14_3398782(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp1_3_3398784();
		void _V1_outTRp1_3_3398784(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp1_3_3398784(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp8_1_3398788();
		void _V1_outTRp8_1_3398788(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp8_1_3398788(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp9_1_3398789();
		void _V1_outTRp9_1_3398789(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp9_1_3398789(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp1_17_3398791();
		void _V1_outTRp1_17_3398791(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp1_17_3398791(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp1_7_3398793();
		void _V1_outTRp1_7_3398793(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp1_7_3398793(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp1_7_3398794();
		void _V1_outTRp1_7_3398794(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp1_7_3398794(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp1_4_3398797();
		void _V1_outTRp1_4_3398797(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp1_4_3398797(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp3_29_3398799();
		void _V1_outTRp3_29_3398799(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp3_29_3398799(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp9_2_3398801();
		void _V1_outTRp9_2_3398801(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp9_2_3398801(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp3_13_3398802();
		void _V1_outTRp3_13_3398802(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp3_13_3398802(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp1_7_3398804();
		void _V1_outTRp1_7_3398804(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp1_7_3398804(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp3_32_3398806();
		void _V1_outTRp3_32_3398806(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp3_32_3398806(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp1_20_3398809();
		void _V1_outTRp1_20_3398809(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp1_20_3398809(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp9_3_3398810();
		void _V1_outTRp9_3_3398810(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp9_3_3398810(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp1_1_3398811();
		void _V1_outTRp1_1_3398811(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp1_1_3398811(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp1_9_3398815();
		void _V1_outTRp1_9_3398815(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp1_9_3398815(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp5_4_3398816();
		void _V1_outTRp5_4_3398816(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp5_4_3398816(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp5_4_3398817();
		void _V1_outTRp5_4_3398817(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp5_4_3398817(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp1_25_3398820();
		void _V1_outTRp1_25_3398820(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp1_25_3398820(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp2_10_3398821();
		void _V1_outTRp2_10_3398821(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp2_10_3398821(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp1_26_3398822();
		void _V1_outTRp1_26_3398822(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp1_26_3398822(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp11_1_3398824();
		void _V1_outTRp11_1_3398824(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp11_1_3398824(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp9_1_3398829();
		void _V1_outTRp9_1_3398829(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp9_1_3398829(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp3_2_3398830();
		void _V1_outTRp3_2_3398830(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp3_2_3398830(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp9_5_3398831();
		void _V1_outTRp9_5_3398831(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp9_5_3398831(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp1_21_3398832();
		void _V1_outTRp1_21_3398832(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp1_21_3398832(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp3_29_3398835();
		void _V1_outTRp3_29_3398835(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp3_29_3398835(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp3_21_3398836();
		void _V1_outTRp3_21_3398836(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp3_21_3398836(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp1_20_3398837();
		void _V1_outTRp1_20_3398837(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp1_20_3398837(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp4_2_3398839();
		void _V1_outTRp4_2_3398839(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp4_2_3398839(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp3_8_3398840();
		void _V1_outTRp3_8_3398840(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp3_8_3398840(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp3_4_3398843();
		void _V1_outTRp3_4_3398843(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp3_4_3398843(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp1_5_3398844();
		void _V1_outTRp1_5_3398844(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp1_5_3398844(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp3_44_3398845();
		void _V1_outTRp3_44_3398845(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp3_44_3398845(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp1_12_3398846();
		void _V1_outTRp1_12_3398846(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp1_12_3398846(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp2_9_3398848();
		void _V1_outTRp2_9_3398848(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp2_9_3398848(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp2_7_3398851();
		void _V1_outTRp2_7_3398851(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp2_7_3398851(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp3_13_3398852();
		void _V1_outTRp3_13_3398852(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp3_13_3398852(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp3_40_3398853();
		void _V1_outTRp3_40_3398853(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp3_40_3398853(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp3_40_3398855();
		void _V1_outTRp3_40_3398855(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp3_40_3398855(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp3_6_3398857();
		void _V1_outTRp3_6_3398857(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp3_6_3398857(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp17_1_3398863();
		void _V1_outTRp17_1_3398863(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp17_1_3398863(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp1_3_3398866();
		void _V1_outTRp1_3_3398866(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp1_3_3398866(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp3_10_3398867();
		void _V1_outTRp3_10_3398867(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp3_10_3398867(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp4_3_3398869();
		void _V1_outTRp4_3_3398869(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp4_3_3398869(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp9_1_3398870();
		void _V1_outTRp9_1_3398870(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp9_1_3398870(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp4_2_3398873();
		void _V1_outTRp4_2_3398873(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp4_2_3398873(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp2_1_3398874();
		void _V1_outTRp2_1_3398874(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp2_1_3398874(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp19_1_3398877();
		void _V1_outTRp19_1_3398877(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp19_1_3398877(std::vector<std::string>  list_of_rcvd_notifications);
		void _V1_outTRp1_10_3398879();
		void _V1_outTRp1_10_3398879(int instance_id, int clause_id);
		std::vector<int> _match_V1_outTRp1_10_3398879(std::vector<std::string>  list_of_rcvd_notifications);
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
	
	virtual bool isEnabledV1_inTRp2_1_3398721(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp2_1_3398721(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp2_1_3398721!");
		std::cout<<"ERROR: Unexpected Signal inTRp2_1_3398721!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp2_1_3398721!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp2_1_3398721(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp2_1_3398721!");
		std::cout<<"ERROR: Unexpected Signal inTRp2_1_3398721!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp2_1_3398721!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp3_1_3398722(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp3_1_3398722(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_1_3398722!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_1_3398722!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_1_3398722!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp3_1_3398722(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_1_3398722!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_1_3398722!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_1_3398722!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp1_1_3398723(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp1_1_3398723(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_1_3398723!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_1_3398723!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_1_3398723!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp1_1_3398723(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_1_3398723!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_1_3398723!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_1_3398723!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp3_2_3398726(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp3_2_3398726(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_2_3398726!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_2_3398726!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_2_3398726!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp3_2_3398726(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_2_3398726!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_2_3398726!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_2_3398726!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp2_1_3398728(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp2_1_3398728(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp2_1_3398728!");
		std::cout<<"ERROR: Unexpected Signal inTRp2_1_3398728!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp2_1_3398728!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp2_1_3398728(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp2_1_3398728!");
		std::cout<<"ERROR: Unexpected Signal inTRp2_1_3398728!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp2_1_3398728!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp3_4_3398729(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp3_4_3398729(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_4_3398729!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_4_3398729!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_4_3398729!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp3_4_3398729(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_4_3398729!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_4_3398729!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_4_3398729!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp2_1_3398732(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp2_1_3398732(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp2_1_3398732!");
		std::cout<<"ERROR: Unexpected Signal inTRp2_1_3398732!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp2_1_3398732!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp2_1_3398732(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp2_1_3398732!");
		std::cout<<"ERROR: Unexpected Signal inTRp2_1_3398732!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp2_1_3398732!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp3_5_3398734(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp3_5_3398734(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_5_3398734!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_5_3398734!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_5_3398734!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp3_5_3398734(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_5_3398734!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_5_3398734!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_5_3398734!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp3_4_3398737(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp3_4_3398737(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_4_3398737!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_4_3398737!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_4_3398737!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp3_4_3398737(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_4_3398737!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_4_3398737!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_4_3398737!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp2_2_3398739(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp2_2_3398739(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp2_2_3398739!");
		std::cout<<"ERROR: Unexpected Signal inTRp2_2_3398739!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp2_2_3398739!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp2_2_3398739(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp2_2_3398739!");
		std::cout<<"ERROR: Unexpected Signal inTRp2_2_3398739!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp2_2_3398739!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp3_10_3398741(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp3_10_3398741(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_10_3398741!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_10_3398741!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_10_3398741!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp3_10_3398741(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_10_3398741!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_10_3398741!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_10_3398741!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp1_2_3398742(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp1_2_3398742(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_2_3398742!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_2_3398742!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_2_3398742!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp1_2_3398742(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_2_3398742!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_2_3398742!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_2_3398742!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp1_2_3398743(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp1_2_3398743(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_2_3398743!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_2_3398743!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_2_3398743!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp1_2_3398743(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_2_3398743!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_2_3398743!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_2_3398743!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp1_4_3398746(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp1_4_3398746(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_4_3398746!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_4_3398746!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_4_3398746!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp1_4_3398746(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_4_3398746!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_4_3398746!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_4_3398746!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp3_9_3398747(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp3_9_3398747(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_9_3398747!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_9_3398747!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_9_3398747!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp3_9_3398747(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_9_3398747!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_9_3398747!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_9_3398747!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp3_5_3398749(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp3_5_3398749(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_5_3398749!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_5_3398749!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_5_3398749!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp3_5_3398749(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_5_3398749!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_5_3398749!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_5_3398749!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp3_4_3398750(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp3_4_3398750(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_4_3398750!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_4_3398750!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_4_3398750!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp3_4_3398750(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_4_3398750!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_4_3398750!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_4_3398750!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp3_9_3398751(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp3_9_3398751(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_9_3398751!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_9_3398751!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_9_3398751!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp3_9_3398751(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_9_3398751!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_9_3398751!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_9_3398751!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp3_8_3398752(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp3_8_3398752(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_8_3398752!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_8_3398752!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_8_3398752!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp3_8_3398752(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_8_3398752!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_8_3398752!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_8_3398752!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp2_1_3398753(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp2_1_3398753(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp2_1_3398753!");
		std::cout<<"ERROR: Unexpected Signal inTRp2_1_3398753!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp2_1_3398753!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp2_1_3398753(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp2_1_3398753!");
		std::cout<<"ERROR: Unexpected Signal inTRp2_1_3398753!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp2_1_3398753!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp2_3_3398754(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp2_3_3398754(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp2_3_3398754!");
		std::cout<<"ERROR: Unexpected Signal inTRp2_3_3398754!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp2_3_3398754!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp2_3_3398754(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp2_3_3398754!");
		std::cout<<"ERROR: Unexpected Signal inTRp2_3_3398754!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp2_3_3398754!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp1_5_3398755(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp1_5_3398755(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_5_3398755!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_5_3398755!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_5_3398755!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp1_5_3398755(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_5_3398755!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_5_3398755!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_5_3398755!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp2_1_3398757(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp2_1_3398757(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp2_1_3398757!");
		std::cout<<"ERROR: Unexpected Signal inTRp2_1_3398757!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp2_1_3398757!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp2_1_3398757(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp2_1_3398757!");
		std::cout<<"ERROR: Unexpected Signal inTRp2_1_3398757!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp2_1_3398757!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp1_3_3398758(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp1_3_3398758(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_3_3398758!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_3_3398758!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_3_3398758!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp1_3_3398758(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_3_3398758!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_3_3398758!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_3_3398758!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp3_5_3398760(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp3_5_3398760(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_5_3398760!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_5_3398760!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_5_3398760!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp3_5_3398760(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_5_3398760!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_5_3398760!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_5_3398760!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp3_12_3398765(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp3_12_3398765(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_12_3398765!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_12_3398765!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_12_3398765!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp3_12_3398765(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_12_3398765!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_12_3398765!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_12_3398765!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp1_8_3398767(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp1_8_3398767(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_8_3398767!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_8_3398767!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_8_3398767!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp1_8_3398767(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_8_3398767!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_8_3398767!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_8_3398767!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp3_9_3398768(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp3_9_3398768(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_9_3398768!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_9_3398768!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_9_3398768!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp3_9_3398768(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_9_3398768!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_9_3398768!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_9_3398768!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp3_11_3398770(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp3_11_3398770(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_11_3398770!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_11_3398770!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_11_3398770!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp3_11_3398770(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_11_3398770!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_11_3398770!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_11_3398770!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp2_4_3398772(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp2_4_3398772(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp2_4_3398772!");
		std::cout<<"ERROR: Unexpected Signal inTRp2_4_3398772!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp2_4_3398772!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp2_4_3398772(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp2_4_3398772!");
		std::cout<<"ERROR: Unexpected Signal inTRp2_4_3398772!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp2_4_3398772!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp3_26_3398774(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp3_26_3398774(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_26_3398774!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_26_3398774!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_26_3398774!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp3_26_3398774(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_26_3398774!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_26_3398774!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_26_3398774!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp5_1_3398776(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp5_1_3398776(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp5_1_3398776!");
		std::cout<<"ERROR: Unexpected Signal inTRp5_1_3398776!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp5_1_3398776!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp5_1_3398776(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp5_1_3398776!");
		std::cout<<"ERROR: Unexpected Signal inTRp5_1_3398776!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp5_1_3398776!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp3_8_3398780(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp3_8_3398780(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_8_3398780!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_8_3398780!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_8_3398780!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp3_8_3398780(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_8_3398780!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_8_3398780!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_8_3398780!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp2_3_3398781(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp2_3_3398781(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp2_3_3398781!");
		std::cout<<"ERROR: Unexpected Signal inTRp2_3_3398781!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp2_3_3398781!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp2_3_3398781(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp2_3_3398781!");
		std::cout<<"ERROR: Unexpected Signal inTRp2_3_3398781!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp2_3_3398781!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp1_2_3398783(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp1_2_3398783(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_2_3398783!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_2_3398783!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_2_3398783!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp1_2_3398783(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_2_3398783!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_2_3398783!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_2_3398783!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp1_14_3398785(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp1_14_3398785(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_14_3398785!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_14_3398785!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_14_3398785!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp1_14_3398785(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_14_3398785!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_14_3398785!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_14_3398785!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp3_12_3398786(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp3_12_3398786(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_12_3398786!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_12_3398786!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_12_3398786!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp3_12_3398786(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_12_3398786!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_12_3398786!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_12_3398786!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp3_12_3398787(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp3_12_3398787(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_12_3398787!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_12_3398787!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_12_3398787!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp3_12_3398787(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_12_3398787!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_12_3398787!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_12_3398787!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp1_16_3398790(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp1_16_3398790(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_16_3398790!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_16_3398790!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_16_3398790!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp1_16_3398790(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_16_3398790!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_16_3398790!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_16_3398790!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp3_13_3398792(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp3_13_3398792(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_13_3398792!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_13_3398792!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_13_3398792!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp3_13_3398792(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_13_3398792!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_13_3398792!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_13_3398792!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp10_1_3398795(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp10_1_3398795(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp10_1_3398795!");
		std::cout<<"ERROR: Unexpected Signal inTRp10_1_3398795!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp10_1_3398795!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp10_1_3398795(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp10_1_3398795!");
		std::cout<<"ERROR: Unexpected Signal inTRp10_1_3398795!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp10_1_3398795!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp11_1_3398796(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp11_1_3398796(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp11_1_3398796!");
		std::cout<<"ERROR: Unexpected Signal inTRp11_1_3398796!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp11_1_3398796!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp11_1_3398796(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp11_1_3398796!");
		std::cout<<"ERROR: Unexpected Signal inTRp11_1_3398796!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp11_1_3398796!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp3_18_3398798(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp3_18_3398798(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_18_3398798!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_18_3398798!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_18_3398798!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp3_18_3398798(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_18_3398798!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_18_3398798!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_18_3398798!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp9_1_3398800(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp9_1_3398800(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp9_1_3398800!");
		std::cout<<"ERROR: Unexpected Signal inTRp9_1_3398800!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp9_1_3398800!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp9_1_3398800(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp9_1_3398800!");
		std::cout<<"ERROR: Unexpected Signal inTRp9_1_3398800!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp9_1_3398800!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp3_14_3398803(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp3_14_3398803(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_14_3398803!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_14_3398803!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_14_3398803!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp3_14_3398803(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_14_3398803!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_14_3398803!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_14_3398803!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp10_1_3398805(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp10_1_3398805(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp10_1_3398805!");
		std::cout<<"ERROR: Unexpected Signal inTRp10_1_3398805!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp10_1_3398805!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp10_1_3398805(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp10_1_3398805!");
		std::cout<<"ERROR: Unexpected Signal inTRp10_1_3398805!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp10_1_3398805!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp5_3_3398807(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp5_3_3398807(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp5_3_3398807!");
		std::cout<<"ERROR: Unexpected Signal inTRp5_3_3398807!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp5_3_3398807!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp5_3_3398807(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp5_3_3398807!");
		std::cout<<"ERROR: Unexpected Signal inTRp5_3_3398807!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp5_3_3398807!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp1_9_3398808(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp1_9_3398808(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_9_3398808!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_9_3398808!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_9_3398808!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp1_9_3398808(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_9_3398808!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_9_3398808!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_9_3398808!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp1_2_3398812(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp1_2_3398812(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_2_3398812!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_2_3398812!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_2_3398812!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp1_2_3398812(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_2_3398812!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_2_3398812!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_2_3398812!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp3_10_3398813(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp3_10_3398813(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_10_3398813!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_10_3398813!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_10_3398813!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp3_10_3398813(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_10_3398813!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_10_3398813!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_10_3398813!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp3_17_3398814(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp3_17_3398814(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_17_3398814!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_17_3398814!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_17_3398814!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp3_17_3398814(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_17_3398814!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_17_3398814!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_17_3398814!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp12_1_3398818(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp12_1_3398818(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp12_1_3398818!");
		std::cout<<"ERROR: Unexpected Signal inTRp12_1_3398818!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp12_1_3398818!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp12_1_3398818(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp12_1_3398818!");
		std::cout<<"ERROR: Unexpected Signal inTRp12_1_3398818!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp12_1_3398818!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp13_1_3398819(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp13_1_3398819(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp13_1_3398819!");
		std::cout<<"ERROR: Unexpected Signal inTRp13_1_3398819!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp13_1_3398819!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp13_1_3398819(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp13_1_3398819!");
		std::cout<<"ERROR: Unexpected Signal inTRp13_1_3398819!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp13_1_3398819!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp1_27_3398823(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp1_27_3398823(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_27_3398823!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_27_3398823!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_27_3398823!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp1_27_3398823(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_27_3398823!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_27_3398823!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_27_3398823!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp1_5_3398825(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp1_5_3398825(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_5_3398825!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_5_3398825!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_5_3398825!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp1_5_3398825(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_5_3398825!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_5_3398825!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_5_3398825!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp2_5_3398826(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp2_5_3398826(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp2_5_3398826!");
		std::cout<<"ERROR: Unexpected Signal inTRp2_5_3398826!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp2_5_3398826!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp2_5_3398826(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp2_5_3398826!");
		std::cout<<"ERROR: Unexpected Signal inTRp2_5_3398826!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp2_5_3398826!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp3_15_3398827(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp3_15_3398827(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_15_3398827!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_15_3398827!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_15_3398827!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp3_15_3398827(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_15_3398827!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_15_3398827!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_15_3398827!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp1_31_3398828(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp1_31_3398828(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_31_3398828!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_31_3398828!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_31_3398828!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp1_31_3398828(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_31_3398828!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_31_3398828!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_31_3398828!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp1_14_3398833(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp1_14_3398833(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_14_3398833!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_14_3398833!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_14_3398833!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp1_14_3398833(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_14_3398833!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_14_3398833!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_14_3398833!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp1_32_3398834(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp1_32_3398834(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_32_3398834!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_32_3398834!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_32_3398834!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp1_32_3398834(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_32_3398834!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_32_3398834!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_32_3398834!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp4_1_3398838(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp4_1_3398838(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp4_1_3398838!");
		std::cout<<"ERROR: Unexpected Signal inTRp4_1_3398838!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp4_1_3398838!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp4_1_3398838(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp4_1_3398838!");
		std::cout<<"ERROR: Unexpected Signal inTRp4_1_3398838!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp4_1_3398838!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp14_1_3398841(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp14_1_3398841(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp14_1_3398841!");
		std::cout<<"ERROR: Unexpected Signal inTRp14_1_3398841!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp14_1_3398841!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp14_1_3398841(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp14_1_3398841!");
		std::cout<<"ERROR: Unexpected Signal inTRp14_1_3398841!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp14_1_3398841!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp3_3_3398842(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp3_3_3398842(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_3_3398842!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_3_3398842!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_3_3398842!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp3_3_3398842(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_3_3398842!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_3_3398842!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_3_3398842!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp2_8_3398847(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp2_8_3398847(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp2_8_3398847!");
		std::cout<<"ERROR: Unexpected Signal inTRp2_8_3398847!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp2_8_3398847!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp2_8_3398847(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp2_8_3398847!");
		std::cout<<"ERROR: Unexpected Signal inTRp2_8_3398847!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp2_8_3398847!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp1_10_3398849(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp1_10_3398849(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_10_3398849!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_10_3398849!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_10_3398849!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp1_10_3398849(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_10_3398849!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_10_3398849!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_10_3398849!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp2_6_3398850(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp2_6_3398850(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp2_6_3398850!");
		std::cout<<"ERROR: Unexpected Signal inTRp2_6_3398850!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp2_6_3398850!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp2_6_3398850(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp2_6_3398850!");
		std::cout<<"ERROR: Unexpected Signal inTRp2_6_3398850!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp2_6_3398850!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp15_1_3398854(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp15_1_3398854(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp15_1_3398854!");
		std::cout<<"ERROR: Unexpected Signal inTRp15_1_3398854!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp15_1_3398854!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp15_1_3398854(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp15_1_3398854!");
		std::cout<<"ERROR: Unexpected Signal inTRp15_1_3398854!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp15_1_3398854!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp16_1_3398856(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp16_1_3398856(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp16_1_3398856!");
		std::cout<<"ERROR: Unexpected Signal inTRp16_1_3398856!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp16_1_3398856!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp16_1_3398856(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp16_1_3398856!");
		std::cout<<"ERROR: Unexpected Signal inTRp16_1_3398856!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp16_1_3398856!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp17_1_3398858(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp17_1_3398858(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp17_1_3398858!");
		std::cout<<"ERROR: Unexpected Signal inTRp17_1_3398858!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp17_1_3398858!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp17_1_3398858(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp17_1_3398858!");
		std::cout<<"ERROR: Unexpected Signal inTRp17_1_3398858!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp17_1_3398858!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp1_15_3398859(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp1_15_3398859(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_15_3398859!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_15_3398859!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_15_3398859!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp1_15_3398859(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_15_3398859!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_15_3398859!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_15_3398859!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp3_34_3398860(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp3_34_3398860(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_34_3398860!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_34_3398860!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_34_3398860!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp3_34_3398860(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_34_3398860!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_34_3398860!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_34_3398860!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp1_24_3398861(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp1_24_3398861(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_24_3398861!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_24_3398861!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_24_3398861!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp1_24_3398861(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_24_3398861!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_24_3398861!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_24_3398861!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp1_7_3398862(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp1_7_3398862(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_7_3398862!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_7_3398862!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_7_3398862!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp1_7_3398862(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp1_7_3398862!");
		std::cout<<"ERROR: Unexpected Signal inTRp1_7_3398862!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp1_7_3398862!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp17_2_3398864(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp17_2_3398864(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp17_2_3398864!");
		std::cout<<"ERROR: Unexpected Signal inTRp17_2_3398864!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp17_2_3398864!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp17_2_3398864(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp17_2_3398864!");
		std::cout<<"ERROR: Unexpected Signal inTRp17_2_3398864!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp17_2_3398864!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp3_27_3398865(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp3_27_3398865(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_27_3398865!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_27_3398865!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_27_3398865!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp3_27_3398865(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_27_3398865!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_27_3398865!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_27_3398865!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp4_2_3398868(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp4_2_3398868(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp4_2_3398868!");
		std::cout<<"ERROR: Unexpected Signal inTRp4_2_3398868!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp4_2_3398868!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp4_2_3398868(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp4_2_3398868!");
		std::cout<<"ERROR: Unexpected Signal inTRp4_2_3398868!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp4_2_3398868!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp18_1_3398871(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp18_1_3398871(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp18_1_3398871!");
		std::cout<<"ERROR: Unexpected Signal inTRp18_1_3398871!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp18_1_3398871!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp18_1_3398871(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp18_1_3398871!");
		std::cout<<"ERROR: Unexpected Signal inTRp18_1_3398871!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp18_1_3398871!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp3_22_3398872(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp3_22_3398872(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_22_3398872!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_22_3398872!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_22_3398872!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp3_22_3398872(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_22_3398872!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_22_3398872!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_22_3398872!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp2_2_3398875(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp2_2_3398875(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp2_2_3398875!");
		std::cout<<"ERROR: Unexpected Signal inTRp2_2_3398875!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp2_2_3398875!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp2_2_3398875(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp2_2_3398875!");
		std::cout<<"ERROR: Unexpected Signal inTRp2_2_3398875!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp2_2_3398875!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp4_1_3398876(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp4_1_3398876(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp4_1_3398876!");
		std::cout<<"ERROR: Unexpected Signal inTRp4_1_3398876!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp4_1_3398876!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp4_1_3398876(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp4_1_3398876!");
		std::cout<<"ERROR: Unexpected Signal inTRp4_1_3398876!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp4_1_3398876!", UNEXPECTED_EVENT));
	}
	
	virtual bool isEnabledV1_inTRp3_28_3398878(V1_StateMachineController *smc, int instance_id)
	{
		return false;
	}
	
	virtual void V1_inTRp3_28_3398878(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_28_3398878!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_28_3398878!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_28_3398878!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_inTRp3_28_3398878(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Signal inTRp3_28_3398878!");
		std::cout<<"ERROR: Unexpected Signal inTRp3_28_3398878!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Signal inTRp3_28_3398878!", UNEXPECTED_EVENT));
	}
	
	// Notifications
	virtual void V1_outTRp1_1_3398718(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_1_3398718!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_1_3398718!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_1_3398718!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp1_1_3398718(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_1_3398718 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_1_3398718 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_1_3398718 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp1_1_3398718(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_1_3398718 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_1_3398718 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_1_3398718 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp1_1_3398719(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_1_3398719!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_1_3398719!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_1_3398719!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp1_1_3398719(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_1_3398719 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_1_3398719 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_1_3398719 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp1_1_3398719(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_1_3398719 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_1_3398719 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_1_3398719 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp1_1_3398720(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_1_3398720!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_1_3398720!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_1_3398720!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp1_1_3398720(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_1_3398720 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_1_3398720 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_1_3398720 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp1_1_3398720(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_1_3398720 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_1_3398720 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_1_3398720 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp3_1_3398724(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_1_3398724!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_1_3398724!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_1_3398724!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp3_1_3398724(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_1_3398724 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_1_3398724 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_1_3398724 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp3_1_3398724(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_1_3398724 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_1_3398724 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_1_3398724 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp1_4_3398725(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_4_3398725!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_4_3398725!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_4_3398725!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp1_4_3398725(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_4_3398725 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_4_3398725 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_4_3398725 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp1_4_3398725(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_4_3398725 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_4_3398725 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_4_3398725 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp3_3_3398727(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_3_3398727!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_3_3398727!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_3_3398727!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp3_3_3398727(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_3_3398727 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_3_3398727 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_3_3398727 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp3_3_3398727(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_3_3398727 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_3_3398727 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_3_3398727 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp3_5_3398730(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_5_3398730!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_5_3398730!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_5_3398730!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp3_5_3398730(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_5_3398730 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_5_3398730 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_5_3398730 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp3_5_3398730(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_5_3398730 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_5_3398730 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_5_3398730 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp3_4_3398731(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_4_3398731!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_4_3398731!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_4_3398731!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp3_4_3398731(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_4_3398731 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_4_3398731 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_4_3398731 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp3_4_3398731(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_4_3398731 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_4_3398731 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_4_3398731 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp3_5_3398733(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_5_3398733!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_5_3398733!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_5_3398733!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp3_5_3398733(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_5_3398733 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_5_3398733 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_5_3398733 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp3_5_3398733(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_5_3398733 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_5_3398733 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_5_3398733 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp3_2_3398735(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_2_3398735!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_2_3398735!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_2_3398735!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp3_2_3398735(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_2_3398735 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_2_3398735 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_2_3398735 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp3_2_3398735(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_2_3398735 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_2_3398735 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_2_3398735 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp3_3_3398736(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_3_3398736!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_3_3398736!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_3_3398736!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp3_3_3398736(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_3_3398736 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_3_3398736 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_3_3398736 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp3_3_3398736(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_3_3398736 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_3_3398736 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_3_3398736 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp1_1_3398738(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_1_3398738!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_1_3398738!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_1_3398738!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp1_1_3398738(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_1_3398738 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_1_3398738 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_1_3398738 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp1_1_3398738(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_1_3398738 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_1_3398738 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_1_3398738 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp2_3_3398740(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp2_3_3398740!");
		std::cout<<"ERROR: Unexpected Notification outTRp2_3_3398740!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp2_3_3398740!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp2_3_3398740(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp2_3_3398740 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp2_3_3398740 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp2_3_3398740 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp2_3_3398740(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp2_3_3398740 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp2_3_3398740 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp2_3_3398740 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp4_1_3398744(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp4_1_3398744!");
		std::cout<<"ERROR: Unexpected Notification outTRp4_1_3398744!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp4_1_3398744!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp4_1_3398744(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp4_1_3398744 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp4_1_3398744 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp4_1_3398744 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp4_1_3398744(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp4_1_3398744 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp4_1_3398744 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp4_1_3398744 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp5_1_3398745(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp5_1_3398745!");
		std::cout<<"ERROR: Unexpected Notification outTRp5_1_3398745!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp5_1_3398745!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp5_1_3398745(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp5_1_3398745 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp5_1_3398745 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp5_1_3398745 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp5_1_3398745(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp5_1_3398745 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp5_1_3398745 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp5_1_3398745 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp3_10_3398748(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_10_3398748!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_10_3398748!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_10_3398748!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp3_10_3398748(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_10_3398748 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_10_3398748 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_10_3398748 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp3_10_3398748(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_10_3398748 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_10_3398748 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_10_3398748 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp1_6_3398756(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_6_3398756!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_6_3398756!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_6_3398756!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp1_6_3398756(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_6_3398756 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_6_3398756 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_6_3398756 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp1_6_3398756(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_6_3398756 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_6_3398756 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_6_3398756 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp1_4_3398759(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_4_3398759!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_4_3398759!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_4_3398759!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp1_4_3398759(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_4_3398759 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_4_3398759 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_4_3398759 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp1_4_3398759(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_4_3398759 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_4_3398759 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_4_3398759 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp3_6_3398761(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_6_3398761!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_6_3398761!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_6_3398761!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp3_6_3398761(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_6_3398761 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_6_3398761 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_6_3398761 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp3_6_3398761(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_6_3398761 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_6_3398761 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_6_3398761 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp2_6_3398762(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp2_6_3398762!");
		std::cout<<"ERROR: Unexpected Notification outTRp2_6_3398762!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp2_6_3398762!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp2_6_3398762(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp2_6_3398762 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp2_6_3398762 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp2_6_3398762 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp2_6_3398762(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp2_6_3398762 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp2_6_3398762 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp2_6_3398762 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp3_4_3398763(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_4_3398763!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_4_3398763!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_4_3398763!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp3_4_3398763(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_4_3398763 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_4_3398763 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_4_3398763 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp3_4_3398763(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_4_3398763 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_4_3398763 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_4_3398763 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp3_11_3398764(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_11_3398764!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_11_3398764!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_11_3398764!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp3_11_3398764(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_11_3398764 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_11_3398764 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_11_3398764 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp3_11_3398764(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_11_3398764 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_11_3398764 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_11_3398764 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp3_8_3398766(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_8_3398766!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_8_3398766!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_8_3398766!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp3_8_3398766(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_8_3398766 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_8_3398766 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_8_3398766 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp3_8_3398766(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_8_3398766 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_8_3398766 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_8_3398766 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp1_10_3398769(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_10_3398769!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_10_3398769!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_10_3398769!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp1_10_3398769(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_10_3398769 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_10_3398769 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_10_3398769 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp1_10_3398769(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_10_3398769 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_10_3398769 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_10_3398769 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp3_12_3398771(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_12_3398771!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_12_3398771!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_12_3398771!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp3_12_3398771(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_12_3398771 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_12_3398771 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_12_3398771 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp3_12_3398771(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_12_3398771 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_12_3398771 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_12_3398771 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp6_1_3398773(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp6_1_3398773!");
		std::cout<<"ERROR: Unexpected Notification outTRp6_1_3398773!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp6_1_3398773!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp6_1_3398773(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp6_1_3398773 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp6_1_3398773 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp6_1_3398773 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp6_1_3398773(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp6_1_3398773 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp6_1_3398773 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp6_1_3398773 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp7_1_3398775(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp7_1_3398775!");
		std::cout<<"ERROR: Unexpected Notification outTRp7_1_3398775!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp7_1_3398775!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp7_1_3398775(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp7_1_3398775 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp7_1_3398775 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp7_1_3398775 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp7_1_3398775(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp7_1_3398775 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp7_1_3398775 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp7_1_3398775 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp5_2_3398777(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp5_2_3398777!");
		std::cout<<"ERROR: Unexpected Notification outTRp5_2_3398777!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp5_2_3398777!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp5_2_3398777(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp5_2_3398777 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp5_2_3398777 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp5_2_3398777 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp5_2_3398777(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp5_2_3398777 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp5_2_3398777 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp5_2_3398777 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp1_6_3398778(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_6_3398778!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_6_3398778!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_6_3398778!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp1_6_3398778(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_6_3398778 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_6_3398778 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_6_3398778 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp1_6_3398778(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_6_3398778 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_6_3398778 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_6_3398778 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp3_7_3398779(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_7_3398779!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_7_3398779!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_7_3398779!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp3_7_3398779(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_7_3398779 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_7_3398779 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_7_3398779 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp3_7_3398779(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_7_3398779 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_7_3398779 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_7_3398779 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp1_14_3398782(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_14_3398782!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_14_3398782!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_14_3398782!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp1_14_3398782(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_14_3398782 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_14_3398782 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_14_3398782 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp1_14_3398782(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_14_3398782 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_14_3398782 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_14_3398782 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp1_3_3398784(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_3_3398784!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_3_3398784!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_3_3398784!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp1_3_3398784(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_3_3398784 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_3_3398784 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_3_3398784 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp1_3_3398784(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_3_3398784 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_3_3398784 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_3_3398784 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp8_1_3398788(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp8_1_3398788!");
		std::cout<<"ERROR: Unexpected Notification outTRp8_1_3398788!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp8_1_3398788!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp8_1_3398788(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp8_1_3398788 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp8_1_3398788 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp8_1_3398788 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp8_1_3398788(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp8_1_3398788 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp8_1_3398788 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp8_1_3398788 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp9_1_3398789(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp9_1_3398789!");
		std::cout<<"ERROR: Unexpected Notification outTRp9_1_3398789!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp9_1_3398789!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp9_1_3398789(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp9_1_3398789 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp9_1_3398789 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp9_1_3398789 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp9_1_3398789(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp9_1_3398789 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp9_1_3398789 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp9_1_3398789 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp1_17_3398791(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_17_3398791!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_17_3398791!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_17_3398791!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp1_17_3398791(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_17_3398791 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_17_3398791 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_17_3398791 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp1_17_3398791(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_17_3398791 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_17_3398791 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_17_3398791 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp1_7_3398793(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_7_3398793!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_7_3398793!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_7_3398793!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp1_7_3398793(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_7_3398793 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_7_3398793 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_7_3398793 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp1_7_3398793(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_7_3398793 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_7_3398793 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_7_3398793 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp1_7_3398794(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_7_3398794!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_7_3398794!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_7_3398794!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp1_7_3398794(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_7_3398794 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_7_3398794 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_7_3398794 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp1_7_3398794(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_7_3398794 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_7_3398794 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_7_3398794 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp1_4_3398797(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_4_3398797!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_4_3398797!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_4_3398797!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp1_4_3398797(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_4_3398797 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_4_3398797 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_4_3398797 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp1_4_3398797(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_4_3398797 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_4_3398797 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_4_3398797 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp3_29_3398799(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_29_3398799!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_29_3398799!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_29_3398799!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp3_29_3398799(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_29_3398799 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_29_3398799 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_29_3398799 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp3_29_3398799(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_29_3398799 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_29_3398799 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_29_3398799 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp9_2_3398801(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp9_2_3398801!");
		std::cout<<"ERROR: Unexpected Notification outTRp9_2_3398801!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp9_2_3398801!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp9_2_3398801(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp9_2_3398801 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp9_2_3398801 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp9_2_3398801 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp9_2_3398801(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp9_2_3398801 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp9_2_3398801 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp9_2_3398801 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp3_13_3398802(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_13_3398802!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_13_3398802!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_13_3398802!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp3_13_3398802(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_13_3398802 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_13_3398802 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_13_3398802 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp3_13_3398802(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_13_3398802 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_13_3398802 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_13_3398802 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp1_7_3398804(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_7_3398804!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_7_3398804!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_7_3398804!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp1_7_3398804(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_7_3398804 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_7_3398804 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_7_3398804 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp1_7_3398804(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_7_3398804 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_7_3398804 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_7_3398804 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp3_32_3398806(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_32_3398806!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_32_3398806!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_32_3398806!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp3_32_3398806(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_32_3398806 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_32_3398806 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_32_3398806 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp3_32_3398806(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_32_3398806 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_32_3398806 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_32_3398806 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp1_20_3398809(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_20_3398809!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_20_3398809!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_20_3398809!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp1_20_3398809(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_20_3398809 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_20_3398809 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_20_3398809 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp1_20_3398809(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_20_3398809 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_20_3398809 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_20_3398809 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp9_3_3398810(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp9_3_3398810!");
		std::cout<<"ERROR: Unexpected Notification outTRp9_3_3398810!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp9_3_3398810!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp9_3_3398810(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp9_3_3398810 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp9_3_3398810 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp9_3_3398810 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp9_3_3398810(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp9_3_3398810 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp9_3_3398810 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp9_3_3398810 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp1_1_3398811(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_1_3398811!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_1_3398811!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_1_3398811!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp1_1_3398811(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_1_3398811 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_1_3398811 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_1_3398811 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp1_1_3398811(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_1_3398811 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_1_3398811 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_1_3398811 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp1_9_3398815(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_9_3398815!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_9_3398815!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_9_3398815!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp1_9_3398815(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_9_3398815 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_9_3398815 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_9_3398815 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp1_9_3398815(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_9_3398815 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_9_3398815 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_9_3398815 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp5_4_3398816(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp5_4_3398816!");
		std::cout<<"ERROR: Unexpected Notification outTRp5_4_3398816!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp5_4_3398816!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp5_4_3398816(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp5_4_3398816 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp5_4_3398816 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp5_4_3398816 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp5_4_3398816(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp5_4_3398816 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp5_4_3398816 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp5_4_3398816 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp5_4_3398817(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp5_4_3398817!");
		std::cout<<"ERROR: Unexpected Notification outTRp5_4_3398817!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp5_4_3398817!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp5_4_3398817(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp5_4_3398817 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp5_4_3398817 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp5_4_3398817 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp5_4_3398817(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp5_4_3398817 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp5_4_3398817 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp5_4_3398817 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp1_25_3398820(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_25_3398820!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_25_3398820!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_25_3398820!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp1_25_3398820(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_25_3398820 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_25_3398820 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_25_3398820 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp1_25_3398820(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_25_3398820 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_25_3398820 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_25_3398820 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp2_10_3398821(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp2_10_3398821!");
		std::cout<<"ERROR: Unexpected Notification outTRp2_10_3398821!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp2_10_3398821!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp2_10_3398821(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp2_10_3398821 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp2_10_3398821 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp2_10_3398821 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp2_10_3398821(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp2_10_3398821 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp2_10_3398821 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp2_10_3398821 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp1_26_3398822(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_26_3398822!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_26_3398822!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_26_3398822!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp1_26_3398822(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_26_3398822 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_26_3398822 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_26_3398822 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp1_26_3398822(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_26_3398822 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_26_3398822 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_26_3398822 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp11_1_3398824(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp11_1_3398824!");
		std::cout<<"ERROR: Unexpected Notification outTRp11_1_3398824!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp11_1_3398824!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp11_1_3398824(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp11_1_3398824 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp11_1_3398824 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp11_1_3398824 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp11_1_3398824(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp11_1_3398824 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp11_1_3398824 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp11_1_3398824 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp9_1_3398829(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp9_1_3398829!");
		std::cout<<"ERROR: Unexpected Notification outTRp9_1_3398829!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp9_1_3398829!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp9_1_3398829(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp9_1_3398829 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp9_1_3398829 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp9_1_3398829 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp9_1_3398829(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp9_1_3398829 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp9_1_3398829 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp9_1_3398829 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp3_2_3398830(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_2_3398830!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_2_3398830!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_2_3398830!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp3_2_3398830(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_2_3398830 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_2_3398830 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_2_3398830 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp3_2_3398830(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_2_3398830 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_2_3398830 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_2_3398830 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp9_5_3398831(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp9_5_3398831!");
		std::cout<<"ERROR: Unexpected Notification outTRp9_5_3398831!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp9_5_3398831!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp9_5_3398831(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp9_5_3398831 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp9_5_3398831 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp9_5_3398831 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp9_5_3398831(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp9_5_3398831 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp9_5_3398831 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp9_5_3398831 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp1_21_3398832(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_21_3398832!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_21_3398832!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_21_3398832!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp1_21_3398832(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_21_3398832 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_21_3398832 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_21_3398832 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp1_21_3398832(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_21_3398832 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_21_3398832 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_21_3398832 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp3_29_3398835(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_29_3398835!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_29_3398835!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_29_3398835!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp3_29_3398835(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_29_3398835 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_29_3398835 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_29_3398835 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp3_29_3398835(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_29_3398835 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_29_3398835 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_29_3398835 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp3_21_3398836(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_21_3398836!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_21_3398836!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_21_3398836!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp3_21_3398836(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_21_3398836 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_21_3398836 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_21_3398836 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp3_21_3398836(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_21_3398836 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_21_3398836 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_21_3398836 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp1_20_3398837(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_20_3398837!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_20_3398837!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_20_3398837!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp1_20_3398837(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_20_3398837 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_20_3398837 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_20_3398837 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp1_20_3398837(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_20_3398837 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_20_3398837 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_20_3398837 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp4_2_3398839(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp4_2_3398839!");
		std::cout<<"ERROR: Unexpected Notification outTRp4_2_3398839!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp4_2_3398839!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp4_2_3398839(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp4_2_3398839 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp4_2_3398839 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp4_2_3398839 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp4_2_3398839(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp4_2_3398839 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp4_2_3398839 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp4_2_3398839 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp3_8_3398840(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_8_3398840!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_8_3398840!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_8_3398840!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp3_8_3398840(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_8_3398840 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_8_3398840 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_8_3398840 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp3_8_3398840(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_8_3398840 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_8_3398840 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_8_3398840 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp3_4_3398843(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_4_3398843!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_4_3398843!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_4_3398843!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp3_4_3398843(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_4_3398843 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_4_3398843 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_4_3398843 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp3_4_3398843(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_4_3398843 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_4_3398843 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_4_3398843 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp1_5_3398844(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_5_3398844!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_5_3398844!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_5_3398844!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp1_5_3398844(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_5_3398844 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_5_3398844 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_5_3398844 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp1_5_3398844(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_5_3398844 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_5_3398844 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_5_3398844 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp3_44_3398845(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_44_3398845!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_44_3398845!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_44_3398845!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp3_44_3398845(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_44_3398845 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_44_3398845 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_44_3398845 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp3_44_3398845(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_44_3398845 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_44_3398845 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_44_3398845 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp1_12_3398846(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_12_3398846!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_12_3398846!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_12_3398846!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp1_12_3398846(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_12_3398846 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_12_3398846 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_12_3398846 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp1_12_3398846(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_12_3398846 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_12_3398846 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_12_3398846 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp2_9_3398848(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp2_9_3398848!");
		std::cout<<"ERROR: Unexpected Notification outTRp2_9_3398848!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp2_9_3398848!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp2_9_3398848(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp2_9_3398848 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp2_9_3398848 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp2_9_3398848 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp2_9_3398848(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp2_9_3398848 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp2_9_3398848 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp2_9_3398848 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp2_7_3398851(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp2_7_3398851!");
		std::cout<<"ERROR: Unexpected Notification outTRp2_7_3398851!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp2_7_3398851!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp2_7_3398851(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp2_7_3398851 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp2_7_3398851 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp2_7_3398851 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp2_7_3398851(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp2_7_3398851 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp2_7_3398851 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp2_7_3398851 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp3_13_3398852(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_13_3398852!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_13_3398852!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_13_3398852!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp3_13_3398852(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_13_3398852 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_13_3398852 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_13_3398852 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp3_13_3398852(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_13_3398852 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_13_3398852 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_13_3398852 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp3_40_3398853(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_40_3398853!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_40_3398853!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_40_3398853!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp3_40_3398853(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_40_3398853 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_40_3398853 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_40_3398853 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp3_40_3398853(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_40_3398853 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_40_3398853 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_40_3398853 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp3_40_3398855(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_40_3398855!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_40_3398855!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_40_3398855!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp3_40_3398855(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_40_3398855 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_40_3398855 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_40_3398855 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp3_40_3398855(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_40_3398855 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_40_3398855 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_40_3398855 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp3_6_3398857(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_6_3398857!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_6_3398857!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_6_3398857!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp3_6_3398857(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_6_3398857 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_6_3398857 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_6_3398857 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp3_6_3398857(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_6_3398857 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_6_3398857 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_6_3398857 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp17_1_3398863(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp17_1_3398863!");
		std::cout<<"ERROR: Unexpected Notification outTRp17_1_3398863!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp17_1_3398863!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp17_1_3398863(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp17_1_3398863 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp17_1_3398863 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp17_1_3398863 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp17_1_3398863(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp17_1_3398863 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp17_1_3398863 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp17_1_3398863 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp1_3_3398866(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_3_3398866!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_3_3398866!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_3_3398866!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp1_3_3398866(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_3_3398866 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_3_3398866 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_3_3398866 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp1_3_3398866(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_3_3398866 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_3_3398866 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_3_3398866 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp3_10_3398867(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_10_3398867!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_10_3398867!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_10_3398867!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp3_10_3398867(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_10_3398867 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_10_3398867 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_10_3398867 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp3_10_3398867(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp3_10_3398867 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp3_10_3398867 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp3_10_3398867 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp4_3_3398869(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp4_3_3398869!");
		std::cout<<"ERROR: Unexpected Notification outTRp4_3_3398869!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp4_3_3398869!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp4_3_3398869(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp4_3_3398869 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp4_3_3398869 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp4_3_3398869 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp4_3_3398869(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp4_3_3398869 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp4_3_3398869 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp4_3_3398869 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp9_1_3398870(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp9_1_3398870!");
		std::cout<<"ERROR: Unexpected Notification outTRp9_1_3398870!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp9_1_3398870!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp9_1_3398870(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp9_1_3398870 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp9_1_3398870 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp9_1_3398870 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp9_1_3398870(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp9_1_3398870 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp9_1_3398870 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp9_1_3398870 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp4_2_3398873(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp4_2_3398873!");
		std::cout<<"ERROR: Unexpected Notification outTRp4_2_3398873!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp4_2_3398873!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp4_2_3398873(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp4_2_3398873 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp4_2_3398873 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp4_2_3398873 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp4_2_3398873(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp4_2_3398873 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp4_2_3398873 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp4_2_3398873 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp2_1_3398874(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp2_1_3398874!");
		std::cout<<"ERROR: Unexpected Notification outTRp2_1_3398874!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp2_1_3398874!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp2_1_3398874(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp2_1_3398874 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp2_1_3398874 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp2_1_3398874 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp2_1_3398874(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp2_1_3398874 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp2_1_3398874 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp2_1_3398874 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp19_1_3398877(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp19_1_3398877!");
		std::cout<<"ERROR: Unexpected Notification outTRp19_1_3398877!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp19_1_3398877!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp19_1_3398877(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp19_1_3398877 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp19_1_3398877 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp19_1_3398877 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp19_1_3398877(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp19_1_3398877 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp19_1_3398877 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp19_1_3398877 in a Deterministic Context!", UNEXPECTED_EVENT));
	}
	virtual void V1_outTRp1_10_3398879(V1_StateMachineController *smc)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_10_3398879!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_10_3398879!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_10_3398879!", UNEXPECTED_EVENT));
	}
	
	virtual std::vector<int> match_V1_outTRp1_10_3398879(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_10_3398879 Matching Request was Received!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_10_3398879 Matching Request was Received!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_10_3398879 Matching Request was Received!", UNEXPECTED_EVENT));
	}
	
	virtual void V1_outTRp1_10_3398879(V1_StateMachineController *smc, int instance_id, int clause_id)
	{
		smc->event_status_msg.push_back("ERROR: Unexpected Notification outTRp1_10_3398879 in a Deterministic Context!");
		std::cout<<"ERROR: Unexpected Notification outTRp1_10_3398879 in a Deterministic Context!"<<std::endl;
		//throw (StubException("EXCEPTION: Unexpected Notification outTRp1_10_3398879 in a Deterministic Context!", UNEXPECTED_EVENT));
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
	
	p1_1(){ name = "p1_1"; expected_ni_list = { {  "V1_outTRp1_1_3398811"  }  }; }
	~p1_1(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p1_1
	void V1_outTRp1_1_3398811(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp1_1_3398811(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp1_1_3398811(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp1_1_3398811

	//enum notifications { _V1_outTRp1_1_3398811, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p1_43: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_43(){ name = "p1_43"; expected_ni_list = { }; }
	~p1_43(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p1_43
	void V1_inTRp1_31_3398828(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp1_31_3398828(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp1_31_3398828(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp1_31_3398828(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p1_35: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_35(){ name = "p1_35"; expected_ni_list = { {  "V1_outTRp1_20_3398809"  }  }; }
	~p1_35(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p1_35
	void V1_outTRp1_20_3398809(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp1_20_3398809(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp1_20_3398809(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp1_20_3398809

	//enum notifications { _V1_outTRp1_20_3398809, END };

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
	
	p2_1(){ name = "p2_1"; expected_ni_list = { {  "V1_outTRp2_1_3398874"  }  }; }
	~p2_1(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p2_1
	void V1_outTRp2_1_3398874(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp2_1_3398874(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp2_1_3398874(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp2_1_3398874

	//enum notifications { _V1_outTRp2_1_3398874, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_1: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_1(){ name = "p3_1"; expected_ni_list = { {  "V1_outTRp3_1_3398724"  }  }; }
	~p3_1(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p3_1
	void V1_outTRp3_1_3398724(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp3_1_3398724(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp3_1_3398724(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp3_1_3398724

	//enum notifications { _V1_outTRp3_1_3398724, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p1_24: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_24(){ name = "p1_24"; expected_ni_list = { {  "V1_outTRp1_6_3398778"  }  }; }
	~p1_24(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p1_24
	void V1_outTRp1_6_3398778(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp1_6_3398778(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp1_6_3398778(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp1_6_3398778

	//enum notifications { _V1_outTRp1_6_3398778, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_2: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_2(){ name = "p3_2"; expected_ni_list = { {  "V1_outTRp3_2_3398830"  }  }; }
	~p3_2(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p3_2
	void V1_outTRp3_2_3398830(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp3_2_3398830(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp3_2_3398830(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp3_2_3398830

	//enum notifications { _V1_outTRp3_2_3398830, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_40: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_40(){ name = "p3_40"; expected_ni_list = { }; }
	~p3_40(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p3_40
	void V1_inTRp3_9_3398751(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp3_9_3398751(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp3_9_3398751(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp3_9_3398751(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_34: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_34(){ name = "p3_34"; expected_ni_list = { {  "V1_outTRp3_11_3398764"  }  }; }
	~p3_34(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p3_34
	void V1_outTRp3_11_3398764(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp3_11_3398764(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp3_11_3398764(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp3_11_3398764

	//enum notifications { _V1_outTRp3_11_3398764, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p2_17: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p2_17(){ name = "p2_17"; expected_ni_list = { {  "V1_outTRp2_10_3398821"  }  }; }
	~p2_17(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p2_17
	void V1_outTRp2_10_3398821(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp2_10_3398821(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp2_10_3398821(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp2_10_3398821

	//enum notifications { _V1_outTRp2_10_3398821, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_52: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_52(){ name = "p3_52"; expected_ni_list = { }; }
	~p3_52(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p3_52
	void V1_inTRp3_1_3398722(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp3_1_3398722(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp3_1_3398722(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp3_1_3398722(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_50: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_50(){ name = "p3_50"; expected_ni_list = { {  "V1_outTRp3_44_3398845"  }  }; }
	~p3_50(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p3_50
	void V1_outTRp3_44_3398845(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp3_44_3398845(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp3_44_3398845(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp3_44_3398845

	//enum notifications { _V1_outTRp3_44_3398845, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_42: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_42(){ name = "p3_42"; expected_ni_list = { }; }
	~p3_42(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p3_42
	void V1_inTRp3_5_3398734(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp3_5_3398734(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp3_5_3398734(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp3_5_3398734(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p2_7: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p2_7(){ name = "p2_7"; expected_ni_list = { }; }
	~p2_7(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p2_7
	void V1_inTRp2_5_3398826(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp2_5_3398826(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp2_5_3398826(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp2_5_3398826(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_48: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_48(){ name = "p3_48"; expected_ni_list = { }; }
	~p3_48(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p3_48
	void V1_inTRp3_10_3398741(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp3_10_3398741(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp3_10_3398741(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp3_10_3398741(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_43: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_43(){ name = "p3_43"; expected_ni_list = { }; }
	~p3_43(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p3_43
	void V1_inTRp3_9_3398747(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp3_9_3398747(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp3_9_3398747(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp3_9_3398747(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_6: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_6(){ name = "p3_6"; expected_ni_list = { {  "V1_outTRp3_3_3398736"  } , {  "V1_outTRp3_6_3398857"  }  }; }
	~p3_6(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p3_6
	void V1_outTRp3_6_3398857(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp3_6_3398857(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp3_6_3398857(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp3_6_3398857
	// Possible Notification in State: p3_6
	void V1_outTRp3_3_3398736(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp3_3_3398736(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp3_3_3398736(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp3_3_3398736

	//enum notifications { _V1_outTRp3_3_3398736,  _V1_outTRp3_6_3398857, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_26: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_26(){ name = "p3_26"; expected_ni_list = { {  "V1_outTRp3_21_3398836"  }  }; }
	~p3_26(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p3_26
	void V1_outTRp3_21_3398836(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp3_21_3398836(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp3_21_3398836(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp3_21_3398836

	//enum notifications { _V1_outTRp3_21_3398836, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_7: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_7(){ name = "p3_7"; expected_ni_list = { {  "V1_outTRp3_4_3398763"  }  }; }
	~p3_7(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p3_7
	void V1_outTRp3_4_3398763(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp3_4_3398763(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp3_4_3398763(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp3_4_3398763

	//enum notifications { _V1_outTRp3_4_3398763, END };

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
	
	p1_5(){ name = "p1_5"; expected_ni_list = { }; }
	~p1_5(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p1_5
	void V1_inTRp1_2_3398783(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp1_2_3398783(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp1_2_3398783(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp1_2_3398783(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p2_16: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p2_16(){ name = "p2_16"; expected_ni_list = { }; }
	~p2_16(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p2_16
	void V1_inTRp2_1_3398728(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp2_1_3398728(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp2_1_3398728(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp2_1_3398728(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p2_12: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p2_12(){ name = "p2_12"; expected_ni_list = { }; }
	~p2_12(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p2_12
	void V1_inTRp2_8_3398847(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp2_8_3398847(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp2_8_3398847(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp2_8_3398847(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_49: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_49(){ name = "p3_49"; expected_ni_list = { }; }
	~p3_49(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p3_49
	void V1_inTRp3_26_3398774(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp3_26_3398774(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp3_26_3398774(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp3_26_3398774(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);
	// Enabled Signal in State: p3_49
	void V1_inTRp3_4_3398729(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp3_4_3398729(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp3_4_3398729(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp3_4_3398729(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p1_13: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_13(){ name = "p1_13"; expected_ni_list = { }; }
	~p1_13(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p1_13
	void V1_inTRp1_10_3398849(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp1_10_3398849(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp1_10_3398849(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp1_10_3398849(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p4_1: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p4_1(){ name = "p4_1"; expected_ni_list = { }; }
	~p4_1(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p4_1
	void V1_inTRp4_1_3398876(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp4_1_3398876(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp4_1_3398876(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp4_1_3398876(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);
	// Enabled Signal in State: p4_1
	void V1_inTRp4_1_3398838(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp4_1_3398838(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp4_1_3398838(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp4_1_3398838(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p5_1: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p5_1(){ name = "p5_1"; expected_ni_list = { }; }
	~p5_1(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p5_1
	void V1_inTRp5_1_3398776(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp5_1_3398776(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp5_1_3398776(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp5_1_3398776(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p1_26: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_26(){ name = "p1_26"; expected_ni_list = { }; }
	~p1_26(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p1_26
	void V1_inTRp1_5_3398755(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp1_5_3398755(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp1_5_3398755(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp1_5_3398755(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_45: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_45(){ name = "p3_45"; expected_ni_list = { {  "V1_outTRp3_29_3398799"  } , {  "V1_outTRp3_40_3398853"  } , {  "V1_outTRp3_40_3398855"  }  }; }
	~p3_45(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p3_45
	void V1_outTRp3_40_3398855(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp3_40_3398855(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp3_40_3398855(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp3_40_3398855
	// Possible Notification in State: p3_45
	void V1_outTRp3_40_3398853(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp3_40_3398853(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp3_40_3398853(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp3_40_3398853
	// Possible Notification in State: p3_45
	void V1_outTRp3_29_3398799(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp3_29_3398799(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp3_29_3398799(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp3_29_3398799

	//enum notifications { _V1_outTRp3_29_3398799,  _V1_outTRp3_40_3398853,  _V1_outTRp3_40_3398855, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_44: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_44(){ name = "p3_44"; expected_ni_list = { {  "V1_outTRp3_10_3398748"  }  }; }
	~p3_44(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p3_44
	void V1_outTRp3_10_3398748(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp3_10_3398748(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp3_10_3398748(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp3_10_3398748

	//enum notifications { _V1_outTRp3_10_3398748, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_32: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_32(){ name = "p3_32"; expected_ni_list = { }; }
	~p3_32(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p3_32
	void V1_inTRp3_18_3398798(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp3_18_3398798(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp3_18_3398798(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp3_18_3398798(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_9: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_9(){ name = "p3_9"; expected_ni_list = { }; }
	~p3_9(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p3_9
	void V1_inTRp3_5_3398760(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp3_5_3398760(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp3_5_3398760(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp3_5_3398760(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_41: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_41(){ name = "p3_41"; expected_ni_list = { {  "V1_outTRp3_4_3398731"  }  }; }
	~p3_41(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p3_41
	void V1_outTRp3_4_3398731(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp3_4_3398731(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp3_4_3398731(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp3_4_3398731

	//enum notifications { _V1_outTRp3_4_3398731, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_37: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_37(){ name = "p3_37"; expected_ni_list = { {  "V1_outTRp3_29_3398835"  }  }; }
	~p3_37(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p3_37
	void V1_outTRp3_29_3398835(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp3_29_3398835(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp3_29_3398835(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp3_29_3398835

	//enum notifications { _V1_outTRp3_29_3398835, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p2_5: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p2_5(){ name = "p2_5"; expected_ni_list = { }; }
	~p2_5(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p2_5
	void V1_inTRp2_3_3398781(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp2_3_3398781(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp2_3_3398781(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp2_3_3398781(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p2_11: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p2_11(){ name = "p2_11"; expected_ni_list = { }; }
	~p2_11(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p2_11
	void V1_inTRp2_2_3398739(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp2_2_3398739(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp2_2_3398739(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp2_2_3398739(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p1_31: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_31(){ name = "p1_31"; expected_ni_list = { {  "V1_outTRp1_21_3398832"  }  }; }
	~p1_31(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p1_31
	void V1_outTRp1_21_3398832(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp1_21_3398832(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp1_21_3398832(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp1_21_3398832

	//enum notifications { _V1_outTRp1_21_3398832, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p1_27: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_27(){ name = "p1_27"; expected_ni_list = { }; }
	~p1_27(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p1_27
	void V1_inTRp1_24_3398861(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp1_24_3398861(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp1_24_3398861(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp1_24_3398861(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p2_4: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p2_4(){ name = "p2_4"; expected_ni_list = { }; }
	~p2_4(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p2_4
	void V1_inTRp2_1_3398753(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp2_1_3398753(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp2_1_3398753(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp2_1_3398753(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p1_20: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_20(){ name = "p1_20"; expected_ni_list = { }; }
	~p1_20(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p1_20
	void V1_inTRp1_9_3398808(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp1_9_3398808(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp1_9_3398808(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp1_9_3398808(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p1_15: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_15(){ name = "p1_15"; expected_ni_list = { {  "V1_outTRp1_9_3398815"  }  }; }
	~p1_15(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p1_15
	void V1_outTRp1_9_3398815(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp1_9_3398815(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp1_9_3398815(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp1_9_3398815

	//enum notifications { _V1_outTRp1_9_3398815, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_14: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_14(){ name = "p3_14"; expected_ni_list = { {  "V1_outTRp3_13_3398852"  }  }; }
	~p3_14(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p3_14
	void V1_outTRp3_13_3398852(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp3_13_3398852(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp3_13_3398852(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp3_13_3398852

	//enum notifications { _V1_outTRp3_13_3398852, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_10: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_10(){ name = "p3_10"; expected_ni_list = { {  "V1_outTRp3_10_3398867"  }  }; }
	~p3_10(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p3_10
	void V1_outTRp3_10_3398867(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp3_10_3398867(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp3_10_3398867(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp3_10_3398867

	//enum notifications { _V1_outTRp3_10_3398867, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p2_15: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p2_15(){ name = "p2_15"; expected_ni_list = { {  "V1_outTRp2_3_3398740"  }  }; }
	~p2_15(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p2_15
	void V1_outTRp2_3_3398740(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp2_3_3398740(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp2_3_3398740(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp2_3_3398740

	//enum notifications { _V1_outTRp2_3_3398740, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_8: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_8(){ name = "p3_8"; expected_ni_list = { }; }
	~p3_8(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p3_8
	void V1_inTRp3_4_3398750(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp3_4_3398750(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp3_4_3398750(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp3_4_3398750(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_36: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_36(){ name = "p3_36"; expected_ni_list = { }; }
	~p3_36(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p3_36
	void V1_inTRp3_8_3398752(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp3_8_3398752(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp3_8_3398752(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp3_8_3398752(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_35: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_35(){ name = "p3_35"; expected_ni_list = { }; }
	~p3_35(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p3_35
	void V1_inTRp3_12_3398765(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp3_12_3398765(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp3_12_3398765(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp3_12_3398765(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_17: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_17(){ name = "p3_17"; expected_ni_list = { }; }
	~p3_17(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p3_17
	void V1_inTRp3_9_3398768(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp3_9_3398768(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp3_9_3398768(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp3_9_3398768(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p1_30: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_30(){ name = "p1_30"; expected_ni_list = { {  "V1_outTRp1_6_3398756"  }  }; }
	~p1_30(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p1_30
	void V1_outTRp1_6_3398756(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp1_6_3398756(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp1_6_3398756(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp1_6_3398756

	//enum notifications { _V1_outTRp1_6_3398756, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_18: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_18(){ name = "p3_18"; expected_ni_list = { }; }
	~p3_18(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p3_18
	void V1_inTRp3_12_3398786(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp3_12_3398786(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp3_12_3398786(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp3_12_3398786(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);
	// Enabled Signal in State: p3_18
	void V1_inTRp3_12_3398787(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp3_12_3398787(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp3_12_3398787(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp3_12_3398787(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p1_33: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_33(){ name = "p1_33"; expected_ni_list = { }; }
	~p1_33(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p1_33
	void V1_inTRp1_14_3398785(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp1_14_3398785(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp1_14_3398785(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp1_14_3398785(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_30: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_30(){ name = "p3_30"; expected_ni_list = { }; }
	~p3_30(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p3_30
	void V1_inTRp3_27_3398865(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp3_27_3398865(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp3_27_3398865(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp3_27_3398865(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_28: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_28(){ name = "p3_28"; expected_ni_list = { }; }
	~p3_28(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p3_28
	void V1_inTRp3_28_3398878(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp3_28_3398878(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp3_28_3398878(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp3_28_3398878(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p6_1: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p6_1(){ name = "p6_1"; expected_ni_list = { {  "V1_outTRp6_1_3398773"  }  }; }
	~p6_1(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p6_1
	void V1_outTRp6_1_3398773(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp6_1_3398773(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp6_1_3398773(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp6_1_3398773

	//enum notifications { _V1_outTRp6_1_3398773, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p7_1: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p7_1(){ name = "p7_1"; expected_ni_list = { {  "V1_outTRp7_1_3398775"  }  }; }
	~p7_1(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p7_1
	void V1_outTRp7_1_3398775(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp7_1_3398775(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp7_1_3398775(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp7_1_3398775

	//enum notifications { _V1_outTRp7_1_3398775, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p5_3: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p5_3(){ name = "p5_3"; expected_ni_list = { }; }
	~p5_3(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p5_3
	void V1_inTRp5_3_3398807(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp5_3_3398807(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp5_3_3398807(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp5_3_3398807(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p5_2: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p5_2(){ name = "p5_2"; expected_ni_list = { {  "V1_outTRp5_2_3398777"  }  }; }
	~p5_2(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p5_2
	void V1_outTRp5_2_3398777(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp5_2_3398777(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp5_2_3398777(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp5_2_3398777

	//enum notifications { _V1_outTRp5_2_3398777, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p1_25: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_25(){ name = "p1_25"; expected_ni_list = { }; }
	~p1_25(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p1_25
	void V1_inTRp1_4_3398746(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp1_4_3398746(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp1_4_3398746(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp1_4_3398746(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_13: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_13(){ name = "p3_13"; expected_ni_list = { {  "V1_outTRp3_6_3398761"  }  }; }
	~p3_13(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p3_13
	void V1_outTRp3_6_3398761(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp3_6_3398761(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp3_6_3398761(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp3_6_3398761

	//enum notifications { _V1_outTRp3_6_3398761, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_12: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_12(){ name = "p3_12"; expected_ni_list = { }; }
	~p3_12(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p3_12
	void V1_inTRp3_8_3398780(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp3_8_3398780(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp3_8_3398780(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp3_8_3398780(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p2_6: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p2_6(){ name = "p2_6"; expected_ni_list = { }; }
	~p2_6(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p2_6
	void V1_inTRp2_1_3398732(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp2_1_3398732(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp2_1_3398732(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp2_1_3398732(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p1_45: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_45(){ name = "p1_45"; expected_ni_list = { {  "V1_outTRp1_4_3398725"  }  }; }
	~p1_45(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p1_45
	void V1_outTRp1_4_3398725(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp1_4_3398725(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp1_4_3398725(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp1_4_3398725

	//enum notifications { _V1_outTRp1_4_3398725, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p1_10: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_10(){ name = "p1_10"; expected_ni_list = { {  "V1_outTRp1_10_3398879"  }  }; }
	~p1_10(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p1_10
	void V1_outTRp1_10_3398879(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp1_10_3398879(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp1_10_3398879(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp1_10_3398879

	//enum notifications { _V1_outTRp1_10_3398879, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p1_6: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_6(){ name = "p1_6"; expected_ni_list = { {  "V1_outTRp1_5_3398844"  }  }; }
	~p1_6(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p1_6
	void V1_outTRp1_5_3398844(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp1_5_3398844(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp1_5_3398844(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp1_5_3398844

	//enum notifications { _V1_outTRp1_5_3398844, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p1_34: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_34(){ name = "p1_34"; expected_ni_list = { {  "V1_outTRp1_1_3398719"  } , {  "V1_outTRp1_1_3398720"  }  }; }
	~p1_34(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p1_34
	void V1_outTRp1_1_3398720(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp1_1_3398720(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp1_1_3398720(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp1_1_3398720
	// Possible Notification in State: p1_34
	void V1_outTRp1_1_3398719(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp1_1_3398719(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp1_1_3398719(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp1_1_3398719

	//enum notifications { _V1_outTRp1_1_3398719,  _V1_outTRp1_1_3398720, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_19: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_19(){ name = "p3_19"; expected_ni_list = { {  "V1_outTRp3_13_3398802"  }  }; }
	~p3_19(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p3_19
	void V1_outTRp3_13_3398802(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp3_13_3398802(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp3_13_3398802(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp3_13_3398802

	//enum notifications { _V1_outTRp3_13_3398802, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p8_1: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p8_1(){ name = "p8_1"; expected_ni_list = { {  "V1_outTRp8_1_3398788"  }  }; }
	~p8_1(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p8_1
	void V1_outTRp8_1_3398788(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp8_1_3398788(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp8_1_3398788(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp8_1_3398788

	//enum notifications { _V1_outTRp8_1_3398788, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p9_1: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p9_1(){ name = "p9_1"; expected_ni_list = { {  "V1_outTRp9_1_3398829"  } , {  "V1_outTRp9_1_3398870"  }  }; }
	~p9_1(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p9_1
	void V1_outTRp9_1_3398870(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp9_1_3398870(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp9_1_3398870(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp9_1_3398870
	// Possible Notification in State: p9_1
	void V1_outTRp9_1_3398829(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp9_1_3398829(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp9_1_3398829(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp9_1_3398829

	//enum notifications { _V1_outTRp9_1_3398829,  _V1_outTRp9_1_3398870, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p1_41: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_41(){ name = "p1_41"; expected_ni_list = { }; }
	~p1_41(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p1_41
	void V1_inTRp1_32_3398834(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp1_32_3398834(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp1_32_3398834(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp1_32_3398834(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p1_37: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_37(){ name = "p1_37"; expected_ni_list = { {  "V1_outTRp1_25_3398820"  }  }; }
	~p1_37(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p1_37
	void V1_outTRp1_25_3398820(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp1_25_3398820(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp1_25_3398820(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp1_25_3398820

	//enum notifications { _V1_outTRp1_25_3398820, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_24: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_24(){ name = "p3_24"; expected_ni_list = { }; }
	~p3_24(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p3_24
	void V1_inTRp3_17_3398814(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp3_17_3398814(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp3_17_3398814(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp3_17_3398814(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p1_23: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_23(){ name = "p1_23"; expected_ni_list = { }; }
	~p1_23(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p1_23
	void V1_inTRp1_1_3398723(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp1_1_3398723(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp1_1_3398723(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp1_1_3398723(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p10_1: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p10_1(){ name = "p10_1"; expected_ni_list = { }; }
	~p10_1(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p10_1
	void V1_inTRp10_1_3398805(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp10_1_3398805(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp10_1_3398805(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp10_1_3398805(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p11_1: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p11_1(){ name = "p11_1"; expected_ni_list = { {  "V1_outTRp11_1_3398824"  }  }; }
	~p11_1(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p11_1
	void V1_outTRp11_1_3398824(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp11_1_3398824(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp11_1_3398824(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp11_1_3398824

	//enum notifications { _V1_outTRp11_1_3398824, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p1_12: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_12(){ name = "p1_12"; expected_ni_list = { }; }
	~p1_12(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p1_12
	void V1_inTRp1_2_3398743(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp1_2_3398743(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp1_2_3398743(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp1_2_3398743(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);
	// Enabled Signal in State: p1_12
	void V1_inTRp1_2_3398742(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp1_2_3398742(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp1_2_3398742(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp1_2_3398742(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_33: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_33(){ name = "p3_33"; expected_ni_list = { }; }
	~p3_33(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p3_33
	void V1_inTRp3_2_3398726(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp3_2_3398726(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp3_2_3398726(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp3_2_3398726(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_46: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_46(){ name = "p3_46"; expected_ni_list = { {  "V1_outTRp3_32_3398806"  }  }; }
	~p3_46(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p3_46
	void V1_outTRp3_32_3398806(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp3_32_3398806(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp3_32_3398806(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp3_32_3398806

	//enum notifications { _V1_outTRp3_32_3398806, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p9_4: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p9_4(){ name = "p9_4"; expected_ni_list = { {  "V1_outTRp9_3_3398810"  }  }; }
	~p9_4(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p9_4
	void V1_outTRp9_3_3398810(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp9_3_3398810(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp9_3_3398810(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp9_3_3398810

	//enum notifications { _V1_outTRp9_3_3398810, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p9_3: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p9_3(){ name = "p9_3"; expected_ni_list = { {  "V1_outTRp9_2_3398801"  }  }; }
	~p9_3(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p9_3
	void V1_outTRp9_2_3398801(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp9_2_3398801(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp9_2_3398801(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp9_2_3398801

	//enum notifications { _V1_outTRp9_2_3398801, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_22: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_22(){ name = "p3_22"; expected_ni_list = { }; }
	~p3_22(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p3_22
	void V1_inTRp3_22_3398872(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp3_22_3398872(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp3_22_3398872(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp3_22_3398872(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_20: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_20(){ name = "p3_20"; expected_ni_list = { }; }
	~p3_20(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p3_20
	void V1_inTRp3_15_3398827(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp3_15_3398827(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp3_15_3398827(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp3_15_3398827(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p1_18: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_18(){ name = "p1_18"; expected_ni_list = { }; }
	~p1_18(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p1_18
	void V1_inTRp1_15_3398859(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp1_15_3398859(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp1_15_3398859(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp1_15_3398859(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p10_2: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p10_2(){ name = "p10_2"; expected_ni_list = { }; }
	~p10_2(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p10_2
	void V1_inTRp10_1_3398795(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp10_1_3398795(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp10_1_3398795(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp10_1_3398795(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_47: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_47(){ name = "p3_47"; expected_ni_list = { {  "V1_outTRp3_5_3398733"  }  }; }
	~p3_47(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p3_47
	void V1_outTRp3_5_3398733(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp3_5_3398733(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp3_5_3398733(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp3_5_3398733

	//enum notifications { _V1_outTRp3_5_3398733, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p5_4: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p5_4(){ name = "p5_4"; expected_ni_list = { {  "V1_outTRp5_4_3398816"  } , {  "V1_outTRp5_4_3398817"  }  }; }
	~p5_4(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p5_4
	void V1_outTRp5_4_3398816(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp5_4_3398816(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp5_4_3398816(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp5_4_3398816
	// Possible Notification in State: p5_4
	void V1_outTRp5_4_3398817(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp5_4_3398817(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp5_4_3398817(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp5_4_3398817

	//enum notifications { _V1_outTRp5_4_3398816,  _V1_outTRp5_4_3398817, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p1_21: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_21(){ name = "p1_21"; expected_ni_list = { }; }
	~p1_21(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p1_21
	void V1_inTRp1_14_3398833(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp1_14_3398833(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp1_14_3398833(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp1_14_3398833(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p1_36: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_36(){ name = "p1_36"; expected_ni_list = { }; }
	~p1_36(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p1_36
	void V1_inTRp1_16_3398790(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp1_16_3398790(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp1_16_3398790(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp1_16_3398790(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p9_5: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p9_5(){ name = "p9_5"; expected_ni_list = { {  "V1_outTRp9_5_3398831"  }  }; }
	~p9_5(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p9_5
	void V1_outTRp9_5_3398831(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp9_5_3398831(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp9_5_3398831(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp9_5_3398831

	//enum notifications { _V1_outTRp9_5_3398831, END };

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
	
	p1_3(){ name = "p1_3"; expected_ni_list = { {  "V1_outTRp1_3_3398866"  }  }; }
	~p1_3(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p1_3
	void V1_outTRp1_3_3398866(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp1_3_3398866(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp1_3_3398866(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp1_3_3398866

	//enum notifications { _V1_outTRp1_3_3398866, END };

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
	void V1_inTRp1_2_3398812(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp1_2_3398812(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp1_2_3398812(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp1_2_3398812(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_16: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_16(){ name = "p3_16"; expected_ni_list = { {  "V1_outTRp3_8_3398766"  }  }; }
	~p3_16(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p3_16
	void V1_outTRp3_8_3398766(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp3_8_3398766(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp3_8_3398766(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp3_8_3398766

	//enum notifications { _V1_outTRp3_8_3398766, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_25: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_25(){ name = "p3_25"; expected_ni_list = { }; }
	~p3_25(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p3_25
	void V1_inTRp3_4_3398737(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp3_4_3398737(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp3_4_3398737(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp3_4_3398737(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p1_16: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_16(){ name = "p1_16"; expected_ni_list = { {  "V1_outTRp1_12_3398846"  }  }; }
	~p1_16(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p1_16
	void V1_outTRp1_12_3398846(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp1_12_3398846(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp1_12_3398846(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp1_12_3398846

	//enum notifications { _V1_outTRp1_12_3398846, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p5_5: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p5_5(){ name = "p5_5"; expected_ni_list = { {  "V1_outTRp5_1_3398745"  }  }; }
	~p5_5(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p5_5
	void V1_outTRp5_1_3398745(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp5_1_3398745(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp5_1_3398745(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp5_1_3398745

	//enum notifications { _V1_outTRp5_1_3398745, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p12_1: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p12_1(){ name = "p12_1"; expected_ni_list = { }; }
	~p12_1(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p12_1
	void V1_inTRp12_1_3398818(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp12_1_3398818(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp12_1_3398818(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp12_1_3398818(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p13_1: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p13_1(){ name = "p13_1"; expected_ni_list = { }; }
	~p13_1(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p13_1
	void V1_inTRp13_1_3398819(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp13_1_3398819(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp13_1_3398819(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp13_1_3398819(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p1_38: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_38(){ name = "p1_38"; expected_ni_list = { {  "V1_outTRp1_26_3398822"  }  }; }
	~p1_38(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p1_38
	void V1_outTRp1_26_3398822(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp1_26_3398822(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp1_26_3398822(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp1_26_3398822

	//enum notifications { _V1_outTRp1_26_3398822, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p2_18: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p2_18(){ name = "p2_18"; expected_ni_list = { }; }
	~p2_18(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p2_18
	void V1_inTRp2_1_3398721(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp2_1_3398721(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp2_1_3398721(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp2_1_3398721(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p1_40: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_40(){ name = "p1_40"; expected_ni_list = { {  "V1_outTRp1_17_3398791"  }  }; }
	~p1_40(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p1_40
	void V1_outTRp1_17_3398791(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp1_17_3398791(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp1_17_3398791(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp1_17_3398791

	//enum notifications { _V1_outTRp1_17_3398791, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p1_39: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_39(){ name = "p1_39"; expected_ni_list = { }; }
	~p1_39(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p1_39
	void V1_inTRp1_27_3398823(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp1_27_3398823(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp1_27_3398823(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp1_27_3398823(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p11_2: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p11_2(){ name = "p11_2"; expected_ni_list = { }; }
	~p11_2(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p11_2
	void V1_inTRp11_1_3398796(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp11_1_3398796(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp11_1_3398796(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp11_1_3398796(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p1_8: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_8(){ name = "p1_8"; expected_ni_list = { }; }
	~p1_8(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p1_8
	void V1_inTRp1_7_3398862(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp1_7_3398862(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp1_7_3398862(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp1_7_3398862(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p2_8: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p2_8(){ name = "p2_8"; expected_ni_list = { }; }
	~p2_8(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p2_8
	void V1_inTRp2_6_3398850(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp2_6_3398850(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp2_6_3398850(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp2_6_3398850(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_21: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_21(){ name = "p3_21"; expected_ni_list = { }; }
	~p3_21(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p3_21
	void V1_inTRp3_14_3398803(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp3_14_3398803(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp3_14_3398803(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp3_14_3398803(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p1_44: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_44(){ name = "p1_44"; expected_ni_list = { {  "V1_outTRp1_14_3398782"  }  }; }
	~p1_44(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p1_44
	void V1_outTRp1_14_3398782(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp1_14_3398782(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp1_14_3398782(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp1_14_3398782

	//enum notifications { _V1_outTRp1_14_3398782, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p9_2: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p9_2(){ name = "p9_2"; expected_ni_list = { }; }
	~p9_2(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p9_2
	void V1_inTRp9_1_3398800(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp9_1_3398800(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp9_1_3398800(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp9_1_3398800(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_3: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_3(){ name = "p3_3"; expected_ni_list = { }; }
	~p3_3(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p3_3
	void V1_inTRp3_3_3398842(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp3_3_3398842(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp3_3_3398842(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp3_3_3398842(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p9_6: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p9_6(){ name = "p9_6"; expected_ni_list = { {  "V1_outTRp9_1_3398789"  }  }; }
	~p9_6(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p9_6
	void V1_outTRp9_1_3398789(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp9_1_3398789(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp9_1_3398789(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp9_1_3398789

	//enum notifications { _V1_outTRp9_1_3398789, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p1_32: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_32(){ name = "p1_32"; expected_ni_list = { {  "V1_outTRp1_10_3398769"  }  }; }
	~p1_32(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p1_32
	void V1_outTRp1_10_3398769(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp1_10_3398769(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp1_10_3398769(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp1_10_3398769

	//enum notifications { _V1_outTRp1_10_3398769, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p1_22: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_22(){ name = "p1_22"; expected_ni_list = { {  "V1_outTRp1_7_3398793"  } , {  "V1_outTRp1_7_3398794"  }  }; }
	~p1_22(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p1_22
	void V1_outTRp1_7_3398794(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp1_7_3398794(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp1_7_3398794(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp1_7_3398794
	// Possible Notification in State: p1_22
	void V1_outTRp1_7_3398793(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp1_7_3398793(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp1_7_3398793(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp1_7_3398793

	//enum notifications { _V1_outTRp1_7_3398793,  _V1_outTRp1_7_3398794, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p1_42: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_42(){ name = "p1_42"; expected_ni_list = { {  "V1_outTRp1_1_3398718"  }  }; }
	~p1_42(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p1_42
	void V1_outTRp1_1_3398718(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp1_1_3398718(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp1_1_3398718(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp1_1_3398718

	//enum notifications { _V1_outTRp1_1_3398718, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_38: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_38(){ name = "p3_38"; expected_ni_list = { }; }
	~p3_38(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p3_38
	void V1_inTRp3_34_3398860(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp3_34_3398860(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp3_34_3398860(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp3_34_3398860(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_27: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_27(){ name = "p3_27"; expected_ni_list = { }; }
	~p3_27(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p3_27
	void V1_inTRp3_11_3398770(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp3_11_3398770(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp3_11_3398770(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp3_11_3398770(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p1_29: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_29(){ name = "p1_29"; expected_ni_list = { }; }
	~p1_29(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p1_29
	void V1_inTRp1_8_3398767(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp1_8_3398767(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp1_8_3398767(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp1_8_3398767(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p4_6: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p4_6(){ name = "p4_6"; expected_ni_list = { {  "V1_outTRp4_1_3398744"  }  }; }
	~p4_6(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p4_6
	void V1_outTRp4_1_3398744(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp4_1_3398744(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp4_1_3398744(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp4_1_3398744

	//enum notifications { _V1_outTRp4_1_3398744, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p4_2: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p4_2(){ name = "p4_2"; expected_ni_list = { {  "V1_outTRp4_2_3398873"  }  }; }
	~p4_2(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p4_2
	void V1_outTRp4_2_3398873(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp4_2_3398873(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp4_2_3398873(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp4_2_3398873

	//enum notifications { _V1_outTRp4_2_3398873, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p14_1: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p14_1(){ name = "p14_1"; expected_ni_list = { }; }
	~p14_1(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p14_1
	void V1_inTRp14_1_3398841(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp14_1_3398841(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp14_1_3398841(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp14_1_3398841(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_5: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_5(){ name = "p3_5"; expected_ni_list = { {  "V1_outTRp3_2_3398735"  }  }; }
	~p3_5(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p3_5
	void V1_outTRp3_2_3398735(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp3_2_3398735(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp3_2_3398735(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp3_2_3398735

	//enum notifications { _V1_outTRp3_2_3398735, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_4: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_4(){ name = "p3_4"; expected_ni_list = { {  "V1_outTRp3_4_3398843"  }  }; }
	~p3_4(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p3_4
	void V1_outTRp3_4_3398843(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp3_4_3398843(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp3_4_3398843(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp3_4_3398843

	//enum notifications { _V1_outTRp3_4_3398843, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p1_7: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_7(){ name = "p1_7"; expected_ni_list = { }; }
	~p1_7(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p1_7
	void V1_inTRp1_5_3398825(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp1_5_3398825(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp1_5_3398825(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp1_5_3398825(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_51: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_51(){ name = "p3_51"; expected_ni_list = { {  "V1_outTRp3_5_3398730"  }  }; }
	~p3_51(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p3_51
	void V1_outTRp3_5_3398730(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp3_5_3398730(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp3_5_3398730(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp3_5_3398730

	//enum notifications { _V1_outTRp3_5_3398730, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p1_17: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_17(){ name = "p1_17"; expected_ni_list = { {  "V1_outTRp1_7_3398804"  }  }; }
	~p1_17(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p1_17
	void V1_outTRp1_7_3398804(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp1_7_3398804(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp1_7_3398804(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp1_7_3398804

	//enum notifications { _V1_outTRp1_7_3398804, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p2_14: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p2_14(){ name = "p2_14"; expected_ni_list = { {  "V1_outTRp2_6_3398762"  }  }; }
	~p2_14(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p2_14
	void V1_outTRp2_6_3398762(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp2_6_3398762(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp2_6_3398762(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp2_6_3398762

	//enum notifications { _V1_outTRp2_6_3398762, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p2_13: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p2_13(){ name = "p2_13"; expected_ni_list = { {  "V1_outTRp2_9_3398848"  }  }; }
	~p2_13(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p2_13
	void V1_outTRp2_9_3398848(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp2_9_3398848(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp2_9_3398848(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp2_9_3398848

	//enum notifications { _V1_outTRp2_9_3398848, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p1_14: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_14(){ name = "p1_14"; expected_ni_list = { }; }
	~p1_14(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p1_14
	void V1_inTRp1_3_3398758(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp1_3_3398758(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp1_3_3398758(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp1_3_3398758(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p2_10: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p2_10(){ name = "p2_10"; expected_ni_list = { }; }
	~p2_10(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p2_10
	void V1_inTRp2_3_3398754(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp2_3_3398754(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp2_3_3398754(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp2_3_3398754(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);
	// Enabled Signal in State: p2_10
	void V1_inTRp2_4_3398772(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp2_4_3398772(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp2_4_3398772(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp2_4_3398772(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p2_9: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p2_9(){ name = "p2_9"; expected_ni_list = { {  "V1_outTRp2_7_3398851"  }  }; }
	~p2_9(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p2_9
	void V1_outTRp2_7_3398851(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp2_7_3398851(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp2_7_3398851(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp2_7_3398851

	//enum notifications { _V1_outTRp2_7_3398851, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_15: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_15(){ name = "p3_15"; expected_ni_list = { }; }
	~p3_15(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p3_15
	void V1_inTRp3_10_3398813(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp3_10_3398813(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp3_10_3398813(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp3_10_3398813(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p15_1: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p15_1(){ name = "p15_1"; expected_ni_list = { }; }
	~p15_1(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p15_1
	void V1_inTRp15_1_3398854(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp15_1_3398854(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp15_1_3398854(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp15_1_3398854(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p16_1: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p16_1(){ name = "p16_1"; expected_ni_list = { }; }
	~p16_1(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p16_1
	void V1_inTRp16_1_3398856(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp16_1_3398856(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp16_1_3398856(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp16_1_3398856(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p17_1: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p17_1(){ name = "p17_1"; expected_ni_list = { {  "V1_outTRp17_1_3398863"  }  }; }
	~p17_1(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p17_1
	void V1_outTRp17_1_3398863(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp17_1_3398863(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp17_1_3398863(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp17_1_3398863

	//enum notifications { _V1_outTRp17_1_3398863, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p1_19: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_19(){ name = "p1_19"; expected_ni_list = { {  "V1_outTRp1_4_3398759"  }  }; }
	~p1_19(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p1_19
	void V1_outTRp1_4_3398759(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp1_4_3398759(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp1_4_3398759(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp1_4_3398759

	//enum notifications { _V1_outTRp1_4_3398759, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_39: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_39(){ name = "p3_39"; expected_ni_list = { {  "V1_outTRp3_3_3398727"  }  }; }
	~p3_39(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p3_39
	void V1_outTRp3_3_3398727(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp3_3_3398727(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp3_3_3398727(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp3_3_3398727

	//enum notifications { _V1_outTRp3_3_3398727, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p1_28: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_28(){ name = "p1_28"; expected_ni_list = { {  "V1_outTRp1_20_3398837"  }  }; }
	~p1_28(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p1_28
	void V1_outTRp1_20_3398837(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp1_20_3398837(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp1_20_3398837(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp1_20_3398837

	//enum notifications { _V1_outTRp1_20_3398837, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p1_9: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_9(){ name = "p1_9"; expected_ni_list = { {  "V1_outTRp1_3_3398784"  }  }; }
	~p1_9(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p1_9
	void V1_outTRp1_3_3398784(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp1_3_3398784(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp1_3_3398784(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp1_3_3398784

	//enum notifications { _V1_outTRp1_3_3398784, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p17_3: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p17_3(){ name = "p17_3"; expected_ni_list = { }; }
	~p17_3(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p17_3
	void V1_inTRp17_1_3398858(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp17_1_3398858(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp17_1_3398858(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp17_1_3398858(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p17_2: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p17_2(){ name = "p17_2"; expected_ni_list = { }; }
	~p17_2(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p17_2
	void V1_inTRp17_2_3398864(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp17_2_3398864(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp17_2_3398864(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp17_2_3398864(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_31: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_31(){ name = "p3_31"; expected_ni_list = { }; }
	~p3_31(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p3_31
	void V1_inTRp3_5_3398749(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp3_5_3398749(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp3_5_3398749(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp3_5_3398749(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p1_4: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_4(){ name = "p1_4"; expected_ni_list = { {  "V1_outTRp1_1_3398738"  }  }; }
	~p1_4(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p1_4
	void V1_outTRp1_1_3398738(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp1_1_3398738(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp1_1_3398738(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp1_1_3398738

	//enum notifications { _V1_outTRp1_1_3398738, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_11: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_11(){ name = "p3_11"; expected_ni_list = { {  "V1_outTRp3_7_3398779"  } , {  "V1_outTRp3_8_3398840"  }  }; }
	~p3_11(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p3_11
	void V1_outTRp3_7_3398779(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp3_7_3398779(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp3_7_3398779(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp3_7_3398779
	// Possible Notification in State: p3_11
	void V1_outTRp3_8_3398840(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp3_8_3398840(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp3_8_3398840(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp3_8_3398840

	//enum notifications { _V1_outTRp3_7_3398779,  _V1_outTRp3_8_3398840, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p4_5: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p4_5(){ name = "p4_5"; expected_ni_list = { {  "V1_outTRp4_2_3398839"  }  }; }
	~p4_5(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p4_5
	void V1_outTRp4_2_3398839(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp4_2_3398839(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp4_2_3398839(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp4_2_3398839

	//enum notifications { _V1_outTRp4_2_3398839, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p4_4: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p4_4(){ name = "p4_4"; expected_ni_list = { {  "V1_outTRp4_3_3398869"  }  }; }
	~p4_4(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p4_4
	void V1_outTRp4_3_3398869(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp4_3_3398869(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp4_3_3398869(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp4_3_3398869

	//enum notifications { _V1_outTRp4_3_3398869, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p18_1: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p18_1(){ name = "p18_1"; expected_ni_list = { }; }
	~p18_1(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p18_1
	void V1_inTRp18_1_3398871(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp18_1_3398871(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp18_1_3398871(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp18_1_3398871(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_23: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_23(){ name = "p3_23"; expected_ni_list = { }; }
	~p3_23(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p3_23
	void V1_inTRp3_13_3398792(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp3_13_3398792(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp3_13_3398792(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp3_13_3398792(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p4_3: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p4_3(){ name = "p4_3"; expected_ni_list = { }; }
	~p4_3(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p4_3
	void V1_inTRp4_2_3398868(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp4_2_3398868(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp4_2_3398868(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp4_2_3398868(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p2_3: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p2_3(){ name = "p2_3"; expected_ni_list = { }; }
	~p2_3(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p2_3
	void V1_inTRp2_1_3398757(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp2_1_3398757(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp2_1_3398757(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp2_1_3398757(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p2_2: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p2_2(){ name = "p2_2"; expected_ni_list = { }; }
	~p2_2(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Enabled Signal in State: p2_2
	void V1_inTRp2_2_3398875(V1_StateMachineController *smc);
	bool isEnabledV1_inTRp2_2_3398875(V1_StateMachineController *smc, int instance_choice);
	void V1_inTRp2_2_3398875(V1_StateMachineController *smc, int instance_id, int clause_id);
	std::vector<int> V1_inTRp2_2_3398875(V1_StateMachineController *smc, std::vector<std::string> list_of_rcvd_notifications);

	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p19_1: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p19_1(){ name = "p19_1"; expected_ni_list = { {  "V1_outTRp19_1_3398877"  }  }; }
	~p19_1(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p19_1
	void V1_outTRp19_1_3398877(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp19_1_3398877(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp19_1_3398877(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp19_1_3398877

	//enum notifications { _V1_outTRp19_1_3398877, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p3_29: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p3_29(){ name = "p3_29"; expected_ni_list = { {  "V1_outTRp3_12_3398771"  }  }; }
	~p3_29(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p3_29
	void V1_outTRp3_12_3398771(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp3_12_3398771(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp3_12_3398771(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp3_12_3398771

	//enum notifications { _V1_outTRp3_12_3398771, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

class p1_11: public V1_State { 
public:
	string name;
	std::vector<std::vector<std::string>> expected_ni_list;
	
	p1_11(){ name = "p1_11"; expected_ni_list = { {  "V1_outTRp1_4_3398797"  }  }; }
	~p1_11(){};
	
	list<string> getCurrentCommandStatusList();
	list<string> getCurrentSignalStatusList();
	list<string> getCurrentNotificationStatusList();
	string getCurrentState();
	list<string> isAtleastOneEnabledCommand(V1_StateMachineController *smc);
	list<string> isAtleastOneEnabledSignal(V1_StateMachineController *smc);
	bool isAtleastOneEnabledNotification(V1_StateMachineController *smc);

	// Possible Notification in State: p1_11
	void V1_outTRp1_4_3398797(V1_StateMachineController *smc);
	std::vector<int> match_V1_outTRp1_4_3398797(V1_StateMachineController *smc, std::vector<std::string>  list_of_rcvd_notifications);
	void V1_outTRp1_4_3398797(V1_StateMachineController *smc, int instance_id, int clause_id);
	// Added DB: DEBUG FEATURE: Java Generator for Compound Notification: V1_outTRp1_4_3398797

	//enum notifications { _V1_outTRp1_4_3398797, END };

	// For Server Stub
	void executeInternalTransitions(V1_StateMachineController *smc);	
	bool isNotificationPossibleInState(V1_StateMachineController *smc){ return isAtleastOneEnabledNotification(smc);}
	// For Client Stub
	void executeAvailableCommandsAndSignalsInState(V1_StateMachineController *smc);
	bool checkEnabledCommandAndSignalInState(V1_StateMachineController *smc);
	list<string> determineEnabledCommandAndSignalInState(V1_StateMachineController *smc);
};

}

#endif /*V1_STATEMACHINECONTROLLER_H_ */
