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

void StepperManager::moveMotorTask(StepperMoveTaskData& taskData){
    if(!taskData.stepper.moveSteps(1, taskData.clockwise)){
        logger.LOG_I("Stepper", "Error Limit");
    }
}

void StepperManager::startMoveMoterTaskImpl(void* _data){
    StepperMoveTaskData data = *((StepperMoveTaskData*)_data);
    for (;;){
        data.stepperManager->moveMotorTask(data);
        delay(50);
        if(data.stepperManager->endTask == true){
            vTaskDelete(NULL);
            delete _data;
        }
    }
}


void StepperManager::startMoving(int motor, const bool clockwise){
    this->endTask = false;

    void* taskData = new StepperMoveTaskData(this, (motor == 0? this->stepper1: this->stepper2), clockwise);
    
    xTaskCreatePinnedToCore(
        StepperManager::startMoveMoterTaskImpl,
        "comandLoop",
        8192,
        taskData,
        1,
        &this->stepper1Move,
        0
    );
}

void StepperManager::stopMoving(int motor){
    this->endTask = true;
}


StepperManager::StepperMoveTaskData::StepperMoveTaskData(StepperManager* stepperManager, Stepper& stepper, const bool& clockwise): stepperManager(stepperManager), stepper(stepper), clockwise(clockwise) {}