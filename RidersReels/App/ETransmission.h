#pragma once

#include <string>

class ETransmission 
{
public:
    static const int None = -2;
    static const int All = -1;
    static const int Automatic = 0;
    static const int Manual = 1;
    static const int Variator = 2;
    static const int End = ETransmission::Variator;

    static std::string ToString(int make) 
    {
        switch (make) 
        {
        case None:
            return "???";
        case All:
            return "all";
        case Automatic:
            return "automatic";
        case Manual:
            return "manual";
        case Variator:
            return "variator";
        }

        return "";
    }
};
