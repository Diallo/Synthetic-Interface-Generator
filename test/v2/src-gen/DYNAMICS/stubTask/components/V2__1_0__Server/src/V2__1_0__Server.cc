#include "V2__1_0__Server.h"
#include "V2__1_0__ServerDebug.h"
#include "O2N2ComMADataConverter.h"
#include "ComMA2O2NDataConverter.h"

static constexpr int OK = 0;
static constexpr int NOK = 1;

static std::chrono::milliseconds getCurrentTimestamp() {
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
}

V2__1_0__Server* gV2__1_0__Server = nullptr;
V2__1_0__Server* getV2__1_0__Server() { return gV2__1_0__Server; }

void outTRp1_2_12Callback(  ) {
    tno_dynamics_outTRp1_2_12_t outTRp1_2_12{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp1_2_12" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp1_2_12( outTRp1_2_12 );
}

void outTRp1_1_15Callback(  ) {
    tno_dynamics_outTRp1_1_15_t outTRp1_1_15{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp1_1_15" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp1_1_15( outTRp1_1_15 );
}

void outTRp1_1_16Callback(  ) {
    tno_dynamics_outTRp1_1_16_t outTRp1_1_16{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp1_1_16" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp1_1_16( outTRp1_1_16 );
}

void outTRp1_6_19Callback(  ) {
    tno_dynamics_outTRp1_6_19_t outTRp1_6_19{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp1_6_19" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp1_6_19( outTRp1_6_19 );
}

void outTRp1_8_21Callback(  ) {
    tno_dynamics_outTRp1_8_21_t outTRp1_8_21{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp1_8_21" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp1_8_21( outTRp1_8_21 );
}

void outTRp1_6_22Callback(  ) {
    tno_dynamics_outTRp1_6_22_t outTRp1_6_22{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp1_6_22" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp1_6_22( outTRp1_6_22 );
}

void outTRp1_9_23Callback(  ) {
    tno_dynamics_outTRp1_9_23_t outTRp1_9_23{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp1_9_23" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp1_9_23( outTRp1_9_23 );
}


V2__1_0__Server::V2__1_0__Server(): V2__1_0__ServerBase() {}
    
V2__1_0__Server::~V2__1_0__Server() {}

int V2__1_0__Server::init() noexcept {
    //Only invoked during the first activation of the component, called before start
    //Warning parameter update callbacks will be called before and possible after
    //(if a param update happens) init. 
    V2__1_0__ServerBase::init();

    gV2__1_0__Server = this;

	notificationEventHandler.register_outTRp1_2_12CB( outTRp1_2_12Callback );
	notificationEventHandler.register_outTRp1_1_15CB( outTRp1_1_15Callback );
	notificationEventHandler.register_outTRp1_1_16CB( outTRp1_1_16Callback );
	notificationEventHandler.register_outTRp1_6_19CB( outTRp1_6_19Callback );
	notificationEventHandler.register_outTRp1_8_21CB( outTRp1_8_21Callback );
	notificationEventHandler.register_outTRp1_6_22CB( outTRp1_6_22Callback );
	notificationEventHandler.register_outTRp1_9_23CB( outTRp1_9_23Callback );

    return OK;
}

int V2__1_0__Server::start() noexcept {
    //Invoked when a component is started (e.g. when all required service are available)
    V2__1_0__ServerBase::start();
    return OK;
}

int V2__1_0__Server::stop() noexcept {
    //Invoked when a component is stopped (e.g. when the bundle is stopped or
    //one of the required services becomes unavailable
    V2__1_0__ServerBase::stop();
    return OK;
}

int V2__1_0__Server::deinit() noexcept {
    //Only invoked when the bundle is stopped, called after stop
    V2__1_0__ServerBase::deinit();
    return OK;
}

int V2__1_0__Server::commands_receiveInTRp1_1_11(__attribute__((unused)) const tno_dynamics_inTRp1_1_11_t& inTRp1_1_11, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp1_1_11\n" );
    eventApi.inTRp1_1_11(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp1_3_13(__attribute__((unused)) const tno_dynamics_inTRp1_3_13_t& inTRp1_3_13, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp1_3_13\n" );
    eventApi.inTRp1_3_13(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp1_4_14(__attribute__((unused)) const tno_dynamics_inTRp1_4_14_t& inTRp1_4_14, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp1_4_14\n" );
    eventApi.inTRp1_4_14(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp2_1_17(__attribute__((unused)) const tno_dynamics_inTRp2_1_17_t& inTRp2_1_17, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp2_1_17\n" );
    eventApi.inTRp2_1_17(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp3_1_18(__attribute__((unused)) const tno_dynamics_inTRp3_1_18_t& inTRp3_1_18, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp3_1_18\n" );
    eventApi.inTRp3_1_18(  );
    return OK;
}

