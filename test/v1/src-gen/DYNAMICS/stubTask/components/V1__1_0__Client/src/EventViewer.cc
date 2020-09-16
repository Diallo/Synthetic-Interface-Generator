#include "EventViewer.h"

namespace StateMachineController {

std::vector<std::string> EventViewer::listOfAvailableEvents;
int EventViewer::_sim_mode;

#ifdef SSCF_VERSION
StateMachineController::EventIndexData* EventViewer::evtIndxData = new StateMachineController::EventIndexData();
#endif

EventViewer::EventViewer(int sim_mode) {
	// std::cout<<std::endl<<"INFO: Event Viewer has been constructed!"<<std::endl;
	EventViewer::_sim_mode = sim_mode;
}

EventViewer::~EventViewer() { EventViewer::listOfAvailableEvents.clear(); std::cout << std::endl << "Destroying Event Viewer! " << std::endl; }

void EventViewer::renderConsole(std::list<std::string> evt_status_msg) 
{
	for(auto msg: evt_status_msg) 
	{
		std::cout << std::endl << std::endl; // << "----------------------------------------------" << std::endl;
		std::cout<<"[INFO] > "<<msg<<std::endl << std::endl;
		//cout<<"----------------------------------------------"<<std::endl;
	}

	std::cout<<"----------------------------------------------------------" << std::endl;
	std::cout << "  Available Events: " << std::endl; 
	std::cout<<"----------------------------------------------------------" << std::endl;

	for(auto evt : EventViewer::listOfAvailableEvents)
	{
	#ifndef SSCF_VERSION
	std::cout<<eventIndex.at(evt)<<": \t"<<evt<<"\n";
	#endif
	#ifdef SSCF_VERSION
	std::cout<<EventViewer::evtIndxData->geteventIndex().at(evt)<<": \t"<<evt<<std::endl;
	#endif
	}
	
	if (EventViewer::listOfAvailableEvents.size() == 0)
	{
		std::cout << "There are no Enabled Events in the Current State!" << std::endl;
		// std::cout << "Please inspect the Interface Specification." << std::endl;
	}
	std::cout<<"----------------------------------------------------------" << std::endl;
}

// TODO: Update Depending on whether this is for a Client or Server Stub
void EventViewer::updateAvailableEvents(std::list<std::string> comm,
										std::list<std::string> sig,
										std::list<std::string> ni,
										std::list<std::string> evt_status_msg)
{
	EventViewer::listOfAvailableEvents.clear();
	
	if(EventViewer::_sim_mode == SERVER_STUB) {
		for(std::list<std::string>::iterator iter = comm.begin(); iter != comm.end(); iter++){
			EventViewer::listOfAvailableEvents.push_back(*iter);
		}

		for(std::list<std::string>::iterator iter = sig.begin(); iter != sig.end(); iter++){
	EventViewer::listOfAvailableEvents.push_back(*iter);
		}
	}
	else if(EventViewer::_sim_mode == CLIENT_STUB) {
		for(std::list<std::string>::iterator iter = ni.begin(); iter != ni.end(); iter++){
			EventViewer::listOfAvailableEvents.push_back(*iter);
		}
	}
	else if(EventViewer::_sim_mode == UI) {
		for(std::list<std::string>::iterator iter = comm.begin(); iter != comm.end(); iter++){
			EventViewer::listOfAvailableEvents.push_back(*iter);
		}
		for(std::list<std::string>::iterator iter = sig.begin(); iter != sig.end(); iter++){
			EventViewer::listOfAvailableEvents.push_back(*iter);
		}
		for(std::list<std::string>::iterator iter = ni.begin(); iter != ni.end(); iter++){
			EventViewer::listOfAvailableEvents.push_back(*iter);
		}
	}
	else
		std::cout << std::endl << "FATAL ERROR: BUG in Simulator!" << std::endl;

	EventViewer::renderConsole(evt_status_msg);
}

}
