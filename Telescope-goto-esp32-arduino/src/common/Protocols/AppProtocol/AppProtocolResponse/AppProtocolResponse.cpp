#include "AppProtocolResponse.h"

AppProtocolResponse::AppProtocolResponse(std::string body){
    this->setBody(body);
}

std::string AppProtocolResponse::getBody(){
    return this->body;
}

void AppProtocolResponse::setBody(std::string body){
    this->body = ":" + body + ";";
}

AppProtocolResponse AppProtocolResponse::ok(){
    return AppProtocolResponse("ok");
}

AppProtocolResponse AppProtocolResponse::unknown(){
    return AppProtocolResponse("unknown");
}