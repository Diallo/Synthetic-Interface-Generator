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

void outTRp1_1_3398718Callback(  ) {
    tno_dynamics_outTRp1_1_3398718_t outTRp1_1_3398718{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp1_1_3398718" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp1_1_3398718( outTRp1_1_3398718 );
}

void outTRp1_1_3398719Callback(  ) {
    tno_dynamics_outTRp1_1_3398719_t outTRp1_1_3398719{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp1_1_3398719" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp1_1_3398719( outTRp1_1_3398719 );
}

void outTRp1_1_3398720Callback(  ) {
    tno_dynamics_outTRp1_1_3398720_t outTRp1_1_3398720{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp1_1_3398720" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp1_1_3398720( outTRp1_1_3398720 );
}

void outTRp3_1_3398724Callback(  ) {
    tno_dynamics_outTRp3_1_3398724_t outTRp3_1_3398724{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp3_1_3398724" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp3_1_3398724( outTRp3_1_3398724 );
}

void outTRp1_4_3398725Callback(  ) {
    tno_dynamics_outTRp1_4_3398725_t outTRp1_4_3398725{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp1_4_3398725" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp1_4_3398725( outTRp1_4_3398725 );
}

void outTRp3_3_3398727Callback(  ) {
    tno_dynamics_outTRp3_3_3398727_t outTRp3_3_3398727{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp3_3_3398727" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp3_3_3398727( outTRp3_3_3398727 );
}

void outTRp3_4_3398731Callback(  ) {
    tno_dynamics_outTRp3_4_3398731_t outTRp3_4_3398731{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp3_4_3398731" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp3_4_3398731( outTRp3_4_3398731 );
}

void outTRp3_5_3398733Callback(  ) {
    tno_dynamics_outTRp3_5_3398733_t outTRp3_5_3398733{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp3_5_3398733" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp3_5_3398733( outTRp3_5_3398733 );
}

void outTRp3_2_3398735Callback(  ) {
    tno_dynamics_outTRp3_2_3398735_t outTRp3_2_3398735{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp3_2_3398735" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp3_2_3398735( outTRp3_2_3398735 );
}

void outTRp3_3_3398736Callback(  ) {
    tno_dynamics_outTRp3_3_3398736_t outTRp3_3_3398736{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp3_3_3398736" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp3_3_3398736( outTRp3_3_3398736 );
}

void outTRp1_1_3398738Callback(  ) {
    tno_dynamics_outTRp1_1_3398738_t outTRp1_1_3398738{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp1_1_3398738" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp1_1_3398738( outTRp1_1_3398738 );
}

void outTRp2_3_3398740Callback(  ) {
    tno_dynamics_outTRp2_3_3398740_t outTRp2_3_3398740{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp2_3_3398740" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp2_3_3398740( outTRp2_3_3398740 );
}

void outTRp4_1_3398744Callback(  ) {
    tno_dynamics_outTRp4_1_3398744_t outTRp4_1_3398744{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp4_1_3398744" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp4_1_3398744( outTRp4_1_3398744 );
}

void outTRp5_1_3398745Callback(  ) {
    tno_dynamics_outTRp5_1_3398745_t outTRp5_1_3398745{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp5_1_3398745" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp5_1_3398745( outTRp5_1_3398745 );
}

void outTRp3_10_3398748Callback(  ) {
    tno_dynamics_outTRp3_10_3398748_t outTRp3_10_3398748{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp3_10_3398748" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp3_10_3398748( outTRp3_10_3398748 );
}

void outTRp1_6_3398756Callback(  ) {
    tno_dynamics_outTRp1_6_3398756_t outTRp1_6_3398756{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp1_6_3398756" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp1_6_3398756( outTRp1_6_3398756 );
}

void outTRp1_4_3398759Callback(  ) {
    tno_dynamics_outTRp1_4_3398759_t outTRp1_4_3398759{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp1_4_3398759" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp1_4_3398759( outTRp1_4_3398759 );
}

void outTRp3_6_3398761Callback(  ) {
    tno_dynamics_outTRp3_6_3398761_t outTRp3_6_3398761{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp3_6_3398761" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp3_6_3398761( outTRp3_6_3398761 );
}

void outTRp2_6_3398762Callback(  ) {
    tno_dynamics_outTRp2_6_3398762_t outTRp2_6_3398762{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp2_6_3398762" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp2_6_3398762( outTRp2_6_3398762 );
}

void outTRp3_4_3398763Callback(  ) {
    tno_dynamics_outTRp3_4_3398763_t outTRp3_4_3398763{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp3_4_3398763" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp3_4_3398763( outTRp3_4_3398763 );
}

void outTRp3_11_3398764Callback(  ) {
    tno_dynamics_outTRp3_11_3398764_t outTRp3_11_3398764{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp3_11_3398764" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp3_11_3398764( outTRp3_11_3398764 );
}

void outTRp3_8_3398766Callback(  ) {
    tno_dynamics_outTRp3_8_3398766_t outTRp3_8_3398766{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp3_8_3398766" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp3_8_3398766( outTRp3_8_3398766 );
}

void outTRp1_10_3398769Callback(  ) {
    tno_dynamics_outTRp1_10_3398769_t outTRp1_10_3398769{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp1_10_3398769" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp1_10_3398769( outTRp1_10_3398769 );
}

void outTRp3_12_3398771Callback(  ) {
    tno_dynamics_outTRp3_12_3398771_t outTRp3_12_3398771{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp3_12_3398771" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp3_12_3398771( outTRp3_12_3398771 );
}

void outTRp6_1_3398773Callback(  ) {
    tno_dynamics_outTRp6_1_3398773_t outTRp6_1_3398773{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp6_1_3398773" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp6_1_3398773( outTRp6_1_3398773 );
}

void outTRp7_1_3398775Callback(  ) {
    tno_dynamics_outTRp7_1_3398775_t outTRp7_1_3398775{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp7_1_3398775" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp7_1_3398775( outTRp7_1_3398775 );
}

void outTRp5_2_3398777Callback(  ) {
    tno_dynamics_outTRp5_2_3398777_t outTRp5_2_3398777{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp5_2_3398777" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp5_2_3398777( outTRp5_2_3398777 );
}

void outTRp1_6_3398778Callback(  ) {
    tno_dynamics_outTRp1_6_3398778_t outTRp1_6_3398778{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp1_6_3398778" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp1_6_3398778( outTRp1_6_3398778 );
}

void outTRp1_14_3398782Callback(  ) {
    tno_dynamics_outTRp1_14_3398782_t outTRp1_14_3398782{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp1_14_3398782" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp1_14_3398782( outTRp1_14_3398782 );
}

void outTRp1_3_3398784Callback(  ) {
    tno_dynamics_outTRp1_3_3398784_t outTRp1_3_3398784{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp1_3_3398784" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp1_3_3398784( outTRp1_3_3398784 );
}

void outTRp8_1_3398788Callback(  ) {
    tno_dynamics_outTRp8_1_3398788_t outTRp8_1_3398788{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp8_1_3398788" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp8_1_3398788( outTRp8_1_3398788 );
}

void outTRp9_1_3398789Callback(  ) {
    tno_dynamics_outTRp9_1_3398789_t outTRp9_1_3398789{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp9_1_3398789" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp9_1_3398789( outTRp9_1_3398789 );
}

void outTRp1_17_3398791Callback(  ) {
    tno_dynamics_outTRp1_17_3398791_t outTRp1_17_3398791{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp1_17_3398791" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp1_17_3398791( outTRp1_17_3398791 );
}

void outTRp1_7_3398793Callback(  ) {
    tno_dynamics_outTRp1_7_3398793_t outTRp1_7_3398793{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp1_7_3398793" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp1_7_3398793( outTRp1_7_3398793 );
}

void outTRp1_7_3398794Callback(  ) {
    tno_dynamics_outTRp1_7_3398794_t outTRp1_7_3398794{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp1_7_3398794" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp1_7_3398794( outTRp1_7_3398794 );
}

void outTRp1_4_3398797Callback(  ) {
    tno_dynamics_outTRp1_4_3398797_t outTRp1_4_3398797{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp1_4_3398797" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp1_4_3398797( outTRp1_4_3398797 );
}

void outTRp3_29_3398799Callback(  ) {
    tno_dynamics_outTRp3_29_3398799_t outTRp3_29_3398799{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp3_29_3398799" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp3_29_3398799( outTRp3_29_3398799 );
}

void outTRp9_2_3398801Callback(  ) {
    tno_dynamics_outTRp9_2_3398801_t outTRp9_2_3398801{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp9_2_3398801" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp9_2_3398801( outTRp9_2_3398801 );
}

void outTRp3_13_3398802Callback(  ) {
    tno_dynamics_outTRp3_13_3398802_t outTRp3_13_3398802{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp3_13_3398802" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp3_13_3398802( outTRp3_13_3398802 );
}

void outTRp1_7_3398804Callback(  ) {
    tno_dynamics_outTRp1_7_3398804_t outTRp1_7_3398804{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp1_7_3398804" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp1_7_3398804( outTRp1_7_3398804 );
}

void outTRp3_32_3398806Callback(  ) {
    tno_dynamics_outTRp3_32_3398806_t outTRp3_32_3398806{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp3_32_3398806" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp3_32_3398806( outTRp3_32_3398806 );
}

void outTRp1_20_3398809Callback(  ) {
    tno_dynamics_outTRp1_20_3398809_t outTRp1_20_3398809{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp1_20_3398809" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp1_20_3398809( outTRp1_20_3398809 );
}

void outTRp9_3_3398810Callback(  ) {
    tno_dynamics_outTRp9_3_3398810_t outTRp9_3_3398810{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp9_3_3398810" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp9_3_3398810( outTRp9_3_3398810 );
}

void outTRp1_1_3398811Callback(  ) {
    tno_dynamics_outTRp1_1_3398811_t outTRp1_1_3398811{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp1_1_3398811" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp1_1_3398811( outTRp1_1_3398811 );
}

void outTRp1_9_3398815Callback(  ) {
    tno_dynamics_outTRp1_9_3398815_t outTRp1_9_3398815{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp1_9_3398815" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp1_9_3398815( outTRp1_9_3398815 );
}

void outTRp5_4_3398816Callback(  ) {
    tno_dynamics_outTRp5_4_3398816_t outTRp5_4_3398816{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp5_4_3398816" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp5_4_3398816( outTRp5_4_3398816 );
}

void outTRp5_4_3398817Callback(  ) {
    tno_dynamics_outTRp5_4_3398817_t outTRp5_4_3398817{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp5_4_3398817" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp5_4_3398817( outTRp5_4_3398817 );
}

void outTRp1_25_3398820Callback(  ) {
    tno_dynamics_outTRp1_25_3398820_t outTRp1_25_3398820{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp1_25_3398820" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp1_25_3398820( outTRp1_25_3398820 );
}

void outTRp2_10_3398821Callback(  ) {
    tno_dynamics_outTRp2_10_3398821_t outTRp2_10_3398821{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp2_10_3398821" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp2_10_3398821( outTRp2_10_3398821 );
}

void outTRp1_26_3398822Callback(  ) {
    tno_dynamics_outTRp1_26_3398822_t outTRp1_26_3398822{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp1_26_3398822" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp1_26_3398822( outTRp1_26_3398822 );
}

void outTRp11_1_3398824Callback(  ) {
    tno_dynamics_outTRp11_1_3398824_t outTRp11_1_3398824{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp11_1_3398824" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp11_1_3398824( outTRp11_1_3398824 );
}

void outTRp9_1_3398829Callback(  ) {
    tno_dynamics_outTRp9_1_3398829_t outTRp9_1_3398829{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp9_1_3398829" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp9_1_3398829( outTRp9_1_3398829 );
}

void outTRp3_2_3398830Callback(  ) {
    tno_dynamics_outTRp3_2_3398830_t outTRp3_2_3398830{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp3_2_3398830" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp3_2_3398830( outTRp3_2_3398830 );
}

void outTRp9_5_3398831Callback(  ) {
    tno_dynamics_outTRp9_5_3398831_t outTRp9_5_3398831{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp9_5_3398831" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp9_5_3398831( outTRp9_5_3398831 );
}

void outTRp1_21_3398832Callback(  ) {
    tno_dynamics_outTRp1_21_3398832_t outTRp1_21_3398832{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp1_21_3398832" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp1_21_3398832( outTRp1_21_3398832 );
}

void outTRp3_29_3398835Callback(  ) {
    tno_dynamics_outTRp3_29_3398835_t outTRp3_29_3398835{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp3_29_3398835" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp3_29_3398835( outTRp3_29_3398835 );
}

void outTRp3_21_3398836Callback(  ) {
    tno_dynamics_outTRp3_21_3398836_t outTRp3_21_3398836{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp3_21_3398836" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp3_21_3398836( outTRp3_21_3398836 );
}

void outTRp1_20_3398837Callback(  ) {
    tno_dynamics_outTRp1_20_3398837_t outTRp1_20_3398837{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp1_20_3398837" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp1_20_3398837( outTRp1_20_3398837 );
}

void outTRp4_2_3398839Callback(  ) {
    tno_dynamics_outTRp4_2_3398839_t outTRp4_2_3398839{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp4_2_3398839" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp4_2_3398839( outTRp4_2_3398839 );
}

void outTRp3_8_3398840Callback(  ) {
    tno_dynamics_outTRp3_8_3398840_t outTRp3_8_3398840{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp3_8_3398840" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp3_8_3398840( outTRp3_8_3398840 );
}

void outTRp1_5_3398844Callback(  ) {
    tno_dynamics_outTRp1_5_3398844_t outTRp1_5_3398844{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp1_5_3398844" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp1_5_3398844( outTRp1_5_3398844 );
}

void outTRp1_12_3398846Callback(  ) {
    tno_dynamics_outTRp1_12_3398846_t outTRp1_12_3398846{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp1_12_3398846" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp1_12_3398846( outTRp1_12_3398846 );
}

void outTRp2_9_3398848Callback(  ) {
    tno_dynamics_outTRp2_9_3398848_t outTRp2_9_3398848{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp2_9_3398848" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp2_9_3398848( outTRp2_9_3398848 );
}

void outTRp2_7_3398851Callback(  ) {
    tno_dynamics_outTRp2_7_3398851_t outTRp2_7_3398851{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp2_7_3398851" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp2_7_3398851( outTRp2_7_3398851 );
}

void outTRp3_13_3398852Callback(  ) {
    tno_dynamics_outTRp3_13_3398852_t outTRp3_13_3398852{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp3_13_3398852" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp3_13_3398852( outTRp3_13_3398852 );
}

void outTRp3_40_3398853Callback(  ) {
    tno_dynamics_outTRp3_40_3398853_t outTRp3_40_3398853{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp3_40_3398853" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp3_40_3398853( outTRp3_40_3398853 );
}

void outTRp3_40_3398855Callback(  ) {
    tno_dynamics_outTRp3_40_3398855_t outTRp3_40_3398855{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp3_40_3398855" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp3_40_3398855( outTRp3_40_3398855 );
}

void outTRp3_6_3398857Callback(  ) {
    tno_dynamics_outTRp3_6_3398857_t outTRp3_6_3398857{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp3_6_3398857" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp3_6_3398857( outTRp3_6_3398857 );
}

void outTRp17_1_3398863Callback(  ) {
    tno_dynamics_outTRp17_1_3398863_t outTRp17_1_3398863{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp17_1_3398863" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp17_1_3398863( outTRp17_1_3398863 );
}

void outTRp1_3_3398866Callback(  ) {
    tno_dynamics_outTRp1_3_3398866_t outTRp1_3_3398866{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp1_3_3398866" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp1_3_3398866( outTRp1_3_3398866 );
}

void outTRp3_10_3398867Callback(  ) {
    tno_dynamics_outTRp3_10_3398867_t outTRp3_10_3398867{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp3_10_3398867" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp3_10_3398867( outTRp3_10_3398867 );
}

void outTRp4_3_3398869Callback(  ) {
    tno_dynamics_outTRp4_3_3398869_t outTRp4_3_3398869{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp4_3_3398869" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp4_3_3398869( outTRp4_3_3398869 );
}

void outTRp9_1_3398870Callback(  ) {
    tno_dynamics_outTRp9_1_3398870_t outTRp9_1_3398870{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp9_1_3398870" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp9_1_3398870( outTRp9_1_3398870 );
}

void outTRp4_2_3398873Callback(  ) {
    tno_dynamics_outTRp4_2_3398873_t outTRp4_2_3398873{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp4_2_3398873" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp4_2_3398873( outTRp4_2_3398873 );
}

void outTRp2_1_3398874Callback(  ) {
    tno_dynamics_outTRp2_1_3398874_t outTRp2_1_3398874{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp2_1_3398874" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp2_1_3398874( outTRp2_1_3398874 );
}

void outTRp19_1_3398877Callback(  ) {
    tno_dynamics_outTRp19_1_3398877_t outTRp19_1_3398877{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp19_1_3398877" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp19_1_3398877( outTRp19_1_3398877 );
}

void outTRp1_10_3398879Callback(  ) {
    tno_dynamics_outTRp1_10_3398879_t outTRp1_10_3398879{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp1_10_3398879" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp1_10_3398879( outTRp1_10_3398879 );
}

void outTRp3_52_3398880Callback(  ) {
    tno_dynamics_outTRp3_52_3398880_t outTRp3_52_3398880{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp3_52_3398880" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp3_52_3398880( outTRp3_52_3398880 );
}

void outTRp3_52_3398881Callback(  ) {
    tno_dynamics_outTRp3_52_3398881_t outTRp3_52_3398881{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp3_52_3398881" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp3_52_3398881( outTRp3_52_3398881 );
}

void outTRp3_41_3398883Callback(  ) {
    tno_dynamics_outTRp3_41_3398883_t outTRp3_41_3398883{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp3_41_3398883" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp3_41_3398883( outTRp3_41_3398883 );
}

void outTRp3_36_3398884Callback(  ) {
    tno_dynamics_outTRp3_36_3398884_t outTRp3_36_3398884{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp3_36_3398884" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp3_36_3398884( outTRp3_36_3398884 );
}

void outTRp3_34_3398885Callback(  ) {
    tno_dynamics_outTRp3_34_3398885_t outTRp3_34_3398885{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp3_34_3398885" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp3_34_3398885( outTRp3_34_3398885 );
}

void outTRp3_31_3398886Callback(  ) {
    tno_dynamics_outTRp3_31_3398886_t outTRp3_31_3398886{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp3_31_3398886" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp3_31_3398886( outTRp3_31_3398886 );
}

void outTRp3_29_3398887Callback(  ) {
    tno_dynamics_outTRp3_29_3398887_t outTRp3_29_3398887{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp3_29_3398887" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp3_29_3398887( outTRp3_29_3398887 );
}

void outTRp3_18_3398888Callback(  ) {
    tno_dynamics_outTRp3_18_3398888_t outTRp3_18_3398888{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp3_18_3398888" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp3_18_3398888( outTRp3_18_3398888 );
}

void outTRp3_60_3398889Callback(  ) {
    tno_dynamics_outTRp3_60_3398889_t outTRp3_60_3398889{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp3_60_3398889" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp3_60_3398889( outTRp3_60_3398889 );
}

void outTRp3_62_3398890Callback(  ) {
    tno_dynamics_outTRp3_62_3398890_t outTRp3_62_3398890{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp3_62_3398890" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp3_62_3398890( outTRp3_62_3398890 );
}

void outTRp3_60_3398891Callback(  ) {
    tno_dynamics_outTRp3_60_3398891_t outTRp3_60_3398891{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp3_60_3398891" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp3_60_3398891( outTRp3_60_3398891 );
}

void outTRp3_62_3398892Callback(  ) {
    tno_dynamics_outTRp3_62_3398892_t outTRp3_62_3398892{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp3_62_3398892" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp3_62_3398892( outTRp3_62_3398892 );
}

void outTRp3_62_3398893Callback(  ) {
    tno_dynamics_outTRp3_62_3398893_t outTRp3_62_3398893{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp3_62_3398893" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp3_62_3398893( outTRp3_62_3398893 );
}

void outTRp3_61_3398894Callback(  ) {
    tno_dynamics_outTRp3_61_3398894_t outTRp3_61_3398894{};

    std::cout << std::endl << "######## O2N V2__1_0__Server_sendOutTRp3_61_3398894" <<std::endl;
    getV2__1_0__Server()->status_sendOutTRp3_61_3398894( outTRp3_61_3398894 );
}


V2__1_0__Server::V2__1_0__Server(): V2__1_0__ServerBase() {}
    
V2__1_0__Server::~V2__1_0__Server() {}

int V2__1_0__Server::init() noexcept {
    //Only invoked during the first activation of the component, called before start
    //Warning parameter update callbacks will be called before and possible after
    //(if a param update happens) init. 
    V2__1_0__ServerBase::init();

    gV2__1_0__Server = this;

	notificationEventHandler.register_outTRp1_1_3398718CB( outTRp1_1_3398718Callback );
	notificationEventHandler.register_outTRp1_1_3398719CB( outTRp1_1_3398719Callback );
	notificationEventHandler.register_outTRp1_1_3398720CB( outTRp1_1_3398720Callback );
	notificationEventHandler.register_outTRp3_1_3398724CB( outTRp3_1_3398724Callback );
	notificationEventHandler.register_outTRp1_4_3398725CB( outTRp1_4_3398725Callback );
	notificationEventHandler.register_outTRp3_3_3398727CB( outTRp3_3_3398727Callback );
	notificationEventHandler.register_outTRp3_4_3398731CB( outTRp3_4_3398731Callback );
	notificationEventHandler.register_outTRp3_5_3398733CB( outTRp3_5_3398733Callback );
	notificationEventHandler.register_outTRp3_2_3398735CB( outTRp3_2_3398735Callback );
	notificationEventHandler.register_outTRp3_3_3398736CB( outTRp3_3_3398736Callback );
	notificationEventHandler.register_outTRp1_1_3398738CB( outTRp1_1_3398738Callback );
	notificationEventHandler.register_outTRp2_3_3398740CB( outTRp2_3_3398740Callback );
	notificationEventHandler.register_outTRp4_1_3398744CB( outTRp4_1_3398744Callback );
	notificationEventHandler.register_outTRp5_1_3398745CB( outTRp5_1_3398745Callback );
	notificationEventHandler.register_outTRp3_10_3398748CB( outTRp3_10_3398748Callback );
	notificationEventHandler.register_outTRp1_6_3398756CB( outTRp1_6_3398756Callback );
	notificationEventHandler.register_outTRp1_4_3398759CB( outTRp1_4_3398759Callback );
	notificationEventHandler.register_outTRp3_6_3398761CB( outTRp3_6_3398761Callback );
	notificationEventHandler.register_outTRp2_6_3398762CB( outTRp2_6_3398762Callback );
	notificationEventHandler.register_outTRp3_4_3398763CB( outTRp3_4_3398763Callback );
	notificationEventHandler.register_outTRp3_11_3398764CB( outTRp3_11_3398764Callback );
	notificationEventHandler.register_outTRp3_8_3398766CB( outTRp3_8_3398766Callback );
	notificationEventHandler.register_outTRp1_10_3398769CB( outTRp1_10_3398769Callback );
	notificationEventHandler.register_outTRp3_12_3398771CB( outTRp3_12_3398771Callback );
	notificationEventHandler.register_outTRp6_1_3398773CB( outTRp6_1_3398773Callback );
	notificationEventHandler.register_outTRp7_1_3398775CB( outTRp7_1_3398775Callback );
	notificationEventHandler.register_outTRp5_2_3398777CB( outTRp5_2_3398777Callback );
	notificationEventHandler.register_outTRp1_6_3398778CB( outTRp1_6_3398778Callback );
	notificationEventHandler.register_outTRp1_14_3398782CB( outTRp1_14_3398782Callback );
	notificationEventHandler.register_outTRp1_3_3398784CB( outTRp1_3_3398784Callback );
	notificationEventHandler.register_outTRp8_1_3398788CB( outTRp8_1_3398788Callback );
	notificationEventHandler.register_outTRp9_1_3398789CB( outTRp9_1_3398789Callback );
	notificationEventHandler.register_outTRp1_17_3398791CB( outTRp1_17_3398791Callback );
	notificationEventHandler.register_outTRp1_7_3398793CB( outTRp1_7_3398793Callback );
	notificationEventHandler.register_outTRp1_7_3398794CB( outTRp1_7_3398794Callback );
	notificationEventHandler.register_outTRp1_4_3398797CB( outTRp1_4_3398797Callback );
	notificationEventHandler.register_outTRp3_29_3398799CB( outTRp3_29_3398799Callback );
	notificationEventHandler.register_outTRp9_2_3398801CB( outTRp9_2_3398801Callback );
	notificationEventHandler.register_outTRp3_13_3398802CB( outTRp3_13_3398802Callback );
	notificationEventHandler.register_outTRp1_7_3398804CB( outTRp1_7_3398804Callback );
	notificationEventHandler.register_outTRp3_32_3398806CB( outTRp3_32_3398806Callback );
	notificationEventHandler.register_outTRp1_20_3398809CB( outTRp1_20_3398809Callback );
	notificationEventHandler.register_outTRp9_3_3398810CB( outTRp9_3_3398810Callback );
	notificationEventHandler.register_outTRp1_1_3398811CB( outTRp1_1_3398811Callback );
	notificationEventHandler.register_outTRp1_9_3398815CB( outTRp1_9_3398815Callback );
	notificationEventHandler.register_outTRp5_4_3398816CB( outTRp5_4_3398816Callback );
	notificationEventHandler.register_outTRp5_4_3398817CB( outTRp5_4_3398817Callback );
	notificationEventHandler.register_outTRp1_25_3398820CB( outTRp1_25_3398820Callback );
	notificationEventHandler.register_outTRp2_10_3398821CB( outTRp2_10_3398821Callback );
	notificationEventHandler.register_outTRp1_26_3398822CB( outTRp1_26_3398822Callback );
	notificationEventHandler.register_outTRp11_1_3398824CB( outTRp11_1_3398824Callback );
	notificationEventHandler.register_outTRp9_1_3398829CB( outTRp9_1_3398829Callback );
	notificationEventHandler.register_outTRp3_2_3398830CB( outTRp3_2_3398830Callback );
	notificationEventHandler.register_outTRp9_5_3398831CB( outTRp9_5_3398831Callback );
	notificationEventHandler.register_outTRp1_21_3398832CB( outTRp1_21_3398832Callback );
	notificationEventHandler.register_outTRp3_29_3398835CB( outTRp3_29_3398835Callback );
	notificationEventHandler.register_outTRp3_21_3398836CB( outTRp3_21_3398836Callback );
	notificationEventHandler.register_outTRp1_20_3398837CB( outTRp1_20_3398837Callback );
	notificationEventHandler.register_outTRp4_2_3398839CB( outTRp4_2_3398839Callback );
	notificationEventHandler.register_outTRp3_8_3398840CB( outTRp3_8_3398840Callback );
	notificationEventHandler.register_outTRp1_5_3398844CB( outTRp1_5_3398844Callback );
	notificationEventHandler.register_outTRp1_12_3398846CB( outTRp1_12_3398846Callback );
	notificationEventHandler.register_outTRp2_9_3398848CB( outTRp2_9_3398848Callback );
	notificationEventHandler.register_outTRp2_7_3398851CB( outTRp2_7_3398851Callback );
	notificationEventHandler.register_outTRp3_13_3398852CB( outTRp3_13_3398852Callback );
	notificationEventHandler.register_outTRp3_40_3398853CB( outTRp3_40_3398853Callback );
	notificationEventHandler.register_outTRp3_40_3398855CB( outTRp3_40_3398855Callback );
	notificationEventHandler.register_outTRp3_6_3398857CB( outTRp3_6_3398857Callback );
	notificationEventHandler.register_outTRp17_1_3398863CB( outTRp17_1_3398863Callback );
	notificationEventHandler.register_outTRp1_3_3398866CB( outTRp1_3_3398866Callback );
	notificationEventHandler.register_outTRp3_10_3398867CB( outTRp3_10_3398867Callback );
	notificationEventHandler.register_outTRp4_3_3398869CB( outTRp4_3_3398869Callback );
	notificationEventHandler.register_outTRp9_1_3398870CB( outTRp9_1_3398870Callback );
	notificationEventHandler.register_outTRp4_2_3398873CB( outTRp4_2_3398873Callback );
	notificationEventHandler.register_outTRp2_1_3398874CB( outTRp2_1_3398874Callback );
	notificationEventHandler.register_outTRp19_1_3398877CB( outTRp19_1_3398877Callback );
	notificationEventHandler.register_outTRp1_10_3398879CB( outTRp1_10_3398879Callback );
	notificationEventHandler.register_outTRp3_52_3398880CB( outTRp3_52_3398880Callback );
	notificationEventHandler.register_outTRp3_52_3398881CB( outTRp3_52_3398881Callback );
	notificationEventHandler.register_outTRp3_41_3398883CB( outTRp3_41_3398883Callback );
	notificationEventHandler.register_outTRp3_36_3398884CB( outTRp3_36_3398884Callback );
	notificationEventHandler.register_outTRp3_34_3398885CB( outTRp3_34_3398885Callback );
	notificationEventHandler.register_outTRp3_31_3398886CB( outTRp3_31_3398886Callback );
	notificationEventHandler.register_outTRp3_29_3398887CB( outTRp3_29_3398887Callback );
	notificationEventHandler.register_outTRp3_18_3398888CB( outTRp3_18_3398888Callback );
	notificationEventHandler.register_outTRp3_60_3398889CB( outTRp3_60_3398889Callback );
	notificationEventHandler.register_outTRp3_62_3398890CB( outTRp3_62_3398890Callback );
	notificationEventHandler.register_outTRp3_60_3398891CB( outTRp3_60_3398891Callback );
	notificationEventHandler.register_outTRp3_62_3398892CB( outTRp3_62_3398892Callback );
	notificationEventHandler.register_outTRp3_62_3398893CB( outTRp3_62_3398893Callback );
	notificationEventHandler.register_outTRp3_61_3398894CB( outTRp3_61_3398894Callback );

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

int V2__1_0__Server::commands_receiveInTRp2_1_3398721(__attribute__((unused)) const tno_dynamics_inTRp2_1_3398721_t& inTRp2_1_3398721, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp2_1_3398721\n" );
    eventApi.inTRp2_1_3398721(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp3_1_3398722(__attribute__((unused)) const tno_dynamics_inTRp3_1_3398722_t& inTRp3_1_3398722, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp3_1_3398722\n" );
    eventApi.inTRp3_1_3398722(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp1_1_3398723(__attribute__((unused)) const tno_dynamics_inTRp1_1_3398723_t& inTRp1_1_3398723, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp1_1_3398723\n" );
    eventApi.inTRp1_1_3398723(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp3_2_3398726(__attribute__((unused)) const tno_dynamics_inTRp3_2_3398726_t& inTRp3_2_3398726, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp3_2_3398726\n" );
    eventApi.inTRp3_2_3398726(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp2_1_3398728(__attribute__((unused)) const tno_dynamics_inTRp2_1_3398728_t& inTRp2_1_3398728, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp2_1_3398728\n" );
    eventApi.inTRp2_1_3398728(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp3_4_3398729(__attribute__((unused)) const tno_dynamics_inTRp3_4_3398729_t& inTRp3_4_3398729, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp3_4_3398729\n" );
    eventApi.inTRp3_4_3398729(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp2_1_3398732(__attribute__((unused)) const tno_dynamics_inTRp2_1_3398732_t& inTRp2_1_3398732, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp2_1_3398732\n" );
    eventApi.inTRp2_1_3398732(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp3_5_3398734(__attribute__((unused)) const tno_dynamics_inTRp3_5_3398734_t& inTRp3_5_3398734, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp3_5_3398734\n" );
    eventApi.inTRp3_5_3398734(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp3_4_3398737(__attribute__((unused)) const tno_dynamics_inTRp3_4_3398737_t& inTRp3_4_3398737, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp3_4_3398737\n" );
    eventApi.inTRp3_4_3398737(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp2_2_3398739(__attribute__((unused)) const tno_dynamics_inTRp2_2_3398739_t& inTRp2_2_3398739, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp2_2_3398739\n" );
    eventApi.inTRp2_2_3398739(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp3_10_3398741(__attribute__((unused)) const tno_dynamics_inTRp3_10_3398741_t& inTRp3_10_3398741, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp3_10_3398741\n" );
    eventApi.inTRp3_10_3398741(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp1_2_3398742(__attribute__((unused)) const tno_dynamics_inTRp1_2_3398742_t& inTRp1_2_3398742, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp1_2_3398742\n" );
    eventApi.inTRp1_2_3398742(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp1_2_3398743(__attribute__((unused)) const tno_dynamics_inTRp1_2_3398743_t& inTRp1_2_3398743, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp1_2_3398743\n" );
    eventApi.inTRp1_2_3398743(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp1_4_3398746(__attribute__((unused)) const tno_dynamics_inTRp1_4_3398746_t& inTRp1_4_3398746, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp1_4_3398746\n" );
    eventApi.inTRp1_4_3398746(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp3_9_3398747(__attribute__((unused)) const tno_dynamics_inTRp3_9_3398747_t& inTRp3_9_3398747, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp3_9_3398747\n" );
    eventApi.inTRp3_9_3398747(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp3_5_3398749(__attribute__((unused)) const tno_dynamics_inTRp3_5_3398749_t& inTRp3_5_3398749, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp3_5_3398749\n" );
    eventApi.inTRp3_5_3398749(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp3_4_3398750(__attribute__((unused)) const tno_dynamics_inTRp3_4_3398750_t& inTRp3_4_3398750, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp3_4_3398750\n" );
    eventApi.inTRp3_4_3398750(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp3_9_3398751(__attribute__((unused)) const tno_dynamics_inTRp3_9_3398751_t& inTRp3_9_3398751, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp3_9_3398751\n" );
    eventApi.inTRp3_9_3398751(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp3_8_3398752(__attribute__((unused)) const tno_dynamics_inTRp3_8_3398752_t& inTRp3_8_3398752, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp3_8_3398752\n" );
    eventApi.inTRp3_8_3398752(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp2_1_3398753(__attribute__((unused)) const tno_dynamics_inTRp2_1_3398753_t& inTRp2_1_3398753, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp2_1_3398753\n" );
    eventApi.inTRp2_1_3398753(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp2_3_3398754(__attribute__((unused)) const tno_dynamics_inTRp2_3_3398754_t& inTRp2_3_3398754, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp2_3_3398754\n" );
    eventApi.inTRp2_3_3398754(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp1_5_3398755(__attribute__((unused)) const tno_dynamics_inTRp1_5_3398755_t& inTRp1_5_3398755, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp1_5_3398755\n" );
    eventApi.inTRp1_5_3398755(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp2_1_3398757(__attribute__((unused)) const tno_dynamics_inTRp2_1_3398757_t& inTRp2_1_3398757, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp2_1_3398757\n" );
    eventApi.inTRp2_1_3398757(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp1_3_3398758(__attribute__((unused)) const tno_dynamics_inTRp1_3_3398758_t& inTRp1_3_3398758, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp1_3_3398758\n" );
    eventApi.inTRp1_3_3398758(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp3_5_3398760(__attribute__((unused)) const tno_dynamics_inTRp3_5_3398760_t& inTRp3_5_3398760, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp3_5_3398760\n" );
    eventApi.inTRp3_5_3398760(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp3_12_3398765(__attribute__((unused)) const tno_dynamics_inTRp3_12_3398765_t& inTRp3_12_3398765, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp3_12_3398765\n" );
    eventApi.inTRp3_12_3398765(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp1_8_3398767(__attribute__((unused)) const tno_dynamics_inTRp1_8_3398767_t& inTRp1_8_3398767, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp1_8_3398767\n" );
    eventApi.inTRp1_8_3398767(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp3_9_3398768(__attribute__((unused)) const tno_dynamics_inTRp3_9_3398768_t& inTRp3_9_3398768, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp3_9_3398768\n" );
    eventApi.inTRp3_9_3398768(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp3_11_3398770(__attribute__((unused)) const tno_dynamics_inTRp3_11_3398770_t& inTRp3_11_3398770, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp3_11_3398770\n" );
    eventApi.inTRp3_11_3398770(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp2_4_3398772(__attribute__((unused)) const tno_dynamics_inTRp2_4_3398772_t& inTRp2_4_3398772, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp2_4_3398772\n" );
    eventApi.inTRp2_4_3398772(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp3_26_3398774(__attribute__((unused)) const tno_dynamics_inTRp3_26_3398774_t& inTRp3_26_3398774, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp3_26_3398774\n" );
    eventApi.inTRp3_26_3398774(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp5_1_3398776(__attribute__((unused)) const tno_dynamics_inTRp5_1_3398776_t& inTRp5_1_3398776, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp5_1_3398776\n" );
    eventApi.inTRp5_1_3398776(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp3_8_3398780(__attribute__((unused)) const tno_dynamics_inTRp3_8_3398780_t& inTRp3_8_3398780, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp3_8_3398780\n" );
    eventApi.inTRp3_8_3398780(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp2_3_3398781(__attribute__((unused)) const tno_dynamics_inTRp2_3_3398781_t& inTRp2_3_3398781, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp2_3_3398781\n" );
    eventApi.inTRp2_3_3398781(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp1_2_3398783(__attribute__((unused)) const tno_dynamics_inTRp1_2_3398783_t& inTRp1_2_3398783, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp1_2_3398783\n" );
    eventApi.inTRp1_2_3398783(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp1_14_3398785(__attribute__((unused)) const tno_dynamics_inTRp1_14_3398785_t& inTRp1_14_3398785, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp1_14_3398785\n" );
    eventApi.inTRp1_14_3398785(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp3_12_3398786(__attribute__((unused)) const tno_dynamics_inTRp3_12_3398786_t& inTRp3_12_3398786, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp3_12_3398786\n" );
    eventApi.inTRp3_12_3398786(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp3_12_3398787(__attribute__((unused)) const tno_dynamics_inTRp3_12_3398787_t& inTRp3_12_3398787, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp3_12_3398787\n" );
    eventApi.inTRp3_12_3398787(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp1_16_3398790(__attribute__((unused)) const tno_dynamics_inTRp1_16_3398790_t& inTRp1_16_3398790, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp1_16_3398790\n" );
    eventApi.inTRp1_16_3398790(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp3_13_3398792(__attribute__((unused)) const tno_dynamics_inTRp3_13_3398792_t& inTRp3_13_3398792, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp3_13_3398792\n" );
    eventApi.inTRp3_13_3398792(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp10_1_3398795(__attribute__((unused)) const tno_dynamics_inTRp10_1_3398795_t& inTRp10_1_3398795, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp10_1_3398795\n" );
    eventApi.inTRp10_1_3398795(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp11_1_3398796(__attribute__((unused)) const tno_dynamics_inTRp11_1_3398796_t& inTRp11_1_3398796, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp11_1_3398796\n" );
    eventApi.inTRp11_1_3398796(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp3_18_3398798(__attribute__((unused)) const tno_dynamics_inTRp3_18_3398798_t& inTRp3_18_3398798, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp3_18_3398798\n" );
    eventApi.inTRp3_18_3398798(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp9_1_3398800(__attribute__((unused)) const tno_dynamics_inTRp9_1_3398800_t& inTRp9_1_3398800, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp9_1_3398800\n" );
    eventApi.inTRp9_1_3398800(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp3_14_3398803(__attribute__((unused)) const tno_dynamics_inTRp3_14_3398803_t& inTRp3_14_3398803, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp3_14_3398803\n" );
    eventApi.inTRp3_14_3398803(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp10_1_3398805(__attribute__((unused)) const tno_dynamics_inTRp10_1_3398805_t& inTRp10_1_3398805, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp10_1_3398805\n" );
    eventApi.inTRp10_1_3398805(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp5_3_3398807(__attribute__((unused)) const tno_dynamics_inTRp5_3_3398807_t& inTRp5_3_3398807, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp5_3_3398807\n" );
    eventApi.inTRp5_3_3398807(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp1_9_3398808(__attribute__((unused)) const tno_dynamics_inTRp1_9_3398808_t& inTRp1_9_3398808, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp1_9_3398808\n" );
    eventApi.inTRp1_9_3398808(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp1_2_3398812(__attribute__((unused)) const tno_dynamics_inTRp1_2_3398812_t& inTRp1_2_3398812, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp1_2_3398812\n" );
    eventApi.inTRp1_2_3398812(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp3_10_3398813(__attribute__((unused)) const tno_dynamics_inTRp3_10_3398813_t& inTRp3_10_3398813, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp3_10_3398813\n" );
    eventApi.inTRp3_10_3398813(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp3_17_3398814(__attribute__((unused)) const tno_dynamics_inTRp3_17_3398814_t& inTRp3_17_3398814, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp3_17_3398814\n" );
    eventApi.inTRp3_17_3398814(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp12_1_3398818(__attribute__((unused)) const tno_dynamics_inTRp12_1_3398818_t& inTRp12_1_3398818, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp12_1_3398818\n" );
    eventApi.inTRp12_1_3398818(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp13_1_3398819(__attribute__((unused)) const tno_dynamics_inTRp13_1_3398819_t& inTRp13_1_3398819, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp13_1_3398819\n" );
    eventApi.inTRp13_1_3398819(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp1_27_3398823(__attribute__((unused)) const tno_dynamics_inTRp1_27_3398823_t& inTRp1_27_3398823, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp1_27_3398823\n" );
    eventApi.inTRp1_27_3398823(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp1_5_3398825(__attribute__((unused)) const tno_dynamics_inTRp1_5_3398825_t& inTRp1_5_3398825, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp1_5_3398825\n" );
    eventApi.inTRp1_5_3398825(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp2_5_3398826(__attribute__((unused)) const tno_dynamics_inTRp2_5_3398826_t& inTRp2_5_3398826, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp2_5_3398826\n" );
    eventApi.inTRp2_5_3398826(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp3_15_3398827(__attribute__((unused)) const tno_dynamics_inTRp3_15_3398827_t& inTRp3_15_3398827, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp3_15_3398827\n" );
    eventApi.inTRp3_15_3398827(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp1_31_3398828(__attribute__((unused)) const tno_dynamics_inTRp1_31_3398828_t& inTRp1_31_3398828, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp1_31_3398828\n" );
    eventApi.inTRp1_31_3398828(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp1_14_3398833(__attribute__((unused)) const tno_dynamics_inTRp1_14_3398833_t& inTRp1_14_3398833, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp1_14_3398833\n" );
    eventApi.inTRp1_14_3398833(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp1_32_3398834(__attribute__((unused)) const tno_dynamics_inTRp1_32_3398834_t& inTRp1_32_3398834, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp1_32_3398834\n" );
    eventApi.inTRp1_32_3398834(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp4_1_3398838(__attribute__((unused)) const tno_dynamics_inTRp4_1_3398838_t& inTRp4_1_3398838, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp4_1_3398838\n" );
    eventApi.inTRp4_1_3398838(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp14_1_3398841(__attribute__((unused)) const tno_dynamics_inTRp14_1_3398841_t& inTRp14_1_3398841, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp14_1_3398841\n" );
    eventApi.inTRp14_1_3398841(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp3_3_3398842(__attribute__((unused)) const tno_dynamics_inTRp3_3_3398842_t& inTRp3_3_3398842, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp3_3_3398842\n" );
    eventApi.inTRp3_3_3398842(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp2_8_3398847(__attribute__((unused)) const tno_dynamics_inTRp2_8_3398847_t& inTRp2_8_3398847, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp2_8_3398847\n" );
    eventApi.inTRp2_8_3398847(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp1_10_3398849(__attribute__((unused)) const tno_dynamics_inTRp1_10_3398849_t& inTRp1_10_3398849, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp1_10_3398849\n" );
    eventApi.inTRp1_10_3398849(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp2_6_3398850(__attribute__((unused)) const tno_dynamics_inTRp2_6_3398850_t& inTRp2_6_3398850, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp2_6_3398850\n" );
    eventApi.inTRp2_6_3398850(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp15_1_3398854(__attribute__((unused)) const tno_dynamics_inTRp15_1_3398854_t& inTRp15_1_3398854, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp15_1_3398854\n" );
    eventApi.inTRp15_1_3398854(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp16_1_3398856(__attribute__((unused)) const tno_dynamics_inTRp16_1_3398856_t& inTRp16_1_3398856, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp16_1_3398856\n" );
    eventApi.inTRp16_1_3398856(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp17_1_3398858(__attribute__((unused)) const tno_dynamics_inTRp17_1_3398858_t& inTRp17_1_3398858, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp17_1_3398858\n" );
    eventApi.inTRp17_1_3398858(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp1_15_3398859(__attribute__((unused)) const tno_dynamics_inTRp1_15_3398859_t& inTRp1_15_3398859, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp1_15_3398859\n" );
    eventApi.inTRp1_15_3398859(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp3_34_3398860(__attribute__((unused)) const tno_dynamics_inTRp3_34_3398860_t& inTRp3_34_3398860, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp3_34_3398860\n" );
    eventApi.inTRp3_34_3398860(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp1_24_3398861(__attribute__((unused)) const tno_dynamics_inTRp1_24_3398861_t& inTRp1_24_3398861, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp1_24_3398861\n" );
    eventApi.inTRp1_24_3398861(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp1_7_3398862(__attribute__((unused)) const tno_dynamics_inTRp1_7_3398862_t& inTRp1_7_3398862, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp1_7_3398862\n" );
    eventApi.inTRp1_7_3398862(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp17_2_3398864(__attribute__((unused)) const tno_dynamics_inTRp17_2_3398864_t& inTRp17_2_3398864, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp17_2_3398864\n" );
    eventApi.inTRp17_2_3398864(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp3_27_3398865(__attribute__((unused)) const tno_dynamics_inTRp3_27_3398865_t& inTRp3_27_3398865, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp3_27_3398865\n" );
    eventApi.inTRp3_27_3398865(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp4_2_3398868(__attribute__((unused)) const tno_dynamics_inTRp4_2_3398868_t& inTRp4_2_3398868, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp4_2_3398868\n" );
    eventApi.inTRp4_2_3398868(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp18_1_3398871(__attribute__((unused)) const tno_dynamics_inTRp18_1_3398871_t& inTRp18_1_3398871, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp18_1_3398871\n" );
    eventApi.inTRp18_1_3398871(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp3_22_3398872(__attribute__((unused)) const tno_dynamics_inTRp3_22_3398872_t& inTRp3_22_3398872, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp3_22_3398872\n" );
    eventApi.inTRp3_22_3398872(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp2_2_3398875(__attribute__((unused)) const tno_dynamics_inTRp2_2_3398875_t& inTRp2_2_3398875, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp2_2_3398875\n" );
    eventApi.inTRp2_2_3398875(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp4_1_3398876(__attribute__((unused)) const tno_dynamics_inTRp4_1_3398876_t& inTRp4_1_3398876, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp4_1_3398876\n" );
    eventApi.inTRp4_1_3398876(  );
    return OK;
}
int V2__1_0__Server::commands_receiveInTRp3_28_3398878(__attribute__((unused)) const tno_dynamics_inTRp3_28_3398878_t& inTRp3_28_3398878, __attribute__((unused)) pubsub::ISubscriberCallbacks& callbacks) noexcept {
    
    LOG_INFO( "\n######## O2N: V2__1_0__Server received: inTRp3_28_3398878\n" );
    eventApi.inTRp3_28_3398878(  );
    return OK;
}

