#ifndef __AppProtocolRequests_CalibrationDec_h__
#define __AppProtocolRequests_CalibrationDec_h__

#include <string>

#include "../AppProtocolRequest.h"
#include "../AppProtocolRequests.h"

namespace AppRequests{

  class CalibrationDec: public AppProtocolRequest{
    private:
        std::string data;
    public:
        CalibrationDec(std::string data);
        std::string getRawData();
    };  




} // namespace AppProtocolRequests



#endif