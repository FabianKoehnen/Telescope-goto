#include "./Lx200.h"

Lx200::Lx200(Lx200RequestHandler &requestHandler) : requestHandler(requestHandler)
{
}

std::vector<std::string> Lx200::extractComand(std::string rawMsg)
{
    std::vector<std::string> comands;
    bool colect = false;
    int comandCounter = 0;
    std::string comand = "";

    for (int i = 0; i < rawMsg.length(); i++)
    {
        if (rawMsg[i] == 0x06)
        {
            comands.push_back("ACK");
            return comands;
        }
    }

    for (int i = 0; i < rawMsg.length(); i++)
    {
        if (rawMsg[i] == ':')
        {
            if (colect == false)
            {
                colect = true;
                comand = "";
                continue;
            }
        }
        else if (rawMsg[i] == '#')
        {
            if (colect == true)
            {
                colect = false;
                comandCounter++;
                comands.push_back(comand);
            }
        }
        if (colect == true)
        {
            comand += rawMsg[i];
        }
    }
    return comands;
}

std::string Lx200::getComandType(std::string comand)
{
    std::string type = "";
    bool collect = true;

    for (int i = 0; i < comand.length(); i++)
    {
        if ((comand[i] >= '+' && comand[i] <= ':') || comand[i] == '#')
        {
            return type;
        }
        if (collect == true)
        {
            type += comand[i];
        }
    }
    return type != "" ? type : "unknown";
}

std::string Lx200::getComandPayload(std::string comand)
{
    std::string payload = "";
    bool collect = false;

    for (int i = 0; i < comand.length(); i++)
    {
        if ((comand[i] >= '+' && comand[i] <= ':'))
        {
            collect = true;
        }
        if (collect == true)
        {
            payload += comand[i];
        }
    }
    return payload != "" ? payload : "unknown";
}

std::string Lx200::interpret(std::string msg)
{
    std::vector<std::string> comands = this->extractComand(msg);
    for (std::string comand : comands)
    {
        std::string type = this->getComandType(comand);
        std::string payload = this->getComandPayload(comand);
        //logger.LOG_I("comand", comand);
        //logger.LOG_I("type", type);
        //logger.LOG_I("payload", payload);
        if (comand == "ACK")
        { // Query alignment status
            return "P";
        }
        else if (type == "GR")
        {
            return this->requestHandler.handle(Lx200Request::GR()).getBody();
        }
        else if (type == "GD")
        {
            return this->requestHandler.handle(Lx200Request::GD()).getBody();
        }
        else if (type == "GVP")
        { // Product Name
            return this->requestHandler.handle(Lx200Request::GVP()).getBody();
        }
        else if (type == "GVN")
        { // Firmware version
            // return "1234#";
            return this->requestHandler.handle(Lx200Request::GVN()).getBody();
        }
        else if (type == "GVD")
        { // Firmware Date
            // return "Oct 10 2020#";
            return this->requestHandler.handle(Lx200Request::GVD()).getBody();
        }
        else if (type == "GVT")
        { // Firmware Time
            // return "11:10:00#";
            return this->requestHandler.handle(Lx200Request::GVT()).getBody();
        }
        else if (type == "Gg")
        { // Current Site Longitude
            // return "+100*01:20#";
            return this->requestHandler.handle(Lx200Request::Gg()).getBody();
        }
        else if (type == "Gt")
        { // Current Site Latitude
            // return "+100*01:20#";
            return this->requestHandler.handle(Lx200Request::Gt()).getBody();
        }
        else if (type == "GC")
        { // Get local date
            // return "10/13/20#";
            return this->requestHandler.handle(Lx200Request::GC()).getBody();
        }
        else if (type == "GL")
        { // Local Time in 24 hour format
            // return "11:21:10#";
            return this->requestHandler.handle(Lx200Request::GL()).getBody();
        }
        else if (type == "GG")
        { // UTC offset time
            // return "+02.0#";
            return this->requestHandler.handle(Lx200Request::GG()).getBody();
        }
        else if (type == "D")
        { // If slewing
            // return "#";
            return this->requestHandler.handle(Lx200Request::D()).getBody();
        }
        else if (type == "GW")
        { // Get track state / mount type
            // return "PT2#";
            return this->requestHandler.handle(Lx200Request::GW()).getBody();
        }
        else if (type == "Q")
        {
            return this->requestHandler.handle(Lx200Request::Q()).getBody();
        }
        else if (type == "Sr")
        {
            return this->requestHandler.handle(Lx200Request::Sr(payload)).getBody();
        }
        else if (type == "Sd")
        {
            return this->requestHandler.handle(Lx200Request::Sd(payload)).getBody();
        }
        else
        {
            return this->requestHandler.handle(Lx200Request::unknown()).getBody();
        }
    }
}