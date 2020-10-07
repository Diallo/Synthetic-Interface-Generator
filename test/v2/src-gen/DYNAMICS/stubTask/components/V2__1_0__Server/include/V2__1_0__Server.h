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
    int commands_receiveInTRp2_1_3398721( const tno_dynamics_inTRp2_1_3398721_t& inTRp2_1_3398721, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp3_1_3398722( const tno_dynamics_inTRp3_1_3398722_t& inTRp3_1_3398722, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp1_1_3398723( const tno_dynamics_inTRp1_1_3398723_t& inTRp1_1_3398723, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp3_2_3398726( const tno_dynamics_inTRp3_2_3398726_t& inTRp3_2_3398726, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp2_1_3398728( const tno_dynamics_inTRp2_1_3398728_t& inTRp2_1_3398728, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp3_4_3398729( const tno_dynamics_inTRp3_4_3398729_t& inTRp3_4_3398729, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp2_1_3398732( const tno_dynamics_inTRp2_1_3398732_t& inTRp2_1_3398732, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp3_5_3398734( const tno_dynamics_inTRp3_5_3398734_t& inTRp3_5_3398734, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp3_4_3398737( const tno_dynamics_inTRp3_4_3398737_t& inTRp3_4_3398737, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp2_2_3398739( const tno_dynamics_inTRp2_2_3398739_t& inTRp2_2_3398739, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp3_10_3398741( const tno_dynamics_inTRp3_10_3398741_t& inTRp3_10_3398741, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp1_2_3398742( const tno_dynamics_inTRp1_2_3398742_t& inTRp1_2_3398742, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp1_2_3398743( const tno_dynamics_inTRp1_2_3398743_t& inTRp1_2_3398743, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp1_4_3398746( const tno_dynamics_inTRp1_4_3398746_t& inTRp1_4_3398746, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp3_9_3398747( const tno_dynamics_inTRp3_9_3398747_t& inTRp3_9_3398747, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp3_5_3398749( const tno_dynamics_inTRp3_5_3398749_t& inTRp3_5_3398749, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp3_4_3398750( const tno_dynamics_inTRp3_4_3398750_t& inTRp3_4_3398750, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp3_9_3398751( const tno_dynamics_inTRp3_9_3398751_t& inTRp3_9_3398751, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp3_8_3398752( const tno_dynamics_inTRp3_8_3398752_t& inTRp3_8_3398752, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp2_1_3398753( const tno_dynamics_inTRp2_1_3398753_t& inTRp2_1_3398753, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp2_3_3398754( const tno_dynamics_inTRp2_3_3398754_t& inTRp2_3_3398754, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp1_5_3398755( const tno_dynamics_inTRp1_5_3398755_t& inTRp1_5_3398755, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp2_1_3398757( const tno_dynamics_inTRp2_1_3398757_t& inTRp2_1_3398757, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp1_3_3398758( const tno_dynamics_inTRp1_3_3398758_t& inTRp1_3_3398758, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp3_5_3398760( const tno_dynamics_inTRp3_5_3398760_t& inTRp3_5_3398760, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp3_12_3398765( const tno_dynamics_inTRp3_12_3398765_t& inTRp3_12_3398765, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp1_8_3398767( const tno_dynamics_inTRp1_8_3398767_t& inTRp1_8_3398767, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp3_9_3398768( const tno_dynamics_inTRp3_9_3398768_t& inTRp3_9_3398768, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp3_11_3398770( const tno_dynamics_inTRp3_11_3398770_t& inTRp3_11_3398770, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp2_4_3398772( const tno_dynamics_inTRp2_4_3398772_t& inTRp2_4_3398772, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp3_26_3398774( const tno_dynamics_inTRp3_26_3398774_t& inTRp3_26_3398774, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp5_1_3398776( const tno_dynamics_inTRp5_1_3398776_t& inTRp5_1_3398776, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp3_8_3398780( const tno_dynamics_inTRp3_8_3398780_t& inTRp3_8_3398780, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp2_3_3398781( const tno_dynamics_inTRp2_3_3398781_t& inTRp2_3_3398781, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp1_2_3398783( const tno_dynamics_inTRp1_2_3398783_t& inTRp1_2_3398783, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp1_14_3398785( const tno_dynamics_inTRp1_14_3398785_t& inTRp1_14_3398785, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp3_12_3398786( const tno_dynamics_inTRp3_12_3398786_t& inTRp3_12_3398786, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp3_12_3398787( const tno_dynamics_inTRp3_12_3398787_t& inTRp3_12_3398787, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp1_16_3398790( const tno_dynamics_inTRp1_16_3398790_t& inTRp1_16_3398790, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp3_13_3398792( const tno_dynamics_inTRp3_13_3398792_t& inTRp3_13_3398792, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp10_1_3398795( const tno_dynamics_inTRp10_1_3398795_t& inTRp10_1_3398795, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp11_1_3398796( const tno_dynamics_inTRp11_1_3398796_t& inTRp11_1_3398796, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp3_18_3398798( const tno_dynamics_inTRp3_18_3398798_t& inTRp3_18_3398798, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp9_1_3398800( const tno_dynamics_inTRp9_1_3398800_t& inTRp9_1_3398800, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp3_14_3398803( const tno_dynamics_inTRp3_14_3398803_t& inTRp3_14_3398803, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp10_1_3398805( const tno_dynamics_inTRp10_1_3398805_t& inTRp10_1_3398805, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp5_3_3398807( const tno_dynamics_inTRp5_3_3398807_t& inTRp5_3_3398807, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp1_9_3398808( const tno_dynamics_inTRp1_9_3398808_t& inTRp1_9_3398808, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp1_2_3398812( const tno_dynamics_inTRp1_2_3398812_t& inTRp1_2_3398812, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp3_10_3398813( const tno_dynamics_inTRp3_10_3398813_t& inTRp3_10_3398813, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp3_17_3398814( const tno_dynamics_inTRp3_17_3398814_t& inTRp3_17_3398814, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp12_1_3398818( const tno_dynamics_inTRp12_1_3398818_t& inTRp12_1_3398818, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp13_1_3398819( const tno_dynamics_inTRp13_1_3398819_t& inTRp13_1_3398819, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp1_27_3398823( const tno_dynamics_inTRp1_27_3398823_t& inTRp1_27_3398823, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp1_5_3398825( const tno_dynamics_inTRp1_5_3398825_t& inTRp1_5_3398825, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp2_5_3398826( const tno_dynamics_inTRp2_5_3398826_t& inTRp2_5_3398826, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp3_15_3398827( const tno_dynamics_inTRp3_15_3398827_t& inTRp3_15_3398827, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp1_31_3398828( const tno_dynamics_inTRp1_31_3398828_t& inTRp1_31_3398828, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp1_14_3398833( const tno_dynamics_inTRp1_14_3398833_t& inTRp1_14_3398833, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp1_32_3398834( const tno_dynamics_inTRp1_32_3398834_t& inTRp1_32_3398834, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp4_1_3398838( const tno_dynamics_inTRp4_1_3398838_t& inTRp4_1_3398838, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp14_1_3398841( const tno_dynamics_inTRp14_1_3398841_t& inTRp14_1_3398841, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp3_3_3398842( const tno_dynamics_inTRp3_3_3398842_t& inTRp3_3_3398842, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp2_8_3398847( const tno_dynamics_inTRp2_8_3398847_t& inTRp2_8_3398847, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp1_10_3398849( const tno_dynamics_inTRp1_10_3398849_t& inTRp1_10_3398849, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp2_6_3398850( const tno_dynamics_inTRp2_6_3398850_t& inTRp2_6_3398850, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp15_1_3398854( const tno_dynamics_inTRp15_1_3398854_t& inTRp15_1_3398854, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp16_1_3398856( const tno_dynamics_inTRp16_1_3398856_t& inTRp16_1_3398856, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp17_1_3398858( const tno_dynamics_inTRp17_1_3398858_t& inTRp17_1_3398858, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp1_15_3398859( const tno_dynamics_inTRp1_15_3398859_t& inTRp1_15_3398859, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp3_34_3398860( const tno_dynamics_inTRp3_34_3398860_t& inTRp3_34_3398860, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp1_24_3398861( const tno_dynamics_inTRp1_24_3398861_t& inTRp1_24_3398861, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp1_7_3398862( const tno_dynamics_inTRp1_7_3398862_t& inTRp1_7_3398862, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp17_2_3398864( const tno_dynamics_inTRp17_2_3398864_t& inTRp17_2_3398864, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp3_27_3398865( const tno_dynamics_inTRp3_27_3398865_t& inTRp3_27_3398865, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp4_2_3398868( const tno_dynamics_inTRp4_2_3398868_t& inTRp4_2_3398868, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp18_1_3398871( const tno_dynamics_inTRp18_1_3398871_t& inTRp18_1_3398871, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp3_22_3398872( const tno_dynamics_inTRp3_22_3398872_t& inTRp3_22_3398872, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp2_2_3398875( const tno_dynamics_inTRp2_2_3398875_t& inTRp2_2_3398875, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp4_1_3398876( const tno_dynamics_inTRp4_1_3398876_t& inTRp4_1_3398876, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
    int commands_receiveInTRp3_28_3398878( const tno_dynamics_inTRp3_28_3398878_t& inTRp3_28_3398878, pubsub::ISubscriberCallbacks& callbacks ) noexcept override;
private:
    EventAPI eventApi;
    NotificationEventHandler notificationEventHandler;
};

#endif //V2__1_0__SERVER_H
