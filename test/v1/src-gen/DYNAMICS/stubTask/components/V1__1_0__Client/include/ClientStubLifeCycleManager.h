#ifndef CLIENTSTUBLIFECYCLEMANAGER_H_
#define CLIENTSTUBLIFECYCLEMANAGER_H_

#include "V1_StateMachineController.h"
#include "V1StubAdapter.h"
#include "EventViewer.h"

#ifdef SSCF_CLIENT_STUB_ADAPTER
//#include "V1.h"
#include "V1.h"
#include "SSCFClientConnection.h"
#endif

#ifdef SSCF_CLIENT_STUB_ADAPTER
namespace UNDEFINED {
	
	// Record Type Definitions for SSCF
	
//namespace SscfV1 {
#endif

// This class owns the client stub and provides a handle to raise notifications
#ifndef SSCF_CLIENT_STUB_ADAPTER
class ClientStubLifeCycleManager
#endif
#ifdef SSCF_CLIENT_STUB_ADAPTER
class ClientStubLifeCycleManager : public SscfTs1::EventHandler
#endif
{
public:
	#ifndef SSCF_CLIENT_STUB_ADAPTER
	ClientStubLifeCycleManager()
	#endif
	#ifdef SSCF_CLIENT_STUB_ADAPTER
	ClientStubLifeCycleManager(SscfTs1::EventLoop& eventLoop, std::string network, std::string serviceResourceName) : m_connection(eventLoop, network, serviceResourceName)
	#endif	
	{
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		std::cout << "Connecting to server..." << std::endl;
		m_connection.Connect();

		do {
			//std::cout << "Connecting to server..." << std::endl;
		} while (!m_connection.IsConnected());

		if (m_connection.IsConnected())
		{
			std::cout << "Connected to server" << std::endl;
		}
		#endif
		
		sim_mode = CLIENT_STUB;

		signalInitlist.push_back("V1_inTRp2_1_3398721");
		signalInitlist.push_back("V1_inTRp3_1_3398722");
		signalInitlist.push_back("V1_inTRp1_1_3398723");
		signalInitlist.push_back("V1_inTRp3_2_3398726");
		signalInitlist.push_back("V1_inTRp2_1_3398728");
		signalInitlist.push_back("V1_inTRp3_4_3398729");
		signalInitlist.push_back("V1_inTRp2_1_3398732");
		signalInitlist.push_back("V1_inTRp3_5_3398734");
		signalInitlist.push_back("V1_inTRp3_4_3398737");
		signalInitlist.push_back("V1_inTRp2_2_3398739");
		signalInitlist.push_back("V1_inTRp3_10_3398741");
		signalInitlist.push_back("V1_inTRp1_2_3398742");
		signalInitlist.push_back("V1_inTRp1_2_3398743");
		signalInitlist.push_back("V1_inTRp1_4_3398746");
		signalInitlist.push_back("V1_inTRp3_9_3398747");
		signalInitlist.push_back("V1_inTRp3_5_3398749");
		signalInitlist.push_back("V1_inTRp3_4_3398750");
		signalInitlist.push_back("V1_inTRp3_9_3398751");
		signalInitlist.push_back("V1_inTRp3_8_3398752");
		signalInitlist.push_back("V1_inTRp2_1_3398753");
		signalInitlist.push_back("V1_inTRp2_3_3398754");
		signalInitlist.push_back("V1_inTRp1_5_3398755");
		signalInitlist.push_back("V1_inTRp2_1_3398757");
		signalInitlist.push_back("V1_inTRp1_3_3398758");
		signalInitlist.push_back("V1_inTRp3_5_3398760");
		signalInitlist.push_back("V1_inTRp3_12_3398765");
		signalInitlist.push_back("V1_inTRp1_8_3398767");
		signalInitlist.push_back("V1_inTRp3_9_3398768");
		signalInitlist.push_back("V1_inTRp3_11_3398770");
		signalInitlist.push_back("V1_inTRp2_4_3398772");
		signalInitlist.push_back("V1_inTRp3_26_3398774");
		signalInitlist.push_back("V1_inTRp5_1_3398776");
		signalInitlist.push_back("V1_inTRp3_8_3398780");
		signalInitlist.push_back("V1_inTRp2_3_3398781");
		signalInitlist.push_back("V1_inTRp1_2_3398783");
		signalInitlist.push_back("V1_inTRp1_14_3398785");
		signalInitlist.push_back("V1_inTRp3_12_3398786");
		signalInitlist.push_back("V1_inTRp3_12_3398787");
		signalInitlist.push_back("V1_inTRp1_16_3398790");
		signalInitlist.push_back("V1_inTRp3_13_3398792");
		signalInitlist.push_back("V1_inTRp10_1_3398795");
		signalInitlist.push_back("V1_inTRp11_1_3398796");
		signalInitlist.push_back("V1_inTRp3_18_3398798");
		signalInitlist.push_back("V1_inTRp9_1_3398800");
		signalInitlist.push_back("V1_inTRp3_14_3398803");
		signalInitlist.push_back("V1_inTRp10_1_3398805");
		signalInitlist.push_back("V1_inTRp5_3_3398807");
		signalInitlist.push_back("V1_inTRp1_9_3398808");
		signalInitlist.push_back("V1_inTRp1_2_3398812");
		signalInitlist.push_back("V1_inTRp3_10_3398813");
		signalInitlist.push_back("V1_inTRp3_17_3398814");
		signalInitlist.push_back("V1_inTRp12_1_3398818");
		signalInitlist.push_back("V1_inTRp13_1_3398819");
		signalInitlist.push_back("V1_inTRp1_27_3398823");
		signalInitlist.push_back("V1_inTRp1_5_3398825");
		signalInitlist.push_back("V1_inTRp2_5_3398826");
		signalInitlist.push_back("V1_inTRp3_15_3398827");
		signalInitlist.push_back("V1_inTRp1_31_3398828");
		signalInitlist.push_back("V1_inTRp1_14_3398833");
		signalInitlist.push_back("V1_inTRp1_32_3398834");
		signalInitlist.push_back("V1_inTRp4_1_3398838");
		signalInitlist.push_back("V1_inTRp14_1_3398841");
		signalInitlist.push_back("V1_inTRp3_3_3398842");
		signalInitlist.push_back("V1_inTRp2_8_3398847");
		signalInitlist.push_back("V1_inTRp1_10_3398849");
		signalInitlist.push_back("V1_inTRp2_6_3398850");
		signalInitlist.push_back("V1_inTRp15_1_3398854");
		signalInitlist.push_back("V1_inTRp16_1_3398856");
		signalInitlist.push_back("V1_inTRp17_1_3398858");
		signalInitlist.push_back("V1_inTRp1_15_3398859");
		signalInitlist.push_back("V1_inTRp3_34_3398860");
		signalInitlist.push_back("V1_inTRp1_24_3398861");
		signalInitlist.push_back("V1_inTRp1_7_3398862");
		signalInitlist.push_back("V1_inTRp17_2_3398864");
		signalInitlist.push_back("V1_inTRp3_27_3398865");
		signalInitlist.push_back("V1_inTRp4_2_3398868");
		signalInitlist.push_back("V1_inTRp18_1_3398871");
		signalInitlist.push_back("V1_inTRp3_22_3398872");
		signalInitlist.push_back("V1_inTRp2_2_3398875");
		signalInitlist.push_back("V1_inTRp4_1_3398876");
		signalInitlist.push_back("V1_inTRp3_28_3398878");
		notificationInitlist.push_back("V1_outTRp1_1_3398718");
		notificationInitlist.push_back("V1_outTRp1_1_3398719");
		notificationInitlist.push_back("V1_outTRp1_1_3398720");
		notificationInitlist.push_back("V1_outTRp3_1_3398724");
		notificationInitlist.push_back("V1_outTRp1_4_3398725");
		notificationInitlist.push_back("V1_outTRp3_3_3398727");
		notificationInitlist.push_back("V1_outTRp3_5_3398730");
		notificationInitlist.push_back("V1_outTRp3_4_3398731");
		notificationInitlist.push_back("V1_outTRp3_5_3398733");
		notificationInitlist.push_back("V1_outTRp3_2_3398735");
		notificationInitlist.push_back("V1_outTRp3_3_3398736");
		notificationInitlist.push_back("V1_outTRp1_1_3398738");
		notificationInitlist.push_back("V1_outTRp2_3_3398740");
		notificationInitlist.push_back("V1_outTRp4_1_3398744");
		notificationInitlist.push_back("V1_outTRp5_1_3398745");
		notificationInitlist.push_back("V1_outTRp3_10_3398748");
		notificationInitlist.push_back("V1_outTRp1_6_3398756");
		notificationInitlist.push_back("V1_outTRp1_4_3398759");
		notificationInitlist.push_back("V1_outTRp3_6_3398761");
		notificationInitlist.push_back("V1_outTRp2_6_3398762");
		notificationInitlist.push_back("V1_outTRp3_4_3398763");
		notificationInitlist.push_back("V1_outTRp3_11_3398764");
		notificationInitlist.push_back("V1_outTRp3_8_3398766");
		notificationInitlist.push_back("V1_outTRp1_10_3398769");
		notificationInitlist.push_back("V1_outTRp3_12_3398771");
		notificationInitlist.push_back("V1_outTRp6_1_3398773");
		notificationInitlist.push_back("V1_outTRp7_1_3398775");
		notificationInitlist.push_back("V1_outTRp5_2_3398777");
		notificationInitlist.push_back("V1_outTRp1_6_3398778");
		notificationInitlist.push_back("V1_outTRp3_7_3398779");
		notificationInitlist.push_back("V1_outTRp1_14_3398782");
		notificationInitlist.push_back("V1_outTRp1_3_3398784");
		notificationInitlist.push_back("V1_outTRp8_1_3398788");
		notificationInitlist.push_back("V1_outTRp9_1_3398789");
		notificationInitlist.push_back("V1_outTRp1_17_3398791");
		notificationInitlist.push_back("V1_outTRp1_7_3398793");
		notificationInitlist.push_back("V1_outTRp1_7_3398794");
		notificationInitlist.push_back("V1_outTRp1_4_3398797");
		notificationInitlist.push_back("V1_outTRp3_29_3398799");
		notificationInitlist.push_back("V1_outTRp9_2_3398801");
		notificationInitlist.push_back("V1_outTRp3_13_3398802");
		notificationInitlist.push_back("V1_outTRp1_7_3398804");
		notificationInitlist.push_back("V1_outTRp3_32_3398806");
		notificationInitlist.push_back("V1_outTRp1_20_3398809");
		notificationInitlist.push_back("V1_outTRp9_3_3398810");
		notificationInitlist.push_back("V1_outTRp1_1_3398811");
		notificationInitlist.push_back("V1_outTRp1_9_3398815");
		notificationInitlist.push_back("V1_outTRp5_4_3398816");
		notificationInitlist.push_back("V1_outTRp5_4_3398817");
		notificationInitlist.push_back("V1_outTRp1_25_3398820");
		notificationInitlist.push_back("V1_outTRp2_10_3398821");
		notificationInitlist.push_back("V1_outTRp1_26_3398822");
		notificationInitlist.push_back("V1_outTRp11_1_3398824");
		notificationInitlist.push_back("V1_outTRp9_1_3398829");
		notificationInitlist.push_back("V1_outTRp3_2_3398830");
		notificationInitlist.push_back("V1_outTRp9_5_3398831");
		notificationInitlist.push_back("V1_outTRp1_21_3398832");
		notificationInitlist.push_back("V1_outTRp3_29_3398835");
		notificationInitlist.push_back("V1_outTRp3_21_3398836");
		notificationInitlist.push_back("V1_outTRp1_20_3398837");
		notificationInitlist.push_back("V1_outTRp4_2_3398839");
		notificationInitlist.push_back("V1_outTRp3_8_3398840");
		notificationInitlist.push_back("V1_outTRp3_4_3398843");
		notificationInitlist.push_back("V1_outTRp1_5_3398844");
		notificationInitlist.push_back("V1_outTRp3_44_3398845");
		notificationInitlist.push_back("V1_outTRp1_12_3398846");
		notificationInitlist.push_back("V1_outTRp2_9_3398848");
		notificationInitlist.push_back("V1_outTRp2_7_3398851");
		notificationInitlist.push_back("V1_outTRp3_13_3398852");
		notificationInitlist.push_back("V1_outTRp3_40_3398853");
		notificationInitlist.push_back("V1_outTRp3_40_3398855");
		notificationInitlist.push_back("V1_outTRp3_6_3398857");
		notificationInitlist.push_back("V1_outTRp17_1_3398863");
		notificationInitlist.push_back("V1_outTRp1_3_3398866");
		notificationInitlist.push_back("V1_outTRp3_10_3398867");
		notificationInitlist.push_back("V1_outTRp4_3_3398869");
		notificationInitlist.push_back("V1_outTRp9_1_3398870");
		notificationInitlist.push_back("V1_outTRp4_2_3398873");
		notificationInitlist.push_back("V1_outTRp2_1_3398874");
		notificationInitlist.push_back("V1_outTRp19_1_3398877");
		notificationInitlist.push_back("V1_outTRp1_10_3398879");

		ev = new StateMachineController::EventViewer(sim_mode);
		er = new StateMachineController::EventRepository(commandInitlist, signalInitlist, notificationInitlist);
		er->RegisterDataChangeHandler(&StateMachineController::EventViewer::updateAvailableEvents);
		
		#ifndef SSCF_CLIENT_STUB_ADAPTER
		smc = new StateMachineController::V1_StateMachineController(er, sim_mode);
		m_niHandler = new StateMachineController::NiHandler(*smc);
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		smc = new StateMachineController::V1_StateMachineController(er, sim_mode, m_connection);
		#endif
		
		#ifndef SSCF_CLIENT_STUB_ADAPTER
		// Register call backs to the state machine controller
		m_niHandler->register_outTRp1_1_3398718_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_1_3398718_clHandler);
		m_niHandler->register_outTRp1_1_3398719_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_1_3398719_clHandler);
		m_niHandler->register_outTRp1_1_3398720_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_1_3398720_clHandler);
		m_niHandler->register_outTRp3_1_3398724_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_1_3398724_clHandler);
		m_niHandler->register_outTRp1_4_3398725_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_4_3398725_clHandler);
		m_niHandler->register_outTRp3_3_3398727_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_3_3398727_clHandler);
		m_niHandler->register_outTRp3_5_3398730_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_5_3398730_clHandler);
		m_niHandler->register_outTRp3_4_3398731_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_4_3398731_clHandler);
		m_niHandler->register_outTRp3_5_3398733_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_5_3398733_clHandler);
		m_niHandler->register_outTRp3_2_3398735_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_2_3398735_clHandler);
		m_niHandler->register_outTRp3_3_3398736_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_3_3398736_clHandler);
		m_niHandler->register_outTRp1_1_3398738_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_1_3398738_clHandler);
		m_niHandler->register_outTRp2_3_3398740_CBHandler(&StateMachineController::V1_StateMachineController::outTRp2_3_3398740_clHandler);
		m_niHandler->register_outTRp4_1_3398744_CBHandler(&StateMachineController::V1_StateMachineController::outTRp4_1_3398744_clHandler);
		m_niHandler->register_outTRp5_1_3398745_CBHandler(&StateMachineController::V1_StateMachineController::outTRp5_1_3398745_clHandler);
		m_niHandler->register_outTRp3_10_3398748_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_10_3398748_clHandler);
		m_niHandler->register_outTRp1_6_3398756_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_6_3398756_clHandler);
		m_niHandler->register_outTRp1_4_3398759_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_4_3398759_clHandler);
		m_niHandler->register_outTRp3_6_3398761_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_6_3398761_clHandler);
		m_niHandler->register_outTRp2_6_3398762_CBHandler(&StateMachineController::V1_StateMachineController::outTRp2_6_3398762_clHandler);
		m_niHandler->register_outTRp3_4_3398763_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_4_3398763_clHandler);
		m_niHandler->register_outTRp3_11_3398764_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_11_3398764_clHandler);
		m_niHandler->register_outTRp3_8_3398766_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_8_3398766_clHandler);
		m_niHandler->register_outTRp1_10_3398769_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_10_3398769_clHandler);
		m_niHandler->register_outTRp3_12_3398771_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_12_3398771_clHandler);
		m_niHandler->register_outTRp6_1_3398773_CBHandler(&StateMachineController::V1_StateMachineController::outTRp6_1_3398773_clHandler);
		m_niHandler->register_outTRp7_1_3398775_CBHandler(&StateMachineController::V1_StateMachineController::outTRp7_1_3398775_clHandler);
		m_niHandler->register_outTRp5_2_3398777_CBHandler(&StateMachineController::V1_StateMachineController::outTRp5_2_3398777_clHandler);
		m_niHandler->register_outTRp1_6_3398778_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_6_3398778_clHandler);
		m_niHandler->register_outTRp3_7_3398779_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_7_3398779_clHandler);
		m_niHandler->register_outTRp1_14_3398782_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_14_3398782_clHandler);
		m_niHandler->register_outTRp1_3_3398784_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_3_3398784_clHandler);
		m_niHandler->register_outTRp8_1_3398788_CBHandler(&StateMachineController::V1_StateMachineController::outTRp8_1_3398788_clHandler);
		m_niHandler->register_outTRp9_1_3398789_CBHandler(&StateMachineController::V1_StateMachineController::outTRp9_1_3398789_clHandler);
		m_niHandler->register_outTRp1_17_3398791_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_17_3398791_clHandler);
		m_niHandler->register_outTRp1_7_3398793_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_7_3398793_clHandler);
		m_niHandler->register_outTRp1_7_3398794_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_7_3398794_clHandler);
		m_niHandler->register_outTRp1_4_3398797_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_4_3398797_clHandler);
		m_niHandler->register_outTRp3_29_3398799_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_29_3398799_clHandler);
		m_niHandler->register_outTRp9_2_3398801_CBHandler(&StateMachineController::V1_StateMachineController::outTRp9_2_3398801_clHandler);
		m_niHandler->register_outTRp3_13_3398802_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_13_3398802_clHandler);
		m_niHandler->register_outTRp1_7_3398804_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_7_3398804_clHandler);
		m_niHandler->register_outTRp3_32_3398806_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_32_3398806_clHandler);
		m_niHandler->register_outTRp1_20_3398809_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_20_3398809_clHandler);
		m_niHandler->register_outTRp9_3_3398810_CBHandler(&StateMachineController::V1_StateMachineController::outTRp9_3_3398810_clHandler);
		m_niHandler->register_outTRp1_1_3398811_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_1_3398811_clHandler);
		m_niHandler->register_outTRp1_9_3398815_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_9_3398815_clHandler);
		m_niHandler->register_outTRp5_4_3398816_CBHandler(&StateMachineController::V1_StateMachineController::outTRp5_4_3398816_clHandler);
		m_niHandler->register_outTRp5_4_3398817_CBHandler(&StateMachineController::V1_StateMachineController::outTRp5_4_3398817_clHandler);
		m_niHandler->register_outTRp1_25_3398820_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_25_3398820_clHandler);
		m_niHandler->register_outTRp2_10_3398821_CBHandler(&StateMachineController::V1_StateMachineController::outTRp2_10_3398821_clHandler);
		m_niHandler->register_outTRp1_26_3398822_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_26_3398822_clHandler);
		m_niHandler->register_outTRp11_1_3398824_CBHandler(&StateMachineController::V1_StateMachineController::outTRp11_1_3398824_clHandler);
		m_niHandler->register_outTRp9_1_3398829_CBHandler(&StateMachineController::V1_StateMachineController::outTRp9_1_3398829_clHandler);
		m_niHandler->register_outTRp3_2_3398830_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_2_3398830_clHandler);
		m_niHandler->register_outTRp9_5_3398831_CBHandler(&StateMachineController::V1_StateMachineController::outTRp9_5_3398831_clHandler);
		m_niHandler->register_outTRp1_21_3398832_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_21_3398832_clHandler);
		m_niHandler->register_outTRp3_29_3398835_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_29_3398835_clHandler);
		m_niHandler->register_outTRp3_21_3398836_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_21_3398836_clHandler);
		m_niHandler->register_outTRp1_20_3398837_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_20_3398837_clHandler);
		m_niHandler->register_outTRp4_2_3398839_CBHandler(&StateMachineController::V1_StateMachineController::outTRp4_2_3398839_clHandler);
		m_niHandler->register_outTRp3_8_3398840_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_8_3398840_clHandler);
		m_niHandler->register_outTRp3_4_3398843_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_4_3398843_clHandler);
		m_niHandler->register_outTRp1_5_3398844_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_5_3398844_clHandler);
		m_niHandler->register_outTRp3_44_3398845_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_44_3398845_clHandler);
		m_niHandler->register_outTRp1_12_3398846_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_12_3398846_clHandler);
		m_niHandler->register_outTRp2_9_3398848_CBHandler(&StateMachineController::V1_StateMachineController::outTRp2_9_3398848_clHandler);
		m_niHandler->register_outTRp2_7_3398851_CBHandler(&StateMachineController::V1_StateMachineController::outTRp2_7_3398851_clHandler);
		m_niHandler->register_outTRp3_13_3398852_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_13_3398852_clHandler);
		m_niHandler->register_outTRp3_40_3398853_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_40_3398853_clHandler);
		m_niHandler->register_outTRp3_40_3398855_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_40_3398855_clHandler);
		m_niHandler->register_outTRp3_6_3398857_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_6_3398857_clHandler);
		m_niHandler->register_outTRp17_1_3398863_CBHandler(&StateMachineController::V1_StateMachineController::outTRp17_1_3398863_clHandler);
		m_niHandler->register_outTRp1_3_3398866_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_3_3398866_clHandler);
		m_niHandler->register_outTRp3_10_3398867_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_10_3398867_clHandler);
		m_niHandler->register_outTRp4_3_3398869_CBHandler(&StateMachineController::V1_StateMachineController::outTRp4_3_3398869_clHandler);
		m_niHandler->register_outTRp9_1_3398870_CBHandler(&StateMachineController::V1_StateMachineController::outTRp9_1_3398870_clHandler);
		m_niHandler->register_outTRp4_2_3398873_CBHandler(&StateMachineController::V1_StateMachineController::outTRp4_2_3398873_clHandler);
		m_niHandler->register_outTRp2_1_3398874_CBHandler(&StateMachineController::V1_StateMachineController::outTRp2_1_3398874_clHandler);
		m_niHandler->register_outTRp19_1_3398877_CBHandler(&StateMachineController::V1_StateMachineController::outTRp19_1_3398877_clHandler);
		m_niHandler->register_outTRp1_10_3398879_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_10_3398879_clHandler);
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp1_1_3398718_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_1_3398718_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp1_1_3398719_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_1_3398719_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp1_1_3398720_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_1_3398720_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp3_1_3398724_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_1_3398724_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp1_4_3398725_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_4_3398725_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp3_3_3398727_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_3_3398727_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp3_5_3398730_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_5_3398730_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp3_4_3398731_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_4_3398731_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp3_5_3398733_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_5_3398733_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp3_2_3398735_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_2_3398735_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp3_3_3398736_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_3_3398736_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp1_1_3398738_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_1_3398738_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp2_3_3398740_CBHandler(&StateMachineController::V1_StateMachineController::outTRp2_3_3398740_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp4_1_3398744_CBHandler(&StateMachineController::V1_StateMachineController::outTRp4_1_3398744_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp5_1_3398745_CBHandler(&StateMachineController::V1_StateMachineController::outTRp5_1_3398745_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp3_10_3398748_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_10_3398748_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp1_6_3398756_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_6_3398756_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp1_4_3398759_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_4_3398759_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp3_6_3398761_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_6_3398761_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp2_6_3398762_CBHandler(&StateMachineController::V1_StateMachineController::outTRp2_6_3398762_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp3_4_3398763_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_4_3398763_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp3_11_3398764_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_11_3398764_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp3_8_3398766_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_8_3398766_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp1_10_3398769_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_10_3398769_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp3_12_3398771_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_12_3398771_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp6_1_3398773_CBHandler(&StateMachineController::V1_StateMachineController::outTRp6_1_3398773_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp7_1_3398775_CBHandler(&StateMachineController::V1_StateMachineController::outTRp7_1_3398775_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp5_2_3398777_CBHandler(&StateMachineController::V1_StateMachineController::outTRp5_2_3398777_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp1_6_3398778_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_6_3398778_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp3_7_3398779_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_7_3398779_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp1_14_3398782_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_14_3398782_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp1_3_3398784_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_3_3398784_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp8_1_3398788_CBHandler(&StateMachineController::V1_StateMachineController::outTRp8_1_3398788_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp9_1_3398789_CBHandler(&StateMachineController::V1_StateMachineController::outTRp9_1_3398789_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp1_17_3398791_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_17_3398791_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp1_7_3398793_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_7_3398793_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp1_7_3398794_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_7_3398794_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp1_4_3398797_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_4_3398797_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp3_29_3398799_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_29_3398799_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp9_2_3398801_CBHandler(&StateMachineController::V1_StateMachineController::outTRp9_2_3398801_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp3_13_3398802_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_13_3398802_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp1_7_3398804_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_7_3398804_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp3_32_3398806_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_32_3398806_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp1_20_3398809_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_20_3398809_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp9_3_3398810_CBHandler(&StateMachineController::V1_StateMachineController::outTRp9_3_3398810_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp1_1_3398811_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_1_3398811_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp1_9_3398815_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_9_3398815_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp5_4_3398816_CBHandler(&StateMachineController::V1_StateMachineController::outTRp5_4_3398816_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp5_4_3398817_CBHandler(&StateMachineController::V1_StateMachineController::outTRp5_4_3398817_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp1_25_3398820_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_25_3398820_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp2_10_3398821_CBHandler(&StateMachineController::V1_StateMachineController::outTRp2_10_3398821_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp1_26_3398822_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_26_3398822_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp11_1_3398824_CBHandler(&StateMachineController::V1_StateMachineController::outTRp11_1_3398824_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp9_1_3398829_CBHandler(&StateMachineController::V1_StateMachineController::outTRp9_1_3398829_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp3_2_3398830_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_2_3398830_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp9_5_3398831_CBHandler(&StateMachineController::V1_StateMachineController::outTRp9_5_3398831_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp1_21_3398832_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_21_3398832_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp3_29_3398835_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_29_3398835_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp3_21_3398836_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_21_3398836_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp1_20_3398837_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_20_3398837_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp4_2_3398839_CBHandler(&StateMachineController::V1_StateMachineController::outTRp4_2_3398839_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp3_8_3398840_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_8_3398840_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp3_4_3398843_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_4_3398843_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp1_5_3398844_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_5_3398844_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp3_44_3398845_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_44_3398845_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp1_12_3398846_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_12_3398846_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp2_9_3398848_CBHandler(&StateMachineController::V1_StateMachineController::outTRp2_9_3398848_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp2_7_3398851_CBHandler(&StateMachineController::V1_StateMachineController::outTRp2_7_3398851_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp3_13_3398852_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_13_3398852_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp3_40_3398853_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_40_3398853_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp3_40_3398855_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_40_3398855_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp3_6_3398857_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_6_3398857_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp17_1_3398863_CBHandler(&StateMachineController::V1_StateMachineController::outTRp17_1_3398863_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp1_3_3398866_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_3_3398866_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp3_10_3398867_CBHandler(&StateMachineController::V1_StateMachineController::outTRp3_10_3398867_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp4_3_3398869_CBHandler(&StateMachineController::V1_StateMachineController::outTRp4_3_3398869_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp9_1_3398870_CBHandler(&StateMachineController::V1_StateMachineController::outTRp9_1_3398870_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp4_2_3398873_CBHandler(&StateMachineController::V1_StateMachineController::outTRp4_2_3398873_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp2_1_3398874_CBHandler(&StateMachineController::V1_StateMachineController::outTRp2_1_3398874_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp19_1_3398877_CBHandler(&StateMachineController::V1_StateMachineController::outTRp19_1_3398877_clHandler);
		// This is done in the SMC constructor
		// smc->client_api_handler->getNIHandler().register_outTRp1_10_3398879_CBHandler(&StateMachineController::V1_StateMachineController::outTRp1_10_3398879_clHandler);
		#endif

		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp1_1_3398718, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp1_1_3398718 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp1_1_3398718();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp1_1_3398719, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp1_1_3398719 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp1_1_3398719();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp1_1_3398720, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp1_1_3398720 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp1_1_3398720();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp3_1_3398724, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp3_1_3398724 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp3_1_3398724();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp1_4_3398725, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp1_4_3398725 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp1_4_3398725();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp3_3_3398727, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp3_3_3398727 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp3_3_3398727();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp3_5_3398730, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp3_5_3398730 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp3_5_3398730();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp3_4_3398731, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp3_4_3398731 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp3_4_3398731();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp3_5_3398733, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp3_5_3398733 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp3_5_3398733();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp3_2_3398735, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp3_2_3398735 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp3_2_3398735();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp3_3_3398736, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp3_3_3398736 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp3_3_3398736();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp1_1_3398738, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp1_1_3398738 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp1_1_3398738();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp2_3_3398740, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp2_3_3398740 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp2_3_3398740();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp4_1_3398744, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp4_1_3398744 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp4_1_3398744();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp5_1_3398745, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp5_1_3398745 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp5_1_3398745();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp3_10_3398748, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp3_10_3398748 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp3_10_3398748();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp1_6_3398756, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp1_6_3398756 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp1_6_3398756();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp1_4_3398759, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp1_4_3398759 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp1_4_3398759();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp3_6_3398761, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp3_6_3398761 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp3_6_3398761();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp2_6_3398762, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp2_6_3398762 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp2_6_3398762();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp3_4_3398763, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp3_4_3398763 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp3_4_3398763();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp3_11_3398764, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp3_11_3398764 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp3_11_3398764();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp3_8_3398766, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp3_8_3398766 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp3_8_3398766();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp1_10_3398769, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp1_10_3398769 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp1_10_3398769();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp3_12_3398771, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp3_12_3398771 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp3_12_3398771();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp6_1_3398773, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp6_1_3398773 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp6_1_3398773();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp7_1_3398775, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp7_1_3398775 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp7_1_3398775();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp5_2_3398777, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp5_2_3398777 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp5_2_3398777();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp1_6_3398778, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp1_6_3398778 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp1_6_3398778();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp3_7_3398779, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp3_7_3398779 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp3_7_3398779();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp1_14_3398782, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp1_14_3398782 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp1_14_3398782();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp1_3_3398784, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp1_3_3398784 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp1_3_3398784();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp8_1_3398788, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp8_1_3398788 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp8_1_3398788();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp9_1_3398789, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp9_1_3398789 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp9_1_3398789();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp1_17_3398791, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp1_17_3398791 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp1_17_3398791();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp1_7_3398793, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp1_7_3398793 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp1_7_3398793();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp1_7_3398794, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp1_7_3398794 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp1_7_3398794();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp1_4_3398797, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp1_4_3398797 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp1_4_3398797();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp3_29_3398799, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp3_29_3398799 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp3_29_3398799();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp9_2_3398801, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp9_2_3398801 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp9_2_3398801();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp3_13_3398802, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp3_13_3398802 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp3_13_3398802();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp1_7_3398804, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp1_7_3398804 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp1_7_3398804();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp3_32_3398806, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp3_32_3398806 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp3_32_3398806();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp1_20_3398809, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp1_20_3398809 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp1_20_3398809();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp9_3_3398810, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp9_3_3398810 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp9_3_3398810();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp1_1_3398811, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp1_1_3398811 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp1_1_3398811();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp1_9_3398815, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp1_9_3398815 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp1_9_3398815();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp5_4_3398816, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp5_4_3398816 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp5_4_3398816();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp5_4_3398817, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp5_4_3398817 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp5_4_3398817();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp1_25_3398820, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp1_25_3398820 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp1_25_3398820();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp2_10_3398821, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp2_10_3398821 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp2_10_3398821();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp1_26_3398822, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp1_26_3398822 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp1_26_3398822();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp11_1_3398824, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp11_1_3398824 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp11_1_3398824();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp9_1_3398829, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp9_1_3398829 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp9_1_3398829();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp3_2_3398830, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp3_2_3398830 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp3_2_3398830();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp9_5_3398831, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp9_5_3398831 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp9_5_3398831();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp1_21_3398832, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp1_21_3398832 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp1_21_3398832();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp3_29_3398835, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp3_29_3398835 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp3_29_3398835();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp3_21_3398836, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp3_21_3398836 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp3_21_3398836();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp1_20_3398837, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp1_20_3398837 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp1_20_3398837();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp4_2_3398839, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp4_2_3398839 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp4_2_3398839();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp3_8_3398840, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp3_8_3398840 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp3_8_3398840();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp3_4_3398843, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp3_4_3398843 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp3_4_3398843();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp1_5_3398844, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp1_5_3398844 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp1_5_3398844();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp3_44_3398845, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp3_44_3398845 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp3_44_3398845();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp1_12_3398846, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp1_12_3398846 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp1_12_3398846();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp2_9_3398848, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp2_9_3398848 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp2_9_3398848();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp2_7_3398851, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp2_7_3398851 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp2_7_3398851();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp3_13_3398852, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp3_13_3398852 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp3_13_3398852();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp3_40_3398853, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp3_40_3398853 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp3_40_3398853();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp3_40_3398855, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp3_40_3398855 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp3_40_3398855();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp3_6_3398857, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp3_6_3398857 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp3_6_3398857();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp17_1_3398863, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp17_1_3398863 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp17_1_3398863();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp1_3_3398866, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp1_3_3398866 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp1_3_3398866();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp3_10_3398867, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp3_10_3398867 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp3_10_3398867();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp4_3_3398869, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp4_3_3398869 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp4_3_3398869();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp9_1_3398870, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp9_1_3398870 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp9_1_3398870();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp4_2_3398873, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp4_2_3398873 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp4_2_3398873();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp2_1_3398874, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp2_1_3398874 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp2_1_3398874();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp19_1_3398877, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp19_1_3398877 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp19_1_3398877();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		subscribe(m_connection.Proxy().outTRp1_10_3398879, [&]()
		{
			//if(m_client.isConnected()) std::cout<<"test"<<std::endl;
			
			// Prevents Callback from Starting.
			smc->isNotificationInProcess = true;
			
			// Wait for SMC Controller: If Command and Signal CB Execution Is In Progress
			/*
			std::cout << "INFO@Thread_Callback_Method: Checking Lock Available..." << std::endl;
			//std::mutex m_mutex;
			std::unique_lock<std::mutex> mlock(m_mutex);
			if (!smc->isIdle())
			{
				smc->getCondVar().wait(mlock, std::bind(&StateMachineController::IAcqusitionSettingsV1Behavior_StateMachineController::isIdle, smc));
			}
			std::cout << "INFO@NOTIFICATION CB: Acquired Lock!" << std::endl;
								
			while(smc->isCBActive) { 
				std::cout << "Notification Pending. Controller Sync In Progress..." << std::endl;
				Sleep(500);
			}
			*/
			
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "received NI: outTRp1_10_3398879 from SSCF server" << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			smc->client_api_handler->getNIHandler().outTRp1_10_3398879();
			// Added here for ni that is in open context
			smc->isNotificationInProcess = false;
		});
		#endif
	}
	

	#ifndef SSCF_CLIENT_STUB_ADAPTER
	StateMachineController::NiHandler& getNIHandler() { return *m_niHandler; }
	#endif

	~ClientStubLifeCycleManager()
	{
		delete smc;
		delete er;
		delete ev;
		#ifndef SSCF_CLIENT_STUB_ADAPTER
		delete m_niHandler;
		#endif
	}

	StateMachineController::V1_StateMachineController* getSmc() { return smc; }

private:
	int sim_mode;
	std::list<std::string> commandInitlist;
	std::list<std::string> signalInitlist;
	std::list<std::string> notificationInitlist;

	#ifdef SSCF_CLIENT_STUB_ADAPTER
	SscfClientConnection<V1Proxy, V1> m_connection;
	//std::mutex m_mutex;
	#endif

	StateMachineController::EventViewer *ev;
	StateMachineController::EventRepository *er;
	StateMachineController::V1_StateMachineController *smc;
	#ifndef SSCF_CLIENT_STUB_ADAPTER
	StateMachineController::NiHandler *m_niHandler;
	#endif
};
#ifdef SSCF_CLIENT_STUB_ADAPTER
}
#endif

#endif
