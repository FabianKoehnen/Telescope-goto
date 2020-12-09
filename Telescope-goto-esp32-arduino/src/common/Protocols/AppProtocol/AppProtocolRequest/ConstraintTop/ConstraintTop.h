#ifndef __AppProtocolRequests_ConstraintTop_h__
#define __AppProtocolRequests_ConstraintTop_h__

#include <string>

#include "../AppProtocolRequest.h"
#include "../AppProtocolRequests.h"

namespace AppRequests{

  class ConstraintTop: public AppProtocolRequest{
    private:
        std::string data;
    public:
        ConstraintTop(std::string data);
        std::string getRawData();
    };  




} // namespace AppProtocolRequests



#endif