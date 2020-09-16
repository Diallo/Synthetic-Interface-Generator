#ifndef V2__1_0__SERVER_H
#define V2__1_0__SERVER_H 

#include <memory>

#include "V2__1_0__ServerBase.h"
#include "V2StubAdapter.h"

class V2__1_0__Server : public V2__1_0__ServerBase {
public:
    V2__1_0__Server();
    virtual ~V2__1_0__Server();
    
    int init() noexcept override;
    int start() noexcept override;
    int stop() noexcept override;
    int deinit() noexcept override;


    /*==========================================================================
      V2__1_0__Server - Receive methods for subscriptions command
      ========================================================================*/
    int commands_receiveInTRp1_1_11( const tno_dynamics_inTRp1_1_11_t& inTRp1_1_11, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp1_3_13( const tno_dynamics_inTRp1_3_13_t& inTRp1_3_13, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp1_4_14( const tno_dynamics_inTRp1_4_14_t& inTRp1_4_14, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp2_1_17( const tno_dynamics_inTRp2_1_17_t& inTRp2_1_17, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp3_1_18( const tno_dynamics_inTRp3_1_18_t& inTRp3_1_18, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
private:
    EventAPI eventApi;
    NotificationEventHandler notificationEventHandler;
};

#endif //V2__1_0__SERVER_H
