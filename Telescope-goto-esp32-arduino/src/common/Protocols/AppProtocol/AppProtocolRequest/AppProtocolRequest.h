#ifndef __AppProtocolRequest_h__
#define __AppProtocolRequest_h__

#include "AppProtocolRequests.h"

class AppProtocolRequest{
protected:
    AppProtocolRequests type;
public:
    virtual AppProtocolRequests getType();
};

namespace AppRequests{
    
};

#endif