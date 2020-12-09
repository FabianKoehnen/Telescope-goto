#ifndef __MotorManager_h__
#define __MotorManager_h__

#include "Stepper/Stepper.h"
#include "../EquatorialCoordinates/EquatorialCoordinates.h"

class StepperManager{
private:
    Stepper stepper1;
    Stepper stepper2;
public:
    StepperManager();

    bool moveVector(EquatorialCoordinates cords);

    Stepper& getStepper1();
    Stepper& getStepper2();
};


#endif