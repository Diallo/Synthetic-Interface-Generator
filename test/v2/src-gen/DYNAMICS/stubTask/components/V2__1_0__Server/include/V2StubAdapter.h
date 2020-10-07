#include "common.h"
#include "EventRepository.h"
#include "V2_StateMachineController.h"
#include "EventViewer.h"
#include "InputParametersContainer.h"

#include <condition_variable>
#include <time.h>

#define NI_TIMEOUT 10
#define UNREF_PARAM(x) x

class NotificationEventHandler
{
public:
	NotificationEventHandler() { isTimeOut = std::cv_status::no_timeout; }
	~NotificationEventHandler();

	static std::mutex mtx;
	static std::condition_variable cv;

	static StateMachineController::outTRp1_1_3398718_Handler m_outTRp1_1_3398718CB;
	void register_outTRp1_1_3398718CB(StateMachineController::outTRp1_1_3398718_Handler _outTRp1_1_3398718CB) { this->m_outTRp1_1_3398718CB = _outTRp1_1_3398718CB; }
	static StateMachineController::outTRp1_1_3398719_Handler m_outTRp1_1_3398719CB;
	void register_outTRp1_1_3398719CB(StateMachineController::outTRp1_1_3398719_Handler _outTRp1_1_3398719CB) { this->m_outTRp1_1_3398719CB = _outTRp1_1_3398719CB; }
	static StateMachineController::outTRp1_1_3398720_Handler m_outTRp1_1_3398720CB;
	void register_outTRp1_1_3398720CB(StateMachineController::outTRp1_1_3398720_Handler _outTRp1_1_3398720CB) { this->m_outTRp1_1_3398720CB = _outTRp1_1_3398720CB; }
	static StateMachineController::outTRp3_1_3398724_Handler m_outTRp3_1_3398724CB;
	void register_outTRp3_1_3398724CB(StateMachineController::outTRp3_1_3398724_Handler _outTRp3_1_3398724CB) { this->m_outTRp3_1_3398724CB = _outTRp3_1_3398724CB; }
	static StateMachineController::outTRp1_4_3398725_Handler m_outTRp1_4_3398725CB;
	void register_outTRp1_4_3398725CB(StateMachineController::outTRp1_4_3398725_Handler _outTRp1_4_3398725CB) { this->m_outTRp1_4_3398725CB = _outTRp1_4_3398725CB; }
	static StateMachineController::outTRp3_3_3398727_Handler m_outTRp3_3_3398727CB;
	void register_outTRp3_3_3398727CB(StateMachineController::outTRp3_3_3398727_Handler _outTRp3_3_3398727CB) { this->m_outTRp3_3_3398727CB = _outTRp3_3_3398727CB; }
	static StateMachineController::outTRp3_4_3398731_Handler m_outTRp3_4_3398731CB;
	void register_outTRp3_4_3398731CB(StateMachineController::outTRp3_4_3398731_Handler _outTRp3_4_3398731CB) { this->m_outTRp3_4_3398731CB = _outTRp3_4_3398731CB; }
	static StateMachineController::outTRp3_5_3398733_Handler m_outTRp3_5_3398733CB;
	void register_outTRp3_5_3398733CB(StateMachineController::outTRp3_5_3398733_Handler _outTRp3_5_3398733CB) { this->m_outTRp3_5_3398733CB = _outTRp3_5_3398733CB; }
	static StateMachineController::outTRp3_2_3398735_Handler m_outTRp3_2_3398735CB;
	void register_outTRp3_2_3398735CB(StateMachineController::outTRp3_2_3398735_Handler _outTRp3_2_3398735CB) { this->m_outTRp3_2_3398735CB = _outTRp3_2_3398735CB; }
	static StateMachineController::outTRp3_3_3398736_Handler m_outTRp3_3_3398736CB;
	void register_outTRp3_3_3398736CB(StateMachineController::outTRp3_3_3398736_Handler _outTRp3_3_3398736CB) { this->m_outTRp3_3_3398736CB = _outTRp3_3_3398736CB; }
	static StateMachineController::outTRp1_1_3398738_Handler m_outTRp1_1_3398738CB;
	void register_outTRp1_1_3398738CB(StateMachineController::outTRp1_1_3398738_Handler _outTRp1_1_3398738CB) { this->m_outTRp1_1_3398738CB = _outTRp1_1_3398738CB; }
	static StateMachineController::outTRp2_3_3398740_Handler m_outTRp2_3_3398740CB;
	void register_outTRp2_3_3398740CB(StateMachineController::outTRp2_3_3398740_Handler _outTRp2_3_3398740CB) { this->m_outTRp2_3_3398740CB = _outTRp2_3_3398740CB; }
	static StateMachineController::outTRp4_1_3398744_Handler m_outTRp4_1_3398744CB;
	void register_outTRp4_1_3398744CB(StateMachineController::outTRp4_1_3398744_Handler _outTRp4_1_3398744CB) { this->m_outTRp4_1_3398744CB = _outTRp4_1_3398744CB; }
	static StateMachineController::outTRp5_1_3398745_Handler m_outTRp5_1_3398745CB;
	void register_outTRp5_1_3398745CB(StateMachineController::outTRp5_1_3398745_Handler _outTRp5_1_3398745CB) { this->m_outTRp5_1_3398745CB = _outTRp5_1_3398745CB; }
	static StateMachineController::outTRp3_10_3398748_Handler m_outTRp3_10_3398748CB;
	void register_outTRp3_10_3398748CB(StateMachineController::outTRp3_10_3398748_Handler _outTRp3_10_3398748CB) { this->m_outTRp3_10_3398748CB = _outTRp3_10_3398748CB; }
	static StateMachineController::outTRp1_6_3398756_Handler m_outTRp1_6_3398756CB;
	void register_outTRp1_6_3398756CB(StateMachineController::outTRp1_6_3398756_Handler _outTRp1_6_3398756CB) { this->m_outTRp1_6_3398756CB = _outTRp1_6_3398756CB; }
	static StateMachineController::outTRp1_4_3398759_Handler m_outTRp1_4_3398759CB;
	void register_outTRp1_4_3398759CB(StateMachineController::outTRp1_4_3398759_Handler _outTRp1_4_3398759CB) { this->m_outTRp1_4_3398759CB = _outTRp1_4_3398759CB; }
	static StateMachineController::outTRp3_6_3398761_Handler m_outTRp3_6_3398761CB;
	void register_outTRp3_6_3398761CB(StateMachineController::outTRp3_6_3398761_Handler _outTRp3_6_3398761CB) { this->m_outTRp3_6_3398761CB = _outTRp3_6_3398761CB; }
	static StateMachineController::outTRp2_6_3398762_Handler m_outTRp2_6_3398762CB;
	void register_outTRp2_6_3398762CB(StateMachineController::outTRp2_6_3398762_Handler _outTRp2_6_3398762CB) { this->m_outTRp2_6_3398762CB = _outTRp2_6_3398762CB; }
	static StateMachineController::outTRp3_4_3398763_Handler m_outTRp3_4_3398763CB;
	void register_outTRp3_4_3398763CB(StateMachineController::outTRp3_4_3398763_Handler _outTRp3_4_3398763CB) { this->m_outTRp3_4_3398763CB = _outTRp3_4_3398763CB; }
	static StateMachineController::outTRp3_11_3398764_Handler m_outTRp3_11_3398764CB;
	void register_outTRp3_11_3398764CB(StateMachineController::outTRp3_11_3398764_Handler _outTRp3_11_3398764CB) { this->m_outTRp3_11_3398764CB = _outTRp3_11_3398764CB; }
	static StateMachineController::outTRp3_8_3398766_Handler m_outTRp3_8_3398766CB;
	void register_outTRp3_8_3398766CB(StateMachineController::outTRp3_8_3398766_Handler _outTRp3_8_3398766CB) { this->m_outTRp3_8_3398766CB = _outTRp3_8_3398766CB; }
	static StateMachineController::outTRp1_10_3398769_Handler m_outTRp1_10_3398769CB;
	void register_outTRp1_10_3398769CB(StateMachineController::outTRp1_10_3398769_Handler _outTRp1_10_3398769CB) { this->m_outTRp1_10_3398769CB = _outTRp1_10_3398769CB; }
	static StateMachineController::outTRp3_12_3398771_Handler m_outTRp3_12_3398771CB;
	void register_outTRp3_12_3398771CB(StateMachineController::outTRp3_12_3398771_Handler _outTRp3_12_3398771CB) { this->m_outTRp3_12_3398771CB = _outTRp3_12_3398771CB; }
	static StateMachineController::outTRp6_1_3398773_Handler m_outTRp6_1_3398773CB;
	void register_outTRp6_1_3398773CB(StateMachineController::outTRp6_1_3398773_Handler _outTRp6_1_3398773CB) { this->m_outTRp6_1_3398773CB = _outTRp6_1_3398773CB; }
	static StateMachineController::outTRp7_1_3398775_Handler m_outTRp7_1_3398775CB;
	void register_outTRp7_1_3398775CB(StateMachineController::outTRp7_1_3398775_Handler _outTRp7_1_3398775CB) { this->m_outTRp7_1_3398775CB = _outTRp7_1_3398775CB; }
	static StateMachineController::outTRp5_2_3398777_Handler m_outTRp5_2_3398777CB;
	void register_outTRp5_2_3398777CB(StateMachineController::outTRp5_2_3398777_Handler _outTRp5_2_3398777CB) { this->m_outTRp5_2_3398777CB = _outTRp5_2_3398777CB; }
	static StateMachineController::outTRp1_6_3398778_Handler m_outTRp1_6_3398778CB;
	void register_outTRp1_6_3398778CB(StateMachineController::outTRp1_6_3398778_Handler _outTRp1_6_3398778CB) { this->m_outTRp1_6_3398778CB = _outTRp1_6_3398778CB; }
	static StateMachineController::outTRp1_14_3398782_Handler m_outTRp1_14_3398782CB;
	void register_outTRp1_14_3398782CB(StateMachineController::outTRp1_14_3398782_Handler _outTRp1_14_3398782CB) { this->m_outTRp1_14_3398782CB = _outTRp1_14_3398782CB; }
	static StateMachineController::outTRp1_3_3398784_Handler m_outTRp1_3_3398784CB;
	void register_outTRp1_3_3398784CB(StateMachineController::outTRp1_3_3398784_Handler _outTRp1_3_3398784CB) { this->m_outTRp1_3_3398784CB = _outTRp1_3_3398784CB; }
	static StateMachineController::outTRp8_1_3398788_Handler m_outTRp8_1_3398788CB;
	void register_outTRp8_1_3398788CB(StateMachineController::outTRp8_1_3398788_Handler _outTRp8_1_3398788CB) { this->m_outTRp8_1_3398788CB = _outTRp8_1_3398788CB; }
	static StateMachineController::outTRp9_1_3398789_Handler m_outTRp9_1_3398789CB;
	void register_outTRp9_1_3398789CB(StateMachineController::outTRp9_1_3398789_Handler _outTRp9_1_3398789CB) { this->m_outTRp9_1_3398789CB = _outTRp9_1_3398789CB; }
	static StateMachineController::outTRp1_17_3398791_Handler m_outTRp1_17_3398791CB;
	void register_outTRp1_17_3398791CB(StateMachineController::outTRp1_17_3398791_Handler _outTRp1_17_3398791CB) { this->m_outTRp1_17_3398791CB = _outTRp1_17_3398791CB; }
	static StateMachineController::outTRp1_7_3398793_Handler m_outTRp1_7_3398793CB;
	void register_outTRp1_7_3398793CB(StateMachineController::outTRp1_7_3398793_Handler _outTRp1_7_3398793CB) { this->m_outTRp1_7_3398793CB = _outTRp1_7_3398793CB; }
	static StateMachineController::outTRp1_7_3398794_Handler m_outTRp1_7_3398794CB;
	void register_outTRp1_7_3398794CB(StateMachineController::outTRp1_7_3398794_Handler _outTRp1_7_3398794CB) { this->m_outTRp1_7_3398794CB = _outTRp1_7_3398794CB; }
	static StateMachineController::outTRp1_4_3398797_Handler m_outTRp1_4_3398797CB;
	void register_outTRp1_4_3398797CB(StateMachineController::outTRp1_4_3398797_Handler _outTRp1_4_3398797CB) { this->m_outTRp1_4_3398797CB = _outTRp1_4_3398797CB; }
	static StateMachineController::outTRp3_29_3398799_Handler m_outTRp3_29_3398799CB;
	void register_outTRp3_29_3398799CB(StateMachineController::outTRp3_29_3398799_Handler _outTRp3_29_3398799CB) { this->m_outTRp3_29_3398799CB = _outTRp3_29_3398799CB; }
	static StateMachineController::outTRp9_2_3398801_Handler m_outTRp9_2_3398801CB;
	void register_outTRp9_2_3398801CB(StateMachineController::outTRp9_2_3398801_Handler _outTRp9_2_3398801CB) { this->m_outTRp9_2_3398801CB = _outTRp9_2_3398801CB; }
	static StateMachineController::outTRp3_13_3398802_Handler m_outTRp3_13_3398802CB;
	void register_outTRp3_13_3398802CB(StateMachineController::outTRp3_13_3398802_Handler _outTRp3_13_3398802CB) { this->m_outTRp3_13_3398802CB = _outTRp3_13_3398802CB; }
	static StateMachineController::outTRp1_7_3398804_Handler m_outTRp1_7_3398804CB;
	void register_outTRp1_7_3398804CB(StateMachineController::outTRp1_7_3398804_Handler _outTRp1_7_3398804CB) { this->m_outTRp1_7_3398804CB = _outTRp1_7_3398804CB; }
	static StateMachineController::outTRp3_32_3398806_Handler m_outTRp3_32_3398806CB;
	void register_outTRp3_32_3398806CB(StateMachineController::outTRp3_32_3398806_Handler _outTRp3_32_3398806CB) { this->m_outTRp3_32_3398806CB = _outTRp3_32_3398806CB; }
	static StateMachineController::outTRp1_20_3398809_Handler m_outTRp1_20_3398809CB;
	void register_outTRp1_20_3398809CB(StateMachineController::outTRp1_20_3398809_Handler _outTRp1_20_3398809CB) { this->m_outTRp1_20_3398809CB = _outTRp1_20_3398809CB; }
	static StateMachineController::outTRp9_3_3398810_Handler m_outTRp9_3_3398810CB;
	void register_outTRp9_3_3398810CB(StateMachineController::outTRp9_3_3398810_Handler _outTRp9_3_3398810CB) { this->m_outTRp9_3_3398810CB = _outTRp9_3_3398810CB; }
	static StateMachineController::outTRp1_1_3398811_Handler m_outTRp1_1_3398811CB;
	void register_outTRp1_1_3398811CB(StateMachineController::outTRp1_1_3398811_Handler _outTRp1_1_3398811CB) { this->m_outTRp1_1_3398811CB = _outTRp1_1_3398811CB; }
	static StateMachineController::outTRp1_9_3398815_Handler m_outTRp1_9_3398815CB;
	void register_outTRp1_9_3398815CB(StateMachineController::outTRp1_9_3398815_Handler _outTRp1_9_3398815CB) { this->m_outTRp1_9_3398815CB = _outTRp1_9_3398815CB; }
	static StateMachineController::outTRp5_4_3398816_Handler m_outTRp5_4_3398816CB;
	void register_outTRp5_4_3398816CB(StateMachineController::outTRp5_4_3398816_Handler _outTRp5_4_3398816CB) { this->m_outTRp5_4_3398816CB = _outTRp5_4_3398816CB; }
	static StateMachineController::outTRp5_4_3398817_Handler m_outTRp5_4_3398817CB;
	void register_outTRp5_4_3398817CB(StateMachineController::outTRp5_4_3398817_Handler _outTRp5_4_3398817CB) { this->m_outTRp5_4_3398817CB = _outTRp5_4_3398817CB; }
	static StateMachineController::outTRp1_25_3398820_Handler m_outTRp1_25_3398820CB;
	void register_outTRp1_25_3398820CB(StateMachineController::outTRp1_25_3398820_Handler _outTRp1_25_3398820CB) { this->m_outTRp1_25_3398820CB = _outTRp1_25_3398820CB; }
	static StateMachineController::outTRp2_10_3398821_Handler m_outTRp2_10_3398821CB;
	void register_outTRp2_10_3398821CB(StateMachineController::outTRp2_10_3398821_Handler _outTRp2_10_3398821CB) { this->m_outTRp2_10_3398821CB = _outTRp2_10_3398821CB; }
	static StateMachineController::outTRp1_26_3398822_Handler m_outTRp1_26_3398822CB;
	void register_outTRp1_26_3398822CB(StateMachineController::outTRp1_26_3398822_Handler _outTRp1_26_3398822CB) { this->m_outTRp1_26_3398822CB = _outTRp1_26_3398822CB; }
	static StateMachineController::outTRp11_1_3398824_Handler m_outTRp11_1_3398824CB;
	void register_outTRp11_1_3398824CB(StateMachineController::outTRp11_1_3398824_Handler _outTRp11_1_3398824CB) { this->m_outTRp11_1_3398824CB = _outTRp11_1_3398824CB; }
	static StateMachineController::outTRp9_1_3398829_Handler m_outTRp9_1_3398829CB;
	void register_outTRp9_1_3398829CB(StateMachineController::outTRp9_1_3398829_Handler _outTRp9_1_3398829CB) { this->m_outTRp9_1_3398829CB = _outTRp9_1_3398829CB; }
	static StateMachineController::outTRp3_2_3398830_Handler m_outTRp3_2_3398830CB;
	void register_outTRp3_2_3398830CB(StateMachineController::outTRp3_2_3398830_Handler _outTRp3_2_3398830CB) { this->m_outTRp3_2_3398830CB = _outTRp3_2_3398830CB; }
	static StateMachineController::outTRp9_5_3398831_Handler m_outTRp9_5_3398831CB;
	void register_outTRp9_5_3398831CB(StateMachineController::outTRp9_5_3398831_Handler _outTRp9_5_3398831CB) { this->m_outTRp9_5_3398831CB = _outTRp9_5_3398831CB; }
	static StateMachineController::outTRp1_21_3398832_Handler m_outTRp1_21_3398832CB;
	void register_outTRp1_21_3398832CB(StateMachineController::outTRp1_21_3398832_Handler _outTRp1_21_3398832CB) { this->m_outTRp1_21_3398832CB = _outTRp1_21_3398832CB; }
	static StateMachineController::outTRp3_29_3398835_Handler m_outTRp3_29_3398835CB;
	void register_outTRp3_29_3398835CB(StateMachineController::outTRp3_29_3398835_Handler _outTRp3_29_3398835CB) { this->m_outTRp3_29_3398835CB = _outTRp3_29_3398835CB; }
	static StateMachineController::outTRp3_21_3398836_Handler m_outTRp3_21_3398836CB;
	void register_outTRp3_21_3398836CB(StateMachineController::outTRp3_21_3398836_Handler _outTRp3_21_3398836CB) { this->m_outTRp3_21_3398836CB = _outTRp3_21_3398836CB; }
	static StateMachineController::outTRp1_20_3398837_Handler m_outTRp1_20_3398837CB;
	void register_outTRp1_20_3398837CB(StateMachineController::outTRp1_20_3398837_Handler _outTRp1_20_3398837CB) { this->m_outTRp1_20_3398837CB = _outTRp1_20_3398837CB; }
	static StateMachineController::outTRp4_2_3398839_Handler m_outTRp4_2_3398839CB;
	void register_outTRp4_2_3398839CB(StateMachineController::outTRp4_2_3398839_Handler _outTRp4_2_3398839CB) { this->m_outTRp4_2_3398839CB = _outTRp4_2_3398839CB; }
	static StateMachineController::outTRp3_8_3398840_Handler m_outTRp3_8_3398840CB;
	void register_outTRp3_8_3398840CB(StateMachineController::outTRp3_8_3398840_Handler _outTRp3_8_3398840CB) { this->m_outTRp3_8_3398840CB = _outTRp3_8_3398840CB; }
	static StateMachineController::outTRp1_5_3398844_Handler m_outTRp1_5_3398844CB;
	void register_outTRp1_5_3398844CB(StateMachineController::outTRp1_5_3398844_Handler _outTRp1_5_3398844CB) { this->m_outTRp1_5_3398844CB = _outTRp1_5_3398844CB; }
	static StateMachineController::outTRp1_12_3398846_Handler m_outTRp1_12_3398846CB;
	void register_outTRp1_12_3398846CB(StateMachineController::outTRp1_12_3398846_Handler _outTRp1_12_3398846CB) { this->m_outTRp1_12_3398846CB = _outTRp1_12_3398846CB; }
	static StateMachineController::outTRp2_9_3398848_Handler m_outTRp2_9_3398848CB;
	void register_outTRp2_9_3398848CB(StateMachineController::outTRp2_9_3398848_Handler _outTRp2_9_3398848CB) { this->m_outTRp2_9_3398848CB = _outTRp2_9_3398848CB; }
	static StateMachineController::outTRp2_7_3398851_Handler m_outTRp2_7_3398851CB;
	void register_outTRp2_7_3398851CB(StateMachineController::outTRp2_7_3398851_Handler _outTRp2_7_3398851CB) { this->m_outTRp2_7_3398851CB = _outTRp2_7_3398851CB; }
	static StateMachineController::outTRp3_13_3398852_Handler m_outTRp3_13_3398852CB;
	void register_outTRp3_13_3398852CB(StateMachineController::outTRp3_13_3398852_Handler _outTRp3_13_3398852CB) { this->m_outTRp3_13_3398852CB = _outTRp3_13_3398852CB; }
	static StateMachineController::outTRp3_40_3398853_Handler m_outTRp3_40_3398853CB;
	void register_outTRp3_40_3398853CB(StateMachineController::outTRp3_40_3398853_Handler _outTRp3_40_3398853CB) { this->m_outTRp3_40_3398853CB = _outTRp3_40_3398853CB; }
	static StateMachineController::outTRp3_40_3398855_Handler m_outTRp3_40_3398855CB;
	void register_outTRp3_40_3398855CB(StateMachineController::outTRp3_40_3398855_Handler _outTRp3_40_3398855CB) { this->m_outTRp3_40_3398855CB = _outTRp3_40_3398855CB; }
	static StateMachineController::outTRp3_6_3398857_Handler m_outTRp3_6_3398857CB;
	void register_outTRp3_6_3398857CB(StateMachineController::outTRp3_6_3398857_Handler _outTRp3_6_3398857CB) { this->m_outTRp3_6_3398857CB = _outTRp3_6_3398857CB; }
	static StateMachineController::outTRp17_1_3398863_Handler m_outTRp17_1_3398863CB;
	void register_outTRp17_1_3398863CB(StateMachineController::outTRp17_1_3398863_Handler _outTRp17_1_3398863CB) { this->m_outTRp17_1_3398863CB = _outTRp17_1_3398863CB; }
	static StateMachineController::outTRp1_3_3398866_Handler m_outTRp1_3_3398866CB;
	void register_outTRp1_3_3398866CB(StateMachineController::outTRp1_3_3398866_Handler _outTRp1_3_3398866CB) { this->m_outTRp1_3_3398866CB = _outTRp1_3_3398866CB; }
	static StateMachineController::outTRp3_10_3398867_Handler m_outTRp3_10_3398867CB;
	void register_outTRp3_10_3398867CB(StateMachineController::outTRp3_10_3398867_Handler _outTRp3_10_3398867CB) { this->m_outTRp3_10_3398867CB = _outTRp3_10_3398867CB; }
	static StateMachineController::outTRp4_3_3398869_Handler m_outTRp4_3_3398869CB;
	void register_outTRp4_3_3398869CB(StateMachineController::outTRp4_3_3398869_Handler _outTRp4_3_3398869CB) { this->m_outTRp4_3_3398869CB = _outTRp4_3_3398869CB; }
	static StateMachineController::outTRp9_1_3398870_Handler m_outTRp9_1_3398870CB;
	void register_outTRp9_1_3398870CB(StateMachineController::outTRp9_1_3398870_Handler _outTRp9_1_3398870CB) { this->m_outTRp9_1_3398870CB = _outTRp9_1_3398870CB; }
	static StateMachineController::outTRp4_2_3398873_Handler m_outTRp4_2_3398873CB;
	void register_outTRp4_2_3398873CB(StateMachineController::outTRp4_2_3398873_Handler _outTRp4_2_3398873CB) { this->m_outTRp4_2_3398873CB = _outTRp4_2_3398873CB; }
	static StateMachineController::outTRp2_1_3398874_Handler m_outTRp2_1_3398874CB;
	void register_outTRp2_1_3398874CB(StateMachineController::outTRp2_1_3398874_Handler _outTRp2_1_3398874CB) { this->m_outTRp2_1_3398874CB = _outTRp2_1_3398874CB; }
	static StateMachineController::outTRp19_1_3398877_Handler m_outTRp19_1_3398877CB;
	void register_outTRp19_1_3398877CB(StateMachineController::outTRp19_1_3398877_Handler _outTRp19_1_3398877CB) { this->m_outTRp19_1_3398877CB = _outTRp19_1_3398877CB; }
	static StateMachineController::outTRp1_10_3398879_Handler m_outTRp1_10_3398879CB;
	void register_outTRp1_10_3398879CB(StateMachineController::outTRp1_10_3398879_Handler _outTRp1_10_3398879CB) { this->m_outTRp1_10_3398879CB = _outTRp1_10_3398879CB; }
	static StateMachineController::outTRp3_52_3398880_Handler m_outTRp3_52_3398880CB;
	void register_outTRp3_52_3398880CB(StateMachineController::outTRp3_52_3398880_Handler _outTRp3_52_3398880CB) { this->m_outTRp3_52_3398880CB = _outTRp3_52_3398880CB; }
	static StateMachineController::outTRp3_52_3398881_Handler m_outTRp3_52_3398881CB;
	void register_outTRp3_52_3398881CB(StateMachineController::outTRp3_52_3398881_Handler _outTRp3_52_3398881CB) { this->m_outTRp3_52_3398881CB = _outTRp3_52_3398881CB; }
	static StateMachineController::outTRp3_41_3398883_Handler m_outTRp3_41_3398883CB;
	void register_outTRp3_41_3398883CB(StateMachineController::outTRp3_41_3398883_Handler _outTRp3_41_3398883CB) { this->m_outTRp3_41_3398883CB = _outTRp3_41_3398883CB; }
	static StateMachineController::outTRp3_36_3398884_Handler m_outTRp3_36_3398884CB;
	void register_outTRp3_36_3398884CB(StateMachineController::outTRp3_36_3398884_Handler _outTRp3_36_3398884CB) { this->m_outTRp3_36_3398884CB = _outTRp3_36_3398884CB; }
	static StateMachineController::outTRp3_34_3398885_Handler m_outTRp3_34_3398885CB;
	void register_outTRp3_34_3398885CB(StateMachineController::outTRp3_34_3398885_Handler _outTRp3_34_3398885CB) { this->m_outTRp3_34_3398885CB = _outTRp3_34_3398885CB; }
	static StateMachineController::outTRp3_31_3398886_Handler m_outTRp3_31_3398886CB;
	void register_outTRp3_31_3398886CB(StateMachineController::outTRp3_31_3398886_Handler _outTRp3_31_3398886CB) { this->m_outTRp3_31_3398886CB = _outTRp3_31_3398886CB; }
	static StateMachineController::outTRp3_29_3398887_Handler m_outTRp3_29_3398887CB;
	void register_outTRp3_29_3398887CB(StateMachineController::outTRp3_29_3398887_Handler _outTRp3_29_3398887CB) { this->m_outTRp3_29_3398887CB = _outTRp3_29_3398887CB; }
	static StateMachineController::outTRp3_18_3398888_Handler m_outTRp3_18_3398888CB;
	void register_outTRp3_18_3398888CB(StateMachineController::outTRp3_18_3398888_Handler _outTRp3_18_3398888CB) { this->m_outTRp3_18_3398888CB = _outTRp3_18_3398888CB; }
	static StateMachineController::outTRp3_60_3398889_Handler m_outTRp3_60_3398889CB;
	void register_outTRp3_60_3398889CB(StateMachineController::outTRp3_60_3398889_Handler _outTRp3_60_3398889CB) { this->m_outTRp3_60_3398889CB = _outTRp3_60_3398889CB; }
	static StateMachineController::outTRp3_62_3398890_Handler m_outTRp3_62_3398890CB;
	void register_outTRp3_62_3398890CB(StateMachineController::outTRp3_62_3398890_Handler _outTRp3_62_3398890CB) { this->m_outTRp3_62_3398890CB = _outTRp3_62_3398890CB; }
	static StateMachineController::outTRp3_60_3398891_Handler m_outTRp3_60_3398891CB;
	void register_outTRp3_60_3398891CB(StateMachineController::outTRp3_60_3398891_Handler _outTRp3_60_3398891CB) { this->m_outTRp3_60_3398891CB = _outTRp3_60_3398891CB; }
	static StateMachineController::outTRp3_62_3398892_Handler m_outTRp3_62_3398892CB;
	void register_outTRp3_62_3398892CB(StateMachineController::outTRp3_62_3398892_Handler _outTRp3_62_3398892CB) { this->m_outTRp3_62_3398892CB = _outTRp3_62_3398892CB; }
	static StateMachineController::outTRp3_62_3398893_Handler m_outTRp3_62_3398893CB;
	void register_outTRp3_62_3398893CB(StateMachineController::outTRp3_62_3398893_Handler _outTRp3_62_3398893CB) { this->m_outTRp3_62_3398893CB = _outTRp3_62_3398893CB; }
	static StateMachineController::outTRp3_61_3398894_Handler m_outTRp3_61_3398894CB;
	void register_outTRp3_61_3398894CB(StateMachineController::outTRp3_61_3398894_Handler _outTRp3_61_3398894CB) { this->m_outTRp3_61_3398894CB = _outTRp3_61_3398894CB; }

	// TODO Handle Unexpected Notification!
	static void niEvt(std::string val)
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: " << val << std::endl;
		cv.notify_one();

		std::cout << std::endl;
	}

	static void outTRp1_1_3398718()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp1_1_3398718!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp1_1_3398718CB != nullptr)
			m_outTRp1_1_3398718CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp1_1_3398719()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp1_1_3398719!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp1_1_3398719CB != nullptr)
			m_outTRp1_1_3398719CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp1_1_3398720()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp1_1_3398720!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp1_1_3398720CB != nullptr)
			m_outTRp1_1_3398720CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp3_1_3398724()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp3_1_3398724!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp3_1_3398724CB != nullptr)
			m_outTRp3_1_3398724CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp1_4_3398725()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp1_4_3398725!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp1_4_3398725CB != nullptr)
			m_outTRp1_4_3398725CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp3_3_3398727()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp3_3_3398727!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp3_3_3398727CB != nullptr)
			m_outTRp3_3_3398727CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp3_4_3398731()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp3_4_3398731!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp3_4_3398731CB != nullptr)
			m_outTRp3_4_3398731CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp3_5_3398733()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp3_5_3398733!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp3_5_3398733CB != nullptr)
			m_outTRp3_5_3398733CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp3_2_3398735()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp3_2_3398735!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp3_2_3398735CB != nullptr)
			m_outTRp3_2_3398735CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp3_3_3398736()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp3_3_3398736!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp3_3_3398736CB != nullptr)
			m_outTRp3_3_3398736CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp1_1_3398738()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp1_1_3398738!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp1_1_3398738CB != nullptr)
			m_outTRp1_1_3398738CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp2_3_3398740()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp2_3_3398740!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp2_3_3398740CB != nullptr)
			m_outTRp2_3_3398740CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp4_1_3398744()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp4_1_3398744!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp4_1_3398744CB != nullptr)
			m_outTRp4_1_3398744CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp5_1_3398745()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp5_1_3398745!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp5_1_3398745CB != nullptr)
			m_outTRp5_1_3398745CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp3_10_3398748()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp3_10_3398748!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp3_10_3398748CB != nullptr)
			m_outTRp3_10_3398748CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp1_6_3398756()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp1_6_3398756!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp1_6_3398756CB != nullptr)
			m_outTRp1_6_3398756CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp1_4_3398759()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp1_4_3398759!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp1_4_3398759CB != nullptr)
			m_outTRp1_4_3398759CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp3_6_3398761()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp3_6_3398761!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp3_6_3398761CB != nullptr)
			m_outTRp3_6_3398761CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp2_6_3398762()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp2_6_3398762!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp2_6_3398762CB != nullptr)
			m_outTRp2_6_3398762CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp3_4_3398763()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp3_4_3398763!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp3_4_3398763CB != nullptr)
			m_outTRp3_4_3398763CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp3_11_3398764()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp3_11_3398764!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp3_11_3398764CB != nullptr)
			m_outTRp3_11_3398764CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp3_8_3398766()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp3_8_3398766!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp3_8_3398766CB != nullptr)
			m_outTRp3_8_3398766CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp1_10_3398769()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp1_10_3398769!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp1_10_3398769CB != nullptr)
			m_outTRp1_10_3398769CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp3_12_3398771()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp3_12_3398771!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp3_12_3398771CB != nullptr)
			m_outTRp3_12_3398771CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp6_1_3398773()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp6_1_3398773!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp6_1_3398773CB != nullptr)
			m_outTRp6_1_3398773CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp7_1_3398775()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp7_1_3398775!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp7_1_3398775CB != nullptr)
			m_outTRp7_1_3398775CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp5_2_3398777()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp5_2_3398777!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp5_2_3398777CB != nullptr)
			m_outTRp5_2_3398777CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp1_6_3398778()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp1_6_3398778!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp1_6_3398778CB != nullptr)
			m_outTRp1_6_3398778CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp1_14_3398782()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp1_14_3398782!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp1_14_3398782CB != nullptr)
			m_outTRp1_14_3398782CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp1_3_3398784()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp1_3_3398784!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp1_3_3398784CB != nullptr)
			m_outTRp1_3_3398784CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp8_1_3398788()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp8_1_3398788!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp8_1_3398788CB != nullptr)
			m_outTRp8_1_3398788CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp9_1_3398789()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp9_1_3398789!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp9_1_3398789CB != nullptr)
			m_outTRp9_1_3398789CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp1_17_3398791()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp1_17_3398791!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp1_17_3398791CB != nullptr)
			m_outTRp1_17_3398791CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp1_7_3398793()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp1_7_3398793!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp1_7_3398793CB != nullptr)
			m_outTRp1_7_3398793CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp1_7_3398794()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp1_7_3398794!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp1_7_3398794CB != nullptr)
			m_outTRp1_7_3398794CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp1_4_3398797()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp1_4_3398797!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp1_4_3398797CB != nullptr)
			m_outTRp1_4_3398797CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp3_29_3398799()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp3_29_3398799!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp3_29_3398799CB != nullptr)
			m_outTRp3_29_3398799CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp9_2_3398801()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp9_2_3398801!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp9_2_3398801CB != nullptr)
			m_outTRp9_2_3398801CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp3_13_3398802()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp3_13_3398802!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp3_13_3398802CB != nullptr)
			m_outTRp3_13_3398802CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp1_7_3398804()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp1_7_3398804!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp1_7_3398804CB != nullptr)
			m_outTRp1_7_3398804CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp3_32_3398806()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp3_32_3398806!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp3_32_3398806CB != nullptr)
			m_outTRp3_32_3398806CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp1_20_3398809()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp1_20_3398809!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp1_20_3398809CB != nullptr)
			m_outTRp1_20_3398809CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp9_3_3398810()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp9_3_3398810!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp9_3_3398810CB != nullptr)
			m_outTRp9_3_3398810CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp1_1_3398811()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp1_1_3398811!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp1_1_3398811CB != nullptr)
			m_outTRp1_1_3398811CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp1_9_3398815()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp1_9_3398815!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp1_9_3398815CB != nullptr)
			m_outTRp1_9_3398815CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp5_4_3398816()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp5_4_3398816!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp5_4_3398816CB != nullptr)
			m_outTRp5_4_3398816CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp5_4_3398817()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp5_4_3398817!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp5_4_3398817CB != nullptr)
			m_outTRp5_4_3398817CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp1_25_3398820()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp1_25_3398820!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp1_25_3398820CB != nullptr)
			m_outTRp1_25_3398820CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp2_10_3398821()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp2_10_3398821!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp2_10_3398821CB != nullptr)
			m_outTRp2_10_3398821CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp1_26_3398822()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp1_26_3398822!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp1_26_3398822CB != nullptr)
			m_outTRp1_26_3398822CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp11_1_3398824()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp11_1_3398824!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp11_1_3398824CB != nullptr)
			m_outTRp11_1_3398824CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp9_1_3398829()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp9_1_3398829!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp9_1_3398829CB != nullptr)
			m_outTRp9_1_3398829CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp3_2_3398830()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp3_2_3398830!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp3_2_3398830CB != nullptr)
			m_outTRp3_2_3398830CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp9_5_3398831()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp9_5_3398831!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp9_5_3398831CB != nullptr)
			m_outTRp9_5_3398831CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp1_21_3398832()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp1_21_3398832!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp1_21_3398832CB != nullptr)
			m_outTRp1_21_3398832CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp3_29_3398835()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp3_29_3398835!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp3_29_3398835CB != nullptr)
			m_outTRp3_29_3398835CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp3_21_3398836()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp3_21_3398836!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp3_21_3398836CB != nullptr)
			m_outTRp3_21_3398836CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp1_20_3398837()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp1_20_3398837!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp1_20_3398837CB != nullptr)
			m_outTRp1_20_3398837CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp4_2_3398839()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp4_2_3398839!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp4_2_3398839CB != nullptr)
			m_outTRp4_2_3398839CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp3_8_3398840()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp3_8_3398840!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp3_8_3398840CB != nullptr)
			m_outTRp3_8_3398840CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp1_5_3398844()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp1_5_3398844!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp1_5_3398844CB != nullptr)
			m_outTRp1_5_3398844CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp1_12_3398846()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp1_12_3398846!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp1_12_3398846CB != nullptr)
			m_outTRp1_12_3398846CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp2_9_3398848()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp2_9_3398848!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp2_9_3398848CB != nullptr)
			m_outTRp2_9_3398848CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp2_7_3398851()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp2_7_3398851!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp2_7_3398851CB != nullptr)
			m_outTRp2_7_3398851CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp3_13_3398852()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp3_13_3398852!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp3_13_3398852CB != nullptr)
			m_outTRp3_13_3398852CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp3_40_3398853()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp3_40_3398853!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp3_40_3398853CB != nullptr)
			m_outTRp3_40_3398853CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp3_40_3398855()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp3_40_3398855!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp3_40_3398855CB != nullptr)
			m_outTRp3_40_3398855CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp3_6_3398857()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp3_6_3398857!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp3_6_3398857CB != nullptr)
			m_outTRp3_6_3398857CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp17_1_3398863()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp17_1_3398863!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp17_1_3398863CB != nullptr)
			m_outTRp17_1_3398863CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp1_3_3398866()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp1_3_3398866!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp1_3_3398866CB != nullptr)
			m_outTRp1_3_3398866CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp3_10_3398867()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp3_10_3398867!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp3_10_3398867CB != nullptr)
			m_outTRp3_10_3398867CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp4_3_3398869()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp4_3_3398869!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp4_3_3398869CB != nullptr)
			m_outTRp4_3_3398869CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp9_1_3398870()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp9_1_3398870!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp9_1_3398870CB != nullptr)
			m_outTRp9_1_3398870CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp4_2_3398873()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp4_2_3398873!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp4_2_3398873CB != nullptr)
			m_outTRp4_2_3398873CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp2_1_3398874()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp2_1_3398874!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp2_1_3398874CB != nullptr)
			m_outTRp2_1_3398874CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp19_1_3398877()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp19_1_3398877!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp19_1_3398877CB != nullptr)
			m_outTRp19_1_3398877CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp1_10_3398879()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp1_10_3398879!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp1_10_3398879CB != nullptr)
			m_outTRp1_10_3398879CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp3_52_3398880()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp3_52_3398880!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp3_52_3398880CB != nullptr)
			m_outTRp3_52_3398880CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp3_52_3398881()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp3_52_3398881!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp3_52_3398881CB != nullptr)
			m_outTRp3_52_3398881CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp3_41_3398883()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp3_41_3398883!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp3_41_3398883CB != nullptr)
			m_outTRp3_41_3398883CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp3_36_3398884()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp3_36_3398884!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp3_36_3398884CB != nullptr)
			m_outTRp3_36_3398884CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp3_34_3398885()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp3_34_3398885!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp3_34_3398885CB != nullptr)
			m_outTRp3_34_3398885CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp3_31_3398886()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp3_31_3398886!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp3_31_3398886CB != nullptr)
			m_outTRp3_31_3398886CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp3_29_3398887()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp3_29_3398887!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp3_29_3398887CB != nullptr)
			m_outTRp3_29_3398887CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp3_18_3398888()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp3_18_3398888!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp3_18_3398888CB != nullptr)
			m_outTRp3_18_3398888CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp3_60_3398889()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp3_60_3398889!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp3_60_3398889CB != nullptr)
			m_outTRp3_60_3398889CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp3_62_3398890()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp3_62_3398890!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp3_62_3398890CB != nullptr)
			m_outTRp3_62_3398890CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp3_60_3398891()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp3_60_3398891!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp3_60_3398891CB != nullptr)
			m_outTRp3_60_3398891CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp3_62_3398892()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp3_62_3398892!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp3_62_3398892CB != nullptr)
			m_outTRp3_62_3398892CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp3_62_3398893()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp3_62_3398893!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp3_62_3398893CB != nullptr)
			m_outTRp3_62_3398893CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp3_61_3398894()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp3_61_3398894!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp3_61_3398894CB != nullptr)
			m_outTRp3_61_3398894CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}

	void waitForEvent();

private:
	std::cv_status isTimeOut;
};

class EventAPI
{
public:
	EventAPI();
	~EventAPI() 
	{
		delete smc; 
		delete er; 
		delete ev;
	}

	void inTRp2_1_3398721();
	void inTRp3_1_3398722();
	void inTRp1_1_3398723();
	void inTRp3_2_3398726();
	void inTRp2_1_3398728();
	void inTRp3_4_3398729();
	void inTRp2_1_3398732();
	void inTRp3_5_3398734();
	void inTRp3_4_3398737();
	void inTRp2_2_3398739();
	void inTRp3_10_3398741();
	void inTRp1_2_3398742();
	void inTRp1_2_3398743();
	void inTRp1_4_3398746();
	void inTRp3_9_3398747();
	void inTRp3_5_3398749();
	void inTRp3_4_3398750();
	void inTRp3_9_3398751();
	void inTRp3_8_3398752();
	void inTRp2_1_3398753();
	void inTRp2_3_3398754();
	void inTRp1_5_3398755();
	void inTRp2_1_3398757();
	void inTRp1_3_3398758();
	void inTRp3_5_3398760();
	void inTRp3_12_3398765();
	void inTRp1_8_3398767();
	void inTRp3_9_3398768();
	void inTRp3_11_3398770();
	void inTRp2_4_3398772();
	void inTRp3_26_3398774();
	void inTRp5_1_3398776();
	void inTRp3_8_3398780();
	void inTRp2_3_3398781();
	void inTRp1_2_3398783();
	void inTRp1_14_3398785();
	void inTRp3_12_3398786();
	void inTRp3_12_3398787();
	void inTRp1_16_3398790();
	void inTRp3_13_3398792();
	void inTRp10_1_3398795();
	void inTRp11_1_3398796();
	void inTRp3_18_3398798();
	void inTRp9_1_3398800();
	void inTRp3_14_3398803();
	void inTRp10_1_3398805();
	void inTRp5_3_3398807();
	void inTRp1_9_3398808();
	void inTRp1_2_3398812();
	void inTRp3_10_3398813();
	void inTRp3_17_3398814();
	void inTRp12_1_3398818();
	void inTRp13_1_3398819();
	void inTRp1_27_3398823();
	void inTRp1_5_3398825();
	void inTRp2_5_3398826();
	void inTRp3_15_3398827();
	void inTRp1_31_3398828();
	void inTRp1_14_3398833();
	void inTRp1_32_3398834();
	void inTRp4_1_3398838();
	void inTRp14_1_3398841();
	void inTRp3_3_3398842();
	void inTRp2_8_3398847();
	void inTRp1_10_3398849();
	void inTRp2_6_3398850();
	void inTRp15_1_3398854();
	void inTRp16_1_3398856();
	void inTRp17_1_3398858();
	void inTRp1_15_3398859();
	void inTRp3_34_3398860();
	void inTRp1_24_3398861();
	void inTRp1_7_3398862();
	void inTRp17_2_3398864();
	void inTRp3_27_3398865();
	void inTRp4_2_3398868();
	void inTRp18_1_3398871();
	void inTRp3_22_3398872();
	void inTRp2_2_3398875();
	void inTRp4_1_3398876();
	void inTRp3_28_3398878();
	
	// TODO: Temporary, For Debug, To be removed!
	// StateMachineController::vendingMachine_StateMachineController& getSMCPtr() { return *smc; }

private:
	int sim_mode;
	std::list<std::string> commandInitlist;
	std::list<std::string> signalInitlist;
	std::list<std::string> notificationInitlist;

	StateMachineController::EventViewer *ev;
	StateMachineController::EventRepository *er;
	StateMachineController::V2_StateMachineController *smc;
	StateMachineController::SimulatorConfiguration sc;
};

