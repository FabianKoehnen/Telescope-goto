#include "Longitude.h"


namespace AppRequests{

    Longitude::Longitude(std::string data){
        this->type = AppProtocolRequests::Longitude;
        this->data = data;
    }

    std::string Longitude::getRawData(){
        return this->data;
    }

}