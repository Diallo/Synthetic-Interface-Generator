#ifndef V1__1_0__SERVER_H
#define V1__1_0__SERVER_H 

#include <memory>

#include "V1__1_0__ServerBase.h"
#include "V1StubAdapter.h"

class V1__1_0__Server : public V1__1_0__ServerBase {
public:
    V1__1_0__Server();
    virtual ~V1__1_0__Server();
    
    int init() noexcept override;
    int start() noexcept override;
    int stop() noexcept override;
    int deinit() noexcept override;


    /*==========================================================================
      V1__1_0__Server - Receive methods for subscriptions command
      ========================================================================*/
    int commands_receiveInTRp1_1_24( const tno_dynamics_inTRp1_1_24_t& inTRp1_1_24, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp1_1_27( const tno_dynamics_inTRp1_1_27_t& inTRp1_1_27, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp2_1_31( const tno_dynamics_inTRp2_1_31_t& inTRp2_1_31, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp3_1_32( const tno_dynamics_inTRp3_1_32_t& inTRp3_1_32, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp3_1_33( const tno_dynamics_inTRp3_1_33_t& inTRp3_1_33, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
private:
    EventAPI eventApi;
    NotificationEventHandler notificationEventHandler;
};

#endif //V1__1_0__SERVER_H
