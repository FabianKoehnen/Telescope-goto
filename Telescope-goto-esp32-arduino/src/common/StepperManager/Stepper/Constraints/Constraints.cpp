#include "Constraints.h"

#include "../../../Logger.h"

Constraints::Constraints(): stepsAwayFromTopConstraint(-1), stepsAwayFromBottomConstraint(-1), isTopActive(false), isBottomActive(false){

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
    logger.LOG_I("moveSteps step", steps);
    logger.LOG_I("moveSteps top", this->stepsAwayFromTopConstraint);
    logger.LOG_I("moveSteps bottom", this->stepsAwayFromBottomConstraint);
    if(isCounterClockwise){
        this->stepsAwayFromTopConstraint = this->stepsAwayFromTopConstraint + steps;
        this->stepsAwayFromBottomConstraint = this->stepsAwayFromBottomConstraint - steps;
    }else{
        this->stepsAwayFromBottomConstraint = this->stepsAwayFromBottomConstraint + steps;
        this->stepsAwayFromTopConstraint = this->stepsAwayFromTopConstraint - steps;
    };
}