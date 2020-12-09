#ifndef __AppProtocolResponse_h__
#define __AppProtocolResponse_h__


#include <string>

class AppProtocolResponse{
    protected:
        std::string body;
        void setBody(std::string body);
    public:
        std::string getBody();
        AppProtocolResponse(std::string body);

        static AppProtocolResponse ok();
        static AppProtocolResponse unknown();
};

#endif