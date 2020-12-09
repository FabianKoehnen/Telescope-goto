#ifndef __Logger_h__
#define __Logger_h__

#include <string>

class Logger{
public:
    Logger();
    virtual void LOG_I(std::string tag, std::string msg);
    virtual void LOG_I(std::string tag, int msg);
    virtual void LOG_E(std::string tag, std::string msg);
    virtual void LOG_E(std::string tag, int msg);
};

extern Logger logger;

#endif