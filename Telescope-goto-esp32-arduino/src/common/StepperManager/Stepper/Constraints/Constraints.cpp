#include "Constraints.h"


Constraints::Constraints(): stepsAwayFromTopConstraint(0), stepsAwayFromBottomConstraint(0), isTopActive(false), isBottomActive(false){

}

void Constraints::setTopConstraint(){
    this->isTopActive = true;
    this->stepsAwayFromTopConstraint = 0;
}

void Constraints::setBottomConstraint(){
    this->isBottomActive = true;
    this->stepsAwayFromBottomConstraint = 0;
}

bool Constraints::isActive(){
    return this->isBottomActive || this->isTopActive;
}

bool Constraints::isValid(int steps, bool isCounterClockwise){
    if(isCounterClockwise){
        if(this->isTopActive){
            return (this->stepsAwayFromTopConstraint - steps) > 0;
        }else{
            return true;
        }
    }else{
        if(this->isBottomActive){
            return (this->stepsAwayFromBottomConstraint - steps) > 0;
        }else{
            return true;
        }
    };
}

void Constraints::moveSteps(int steps, bool isCounterClockwise){
    if(isCounterClockwise){
        this->stepsAwayFromTopConstraint =- steps;
    }else{
        this->stepsAwayFromBottomConstraint =- steps;
    };
}