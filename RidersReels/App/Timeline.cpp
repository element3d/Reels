#include "Timeline.h"

Timeline* Timeline::sInstance = nullptr;

Timeline* Timeline::Get() 
{
    if (!sInstance) sInstance = new Timeline();

    return sInstance;
}

Timeline::Timeline() 
{

}