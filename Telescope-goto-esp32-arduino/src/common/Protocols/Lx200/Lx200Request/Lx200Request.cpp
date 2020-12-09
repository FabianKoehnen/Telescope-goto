#include "Lx200Request.h"

Lx200Request::Lx200Request(Lx200Requests type){
    this->type = type;
    this->payload = "";
}

Lx200Request::Lx200Request(Lx200Requests type, std::string payload){
    this->type = type;
    this->payload = payload;
}

Lx200Requests Lx200Request::getType(){
    return this->type;
}

std::string Lx200Request::getPayload(){
    return this->payload;
}

Lx200Request Lx200Request::unknown(){
    return Lx200Request(Lx200Requests::unknown);
}

Lx200Request Lx200Request::GD(){
    return Lx200Request(Lx200Requests::GD);
}

Lx200Request Lx200Request::GR(){
    return Lx200Request(Lx200Requests::GR);
}

Lx200Request Lx200Request::GVD(){
    return Lx200Request(Lx200Requests::GVD);
}

Lx200Request Lx200Request::GVN(){
    return Lx200Request(Lx200Requests::GVN);
}

Lx200Request Lx200Request::GVP(){
    return Lx200Request(Lx200Requests::GVP);
}

Lx200Request Lx200Request::GVT(){
    return Lx200Request(Lx200Requests::GVT);
}

Lx200Request Lx200Request::Gg(){
    return Lx200Request(Lx200Requests::Gg);
}

Lx200Request Lx200Request::Gt(){
    return Lx200Request(Lx200Requests::Gt);
}

Lx200Request Lx200Request::GC(){
    return Lx200Request(Lx200Requests::GC);
}

Lx200Request Lx200Request::GL(){
    return Lx200Request(Lx200Requests::GL);
}

Lx200Request Lx200Request::GG(){
    return Lx200Request(Lx200Requests::GG);
}

Lx200Request Lx200Request::D(){
    return Lx200Request(Lx200Requests::D);
}

Lx200Request Lx200Request::GW(){
    return Lx200Request(Lx200Requests::GW);
}

Lx200Request Lx200Request::Sr(std::string payload){
    return Lx200Request(Lx200Requests::Sr, payload);
}

Lx200Request Lx200Request::Sd(std::string payload){
    return Lx200Request(Lx200Requests::Sd, payload);
}

Lx200Request Lx200Request::Q(){
    return Lx200Request(Lx200Requests::Q);
}