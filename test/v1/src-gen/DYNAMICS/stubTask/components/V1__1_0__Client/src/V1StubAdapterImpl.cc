#include "V1StubAdapterImpl.h"
#include "V1__1_0__Client.h"
#include "ComMA2O2NDataConverter.h"

namespace StateMachineController {
	

// Implement this function
void EventAPIHandlerImpl::inTRp1_1_24()
{
	#ifdef SSCF_CLIENT_STUB_ADAPTER
	m_connection.getEventLoop().send([this]()
	{
		try
	    {
			m_connection.Proxy().inTRp1_1_24();
			setControllerSyncStatus(true);
		}
		catch (const SscfTs1::CommunicationException &e)
		{
			std::cout << e.what() << std::endl;
		}
	});
	#endif
	
	tno_dynamics_inTRp1_1_24_t inTRp1_1_24{};
	std::cout << std::endl << "######## V1__1_0__Client: Going to trigger Signal: inTRp1_1_24" << std::endl;
	getV1__1_0__Client()->commands_sendInTRp1_1_24( inTRp1_1_24 );
	
}

// Implement this function
void EventAPIHandlerImpl::inTRp1_1_27()
{
	#ifdef SSCF_CLIENT_STUB_ADAPTER
	m_connection.getEventLoop().send([this]()
	{
		try
	    {
			m_connection.Proxy().inTRp1_1_27();
			setControllerSyncStatus(true);
		}
		catch (const SscfTs1::CommunicationException &e)
		{
			std::cout << e.what() << std::endl;
		}
	});
	#endif
	
	tno_dynamics_inTRp1_1_27_t inTRp1_1_27{};
	std::cout << std::endl << "######## V1__1_0__Client: Going to trigger Signal: inTRp1_1_27" << std::endl;
	getV1__1_0__Client()->commands_sendInTRp1_1_27( inTRp1_1_27 );
	
}

// Implement this function
void EventAPIHandlerImpl::inTRp2_1_31()
{
	#ifdef SSCF_CLIENT_STUB_ADAPTER
	m_connection.getEventLoop().send([this]()
	{
		try
	    {
			m_connection.Proxy().inTRp2_1_31();
			setControllerSyncStatus(true);
		}
		catch (const SscfTs1::CommunicationException &e)
		{
			std::cout << e.what() << std::endl;
		}
	});
	#endif
	
	tno_dynamics_inTRp2_1_31_t inTRp2_1_31{};
	std::cout << std::endl << "######## V1__1_0__Client: Going to trigger Signal: inTRp2_1_31" << std::endl;
	getV1__1_0__Client()->commands_sendInTRp2_1_31( inTRp2_1_31 );
	
}

// Implement this function
void EventAPIHandlerImpl::inTRp3_1_32()
{
	#ifdef SSCF_CLIENT_STUB_ADAPTER
	m_connection.getEventLoop().send([this]()
	{
		try
	    {
			m_connection.Proxy().inTRp3_1_32();
			setControllerSyncStatus(true);
		}
		catch (const SscfTs1::CommunicationException &e)
		{
			std::cout << e.what() << std::endl;
		}
	});
	#endif
	
	tno_dynamics_inTRp3_1_32_t inTRp3_1_32{};
	std::cout << std::endl << "######## V1__1_0__Client: Going to trigger Signal: inTRp3_1_32" << std::endl;
	getV1__1_0__Client()->commands_sendInTRp3_1_32( inTRp3_1_32 );
	
}

// Implement this function
void EventAPIHandlerImpl::inTRp3_1_33()
{
	#ifdef SSCF_CLIENT_STUB_ADAPTER
	m_connection.getEventLoop().send([this]()
	{
		try
	    {
			m_connection.Proxy().inTRp3_1_33();
			setControllerSyncStatus(true);
		}
		catch (const SscfTs1::CommunicationException &e)
		{
			std::cout << e.what() << std::endl;
		}
	});
	#endif
	
	tno_dynamics_inTRp3_1_33_t inTRp3_1_33{};
	std::cout << std::endl << "######## V1__1_0__Client: Going to trigger Signal: inTRp3_1_33" << std::endl;
	getV1__1_0__Client()->commands_sendInTRp3_1_33( inTRp3_1_33 );
	
}

}
