#pragma once

#include <string>

class EBodyType 
{
public:
    static const int None = -2;
    static const int All = -1;
    static const int Sedan = 0;
    static const int Coupe = 1;
    static const int Hatchback = 2;
    static const int Convertible = 3;
    static const int SUV = 4;
    static const int Pickup = 5;
    static const int Begin = 0;
    static const int End = EBodyType::Pickup;

    static std::string ToString(int make) {
        switch (make) {
        case None:
            return "???";
        case All:
            return "all";
        case Sedan:
            return "sedan";
        case Coupe:
            return "coupe";
        case Hatchback:
            return "hatchback";
        case Convertible:
            return "convertible";
        case SUV:
            return "suv";
        case Pickup:
            return "pickup";
        }

        return "???";
    }
};
