#include "Stepper.h"
#include "../../Logger.h"

Stepper::Stepper(GPIOPin stepPin, GPIOPin dirPin, int steps, int microstepping, float gearRatio, Constraints constraints) : stepPin(stepPin), dirPin(dirPin), steps(steps), microstepping(microstepping), gearRatio(gearRatio), constraints(constraints)
{
}

Stepper Stepper::stepper1()
{
    return Stepper(GPIOPin(Stepper1_Step_Pin), GPIOPin(Stepper1_Dir_Pin), Stepper1_Steps, Stepper1_Microstepping, Stepper1_GearRatio, Constraints());
}

Stepper Stepper::stepper2()
{
    return Stepper(GPIOPin(Stepper2_Step_Pin), GPIOPin(Stepper2_Dir_Pin), Stepper2_Steps, Stepper2_Microstepping, Stepper2_GearRatio, Constraints());
}

void Stepper::changeDir(bool clockwise)
{
    clockwise ? this->dirPin.low() : this->dirPin.high();
}

bool Stepper::moveDegree(float degree)
{
    float degreePerStep = (this->steps * this->microstepping * this->gearRatio) / 360;
    int steps = round(degree * degreePerStep);
    if (degree < 0)
    {
        return this->moveSteps((steps * -1), false);
    }
    else
    {
        return this->moveSteps(steps, true);
    }
}

bool Stepper::moveSteps(int steps, bool clockwise)
{
    if (this->constraints.isActive())
    {
        bool isValid = this->constraints.isValid(steps, !clockwise);
        if (isValid)
        {
            this->changeDir(clockwise);
            for (int i = 0; i < steps; i++)
            {
                this->stepPin.toggle();
                this->stepPin.toggle();
            }
            this->constraints.moveSteps(steps, !clockwise);
        }
        return isValid;
    }
    else
    {
        this->changeDir(clockwise);
        for (int i = 0; i < steps; i++)
        {
            this->stepPin.toggle();
            this->stepPin.toggle();
        }
        return true;
    }
}

bool Stepper::isValid(int arcseconds)
{
    logger.LOG_I("arcseconds", arcseconds);
    float arcsecondPerStep = (float) (this->steps * this->microstepping) / (360 * 3600);
    int stepsToDrive = round(arcseconds * arcsecondPerStep);
    logger.LOG_I("arcsecondPerStep", arcsecondPerStep);
    logger.LOG_I("Stepper", stepsToDrive);
    if (arcseconds > 0)
    {
        return this->constraints.isValid(stepsToDrive, true);
    }
    else
    {
        return this->constraints.isValid((stepsToDrive * -1), false);
    }
}

Constraints &Stepper::getConstraints()
{
    return this->constraints;
}