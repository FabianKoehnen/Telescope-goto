#ifndef __AppProtocolRequests_UtcOffset_h__
#define __AppProtocolRequests_UtcOffset_h__

#include <string>

#include "../AppProtocolRequest.h"
#include "../AppProtocolRequests.h"

namespace AppRequests{

  class UtcOffset: public AppProtocolRequest{
    private:
        std::string data;
    public:
        UtcOffset(std::string data);
        std::string getRawData();
    };  




} // namespace AppProtocolRequests



#endif