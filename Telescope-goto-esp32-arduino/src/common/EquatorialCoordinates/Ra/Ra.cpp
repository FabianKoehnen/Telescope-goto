#include "Ra.h"
#include <stdexcept>

Ra::Ra(int seconds){
    if (this->seconds > 86400) throw std::runtime_error("ra value invalid");
    this->seconds = seconds;
}
Ra::Ra(int hours, int minutes, int seconds){
    this->seconds = 0;
    this->seconds += hours * 3600;
    this->seconds += minutes * 60;    
    this->seconds += seconds;
    if (this->seconds > 86400) throw std::runtime_error("ra value invalid");
}

Ra Ra::operator+ (const Ra& other){
 return Ra(seconds+other.seconds);
}

Ra Ra::operator- (const Ra& other){
 return Ra(seconds-other.seconds);
}

int Ra::toArcsecond(){
    return seconds*15;
}

//12:12:12
void Ra::update(std::string str){
    seconds = 0;
    seconds += atoi(str.substr(0,2).c_str()) * 3600;
    seconds += atoi(str.substr(3,2).c_str()) * 60;
    seconds += atoi(str.substr(6,2).c_str());
}


std::string Ra::toString(){
    char buffer[24] = {};
    int tmp = this->seconds;

    int hours = tmp / 3600;
    tmp -= hours * 3600;
    int minutes = tmp / 60;
    tmp -= minutes * 60;
    int seconds = tmp;
    sprintf(buffer, "%i:%i:%i", hours, minutes, seconds); // todo if < 10 add 0
    return buffer;
};

//12:12:12
Ra Ra::fromString(std::string str){
    int hours = atoi(str.substr(0,2).c_str());
    int minutes = atoi(str.substr(3,2).c_str());
    int seconds = atoi(str.substr(6,2).c_str());

    return Ra(hours, minutes, seconds);
}