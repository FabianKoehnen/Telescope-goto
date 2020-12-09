#ifndef __GPIO_h__
#define __GPIO_h__

enum GPIOState{
    High,
    Low
};

class GPIOPin{
private:
    int pin;
    GPIOState isHigh;
public:
    GPIOPin(int pin);
    ~GPIOPin();

    void high();
    void low();
    void toggle();
    GPIOState read();
};


#endif