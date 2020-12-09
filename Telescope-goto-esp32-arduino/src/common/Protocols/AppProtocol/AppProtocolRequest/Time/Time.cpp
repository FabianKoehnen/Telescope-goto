#include "Time.h"


namespace AppRequests{

    Time::Time(std::string data){
        this->type = AppProtocolRequests::Time;
        this->data = data;
    }

    std::string Time::getRawData(){
        return this->data;
    }

}