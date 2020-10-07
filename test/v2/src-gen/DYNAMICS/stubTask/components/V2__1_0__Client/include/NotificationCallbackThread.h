#ifndef SRC_TIMER_H
#define SRC_TIMER_H


#include <thread>
#include <chrono>

#include "V2_StateMachineController.h"

namespace StateMachineController 
{
	class NotificationCallbackThread
	{
	public:
	    typedef std::chrono::milliseconds Interval;
	
	    //NotificationCallbackThread(class V2_StateMachineController *smc, int sim_mode);
	    NotificationCallbackThread(class V2_StateMachineController& smc, int sim_mode);
	    
		~NotificationCallbackThread();
	
	    void start(bool multiThread = false);
	    void stop();
	
	    bool running() const;
		void setSimMode(int sim_mode) { _sim_mode = sim_mode; }
	    void setSingleShot(bool singleShot);
	    bool isSingleShot() const;
	
	    void setInterval(const Interval &interval);
	    const Interval &interval() const;
	
	private:
	    std::thread _thread;
		// class V2_StateMachineController *_smc;
		class V2_StateMachineController& _smc;
		
		int _sim_mode;
	    bool _running;
	    bool _isSingleShot;
	
	    Interval _interval;
	
	    void _temporize();
	    void _sleepThenTimeout();
	};
}
#endif // SRC_TIMER_H
