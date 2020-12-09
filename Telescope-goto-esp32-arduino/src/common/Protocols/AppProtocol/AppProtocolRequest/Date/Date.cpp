#include "Date.h"


namespace AppRequests{

    Date::Date(std::string data){
        this->type = AppProtocolRequests::Date;
        this->data = data;
    }

    std::string Date::getRawData(){
        return this->data;
    }

}