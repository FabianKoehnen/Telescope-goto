#include "ConstraintBottom.h"


namespace AppRequests{

    ConstraintBottom::ConstraintBottom(std::string data){
        this->type = AppProtocolRequests::ConstraintBottom;
        this->data = data;
    }

    std::string ConstraintBottom::getRawData(){
        return this->data;
    }

}