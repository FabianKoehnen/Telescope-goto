#include "../common/Logger.h"

#include <Arduino.h>

Logger logger;

Logger::Logger(){
    Serial.begin(115200);
}

void Logger::LOG_I(std::string tag, std::string msg){
    Serial.printf("%s: %s\n", tag.c_str(), msg.c_str());
}

void Logger::LOG_I(std::string tag, int msg){
    Serial.printf("%s: %i\n", tag.c_str(), msg);
}

void Logger::LOG_E(std::string tag, std::string msg){
    //todo error log
}

void Logger::LOG_E(std::string tag, int msg){
    //todo error log
}