#pragma once

#include <e3/Element.h>

class Timeline 
{
public:
    static Timeline* sInstance;
    static Timeline* Get();

    Timeline();
    void Begin();
    void OnFrame();
    double GetTime();

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> mStartTime;
    std::chrono::time_point<std::chrono::high_resolution_clock> mCurrentTime;
};