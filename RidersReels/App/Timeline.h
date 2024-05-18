#pragma once

#include <e3/Element.h>

class Timeline 
{
public:
    static Timeline* sInstance;
    static Timeline* Get();

    Timeline();
};