#ifndef __MotorManager_h__
#define __MotorManager_h__

#include <Arduino.h>
#include <functional> 
#include "Stepper/Stepper.h"
#include "../EquatorialCoordinates/EquatorialCoordinates.h"
#include "../Logger.h"



class StepperManager{
private:
    Stepper stepper1;
    Stepper stepper2;
    TaskHandle_t stepper1Move;
    TaskHandle_t stepper2Move;
    bool endTask = false;


    class StepperMoveTaskData{
        public:
        StepperManager* stepperManager;
        Stepper& stepper;
        bool clockwise;
        StepperMoveTaskData(StepperManager* stepperManager, Stepper& stepper, const bool& clockwise);
    };

public:
    StepperManager();

    bool moveVector(EquatorialCoordinates cords);

    Stepper& getStepper1();
    Stepper& getStepper2();

    void moveMotorTask(StepperManager::StepperMoveTaskData& taskData);

    static void startMoveMoterTaskImpl(void*);

    void startMoving(int motor, const bool clockwise);
    void stopMoving(int motor);
};




#endif