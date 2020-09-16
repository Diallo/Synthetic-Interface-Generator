#include "V1__1_0__Server.h"
#include "V1__1_0__ServerDebug.h"
#include "O2N2ComMADataConverter.h"
#include "ComMA2O2NDataConverter.h"

static constexpr int OK = 0;
static constexpr int NOK = 1;

static std::chrono::milliseconds getCurrentTimestamp() {
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
}

V1__1_0__Server* gV1__1_0__Server = nullptr;
V1__1_0__Server* getV1__1_0__Server() { return gV1__1_0__Server; }

void outTRp1_2_25Callback(  ) {
    tno_dynamics_outTRp1_2_25_t outTRp1_2_25{};

    std::cout << std::endl << "######## O2N V1__1_0__Server_sendOutTRp1_2_25" <<std::endl;
    getV1__1_0__Server()->status_sendOutTRp1_2_25( outTRp1_2_25 );
}

void outTRp1_3_26Callback(  ) {
    tno_dynamics_outTRp1_3_26_t outTRp1_3_26{};

    std::cout << std::endl << "######## O2N V1__1_0__Server_sendOutTRp1_3_26" <<std::endl;
    getV1__1_0__Server()->status_sendOutTRp1_3_26( outTRp1_3_26 );
}

void outTRp1_5_28Callback(  ) {
    tno_dynamics_outTRp1_5_28_t outTRp1_5_28{};

    std::cout << std::endl << "######## O2N V1__1_0__Server_sendOutTRp1_5_28" <<std::endl;
    getV1__1_0__Server()->status_sendOutTRp1_5_28( outTRp1_5_28 );
}

void outTRp1_6_29Callback(  ) {
    tno_dynamics_outTRp1_6_29_t outTRp1_6_29{};

    std::cout << std::endl << "######## O2N V1__1_0__Server_sendOutTRp1_6_29" <<std::endl;
    getV1__1_0__Server()->status_sendOutTRp1_6_29( outTRp1_6_29 );
}

void outTRp1_6_30Callback(  ) {
    tno_dynamics_outTRp1_6_30_t outTRp1_6_30{};

    std::cout << std::endl << "######## O2N V1__1_0__Server_sendOutTRp1_6_30" <<std::endl;
    getV1__1_0__Server()->status_sendOutTRp1_6_30( outTRp1_6_30 );
}


V1__1_0__Server::V1__1_0__Server(): V1__1_0__ServerBase() {}
    
V1__1_0__Server::~V1__1_0__Server() {}

int V1__1_0__Server::init() noexcept {
    //Only invoked during the first activation of the component, called before start
    //Warning parameter update callbacks will be called before and possible after
    //(if a param update happens) init. 
    V1__1_0__ServerBase::init();

    gV1__1_0__Server = this;

	notificationEventHandler.register_outTRp1_2_25CB( outTRp1_2_25Callback );
	notificationEventHandler.register_outTRp1_3_26CB( outTRp1_3_26Callback );
	notificationEventHandler.register_outTRp1_5_28CB( outTRp1_5_28Callback );
	notificationEventHandler.register_outTRp1_6_29CB( outTRp1_6_29Callback );
	notificationEventHandler.register_outTRp1_6_30CB( outTRp1_6_30Callback );

    return OK;
}

int V1__1_0__Server::start() noexcept {
    //Invoked when a component is started (e.g. when all required service are available)
    V1__1_0__ServerBase::start();
    return OK;
}

int V1__1_0__Server::stop() noexcept {
    //Invoked when a component is stopped (e.g. when the bundle is stopped or
    //one of the required services becomes unavailable
    V1__1_0__ServerBase::stop();
    return OK;
}

int V1__1_0__Server::deinit() noexcept {
    //Only invoked when the bundle is stopped, called after stop
    V1__1_0__ServerBase::deinit();
    return OK;
}

int V1__1_0__Server::commands_receiveInTRp1_1_24(__attribute__((unused)) const tno_dynamics_inTRp1_1_24_t& inTRp1_1_24, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V1__1_0__Server received: inTRp1_1_24\n" );
    eventApi.inTRp1_1_24(  );
    return OK;
}
int V1__1_0__Server::commands_receiveInTRp1_1_27(__attribute__((unused)) const tno_dynamics_inTRp1_1_27_t& inTRp1_1_27, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V1__1_0__Server received: inTRp1_1_27\n" );
    eventApi.inTRp1_1_27(  );
    return OK;
}
int V1__1_0__Server::commands_receiveInTRp2_1_31(__attribute__((unused)) const tno_dynamics_inTRp2_1_31_t& inTRp2_1_31, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V1__1_0__Server received: inTRp2_1_31\n" );
    eventApi.inTRp2_1_31(  );
    return OK;
}
int V1__1_0__Server::commands_receiveInTRp3_1_32(__attribute__((unused)) const tno_dynamics_inTRp3_1_32_t& inTRp3_1_32, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V1__1_0__Server received: inTRp3_1_32\n" );
    eventApi.inTRp3_1_32(  );
    return OK;
}
int V1__1_0__Server::commands_receiveInTRp3_1_33(__attribute__((unused)) const tno_dynamics_inTRp3_1_33_t& inTRp3_1_33, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V1__1_0__Server received: inTRp3_1_33\n" );
    eventApi.inTRp3_1_33(  );
    return OK;
}

