#ifndef __LX200Request_h__
#define __LX200Request_h__

#include <string>
#include "Lx200Requests.h"

class Lx200Request{
    protected:
        Lx200Requests type;
        std::string payload;
    public:
        Lx200Request(Lx200Requests type);
        Lx200Request(Lx200Requests type, std::string payload);
        Lx200Requests getType();
        std::string getPayload();

        static Lx200Request unknown();

        static Lx200Request GD();
        static Lx200Request GR();
        static Lx200Request GVD();
        static Lx200Request GVN();
        static Lx200Request GVP();
        static Lx200Request GVT();
        static Lx200Request Gg();
        static Lx200Request Gt();
        static Lx200Request GC();
        static Lx200Request GL();
        static Lx200Request GG();
        static Lx200Request D();
        static Lx200Request GW();
        static Lx200Request Q();
        static Lx200Request Sr(std::string payload);
        static Lx200Request Sd(std::string payload);

};

#endif