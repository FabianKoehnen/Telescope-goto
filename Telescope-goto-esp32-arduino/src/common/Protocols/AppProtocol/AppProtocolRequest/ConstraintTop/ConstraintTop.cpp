#include "ConstraintTop.h"


namespace AppRequests{

    ConstraintTop::ConstraintTop(std::string data){
        this->type = AppProtocolRequests::ConstraintTop;
        this->data = data;
    }

    std::string ConstraintTop::getRawData(){
        return this->data;
    }

}