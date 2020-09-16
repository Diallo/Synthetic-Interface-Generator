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

	static StateMachineController::outTRp1_2_12_Handler m_outTRp1_2_12CB;
	void register_outTRp1_2_12CB(StateMachineController::outTRp1_2_12_Handler _outTRp1_2_12CB) { this->m_outTRp1_2_12CB = _outTRp1_2_12CB; }
	static StateMachineController::outTRp1_1_15_Handler m_outTRp1_1_15CB;
	void register_outTRp1_1_15CB(StateMachineController::outTRp1_1_15_Handler _outTRp1_1_15CB) { this->m_outTRp1_1_15CB = _outTRp1_1_15CB; }
	static StateMachineController::outTRp1_1_16_Handler m_outTRp1_1_16CB;
	void register_outTRp1_1_16CB(StateMachineController::outTRp1_1_16_Handler _outTRp1_1_16CB) { this->m_outTRp1_1_16CB = _outTRp1_1_16CB; }
	static StateMachineController::outTRp1_6_19_Handler m_outTRp1_6_19CB;
	void register_outTRp1_6_19CB(StateMachineController::outTRp1_6_19_Handler _outTRp1_6_19CB) { this->m_outTRp1_6_19CB = _outTRp1_6_19CB; }
	static StateMachineController::outTRp1_8_21_Handler m_outTRp1_8_21CB;
	void register_outTRp1_8_21CB(StateMachineController::outTRp1_8_21_Handler _outTRp1_8_21CB) { this->m_outTRp1_8_21CB = _outTRp1_8_21CB; }
	static StateMachineController::outTRp1_6_22_Handler m_outTRp1_6_22CB;
	void register_outTRp1_6_22CB(StateMachineController::outTRp1_6_22_Handler _outTRp1_6_22CB) { this->m_outTRp1_6_22CB = _outTRp1_6_22CB; }
	static StateMachineController::outTRp1_9_23_Handler m_outTRp1_9_23CB;
	void register_outTRp1_9_23CB(StateMachineController::outTRp1_9_23_Handler _outTRp1_9_23CB) { this->m_outTRp1_9_23CB = _outTRp1_9_23CB; }

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

	static void outTRp1_2_12()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp1_2_12!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp1_2_12CB != nullptr)
			m_outTRp1_2_12CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp1_1_15()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp1_1_15!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp1_1_15CB != nullptr)
			m_outTRp1_1_15CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp1_1_16()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp1_1_16!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp1_1_16CB != nullptr)
			m_outTRp1_1_16CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp1_6_19()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp1_6_19!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp1_6_19CB != nullptr)
			m_outTRp1_6_19CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp1_8_21()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp1_8_21!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp1_8_21CB != nullptr)
			m_outTRp1_8_21CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp1_6_22()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp1_6_22!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp1_6_22CB != nullptr)
			m_outTRp1_6_22CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp1_9_23()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp1_9_23!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp1_9_23CB != nullptr)
			m_outTRp1_9_23CB();
		
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

	void inTRp1_1_11();
	void inTRp1_3_13();
	void inTRp1_4_14();
	void inTRp2_1_17();
	void inTRp3_1_18();
	
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

