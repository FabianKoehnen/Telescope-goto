#include "Move.h"


namespace AppRequests{

    Move::Move(std::string data){
        this->type = AppProtocolRequests::Move;
        this->data = data;
    }

    std::string Move::getRawData(){
        return this->data;
    }

}