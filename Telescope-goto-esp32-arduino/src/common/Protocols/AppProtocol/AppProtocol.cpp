#include "AppProtocol.h"

AppProtocol::AppProtocol(AppProtocolRequestHandler &requestHandler): requestHandler(requestHandler){

}

std::vector<std::string> AppProtocol::extractComand(std::string rawMsg){
    std::vector<std::string> comands;
    bool colect = false;
    int comandCounter = 0;
    std::string comand = "";

    for (int i = 0; i < rawMsg.length(); i++){
        if(rawMsg[i] == ':'){
            if(colect == false){
                colect = true;
                comand = "";
                continue;
            }
        }else if(rawMsg[i] == ';'){
            if(colect == true){
                colect = false;
                comandCounter++;
                comands.push_back(comand);
            }
        }
        if(colect == true){
            comand += rawMsg[i];
        }
    }
    return comands;
}

std::string AppProtocol::getComandType(std::string comand){
    bool colect = true;
    std::string type = "";

    for (int i = 0; i < comand.length(); i++){
        if(comand[i] == '='){
            if(colect == true){
                colect = false;
                return type;
            }
        }
        if(colect == true){
            type += comand[i];
        }
    }
    return type;
}

std::string AppProtocol::getComandPayload(std::string comand){
    bool colect = false;
    std::string payload = "";

    for (int i = 0; i < comand.length(); i++){
        if(comand[i] == '='){
            if(colect == false){
                colect = true;
                payload = "";
                continue;
            }
        }
        if(colect == true){
            payload += comand[i];
        }
    }
    return payload;
}

std::string AppProtocol::interpret(std::string msg){
    std::vector<std::string> comands = this->extractComand(msg);
    AppProtocolResponse response = AppProtocolResponse::unknown();
    for (std::string comand : comands){
        std::string type = this->getComandType(comand);
        logger.LOG_I("type", type);
        std::string payload = this->getComandPayload(comand);
        logger.LOG_I("payload", payload);
        AppProtocolRequest* request = nullptr;
        if(type == "trackingInfo"){
            //todo add response
        }else if(type == "date"){
            request = new AppRequests::Date(payload);
        }else if(type == "time"){
            request = new AppRequests::Time(payload);
        }else if(type == "utcOffset"){
            request = new AppRequests::UtcOffset(payload);
        }else if(type == "latitude"){
            request = new AppRequests::Latitude(payload);
        }else if(type == "longitude"){
            request = new AppRequests::Longitude(payload);
        }else if(type == "calibrationRa"){
            request = new AppRequests::CalibrationRa(payload);
        }else if(type == "calibrationDec"){
            request = new AppRequests::CalibrationDec(payload);
        }else if(type == "move"){
            request = new AppRequests::Move(payload);
        }else if(type == "constraintTop"){
            request = new AppRequests::ConstraintTop(payload);
        }else if(type == "constraintBottom"){
            request = new AppRequests::ConstraintBottom(payload);
        }

        if(request != nullptr){
            response = this->requestHandler.handle(request);
            delete request;
        }
    }
    return response.getBody();
}