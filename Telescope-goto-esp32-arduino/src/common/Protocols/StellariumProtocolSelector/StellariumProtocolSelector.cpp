#include "StellariumProtocolSelector.h"

StellariumProtocolSelector::StellariumProtocolSelector(){

}

std::string StellariumProtocolSelector::interpret(std::string msg){
    std::string lx200Match = "";
    lx200Match += '#';
    lx200Match += 0x06;

    if (msg == lx200Match){
        return "#";
    }

    return "";
}