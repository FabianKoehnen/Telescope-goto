#include "../common/GPIOPin.h"

GPIOPin::GPIOPin(int pin): pin(pin){
    this->low();
}

GPIOPin::~GPIOPin(){
    this->low();
}

void GPIOPin::high(){
    this->isHigh = GPIOState::High;
}

void GPIOPin::low(){
    this->isHigh = GPIOState::Low;
}

void GPIOPin::toggle(){
    if(this->isHigh == GPIOState::High){
        this->low();
    }else{
        this->high();
    }
}

GPIOState GPIOPin::read(){
    return this->isHigh;
}