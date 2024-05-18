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

double Timeline::GetTime()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(mCurrentTime - mStartTime).count();
}

void Timeline::OnFrame()
{
    mCurrentTime = std::chrono::high_resolution_clock::now();    
}

void Timeline::Begin()
{
    mStartTime = std::chrono::high_resolution_clock::now();
}