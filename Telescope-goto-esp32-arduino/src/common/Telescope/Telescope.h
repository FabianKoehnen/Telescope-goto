#ifndef __Telescope_h__
#define __Telescope_h__

#include <memory>
#include "../EquatorialCoordinates/EquatorialCoordinates.h"
#include "../EquatorialCoordinates/Ra/Ra.h"
#include "../StepperManager/StepperManager.h"
#include "Position/Position.h"
#include "DateTime/DateTime.h"

class Telescope{
private:
    StepperManager& stepperManager;
    EquatorialCoordinates looksAt;
    Position currentPosition;
    DateTime currentDateTime;
public:
    Telescope(StepperManager&);
    EquatorialCoordinates& getLooksAt();
    bool lookAt(EquatorialCoordinates);
    Position& getCurrentPosition();
    DateTime& getCurrentDateTime();
    Constraints& getStepper1Constraints();
    Constraints& getStepper2Constraints();
    StepperManager& getStepperManager();
};



#endif