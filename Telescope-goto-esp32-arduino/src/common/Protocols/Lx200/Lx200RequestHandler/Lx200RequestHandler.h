#ifndef __Lx200RequestHandler_h__
#define __Lx200RequestHandler_h__

#include "../../../Telescope/Telescope.h"

#include "../Lx200Response/Lx200Response.h"
#include "../Lx200Request/Lx200Request.h"

class Lx200RequestHandler{
private:
    Telescope& telescope;
public:
    Lx200RequestHandler(Telescope& telescope);
    Lx200Response handle(Lx200Request);
};

#endif