#ifndef __ComunicationInterface_h__
#define __ComunicationInterface_h__

#include <string>


class ComunicationInterface{
    public:
        virtual bool available() = 0;
        virtual void write(std::string send) = 0;
        virtual std::string recive() = 0;
};

#endif