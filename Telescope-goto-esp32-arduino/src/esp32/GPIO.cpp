#include <Arduino.h>
#include "../common/GPIOPin.h"

GPIOPin::GPIOPin(int pin): pin(pin){
    pinMode(this->pin, OUTPUT);
    this->low();
}

GPIOPin::~GPIOPin(){
    this->low();
}

void GPIOPin::high(){
    digitalWrite(this->pin, HIGH);
    this->isHigh = GPIOState::High;
}

void GPIOPin::low(){
    digitalWrite(this->pin, LOW);
    this->isHigh = GPIOState::Low;
}

void GPIOPin::toggle(){
    if(this->read() == GPIOState::High){
        this->low();
    }else{
        this->high();
    }
}

GPIOState GPIOPin::read(){
    return this->isHigh;
}