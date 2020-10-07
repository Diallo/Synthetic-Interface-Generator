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
	std::vector<int> getInstanceClauseIDofinTRp2_1_3398721(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp2_1_3398721(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp2_1_3398721(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp3_1_3398722(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp3_1_3398722(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp3_1_3398722(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp1_1_3398723(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp1_1_3398723(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp1_1_3398723(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp3_2_3398726(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp3_2_3398726(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp3_2_3398726(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp2_1_3398728(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp2_1_3398728(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp2_1_3398728(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp3_4_3398729(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp3_4_3398729(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp3_4_3398729(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp2_1_3398732(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp2_1_3398732(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp2_1_3398732(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp3_5_3398734(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp3_5_3398734(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp3_5_3398734(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp3_4_3398737(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp3_4_3398737(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp3_4_3398737(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp2_2_3398739(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp2_2_3398739(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp2_2_3398739(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp3_10_3398741(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp3_10_3398741(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp3_10_3398741(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp1_2_3398742(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp1_2_3398742(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp1_2_3398742(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp1_2_3398743(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp1_2_3398743(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp1_2_3398743(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp1_4_3398746(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp1_4_3398746(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp1_4_3398746(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp3_9_3398747(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp3_9_3398747(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp3_9_3398747(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp3_5_3398749(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp3_5_3398749(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp3_5_3398749(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp3_4_3398750(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp3_4_3398750(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp3_4_3398750(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp3_9_3398751(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp3_9_3398751(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp3_9_3398751(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp3_8_3398752(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp3_8_3398752(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp3_8_3398752(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp2_1_3398753(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp2_1_3398753(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp2_1_3398753(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp2_3_3398754(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp2_3_3398754(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp2_3_3398754(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp1_5_3398755(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp1_5_3398755(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp1_5_3398755(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp2_1_3398757(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp2_1_3398757(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp2_1_3398757(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp1_3_3398758(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp1_3_3398758(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp1_3_3398758(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp3_5_3398760(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp3_5_3398760(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp3_5_3398760(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp3_12_3398765(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp3_12_3398765(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp3_12_3398765(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp1_8_3398767(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp1_8_3398767(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp1_8_3398767(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp3_9_3398768(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp3_9_3398768(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp3_9_3398768(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp3_11_3398770(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp3_11_3398770(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp3_11_3398770(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp2_4_3398772(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp2_4_3398772(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp2_4_3398772(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp3_26_3398774(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp3_26_3398774(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp3_26_3398774(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp5_1_3398776(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp5_1_3398776(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp5_1_3398776(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp3_8_3398780(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp3_8_3398780(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp3_8_3398780(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp2_3_3398781(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp2_3_3398781(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp2_3_3398781(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp1_2_3398783(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp1_2_3398783(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp1_2_3398783(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp1_14_3398785(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp1_14_3398785(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp1_14_3398785(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp3_12_3398786(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp3_12_3398786(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp3_12_3398786(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp3_12_3398787(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp3_12_3398787(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp3_12_3398787(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp1_16_3398790(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp1_16_3398790(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp1_16_3398790(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp3_13_3398792(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp3_13_3398792(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp3_13_3398792(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp10_1_3398795(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp10_1_3398795(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp10_1_3398795(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp11_1_3398796(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp11_1_3398796(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp11_1_3398796(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp3_18_3398798(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp3_18_3398798(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp3_18_3398798(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp9_1_3398800(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp9_1_3398800(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp9_1_3398800(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp3_14_3398803(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp3_14_3398803(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp3_14_3398803(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp10_1_3398805(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp10_1_3398805(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp10_1_3398805(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp5_3_3398807(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp5_3_3398807(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp5_3_3398807(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp1_9_3398808(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp1_9_3398808(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp1_9_3398808(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp1_2_3398812(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp1_2_3398812(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp1_2_3398812(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp3_10_3398813(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp3_10_3398813(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp3_10_3398813(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp3_17_3398814(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp3_17_3398814(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp3_17_3398814(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp12_1_3398818(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp12_1_3398818(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp12_1_3398818(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp13_1_3398819(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp13_1_3398819(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp13_1_3398819(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp1_27_3398823(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp1_27_3398823(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp1_27_3398823(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp1_5_3398825(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp1_5_3398825(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp1_5_3398825(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp2_5_3398826(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp2_5_3398826(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp2_5_3398826(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp3_15_3398827(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp3_15_3398827(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp3_15_3398827(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp1_31_3398828(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp1_31_3398828(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp1_31_3398828(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp1_14_3398833(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp1_14_3398833(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp1_14_3398833(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp1_32_3398834(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp1_32_3398834(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp1_32_3398834(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp4_1_3398838(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp4_1_3398838(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp4_1_3398838(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp14_1_3398841(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp14_1_3398841(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp14_1_3398841(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp3_3_3398842(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp3_3_3398842(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp3_3_3398842(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp2_8_3398847(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp2_8_3398847(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp2_8_3398847(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp1_10_3398849(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp1_10_3398849(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp1_10_3398849(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp2_6_3398850(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp2_6_3398850(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp2_6_3398850(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp15_1_3398854(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp15_1_3398854(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp15_1_3398854(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp16_1_3398856(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp16_1_3398856(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp16_1_3398856(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp17_1_3398858(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp17_1_3398858(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp17_1_3398858(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp1_15_3398859(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp1_15_3398859(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp1_15_3398859(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp3_34_3398860(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp3_34_3398860(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp3_34_3398860(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp1_24_3398861(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp1_24_3398861(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp1_24_3398861(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp1_7_3398862(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp1_7_3398862(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp1_7_3398862(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp17_2_3398864(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp17_2_3398864(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp17_2_3398864(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp3_27_3398865(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp3_27_3398865(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp3_27_3398865(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp4_2_3398868(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp4_2_3398868(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp4_2_3398868(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp18_1_3398871(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp18_1_3398871(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp18_1_3398871(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp3_22_3398872(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp3_22_3398872(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp3_22_3398872(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp2_2_3398875(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp2_2_3398875(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp2_2_3398875(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp4_1_3398876(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp4_1_3398876(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp4_1_3398876(string state, int instance_id, bool print_to_console)
	{
		std::vector<int> list_of_clause_id;
		list_of_clause_id.push_back(UNDEFINED_CHOICE);
		return list_of_clause_id;
	}
	std::vector<int> getInstanceClauseIDofinTRp3_28_3398878(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfInstanceIDofinTRp3_28_3398878(string state, bool print_to_console)
	{
		std::vector<int> list_of_instance_id;
		list_of_instance_id.push_back(UNDEFINED_CHOICE);
		return list_of_instance_id;
	}

	std::vector<int> getListOfClauseIDofinTRp3_28_3398878(string state, int instance_id, bool print_to_console)
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
