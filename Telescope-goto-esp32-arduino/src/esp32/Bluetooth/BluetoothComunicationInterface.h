#ifndef __BluetoothComunicationInterface_h__
#define __BluetoothComunicationInterface_h__

#include <Arduino.h>
#include "BluetoothSerial.h"
#include <string>
#include "../../common/ComunicationInterface/ComunicationInterface.h"

class BluetoothComunicationInterface: public ComunicationInterface{
    private:
        BluetoothSerial btSerial;
    public:
        BluetoothComunicationInterface();
        ~BluetoothComunicationInterface();
        void init(std::string deviceName);
        virtual bool available();
        virtual void write(std::string send);
        virtual std::string recive();
};

#endif