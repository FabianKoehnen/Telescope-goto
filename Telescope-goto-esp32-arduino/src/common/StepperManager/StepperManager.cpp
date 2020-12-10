#include "StepperManager.h"

StepperManager::StepperManager(): stepper1(Stepper::stepper1()), stepper2(Stepper::stepper2()){}

bool StepperManager::moveVector(Ra ra){
    return this->getStepper1().isValid(ra.toArcsecond());
}

bool StepperManager::moveVector(Dec dec){
    return this->getStepper2().isValid(dec.getArcseconds());
}


Stepper& StepperManager::getStepper1(){
    return this->stepper1;
}

Stepper& StepperManager::getStepper2(){
    return this->stepper2;
}