#include "Dec.h"
#include <stdexcept>
    
Dec::Dec(int arcseconds):arcseconds(arcseconds){
    if (this->arcseconds > 648000 || this->arcseconds < -648000) throw std::runtime_error("dec value invalid");
    this->arcseconds=arcseconds;
}
    
Dec::Dec(char sign, int degrees, int arcminutes, int arcseconds){
    this->arcseconds = 0;
    this->arcseconds += degrees * 3600;
    this->arcseconds += arcminutes * 60;
    this->arcseconds += arcseconds;
    this->arcseconds = sign == '-'? this->arcseconds *-1: this->arcseconds;
    if (this->arcseconds > 648000 || this->arcseconds < -648000) throw std::runtime_error("dec value invalid");
}

Dec Dec::operator+ (const Dec& other){
 return Dec(arcseconds+other.arcseconds);
}

Dec Dec::operator- (const Dec& other){
 return Dec(arcseconds-other.arcseconds);
}

int Dec::getArcseconds(){
    return arcseconds;
}

//-22*27:57
void Dec::update(std::string str){
    arcseconds = 0;
    arcseconds += atoi(str.substr(1, 2).c_str()) * 3600;
    arcseconds += atoi(str.substr(4, 2).c_str()) * 60;
    arcseconds += atoi(str.substr(7, 2).c_str());
    arcseconds = str[0] == '-'? arcseconds *-1: arcseconds;
}


std::string Dec::toString(){
    char buffer[24] = {};
    int tmp = this->arcseconds;

    int sign = arcseconds < 0 ? '-': '+';
    int degrees = tmp / 3600;
    tmp -= degrees * 3600;
    int arcminutes = tmp / 60;
    tmp -= arcminutes * 60;
    int arcseconds = tmp;

    sprintf(buffer, "%c%i*%i:%i", sign, degrees, arcminutes, arcseconds); // todo if < 10 add 0
    return buffer;
}

//-22*27:57
Dec Dec::fromString(std::string str){
    char sign = str[0];
    int degrees = atoi(str.substr(1, 2).c_str());
    int arcminutes = atoi(str.substr(4, 2).c_str());
    int arcseconds = atoi(str.substr(7, 2).c_str());

    return Dec(sign, degrees, arcminutes, arcseconds);
}