#ifndef __LX200_h__
#define __LX200_h__

#include "../../Logger.h"

#include "../IProtocol.h"
#include "./Lx200RequestHandler/Lx200RequestHandler.h"
#include "./Lx200Request/Lx200Requests.h"
#include "./Lx200Request/Lx200Request.h"
#include "./Lx200Response/Lx200Response.h"

class Lx200 : public IProtocol
{
private:
    Lx200RequestHandler &requestHandler;
    std::vector<std::string> extractComand(std::string rawMsg);
    std::string getComandType(std::string comand);
    std::string getComandPayload(std::string comand);

public:
    Lx200(Lx200RequestHandler &requestHandler);
    std::string interpret(std::string msg);
};

#endif
