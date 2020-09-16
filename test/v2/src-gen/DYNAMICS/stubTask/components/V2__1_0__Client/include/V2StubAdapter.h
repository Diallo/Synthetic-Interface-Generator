		#ifndef V2STUBADAPTER_H_
		#define V2STUBADAPTER_H_
		
		#include "V2_StateMachineController.h"
		
		namespace StateMachineController { 
		
		class V2_StateMachineController;
		
		typedef bool(*outTRp1_2_12_callbackHandlerType)(StateMachineController::V2_StateMachineController&, std::vector<std::string>);
		typedef bool(*outTRp1_1_15_callbackHandlerType)(StateMachineController::V2_StateMachineController&, std::vector<std::string>);
		typedef bool(*outTRp1_1_16_callbackHandlerType)(StateMachineController::V2_StateMachineController&, std::vector<std::string>);
		typedef bool(*outTRp1_6_19_callbackHandlerType)(StateMachineController::V2_StateMachineController&, std::vector<std::string>);
		typedef bool(*outTRp1_8_21_callbackHandlerType)(StateMachineController::V2_StateMachineController&, std::vector<std::string>);
		typedef bool(*outTRp1_6_22_callbackHandlerType)(StateMachineController::V2_StateMachineController&, std::vector<std::string>);
		typedef bool(*outTRp1_9_23_callbackHandlerType)(StateMachineController::V2_StateMachineController&, std::vector<std::string>);
		
		class NiHandler
		{
		public:
			NiHandler(StateMachineController::V2_StateMachineController& smc) : _smc(smc) { controllerSyncInProgress = false; };
			~NiHandler() {}
			
			// work in progress
			void register_outTRp1_2_12_CBHandler(outTRp1_2_12_callbackHandlerType _cbHndlr) { outTRp1_2_12_cbHndlr = _cbHndlr; }
			void register_outTRp1_1_15_CBHandler(outTRp1_1_15_callbackHandlerType _cbHndlr) { outTRp1_1_15_cbHndlr = _cbHndlr; }
			void register_outTRp1_1_16_CBHandler(outTRp1_1_16_callbackHandlerType _cbHndlr) { outTRp1_1_16_cbHndlr = _cbHndlr; }
			void register_outTRp1_6_19_CBHandler(outTRp1_6_19_callbackHandlerType _cbHndlr) { outTRp1_6_19_cbHndlr = _cbHndlr; }
			void register_outTRp1_8_21_CBHandler(outTRp1_8_21_callbackHandlerType _cbHndlr) { outTRp1_8_21_cbHndlr = _cbHndlr; }
			void register_outTRp1_6_22_CBHandler(outTRp1_6_22_callbackHandlerType _cbHndlr) { outTRp1_6_22_cbHndlr = _cbHndlr; }
			void register_outTRp1_9_23_CBHandler(outTRp1_9_23_callbackHandlerType _cbHndlr) { outTRp1_9_23_cbHndlr = _cbHndlr; }
			
			void outTRp1_2_12()
			{
				if(isEventContextOpen())
				{
					if(isControllerSyncInProgress())
					{
						std::cout<< "[INFO > Client Stub Adapter] Notification: outTRp1_2_12 was raised in an Open Context but Will be IGNORED!!!" << std::endl;
					}
					else
					{
						std::cout<< "[INFO > Client Stub Adapter] Notification: outTRp1_2_12 was raised in an Open Context!" << std::endl;
						list_of_rcvd_notifications.push_back("V2_outTRp1_2_12");
					}
				}
				else
				{
					std::cout<< "[INFO > Client Stub Adapter] Notification: outTRp1_2_12 was raised!" << std::endl;
					list_of_rcvd_notifications.push_back("V2_outTRp1_2_12");
					
					// Call State Machine Controller: If a prefix was matched, then Clear the List, Otherwise Wait for Notifications.
					if(outTRp1_2_12_cbHndlr != nullptr)
					{
						// TODO: Future Extension: To Match Data Arguments.
						//outTRp1_2_12_cbHndlr(_smc, list_of_rcvd_notifications);
						if(outTRp1_2_12_cbHndlr(_smc, list_of_rcvd_notifications))
						{
							list_of_rcvd_notifications.clear();
						}
					}
					std::cout << std::endl;
				}
			}
			void outTRp1_1_15()
			{
				if(isEventContextOpen())
				{
					if(isControllerSyncInProgress())
					{
						std::cout<< "[INFO > Client Stub Adapter] Notification: outTRp1_1_15 was raised in an Open Context but Will be IGNORED!!!" << std::endl;
					}
					else
					{
						std::cout<< "[INFO > Client Stub Adapter] Notification: outTRp1_1_15 was raised in an Open Context!" << std::endl;
						list_of_rcvd_notifications.push_back("V2_outTRp1_1_15");
					}
				}
				else
				{
					std::cout<< "[INFO > Client Stub Adapter] Notification: outTRp1_1_15 was raised!" << std::endl;
					list_of_rcvd_notifications.push_back("V2_outTRp1_1_15");
					
					// Call State Machine Controller: If a prefix was matched, then Clear the List, Otherwise Wait for Notifications.
					if(outTRp1_1_15_cbHndlr != nullptr)
					{
						// TODO: Future Extension: To Match Data Arguments.
						//outTRp1_1_15_cbHndlr(_smc, list_of_rcvd_notifications);
						if(outTRp1_1_15_cbHndlr(_smc, list_of_rcvd_notifications))
						{
							list_of_rcvd_notifications.clear();
						}
					}
					std::cout << std::endl;
				}
			}
			void outTRp1_1_16()
			{
				if(isEventContextOpen())
				{
					if(isControllerSyncInProgress())
					{
						std::cout<< "[INFO > Client Stub Adapter] Notification: outTRp1_1_16 was raised in an Open Context but Will be IGNORED!!!" << std::endl;
					}
					else
					{
						std::cout<< "[INFO > Client Stub Adapter] Notification: outTRp1_1_16 was raised in an Open Context!" << std::endl;
						list_of_rcvd_notifications.push_back("V2_outTRp1_1_16");
					}
				}
				else
				{
					std::cout<< "[INFO > Client Stub Adapter] Notification: outTRp1_1_16 was raised!" << std::endl;
					list_of_rcvd_notifications.push_back("V2_outTRp1_1_16");
					
					// Call State Machine Controller: If a prefix was matched, then Clear the List, Otherwise Wait for Notifications.
					if(outTRp1_1_16_cbHndlr != nullptr)
					{
						// TODO: Future Extension: To Match Data Arguments.
						//outTRp1_1_16_cbHndlr(_smc, list_of_rcvd_notifications);
						if(outTRp1_1_16_cbHndlr(_smc, list_of_rcvd_notifications))
						{
							list_of_rcvd_notifications.clear();
						}
					}
					std::cout << std::endl;
				}
			}
			void outTRp1_6_19()
			{
				if(isEventContextOpen())
				{
					if(isControllerSyncInProgress())
					{
						std::cout<< "[INFO > Client Stub Adapter] Notification: outTRp1_6_19 was raised in an Open Context but Will be IGNORED!!!" << std::endl;
					}
					else
					{
						std::cout<< "[INFO > Client Stub Adapter] Notification: outTRp1_6_19 was raised in an Open Context!" << std::endl;
						list_of_rcvd_notifications.push_back("V2_outTRp1_6_19");
					}
				}
				else
				{
					std::cout<< "[INFO > Client Stub Adapter] Notification: outTRp1_6_19 was raised!" << std::endl;
					list_of_rcvd_notifications.push_back("V2_outTRp1_6_19");
					
					// Call State Machine Controller: If a prefix was matched, then Clear the List, Otherwise Wait for Notifications.
					if(outTRp1_6_19_cbHndlr != nullptr)
					{
						// TODO: Future Extension: To Match Data Arguments.
						//outTRp1_6_19_cbHndlr(_smc, list_of_rcvd_notifications);
						if(outTRp1_6_19_cbHndlr(_smc, list_of_rcvd_notifications))
						{
							list_of_rcvd_notifications.clear();
						}
					}
					std::cout << std::endl;
				}
			}
			void outTRp1_8_21()
			{
				if(isEventContextOpen())
				{
					if(isControllerSyncInProgress())
					{
						std::cout<< "[INFO > Client Stub Adapter] Notification: outTRp1_8_21 was raised in an Open Context but Will be IGNORED!!!" << std::endl;
					}
					else
					{
						std::cout<< "[INFO > Client Stub Adapter] Notification: outTRp1_8_21 was raised in an Open Context!" << std::endl;
						list_of_rcvd_notifications.push_back("V2_outTRp1_8_21");
					}
				}
				else
				{
					std::cout<< "[INFO > Client Stub Adapter] Notification: outTRp1_8_21 was raised!" << std::endl;
					list_of_rcvd_notifications.push_back("V2_outTRp1_8_21");
					
					// Call State Machine Controller: If a prefix was matched, then Clear the List, Otherwise Wait for Notifications.
					if(outTRp1_8_21_cbHndlr != nullptr)
					{
						// TODO: Future Extension: To Match Data Arguments.
						//outTRp1_8_21_cbHndlr(_smc, list_of_rcvd_notifications);
						if(outTRp1_8_21_cbHndlr(_smc, list_of_rcvd_notifications))
						{
							list_of_rcvd_notifications.clear();
						}
					}
					std::cout << std::endl;
				}
			}
			void outTRp1_6_22()
			{
				if(isEventContextOpen())
				{
					if(isControllerSyncInProgress())
					{
						std::cout<< "[INFO > Client Stub Adapter] Notification: outTRp1_6_22 was raised in an Open Context but Will be IGNORED!!!" << std::endl;
					}
					else
					{
						std::cout<< "[INFO > Client Stub Adapter] Notification: outTRp1_6_22 was raised in an Open Context!" << std::endl;
						list_of_rcvd_notifications.push_back("V2_outTRp1_6_22");
					}
				}
				else
				{
					std::cout<< "[INFO > Client Stub Adapter] Notification: outTRp1_6_22 was raised!" << std::endl;
					list_of_rcvd_notifications.push_back("V2_outTRp1_6_22");
					
					// Call State Machine Controller: If a prefix was matched, then Clear the List, Otherwise Wait for Notifications.
					if(outTRp1_6_22_cbHndlr != nullptr)
					{
						// TODO: Future Extension: To Match Data Arguments.
						//outTRp1_6_22_cbHndlr(_smc, list_of_rcvd_notifications);
						if(outTRp1_6_22_cbHndlr(_smc, list_of_rcvd_notifications))
						{
							list_of_rcvd_notifications.clear();
						}
					}
					std::cout << std::endl;
				}
			}
			void outTRp1_9_23()
			{
				if(isEventContextOpen())
				{
					if(isControllerSyncInProgress())
					{
						std::cout<< "[INFO > Client Stub Adapter] Notification: outTRp1_9_23 was raised in an Open Context but Will be IGNORED!!!" << std::endl;
					}
					else
					{
						std::cout<< "[INFO > Client Stub Adapter] Notification: outTRp1_9_23 was raised in an Open Context!" << std::endl;
						list_of_rcvd_notifications.push_back("V2_outTRp1_9_23");
					}
				}
				else
				{
					std::cout<< "[INFO > Client Stub Adapter] Notification: outTRp1_9_23 was raised!" << std::endl;
					list_of_rcvd_notifications.push_back("V2_outTRp1_9_23");
					
					// Call State Machine Controller: If a prefix was matched, then Clear the List, Otherwise Wait for Notifications.
					if(outTRp1_9_23_cbHndlr != nullptr)
					{
						// TODO: Future Extension: To Match Data Arguments.
						//outTRp1_9_23_cbHndlr(_smc, list_of_rcvd_notifications);
						if(outTRp1_9_23_cbHndlr(_smc, list_of_rcvd_notifications))
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
			outTRp1_2_12_callbackHandlerType outTRp1_2_12_cbHndlr;
			outTRp1_1_15_callbackHandlerType outTRp1_1_15_cbHndlr;
			outTRp1_1_16_callbackHandlerType outTRp1_1_16_cbHndlr;
			outTRp1_6_19_callbackHandlerType outTRp1_6_19_cbHndlr;
			outTRp1_8_21_callbackHandlerType outTRp1_8_21_cbHndlr;
			outTRp1_6_22_callbackHandlerType outTRp1_6_22_cbHndlr;
			outTRp1_9_23_callbackHandlerType outTRp1_9_23_cbHndlr;
			
			
			std::vector<std::string> list_of_rcvd_notifications;
			bool is_command_context_open;
			bool controllerSyncInProgress;
			class StateMachineController::V2_StateMachineController& _smc;
		};
		
		// The class whose methods [commands and signals] needs to be implemented.
		class EventAPIHandler
		{
			public:
				EventAPIHandler(StateMachineController::V2_StateMachineController& smc) : m_niHandler(new NiHandler(smc)) { };
				virtual ~EventAPIHandler() { delete m_niHandler; };
			

				virtual void inTRp1_1_11() = 0;
				virtual void inTRp1_3_13() = 0;
				virtual void inTRp1_4_14() = 0;
				virtual void inTRp2_1_17() = 0;
				virtual void inTRp3_1_18() = 0;
				
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
