		#ifndef V1STUBADAPTER_H_
		#define V1STUBADAPTER_H_
		
		#include "V1_StateMachineController.h"
		
		namespace StateMachineController { 
		
		class V1_StateMachineController;
		
		typedef bool(*outTRp1_2_25_callbackHandlerType)(StateMachineController::V1_StateMachineController&, std::vector<std::string>);
		typedef bool(*outTRp1_3_26_callbackHandlerType)(StateMachineController::V1_StateMachineController&, std::vector<std::string>);
		typedef bool(*outTRp1_5_28_callbackHandlerType)(StateMachineController::V1_StateMachineController&, std::vector<std::string>);
		typedef bool(*outTRp1_6_29_callbackHandlerType)(StateMachineController::V1_StateMachineController&, std::vector<std::string>);
		typedef bool(*outTRp1_6_30_callbackHandlerType)(StateMachineController::V1_StateMachineController&, std::vector<std::string>);
		
		class NiHandler
		{
		public:
			NiHandler(StateMachineController::V1_StateMachineController& smc) : _smc(smc) { controllerSyncInProgress = false; };
			~NiHandler() {}
			
			// work in progress
			void register_outTRp1_2_25_CBHandler(outTRp1_2_25_callbackHandlerType _cbHndlr) { outTRp1_2_25_cbHndlr = _cbHndlr; }
			void register_outTRp1_3_26_CBHandler(outTRp1_3_26_callbackHandlerType _cbHndlr) { outTRp1_3_26_cbHndlr = _cbHndlr; }
			void register_outTRp1_5_28_CBHandler(outTRp1_5_28_callbackHandlerType _cbHndlr) { outTRp1_5_28_cbHndlr = _cbHndlr; }
			void register_outTRp1_6_29_CBHandler(outTRp1_6_29_callbackHandlerType _cbHndlr) { outTRp1_6_29_cbHndlr = _cbHndlr; }
			void register_outTRp1_6_30_CBHandler(outTRp1_6_30_callbackHandlerType _cbHndlr) { outTRp1_6_30_cbHndlr = _cbHndlr; }
			
			void outTRp1_2_25()
			{
				if(isEventContextOpen())
				{
					if(isControllerSyncInProgress())
					{
						std::cout<< "[INFO > Client Stub Adapter] Notification: outTRp1_2_25 was raised in an Open Context but Will be IGNORED!!!" << std::endl;
					}
					else
					{
						std::cout<< "[INFO > Client Stub Adapter] Notification: outTRp1_2_25 was raised in an Open Context!" << std::endl;
						list_of_rcvd_notifications.push_back("V1_outTRp1_2_25");
					}
				}
				else
				{
					std::cout<< "[INFO > Client Stub Adapter] Notification: outTRp1_2_25 was raised!" << std::endl;
					list_of_rcvd_notifications.push_back("V1_outTRp1_2_25");
					
					// Call State Machine Controller: If a prefix was matched, then Clear the List, Otherwise Wait for Notifications.
					if(outTRp1_2_25_cbHndlr != nullptr)
					{
						// TODO: Future Extension: To Match Data Arguments.
						//outTRp1_2_25_cbHndlr(_smc, list_of_rcvd_notifications);
						if(outTRp1_2_25_cbHndlr(_smc, list_of_rcvd_notifications))
						{
							list_of_rcvd_notifications.clear();
						}
					}
					std::cout << std::endl;
				}
			}
			void outTRp1_3_26()
			{
				if(isEventContextOpen())
				{
					if(isControllerSyncInProgress())
					{
						std::cout<< "[INFO > Client Stub Adapter] Notification: outTRp1_3_26 was raised in an Open Context but Will be IGNORED!!!" << std::endl;
					}
					else
					{
						std::cout<< "[INFO > Client Stub Adapter] Notification: outTRp1_3_26 was raised in an Open Context!" << std::endl;
						list_of_rcvd_notifications.push_back("V1_outTRp1_3_26");
					}
				}
				else
				{
					std::cout<< "[INFO > Client Stub Adapter] Notification: outTRp1_3_26 was raised!" << std::endl;
					list_of_rcvd_notifications.push_back("V1_outTRp1_3_26");
					
					// Call State Machine Controller: If a prefix was matched, then Clear the List, Otherwise Wait for Notifications.
					if(outTRp1_3_26_cbHndlr != nullptr)
					{
						// TODO: Future Extension: To Match Data Arguments.
						//outTRp1_3_26_cbHndlr(_smc, list_of_rcvd_notifications);
						if(outTRp1_3_26_cbHndlr(_smc, list_of_rcvd_notifications))
						{
							list_of_rcvd_notifications.clear();
						}
					}
					std::cout << std::endl;
				}
			}
			void outTRp1_5_28()
			{
				if(isEventContextOpen())
				{
					if(isControllerSyncInProgress())
					{
						std::cout<< "[INFO > Client Stub Adapter] Notification: outTRp1_5_28 was raised in an Open Context but Will be IGNORED!!!" << std::endl;
					}
					else
					{
						std::cout<< "[INFO > Client Stub Adapter] Notification: outTRp1_5_28 was raised in an Open Context!" << std::endl;
						list_of_rcvd_notifications.push_back("V1_outTRp1_5_28");
					}
				}
				else
				{
					std::cout<< "[INFO > Client Stub Adapter] Notification: outTRp1_5_28 was raised!" << std::endl;
					list_of_rcvd_notifications.push_back("V1_outTRp1_5_28");
					
					// Call State Machine Controller: If a prefix was matched, then Clear the List, Otherwise Wait for Notifications.
					if(outTRp1_5_28_cbHndlr != nullptr)
					{
						// TODO: Future Extension: To Match Data Arguments.
						//outTRp1_5_28_cbHndlr(_smc, list_of_rcvd_notifications);
						if(outTRp1_5_28_cbHndlr(_smc, list_of_rcvd_notifications))
						{
							list_of_rcvd_notifications.clear();
						}
					}
					std::cout << std::endl;
				}
			}
			void outTRp1_6_29()
			{
				if(isEventContextOpen())
				{
					if(isControllerSyncInProgress())
					{
						std::cout<< "[INFO > Client Stub Adapter] Notification: outTRp1_6_29 was raised in an Open Context but Will be IGNORED!!!" << std::endl;
					}
					else
					{
						std::cout<< "[INFO > Client Stub Adapter] Notification: outTRp1_6_29 was raised in an Open Context!" << std::endl;
						list_of_rcvd_notifications.push_back("V1_outTRp1_6_29");
					}
				}
				else
				{
					std::cout<< "[INFO > Client Stub Adapter] Notification: outTRp1_6_29 was raised!" << std::endl;
					list_of_rcvd_notifications.push_back("V1_outTRp1_6_29");
					
					// Call State Machine Controller: If a prefix was matched, then Clear the List, Otherwise Wait for Notifications.
					if(outTRp1_6_29_cbHndlr != nullptr)
					{
						// TODO: Future Extension: To Match Data Arguments.
						//outTRp1_6_29_cbHndlr(_smc, list_of_rcvd_notifications);
						if(outTRp1_6_29_cbHndlr(_smc, list_of_rcvd_notifications))
						{
							list_of_rcvd_notifications.clear();
						}
					}
					std::cout << std::endl;
				}
			}
			void outTRp1_6_30()
			{
				if(isEventContextOpen())
				{
					if(isControllerSyncInProgress())
					{
						std::cout<< "[INFO > Client Stub Adapter] Notification: outTRp1_6_30 was raised in an Open Context but Will be IGNORED!!!" << std::endl;
					}
					else
					{
						std::cout<< "[INFO > Client Stub Adapter] Notification: outTRp1_6_30 was raised in an Open Context!" << std::endl;
						list_of_rcvd_notifications.push_back("V1_outTRp1_6_30");
					}
				}
				else
				{
					std::cout<< "[INFO > Client Stub Adapter] Notification: outTRp1_6_30 was raised!" << std::endl;
					list_of_rcvd_notifications.push_back("V1_outTRp1_6_30");
					
					// Call State Machine Controller: If a prefix was matched, then Clear the List, Otherwise Wait for Notifications.
					if(outTRp1_6_30_cbHndlr != nullptr)
					{
						// TODO: Future Extension: To Match Data Arguments.
						//outTRp1_6_30_cbHndlr(_smc, list_of_rcvd_notifications);
						if(outTRp1_6_30_cbHndlr(_smc, list_of_rcvd_notifications))
						{
							list_of_rcvd_notifications.clear();
						}
					}
					std::cout << std::endl;
				}
			}

			void openEventContext() { is_command_context_open = true; }
			bool isEventContextOpen() { return is_command_context_open; }
			std::vector<std::string> getListOfRcvdNotifications() { return list_of_rcvd_notifications; controllerSyncInProgress = true; }
			void closeEventContext() { is_command_context_open = false; list_of_rcvd_notifications.clear(); controllerSyncInProgress = false; }
			
			void setControllerSyncStatus(bool status) { controllerSyncInProgress = status; }
			bool isControllerSyncInProgress() { if (controllerSyncInProgress) return true; else return false; }

		private:
			outTRp1_2_25_callbackHandlerType outTRp1_2_25_cbHndlr;
			outTRp1_3_26_callbackHandlerType outTRp1_3_26_cbHndlr;
			outTRp1_5_28_callbackHandlerType outTRp1_5_28_cbHndlr;
			outTRp1_6_29_callbackHandlerType outTRp1_6_29_cbHndlr;
			outTRp1_6_30_callbackHandlerType outTRp1_6_30_cbHndlr;
			
			
			std::vector<std::string> list_of_rcvd_notifications;
			bool is_command_context_open;
			bool controllerSyncInProgress;
			class StateMachineController::V1_StateMachineController& _smc;
		};
		
		// The class whose methods [commands and signals] needs to be implemented.
		class EventAPIHandler
		{
			public:
				EventAPIHandler(StateMachineController::V1_StateMachineController& smc) : m_niHandler(new NiHandler(smc)) { };
				virtual ~EventAPIHandler() { delete m_niHandler; };
			

				virtual void inTRp1_1_24() = 0;
				virtual void inTRp1_1_27() = 0;
				virtual void inTRp2_1_31() = 0;
				virtual void inTRp3_1_32() = 0;
				virtual void inTRp3_1_33() = 0;
				
				std::vector<std::string> getListOfReceivedNotifications() { return getNIHandler().getListOfRcvdNotifications(); }
				void openEventContext() { getNIHandler().openEventContext(); }
				void closeEventContext() { getNIHandler().closeEventContext(); }
				
				void setControllerSyncStatus(bool status) { getNIHandler().setControllerSyncStatus(true); }
				
				// This should be private? TODO.
				NiHandler& getNIHandler() { return *m_niHandler; }
			
			private:
				NiHandler *m_niHandler;
			};
		}
		#endif
