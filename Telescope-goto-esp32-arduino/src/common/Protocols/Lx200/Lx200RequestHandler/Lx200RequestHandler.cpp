#include "Lx200RequestHandler.h"

Lx200RequestHandler::Lx200RequestHandler(Telescope& telescope): telescope(telescope){
}

Lx200Response Lx200RequestHandler::handle(Lx200Request request){
    switch (request.getType()){
    case Lx200Requests::GD:
        return ReturnGD();
    case Lx200Requests::GR:
        return ReturnGR();
    case Lx200Requests::GVP:
        return ReturnGVP();
    case Lx200Requests::GVN:
        return ReturnGVN();
    case Lx200Requests::GVD:
        return ReturnGVD();
    case Lx200Requests::GVT:
        return ReturnGVT();
    case Lx200Requests::Gg:
        return ReturnGg();
    case Lx200Requests::Gt:
        return ReturnGt();
    case Lx200Requests::GC:
        return ReturnGC();
    case Lx200Requests::GL:
        return ReturnGL();
    case Lx200Requests::GG:
        return ReturnGG();
    case Lx200Requests::D:
        return ReturnD();
    case Lx200Requests::GW:
        return ReturnGW();
    case Lx200Requests::Q:
        return ReturnQ();
    case Lx200Requests::Sr:{
        return ReturnSr(request);
    }case Lx200Requests::Sd:{
        return ReturnSd(request);
    }case Lx200Requests::unknown:
        return Lx200Response::null();
    default:
        return Lx200Response::null();
        break;
    }
}

Lx200Response Lx200RequestHandler::ReturnGD(){
    return Lx200Response::GD(this->telescope.getLooksAt().getDec());
}

Lx200Response Lx200RequestHandler::ReturnGR(){
    return Lx200Response::GR(this->telescope.getLooksAt().getRa());
}

Lx200Response Lx200RequestHandler::ReturnGVP(){
    return Lx200Response::GVP("10micron GM4000HPS");
}

Lx200Response Lx200RequestHandler::ReturnGVN(){
    return Lx200Response::GVN("1234");
}

Lx200Response Lx200RequestHandler::ReturnGVD(){
    return Lx200Response::GVD("Oct 10 2020");
}

Lx200Response Lx200RequestHandler::ReturnGVT(){
    return Lx200Response::GVT("11:10:00");
}

Lx200Response Lx200RequestHandler::ReturnGg(){
    if(telescope.getCurrentPosition().getLongitude().empty() == false){
        return Lx200Response(telescope.getCurrentPosition().getLongitude());
    }else{
        return Lx200Response::null(); 
    }
}

Lx200Response Lx200RequestHandler::ReturnGt(){
    if(telescope.getCurrentPosition().getLatitude().empty() == false){
        return Lx200Response(telescope.getCurrentPosition().getLatitude());
    }else{
        return Lx200Response::null(); 
    }
}

Lx200Response Lx200RequestHandler::ReturnGC(){
    if(telescope.getCurrentDateTime().getDate().empty() == false){
        return Lx200Response(telescope.getCurrentDateTime().getDate());
    }else{
        return Lx200Response::null(); 
    }
}

Lx200Response Lx200RequestHandler::ReturnGL(){
    if(telescope.getCurrentDateTime().getTime().empty() == false){
        return Lx200Response(telescope.getCurrentDateTime().getTime());
    }else{
        return Lx200Response::null(); 
    }
}

Lx200Response Lx200RequestHandler::ReturnGG(){
    if(telescope.getCurrentDateTime().getUtcOffset().empty() == false){
        return Lx200Response(telescope.getCurrentDateTime().getUtcOffset());
    }else{
        return Lx200Response::null(); 
    }
}

Lx200Response Lx200RequestHandler::ReturnD(){
    return Lx200Response::D("#");
}

Lx200Response Lx200RequestHandler::ReturnGW(){
    return Lx200Response::GW("ATH");
}

Lx200Response Lx200RequestHandler::ReturnQ(){
    return Lx200Response::null();
}

Lx200Response Lx200RequestHandler::ReturnSd(Lx200Request request){
    bool isValidSr = this->telescope.lookAt(EquatorialCoordinates(Ra::fromString(request.getPayload()), this->telescope.getLooksAt().getDec()));
    return Lx200Response::Sr(isValidSr);
}

Lx200Response Lx200RequestHandler::ReturnSr(Lx200Request request){
    bool isValidSd = this->telescope.lookAt(EquatorialCoordinates(this->telescope.getLooksAt().getRa(), Dec::fromString(request.getPayload())));
    return Lx200Response::Sd(isValidSd);
}