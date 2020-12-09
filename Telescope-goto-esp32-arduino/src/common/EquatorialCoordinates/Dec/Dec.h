#ifndef __Dec_h__
#define __Dec_h__

#include <string>
#include <stdlib.h>
#include <stdio.h>

class Dec{
private:
    int arcseconds;
public:
    Dec(char sign, int degrees, int arcminutes, int arcseconds);
    Dec(int arcseconds);
    static Dec fromString(std::string);

    Dec operator+ (const Dec& other);
    Dec operator- (const Dec& other);

    int getArcseconds();
    void update(std::string);
    std::string toString();
};

#endif