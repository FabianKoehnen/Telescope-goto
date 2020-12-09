#include "Latitude.h"


namespace AppRequests{

    Latitude::Latitude(std::string data){
        this->type = AppProtocolRequests::Latitude;
        this->data = data;
    }

    std::string Latitude::getRawData(){
        return this->data;
    }

}