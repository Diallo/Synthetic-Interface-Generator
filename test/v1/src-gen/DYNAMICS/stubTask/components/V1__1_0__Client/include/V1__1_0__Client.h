#ifndef V1__1_0__CLIENT_H
#define V1__1_0__CLIENT_H 

#include <memory>

#include "V1__1_0__ClientBase.h"
#include "V1_StateMachineController.h"
#include "ClientStubLifeCycleManager.h"

class V1__1_0__Client : public V1__1_0__ClientBase {
public:
    V1__1_0__Client();
    virtual ~V1__1_0__Client();
    
    int init() noexcept override;
    int start() noexcept override;
    int stop() noexcept override;
    int deinit() noexcept override;


    /*==========================================================================
      V1__1_0__Client - Receive methods for subscriptions command
      ========================================================================*/
    int status_receiveOutTRp1_2_25( const tno_dynamics_outTRp1_2_25_t& outTRp1_2_25, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp1_3_26( const tno_dynamics_outTRp1_3_26_t& outTRp1_3_26, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp1_5_28( const tno_dynamics_outTRp1_5_28_t& outTRp1_5_28, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp1_6_29( const tno_dynamics_outTRp1_6_29_t& outTRp1_6_29, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp1_6_30( const tno_dynamics_outTRp1_6_30_t& outTRp1_6_30, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;

private:
    ClientStubLifeCycleManager clientStubLifeCycleManager;
};

extern V1__1_0__Client* getV1__1_0__Client();

#endif //V1__1_0__CLIENT_H
