#include "V1__1_0__Client.h"
#include "V1__1_0__ClientDebug.h"
#include "V1_StateMachineController.h"
#include "EventViewer.h"
#include "O2N2ComMADataConverter.h"

static constexpr int OK = 0;
static constexpr int NOK = 1;


static V1__1_0__Client* gV1__1_0__Client = nullptr;
V1__1_0__Client* getV1__1_0__Client() { return gV1__1_0__Client; }

V1__1_0__Client::V1__1_0__Client(): V1__1_0__ClientBase() {}
    
V1__1_0__Client::~V1__1_0__Client() {}

int V1__1_0__Client::init() noexcept {
    //Only invoked during the first activation of the component, called before start
    //Warning parameter update callbacks will be called before and possible after
    //(if a param update happens) init. 
    V1__1_0__ClientBase::init();

    gV1__1_0__Client = this;

    return OK;
}

int V1__1_0__Client::start() noexcept {
    //Invoked when a component is started (e.g. when all required service are available)
    V1__1_0__ClientBase::start();

    return OK;
}

int V1__1_0__Client::stop() noexcept {
    //Invoked when a component is stopped (e.g. when the bundle is stopped or
    //one of the required services becomes unavailable
    V1__1_0__ClientBase::stop();
    return OK;
}

int V1__1_0__Client::deinit() noexcept {
    //Only invoked when the bundle is stopped, called after stop
    V1__1_0__ClientBase::deinit();
    return OK;
}

int V1__1_0__Client::status_receiveOutTRp1_2_25(__attribute__((unused)) const tno_dynamics_outTRp1_2_25_t& outTRp1_2_25, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V1__1_0__ClientReceived outTRp1_2_25" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp1_2_25(  );

    return OK;
}
int V1__1_0__Client::status_receiveOutTRp1_3_26(__attribute__((unused)) const tno_dynamics_outTRp1_3_26_t& outTRp1_3_26, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V1__1_0__ClientReceived outTRp1_3_26" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp1_3_26(  );

    return OK;
}
int V1__1_0__Client::status_receiveOutTRp1_5_28(__attribute__((unused)) const tno_dynamics_outTRp1_5_28_t& outTRp1_5_28, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V1__1_0__ClientReceived outTRp1_5_28" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp1_5_28(  );

    return OK;
}
int V1__1_0__Client::status_receiveOutTRp1_6_29(__attribute__((unused)) const tno_dynamics_outTRp1_6_29_t& outTRp1_6_29, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V1__1_0__ClientReceived outTRp1_6_29" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp1_6_29(  );

    return OK;
}
int V1__1_0__Client::status_receiveOutTRp1_6_30(__attribute__((unused)) const tno_dynamics_outTRp1_6_30_t& outTRp1_6_30, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V1__1_0__ClientReceived outTRp1_6_30" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp1_6_30(  );

    return OK;
}



