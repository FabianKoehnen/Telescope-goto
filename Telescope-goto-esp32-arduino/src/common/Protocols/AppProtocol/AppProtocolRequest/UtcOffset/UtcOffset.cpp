#include "UtcOffset.h"


namespace AppRequests{

    UtcOffset::UtcOffset(std::string data){
        this->type = AppProtocolRequests::UtcOffset;
        this->data = data;
    }

    std::string UtcOffset::getRawData(){
        return this->data;
    }

}