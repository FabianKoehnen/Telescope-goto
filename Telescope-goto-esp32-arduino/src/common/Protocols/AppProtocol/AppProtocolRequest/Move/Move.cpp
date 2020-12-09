#include "Move.h"


namespace AppRequests{

    Move::Move(std::string data){
        this->type = AppProtocolRequests::Move;
        this->data = data;
        this->segments[0] = "";
        this->segments[1] = "";
        this->segments[2] = "";

        int count = 0;
        for (int i = 0; i < data.length(); i++){
        
            if(data[i] == ':'){
                count++;
                continue;
            }

            this->segments[count] += data[i];
        }
        
    }

    std::string Move::getRawData(){
        return this->data;
    }

    int Move::getMotor(){
        return atoi(segments[0].c_str());
    }

    bool Move::isOn(){
        return this->segments[1] == "on";
    }

    bool Move::isClockwise(){
        return this->segments[2] == "clockwise";
    }

}