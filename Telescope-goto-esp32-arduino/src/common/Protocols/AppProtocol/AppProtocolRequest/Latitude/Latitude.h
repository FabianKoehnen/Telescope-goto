#ifndef __AppProtocolRequests_Latitude_h__
#define __AppProtocolRequests_Latitude_h__

#include <string>

#include "../AppProtocolRequest.h"
#include "../AppProtocolRequests.h"

namespace AppRequests{

  class Latitude: public AppProtocolRequest{
    private:
        std::string data;
    public:
        Latitude(std::string data);
        std::string getRawData();
    };  




} // namespace AppProtocolRequests



#endif