#ifndef __AppProtocol_h__
#define __AppProtocol_h__

#include <vector>
#include "../../Logger.h"
#include "../IProtocol.h"
#include "./AppProtocolRequestHandler/AppProtocolRequestHandler.h"

#include "AppProtocolRequest/Date/Date.h"
#include "AppProtocolRequest/Time/Time.h"
#include "AppProtocolRequest/UtcOffset/UtcOffset.h"
#include "AppProtocolRequest/Latitude/Latitude.h"
#include "AppProtocolRequest/Longitude/Longitude.h"
#include "AppProtocolRequest/CalibrationDec/CalibrationDec.h"
#include "AppProtocolRequest/CalibrationRa/CalibrationRa.h"
#include "AppProtocolRequest/Move/Move.h"

class AppProtocol: public IProtocol{
private:
    AppProtocolRequestHandler &requestHandler;
    std::vector<std::string> extractComand(std::string rawMsg);
    std::string getComandType(std::string comand);
    std::string getComandPayload(std::string comand);
public:
    AppProtocol(AppProtocolRequestHandler &requestHandler);
    std::string interpret(std::string msg);
};

#endif