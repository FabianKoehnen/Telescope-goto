#include "DateTime.h"

DateTime::DateTime(std::string time, std::string date, std::string utcOffset): time(time), date(date), utcOffset(utcOffset) {};

DateTime DateTime::unknown(){
    return DateTime("", "", "");
}

std::string DateTime::getTime(){
    return this->time;
}

std::string DateTime::getDate(){
    return this->date;
}

std::string DateTime::getUtcOffset(){
    return this->utcOffset;
}

void DateTime::setTime(std::string time){
    this->time = time;
}

void DateTime::setDate(std::string date){
    this->date = date;
}

void DateTime::setUtcOffset(std::string utcOffset){
    this->utcOffset = utcOffset;
}