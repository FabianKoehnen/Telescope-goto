#include "Lx200Response.h"

Lx200Response::Lx200Response(std::string body){
    this->setBody(body);
    this->shouldGetSend = true;
}

Lx200Response::Lx200Response(){
    this->body = "";
}

std::string Lx200Response::getBody(){
    return this->body;
}

void Lx200Response::setBody(std::string body){
    this->body = body + "#";
}

Lx200Response Lx200Response::GD(Dec dec){
    return Lx200Response(dec.toString());
}

Lx200Response Lx200Response::GR(Ra ra){
    return Lx200Response(ra.toString());
}

Lx200Response Lx200Response::null(){
    return Lx200Response();
}

Lx200Response Lx200Response::GVP(std::string firmwareName){
    return Lx200Response(firmwareName);
}

Lx200Response Lx200Response::GVN(std::string firmwareVersion){
    return Lx200Response(firmwareVersion);
}

Lx200Response Lx200Response::GVD(std::string firmwareDate){
    return Lx200Response(firmwareDate);
}

Lx200Response Lx200Response::GVT(std::string firmwareTime){
    return Lx200Response(firmwareTime);
}

Lx200Response Lx200Response::D(bool isSlewing){
    return Lx200Response(isSlewing? "": ""); //todo
}

Lx200Response Lx200Response::GW(std::string info){
    return Lx200Response(info); 
}

Lx200Response Lx200Response::Sr(bool isValid){
    return isValid ? Lx200Response("1"): Lx200Response("0"); 
}

Lx200Response Lx200Response::Sd(bool isValid){
    return isValid ? Lx200Response("1"): Lx200Response("0"); 
}
