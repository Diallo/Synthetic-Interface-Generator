#ifndef SRC_EVENTVIEWER_H_
#define SRC_EVENTVIEWER_H_

#include "common.h"

namespace StateMachineController {

class EventViewer {
public:

	EventViewer(int sim_mode);
	~EventViewer();

	#ifdef SSCF_VERSION
	static class StateMachineController::EventIndexData *evtIndxData;
	#endif
	static int _sim_mode;
	static void setSimMode(int sim_mode) { EventViewer::_sim_mode = sim_mode; }
	static void updateAvailableEvents(std::list<std::string>, std::list<std::string>, std::list<std::string>, std::list<std::string>);
	static std::vector<std::string> listOfAvailableEvents;
	static void renderConsole(std::list<std::string> evt_status_msg);
};

}
#endif /* SRC_EVENTVIEWER_H_ */

