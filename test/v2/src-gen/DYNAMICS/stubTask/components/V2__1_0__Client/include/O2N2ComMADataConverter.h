#ifndef O2N2COMMADATACONVERTER_H
#define O2N2COMMADATACONVERTER_H

#include "common.h"

#include "tno/dynamics/Response.h"
#include "tno/dynamics/inTRp2_1_3398721.h"
#include "tno/dynamics/inTRp3_1_3398722.h"
#include "tno/dynamics/inTRp1_1_3398723.h"
#include "tno/dynamics/inTRp3_2_3398726.h"
#include "tno/dynamics/inTRp2_1_3398728.h"
#include "tno/dynamics/inTRp3_4_3398729.h"
#include "tno/dynamics/inTRp2_1_3398732.h"
#include "tno/dynamics/inTRp3_5_3398734.h"
#include "tno/dynamics/inTRp3_4_3398737.h"
#include "tno/dynamics/inTRp2_2_3398739.h"
#include "tno/dynamics/inTRp3_10_3398741.h"
#include "tno/dynamics/inTRp1_2_3398742.h"
#include "tno/dynamics/inTRp1_2_3398743.h"
#include "tno/dynamics/inTRp1_4_3398746.h"
#include "tno/dynamics/inTRp3_9_3398747.h"
#include "tno/dynamics/inTRp3_5_3398749.h"
#include "tno/dynamics/inTRp3_4_3398750.h"
#include "tno/dynamics/inTRp3_9_3398751.h"
#include "tno/dynamics/inTRp3_8_3398752.h"
#include "tno/dynamics/inTRp2_1_3398753.h"
#include "tno/dynamics/inTRp2_3_3398754.h"
#include "tno/dynamics/inTRp1_5_3398755.h"
#include "tno/dynamics/inTRp2_1_3398757.h"
#include "tno/dynamics/inTRp1_3_3398758.h"
#include "tno/dynamics/inTRp3_5_3398760.h"
#include "tno/dynamics/inTRp3_12_3398765.h"
#include "tno/dynamics/inTRp1_8_3398767.h"
#include "tno/dynamics/inTRp3_9_3398768.h"
#include "tno/dynamics/inTRp3_11_3398770.h"
#include "tno/dynamics/inTRp2_4_3398772.h"
#include "tno/dynamics/inTRp3_26_3398774.h"
#include "tno/dynamics/inTRp5_1_3398776.h"
#include "tno/dynamics/inTRp3_8_3398780.h"
#include "tno/dynamics/inTRp2_3_3398781.h"
#include "tno/dynamics/inTRp1_2_3398783.h"
#include "tno/dynamics/inTRp1_14_3398785.h"
#include "tno/dynamics/inTRp3_12_3398786.h"
#include "tno/dynamics/inTRp3_12_3398787.h"
#include "tno/dynamics/inTRp1_16_3398790.h"
#include "tno/dynamics/inTRp3_13_3398792.h"
#include "tno/dynamics/inTRp10_1_3398795.h"
#include "tno/dynamics/inTRp11_1_3398796.h"
#include "tno/dynamics/inTRp3_18_3398798.h"
#include "tno/dynamics/inTRp9_1_3398800.h"
#include "tno/dynamics/inTRp3_14_3398803.h"
#include "tno/dynamics/inTRp10_1_3398805.h"
#include "tno/dynamics/inTRp5_3_3398807.h"
#include "tno/dynamics/inTRp1_9_3398808.h"
#include "tno/dynamics/inTRp1_2_3398812.h"
#include "tno/dynamics/inTRp3_10_3398813.h"
#include "tno/dynamics/inTRp3_17_3398814.h"
#include "tno/dynamics/inTRp12_1_3398818.h"
#include "tno/dynamics/inTRp13_1_3398819.h"
#include "tno/dynamics/inTRp1_27_3398823.h"
#include "tno/dynamics/inTRp1_5_3398825.h"
#include "tno/dynamics/inTRp2_5_3398826.h"
#include "tno/dynamics/inTRp3_15_3398827.h"
#include "tno/dynamics/inTRp1_31_3398828.h"
#include "tno/dynamics/inTRp1_14_3398833.h"
#include "tno/dynamics/inTRp1_32_3398834.h"
#include "tno/dynamics/inTRp4_1_3398838.h"
#include "tno/dynamics/inTRp14_1_3398841.h"
#include "tno/dynamics/inTRp3_3_3398842.h"
#include "tno/dynamics/inTRp2_8_3398847.h"
#include "tno/dynamics/inTRp1_10_3398849.h"
#include "tno/dynamics/inTRp2_6_3398850.h"
#include "tno/dynamics/inTRp15_1_3398854.h"
#include "tno/dynamics/inTRp16_1_3398856.h"
#include "tno/dynamics/inTRp17_1_3398858.h"
#include "tno/dynamics/inTRp1_15_3398859.h"
#include "tno/dynamics/inTRp3_34_3398860.h"
#include "tno/dynamics/inTRp1_24_3398861.h"
#include "tno/dynamics/inTRp1_7_3398862.h"
#include "tno/dynamics/inTRp17_2_3398864.h"
#include "tno/dynamics/inTRp3_27_3398865.h"
#include "tno/dynamics/inTRp4_2_3398868.h"
#include "tno/dynamics/inTRp18_1_3398871.h"
#include "tno/dynamics/inTRp3_22_3398872.h"
#include "tno/dynamics/inTRp2_2_3398875.h"
#include "tno/dynamics/inTRp4_1_3398876.h"
#include "tno/dynamics/inTRp3_28_3398878.h"

class O2N2ComMADataConverter {
public:
	static real convert( float argument ) {
		return static_cast<real>( argument );
	}
	
	static int convert( int argument ) {
		return argument;
	}
	
	static bool convert( bool argument ) {
		return argument;
	}
	
	static std::string convert( char* argument ) {
		if ( argument != nullptr ) {
			std::string s( argument );
			return s;
		}
		else {
			return "";
		}
	}
	
	static StateMachineController::V2::Response::Response convert( tno_dynamics_Response_t response ) {
	    StateMachineController::V2::Response::Response commaResponse{};
	
	    switch ( response ) {
			case tno_dynamics_Response_t::tno_dynamics_ACK: {
			    commaResponse = StateMachineController::V2::Response::ACK;
			    break;
			}
			case tno_dynamics_Response_t::tno_dynamics_UPDATE: {
			    commaResponse = StateMachineController::V2::Response::UPDATE;
			    break;
			}
	    }
	
	    return commaResponse;
	}
	
};

#endif //O2N2COMMADATACONVERTER_H
