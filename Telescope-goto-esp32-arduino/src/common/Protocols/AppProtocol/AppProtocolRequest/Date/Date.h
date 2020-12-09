#ifndef __AppProtocolRequests_Date_h__
#define __AppProtocolRequests_Date_h__

#include <string>

#include "../AppProtocolRequest.h"
#include "../AppProtocolRequests.h"

namespace AppRequests{

  class Date: public AppProtocolRequest{
    private:
        std::string data;
    public:
        Date(std::string data);
        std::string getRawData();
    };  




} // namespace AppProtocolRequests



#endif