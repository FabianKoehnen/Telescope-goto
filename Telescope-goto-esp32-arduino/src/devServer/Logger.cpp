#include "../common/Logger.h"

#include <stdio.h>

Logger logger;

Logger::Logger(){}

void Logger::LOG_I(std::string tag, std::string msg){
    printf("%s: %s\n", tag.c_str(), msg.c_str());
}

void Logger::LOG_I(std::string tag, int msg){
    printf("%s: %i\n", tag.c_str(), msg);
}

void Logger::LOG_E(std::string tag, std::string msg){
    //todo error log
}

void Logger::LOG_E(std::string tag, int msg){
    //todo error log
}
