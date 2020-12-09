#include "ProtocolsManager.h"
 
ProtocolsManager::ProtocolsManager(
    ComunicationInterface &comunicationInterface, 
    AppProtocol &appProtocol, 
    StellariumProtocolSelector &stellariumProtocolSelector,
    Lx200 &lx200): 
    comunicationInterface(comunicationInterface), 
    appProtocol(appProtocol), 
    stellariumProtocolSelector(stellariumProtocolSelector), 
    lx200(lx200){
}

void ProtocolsManager::loop(){
    if(this->comunicationInterface.available()){
        std::string buffer = this->comunicationInterface.recive();
        logger.LOG_I("=>", buffer);
        std::string response = "";

        if((buffer.length() != 1 && buffer[buffer.length() - 1] == '#') || buffer[0] == 0x06){
            response = this->lx200.interpret(buffer);
        }else if(buffer[buffer.length() - 1] == ';'){
            response = this->appProtocol.interpret(buffer);
        }else{
            response = this->stellariumProtocolSelector.interpret(buffer);
        }
        
        if(response != ""){
            logger.LOG_I("<=", response);
            this->comunicationInterface.write(response);
        }
    }
}


void ProtocolsManager::startTaskImpl(void* _this){
    while (true){
        ((ProtocolsManager*)_this)->loop();
    }
}
