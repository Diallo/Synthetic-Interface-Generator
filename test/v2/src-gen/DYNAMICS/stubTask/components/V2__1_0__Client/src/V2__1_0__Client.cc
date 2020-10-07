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

int V2__1_0__Client::status_receiveOutTRp1_1_3398718(__attribute__((unused)) const tno_dynamics_outTRp1_1_3398718_t& outTRp1_1_3398718, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp1_1_3398718" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp1_1_3398718(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp1_1_3398719(__attribute__((unused)) const tno_dynamics_outTRp1_1_3398719_t& outTRp1_1_3398719, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp1_1_3398719" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp1_1_3398719(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp1_1_3398720(__attribute__((unused)) const tno_dynamics_outTRp1_1_3398720_t& outTRp1_1_3398720, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp1_1_3398720" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp1_1_3398720(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp3_1_3398724(__attribute__((unused)) const tno_dynamics_outTRp3_1_3398724_t& outTRp3_1_3398724, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp3_1_3398724" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp3_1_3398724(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp1_4_3398725(__attribute__((unused)) const tno_dynamics_outTRp1_4_3398725_t& outTRp1_4_3398725, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp1_4_3398725" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp1_4_3398725(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp3_3_3398727(__attribute__((unused)) const tno_dynamics_outTRp3_3_3398727_t& outTRp3_3_3398727, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp3_3_3398727" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp3_3_3398727(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp3_4_3398731(__attribute__((unused)) const tno_dynamics_outTRp3_4_3398731_t& outTRp3_4_3398731, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp3_4_3398731" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp3_4_3398731(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp3_5_3398733(__attribute__((unused)) const tno_dynamics_outTRp3_5_3398733_t& outTRp3_5_3398733, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp3_5_3398733" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp3_5_3398733(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp3_2_3398735(__attribute__((unused)) const tno_dynamics_outTRp3_2_3398735_t& outTRp3_2_3398735, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp3_2_3398735" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp3_2_3398735(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp3_3_3398736(__attribute__((unused)) const tno_dynamics_outTRp3_3_3398736_t& outTRp3_3_3398736, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp3_3_3398736" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp3_3_3398736(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp1_1_3398738(__attribute__((unused)) const tno_dynamics_outTRp1_1_3398738_t& outTRp1_1_3398738, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp1_1_3398738" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp1_1_3398738(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp2_3_3398740(__attribute__((unused)) const tno_dynamics_outTRp2_3_3398740_t& outTRp2_3_3398740, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp2_3_3398740" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp2_3_3398740(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp4_1_3398744(__attribute__((unused)) const tno_dynamics_outTRp4_1_3398744_t& outTRp4_1_3398744, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp4_1_3398744" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp4_1_3398744(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp5_1_3398745(__attribute__((unused)) const tno_dynamics_outTRp5_1_3398745_t& outTRp5_1_3398745, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp5_1_3398745" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp5_1_3398745(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp3_10_3398748(__attribute__((unused)) const tno_dynamics_outTRp3_10_3398748_t& outTRp3_10_3398748, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp3_10_3398748" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp3_10_3398748(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp1_6_3398756(__attribute__((unused)) const tno_dynamics_outTRp1_6_3398756_t& outTRp1_6_3398756, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp1_6_3398756" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp1_6_3398756(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp1_4_3398759(__attribute__((unused)) const tno_dynamics_outTRp1_4_3398759_t& outTRp1_4_3398759, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp1_4_3398759" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp1_4_3398759(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp3_6_3398761(__attribute__((unused)) const tno_dynamics_outTRp3_6_3398761_t& outTRp3_6_3398761, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp3_6_3398761" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp3_6_3398761(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp2_6_3398762(__attribute__((unused)) const tno_dynamics_outTRp2_6_3398762_t& outTRp2_6_3398762, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp2_6_3398762" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp2_6_3398762(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp3_4_3398763(__attribute__((unused)) const tno_dynamics_outTRp3_4_3398763_t& outTRp3_4_3398763, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp3_4_3398763" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp3_4_3398763(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp3_11_3398764(__attribute__((unused)) const tno_dynamics_outTRp3_11_3398764_t& outTRp3_11_3398764, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp3_11_3398764" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp3_11_3398764(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp3_8_3398766(__attribute__((unused)) const tno_dynamics_outTRp3_8_3398766_t& outTRp3_8_3398766, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp3_8_3398766" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp3_8_3398766(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp1_10_3398769(__attribute__((unused)) const tno_dynamics_outTRp1_10_3398769_t& outTRp1_10_3398769, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp1_10_3398769" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp1_10_3398769(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp3_12_3398771(__attribute__((unused)) const tno_dynamics_outTRp3_12_3398771_t& outTRp3_12_3398771, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp3_12_3398771" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp3_12_3398771(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp6_1_3398773(__attribute__((unused)) const tno_dynamics_outTRp6_1_3398773_t& outTRp6_1_3398773, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp6_1_3398773" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp6_1_3398773(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp7_1_3398775(__attribute__((unused)) const tno_dynamics_outTRp7_1_3398775_t& outTRp7_1_3398775, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp7_1_3398775" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp7_1_3398775(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp5_2_3398777(__attribute__((unused)) const tno_dynamics_outTRp5_2_3398777_t& outTRp5_2_3398777, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp5_2_3398777" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp5_2_3398777(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp1_6_3398778(__attribute__((unused)) const tno_dynamics_outTRp1_6_3398778_t& outTRp1_6_3398778, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp1_6_3398778" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp1_6_3398778(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp1_14_3398782(__attribute__((unused)) const tno_dynamics_outTRp1_14_3398782_t& outTRp1_14_3398782, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp1_14_3398782" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp1_14_3398782(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp1_3_3398784(__attribute__((unused)) const tno_dynamics_outTRp1_3_3398784_t& outTRp1_3_3398784, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp1_3_3398784" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp1_3_3398784(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp8_1_3398788(__attribute__((unused)) const tno_dynamics_outTRp8_1_3398788_t& outTRp8_1_3398788, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp8_1_3398788" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp8_1_3398788(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp9_1_3398789(__attribute__((unused)) const tno_dynamics_outTRp9_1_3398789_t& outTRp9_1_3398789, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp9_1_3398789" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp9_1_3398789(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp1_17_3398791(__attribute__((unused)) const tno_dynamics_outTRp1_17_3398791_t& outTRp1_17_3398791, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp1_17_3398791" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp1_17_3398791(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp1_7_3398793(__attribute__((unused)) const tno_dynamics_outTRp1_7_3398793_t& outTRp1_7_3398793, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp1_7_3398793" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp1_7_3398793(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp1_7_3398794(__attribute__((unused)) const tno_dynamics_outTRp1_7_3398794_t& outTRp1_7_3398794, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp1_7_3398794" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp1_7_3398794(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp1_4_3398797(__attribute__((unused)) const tno_dynamics_outTRp1_4_3398797_t& outTRp1_4_3398797, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp1_4_3398797" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp1_4_3398797(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp3_29_3398799(__attribute__((unused)) const tno_dynamics_outTRp3_29_3398799_t& outTRp3_29_3398799, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp3_29_3398799" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp3_29_3398799(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp9_2_3398801(__attribute__((unused)) const tno_dynamics_outTRp9_2_3398801_t& outTRp9_2_3398801, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp9_2_3398801" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp9_2_3398801(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp3_13_3398802(__attribute__((unused)) const tno_dynamics_outTRp3_13_3398802_t& outTRp3_13_3398802, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp3_13_3398802" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp3_13_3398802(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp1_7_3398804(__attribute__((unused)) const tno_dynamics_outTRp1_7_3398804_t& outTRp1_7_3398804, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp1_7_3398804" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp1_7_3398804(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp3_32_3398806(__attribute__((unused)) const tno_dynamics_outTRp3_32_3398806_t& outTRp3_32_3398806, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp3_32_3398806" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp3_32_3398806(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp1_20_3398809(__attribute__((unused)) const tno_dynamics_outTRp1_20_3398809_t& outTRp1_20_3398809, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp1_20_3398809" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp1_20_3398809(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp9_3_3398810(__attribute__((unused)) const tno_dynamics_outTRp9_3_3398810_t& outTRp9_3_3398810, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp9_3_3398810" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp9_3_3398810(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp1_1_3398811(__attribute__((unused)) const tno_dynamics_outTRp1_1_3398811_t& outTRp1_1_3398811, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp1_1_3398811" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp1_1_3398811(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp1_9_3398815(__attribute__((unused)) const tno_dynamics_outTRp1_9_3398815_t& outTRp1_9_3398815, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp1_9_3398815" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp1_9_3398815(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp5_4_3398816(__attribute__((unused)) const tno_dynamics_outTRp5_4_3398816_t& outTRp5_4_3398816, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp5_4_3398816" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp5_4_3398816(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp5_4_3398817(__attribute__((unused)) const tno_dynamics_outTRp5_4_3398817_t& outTRp5_4_3398817, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp5_4_3398817" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp5_4_3398817(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp1_25_3398820(__attribute__((unused)) const tno_dynamics_outTRp1_25_3398820_t& outTRp1_25_3398820, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp1_25_3398820" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp1_25_3398820(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp2_10_3398821(__attribute__((unused)) const tno_dynamics_outTRp2_10_3398821_t& outTRp2_10_3398821, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp2_10_3398821" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp2_10_3398821(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp1_26_3398822(__attribute__((unused)) const tno_dynamics_outTRp1_26_3398822_t& outTRp1_26_3398822, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp1_26_3398822" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp1_26_3398822(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp11_1_3398824(__attribute__((unused)) const tno_dynamics_outTRp11_1_3398824_t& outTRp11_1_3398824, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp11_1_3398824" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp11_1_3398824(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp9_1_3398829(__attribute__((unused)) const tno_dynamics_outTRp9_1_3398829_t& outTRp9_1_3398829, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp9_1_3398829" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp9_1_3398829(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp3_2_3398830(__attribute__((unused)) const tno_dynamics_outTRp3_2_3398830_t& outTRp3_2_3398830, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp3_2_3398830" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp3_2_3398830(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp9_5_3398831(__attribute__((unused)) const tno_dynamics_outTRp9_5_3398831_t& outTRp9_5_3398831, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp9_5_3398831" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp9_5_3398831(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp1_21_3398832(__attribute__((unused)) const tno_dynamics_outTRp1_21_3398832_t& outTRp1_21_3398832, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp1_21_3398832" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp1_21_3398832(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp3_29_3398835(__attribute__((unused)) const tno_dynamics_outTRp3_29_3398835_t& outTRp3_29_3398835, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp3_29_3398835" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp3_29_3398835(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp3_21_3398836(__attribute__((unused)) const tno_dynamics_outTRp3_21_3398836_t& outTRp3_21_3398836, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp3_21_3398836" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp3_21_3398836(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp1_20_3398837(__attribute__((unused)) const tno_dynamics_outTRp1_20_3398837_t& outTRp1_20_3398837, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp1_20_3398837" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp1_20_3398837(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp4_2_3398839(__attribute__((unused)) const tno_dynamics_outTRp4_2_3398839_t& outTRp4_2_3398839, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp4_2_3398839" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp4_2_3398839(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp3_8_3398840(__attribute__((unused)) const tno_dynamics_outTRp3_8_3398840_t& outTRp3_8_3398840, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp3_8_3398840" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp3_8_3398840(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp1_5_3398844(__attribute__((unused)) const tno_dynamics_outTRp1_5_3398844_t& outTRp1_5_3398844, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp1_5_3398844" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp1_5_3398844(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp1_12_3398846(__attribute__((unused)) const tno_dynamics_outTRp1_12_3398846_t& outTRp1_12_3398846, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp1_12_3398846" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp1_12_3398846(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp2_9_3398848(__attribute__((unused)) const tno_dynamics_outTRp2_9_3398848_t& outTRp2_9_3398848, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp2_9_3398848" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp2_9_3398848(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp2_7_3398851(__attribute__((unused)) const tno_dynamics_outTRp2_7_3398851_t& outTRp2_7_3398851, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp2_7_3398851" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp2_7_3398851(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp3_13_3398852(__attribute__((unused)) const tno_dynamics_outTRp3_13_3398852_t& outTRp3_13_3398852, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp3_13_3398852" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp3_13_3398852(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp3_40_3398853(__attribute__((unused)) const tno_dynamics_outTRp3_40_3398853_t& outTRp3_40_3398853, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp3_40_3398853" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp3_40_3398853(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp3_40_3398855(__attribute__((unused)) const tno_dynamics_outTRp3_40_3398855_t& outTRp3_40_3398855, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp3_40_3398855" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp3_40_3398855(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp3_6_3398857(__attribute__((unused)) const tno_dynamics_outTRp3_6_3398857_t& outTRp3_6_3398857, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp3_6_3398857" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp3_6_3398857(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp17_1_3398863(__attribute__((unused)) const tno_dynamics_outTRp17_1_3398863_t& outTRp17_1_3398863, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp17_1_3398863" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp17_1_3398863(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp1_3_3398866(__attribute__((unused)) const tno_dynamics_outTRp1_3_3398866_t& outTRp1_3_3398866, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp1_3_3398866" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp1_3_3398866(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp3_10_3398867(__attribute__((unused)) const tno_dynamics_outTRp3_10_3398867_t& outTRp3_10_3398867, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp3_10_3398867" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp3_10_3398867(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp4_3_3398869(__attribute__((unused)) const tno_dynamics_outTRp4_3_3398869_t& outTRp4_3_3398869, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp4_3_3398869" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp4_3_3398869(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp9_1_3398870(__attribute__((unused)) const tno_dynamics_outTRp9_1_3398870_t& outTRp9_1_3398870, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp9_1_3398870" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp9_1_3398870(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp4_2_3398873(__attribute__((unused)) const tno_dynamics_outTRp4_2_3398873_t& outTRp4_2_3398873, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp4_2_3398873" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp4_2_3398873(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp2_1_3398874(__attribute__((unused)) const tno_dynamics_outTRp2_1_3398874_t& outTRp2_1_3398874, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp2_1_3398874" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp2_1_3398874(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp19_1_3398877(__attribute__((unused)) const tno_dynamics_outTRp19_1_3398877_t& outTRp19_1_3398877, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp19_1_3398877" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp19_1_3398877(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp1_10_3398879(__attribute__((unused)) const tno_dynamics_outTRp1_10_3398879_t& outTRp1_10_3398879, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp1_10_3398879" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp1_10_3398879(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp3_52_3398880(__attribute__((unused)) const tno_dynamics_outTRp3_52_3398880_t& outTRp3_52_3398880, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp3_52_3398880" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp3_52_3398880(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp3_52_3398881(__attribute__((unused)) const tno_dynamics_outTRp3_52_3398881_t& outTRp3_52_3398881, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp3_52_3398881" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp3_52_3398881(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp3_41_3398883(__attribute__((unused)) const tno_dynamics_outTRp3_41_3398883_t& outTRp3_41_3398883, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp3_41_3398883" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp3_41_3398883(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp3_36_3398884(__attribute__((unused)) const tno_dynamics_outTRp3_36_3398884_t& outTRp3_36_3398884, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp3_36_3398884" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp3_36_3398884(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp3_34_3398885(__attribute__((unused)) const tno_dynamics_outTRp3_34_3398885_t& outTRp3_34_3398885, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp3_34_3398885" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp3_34_3398885(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp3_31_3398886(__attribute__((unused)) const tno_dynamics_outTRp3_31_3398886_t& outTRp3_31_3398886, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp3_31_3398886" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp3_31_3398886(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp3_29_3398887(__attribute__((unused)) const tno_dynamics_outTRp3_29_3398887_t& outTRp3_29_3398887, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp3_29_3398887" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp3_29_3398887(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp3_18_3398888(__attribute__((unused)) const tno_dynamics_outTRp3_18_3398888_t& outTRp3_18_3398888, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp3_18_3398888" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp3_18_3398888(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp3_60_3398889(__attribute__((unused)) const tno_dynamics_outTRp3_60_3398889_t& outTRp3_60_3398889, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp3_60_3398889" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp3_60_3398889(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp3_62_3398890(__attribute__((unused)) const tno_dynamics_outTRp3_62_3398890_t& outTRp3_62_3398890, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp3_62_3398890" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp3_62_3398890(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp3_60_3398891(__attribute__((unused)) const tno_dynamics_outTRp3_60_3398891_t& outTRp3_60_3398891, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp3_60_3398891" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp3_60_3398891(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp3_62_3398892(__attribute__((unused)) const tno_dynamics_outTRp3_62_3398892_t& outTRp3_62_3398892, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp3_62_3398892" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp3_62_3398892(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp3_62_3398893(__attribute__((unused)) const tno_dynamics_outTRp3_62_3398893_t& outTRp3_62_3398893, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp3_62_3398893" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp3_62_3398893(  );

    return OK;
}
int V2__1_0__Client::status_receiveOutTRp3_61_3398894(__attribute__((unused)) const tno_dynamics_outTRp3_61_3398894_t& outTRp3_61_3398894, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {

    std::cout << std::endl << "######## V2__1_0__ClientReceived outTRp3_61_3398894" << std::endl;

    clientStubLifeCycleManager.getSmc()->client_api_handler->getNIHandler().outTRp3_61_3398894(  );

    return OK;
}



