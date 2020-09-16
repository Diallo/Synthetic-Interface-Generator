#include "V2__1_0__Client.h"
#include "V2__1_0__ClientDebug.h"
#include "V2_StateMachineController.h"
#include "EventViewer.h"
#include "O2N2ComMADataConverter.h"

static constexpr int OK = 0;
static constexpr int NOK = 1;


static V2__1_0__Client* gV2__1_0__Client = nullptr;
V2__1_0__Client* getV2__1_0__Client() { return gV2__1_0__Client; }

V2__1_0__Client::V2__1_0__Client(): V2__1_0__ClientBase() {}
    
V2__1_0__Client::~V2__1_0__Client() {}

int V2__1_0__Client::init() noexcept {
    //Only invoked during the first activation of the component, called before start
    //Warning parameter update callbacks will be called before and possible after
    //(if a param update happens) init. 
    V2__1_0__ClientBase::init();

    gV2__1_0__Client = this;

    return OK;
}

int V2__1_0__Client::start() noexcept {
    //Invoked when a component is started (e.g. when all required service are available)
    V2__1_0__ClientBase::start();

    return OK;
}

int V2__1_0__Client::stop() noexcept {
    //Invoked when a component is stopped (e.g. when the bundle is stopped or
    //one of the required services becomes unavailable
    V2__1_0__ClientBase::stop();
    return OK;
}

int V2__1_0__Client::deinit() noexcept {
    //Only invoked when the bundle is stopped, called after stop
    V2__1_0__ClientBase::deinit();
    return OK;
}

int V2__1_0__Client::status_receiveOutTRp1_2_12(__attribute__((unused)) const tno_dynamics_outTRp1_2_12_t& outTRp1_2_12, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp1_2_12" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp1_2_12(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp1_1_15(__attribute__((unused)) const tno_dynamics_outTRp1_1_15_t& outTRp1_1_15, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp1_1_15" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp1_1_15(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp1_1_16(__attribute__((unused)) const tno_dynamics_outTRp1_1_16_t& outTRp1_1_16, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp1_1_16" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp1_1_16(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp1_6_19(__attribute__((unused)) const tno_dynamics_outTRp1_6_19_t& outTRp1_6_19, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp1_6_19" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp1_6_19(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp1_8_21(__attribute__((unused)) const tno_dynamics_outTRp1_8_21_t& outTRp1_8_21, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp1_8_21" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp1_8_21(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp1_6_22(__attribute__((unused)) const tno_dynamics_outTRp1_6_22_t& outTRp1_6_22, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp1_6_22" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp1_6_22(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp1_9_23(__attribute__((unused)) const tno_dynamics_outTRp1_9_23_t& outTRp1_9_23, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp1_9_23" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp1_9_23(  );

    return OK;
}



