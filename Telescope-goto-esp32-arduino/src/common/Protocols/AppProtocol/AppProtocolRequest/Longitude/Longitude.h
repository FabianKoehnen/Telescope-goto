#ifndef __AppProtocolRequests_Longitude_h__
#define __AppProtocolRequests_Longitude_h__

#include <string>

#include "../AppProtocolRequest.h"
#include "../AppProtocolRequests.h"

namespace AppRequests{

  class Longitude: public AppProtocolRequest{
    private:
        std::string data;
    public:
        Longitude(std::string data);
        std::string getRawData();
    };  




} // namespace AppProtocolRequests



#endif