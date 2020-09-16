#ifndef INPUT_PARAMETERS_CONTAINER_H_
#define INPUT_PARAMETERS_CONTAINER_H_

#include "common.h"

namespace StateMachineController {

class InputParametersContainer 
{
	public:
	
	// Local Variables
	
	
	std::list<std::string> logged_gui_msgs;
					
	//constructor
	InputParametersContainer() 
	{
	}
	
	void selectParameterContext() {
	logged_gui_msgs.clear();
	}
	
	std::list<std::string> getLoggedGUIMsgs() { return logged_gui_msgs; }
	
	void clearLoggedMsgs() { logged_gui_msgs.clear(); }
	
	~InputParametersContainer() { }

	// Getters for Clause Instance ID of Events Not Present in Input Specification
	std::vector<int> getInstanceClauseIDofinTRp1_1_11(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp1_1_11(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp1_1_11(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp1_3_13(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp1_3_13(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp1_3_13(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp1_4_14(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp1_4_14(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp1_4_14(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp2_1_17(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp2_1_17(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp2_1_17(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp3_1_18(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp3_1_18(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp3_1_18(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}

	// use the type: InstanceClauseID
	// 1. Getter for the list of Instance IDs (for a event, in a given state)

	// 2. Getter for the list of Clause IDs (for an instance id of an event in a given state)

	// Getters for Clause Instance ID [Original]

	// Getters for Input Parameters of Events
};
}

#endif /*INPUT_PARAMETERS_CONTAINER_H_ */
