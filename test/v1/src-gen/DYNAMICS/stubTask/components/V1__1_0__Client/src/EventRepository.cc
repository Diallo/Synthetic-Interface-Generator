#include "EventRepository.h"

namespace StateMachineController {

//TODO: IF SSCF SERVER STATE MACHINE
/*
EventRepository::EventRepository(const list<string>& command_list,
		const list<string>& signal_list,
		const list<string>& notification_list, class SscfSampleServer *srv)
{
	m_cbHandler = nullptr;

	// TODO: IF SSCF SERVER STATE MACHINE
	// m_serverPtr = srv;

	if(!command_list.empty()) setCommandsMap(command_list, true);
	if(!signal_list.empty()) setSignalsMap(signal_list, true);
	if(!notification_list.empty()) setNotificationsMap(notification_list, true);
	// cout<<"\n Event Repository has been constructed! \n";
} */

EventRepository::EventRepository(const list<string>& command_list,
		const list<string>& signal_list,
		const list<string>& notification_list)
{
	m_cbHandler = nullptr;
	if(!command_list.empty()) setCommandsMap(command_list, true);
	if(!signal_list.empty()) setSignalsMap(signal_list, true);
	if(!notification_list.empty()) setNotificationsMap(notification_list, true);
	// cout<<std::endl<<"INFO: Event Repository has been constructed!"<<std::endl;
}


EventRepository::~EventRepository() {
	std::cout << std::endl << "Destroying Event Repository! " << std::endl;
}

void EventRepository::printStr(string s) {
	//cout<<"ER_DEBUG: "<<s<<"\n";
}

// This should be called by the State Machine Controller and No one Else!
void EventRepository::setEventsMap(const list<string>& command_list,
								const list<string>& signal_list,
								const list<string>& notification_list,
								const list<string>& evt_status_msg)
{
	setCommandsMap(command_list, true);
	setSignalsMap(signal_list, true);
	setNotificationsMap(notification_list, true);
	raiseNotification(evt_status_msg);
}

void EventRepository::raiseNotification(const list<string>& evt_status_msg)
{
	//TODO: IF SSCF SERVER STATE MACHINE
	/*
	if(m_serverPtr != nullptr)
	{
		m_serverPtr->raiseNotificationDataUpdate(getEnabledCommands(),
												getEnabledSignals(),
												getEnabledNotifications(),
												evt_status_msg);
	}
	else
	{
		cout<<"SSCF Client is not yet registered.."<<std::endl;
	} */
	
	if(this->m_cbHandler != nullptr)
	{
		// cout<<"INFO: Raising Notification to Event Viewer \n";
		m_cbHandler(getEnabledCommands(),
			getEnabledSignals(),
			getEnabledNotifications(),
			evt_status_msg);

	}
	else
	{
		cout<<"No Event Viewer Assigned! Not raising notification.. \n";
	}
}

void EventRepository::setCommandsMap(const list<string>& commandList, bool isEnabled){

	for(auto const &map_entry : commands_map)
		if(map_entry.second)
			commands_map[map_entry.first] = false;

	list<string>::const_iterator it = commandList.begin();
	while(it != commandList.end())
	{
		if(commands_map.find(*it) == commands_map.end()){
			commands_map.insert(make_pair(*it, isEnabled));
			printStr("Adding Command Entry: "+ *it);
		}
		else{
			commands_map[*it] = isEnabled;
			printStr("Updated Command isEnabled: "+ *it);
		}
		it++;
	}
	//raiseNotification();
}

void EventRepository::setSignalsMap(const list<string>& signalList, bool isEnabled){
	for(auto const &map_entry : signals_map)
		if(map_entry.second)
			signals_map[map_entry.first] = false;

	list<string>::const_iterator it = signalList.begin();
	while(it != signalList.end())
	{
		if(signals_map.find(*it) == signals_map.end()){
			signals_map.insert(make_pair(*it, isEnabled));
			printStr("Adding Signal Entry: "+ *it);
		}
		else{
			signals_map[*it] = isEnabled;
			printStr("Updated Signal isEnabled: "+ *it);
		}
		it++;
	}
	//raiseNotification();
}

void EventRepository::setNotificationsMap(const list<string>& notificationList, bool isEnabled){
	for(auto const &map_entry : notifications_map)
		if(map_entry.second)
			notifications_map[map_entry.first] = false;

	list<string>::const_iterator it = notificationList.begin();
	while(it != notificationList.end())
	{
		if(notifications_map.find(*it) == notifications_map.end()){
			notifications_map.insert(make_pair(*it, isEnabled));
			printStr("Adding Notification Entry: "+ *it);
		}
		else{
			notifications_map[*it] = isEnabled;
			printStr("Updated Notification isEnabled: "+ *it);
		}
		it++;
	}
	//raiseNotification();
}

list<string> EventRepository::getEnabledCommands() {
	//std::list<string> clist = {};
	std::list<string> clist;
	//clist.push_back("");
	for(auto const &map_entry : commands_map) {
		if(map_entry.second)
		{
			printStr("------ \n COMM Name: " + map_entry.first +
				"\t" + "isEnabled: " + to_string(map_entry.second) + "\n");
			clist.push_back(map_entry.first);
		}
	}
	return clist;
}

list<string> EventRepository::getEnabledSignals() {
	std::list<string> slist; // = {};
	for(auto const &map_entry : signals_map) {
		if(map_entry.second)
		{
			printStr("------ \n SIG Name: " + map_entry.first +
				"\t" + "isEnabled: " + to_string(map_entry.second) + "\n");
			slist.push_back(map_entry.first);
		}
	}
	return slist;
}

list<string> EventRepository::getEnabledNotifications() {
	std::list<string> nlist; // = {};
	for(auto const &map_entry : notifications_map) {
		if(map_entry.second)
		{
			printStr("------ \n NI Name: " + map_entry.first +
				"\t" + "isEnabled: " + to_string(map_entry.second) + "\n");
			nlist.push_back(map_entry.first);
		}
	}
	return nlist;
}
}
