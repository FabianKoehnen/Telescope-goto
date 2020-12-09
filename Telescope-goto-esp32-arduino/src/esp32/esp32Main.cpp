#include "./esp32/Bluetooth/BluetoothComunicationInterface.h"
#include "../common/Protocols/ProtocolsManager.h"

#include "../common/StepperManager/StepperManager.h"

#include "../common/Telescope/Telescope.h"

#include "../common/EquatorialCoordinates/EquatorialCoordinates.h"

#include "../common/Protocols/Lx200/Lx200RequestHandler/Lx200RequestHandler.h"
#include "../common/Protocols/Lx200/Lx200.h"

#include "../common/Protocols/AppProtocol/AppProtocol.h"
#include "../common/Protocols/AppProtocol/AppProtocolRequestHandler/AppProtocolRequestHandler.h"

#include "../common/Protocols/StellariumProtocolSelector/StellariumProtocolSelector.h"


BluetoothComunicationInterface comunicationInterface;

StepperManager stepperManager;

Telescope telescope(stepperManager);

Lx200RequestHandler lx200RequestHandler(telescope);
AppProtocolRequestHandler appProtocolRequestHandler(telescope);

Lx200 lx200(lx200RequestHandler);
AppProtocol appProtocol(appProtocolRequestHandler);
StellariumProtocolSelector stellariumProtocolSelector;

ProtocolsManager protocolsManager(comunicationInterface, appProtocol, stellariumProtocolSelector, lx200);
bool isProtocolSelected = false;

TaskHandle_t comandLoop;

void setup(){
    comunicationInterface.init("Teleskop GoTo");
    xTaskCreatePinnedToCore(
        protocolsManager.startTaskImpl,
        "comandLoop",
        8192,
        &protocolsManager,
        1,
        &comandLoop,
        1
    );
}

void loop(){ 
    delay(100000);
    // protocolsManager.loop();
}

