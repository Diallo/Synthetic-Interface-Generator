#ifndef SRC_EVENTREPOSITORY_H_
#define SRC_EVENTREPOSITORY_H_

#include "common.h"

//TODO: IF SSCF SERVER STATE MACHINE
//#include "SampleServer.h"

namespace StateMachineController {

using namespace std;

class EventRepository {

public:
	EventRepository(){m_cbHandler = nullptr;}

	//TODO: IF SSCF SERVER STATE MACHINE
	/* EventRepository(const list<string>& command_list,
			const list<string>& signal_list,
			const list<string>& notification_list,
			class SscfSampleServer *srv); */

	EventRepository(const list<string>& command_list,
			const list<string>& signal_list,
			const list<string>& notification_list);

	~EventRepository();

	void setEventsMap(const list<string>& command_list,
					const list<string>& signal_list,
					const list<string>& notification_list,
					const list<string>& evt_status_msg);
	void setCommandsMap(const list<string>& command_list, bool isEnabled);
	void setSignalsMap(const list<string>& signal_list, bool isEnabled);
	void setNotificationsMap(const list<string>& notification_list, bool isEnabled);
	void raiseNotification(const list<string>& evt_status_msg);

	void RegisterDataChangeHandler(callBackHandler cbHandler) {
		this->m_cbHandler = cbHandler; }

	// TODO: IF SSCF SERVER STATE MACHINE
	//class SscfSampleServer *m_serverPtr;

private:
	callBackHandler m_cbHandler; //= nullptr;

	map<string, bool> commands_map;
	map<string, bool> signals_map;
	map<string, bool> notifications_map;

	list<string> getEnabledCommands();
	list<string> getEnabledSignals();
	list<string> getEnabledNotifications();
	void printStr(string s);
};
}
#endif /* SRC_EVENTREPOSITORY_H_ */
