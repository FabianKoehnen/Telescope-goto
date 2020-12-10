#include "Telescope.h"

Telescope::Telescope(StepperManager& stepperManager): stepperManager(stepperManager), looksAt(EquatorialCoordinates::polarStar()), currentPosition(Position::unknown()), currentDateTime(DateTime::unknown()){}

EquatorialCoordinates& Telescope::getLooksAt(){
    return this->looksAt;
}

bool Telescope::lookAt(Ra ra){
    return this->stepperManager.moveVector(this->looksAt.getRa() - ra);
}

bool Telescope::lookAt(Dec dec){
    return this->stepperManager.moveVector(this->looksAt.getDec() - dec);
}

Position& Telescope::getCurrentPosition(){
    return this->currentPosition;
}

DateTime& Telescope::getCurrentDateTime(){
    return this->currentDateTime;
}

Constraints& Telescope::getStepper1Constraints(){
    return this->stepperManager.getStepper1().getConstraints();
}

Constraints& Telescope::getStepper2Constraints(){
    return this->stepperManager.getStepper2().getConstraints();
}