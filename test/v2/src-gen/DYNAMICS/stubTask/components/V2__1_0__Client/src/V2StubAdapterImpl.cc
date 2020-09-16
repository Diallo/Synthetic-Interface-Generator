#include "V2StubAdapterImpl.h"
#include "V2__1_0__Client.h"
#include "ComMA2O2NDataConverter.h"

namespace StateMachineController {
	

// Implement this function
void EventAPIHandlerImpl::inTRp1_1_11()
{
	#ifdef SSCF_CLIENT_STUB_ADAPTER
	m_connection.getEventLoop().send([this]()
	{
		try
	    {
			m_connection.Proxy().inTRp1_1_11();
			setControllerSyncStatus(true);
		}
		catch (const SscfTs1::CommunicationException &e)
		{
			std::cout << e.what() << std::endl;
		}
	});
	#endif
	
	tno_dynamics_inTRp1_1_11_t inTRp1_1_11{};
	std::cout << std::endl << "######## V2__1_0__Client: Going to trigger Signal: inTRp1_1_11" << std::endl;
	getV2__1_0__Client()->commands_sendInTRp1_1_11( inTRp1_1_11 );
	
}

// Implement this function
void EventAPIHandlerImpl::inTRp1_3_13()
{
	#ifdef SSCF_CLIENT_STUB_ADAPTER
	m_connection.getEventLoop().send([this]()
	{
		try
	    {
			m_connection.Proxy().inTRp1_3_13();
			setControllerSyncStatus(true);
		}
		catch (const SscfTs1::CommunicationException &e)
		{
			std::cout << e.what() << std::endl;
		}
	});
	#endif
	
	tno_dynamics_inTRp1_3_13_t inTRp1_3_13{};
	std::cout << std::endl << "######## V2__1_0__Client: Going to trigger Signal: inTRp1_3_13" << std::endl;
	getV2__1_0__Client()->commands_sendInTRp1_3_13( inTRp1_3_13 );
	
}

// Implement this function
void EventAPIHandlerImpl::inTRp1_4_14()
{
	#ifdef SSCF_CLIENT_STUB_ADAPTER
	m_connection.getEventLoop().send([this]()
	{
		try
	    {
			m_connection.Proxy().inTRp1_4_14();
			setControllerSyncStatus(true);
		}
		catch (const SscfTs1::CommunicationException &e)
		{
			std::cout << e.what() << std::endl;
		}
	});
	#endif
	
	tno_dynamics_inTRp1_4_14_t inTRp1_4_14{};
	std::cout << std::endl << "######## V2__1_0__Client: Going to trigger Signal: inTRp1_4_14" << std::endl;
	getV2__1_0__Client()->commands_sendInTRp1_4_14( inTRp1_4_14 );
	
}

// Implement this function
void EventAPIHandlerImpl::inTRp2_1_17()
{
	#ifdef SSCF_CLIENT_STUB_ADAPTER
	m_connection.getEventLoop().send([this]()
	{
		try
	    {
			m_connection.Proxy().inTRp2_1_17();
			setControllerSyncStatus(true);
		}
		catch (const SscfTs1::CommunicationException &e)
		{
			std::cout << e.what() << std::endl;
		}
	});
	#endif
	
	tno_dynamics_inTRp2_1_17_t inTRp2_1_17{};
	std::cout << std::endl << "######## V2__1_0__Client: Going to trigger Signal: inTRp2_1_17" << std::endl;
	getV2__1_0__Client()->commands_sendInTRp2_1_17( inTRp2_1_17 );
	
}

// Implement this function
void EventAPIHandlerImpl::inTRp3_1_18()
{
	#ifdef SSCF_CLIENT_STUB_ADAPTER
	m_connection.getEventLoop().send([this]()
	{
		try
	    {
			m_connection.Proxy().inTRp3_1_18();
			setControllerSyncStatus(true);
		}
		catch (const SscfTs1::CommunicationException &e)
		{
			std::cout << e.what() << std::endl;
		}
	});
	#endif
	
	tno_dynamics_inTRp3_1_18_t inTRp3_1_18{};
	std::cout << std::endl << "######## V2__1_0__Client: Going to trigger Signal: inTRp3_1_18" << std::endl;
	getV2__1_0__Client()->commands_sendInTRp3_1_18( inTRp3_1_18 );
	
}

}
