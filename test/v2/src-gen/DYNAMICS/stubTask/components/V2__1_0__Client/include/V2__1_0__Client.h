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
    int status_receiveOutTRp1_1_3398718( const tno_dynamics_outTRp1_1_3398718_t& outTRp1_1_3398718, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp1_1_3398719( const tno_dynamics_outTRp1_1_3398719_t& outTRp1_1_3398719, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp1_1_3398720( const tno_dynamics_outTRp1_1_3398720_t& outTRp1_1_3398720, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp3_1_3398724( const tno_dynamics_outTRp3_1_3398724_t& outTRp3_1_3398724, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp1_4_3398725( const tno_dynamics_outTRp1_4_3398725_t& outTRp1_4_3398725, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp3_3_3398727( const tno_dynamics_outTRp3_3_3398727_t& outTRp3_3_3398727, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp3_4_3398731( const tno_dynamics_outTRp3_4_3398731_t& outTRp3_4_3398731, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp3_5_3398733( const tno_dynamics_outTRp3_5_3398733_t& outTRp3_5_3398733, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp3_2_3398735( const tno_dynamics_outTRp3_2_3398735_t& outTRp3_2_3398735, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp3_3_3398736( const tno_dynamics_outTRp3_3_3398736_t& outTRp3_3_3398736, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp1_1_3398738( const tno_dynamics_outTRp1_1_3398738_t& outTRp1_1_3398738, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp2_3_3398740( const tno_dynamics_outTRp2_3_3398740_t& outTRp2_3_3398740, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp4_1_3398744( const tno_dynamics_outTRp4_1_3398744_t& outTRp4_1_3398744, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp5_1_3398745( const tno_dynamics_outTRp5_1_3398745_t& outTRp5_1_3398745, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp3_10_3398748( const tno_dynamics_outTRp3_10_3398748_t& outTRp3_10_3398748, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp1_6_3398756( const tno_dynamics_outTRp1_6_3398756_t& outTRp1_6_3398756, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp1_4_3398759( const tno_dynamics_outTRp1_4_3398759_t& outTRp1_4_3398759, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp3_6_3398761( const tno_dynamics_outTRp3_6_3398761_t& outTRp3_6_3398761, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp2_6_3398762( const tno_dynamics_outTRp2_6_3398762_t& outTRp2_6_3398762, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp3_4_3398763( const tno_dynamics_outTRp3_4_3398763_t& outTRp3_4_3398763, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp3_11_3398764( const tno_dynamics_outTRp3_11_3398764_t& outTRp3_11_3398764, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp3_8_3398766( const tno_dynamics_outTRp3_8_3398766_t& outTRp3_8_3398766, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp1_10_3398769( const tno_dynamics_outTRp1_10_3398769_t& outTRp1_10_3398769, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp3_12_3398771( const tno_dynamics_outTRp3_12_3398771_t& outTRp3_12_3398771, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp6_1_3398773( const tno_dynamics_outTRp6_1_3398773_t& outTRp6_1_3398773, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp7_1_3398775( const tno_dynamics_outTRp7_1_3398775_t& outTRp7_1_3398775, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp5_2_3398777( const tno_dynamics_outTRp5_2_3398777_t& outTRp5_2_3398777, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp1_6_3398778( const tno_dynamics_outTRp1_6_3398778_t& outTRp1_6_3398778, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp1_14_3398782( const tno_dynamics_outTRp1_14_3398782_t& outTRp1_14_3398782, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp1_3_3398784( const tno_dynamics_outTRp1_3_3398784_t& outTRp1_3_3398784, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp8_1_3398788( const tno_dynamics_outTRp8_1_3398788_t& outTRp8_1_3398788, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp9_1_3398789( const tno_dynamics_outTRp9_1_3398789_t& outTRp9_1_3398789, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp1_17_3398791( const tno_dynamics_outTRp1_17_3398791_t& outTRp1_17_3398791, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp1_7_3398793( const tno_dynamics_outTRp1_7_3398793_t& outTRp1_7_3398793, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp1_7_3398794( const tno_dynamics_outTRp1_7_3398794_t& outTRp1_7_3398794, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp1_4_3398797( const tno_dynamics_outTRp1_4_3398797_t& outTRp1_4_3398797, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp3_29_3398799( const tno_dynamics_outTRp3_29_3398799_t& outTRp3_29_3398799, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp9_2_3398801( const tno_dynamics_outTRp9_2_3398801_t& outTRp9_2_3398801, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp3_13_3398802( const tno_dynamics_outTRp3_13_3398802_t& outTRp3_13_3398802, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp1_7_3398804( const tno_dynamics_outTRp1_7_3398804_t& outTRp1_7_3398804, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp3_32_3398806( const tno_dynamics_outTRp3_32_3398806_t& outTRp3_32_3398806, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp1_20_3398809( const tno_dynamics_outTRp1_20_3398809_t& outTRp1_20_3398809, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp9_3_3398810( const tno_dynamics_outTRp9_3_3398810_t& outTRp9_3_3398810, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp1_1_3398811( const tno_dynamics_outTRp1_1_3398811_t& outTRp1_1_3398811, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp1_9_3398815( const tno_dynamics_outTRp1_9_3398815_t& outTRp1_9_3398815, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp5_4_3398816( const tno_dynamics_outTRp5_4_3398816_t& outTRp5_4_3398816, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp5_4_3398817( const tno_dynamics_outTRp5_4_3398817_t& outTRp5_4_3398817, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp1_25_3398820( const tno_dynamics_outTRp1_25_3398820_t& outTRp1_25_3398820, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp2_10_3398821( const tno_dynamics_outTRp2_10_3398821_t& outTRp2_10_3398821, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp1_26_3398822( const tno_dynamics_outTRp1_26_3398822_t& outTRp1_26_3398822, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp11_1_3398824( const tno_dynamics_outTRp11_1_3398824_t& outTRp11_1_3398824, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp9_1_3398829( const tno_dynamics_outTRp9_1_3398829_t& outTRp9_1_3398829, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp3_2_3398830( const tno_dynamics_outTRp3_2_3398830_t& outTRp3_2_3398830, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp9_5_3398831( const tno_dynamics_outTRp9_5_3398831_t& outTRp9_5_3398831, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp1_21_3398832( const tno_dynamics_outTRp1_21_3398832_t& outTRp1_21_3398832, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp3_29_3398835( const tno_dynamics_outTRp3_29_3398835_t& outTRp3_29_3398835, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp3_21_3398836( const tno_dynamics_outTRp3_21_3398836_t& outTRp3_21_3398836, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp1_20_3398837( const tno_dynamics_outTRp1_20_3398837_t& outTRp1_20_3398837, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp4_2_3398839( const tno_dynamics_outTRp4_2_3398839_t& outTRp4_2_3398839, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp3_8_3398840( const tno_dynamics_outTRp3_8_3398840_t& outTRp3_8_3398840, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp1_5_3398844( const tno_dynamics_outTRp1_5_3398844_t& outTRp1_5_3398844, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp1_12_3398846( const tno_dynamics_outTRp1_12_3398846_t& outTRp1_12_3398846, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp2_9_3398848( const tno_dynamics_outTRp2_9_3398848_t& outTRp2_9_3398848, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp2_7_3398851( const tno_dynamics_outTRp2_7_3398851_t& outTRp2_7_3398851, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp3_13_3398852( const tno_dynamics_outTRp3_13_3398852_t& outTRp3_13_3398852, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp3_40_3398853( const tno_dynamics_outTRp3_40_3398853_t& outTRp3_40_3398853, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp3_40_3398855( const tno_dynamics_outTRp3_40_3398855_t& outTRp3_40_3398855, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp3_6_3398857( const tno_dynamics_outTRp3_6_3398857_t& outTRp3_6_3398857, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp17_1_3398863( const tno_dynamics_outTRp17_1_3398863_t& outTRp17_1_3398863, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp1_3_3398866( const tno_dynamics_outTRp1_3_3398866_t& outTRp1_3_3398866, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp3_10_3398867( const tno_dynamics_outTRp3_10_3398867_t& outTRp3_10_3398867, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp4_3_3398869( const tno_dynamics_outTRp4_3_3398869_t& outTRp4_3_3398869, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp9_1_3398870( const tno_dynamics_outTRp9_1_3398870_t& outTRp9_1_3398870, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp4_2_3398873( const tno_dynamics_outTRp4_2_3398873_t& outTRp4_2_3398873, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp2_1_3398874( const tno_dynamics_outTRp2_1_3398874_t& outTRp2_1_3398874, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp19_1_3398877( const tno_dynamics_outTRp19_1_3398877_t& outTRp19_1_3398877, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp1_10_3398879( const tno_dynamics_outTRp1_10_3398879_t& outTRp1_10_3398879, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp3_52_3398880( const tno_dynamics_outTRp3_52_3398880_t& outTRp3_52_3398880, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp3_52_3398881( const tno_dynamics_outTRp3_52_3398881_t& outTRp3_52_3398881, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp3_41_3398883( const tno_dynamics_outTRp3_41_3398883_t& outTRp3_41_3398883, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp3_36_3398884( const tno_dynamics_outTRp3_36_3398884_t& outTRp3_36_3398884, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp3_34_3398885( const tno_dynamics_outTRp3_34_3398885_t& outTRp3_34_3398885, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp3_31_3398886( const tno_dynamics_outTRp3_31_3398886_t& outTRp3_31_3398886, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp3_29_3398887( const tno_dynamics_outTRp3_29_3398887_t& outTRp3_29_3398887, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp3_18_3398888( const tno_dynamics_outTRp3_18_3398888_t& outTRp3_18_3398888, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp3_60_3398889( const tno_dynamics_outTRp3_60_3398889_t& outTRp3_60_3398889, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp3_62_3398890( const tno_dynamics_outTRp3_62_3398890_t& outTRp3_62_3398890, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp3_60_3398891( const tno_dynamics_outTRp3_60_3398891_t& outTRp3_60_3398891, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp3_62_3398892( const tno_dynamics_outTRp3_62_3398892_t& outTRp3_62_3398892, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp3_62_3398893( const tno_dynamics_outTRp3_62_3398893_t& outTRp3_62_3398893, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int status_receiveOutTRp3_61_3398894( const tno_dynamics_outTRp3_61_3398894_t& outTRp3_61_3398894, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;

private:
    ClientStubLifeCycleManager clientStubLifeCycleManager;
};

extern V2__1_0__Client* getV2__1_0__Client();

#endif //V2__1_0__CLIENT_H
