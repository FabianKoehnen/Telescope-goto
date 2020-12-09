#ifndef __AppProtocolRequests_Move_h__
#define __AppProtocolRequests_Move_h__

#include <string>

#include "../AppProtocolRequest.h"
#include "../AppProtocolRequests.h"

namespace AppRequests{

  class Move: public AppProtocolRequest{
    private:
        std::string data;
    public:
        Move(std::string data);
        std::string getRawData();
    };  




} // namespace AppProtocolRequests



#endif