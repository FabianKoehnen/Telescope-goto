#ifndef __Position_h__
#define __Position_h__

#include <string>

class Position{
private:
    std::string latitude;
    std::string longitude;
public:
    Position(std::string latitude, std::string longitude);

    static Position unknown();

    void setLatitude(std::string);
    void setLongitude(std::string);

    std::string getLatitude();
    std::string getLongitude();
};

#endif