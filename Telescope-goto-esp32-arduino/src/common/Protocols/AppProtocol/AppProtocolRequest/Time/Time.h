#ifndef __AppProtocolRequests_Time_h__
#define __AppProtocolRequests_Time_h__

#include <string>

#include "../AppProtocolRequest.h"
#include "../AppProtocolRequests.h"

namespace AppRequests{

  class Time: public AppProtocolRequest{
    private:
        std::string data;
    public:
        Time(std::string data);
        std::string getRawData();
    };  




} // namespace AppProtocolRequests



#endif