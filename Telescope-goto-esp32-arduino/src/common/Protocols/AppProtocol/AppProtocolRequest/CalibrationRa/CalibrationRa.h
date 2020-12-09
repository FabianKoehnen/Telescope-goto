#ifndef __AppProtocolRequests_CalibrationRa_h__
#define __AppProtocolRequests_CalibrationRa_h__

#include <string>

#include "../AppProtocolRequest.h"
#include "../AppProtocolRequests.h"

namespace AppRequests{

  class CalibrationRa: public AppProtocolRequest{
    private:
        std::string data;
    public:
        CalibrationRa(std::string data);
        std::string getRawData();
    };  




} // namespace AppProtocolRequests



#endif