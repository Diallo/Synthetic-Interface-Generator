#ifndef V1STUBADAPTERSTUBADAPTERIMPL_H_
#define V1STUBADAPTERSTUBADAPTERIMPL_H_

#include "V1StubAdapter.h"

#ifdef SSCF_CLIENT_STUB_ADAPTER
//#include "V1.h"
#include "V1.h"
#include "SSCFClientConnection.h"

//namespace SscfV1 {
namespace UNDEFINED {
}
#endif

namespace StateMachineController
{
	#ifdef SSCF_CLIENT_STUB_ADAPTER
	using namespace UNDEFINED; //SscfV1;
	#endif
	
	class EventAPIHandlerImpl : public EventAPIHandler
	{
		public:
		#ifndef SSCF_CLIENT_STUB_ADAPTER
		EventAPIHandlerImpl(StateMachineController::V1_StateMachineController& smc) : EventAPIHandler(smc) { };
		#endif
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		EventAPIHandlerImpl(StateMachineController::V1_StateMachineController& smc, 
			SscfClientConnection<UNDEFINED::V1Proxy, UNDEFINED::V1>& _m_connection) : EventAPIHandler(smc), m_connection(_m_connection) { };
			// SscfClientConnection<SscfV1::V1Proxy, SscfV1::V1>& _m_connection) : EventAPIHandler(smc), m_connection(_m_connection) { };
		#endif
		virtual ~EventAPIHandlerImpl() {};
		
		// Following are the Commands and Signals Method that will be called by the client stub.
		void inTRp1_1_24() override;
		void inTRp1_1_27() override;
		void inTRp2_1_31() override;
		void inTRp3_1_32() override;
		void inTRp3_1_33() override;
		
		#ifdef SSCF_CLIENT_STUB_ADAPTER
		//SscfClientConnection<SscfV1::V1Proxy, SscfV1::V1>& m_connection;
		SscfClientConnection<UNDEFINED::V1Proxy, UNDEFINED::V1>& m_connection;

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
