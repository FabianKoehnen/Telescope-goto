#include "CalibrationRa.h"


namespace AppRequests{

    CalibrationRa::CalibrationRa(std::string data){
        this->type = AppProtocolRequests::CalibrationRa;
        this->data = data;
    }

    std::string CalibrationRa::getRawData(){
        return this->data;
    }

}