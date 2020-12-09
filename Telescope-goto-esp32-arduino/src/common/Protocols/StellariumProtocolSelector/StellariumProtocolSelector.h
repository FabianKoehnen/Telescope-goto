#ifndef __StellariumProtocolSelector_h__
#define __StellariumProtocolSelector_h__

#include "../IProtocol.h"

class StellariumProtocolSelector: public IProtocol{
private:
public:
    StellariumProtocolSelector();
    std::string interpret(std::string msg);
};

#endif