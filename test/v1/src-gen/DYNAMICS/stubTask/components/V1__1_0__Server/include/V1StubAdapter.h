#include "common.h"
#include "EventRepository.h"
#include "V1_StateMachineController.h"
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

	static StateMachineController::outTRp1_2_25_Handler m_outTRp1_2_25CB;
	void register_outTRp1_2_25CB(StateMachineController::outTRp1_2_25_Handler _outTRp1_2_25CB) { this->m_outTRp1_2_25CB = _outTRp1_2_25CB; }
	static StateMachineController::outTRp1_3_26_Handler m_outTRp1_3_26CB;
	void register_outTRp1_3_26CB(StateMachineController::outTRp1_3_26_Handler _outTRp1_3_26CB) { this->m_outTRp1_3_26CB = _outTRp1_3_26CB; }
	static StateMachineController::outTRp1_5_28_Handler m_outTRp1_5_28CB;
	void register_outTRp1_5_28CB(StateMachineController::outTRp1_5_28_Handler _outTRp1_5_28CB) { this->m_outTRp1_5_28CB = _outTRp1_5_28CB; }
	static StateMachineController::outTRp1_6_29_Handler m_outTRp1_6_29CB;
	void register_outTRp1_6_29CB(StateMachineController::outTRp1_6_29_Handler _outTRp1_6_29CB) { this->m_outTRp1_6_29CB = _outTRp1_6_29CB; }
	static StateMachineController::outTRp1_6_30_Handler m_outTRp1_6_30CB;
	void register_outTRp1_6_30CB(StateMachineController::outTRp1_6_30_Handler _outTRp1_6_30CB) { this->m_outTRp1_6_30CB = _outTRp1_6_30CB; }

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

	static void outTRp1_2_25()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp1_2_25!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp1_2_25CB != nullptr)
			m_outTRp1_2_25CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp1_3_26()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp1_3_26!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp1_3_26CB != nullptr)
			m_outTRp1_3_26CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp1_5_28()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp1_5_28!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp1_5_28CB != nullptr)
			m_outTRp1_5_28CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp1_6_29()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp1_6_29!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp1_6_29CB != nullptr)
			m_outTRp1_6_29CB();
		
		cv.notify_one();

		std::cout << std::endl;
	}
	static void outTRp1_6_30()
	{
		std::cout << std::endl;
		std::cout << "[INFO] @STUB_ADAPTER: Waiting to acquire lock..." << std::endl;
		std::lock_guard<std::mutex> guard(mtx);
		std::cout << "[INFO] @STUB_ADAPTER: Lock acquired!" << std::endl;

		std::cout << "[INFO] @STUB_ADAPTER: Received Notification: outTRp1_6_30!" << std::endl;
		
		// Call the registered callback, if any
		if(m_outTRp1_6_30CB != nullptr)
			m_outTRp1_6_30CB();
		
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

	void inTRp1_1_24();
	void inTRp1_1_27();
	void inTRp2_1_31();
	void inTRp3_1_32();
	void inTRp3_1_33();
	
	// TODO: Temporary, For Debug, To be removed!
	// StateMachineController::vendingMachine_StateMachineController& getSMCPtr() { return *smc; }

private:
	int sim_mode;
	std::list<std::string> commandInitlist;
	std::list<std::string> signalInitlist;
	std::list<std::string> notificationInitlist;

	StateMachineController::EventViewer *ev;
	StateMachineController::EventRepository *er;
	StateMachineController::V1_StateMachineController *smc;
	StateMachineController::SimulatorConfiguration sc;
};

