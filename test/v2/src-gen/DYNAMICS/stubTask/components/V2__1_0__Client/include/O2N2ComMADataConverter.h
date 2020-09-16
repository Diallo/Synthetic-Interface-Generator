#ifndef O2N2COMMADATACONVERTER_H
#define O2N2COMMADATACONVERTER_H

#include "common.h"

#include "tno/dynamics/Response.h"
#include "tno/dynamics/inTRp1_1_11.h"
#include "tno/dynamics/inTRp1_3_13.h"
#include "tno/dynamics/inTRp1_4_14.h"
#include "tno/dynamics/inTRp2_1_17.h"
#include "tno/dynamics/inTRp3_1_18.h"

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
