#ifndef __ProtocolsManager_h__
#define __ProtocolsManager_h__

#include "../Logger.h"
#include "Lx200/Lx200.h"
#include "AppProtocol/AppProtocol.h"
#include "StellariumProtocolSelector/StellariumProtocolSelector.h"

class ProtocolsManager{
private:
    ComunicationInterface &comunicationInterface;
    AppProtocol &appProtocol;
    StellariumProtocolSelector &stellariumProtocolSelector;
    Lx200 &lx200;
public:
    ProtocolsManager(ComunicationInterface &comunicationInterface, AppProtocol &appProtocol, StellariumProtocolSelector &stellariumProtocolSelector, Lx200 &lx200);
    
    void loop();
};

#endif