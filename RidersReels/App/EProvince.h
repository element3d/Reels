#pragma once

#include <string>

class EProvince 
{
public:
    static const int None = -2;
    static const int All = -1;
    static const int Erevan = 0;
    static const int Armavir = 1;
    static const int Ararat = 2;
    static const int Kotayk = 3;
    static const int Shirak = 4;
    static const int Lorri = 5;
    static const int Gegharkunik = 6;
    static const int Syunik = 7;
    static const int Aragatsotn = 8;
    static const int Tavush = 9;
    static const int VayotsDzor = 10;
    static const int Artsakh = 11;
    static const int End = 11;

    static std::string ToString(int province) 
    {
        switch (province) 
        {
        case None:
            return "???";
        case All:
            return "all";
        case Erevan:
            return "erevan";
        case Armavir:
            return "armavir";
        case Ararat:
            return "ararat";
        case Kotayk:
            return "kotayk";
        case Shirak:
            return "shirak";
        case Lorri:
            return "lorri";
        case Gegharkunik:
            return "gegharkunik";
        case Syunik:
            return "syunik";
        case Aragatsotn:
            return "aragatsotn";
        case Tavush:
            return "tavush";
        case VayotsDzor:
            return "vayots_dzor";
        case Artsakh:
            return "artsakh";
        default:
            return "UNKNOWN";
        }
    }
};
