#ifndef V2STUBADAPTERSTUBADAPTERIMPL_H_
#define V2STUBADAPTERSTUBADAPTERIMPL_H_

#include "V2StubAdapter.h"

#ifdef SSCF_CLIENT_STUB_ADAPTER
//#include "V2.h"
#include "V2.h"
#include "SSCFClientConnection.h"

//namespace SscfV2 {
namespace UNDEFINED {
}
#endif

namespace StateMachineController
{
	#ifdef SSCF_CLIENT_STUB_ADAPTER
	using namespace UNDEFINED; //SscfV2;
	#endif
	
	class EventAPIHandlerImpl : public EventAPIHandler
	{
		public:
		#ifndef SSCF_CLIENT_STUB_ADAPTER
		EventAPIHandlerImpl(StateMachineController::V2_StateMachineController& smc) : EventAPIHandler(smc) { };
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		EventAPIHandlerImpl(StateMachineController::V2_StateMachineController& smc, 
			SscfClientConnection<UNDEFINED::V2Proxy, UNDEFINED::V2>& _m_connection) : EventAPIHandler(smc), m_connection(_m_connection) { };
			// SscfClientConnection<SscfV2::V2Proxy, SscfV2::V2>& _m_connection) : EventAPIHandler(smc), m_connection(_m_connection) { };
		#endif
		virtual ~EventAPIHandlerImpl() {};
		
		// Following are the Commands and Signals Method that will be called by the client stub.
		void inTRp2_1_3398721() override;
		void inTRp3_1_3398722() override;
		void inTRp1_1_3398723() override;
		void inTRp3_2_3398726() override;
		void inTRp2_1_3398728() override;
		void inTRp3_4_3398729() override;
		void inTRp2_1_3398732() override;
		void inTRp3_5_3398734() override;
		void inTRp3_4_3398737() override;
		void inTRp2_2_3398739() override;
		void inTRp3_10_3398741() override;
		void inTRp1_2_3398742() override;
		void inTRp1_2_3398743() override;
		void inTRp1_4_3398746() override;
		void inTRp3_9_3398747() override;
		void inTRp3_5_3398749() override;
		void inTRp3_4_3398750() override;
		void inTRp3_9_3398751() override;
		void inTRp3_8_3398752() override;
		void inTRp2_1_3398753() override;
		void inTRp2_3_3398754() override;
		void inTRp1_5_3398755() override;
		void inTRp2_1_3398757() override;
		void inTRp1_3_3398758() override;
		void inTRp3_5_3398760() override;
		void inTRp3_12_3398765() override;
		void inTRp1_8_3398767() override;
		void inTRp3_9_3398768() override;
		void inTRp3_11_3398770() override;
		void inTRp2_4_3398772() override;
		void inTRp3_26_3398774() override;
		void inTRp5_1_3398776() override;
		void inTRp3_8_3398780() override;
		void inTRp2_3_3398781() override;
		void inTRp1_2_3398783() override;
		void inTRp1_14_3398785() override;
		void inTRp3_12_3398786() override;
		void inTRp3_12_3398787() override;
		void inTRp1_16_3398790() override;
		void inTRp3_13_3398792() override;
		void inTRp10_1_3398795() override;
		void inTRp11_1_3398796() override;
		void inTRp3_18_3398798() override;
		void inTRp9_1_3398800() override;
		void inTRp3_14_3398803() override;
		void inTRp10_1_3398805() override;
		void inTRp5_3_3398807() override;
		void inTRp1_9_3398808() override;
		void inTRp1_2_3398812() override;
		void inTRp3_10_3398813() override;
		void inTRp3_17_3398814() override;
		void inTRp12_1_3398818() override;
		void inTRp13_1_3398819() override;
		void inTRp1_27_3398823() override;
		void inTRp1_5_3398825() override;
		void inTRp2_5_3398826() override;
		void inTRp3_15_3398827() override;
		void inTRp1_31_3398828() override;
		void inTRp1_14_3398833() override;
		void inTRp1_32_3398834() override;
		void inTRp4_1_3398838() override;
		void inTRp14_1_3398841() override;
		void inTRp3_3_3398842() override;
		void inTRp2_8_3398847() override;
		void inTRp1_10_3398849() override;
		void inTRp2_6_3398850() override;
		void inTRp15_1_3398854() override;
		void inTRp16_1_3398856() override;
		void inTRp17_1_3398858() override;
		void inTRp1_15_3398859() override;
		void inTRp3_34_3398860() override;
		void inTRp1_24_3398861() override;
		void inTRp1_7_3398862() override;
		void inTRp17_2_3398864() override;
		void inTRp3_27_3398865() override;
		void inTRp4_2_3398868() override;
		void inTRp18_1_3398871() override;
		void inTRp3_22_3398872() override;
		void inTRp2_2_3398875() override;
		void inTRp4_1_3398876() override;
		void inTRp3_28_3398878() override;
		
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		//SscfClientConnection<SscfV2::V2Proxy, SscfV2::V2>& m_connection;
		SscfClientConnection<UNDEFINED::V2Proxy, UNDEFINED::V2>& m_connection;

		// SSCF Data Adapters
		
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		
		#endif
	};
}
#endif
