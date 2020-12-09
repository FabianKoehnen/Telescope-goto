#ifndef __EquatorialCoordinates_h__
#define __EquatorialCoordinates_h__

#include "Ra/Ra.h"
#include "Dec/Dec.h"

class EquatorialCoordinates{
private:
    Ra ra;
    Dec dec;
public:
    EquatorialCoordinates(Ra ra, Dec dec);
    static EquatorialCoordinates polarStar();

    EquatorialCoordinates operator+ (const EquatorialCoordinates& other);
    EquatorialCoordinates operator- (const EquatorialCoordinates& other);

    Ra getRa();
    Dec getDec();

    void updateRa(Ra);
    void updateDec(Dec);
};

#endif