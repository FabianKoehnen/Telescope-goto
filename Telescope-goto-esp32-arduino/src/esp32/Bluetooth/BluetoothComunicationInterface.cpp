#include "BluetoothComunicationInterface.h"


BluetoothComunicationInterface::BluetoothComunicationInterface(){}

void BluetoothComunicationInterface::init(std::string deviceName){
    btSerial.begin(deviceName.c_str());
    btSerial.setTimeout(5);
}

BluetoothComunicationInterface::~BluetoothComunicationInterface(){}

bool BluetoothComunicationInterface::available(){
    return btSerial.available();
}

void BluetoothComunicationInterface::write(std::string send){
    btSerial.print(send.c_str());
}

std::string BluetoothComunicationInterface::recive(){
    // char buffer[1024];
    return btSerial.readString().c_str();
    // return buffer;
}