	#ifndef COMMON_H_
	#define COMMON_H_
	
	
	#define UNDEFINED_INT 0
	#define UNDEFINED_STRING "UNDEFINED"
	#define UNDEFINED_REAL 0.0
	#define UNDEFINED_BULKDATA 0.0
	#define UNDEFINED_BOOL false
	#define UNDEFINED_CHOICE -1
	#define UNREF_PARAM(x) x
	
	#include <list>
	#include <string>
	#include <sstream>
	#include <iostream>
	#include <vector>
	#include <map>
	#include <iterator>
	#include <cstdlib>
	#include <cmath>
	#include <ctime>
	#include <random>
	#include <algorithm>
	#include <functional>
	#include <exception>
	#include <fstream>
	
	#pragma warning(disable: 4100 4189)

	// Removed for SSCF support
	// using namespace std;
	
	// Event Repository to Event Viewer Callback Function Pointer
	// typedef void (*callBackHandler)(list<std::string>, list<std::string>, list<std::string>, list<std::string>);
	typedef std::function<void(std::list<std::string>, std::list<std::string>, std::list<std::string>, std::list<std::string>)> callBackHandler;
	
	// For Test Main subscription to SMC Notifications
	// typedef void (*niHandler)(std::string);
	typedef std::function<void(std::string)> niHandler;
	
	// Map comMA real type to C++ double
	typedef double real;
	typedef double bulkdata;
	
	namespace StateMachineController {
	
		using namespace std;
			
		//--------- Start of All User Types --------------
	
		// First Simple Types
		namespace V1 {
			namespace Response {
			// Enum Type Declarations
			enum Response { 
				ACK,
				UPDATE,
				UNDEFINED
			};
			const char* const enumResponse2str[] = { "ACK", "UPDATE", "UNDEFINED"};
			}
			
		}
	
		//--------- END of All User Types --------------

		// Notification Handlers
		typedef std::function<void()> outTRp1_2_25_Handler;
		typedef std::function<void()> outTRp1_3_26_Handler;
		typedef std::function<void()> outTRp1_5_28_Handler;
		typedef std::function<void()> outTRp1_6_29_Handler;
		typedef std::function<void()> outTRp1_6_30_Handler;
	
		#ifndef SSCF_VERSION
		const std::map<std::string,int> eventIndex = {
			std::make_pair("V1_inTRp1_1_24",0),
			std::make_pair("V1_inTRp1_1_27",1),
			std::make_pair("V1_inTRp2_1_31",2),
			std::make_pair("V1_inTRp3_1_32",3),
			std::make_pair("V1_inTRp3_1_33",4),
			std::make_pair("V1_outTRp1_2_25",5),
			std::make_pair("V1_outTRp1_3_26",6),
			std::make_pair("V1_outTRp1_5_28",7),
			std::make_pair("V1_outTRp1_6_29",8),
			std::make_pair("V1_outTRp1_6_30",9),

			std::make_pair("UNDEFINED", 10)
		};
		#endif

	#define START_STOP_INDEX 10
	#define SERVER_STUB 1
	#define CLIENT_STUB 2
	#define UI 3


	#ifdef SSCF_VERSION
	class EventIndexData
	{
		public:
			EventIndexData() 
			{
				eventIndex.insert(std::make_pair("V1_inTRp1_1_24",0));
				eventIndex.insert(std::make_pair("V1_inTRp1_1_27",1));
				eventIndex.insert(std::make_pair("V1_inTRp2_1_31",2));
				eventIndex.insert(std::make_pair("V1_inTRp3_1_32",3));
				eventIndex.insert(std::make_pair("V1_inTRp3_1_33",4));
				eventIndex.insert(std::make_pair("V1_outTRp1_2_25",5));
				eventIndex.insert(std::make_pair("V1_outTRp1_3_26",6));
				eventIndex.insert(std::make_pair("V1_outTRp1_5_28",7));
				eventIndex.insert(std::make_pair("V1_outTRp1_6_29",8));
				eventIndex.insert(std::make_pair("V1_outTRp1_6_30",9));
				eventIndex.insert(std::make_pair("UNDEFINED", 10));
			}
	
			~EventIndexData() { }
			
			const std::map<std::string,int> & geteventIndex() const { return eventIndex; }
	
		private:
			std::map<std::string,int> eventIndex;
	};
	#endif

	/*
	class ConsolePrinter
	{
	public:
		ConsolePrinter() {}
		~ConsolePrinter() {}
	}; */
	
	// TODO: Use this container for future extensions?
	class SimulatorConfiguration 
	{
	public:
		int sim_mode;
	
		int getSimMode() {
			return sim_mode;
		}
	
		void setSimMode(int i) {
			sim_mode = i;
		}
	
		SimulatorConfiguration() {
			sim_mode = 0;
		}
	
		~SimulatorConfiguration() {
		}
	};
	
	#define UNEXPECTED_EVENT 	0
	#define NO_ENABLED_GUARDS  	1
	#define LOGICAL_ERROR 		2
	#define INPUT_PARAMS_ERROR 	3
	#define RACE_CONDITION      4
	
	class StubException : virtual public std::exception 
	{
	protected:
	
		int error_number;               ///< Error number
		std::string error_message;      ///< Error message
	
	public:
		explicit
			StubException(const std::string& msg, int err_num) :
			error_number(err_num),
			error_message(msg)
		{}
	
		/** Destructor.
		*  Virtual to allow for subclassing.
		*/
		virtual ~StubException() throw () {}
	
		/** Returns a pointer to the (constant) error description.
		*  @return A pointer to a const char*. The underlying memory
		*  is in possession of the StubException object. Callers must
		*  not attempt to free the memory.
		*/
		virtual const char* what() const throw () {
			return error_message.c_str();
		}
	
		virtual int getErrorNumber() const throw() {
			return error_number;
		}
	};

	// Used by the Scenario Logger
	enum eventType { COMMAND, SIGNAL, REPLY, NOTIFICATION }; 
	
	 // Scenario Logging Facility
	class Logger
	{
	public:

		std::ofstream outfile;
		std::string filename;

		Logger(std::string fname) : outfile(fname), filename(fname)
		{
			std::cout << fname << std::endl;
			// the file should be opened.
			if (!outfile.is_open()) { std::cout << "cannot open log file!" << std::endl; return; }
			std::cout << "opened log file!" << std::endl;
			
			outfile << "import " << "\"V1" << ".signature\"" << std::endl;
			outfile << "server Server on 192.68.32.12" << std::endl;
			outfile << "client Client1 on 192.68.32.1 uses " << "V1" << std::endl << std::endl;

			outfile.close();
		}

		~Logger()
		{
			outfile.close();
		}
		
		void writeEventToFile(std::string eventName, eventType evtTyp)
		{
			outfile.open(filename, std::ios_base::app);
			
			outfile << "Time: 2019-05-14 12:20:29.181" << std::endl;
			outfile << "Timestamp: 0.0" << std::endl;
			outfile << "src address: 192.68.32.1" << std::endl;
			outfile << "dest address: 192.68.32.12" << std::endl;
			outfile << "Interface: V1" << std::endl;
			
			if (evtTyp == COMMAND) {
				outfile << "Command: " << eventName << std::endl;
				/*
				for (auto & elm : paramList) {
					outfile << "Parameter: " << elm.rdbuf() << std::endl;
				}
				*/
			}
			else if (evtTyp == SIGNAL) {
				outfile << "Command: " << eventName << " SIGNAL" << std::endl;
				/*
				for (auto & elm : paramList) {
					outfile << "Parameter: " << elm.rdbuf() << std::endl;
				}
				*/
			}
			else if (evtTyp == NOTIFICATION) {
				outfile << "Command: " << eventName << " NOTIFY" << std::endl;
				/*
				for (auto & elm : paramList) {
					outfile << "Parameter: " << elm.rdbuf() << std::endl;
				}
				*/
			}
			else {
				outfile << "Command: " << eventName << " OK" << std::endl;
				/*
				for (auto & elm : paramList) {
					outfile << "Parameter: " << elm.rdbuf() << std::endl;
				}
				*/
			}
			
			outfile << std::endl;
			outfile.close();
		}
	};


	// A type container for instance_clause_id 
	// [see Input Params File].
	class InstanceClauseID
	{
	public:
	
		InstanceClauseID(int _instance_id) : instance_id(_instance_id) { }
	
		int instance_id;
		std::vector<int> list_of_clause_id;
	
		InstanceClauseID& operator=(const InstanceClauseID& copy)
		{
			instance_id = copy.instance_id;
			list_of_clause_id = copy.list_of_clause_id;
		}
	
		bool operator==(const InstanceClauseID &var)
		{
			if (!(instance_id == var.instance_id)) return false;
			if (!(list_of_clause_id == var.list_of_clause_id)) return false;
	
			return true;
		}
	};
	
	}
	#endif /*COMMON_H_ */
