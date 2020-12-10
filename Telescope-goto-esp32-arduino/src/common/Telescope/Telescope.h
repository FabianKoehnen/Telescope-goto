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
    bool lookAt(Ra);
    bool lookAt(Dec);
    Position& getCurrentPosition();
    DateTime& getCurrentDateTime();
    // TODO: Setter hinzufügen und im AppProtocolRequestHandler diese benutzen
    Constraints& getStepper1Constraints();
    Constraints& getStepper2Constraints();
};



#endif