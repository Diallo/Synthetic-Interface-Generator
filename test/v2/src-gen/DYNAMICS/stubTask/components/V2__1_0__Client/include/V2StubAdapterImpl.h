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
		void inTRp1_1_11() override;
		void inTRp1_3_13() override;
		void inTRp1_4_14() override;
		void inTRp2_1_17() override;
		void inTRp3_1_18() override;
		
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		//SscfClientConnection<SscfV2::V2Proxy, SscfV2::V2>& m_connection;
		SscfClientConnection<UNDEFINED::V2Proxy, UNDEFINED::V2>& m_connection;

		// SSCF Data Adapters
		
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		// Data Adapter: ARG > SSCF Type => SMC Type
		
		#endif
	};
}
#endif
