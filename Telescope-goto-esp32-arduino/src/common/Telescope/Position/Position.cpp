#include "Position.h"


Position::Position(std::string latitude, std::string longitude): latitude(latitude), longitude(longitude){}

Position Position::unknown(){
    return Position("", "");
}

void Position::setLatitude(std::string latitude){
    this->latitude = latitude;
}
void Position::setLongitude(std::string longitude){
    this->longitude = longitude;
}

std::string Position::getLatitude(){
    return this->latitude;
}
std::string Position::getLongitude(){
    return this->longitude;
}