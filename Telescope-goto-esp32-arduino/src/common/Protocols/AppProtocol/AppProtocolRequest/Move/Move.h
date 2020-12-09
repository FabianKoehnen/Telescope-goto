#ifndef __AppProtocolRequests_Move_h__
#define __AppProtocolRequests_Move_h__

#include <string>
#include <stdlib.h>

#include "../AppProtocolRequest.h"
#include "../AppProtocolRequests.h"

namespace AppRequests{

  class Move: public AppProtocolRequest{
    private:
        std::string data;
        std::string segments[3];
    public:
        Move(std::string data);
        std::string getRawData();
        int getMotor();
        bool isOn();
        bool isClockwise();
    };  




} // namespace AppProtocolRequests



#endif