#include "StepperManager.h"

StepperManager::StepperManager(): stepper1(Stepper::stepper1()), stepper2(Stepper::stepper2()){}

bool StepperManager::moveVector(EquatorialCoordinates cords){
    bool isValid1 = this->getStepper1().isValid(cords.getRa().toArcsecond());
    bool isValid2 = this->getStepper2().isValid(cords.getDec().getArcseconds());
    return isValid1 && isValid2;
}


Stepper& StepperManager::getStepper1(){
    return this->stepper1;
}

Stepper& StepperManager::getStepper2(){
    return this->stepper2;
}