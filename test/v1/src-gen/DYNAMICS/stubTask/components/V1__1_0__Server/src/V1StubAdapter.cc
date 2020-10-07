#include "V1StubAdapter.h"

std::mutex NotificationEventHandler::mtx;
std::condition_variable NotificationEventHandler::cv;
StateMachineController::outTRp1_1_3398718_Handler NotificationEventHandler::m_outTRp1_1_3398718CB;
StateMachineController::outTRp1_1_3398719_Handler NotificationEventHandler::m_outTRp1_1_3398719CB;
StateMachineController::outTRp1_1_3398720_Handler NotificationEventHandler::m_outTRp1_1_3398720CB;
StateMachineController::outTRp3_1_3398724_Handler NotificationEventHandler::m_outTRp3_1_3398724CB;
StateMachineController::outTRp1_4_3398725_Handler NotificationEventHandler::m_outTRp1_4_3398725CB;
StateMachineController::outTRp3_3_3398727_Handler NotificationEventHandler::m_outTRp3_3_3398727CB;
StateMachineController::outTRp3_5_3398730_Handler NotificationEventHandler::m_outTRp3_5_3398730CB;
StateMachineController::outTRp3_4_3398731_Handler NotificationEventHandler::m_outTRp3_4_3398731CB;
StateMachineController::outTRp3_5_3398733_Handler NotificationEventHandler::m_outTRp3_5_3398733CB;
StateMachineController::outTRp3_2_3398735_Handler NotificationEventHandler::m_outTRp3_2_3398735CB;
StateMachineController::outTRp3_3_3398736_Handler NotificationEventHandler::m_outTRp3_3_3398736CB;
StateMachineController::outTRp1_1_3398738_Handler NotificationEventHandler::m_outTRp1_1_3398738CB;
StateMachineController::outTRp2_3_3398740_Handler NotificationEventHandler::m_outTRp2_3_3398740CB;
StateMachineController::outTRp4_1_3398744_Handler NotificationEventHandler::m_outTRp4_1_3398744CB;
StateMachineController::outTRp5_1_3398745_Handler NotificationEventHandler::m_outTRp5_1_3398745CB;
StateMachineController::outTRp3_10_3398748_Handler NotificationEventHandler::m_outTRp3_10_3398748CB;
StateMachineController::outTRp1_6_3398756_Handler NotificationEventHandler::m_outTRp1_6_3398756CB;
StateMachineController::outTRp1_4_3398759_Handler NotificationEventHandler::m_outTRp1_4_3398759CB;
StateMachineController::outTRp3_6_3398761_Handler NotificationEventHandler::m_outTRp3_6_3398761CB;
StateMachineController::outTRp2_6_3398762_Handler NotificationEventHandler::m_outTRp2_6_3398762CB;
StateMachineController::outTRp3_4_3398763_Handler NotificationEventHandler::m_outTRp3_4_3398763CB;
StateMachineController::outTRp3_11_3398764_Handler NotificationEventHandler::m_outTRp3_11_3398764CB;
StateMachineController::outTRp3_8_3398766_Handler NotificationEventHandler::m_outTRp3_8_3398766CB;
StateMachineController::outTRp1_10_3398769_Handler NotificationEventHandler::m_outTRp1_10_3398769CB;
StateMachineController::outTRp3_12_3398771_Handler NotificationEventHandler::m_outTRp3_12_3398771CB;
StateMachineController::outTRp6_1_3398773_Handler NotificationEventHandler::m_outTRp6_1_3398773CB;
StateMachineController::outTRp7_1_3398775_Handler NotificationEventHandler::m_outTRp7_1_3398775CB;
StateMachineController::outTRp5_2_3398777_Handler NotificationEventHandler::m_outTRp5_2_3398777CB;
StateMachineController::outTRp1_6_3398778_Handler NotificationEventHandler::m_outTRp1_6_3398778CB;
StateMachineController::outTRp3_7_3398779_Handler NotificationEventHandler::m_outTRp3_7_3398779CB;
StateMachineController::outTRp1_14_3398782_Handler NotificationEventHandler::m_outTRp1_14_3398782CB;
StateMachineController::outTRp1_3_3398784_Handler NotificationEventHandler::m_outTRp1_3_3398784CB;
StateMachineController::outTRp8_1_3398788_Handler NotificationEventHandler::m_outTRp8_1_3398788CB;
StateMachineController::outTRp9_1_3398789_Handler NotificationEventHandler::m_outTRp9_1_3398789CB;
StateMachineController::outTRp1_17_3398791_Handler NotificationEventHandler::m_outTRp1_17_3398791CB;
StateMachineController::outTRp1_7_3398793_Handler NotificationEventHandler::m_outTRp1_7_3398793CB;
StateMachineController::outTRp1_7_3398794_Handler NotificationEventHandler::m_outTRp1_7_3398794CB;
StateMachineController::outTRp1_4_3398797_Handler NotificationEventHandler::m_outTRp1_4_3398797CB;
StateMachineController::outTRp3_29_3398799_Handler NotificationEventHandler::m_outTRp3_29_3398799CB;
StateMachineController::outTRp9_2_3398801_Handler NotificationEventHandler::m_outTRp9_2_3398801CB;
StateMachineController::outTRp3_13_3398802_Handler NotificationEventHandler::m_outTRp3_13_3398802CB;
StateMachineController::outTRp1_7_3398804_Handler NotificationEventHandler::m_outTRp1_7_3398804CB;
StateMachineController::outTRp3_32_3398806_Handler NotificationEventHandler::m_outTRp3_32_3398806CB;
StateMachineController::outTRp1_20_3398809_Handler NotificationEventHandler::m_outTRp1_20_3398809CB;
StateMachineController::outTRp9_3_3398810_Handler NotificationEventHandler::m_outTRp9_3_3398810CB;
StateMachineController::outTRp1_1_3398811_Handler NotificationEventHandler::m_outTRp1_1_3398811CB;
StateMachineController::outTRp1_9_3398815_Handler NotificationEventHandler::m_outTRp1_9_3398815CB;
StateMachineController::outTRp5_4_3398816_Handler NotificationEventHandler::m_outTRp5_4_3398816CB;
StateMachineController::outTRp5_4_3398817_Handler NotificationEventHandler::m_outTRp5_4_3398817CB;
StateMachineController::outTRp1_25_3398820_Handler NotificationEventHandler::m_outTRp1_25_3398820CB;
StateMachineController::outTRp2_10_3398821_Handler NotificationEventHandler::m_outTRp2_10_3398821CB;
StateMachineController::outTRp1_26_3398822_Handler NotificationEventHandler::m_outTRp1_26_3398822CB;
StateMachineController::outTRp11_1_3398824_Handler NotificationEventHandler::m_outTRp11_1_3398824CB;
StateMachineController::outTRp9_1_3398829_Handler NotificationEventHandler::m_outTRp9_1_3398829CB;
StateMachineController::outTRp3_2_3398830_Handler NotificationEventHandler::m_outTRp3_2_3398830CB;
StateMachineController::outTRp9_5_3398831_Handler NotificationEventHandler::m_outTRp9_5_3398831CB;
StateMachineController::outTRp1_21_3398832_Handler NotificationEventHandler::m_outTRp1_21_3398832CB;
StateMachineController::outTRp3_29_3398835_Handler NotificationEventHandler::m_outTRp3_29_3398835CB;
StateMachineController::outTRp3_21_3398836_Handler NotificationEventHandler::m_outTRp3_21_3398836CB;
StateMachineController::outTRp1_20_3398837_Handler NotificationEventHandler::m_outTRp1_20_3398837CB;
StateMachineController::outTRp4_2_3398839_Handler NotificationEventHandler::m_outTRp4_2_3398839CB;
StateMachineController::outTRp3_8_3398840_Handler NotificationEventHandler::m_outTRp3_8_3398840CB;
StateMachineController::outTRp3_4_3398843_Handler NotificationEventHandler::m_outTRp3_4_3398843CB;
StateMachineController::outTRp1_5_3398844_Handler NotificationEventHandler::m_outTRp1_5_3398844CB;
StateMachineController::outTRp3_44_3398845_Handler NotificationEventHandler::m_outTRp3_44_3398845CB;
StateMachineController::outTRp1_12_3398846_Handler NotificationEventHandler::m_outTRp1_12_3398846CB;
StateMachineController::outTRp2_9_3398848_Handler NotificationEventHandler::m_outTRp2_9_3398848CB;
StateMachineController::outTRp2_7_3398851_Handler NotificationEventHandler::m_outTRp2_7_3398851CB;
StateMachineController::outTRp3_13_3398852_Handler NotificationEventHandler::m_outTRp3_13_3398852CB;
StateMachineController::outTRp3_40_3398853_Handler NotificationEventHandler::m_outTRp3_40_3398853CB;
StateMachineController::outTRp3_40_3398855_Handler NotificationEventHandler::m_outTRp3_40_3398855CB;
StateMachineController::outTRp3_6_3398857_Handler NotificationEventHandler::m_outTRp3_6_3398857CB;
StateMachineController::outTRp17_1_3398863_Handler NotificationEventHandler::m_outTRp17_1_3398863CB;
StateMachineController::outTRp1_3_3398866_Handler NotificationEventHandler::m_outTRp1_3_3398866CB;
StateMachineController::outTRp3_10_3398867_Handler NotificationEventHandler::m_outTRp3_10_3398867CB;
StateMachineController::outTRp4_3_3398869_Handler NotificationEventHandler::m_outTRp4_3_3398869CB;
StateMachineController::outTRp9_1_3398870_Handler NotificationEventHandler::m_outTRp9_1_3398870CB;
StateMachineController::outTRp4_2_3398873_Handler NotificationEventHandler::m_outTRp4_2_3398873CB;
StateMachineController::outTRp2_1_3398874_Handler NotificationEventHandler::m_outTRp2_1_3398874CB;
StateMachineController::outTRp19_1_3398877_Handler NotificationEventHandler::m_outTRp19_1_3398877CB;
StateMachineController::outTRp1_10_3398879_Handler NotificationEventHandler::m_outTRp1_10_3398879CB;

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
	if(m_outTRp1_1_3398718CB != nullptr) m_outTRp1_1_3398718CB = nullptr;
	if(m_outTRp1_1_3398719CB != nullptr) m_outTRp1_1_3398719CB = nullptr;
	if(m_outTRp1_1_3398720CB != nullptr) m_outTRp1_1_3398720CB = nullptr;
	if(m_outTRp3_1_3398724CB != nullptr) m_outTRp3_1_3398724CB = nullptr;
	if(m_outTRp1_4_3398725CB != nullptr) m_outTRp1_4_3398725CB = nullptr;
	if(m_outTRp3_3_3398727CB != nullptr) m_outTRp3_3_3398727CB = nullptr;
	if(m_outTRp3_5_3398730CB != nullptr) m_outTRp3_5_3398730CB = nullptr;
	if(m_outTRp3_4_3398731CB != nullptr) m_outTRp3_4_3398731CB = nullptr;
	if(m_outTRp3_5_3398733CB != nullptr) m_outTRp3_5_3398733CB = nullptr;
	if(m_outTRp3_2_3398735CB != nullptr) m_outTRp3_2_3398735CB = nullptr;
	if(m_outTRp3_3_3398736CB != nullptr) m_outTRp3_3_3398736CB = nullptr;
	if(m_outTRp1_1_3398738CB != nullptr) m_outTRp1_1_3398738CB = nullptr;
	if(m_outTRp2_3_3398740CB != nullptr) m_outTRp2_3_3398740CB = nullptr;
	if(m_outTRp4_1_3398744CB != nullptr) m_outTRp4_1_3398744CB = nullptr;
	if(m_outTRp5_1_3398745CB != nullptr) m_outTRp5_1_3398745CB = nullptr;
	if(m_outTRp3_10_3398748CB != nullptr) m_outTRp3_10_3398748CB = nullptr;
	if(m_outTRp1_6_3398756CB != nullptr) m_outTRp1_6_3398756CB = nullptr;
	if(m_outTRp1_4_3398759CB != nullptr) m_outTRp1_4_3398759CB = nullptr;
	if(m_outTRp3_6_3398761CB != nullptr) m_outTRp3_6_3398761CB = nullptr;
	if(m_outTRp2_6_3398762CB != nullptr) m_outTRp2_6_3398762CB = nullptr;
	if(m_outTRp3_4_3398763CB != nullptr) m_outTRp3_4_3398763CB = nullptr;
	if(m_outTRp3_11_3398764CB != nullptr) m_outTRp3_11_3398764CB = nullptr;
	if(m_outTRp3_8_3398766CB != nullptr) m_outTRp3_8_3398766CB = nullptr;
	if(m_outTRp1_10_3398769CB != nullptr) m_outTRp1_10_3398769CB = nullptr;
	if(m_outTRp3_12_3398771CB != nullptr) m_outTRp3_12_3398771CB = nullptr;
	if(m_outTRp6_1_3398773CB != nullptr) m_outTRp6_1_3398773CB = nullptr;
	if(m_outTRp7_1_3398775CB != nullptr) m_outTRp7_1_3398775CB = nullptr;
	if(m_outTRp5_2_3398777CB != nullptr) m_outTRp5_2_3398777CB = nullptr;
	if(m_outTRp1_6_3398778CB != nullptr) m_outTRp1_6_3398778CB = nullptr;
	if(m_outTRp3_7_3398779CB != nullptr) m_outTRp3_7_3398779CB = nullptr;
	if(m_outTRp1_14_3398782CB != nullptr) m_outTRp1_14_3398782CB = nullptr;
	if(m_outTRp1_3_3398784CB != nullptr) m_outTRp1_3_3398784CB = nullptr;
	if(m_outTRp8_1_3398788CB != nullptr) m_outTRp8_1_3398788CB = nullptr;
	if(m_outTRp9_1_3398789CB != nullptr) m_outTRp9_1_3398789CB = nullptr;
	if(m_outTRp1_17_3398791CB != nullptr) m_outTRp1_17_3398791CB = nullptr;
	if(m_outTRp1_7_3398793CB != nullptr) m_outTRp1_7_3398793CB = nullptr;
	if(m_outTRp1_7_3398794CB != nullptr) m_outTRp1_7_3398794CB = nullptr;
	if(m_outTRp1_4_3398797CB != nullptr) m_outTRp1_4_3398797CB = nullptr;
	if(m_outTRp3_29_3398799CB != nullptr) m_outTRp3_29_3398799CB = nullptr;
	if(m_outTRp9_2_3398801CB != nullptr) m_outTRp9_2_3398801CB = nullptr;
	if(m_outTRp3_13_3398802CB != nullptr) m_outTRp3_13_3398802CB = nullptr;
	if(m_outTRp1_7_3398804CB != nullptr) m_outTRp1_7_3398804CB = nullptr;
	if(m_outTRp3_32_3398806CB != nullptr) m_outTRp3_32_3398806CB = nullptr;
	if(m_outTRp1_20_3398809CB != nullptr) m_outTRp1_20_3398809CB = nullptr;
	if(m_outTRp9_3_3398810CB != nullptr) m_outTRp9_3_3398810CB = nullptr;
	if(m_outTRp1_1_3398811CB != nullptr) m_outTRp1_1_3398811CB = nullptr;
	if(m_outTRp1_9_3398815CB != nullptr) m_outTRp1_9_3398815CB = nullptr;
	if(m_outTRp5_4_3398816CB != nullptr) m_outTRp5_4_3398816CB = nullptr;
	if(m_outTRp5_4_3398817CB != nullptr) m_outTRp5_4_3398817CB = nullptr;
	if(m_outTRp1_25_3398820CB != nullptr) m_outTRp1_25_3398820CB = nullptr;
	if(m_outTRp2_10_3398821CB != nullptr) m_outTRp2_10_3398821CB = nullptr;
	if(m_outTRp1_26_3398822CB != nullptr) m_outTRp1_26_3398822CB = nullptr;
	if(m_outTRp11_1_3398824CB != nullptr) m_outTRp11_1_3398824CB = nullptr;
	if(m_outTRp9_1_3398829CB != nullptr) m_outTRp9_1_3398829CB = nullptr;
	if(m_outTRp3_2_3398830CB != nullptr) m_outTRp3_2_3398830CB = nullptr;
	if(m_outTRp9_5_3398831CB != nullptr) m_outTRp9_5_3398831CB = nullptr;
	if(m_outTRp1_21_3398832CB != nullptr) m_outTRp1_21_3398832CB = nullptr;
	if(m_outTRp3_29_3398835CB != nullptr) m_outTRp3_29_3398835CB = nullptr;
	if(m_outTRp3_21_3398836CB != nullptr) m_outTRp3_21_3398836CB = nullptr;
	if(m_outTRp1_20_3398837CB != nullptr) m_outTRp1_20_3398837CB = nullptr;
	if(m_outTRp4_2_3398839CB != nullptr) m_outTRp4_2_3398839CB = nullptr;
	if(m_outTRp3_8_3398840CB != nullptr) m_outTRp3_8_3398840CB = nullptr;
	if(m_outTRp3_4_3398843CB != nullptr) m_outTRp3_4_3398843CB = nullptr;
	if(m_outTRp1_5_3398844CB != nullptr) m_outTRp1_5_3398844CB = nullptr;
	if(m_outTRp3_44_3398845CB != nullptr) m_outTRp3_44_3398845CB = nullptr;
	if(m_outTRp1_12_3398846CB != nullptr) m_outTRp1_12_3398846CB = nullptr;
	if(m_outTRp2_9_3398848CB != nullptr) m_outTRp2_9_3398848CB = nullptr;
	if(m_outTRp2_7_3398851CB != nullptr) m_outTRp2_7_3398851CB = nullptr;
	if(m_outTRp3_13_3398852CB != nullptr) m_outTRp3_13_3398852CB = nullptr;
	if(m_outTRp3_40_3398853CB != nullptr) m_outTRp3_40_3398853CB = nullptr;
	if(m_outTRp3_40_3398855CB != nullptr) m_outTRp3_40_3398855CB = nullptr;
	if(m_outTRp3_6_3398857CB != nullptr) m_outTRp3_6_3398857CB = nullptr;
	if(m_outTRp17_1_3398863CB != nullptr) m_outTRp17_1_3398863CB = nullptr;
	if(m_outTRp1_3_3398866CB != nullptr) m_outTRp1_3_3398866CB = nullptr;
	if(m_outTRp3_10_3398867CB != nullptr) m_outTRp3_10_3398867CB = nullptr;
	if(m_outTRp4_3_3398869CB != nullptr) m_outTRp4_3_3398869CB = nullptr;
	if(m_outTRp9_1_3398870CB != nullptr) m_outTRp9_1_3398870CB = nullptr;
	if(m_outTRp4_2_3398873CB != nullptr) m_outTRp4_2_3398873CB = nullptr;
	if(m_outTRp2_1_3398874CB != nullptr) m_outTRp2_1_3398874CB = nullptr;
	if(m_outTRp19_1_3398877CB != nullptr) m_outTRp19_1_3398877CB = nullptr;
	if(m_outTRp1_10_3398879CB != nullptr) m_outTRp1_10_3398879CB = nullptr;
}

EventAPI::EventAPI()
{
	srand(time(0));
	sim_mode = SERVER_STUB;
	signalInitlist.push_back("V1_inTRp2_1_3398721");
	signalInitlist.push_back("V1_inTRp3_1_3398722");
	signalInitlist.push_back("V1_inTRp1_1_3398723");
	signalInitlist.push_back("V1_inTRp3_2_3398726");
	signalInitlist.push_back("V1_inTRp2_1_3398728");
	signalInitlist.push_back("V1_inTRp3_4_3398729");
	signalInitlist.push_back("V1_inTRp2_1_3398732");
	signalInitlist.push_back("V1_inTRp3_5_3398734");
	signalInitlist.push_back("V1_inTRp3_4_3398737");
	signalInitlist.push_back("V1_inTRp2_2_3398739");
	signalInitlist.push_back("V1_inTRp3_10_3398741");
	signalInitlist.push_back("V1_inTRp1_2_3398742");
	signalInitlist.push_back("V1_inTRp1_2_3398743");
	signalInitlist.push_back("V1_inTRp1_4_3398746");
	signalInitlist.push_back("V1_inTRp3_9_3398747");
	signalInitlist.push_back("V1_inTRp3_5_3398749");
	signalInitlist.push_back("V1_inTRp3_4_3398750");
	signalInitlist.push_back("V1_inTRp3_9_3398751");
	signalInitlist.push_back("V1_inTRp3_8_3398752");
	signalInitlist.push_back("V1_inTRp2_1_3398753");
	signalInitlist.push_back("V1_inTRp2_3_3398754");
	signalInitlist.push_back("V1_inTRp1_5_3398755");
	signalInitlist.push_back("V1_inTRp2_1_3398757");
	signalInitlist.push_back("V1_inTRp1_3_3398758");
	signalInitlist.push_back("V1_inTRp3_5_3398760");
	signalInitlist.push_back("V1_inTRp3_12_3398765");
	signalInitlist.push_back("V1_inTRp1_8_3398767");
	signalInitlist.push_back("V1_inTRp3_9_3398768");
	signalInitlist.push_back("V1_inTRp3_11_3398770");
	signalInitlist.push_back("V1_inTRp2_4_3398772");
	signalInitlist.push_back("V1_inTRp3_26_3398774");
	signalInitlist.push_back("V1_inTRp5_1_3398776");
	signalInitlist.push_back("V1_inTRp3_8_3398780");
	signalInitlist.push_back("V1_inTRp2_3_3398781");
	signalInitlist.push_back("V1_inTRp1_2_3398783");
	signalInitlist.push_back("V1_inTRp1_14_3398785");
	signalInitlist.push_back("V1_inTRp3_12_3398786");
	signalInitlist.push_back("V1_inTRp3_12_3398787");
	signalInitlist.push_back("V1_inTRp1_16_3398790");
	signalInitlist.push_back("V1_inTRp3_13_3398792");
	signalInitlist.push_back("V1_inTRp10_1_3398795");
	signalInitlist.push_back("V1_inTRp11_1_3398796");
	signalInitlist.push_back("V1_inTRp3_18_3398798");
	signalInitlist.push_back("V1_inTRp9_1_3398800");
	signalInitlist.push_back("V1_inTRp3_14_3398803");
	signalInitlist.push_back("V1_inTRp10_1_3398805");
	signalInitlist.push_back("V1_inTRp5_3_3398807");
	signalInitlist.push_back("V1_inTRp1_9_3398808");
	signalInitlist.push_back("V1_inTRp1_2_3398812");
	signalInitlist.push_back("V1_inTRp3_10_3398813");
	signalInitlist.push_back("V1_inTRp3_17_3398814");
	signalInitlist.push_back("V1_inTRp12_1_3398818");
	signalInitlist.push_back("V1_inTRp13_1_3398819");
	signalInitlist.push_back("V1_inTRp1_27_3398823");
	signalInitlist.push_back("V1_inTRp1_5_3398825");
	signalInitlist.push_back("V1_inTRp2_5_3398826");
	signalInitlist.push_back("V1_inTRp3_15_3398827");
	signalInitlist.push_back("V1_inTRp1_31_3398828");
	signalInitlist.push_back("V1_inTRp1_14_3398833");
	signalInitlist.push_back("V1_inTRp1_32_3398834");
	signalInitlist.push_back("V1_inTRp4_1_3398838");
	signalInitlist.push_back("V1_inTRp14_1_3398841");
	signalInitlist.push_back("V1_inTRp3_3_3398842");
	signalInitlist.push_back("V1_inTRp2_8_3398847");
	signalInitlist.push_back("V1_inTRp1_10_3398849");
	signalInitlist.push_back("V1_inTRp2_6_3398850");
	signalInitlist.push_back("V1_inTRp15_1_3398854");
	signalInitlist.push_back("V1_inTRp16_1_3398856");
	signalInitlist.push_back("V1_inTRp17_1_3398858");
	signalInitlist.push_back("V1_inTRp1_15_3398859");
	signalInitlist.push_back("V1_inTRp3_34_3398860");
	signalInitlist.push_back("V1_inTRp1_24_3398861");
	signalInitlist.push_back("V1_inTRp1_7_3398862");
	signalInitlist.push_back("V1_inTRp17_2_3398864");
	signalInitlist.push_back("V1_inTRp3_27_3398865");
	signalInitlist.push_back("V1_inTRp4_2_3398868");
	signalInitlist.push_back("V1_inTRp18_1_3398871");
	signalInitlist.push_back("V1_inTRp3_22_3398872");
	signalInitlist.push_back("V1_inTRp2_2_3398875");
	signalInitlist.push_back("V1_inTRp4_1_3398876");
	signalInitlist.push_back("V1_inTRp3_28_3398878");
	notificationInitlist.push_back("V1_outTRp1_1_3398718");
	notificationInitlist.push_back("V1_outTRp1_1_3398719");
	notificationInitlist.push_back("V1_outTRp1_1_3398720");
	notificationInitlist.push_back("V1_outTRp3_1_3398724");
	notificationInitlist.push_back("V1_outTRp1_4_3398725");
	notificationInitlist.push_back("V1_outTRp3_3_3398727");
	notificationInitlist.push_back("V1_outTRp3_5_3398730");
	notificationInitlist.push_back("V1_outTRp3_4_3398731");
	notificationInitlist.push_back("V1_outTRp3_5_3398733");
	notificationInitlist.push_back("V1_outTRp3_2_3398735");
	notificationInitlist.push_back("V1_outTRp3_3_3398736");
	notificationInitlist.push_back("V1_outTRp1_1_3398738");
	notificationInitlist.push_back("V1_outTRp2_3_3398740");
	notificationInitlist.push_back("V1_outTRp4_1_3398744");
	notificationInitlist.push_back("V1_outTRp5_1_3398745");
	notificationInitlist.push_back("V1_outTRp3_10_3398748");
	notificationInitlist.push_back("V1_outTRp1_6_3398756");
	notificationInitlist.push_back("V1_outTRp1_4_3398759");
	notificationInitlist.push_back("V1_outTRp3_6_3398761");
	notificationInitlist.push_back("V1_outTRp2_6_3398762");
	notificationInitlist.push_back("V1_outTRp3_4_3398763");
	notificationInitlist.push_back("V1_outTRp3_11_3398764");
	notificationInitlist.push_back("V1_outTRp3_8_3398766");
	notificationInitlist.push_back("V1_outTRp1_10_3398769");
	notificationInitlist.push_back("V1_outTRp3_12_3398771");
	notificationInitlist.push_back("V1_outTRp6_1_3398773");
	notificationInitlist.push_back("V1_outTRp7_1_3398775");
	notificationInitlist.push_back("V1_outTRp5_2_3398777");
	notificationInitlist.push_back("V1_outTRp1_6_3398778");
	notificationInitlist.push_back("V1_outTRp3_7_3398779");
	notificationInitlist.push_back("V1_outTRp1_14_3398782");
	notificationInitlist.push_back("V1_outTRp1_3_3398784");
	notificationInitlist.push_back("V1_outTRp8_1_3398788");
	notificationInitlist.push_back("V1_outTRp9_1_3398789");
	notificationInitlist.push_back("V1_outTRp1_17_3398791");
	notificationInitlist.push_back("V1_outTRp1_7_3398793");
	notificationInitlist.push_back("V1_outTRp1_7_3398794");
	notificationInitlist.push_back("V1_outTRp1_4_3398797");
	notificationInitlist.push_back("V1_outTRp3_29_3398799");
	notificationInitlist.push_back("V1_outTRp9_2_3398801");
	notificationInitlist.push_back("V1_outTRp3_13_3398802");
	notificationInitlist.push_back("V1_outTRp1_7_3398804");
	notificationInitlist.push_back("V1_outTRp3_32_3398806");
	notificationInitlist.push_back("V1_outTRp1_20_3398809");
	notificationInitlist.push_back("V1_outTRp9_3_3398810");
	notificationInitlist.push_back("V1_outTRp1_1_3398811");
	notificationInitlist.push_back("V1_outTRp1_9_3398815");
	notificationInitlist.push_back("V1_outTRp5_4_3398816");
	notificationInitlist.push_back("V1_outTRp5_4_3398817");
	notificationInitlist.push_back("V1_outTRp1_25_3398820");
	notificationInitlist.push_back("V1_outTRp2_10_3398821");
	notificationInitlist.push_back("V1_outTRp1_26_3398822");
	notificationInitlist.push_back("V1_outTRp11_1_3398824");
	notificationInitlist.push_back("V1_outTRp9_1_3398829");
	notificationInitlist.push_back("V1_outTRp3_2_3398830");
	notificationInitlist.push_back("V1_outTRp9_5_3398831");
	notificationInitlist.push_back("V1_outTRp1_21_3398832");
	notificationInitlist.push_back("V1_outTRp3_29_3398835");
	notificationInitlist.push_back("V1_outTRp3_21_3398836");
	notificationInitlist.push_back("V1_outTRp1_20_3398837");
	notificationInitlist.push_back("V1_outTRp4_2_3398839");
	notificationInitlist.push_back("V1_outTRp3_8_3398840");
	notificationInitlist.push_back("V1_outTRp3_4_3398843");
	notificationInitlist.push_back("V1_outTRp1_5_3398844");
	notificationInitlist.push_back("V1_outTRp3_44_3398845");
	notificationInitlist.push_back("V1_outTRp1_12_3398846");
	notificationInitlist.push_back("V1_outTRp2_9_3398848");
	notificationInitlist.push_back("V1_outTRp2_7_3398851");
	notificationInitlist.push_back("V1_outTRp3_13_3398852");
	notificationInitlist.push_back("V1_outTRp3_40_3398853");
	notificationInitlist.push_back("V1_outTRp3_40_3398855");
	notificationInitlist.push_back("V1_outTRp3_6_3398857");
	notificationInitlist.push_back("V1_outTRp17_1_3398863");
	notificationInitlist.push_back("V1_outTRp1_3_3398866");
	notificationInitlist.push_back("V1_outTRp3_10_3398867");
	notificationInitlist.push_back("V1_outTRp4_3_3398869");
	notificationInitlist.push_back("V1_outTRp9_1_3398870");
	notificationInitlist.push_back("V1_outTRp4_2_3398873");
	notificationInitlist.push_back("V1_outTRp2_1_3398874");
	notificationInitlist.push_back("V1_outTRp19_1_3398877");
	notificationInitlist.push_back("V1_outTRp1_10_3398879");
	
	ev = new StateMachineController::EventViewer(sim_mode);
	er = new StateMachineController::EventRepository(commandInitlist, signalInitlist, notificationInitlist);
	er->RegisterDataChangeHandler(&StateMachineController::EventViewer::updateAvailableEvents);
	smc = new StateMachineController::V1_StateMachineController(er, sim_mode);
	StateMachineController::SimulatorConfiguration sc;
	
	// TODO DEBUG ONLY; REMOVE.
	// smc->RegisterNIHandler(&NotificationEventHandler::niEvt);
	
	smc->register_outTRp1_1_3398718_Handler(&NotificationEventHandler::outTRp1_1_3398718);
	smc->register_outTRp1_1_3398719_Handler(&NotificationEventHandler::outTRp1_1_3398719);
	smc->register_outTRp1_1_3398720_Handler(&NotificationEventHandler::outTRp1_1_3398720);
	smc->register_outTRp3_1_3398724_Handler(&NotificationEventHandler::outTRp3_1_3398724);
	smc->register_outTRp1_4_3398725_Handler(&NotificationEventHandler::outTRp1_4_3398725);
	smc->register_outTRp3_3_3398727_Handler(&NotificationEventHandler::outTRp3_3_3398727);
	smc->register_outTRp3_5_3398730_Handler(&NotificationEventHandler::outTRp3_5_3398730);
	smc->register_outTRp3_4_3398731_Handler(&NotificationEventHandler::outTRp3_4_3398731);
	smc->register_outTRp3_5_3398733_Handler(&NotificationEventHandler::outTRp3_5_3398733);
	smc->register_outTRp3_2_3398735_Handler(&NotificationEventHandler::outTRp3_2_3398735);
	smc->register_outTRp3_3_3398736_Handler(&NotificationEventHandler::outTRp3_3_3398736);
	smc->register_outTRp1_1_3398738_Handler(&NotificationEventHandler::outTRp1_1_3398738);
	smc->register_outTRp2_3_3398740_Handler(&NotificationEventHandler::outTRp2_3_3398740);
	smc->register_outTRp4_1_3398744_Handler(&NotificationEventHandler::outTRp4_1_3398744);
	smc->register_outTRp5_1_3398745_Handler(&NotificationEventHandler::outTRp5_1_3398745);
	smc->register_outTRp3_10_3398748_Handler(&NotificationEventHandler::outTRp3_10_3398748);
	smc->register_outTRp1_6_3398756_Handler(&NotificationEventHandler::outTRp1_6_3398756);
	smc->register_outTRp1_4_3398759_Handler(&NotificationEventHandler::outTRp1_4_3398759);
	smc->register_outTRp3_6_3398761_Handler(&NotificationEventHandler::outTRp3_6_3398761);
	smc->register_outTRp2_6_3398762_Handler(&NotificationEventHandler::outTRp2_6_3398762);
	smc->register_outTRp3_4_3398763_Handler(&NotificationEventHandler::outTRp3_4_3398763);
	smc->register_outTRp3_11_3398764_Handler(&NotificationEventHandler::outTRp3_11_3398764);
	smc->register_outTRp3_8_3398766_Handler(&NotificationEventHandler::outTRp3_8_3398766);
	smc->register_outTRp1_10_3398769_Handler(&NotificationEventHandler::outTRp1_10_3398769);
	smc->register_outTRp3_12_3398771_Handler(&NotificationEventHandler::outTRp3_12_3398771);
	smc->register_outTRp6_1_3398773_Handler(&NotificationEventHandler::outTRp6_1_3398773);
	smc->register_outTRp7_1_3398775_Handler(&NotificationEventHandler::outTRp7_1_3398775);
	smc->register_outTRp5_2_3398777_Handler(&NotificationEventHandler::outTRp5_2_3398777);
	smc->register_outTRp1_6_3398778_Handler(&NotificationEventHandler::outTRp1_6_3398778);
	smc->register_outTRp3_7_3398779_Handler(&NotificationEventHandler::outTRp3_7_3398779);
	smc->register_outTRp1_14_3398782_Handler(&NotificationEventHandler::outTRp1_14_3398782);
	smc->register_outTRp1_3_3398784_Handler(&NotificationEventHandler::outTRp1_3_3398784);
	smc->register_outTRp8_1_3398788_Handler(&NotificationEventHandler::outTRp8_1_3398788);
	smc->register_outTRp9_1_3398789_Handler(&NotificationEventHandler::outTRp9_1_3398789);
	smc->register_outTRp1_17_3398791_Handler(&NotificationEventHandler::outTRp1_17_3398791);
	smc->register_outTRp1_7_3398793_Handler(&NotificationEventHandler::outTRp1_7_3398793);
	smc->register_outTRp1_7_3398794_Handler(&NotificationEventHandler::outTRp1_7_3398794);
	smc->register_outTRp1_4_3398797_Handler(&NotificationEventHandler::outTRp1_4_3398797);
	smc->register_outTRp3_29_3398799_Handler(&NotificationEventHandler::outTRp3_29_3398799);
	smc->register_outTRp9_2_3398801_Handler(&NotificationEventHandler::outTRp9_2_3398801);
	smc->register_outTRp3_13_3398802_Handler(&NotificationEventHandler::outTRp3_13_3398802);
	smc->register_outTRp1_7_3398804_Handler(&NotificationEventHandler::outTRp1_7_3398804);
	smc->register_outTRp3_32_3398806_Handler(&NotificationEventHandler::outTRp3_32_3398806);
	smc->register_outTRp1_20_3398809_Handler(&NotificationEventHandler::outTRp1_20_3398809);
	smc->register_outTRp9_3_3398810_Handler(&NotificationEventHandler::outTRp9_3_3398810);
	smc->register_outTRp1_1_3398811_Handler(&NotificationEventHandler::outTRp1_1_3398811);
	smc->register_outTRp1_9_3398815_Handler(&NotificationEventHandler::outTRp1_9_3398815);
	smc->register_outTRp5_4_3398816_Handler(&NotificationEventHandler::outTRp5_4_3398816);
	smc->register_outTRp5_4_3398817_Handler(&NotificationEventHandler::outTRp5_4_3398817);
	smc->register_outTRp1_25_3398820_Handler(&NotificationEventHandler::outTRp1_25_3398820);
	smc->register_outTRp2_10_3398821_Handler(&NotificationEventHandler::outTRp2_10_3398821);
	smc->register_outTRp1_26_3398822_Handler(&NotificationEventHandler::outTRp1_26_3398822);
	smc->register_outTRp11_1_3398824_Handler(&NotificationEventHandler::outTRp11_1_3398824);
	smc->register_outTRp9_1_3398829_Handler(&NotificationEventHandler::outTRp9_1_3398829);
	smc->register_outTRp3_2_3398830_Handler(&NotificationEventHandler::outTRp3_2_3398830);
	smc->register_outTRp9_5_3398831_Handler(&NotificationEventHandler::outTRp9_5_3398831);
	smc->register_outTRp1_21_3398832_Handler(&NotificationEventHandler::outTRp1_21_3398832);
	smc->register_outTRp3_29_3398835_Handler(&NotificationEventHandler::outTRp3_29_3398835);
	smc->register_outTRp3_21_3398836_Handler(&NotificationEventHandler::outTRp3_21_3398836);
	smc->register_outTRp1_20_3398837_Handler(&NotificationEventHandler::outTRp1_20_3398837);
	smc->register_outTRp4_2_3398839_Handler(&NotificationEventHandler::outTRp4_2_3398839);
	smc->register_outTRp3_8_3398840_Handler(&NotificationEventHandler::outTRp3_8_3398840);
	smc->register_outTRp3_4_3398843_Handler(&NotificationEventHandler::outTRp3_4_3398843);
	smc->register_outTRp1_5_3398844_Handler(&NotificationEventHandler::outTRp1_5_3398844);
	smc->register_outTRp3_44_3398845_Handler(&NotificationEventHandler::outTRp3_44_3398845);
	smc->register_outTRp1_12_3398846_Handler(&NotificationEventHandler::outTRp1_12_3398846);
	smc->register_outTRp2_9_3398848_Handler(&NotificationEventHandler::outTRp2_9_3398848);
	smc->register_outTRp2_7_3398851_Handler(&NotificationEventHandler::outTRp2_7_3398851);
	smc->register_outTRp3_13_3398852_Handler(&NotificationEventHandler::outTRp3_13_3398852);
	smc->register_outTRp3_40_3398853_Handler(&NotificationEventHandler::outTRp3_40_3398853);
	smc->register_outTRp3_40_3398855_Handler(&NotificationEventHandler::outTRp3_40_3398855);
	smc->register_outTRp3_6_3398857_Handler(&NotificationEventHandler::outTRp3_6_3398857);
	smc->register_outTRp17_1_3398863_Handler(&NotificationEventHandler::outTRp17_1_3398863);
	smc->register_outTRp1_3_3398866_Handler(&NotificationEventHandler::outTRp1_3_3398866);
	smc->register_outTRp3_10_3398867_Handler(&NotificationEventHandler::outTRp3_10_3398867);
	smc->register_outTRp4_3_3398869_Handler(&NotificationEventHandler::outTRp4_3_3398869);
	smc->register_outTRp9_1_3398870_Handler(&NotificationEventHandler::outTRp9_1_3398870);
	smc->register_outTRp4_2_3398873_Handler(&NotificationEventHandler::outTRp4_2_3398873);
	smc->register_outTRp2_1_3398874_Handler(&NotificationEventHandler::outTRp2_1_3398874);
	smc->register_outTRp19_1_3398877_Handler(&NotificationEventHandler::outTRp19_1_3398877);
	smc->register_outTRp1_10_3398879_Handler(&NotificationEventHandler::outTRp1_10_3398879);
	
	srand((unsigned int)time(NULL));
}






void EventAPI::inTRp2_1_3398721()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp2_1_3398721" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp2_1_3398721(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp2_1_3398721();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp2_1_3398721(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp2_1_3398721(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp2_1_3398721(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp2_1_3398721 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp2_1_3398721" << std::endl;
		smc->_V1_inTRp2_1_3398721(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp3_1_3398722()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp3_1_3398722" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp3_1_3398722(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp3_1_3398722();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp3_1_3398722(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp3_1_3398722(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp3_1_3398722(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp3_1_3398722 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp3_1_3398722" << std::endl;
		smc->_V1_inTRp3_1_3398722(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp1_1_3398723()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp1_1_3398723" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp1_1_3398723(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp1_1_3398723();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp1_1_3398723(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp1_1_3398723(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp1_1_3398723(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp1_1_3398723 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp1_1_3398723" << std::endl;
		smc->_V1_inTRp1_1_3398723(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp3_2_3398726()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp3_2_3398726" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp3_2_3398726(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp3_2_3398726();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp3_2_3398726(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp3_2_3398726(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp3_2_3398726(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp3_2_3398726 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp3_2_3398726" << std::endl;
		smc->_V1_inTRp3_2_3398726(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp2_1_3398728()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp2_1_3398728" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp2_1_3398728(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp2_1_3398728();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp2_1_3398728(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp2_1_3398728(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp2_1_3398728(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp2_1_3398728 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp2_1_3398728" << std::endl;
		smc->_V1_inTRp2_1_3398728(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp3_4_3398729()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp3_4_3398729" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp3_4_3398729(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp3_4_3398729();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp3_4_3398729(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp3_4_3398729(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp3_4_3398729(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp3_4_3398729 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp3_4_3398729" << std::endl;
		smc->_V1_inTRp3_4_3398729(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp2_1_3398732()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp2_1_3398732" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp2_1_3398732(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp2_1_3398732();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp2_1_3398732(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp2_1_3398732(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp2_1_3398732(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp2_1_3398732 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp2_1_3398732" << std::endl;
		smc->_V1_inTRp2_1_3398732(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp3_5_3398734()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp3_5_3398734" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp3_5_3398734(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp3_5_3398734();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp3_5_3398734(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp3_5_3398734(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp3_5_3398734(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp3_5_3398734 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp3_5_3398734" << std::endl;
		smc->_V1_inTRp3_5_3398734(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp3_4_3398737()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp3_4_3398737" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp3_4_3398737(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp3_4_3398737();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp3_4_3398737(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp3_4_3398737(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp3_4_3398737(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp3_4_3398737 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp3_4_3398737" << std::endl;
		smc->_V1_inTRp3_4_3398737(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp2_2_3398739()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp2_2_3398739" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp2_2_3398739(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp2_2_3398739();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp2_2_3398739(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp2_2_3398739(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp2_2_3398739(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp2_2_3398739 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp2_2_3398739" << std::endl;
		smc->_V1_inTRp2_2_3398739(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp3_10_3398741()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp3_10_3398741" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp3_10_3398741(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp3_10_3398741();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp3_10_3398741(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp3_10_3398741(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp3_10_3398741(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp3_10_3398741 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp3_10_3398741" << std::endl;
		smc->_V1_inTRp3_10_3398741(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp1_2_3398742()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp1_2_3398742" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp1_2_3398742(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp1_2_3398742();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp1_2_3398742(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp1_2_3398742(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp1_2_3398742(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp1_2_3398742 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp1_2_3398742" << std::endl;
		smc->_V1_inTRp1_2_3398742(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp1_2_3398743()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp1_2_3398743" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp1_2_3398743(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp1_2_3398743();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp1_2_3398743(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp1_2_3398743(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp1_2_3398743(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp1_2_3398743 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp1_2_3398743" << std::endl;
		smc->_V1_inTRp1_2_3398743(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp1_4_3398746()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp1_4_3398746" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp1_4_3398746(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp1_4_3398746();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp1_4_3398746(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp1_4_3398746(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp1_4_3398746(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp1_4_3398746 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp1_4_3398746" << std::endl;
		smc->_V1_inTRp1_4_3398746(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp3_9_3398747()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp3_9_3398747" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp3_9_3398747(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp3_9_3398747();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp3_9_3398747(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp3_9_3398747(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp3_9_3398747(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp3_9_3398747 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp3_9_3398747" << std::endl;
		smc->_V1_inTRp3_9_3398747(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp3_5_3398749()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp3_5_3398749" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp3_5_3398749(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp3_5_3398749();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp3_5_3398749(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp3_5_3398749(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp3_5_3398749(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp3_5_3398749 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp3_5_3398749" << std::endl;
		smc->_V1_inTRp3_5_3398749(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp3_4_3398750()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp3_4_3398750" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp3_4_3398750(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp3_4_3398750();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp3_4_3398750(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp3_4_3398750(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp3_4_3398750(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp3_4_3398750 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp3_4_3398750" << std::endl;
		smc->_V1_inTRp3_4_3398750(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp3_9_3398751()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp3_9_3398751" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp3_9_3398751(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp3_9_3398751();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp3_9_3398751(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp3_9_3398751(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp3_9_3398751(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp3_9_3398751 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp3_9_3398751" << std::endl;
		smc->_V1_inTRp3_9_3398751(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp3_8_3398752()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp3_8_3398752" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp3_8_3398752(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp3_8_3398752();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp3_8_3398752(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp3_8_3398752(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp3_8_3398752(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp3_8_3398752 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp3_8_3398752" << std::endl;
		smc->_V1_inTRp3_8_3398752(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp2_1_3398753()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp2_1_3398753" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp2_1_3398753(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp2_1_3398753();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp2_1_3398753(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp2_1_3398753(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp2_1_3398753(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp2_1_3398753 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp2_1_3398753" << std::endl;
		smc->_V1_inTRp2_1_3398753(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp2_3_3398754()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp2_3_3398754" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp2_3_3398754(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp2_3_3398754();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp2_3_3398754(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp2_3_3398754(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp2_3_3398754(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp2_3_3398754 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp2_3_3398754" << std::endl;
		smc->_V1_inTRp2_3_3398754(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp1_5_3398755()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp1_5_3398755" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp1_5_3398755(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp1_5_3398755();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp1_5_3398755(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp1_5_3398755(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp1_5_3398755(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp1_5_3398755 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp1_5_3398755" << std::endl;
		smc->_V1_inTRp1_5_3398755(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp2_1_3398757()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp2_1_3398757" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp2_1_3398757(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp2_1_3398757();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp2_1_3398757(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp2_1_3398757(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp2_1_3398757(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp2_1_3398757 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp2_1_3398757" << std::endl;
		smc->_V1_inTRp2_1_3398757(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp1_3_3398758()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp1_3_3398758" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp1_3_3398758(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp1_3_3398758();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp1_3_3398758(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp1_3_3398758(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp1_3_3398758(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp1_3_3398758 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp1_3_3398758" << std::endl;
		smc->_V1_inTRp1_3_3398758(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp3_5_3398760()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp3_5_3398760" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp3_5_3398760(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp3_5_3398760();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp3_5_3398760(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp3_5_3398760(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp3_5_3398760(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp3_5_3398760 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp3_5_3398760" << std::endl;
		smc->_V1_inTRp3_5_3398760(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp3_12_3398765()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp3_12_3398765" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp3_12_3398765(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp3_12_3398765();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp3_12_3398765(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp3_12_3398765(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp3_12_3398765(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp3_12_3398765 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp3_12_3398765" << std::endl;
		smc->_V1_inTRp3_12_3398765(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp1_8_3398767()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp1_8_3398767" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp1_8_3398767(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp1_8_3398767();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp1_8_3398767(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp1_8_3398767(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp1_8_3398767(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp1_8_3398767 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp1_8_3398767" << std::endl;
		smc->_V1_inTRp1_8_3398767(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp3_9_3398768()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp3_9_3398768" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp3_9_3398768(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp3_9_3398768();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp3_9_3398768(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp3_9_3398768(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp3_9_3398768(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp3_9_3398768 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp3_9_3398768" << std::endl;
		smc->_V1_inTRp3_9_3398768(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp3_11_3398770()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp3_11_3398770" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp3_11_3398770(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp3_11_3398770();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp3_11_3398770(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp3_11_3398770(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp3_11_3398770(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp3_11_3398770 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp3_11_3398770" << std::endl;
		smc->_V1_inTRp3_11_3398770(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp2_4_3398772()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp2_4_3398772" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp2_4_3398772(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp2_4_3398772();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp2_4_3398772(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp2_4_3398772(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp2_4_3398772(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp2_4_3398772 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp2_4_3398772" << std::endl;
		smc->_V1_inTRp2_4_3398772(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp3_26_3398774()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp3_26_3398774" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp3_26_3398774(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp3_26_3398774();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp3_26_3398774(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp3_26_3398774(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp3_26_3398774(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp3_26_3398774 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp3_26_3398774" << std::endl;
		smc->_V1_inTRp3_26_3398774(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp5_1_3398776()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp5_1_3398776" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp5_1_3398776(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp5_1_3398776();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp5_1_3398776(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp5_1_3398776(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp5_1_3398776(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp5_1_3398776 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp5_1_3398776" << std::endl;
		smc->_V1_inTRp5_1_3398776(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp3_8_3398780()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp3_8_3398780" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp3_8_3398780(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp3_8_3398780();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp3_8_3398780(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp3_8_3398780(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp3_8_3398780(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp3_8_3398780 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp3_8_3398780" << std::endl;
		smc->_V1_inTRp3_8_3398780(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp2_3_3398781()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp2_3_3398781" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp2_3_3398781(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp2_3_3398781();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp2_3_3398781(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp2_3_3398781(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp2_3_3398781(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp2_3_3398781 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp2_3_3398781" << std::endl;
		smc->_V1_inTRp2_3_3398781(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp1_2_3398783()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp1_2_3398783" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp1_2_3398783(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp1_2_3398783();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp1_2_3398783(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp1_2_3398783(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp1_2_3398783(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp1_2_3398783 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp1_2_3398783" << std::endl;
		smc->_V1_inTRp1_2_3398783(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp1_14_3398785()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp1_14_3398785" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp1_14_3398785(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp1_14_3398785();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp1_14_3398785(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp1_14_3398785(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp1_14_3398785(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp1_14_3398785 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp1_14_3398785" << std::endl;
		smc->_V1_inTRp1_14_3398785(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp3_12_3398786()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp3_12_3398786" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp3_12_3398786(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp3_12_3398786();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp3_12_3398786(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp3_12_3398786(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp3_12_3398786(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp3_12_3398786 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp3_12_3398786" << std::endl;
		smc->_V1_inTRp3_12_3398786(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp3_12_3398787()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp3_12_3398787" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp3_12_3398787(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp3_12_3398787();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp3_12_3398787(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp3_12_3398787(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp3_12_3398787(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp3_12_3398787 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp3_12_3398787" << std::endl;
		smc->_V1_inTRp3_12_3398787(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp1_16_3398790()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp1_16_3398790" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp1_16_3398790(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp1_16_3398790();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp1_16_3398790(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp1_16_3398790(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp1_16_3398790(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp1_16_3398790 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp1_16_3398790" << std::endl;
		smc->_V1_inTRp1_16_3398790(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp3_13_3398792()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp3_13_3398792" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp3_13_3398792(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp3_13_3398792();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp3_13_3398792(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp3_13_3398792(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp3_13_3398792(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp3_13_3398792 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp3_13_3398792" << std::endl;
		smc->_V1_inTRp3_13_3398792(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp10_1_3398795()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp10_1_3398795" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp10_1_3398795(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp10_1_3398795();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp10_1_3398795(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp10_1_3398795(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp10_1_3398795(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp10_1_3398795 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp10_1_3398795" << std::endl;
		smc->_V1_inTRp10_1_3398795(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp11_1_3398796()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp11_1_3398796" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp11_1_3398796(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp11_1_3398796();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp11_1_3398796(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp11_1_3398796(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp11_1_3398796(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp11_1_3398796 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp11_1_3398796" << std::endl;
		smc->_V1_inTRp11_1_3398796(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp3_18_3398798()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp3_18_3398798" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp3_18_3398798(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp3_18_3398798();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp3_18_3398798(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp3_18_3398798(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp3_18_3398798(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp3_18_3398798 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp3_18_3398798" << std::endl;
		smc->_V1_inTRp3_18_3398798(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp9_1_3398800()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp9_1_3398800" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp9_1_3398800(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp9_1_3398800();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp9_1_3398800(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp9_1_3398800(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp9_1_3398800(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp9_1_3398800 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp9_1_3398800" << std::endl;
		smc->_V1_inTRp9_1_3398800(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp3_14_3398803()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp3_14_3398803" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp3_14_3398803(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp3_14_3398803();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp3_14_3398803(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp3_14_3398803(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp3_14_3398803(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp3_14_3398803 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp3_14_3398803" << std::endl;
		smc->_V1_inTRp3_14_3398803(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp10_1_3398805()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp10_1_3398805" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp10_1_3398805(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp10_1_3398805();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp10_1_3398805(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp10_1_3398805(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp10_1_3398805(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp10_1_3398805 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp10_1_3398805" << std::endl;
		smc->_V1_inTRp10_1_3398805(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp5_3_3398807()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp5_3_3398807" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp5_3_3398807(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp5_3_3398807();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp5_3_3398807(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp5_3_3398807(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp5_3_3398807(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp5_3_3398807 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp5_3_3398807" << std::endl;
		smc->_V1_inTRp5_3_3398807(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp1_9_3398808()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp1_9_3398808" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp1_9_3398808(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp1_9_3398808();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp1_9_3398808(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp1_9_3398808(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp1_9_3398808(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp1_9_3398808 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp1_9_3398808" << std::endl;
		smc->_V1_inTRp1_9_3398808(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp1_2_3398812()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp1_2_3398812" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp1_2_3398812(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp1_2_3398812();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp1_2_3398812(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp1_2_3398812(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp1_2_3398812(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp1_2_3398812 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp1_2_3398812" << std::endl;
		smc->_V1_inTRp1_2_3398812(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp3_10_3398813()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp3_10_3398813" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp3_10_3398813(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp3_10_3398813();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp3_10_3398813(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp3_10_3398813(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp3_10_3398813(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp3_10_3398813 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp3_10_3398813" << std::endl;
		smc->_V1_inTRp3_10_3398813(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp3_17_3398814()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp3_17_3398814" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp3_17_3398814(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp3_17_3398814();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp3_17_3398814(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp3_17_3398814(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp3_17_3398814(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp3_17_3398814 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp3_17_3398814" << std::endl;
		smc->_V1_inTRp3_17_3398814(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp12_1_3398818()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp12_1_3398818" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp12_1_3398818(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp12_1_3398818();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp12_1_3398818(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp12_1_3398818(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp12_1_3398818(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp12_1_3398818 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp12_1_3398818" << std::endl;
		smc->_V1_inTRp12_1_3398818(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp13_1_3398819()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp13_1_3398819" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp13_1_3398819(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp13_1_3398819();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp13_1_3398819(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp13_1_3398819(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp13_1_3398819(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp13_1_3398819 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp13_1_3398819" << std::endl;
		smc->_V1_inTRp13_1_3398819(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp1_27_3398823()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp1_27_3398823" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp1_27_3398823(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp1_27_3398823();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp1_27_3398823(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp1_27_3398823(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp1_27_3398823(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp1_27_3398823 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp1_27_3398823" << std::endl;
		smc->_V1_inTRp1_27_3398823(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp1_5_3398825()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp1_5_3398825" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp1_5_3398825(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp1_5_3398825();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp1_5_3398825(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp1_5_3398825(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp1_5_3398825(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp1_5_3398825 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp1_5_3398825" << std::endl;
		smc->_V1_inTRp1_5_3398825(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp2_5_3398826()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp2_5_3398826" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp2_5_3398826(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp2_5_3398826();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp2_5_3398826(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp2_5_3398826(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp2_5_3398826(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp2_5_3398826 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp2_5_3398826" << std::endl;
		smc->_V1_inTRp2_5_3398826(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp3_15_3398827()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp3_15_3398827" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp3_15_3398827(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp3_15_3398827();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp3_15_3398827(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp3_15_3398827(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp3_15_3398827(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp3_15_3398827 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp3_15_3398827" << std::endl;
		smc->_V1_inTRp3_15_3398827(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp1_31_3398828()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp1_31_3398828" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp1_31_3398828(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp1_31_3398828();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp1_31_3398828(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp1_31_3398828(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp1_31_3398828(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp1_31_3398828 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp1_31_3398828" << std::endl;
		smc->_V1_inTRp1_31_3398828(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp1_14_3398833()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp1_14_3398833" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp1_14_3398833(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp1_14_3398833();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp1_14_3398833(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp1_14_3398833(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp1_14_3398833(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp1_14_3398833 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp1_14_3398833" << std::endl;
		smc->_V1_inTRp1_14_3398833(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp1_32_3398834()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp1_32_3398834" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp1_32_3398834(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp1_32_3398834();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp1_32_3398834(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp1_32_3398834(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp1_32_3398834(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp1_32_3398834 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp1_32_3398834" << std::endl;
		smc->_V1_inTRp1_32_3398834(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp4_1_3398838()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp4_1_3398838" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp4_1_3398838(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp4_1_3398838();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp4_1_3398838(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp4_1_3398838(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp4_1_3398838(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp4_1_3398838 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp4_1_3398838" << std::endl;
		smc->_V1_inTRp4_1_3398838(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp14_1_3398841()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp14_1_3398841" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp14_1_3398841(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp14_1_3398841();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp14_1_3398841(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp14_1_3398841(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp14_1_3398841(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp14_1_3398841 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp14_1_3398841" << std::endl;
		smc->_V1_inTRp14_1_3398841(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp3_3_3398842()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp3_3_3398842" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp3_3_3398842(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp3_3_3398842();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp3_3_3398842(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp3_3_3398842(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp3_3_3398842(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp3_3_3398842 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp3_3_3398842" << std::endl;
		smc->_V1_inTRp3_3_3398842(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp2_8_3398847()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp2_8_3398847" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp2_8_3398847(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp2_8_3398847();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp2_8_3398847(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp2_8_3398847(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp2_8_3398847(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp2_8_3398847 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp2_8_3398847" << std::endl;
		smc->_V1_inTRp2_8_3398847(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp1_10_3398849()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp1_10_3398849" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp1_10_3398849(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp1_10_3398849();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp1_10_3398849(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp1_10_3398849(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp1_10_3398849(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp1_10_3398849 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp1_10_3398849" << std::endl;
		smc->_V1_inTRp1_10_3398849(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp2_6_3398850()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp2_6_3398850" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp2_6_3398850(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp2_6_3398850();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp2_6_3398850(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp2_6_3398850(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp2_6_3398850(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp2_6_3398850 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp2_6_3398850" << std::endl;
		smc->_V1_inTRp2_6_3398850(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp15_1_3398854()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp15_1_3398854" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp15_1_3398854(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp15_1_3398854();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp15_1_3398854(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp15_1_3398854(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp15_1_3398854(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp15_1_3398854 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp15_1_3398854" << std::endl;
		smc->_V1_inTRp15_1_3398854(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp16_1_3398856()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp16_1_3398856" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp16_1_3398856(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp16_1_3398856();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp16_1_3398856(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp16_1_3398856(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp16_1_3398856(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp16_1_3398856 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp16_1_3398856" << std::endl;
		smc->_V1_inTRp16_1_3398856(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp17_1_3398858()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp17_1_3398858" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp17_1_3398858(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp17_1_3398858();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp17_1_3398858(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp17_1_3398858(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp17_1_3398858(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp17_1_3398858 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp17_1_3398858" << std::endl;
		smc->_V1_inTRp17_1_3398858(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp1_15_3398859()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp1_15_3398859" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp1_15_3398859(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp1_15_3398859();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp1_15_3398859(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp1_15_3398859(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp1_15_3398859(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp1_15_3398859 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp1_15_3398859" << std::endl;
		smc->_V1_inTRp1_15_3398859(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp3_34_3398860()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp3_34_3398860" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp3_34_3398860(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp3_34_3398860();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp3_34_3398860(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp3_34_3398860(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp3_34_3398860(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp3_34_3398860 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp3_34_3398860" << std::endl;
		smc->_V1_inTRp3_34_3398860(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp1_24_3398861()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp1_24_3398861" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp1_24_3398861(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp1_24_3398861();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp1_24_3398861(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp1_24_3398861(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp1_24_3398861(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp1_24_3398861 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp1_24_3398861" << std::endl;
		smc->_V1_inTRp1_24_3398861(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp1_7_3398862()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp1_7_3398862" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp1_7_3398862(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp1_7_3398862();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp1_7_3398862(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp1_7_3398862(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp1_7_3398862(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp1_7_3398862 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp1_7_3398862" << std::endl;
		smc->_V1_inTRp1_7_3398862(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp17_2_3398864()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp17_2_3398864" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp17_2_3398864(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp17_2_3398864();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp17_2_3398864(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp17_2_3398864(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp17_2_3398864(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp17_2_3398864 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp17_2_3398864" << std::endl;
		smc->_V1_inTRp17_2_3398864(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp3_27_3398865()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp3_27_3398865" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp3_27_3398865(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp3_27_3398865();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp3_27_3398865(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp3_27_3398865(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp3_27_3398865(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp3_27_3398865 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp3_27_3398865" << std::endl;
		smc->_V1_inTRp3_27_3398865(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp4_2_3398868()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp4_2_3398868" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp4_2_3398868(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp4_2_3398868();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp4_2_3398868(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp4_2_3398868(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp4_2_3398868(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp4_2_3398868 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp4_2_3398868" << std::endl;
		smc->_V1_inTRp4_2_3398868(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp18_1_3398871()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp18_1_3398871" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp18_1_3398871(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp18_1_3398871();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp18_1_3398871(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp18_1_3398871(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp18_1_3398871(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp18_1_3398871 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp18_1_3398871" << std::endl;
		smc->_V1_inTRp18_1_3398871(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp3_22_3398872()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp3_22_3398872" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp3_22_3398872(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp3_22_3398872();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp3_22_3398872(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp3_22_3398872(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp3_22_3398872(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp3_22_3398872 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp3_22_3398872" << std::endl;
		smc->_V1_inTRp3_22_3398872(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp2_2_3398875()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp2_2_3398875" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp2_2_3398875(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp2_2_3398875();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp2_2_3398875(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp2_2_3398875(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp2_2_3398875(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp2_2_3398875 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp2_2_3398875" << std::endl;
		smc->_V1_inTRp2_2_3398875(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp4_1_3398876()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp4_1_3398876" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp4_1_3398876(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp4_1_3398876();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp4_1_3398876(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp4_1_3398876(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp4_1_3398876(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp4_1_3398876 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp4_1_3398876" << std::endl;
		smc->_V1_inTRp4_1_3398876(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}

void EventAPI::inTRp3_28_3398878()
{
	std::cout << "Checking Instance-Clause Preferences for Signal: inTRp3_28_3398878" << std::endl;
	std::vector<int> instance_clause_id = smc->c.getInstanceClauseIDofinTRp3_28_3398878(smc->getCurrentState(), false);
	if (instance_clause_id.at(0) == UNDEFINED_CHOICE || instance_clause_id.at(1) == UNDEFINED_CHOICE)
	{
		smc->_V1_inTRp3_28_3398878();
	}
	else
	{
		std::vector<int> list_of_instance_id = smc->c.getListOfInstanceIDofinTRp3_28_3398878(smc->getCurrentState(), false);
		bool isAtleastOneInstanceEnabled = false;
		for (unsigned int i = 0; i < list_of_instance_id.size(); i++)
		{
			if (smc->isEnabledV1_inTRp3_28_3398878(list_of_instance_id.at(i)))
			{
				instance_clause_id.at(0) = list_of_instance_id.at(i);
				std::vector<int> list_of_clause_id = smc->c.getListOfClauseIDofinTRp3_28_3398878(smc->getCurrentState(), list_of_instance_id.at(i), false);
				instance_clause_id.at(1) = list_of_clause_id.at(rand() % list_of_clause_id.size());
				isAtleastOneInstanceEnabled = true;
			}
		}
		if(!isAtleastOneInstanceEnabled)
			throw (StateMachineController::StubException("EXCEPTION: None of the instances of Signal: inTRp3_28_3398878 specified in the input file are enabled. Check the parameter set, if any!", NO_ENABLED_GUARDS));

		std::cout << "Instance-Clause ID ["<< instance_clause_id.at(0) <<":"<< instance_clause_id.at(1) <<"] found for Signal: inTRp3_28_3398878" << std::endl;
		smc->_V1_inTRp3_28_3398878(instance_clause_id.at(0), instance_clause_id.at(1));
	}
}
