#include "Lx200RequestHandler.h"

Lx200RequestHandler::Lx200RequestHandler(Telescope& telescope): telescope(telescope){
}

Lx200Response Lx200RequestHandler::handle(Lx200Request request){ // todo cases in eigene methoden auslagern 
    switch (request.getType()){
    case Lx200Requests::GD:
        return Lx200Response::GD(this->telescope.getLooksAt().getDec());
    case Lx200Requests::GR:
        return Lx200Response::GR(this->telescope.getLooksAt().getRa());
    case Lx200Requests::GVP:
        return Lx200Response::GVP("10micron GM4000HPS");
    case Lx200Requests::GVN:
        return Lx200Response::GVN("1234");
    case Lx200Requests::GVD:
        return Lx200Response::GVD("Oct 10 2020");
    case Lx200Requests::GVT:
        return Lx200Response::GVT("11:10:00");
    case Lx200Requests::Gg:
        if(telescope.getCurrentPosition().getLongitude().empty() == false){
            return Lx200Response(telescope.getCurrentPosition().getLongitude());
        }else{
           return Lx200Response::null(); 
        }
    case Lx200Requests::Gt:
        if(telescope.getCurrentPosition().getLatitude().empty() == false){
            return Lx200Response(telescope.getCurrentPosition().getLatitude());
        }else{
           return Lx200Response::null(); 
        }
    case Lx200Requests::GC:
        if(telescope.getCurrentDateTime().getDate().empty() == false){
            return Lx200Response(telescope.getCurrentDateTime().getDate());
        }else{
           return Lx200Response::null(); 
        }
    case Lx200Requests::GL:
        if(telescope.getCurrentDateTime().getTime().empty() == false){
            return Lx200Response(telescope.getCurrentDateTime().getTime());
        }else{
           return Lx200Response::null(); 
        }
    case Lx200Requests::GG:
        if(telescope.getCurrentDateTime().getUtcOffset().empty() == false){
            return Lx200Response(telescope.getCurrentDateTime().getUtcOffset());
        }else{
           return Lx200Response::null(); 
        }
    case Lx200Requests::D:
        return Lx200Response::D("#");
    case Lx200Requests::GW:
        return Lx200Response::GW("ATH");
    case Lx200Requests::Q:
        return Lx200Response::null();
    case Lx200Requests::Sr:{
        bool isValidSr = this->telescope.lookAt(EquatorialCoordinates(Ra::fromString(request.getPayload()), this->telescope.getLooksAt().getDec()));
        return Lx200Response::Sr(isValidSr);
    }case Lx200Requests::Sd:{
        bool isValidSd = this->telescope.lookAt(EquatorialCoordinates(this->telescope.getLooksAt().getRa(), Dec::fromString(request.getPayload())));
        return Lx200Response::Sd(isValidSd);
    }case Lx200Requests::unknown:
        return Lx200Response::null();
    default:
        return Lx200Response::null();
        break;
    }
}