#ifndef __Lx200RequestHandler_h__
#define __Lx200RequestHandler_h__

#include "../../../Telescope/Telescope.h"

#include "../Lx200Response/Lx200Response.h"
#include "../Lx200Request/Lx200Request.h"

class Lx200RequestHandler{
private:
    Telescope& telescope;
    Lx200Response ReturnGD();
    Lx200Response ReturnGR();
    Lx200Response ReturnGVP();
    Lx200Response ReturnGVN();
    Lx200Response ReturnGVD();
    Lx200Response ReturnGVT();
    Lx200Response ReturnGg();
    Lx200Response ReturnGt();
    Lx200Response ReturnGC();
    Lx200Response ReturnGL();
    Lx200Response ReturnGG();
    Lx200Response ReturnD();
    Lx200Response ReturnGW();
    Lx200Response ReturnQ();
    Lx200Response ReturnSr(Lx200Request request);
    Lx200Response ReturnSd(Lx200Request request);
public:
    Lx200RequestHandler(Telescope& telescope);
    Lx200Response handle(Lx200Request);
};

#endif