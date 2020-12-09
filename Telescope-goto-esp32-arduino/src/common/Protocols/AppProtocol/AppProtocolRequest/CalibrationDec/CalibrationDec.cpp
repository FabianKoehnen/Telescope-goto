#include "CalibrationDec.h"


namespace AppRequests{

    CalibrationDec::CalibrationDec(std::string data){
        this->type = AppProtocolRequests::CalibrationDec;
        this->data = data;
    }

    std::string CalibrationDec::getRawData(){
        return this->data;
    }

}