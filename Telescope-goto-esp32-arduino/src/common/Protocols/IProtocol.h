#ifndef __IProtocol_h__
#define __IProtocol_h__

#include "../ComunicationInterface/ComunicationInterface.h"

class IProtocol{
public:
    virtual std::string interpret(std::string) = 0;
};

#endif