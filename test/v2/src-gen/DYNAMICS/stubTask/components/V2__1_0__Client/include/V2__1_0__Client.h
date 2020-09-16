#ifndef V2__1_0__CLIENT_H
#define V2__1_0__CLIENT_H 

#include <memory>

#include "V2__1_0__ClientBase.h"
#include "V2_StateMachineController.h"
#include "ClientStubLifeCycleManager.h"

class V2__1_0__Client : public V2__1_0__ClientBase {
public:
    V2__1_0__Client();
    virtual ~V2__1_0__Client();
    
    int init() noexcept override;
    int start() noexcept override;
    int stop() noexcept override;
    int deinit() noexcept override;


    /*==========================================================================
      V2__1_0__Client - Receive methods for subscriptions command
      ========================================================================*/
    int status_receiveOutTRp1_2_12( const tno_dynamics_outTRp1_2_12_t& outTRp1_2_12, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp1_1_15( const tno_dynamics_outTRp1_1_15_t& outTRp1_1_15, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp1_1_16( const tno_dynamics_outTRp1_1_16_t& outTRp1_1_16, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp1_6_19( const tno_dynamics_outTRp1_6_19_t& outTRp1_6_19, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp1_8_21( const tno_dynamics_outTRp1_8_21_t& outTRp1_8_21, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp1_6_22( const tno_dynamics_outTRp1_6_22_t& outTRp1_6_22, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp1_9_23( const tno_dynamics_outTRp1_9_23_t& outTRp1_9_23, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;

private:
    ClientStubLifeCycleManager clientStubLifeCycleManager;
};

extern V2__1_0__Client* getV2__1_0__Client();

#endif //V2__1_0__CLIENT_H
