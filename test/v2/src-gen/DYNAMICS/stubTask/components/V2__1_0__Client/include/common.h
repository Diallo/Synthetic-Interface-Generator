	#ifndef COMMON_H_
	#define COMMON_H_
	
	#define CLIENT_STUB_API
	
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
		namespace V2 {
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
		typedef std::function<void()> outTRp1_1_3398718_Handler;
		typedef std::function<void()> outTRp1_1_3398719_Handler;
		typedef std::function<void()> outTRp1_1_3398720_Handler;
		typedef std::function<void()> outTRp3_1_3398724_Handler;
		typedef std::function<void()> outTRp1_4_3398725_Handler;
		typedef std::function<void()> outTRp3_3_3398727_Handler;
		typedef std::function<void()> outTRp3_4_3398731_Handler;
		typedef std::function<void()> outTRp3_5_3398733_Handler;
		typedef std::function<void()> outTRp3_2_3398735_Handler;
		typedef std::function<void()> outTRp3_3_3398736_Handler;
		typedef std::function<void()> outTRp1_1_3398738_Handler;
		typedef std::function<void()> outTRp2_3_3398740_Handler;
		typedef std::function<void()> outTRp4_1_3398744_Handler;
		typedef std::function<void()> outTRp5_1_3398745_Handler;
		typedef std::function<void()> outTRp3_10_3398748_Handler;
		typedef std::function<void()> outTRp1_6_3398756_Handler;
		typedef std::function<void()> outTRp1_4_3398759_Handler;
		typedef std::function<void()> outTRp3_6_3398761_Handler;
		typedef std::function<void()> outTRp2_6_3398762_Handler;
		typedef std::function<void()> outTRp3_4_3398763_Handler;
		typedef std::function<void()> outTRp3_11_3398764_Handler;
		typedef std::function<void()> outTRp3_8_3398766_Handler;
		typedef std::function<void()> outTRp1_10_3398769_Handler;
		typedef std::function<void()> outTRp3_12_3398771_Handler;
		typedef std::function<void()> outTRp6_1_3398773_Handler;
		typedef std::function<void()> outTRp7_1_3398775_Handler;
		typedef std::function<void()> outTRp5_2_3398777_Handler;
		typedef std::function<void()> outTRp1_6_3398778_Handler;
		typedef std::function<void()> outTRp1_14_3398782_Handler;
		typedef std::function<void()> outTRp1_3_3398784_Handler;
		typedef std::function<void()> outTRp8_1_3398788_Handler;
		typedef std::function<void()> outTRp9_1_3398789_Handler;
		typedef std::function<void()> outTRp1_17_3398791_Handler;
		typedef std::function<void()> outTRp1_7_3398793_Handler;
		typedef std::function<void()> outTRp1_7_3398794_Handler;
		typedef std::function<void()> outTRp1_4_3398797_Handler;
		typedef std::function<void()> outTRp3_29_3398799_Handler;
		typedef std::function<void()> outTRp9_2_3398801_Handler;
		typedef std::function<void()> outTRp3_13_3398802_Handler;
		typedef std::function<void()> outTRp1_7_3398804_Handler;
		typedef std::function<void()> outTRp3_32_3398806_Handler;
		typedef std::function<void()> outTRp1_20_3398809_Handler;
		typedef std::function<void()> outTRp9_3_3398810_Handler;
		typedef std::function<void()> outTRp1_1_3398811_Handler;
		typedef std::function<void()> outTRp1_9_3398815_Handler;
		typedef std::function<void()> outTRp5_4_3398816_Handler;
		typedef std::function<void()> outTRp5_4_3398817_Handler;
		typedef std::function<void()> outTRp1_25_3398820_Handler;
		typedef std::function<void()> outTRp2_10_3398821_Handler;
		typedef std::function<void()> outTRp1_26_3398822_Handler;
		typedef std::function<void()> outTRp11_1_3398824_Handler;
		typedef std::function<void()> outTRp9_1_3398829_Handler;
		typedef std::function<void()> outTRp3_2_3398830_Handler;
		typedef std::function<void()> outTRp9_5_3398831_Handler;
		typedef std::function<void()> outTRp1_21_3398832_Handler;
		typedef std::function<void()> outTRp3_29_3398835_Handler;
		typedef std::function<void()> outTRp3_21_3398836_Handler;
		typedef std::function<void()> outTRp1_20_3398837_Handler;
		typedef std::function<void()> outTRp4_2_3398839_Handler;
		typedef std::function<void()> outTRp3_8_3398840_Handler;
		typedef std::function<void()> outTRp1_5_3398844_Handler;
		typedef std::function<void()> outTRp1_12_3398846_Handler;
		typedef std::function<void()> outTRp2_9_3398848_Handler;
		typedef std::function<void()> outTRp2_7_3398851_Handler;
		typedef std::function<void()> outTRp3_13_3398852_Handler;
		typedef std::function<void()> outTRp3_40_3398853_Handler;
		typedef std::function<void()> outTRp3_40_3398855_Handler;
		typedef std::function<void()> outTRp3_6_3398857_Handler;
		typedef std::function<void()> outTRp17_1_3398863_Handler;
		typedef std::function<void()> outTRp1_3_3398866_Handler;
		typedef std::function<void()> outTRp3_10_3398867_Handler;
		typedef std::function<void()> outTRp4_3_3398869_Handler;
		typedef std::function<void()> outTRp9_1_3398870_Handler;
		typedef std::function<void()> outTRp4_2_3398873_Handler;
		typedef std::function<void()> outTRp2_1_3398874_Handler;
		typedef std::function<void()> outTRp19_1_3398877_Handler;
		typedef std::function<void()> outTRp1_10_3398879_Handler;
		typedef std::function<void()> outTRp3_52_3398880_Handler;
		typedef std::function<void()> outTRp3_52_3398881_Handler;
		typedef std::function<void()> outTRp3_41_3398883_Handler;
		typedef std::function<void()> outTRp3_36_3398884_Handler;
		typedef std::function<void()> outTRp3_34_3398885_Handler;
		typedef std::function<void()> outTRp3_31_3398886_Handler;
		typedef std::function<void()> outTRp3_29_3398887_Handler;
		typedef std::function<void()> outTRp3_18_3398888_Handler;
		typedef std::function<void()> outTRp3_60_3398889_Handler;
		typedef std::function<void()> outTRp3_62_3398890_Handler;
		typedef std::function<void()> outTRp3_60_3398891_Handler;
		typedef std::function<void()> outTRp3_62_3398892_Handler;
		typedef std::function<void()> outTRp3_62_3398893_Handler;
		typedef std::function<void()> outTRp3_61_3398894_Handler;
	
		#ifndef SSCF_VERSION
		const std::map<std::string,int> eventIndex = {
			std::make_pair("V2_inTRp2_1_3398721",0),
			std::make_pair("V2_inTRp3_1_3398722",1),
			std::make_pair("V2_inTRp1_1_3398723",2),
			std::make_pair("V2_inTRp3_2_3398726",3),
			std::make_pair("V2_inTRp2_1_3398728",4),
			std::make_pair("V2_inTRp3_4_3398729",5),
			std::make_pair("V2_inTRp2_1_3398732",6),
			std::make_pair("V2_inTRp3_5_3398734",7),
			std::make_pair("V2_inTRp3_4_3398737",8),
			std::make_pair("V2_inTRp2_2_3398739",9),
			std::make_pair("V2_inTRp3_10_3398741",10),
			std::make_pair("V2_inTRp1_2_3398742",11),
			std::make_pair("V2_inTRp1_2_3398743",12),
			std::make_pair("V2_inTRp1_4_3398746",13),
			std::make_pair("V2_inTRp3_9_3398747",14),
			std::make_pair("V2_inTRp3_5_3398749",15),
			std::make_pair("V2_inTRp3_4_3398750",16),
			std::make_pair("V2_inTRp3_9_3398751",17),
			std::make_pair("V2_inTRp3_8_3398752",18),
			std::make_pair("V2_inTRp2_1_3398753",19),
			std::make_pair("V2_inTRp2_3_3398754",20),
			std::make_pair("V2_inTRp1_5_3398755",21),
			std::make_pair("V2_inTRp2_1_3398757",22),
			std::make_pair("V2_inTRp1_3_3398758",23),
			std::make_pair("V2_inTRp3_5_3398760",24),
			std::make_pair("V2_inTRp3_12_3398765",25),
			std::make_pair("V2_inTRp1_8_3398767",26),
			std::make_pair("V2_inTRp3_9_3398768",27),
			std::make_pair("V2_inTRp3_11_3398770",28),
			std::make_pair("V2_inTRp2_4_3398772",29),
			std::make_pair("V2_inTRp3_26_3398774",30),
			std::make_pair("V2_inTRp5_1_3398776",31),
			std::make_pair("V2_inTRp3_8_3398780",32),
			std::make_pair("V2_inTRp2_3_3398781",33),
			std::make_pair("V2_inTRp1_2_3398783",34),
			std::make_pair("V2_inTRp1_14_3398785",35),
			std::make_pair("V2_inTRp3_12_3398786",36),
			std::make_pair("V2_inTRp3_12_3398787",37),
			std::make_pair("V2_inTRp1_16_3398790",38),
			std::make_pair("V2_inTRp3_13_3398792",39),
			std::make_pair("V2_inTRp10_1_3398795",40),
			std::make_pair("V2_inTRp11_1_3398796",41),
			std::make_pair("V2_inTRp3_18_3398798",42),
			std::make_pair("V2_inTRp9_1_3398800",43),
			std::make_pair("V2_inTRp3_14_3398803",44),
			std::make_pair("V2_inTRp10_1_3398805",45),
			std::make_pair("V2_inTRp5_3_3398807",46),
			std::make_pair("V2_inTRp1_9_3398808",47),
			std::make_pair("V2_inTRp1_2_3398812",48),
			std::make_pair("V2_inTRp3_10_3398813",49),
			std::make_pair("V2_inTRp3_17_3398814",50),
			std::make_pair("V2_inTRp12_1_3398818",51),
			std::make_pair("V2_inTRp13_1_3398819",52),
			std::make_pair("V2_inTRp1_27_3398823",53),
			std::make_pair("V2_inTRp1_5_3398825",54),
			std::make_pair("V2_inTRp2_5_3398826",55),
			std::make_pair("V2_inTRp3_15_3398827",56),
			std::make_pair("V2_inTRp1_31_3398828",57),
			std::make_pair("V2_inTRp1_14_3398833",58),
			std::make_pair("V2_inTRp1_32_3398834",59),
			std::make_pair("V2_inTRp4_1_3398838",60),
			std::make_pair("V2_inTRp14_1_3398841",61),
			std::make_pair("V2_inTRp3_3_3398842",62),
			std::make_pair("V2_inTRp2_8_3398847",63),
			std::make_pair("V2_inTRp1_10_3398849",64),
			std::make_pair("V2_inTRp2_6_3398850",65),
			std::make_pair("V2_inTRp15_1_3398854",66),
			std::make_pair("V2_inTRp16_1_3398856",67),
			std::make_pair("V2_inTRp17_1_3398858",68),
			std::make_pair("V2_inTRp1_15_3398859",69),
			std::make_pair("V2_inTRp3_34_3398860",70),
			std::make_pair("V2_inTRp1_24_3398861",71),
			std::make_pair("V2_inTRp1_7_3398862",72),
			std::make_pair("V2_inTRp17_2_3398864",73),
			std::make_pair("V2_inTRp3_27_3398865",74),
			std::make_pair("V2_inTRp4_2_3398868",75),
			std::make_pair("V2_inTRp18_1_3398871",76),
			std::make_pair("V2_inTRp3_22_3398872",77),
			std::make_pair("V2_inTRp2_2_3398875",78),
			std::make_pair("V2_inTRp4_1_3398876",79),
			std::make_pair("V2_inTRp3_28_3398878",80),
			std::make_pair("V2_outTRp1_1_3398718",81),
			std::make_pair("V2_outTRp1_1_3398719",82),
			std::make_pair("V2_outTRp1_1_3398720",83),
			std::make_pair("V2_outTRp3_1_3398724",84),
			std::make_pair("V2_outTRp1_4_3398725",85),
			std::make_pair("V2_outTRp3_3_3398727",86),
			std::make_pair("V2_outTRp3_4_3398731",87),
			std::make_pair("V2_outTRp3_5_3398733",88),
			std::make_pair("V2_outTRp3_2_3398735",89),
			std::make_pair("V2_outTRp3_3_3398736",90),
			std::make_pair("V2_outTRp1_1_3398738",91),
			std::make_pair("V2_outTRp2_3_3398740",92),
			std::make_pair("V2_outTRp4_1_3398744",93),
			std::make_pair("V2_outTRp5_1_3398745",94),
			std::make_pair("V2_outTRp3_10_3398748",95),
			std::make_pair("V2_outTRp1_6_3398756",96),
			std::make_pair("V2_outTRp1_4_3398759",97),
			std::make_pair("V2_outTRp3_6_3398761",98),
			std::make_pair("V2_outTRp2_6_3398762",99),
			std::make_pair("V2_outTRp3_4_3398763",100),
			std::make_pair("V2_outTRp3_11_3398764",101),
			std::make_pair("V2_outTRp3_8_3398766",102),
			std::make_pair("V2_outTRp1_10_3398769",103),
			std::make_pair("V2_outTRp3_12_3398771",104),
			std::make_pair("V2_outTRp6_1_3398773",105),
			std::make_pair("V2_outTRp7_1_3398775",106),
			std::make_pair("V2_outTRp5_2_3398777",107),
			std::make_pair("V2_outTRp1_6_3398778",108),
			std::make_pair("V2_outTRp1_14_3398782",109),
			std::make_pair("V2_outTRp1_3_3398784",110),
			std::make_pair("V2_outTRp8_1_3398788",111),
			std::make_pair("V2_outTRp9_1_3398789",112),
			std::make_pair("V2_outTRp1_17_3398791",113),
			std::make_pair("V2_outTRp1_7_3398793",114),
			std::make_pair("V2_outTRp1_7_3398794",115),
			std::make_pair("V2_outTRp1_4_3398797",116),
			std::make_pair("V2_outTRp3_29_3398799",117),
			std::make_pair("V2_outTRp9_2_3398801",118),
			std::make_pair("V2_outTRp3_13_3398802",119),
			std::make_pair("V2_outTRp1_7_3398804",120),
			std::make_pair("V2_outTRp3_32_3398806",121),
			std::make_pair("V2_outTRp1_20_3398809",122),
			std::make_pair("V2_outTRp9_3_3398810",123),
			std::make_pair("V2_outTRp1_1_3398811",124),
			std::make_pair("V2_outTRp1_9_3398815",125),
			std::make_pair("V2_outTRp5_4_3398816",126),
			std::make_pair("V2_outTRp5_4_3398817",127),
			std::make_pair("V2_outTRp1_25_3398820",128),
			std::make_pair("V2_outTRp2_10_3398821",129),
			std::make_pair("V2_outTRp1_26_3398822",130),
			std::make_pair("V2_outTRp11_1_3398824",131),
			std::make_pair("V2_outTRp9_1_3398829",132),
			std::make_pair("V2_outTRp3_2_3398830",133),
			std::make_pair("V2_outTRp9_5_3398831",134),
			std::make_pair("V2_outTRp1_21_3398832",135),
			std::make_pair("V2_outTRp3_29_3398835",136),
			std::make_pair("V2_outTRp3_21_3398836",137),
			std::make_pair("V2_outTRp1_20_3398837",138),
			std::make_pair("V2_outTRp4_2_3398839",139),
			std::make_pair("V2_outTRp3_8_3398840",140),
			std::make_pair("V2_outTRp1_5_3398844",141),
			std::make_pair("V2_outTRp1_12_3398846",142),
			std::make_pair("V2_outTRp2_9_3398848",143),
			std::make_pair("V2_outTRp2_7_3398851",144),
			std::make_pair("V2_outTRp3_13_3398852",145),
			std::make_pair("V2_outTRp3_40_3398853",146),
			std::make_pair("V2_outTRp3_40_3398855",147),
			std::make_pair("V2_outTRp3_6_3398857",148),
			std::make_pair("V2_outTRp17_1_3398863",149),
			std::make_pair("V2_outTRp1_3_3398866",150),
			std::make_pair("V2_outTRp3_10_3398867",151),
			std::make_pair("V2_outTRp4_3_3398869",152),
			std::make_pair("V2_outTRp9_1_3398870",153),
			std::make_pair("V2_outTRp4_2_3398873",154),
			std::make_pair("V2_outTRp2_1_3398874",155),
			std::make_pair("V2_outTRp19_1_3398877",156),
			std::make_pair("V2_outTRp1_10_3398879",157),
			std::make_pair("V2_outTRp3_52_3398880",158),
			std::make_pair("V2_outTRp3_52_3398881",159),
			std::make_pair("V2_outTRp3_41_3398883",160),
			std::make_pair("V2_outTRp3_36_3398884",161),
			std::make_pair("V2_outTRp3_34_3398885",162),
			std::make_pair("V2_outTRp3_31_3398886",163),
			std::make_pair("V2_outTRp3_29_3398887",164),
			std::make_pair("V2_outTRp3_18_3398888",165),
			std::make_pair("V2_outTRp3_60_3398889",166),
			std::make_pair("V2_outTRp3_62_3398890",167),
			std::make_pair("V2_outTRp3_60_3398891",168),
			std::make_pair("V2_outTRp3_62_3398892",169),
			std::make_pair("V2_outTRp3_62_3398893",170),
			std::make_pair("V2_outTRp3_61_3398894",171),

			std::make_pair("UNDEFINED", 172)
		};
		#endif

	#define START_STOP_INDEX 172
	#define SERVER_STUB 1
	#define CLIENT_STUB 2
	#define UI 3


	#ifdef CLIENT_STUB_API
	class EventIndexData
	{
		public:
			EventIndexData() 
			{
				eventIndex.insert(std::make_pair("V2_inTRp2_1_3398721",0));
				eventIndex.insert(std::make_pair("V2_inTRp3_1_3398722",1));
				eventIndex.insert(std::make_pair("V2_inTRp1_1_3398723",2));
				eventIndex.insert(std::make_pair("V2_inTRp3_2_3398726",3));
				eventIndex.insert(std::make_pair("V2_inTRp2_1_3398728",4));
				eventIndex.insert(std::make_pair("V2_inTRp3_4_3398729",5));
				eventIndex.insert(std::make_pair("V2_inTRp2_1_3398732",6));
				eventIndex.insert(std::make_pair("V2_inTRp3_5_3398734",7));
				eventIndex.insert(std::make_pair("V2_inTRp3_4_3398737",8));
				eventIndex.insert(std::make_pair("V2_inTRp2_2_3398739",9));
				eventIndex.insert(std::make_pair("V2_inTRp3_10_3398741",10));
				eventIndex.insert(std::make_pair("V2_inTRp1_2_3398742",11));
				eventIndex.insert(std::make_pair("V2_inTRp1_2_3398743",12));
				eventIndex.insert(std::make_pair("V2_inTRp1_4_3398746",13));
				eventIndex.insert(std::make_pair("V2_inTRp3_9_3398747",14));
				eventIndex.insert(std::make_pair("V2_inTRp3_5_3398749",15));
				eventIndex.insert(std::make_pair("V2_inTRp3_4_3398750",16));
				eventIndex.insert(std::make_pair("V2_inTRp3_9_3398751",17));
				eventIndex.insert(std::make_pair("V2_inTRp3_8_3398752",18));
				eventIndex.insert(std::make_pair("V2_inTRp2_1_3398753",19));
				eventIndex.insert(std::make_pair("V2_inTRp2_3_3398754",20));
				eventIndex.insert(std::make_pair("V2_inTRp1_5_3398755",21));
				eventIndex.insert(std::make_pair("V2_inTRp2_1_3398757",22));
				eventIndex.insert(std::make_pair("V2_inTRp1_3_3398758",23));
				eventIndex.insert(std::make_pair("V2_inTRp3_5_3398760",24));
				eventIndex.insert(std::make_pair("V2_inTRp3_12_3398765",25));
				eventIndex.insert(std::make_pair("V2_inTRp1_8_3398767",26));
				eventIndex.insert(std::make_pair("V2_inTRp3_9_3398768",27));
				eventIndex.insert(std::make_pair("V2_inTRp3_11_3398770",28));
				eventIndex.insert(std::make_pair("V2_inTRp2_4_3398772",29));
				eventIndex.insert(std::make_pair("V2_inTRp3_26_3398774",30));
				eventIndex.insert(std::make_pair("V2_inTRp5_1_3398776",31));
				eventIndex.insert(std::make_pair("V2_inTRp3_8_3398780",32));
				eventIndex.insert(std::make_pair("V2_inTRp2_3_3398781",33));
				eventIndex.insert(std::make_pair("V2_inTRp1_2_3398783",34));
				eventIndex.insert(std::make_pair("V2_inTRp1_14_3398785",35));
				eventIndex.insert(std::make_pair("V2_inTRp3_12_3398786",36));
				eventIndex.insert(std::make_pair("V2_inTRp3_12_3398787",37));
				eventIndex.insert(std::make_pair("V2_inTRp1_16_3398790",38));
				eventIndex.insert(std::make_pair("V2_inTRp3_13_3398792",39));
				eventIndex.insert(std::make_pair("V2_inTRp10_1_3398795",40));
				eventIndex.insert(std::make_pair("V2_inTRp11_1_3398796",41));
				eventIndex.insert(std::make_pair("V2_inTRp3_18_3398798",42));
				eventIndex.insert(std::make_pair("V2_inTRp9_1_3398800",43));
				eventIndex.insert(std::make_pair("V2_inTRp3_14_3398803",44));
				eventIndex.insert(std::make_pair("V2_inTRp10_1_3398805",45));
				eventIndex.insert(std::make_pair("V2_inTRp5_3_3398807",46));
				eventIndex.insert(std::make_pair("V2_inTRp1_9_3398808",47));
				eventIndex.insert(std::make_pair("V2_inTRp1_2_3398812",48));
				eventIndex.insert(std::make_pair("V2_inTRp3_10_3398813",49));
				eventIndex.insert(std::make_pair("V2_inTRp3_17_3398814",50));
				eventIndex.insert(std::make_pair("V2_inTRp12_1_3398818",51));
				eventIndex.insert(std::make_pair("V2_inTRp13_1_3398819",52));
				eventIndex.insert(std::make_pair("V2_inTRp1_27_3398823",53));
				eventIndex.insert(std::make_pair("V2_inTRp1_5_3398825",54));
				eventIndex.insert(std::make_pair("V2_inTRp2_5_3398826",55));
				eventIndex.insert(std::make_pair("V2_inTRp3_15_3398827",56));
				eventIndex.insert(std::make_pair("V2_inTRp1_31_3398828",57));
				eventIndex.insert(std::make_pair("V2_inTRp1_14_3398833",58));
				eventIndex.insert(std::make_pair("V2_inTRp1_32_3398834",59));
				eventIndex.insert(std::make_pair("V2_inTRp4_1_3398838",60));
				eventIndex.insert(std::make_pair("V2_inTRp14_1_3398841",61));
				eventIndex.insert(std::make_pair("V2_inTRp3_3_3398842",62));
				eventIndex.insert(std::make_pair("V2_inTRp2_8_3398847",63));
				eventIndex.insert(std::make_pair("V2_inTRp1_10_3398849",64));
				eventIndex.insert(std::make_pair("V2_inTRp2_6_3398850",65));
				eventIndex.insert(std::make_pair("V2_inTRp15_1_3398854",66));
				eventIndex.insert(std::make_pair("V2_inTRp16_1_3398856",67));
				eventIndex.insert(std::make_pair("V2_inTRp17_1_3398858",68));
				eventIndex.insert(std::make_pair("V2_inTRp1_15_3398859",69));
				eventIndex.insert(std::make_pair("V2_inTRp3_34_3398860",70));
				eventIndex.insert(std::make_pair("V2_inTRp1_24_3398861",71));
				eventIndex.insert(std::make_pair("V2_inTRp1_7_3398862",72));
				eventIndex.insert(std::make_pair("V2_inTRp17_2_3398864",73));
				eventIndex.insert(std::make_pair("V2_inTRp3_27_3398865",74));
				eventIndex.insert(std::make_pair("V2_inTRp4_2_3398868",75));
				eventIndex.insert(std::make_pair("V2_inTRp18_1_3398871",76));
				eventIndex.insert(std::make_pair("V2_inTRp3_22_3398872",77));
				eventIndex.insert(std::make_pair("V2_inTRp2_2_3398875",78));
				eventIndex.insert(std::make_pair("V2_inTRp4_1_3398876",79));
				eventIndex.insert(std::make_pair("V2_inTRp3_28_3398878",80));
				eventIndex.insert(std::make_pair("V2_outTRp1_1_3398718",81));
				eventIndex.insert(std::make_pair("V2_outTRp1_1_3398719",82));
				eventIndex.insert(std::make_pair("V2_outTRp1_1_3398720",83));
				eventIndex.insert(std::make_pair("V2_outTRp3_1_3398724",84));
				eventIndex.insert(std::make_pair("V2_outTRp1_4_3398725",85));
				eventIndex.insert(std::make_pair("V2_outTRp3_3_3398727",86));
				eventIndex.insert(std::make_pair("V2_outTRp3_4_3398731",87));
				eventIndex.insert(std::make_pair("V2_outTRp3_5_3398733",88));
				eventIndex.insert(std::make_pair("V2_outTRp3_2_3398735",89));
				eventIndex.insert(std::make_pair("V2_outTRp3_3_3398736",90));
				eventIndex.insert(std::make_pair("V2_outTRp1_1_3398738",91));
				eventIndex.insert(std::make_pair("V2_outTRp2_3_3398740",92));
				eventIndex.insert(std::make_pair("V2_outTRp4_1_3398744",93));
				eventIndex.insert(std::make_pair("V2_outTRp5_1_3398745",94));
				eventIndex.insert(std::make_pair("V2_outTRp3_10_3398748",95));
				eventIndex.insert(std::make_pair("V2_outTRp1_6_3398756",96));
				eventIndex.insert(std::make_pair("V2_outTRp1_4_3398759",97));
				eventIndex.insert(std::make_pair("V2_outTRp3_6_3398761",98));
				eventIndex.insert(std::make_pair("V2_outTRp2_6_3398762",99));
				eventIndex.insert(std::make_pair("V2_outTRp3_4_3398763",100));
				eventIndex.insert(std::make_pair("V2_outTRp3_11_3398764",101));
				eventIndex.insert(std::make_pair("V2_outTRp3_8_3398766",102));
				eventIndex.insert(std::make_pair("V2_outTRp1_10_3398769",103));
				eventIndex.insert(std::make_pair("V2_outTRp3_12_3398771",104));
				eventIndex.insert(std::make_pair("V2_outTRp6_1_3398773",105));
				eventIndex.insert(std::make_pair("V2_outTRp7_1_3398775",106));
				eventIndex.insert(std::make_pair("V2_outTRp5_2_3398777",107));
				eventIndex.insert(std::make_pair("V2_outTRp1_6_3398778",108));
				eventIndex.insert(std::make_pair("V2_outTRp1_14_3398782",109));
				eventIndex.insert(std::make_pair("V2_outTRp1_3_3398784",110));
				eventIndex.insert(std::make_pair("V2_outTRp8_1_3398788",111));
				eventIndex.insert(std::make_pair("V2_outTRp9_1_3398789",112));
				eventIndex.insert(std::make_pair("V2_outTRp1_17_3398791",113));
				eventIndex.insert(std::make_pair("V2_outTRp1_7_3398793",114));
				eventIndex.insert(std::make_pair("V2_outTRp1_7_3398794",115));
				eventIndex.insert(std::make_pair("V2_outTRp1_4_3398797",116));
				eventIndex.insert(std::make_pair("V2_outTRp3_29_3398799",117));
				eventIndex.insert(std::make_pair("V2_outTRp9_2_3398801",118));
				eventIndex.insert(std::make_pair("V2_outTRp3_13_3398802",119));
				eventIndex.insert(std::make_pair("V2_outTRp1_7_3398804",120));
				eventIndex.insert(std::make_pair("V2_outTRp3_32_3398806",121));
				eventIndex.insert(std::make_pair("V2_outTRp1_20_3398809",122));
				eventIndex.insert(std::make_pair("V2_outTRp9_3_3398810",123));
				eventIndex.insert(std::make_pair("V2_outTRp1_1_3398811",124));
				eventIndex.insert(std::make_pair("V2_outTRp1_9_3398815",125));
				eventIndex.insert(std::make_pair("V2_outTRp5_4_3398816",126));
				eventIndex.insert(std::make_pair("V2_outTRp5_4_3398817",127));
				eventIndex.insert(std::make_pair("V2_outTRp1_25_3398820",128));
				eventIndex.insert(std::make_pair("V2_outTRp2_10_3398821",129));
				eventIndex.insert(std::make_pair("V2_outTRp1_26_3398822",130));
				eventIndex.insert(std::make_pair("V2_outTRp11_1_3398824",131));
				eventIndex.insert(std::make_pair("V2_outTRp9_1_3398829",132));
				eventIndex.insert(std::make_pair("V2_outTRp3_2_3398830",133));
				eventIndex.insert(std::make_pair("V2_outTRp9_5_3398831",134));
				eventIndex.insert(std::make_pair("V2_outTRp1_21_3398832",135));
				eventIndex.insert(std::make_pair("V2_outTRp3_29_3398835",136));
				eventIndex.insert(std::make_pair("V2_outTRp3_21_3398836",137));
				eventIndex.insert(std::make_pair("V2_outTRp1_20_3398837",138));
				eventIndex.insert(std::make_pair("V2_outTRp4_2_3398839",139));
				eventIndex.insert(std::make_pair("V2_outTRp3_8_3398840",140));
				eventIndex.insert(std::make_pair("V2_outTRp1_5_3398844",141));
				eventIndex.insert(std::make_pair("V2_outTRp1_12_3398846",142));
				eventIndex.insert(std::make_pair("V2_outTRp2_9_3398848",143));
				eventIndex.insert(std::make_pair("V2_outTRp2_7_3398851",144));
				eventIndex.insert(std::make_pair("V2_outTRp3_13_3398852",145));
				eventIndex.insert(std::make_pair("V2_outTRp3_40_3398853",146));
				eventIndex.insert(std::make_pair("V2_outTRp3_40_3398855",147));
				eventIndex.insert(std::make_pair("V2_outTRp3_6_3398857",148));
				eventIndex.insert(std::make_pair("V2_outTRp17_1_3398863",149));
				eventIndex.insert(std::make_pair("V2_outTRp1_3_3398866",150));
				eventIndex.insert(std::make_pair("V2_outTRp3_10_3398867",151));
				eventIndex.insert(std::make_pair("V2_outTRp4_3_3398869",152));
				eventIndex.insert(std::make_pair("V2_outTRp9_1_3398870",153));
				eventIndex.insert(std::make_pair("V2_outTRp4_2_3398873",154));
				eventIndex.insert(std::make_pair("V2_outTRp2_1_3398874",155));
				eventIndex.insert(std::make_pair("V2_outTRp19_1_3398877",156));
				eventIndex.insert(std::make_pair("V2_outTRp1_10_3398879",157));
				eventIndex.insert(std::make_pair("V2_outTRp3_52_3398880",158));
				eventIndex.insert(std::make_pair("V2_outTRp3_52_3398881",159));
				eventIndex.insert(std::make_pair("V2_outTRp3_41_3398883",160));
				eventIndex.insert(std::make_pair("V2_outTRp3_36_3398884",161));
				eventIndex.insert(std::make_pair("V2_outTRp3_34_3398885",162));
				eventIndex.insert(std::make_pair("V2_outTRp3_31_3398886",163));
				eventIndex.insert(std::make_pair("V2_outTRp3_29_3398887",164));
				eventIndex.insert(std::make_pair("V2_outTRp3_18_3398888",165));
				eventIndex.insert(std::make_pair("V2_outTRp3_60_3398889",166));
				eventIndex.insert(std::make_pair("V2_outTRp3_62_3398890",167));
				eventIndex.insert(std::make_pair("V2_outTRp3_60_3398891",168));
				eventIndex.insert(std::make_pair("V2_outTRp3_62_3398892",169));
				eventIndex.insert(std::make_pair("V2_outTRp3_62_3398893",170));
				eventIndex.insert(std::make_pair("V2_outTRp3_61_3398894",171));
				eventIndex.insert(std::make_pair("UNDEFINED", 172));
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
			
			outfile << "import " << "\"V2" << ".signature\"" << std::endl;
			outfile << "server Server on 192.68.32.12" << std::endl;
			outfile << "client Client1 on 192.68.32.1 uses " << "V2" << std::endl << std::endl;

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
			outfile << "Interface: V2" << std::endl;
			
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
