#ifndef __AppProtocolRequests_ConstraintBottom_h__
#define __AppProtocolRequests_ConstraintBottom_h__

#include <string>

#include "../AppProtocolRequest.h"
#include "../AppProtocolRequests.h"

namespace AppRequests{

  class ConstraintBottom: public AppProtocolRequest{
    private:
        std::string data;
    public:
        ConstraintBottom(std::string data);
        std::string getRawData();
    };  




} // namespace AppProtocolRequests



#endif