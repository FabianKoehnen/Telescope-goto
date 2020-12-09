#ifndef __DateTime_h__
#define __DateTime_h__

#include <string>

class DateTime{
private:
    std::string time;
    std::string date;
    std::string utcOffset;
public:
    DateTime(std::string time, std::string date, std::string utcOffset);

    static DateTime unknown();

    std::string getTime();
    std::string getDate();
    std::string getUtcOffset();

    void setTime(std::string);
    void setDate(std::string);
    void setUtcOffset(std::string);
};

#endif