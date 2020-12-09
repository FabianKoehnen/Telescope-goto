#ifndef __Motor_h__
#define __Motor_h__

#include <math.h> 
#include "../../GPIOPin.h"
#include "Constraints/Constraints.h"
#include "../../StepperConfig.h"

class Stepper{
private:
    GPIOPin stepPin;
    GPIOPin dirPin;
    int stepsPerRotation;
    float gearRatio;
    Constraints constraints;
public:
    Stepper(GPIOPin stepPin, GPIOPin dirPin, int steps, int microstepping, float gearRatio, Constraints constraints);

    static Stepper stepper1();
    static Stepper stepper2();

    void changeDir(bool clockwise);
    bool moveDegree(float degree);
    bool moveSteps(int steps, bool clockwise);
    bool isValid(int arcseconds);
    Constraints& getConstraints();
};


#endif