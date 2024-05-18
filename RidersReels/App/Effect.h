#pragma once

#include <e3/Element.h>

class FrameElement;
class Effect 
{
public:
	Effect(long beginTime, float duration);
	virtual void Start() = 0;
	void SetFrameElement(FrameElement* pE) { mFrameElement = pE; }
	long GetBeginTime() { return mBeginTime; }
protected:
	FrameElement* mFrameElement = nullptr;
	long mBeginTime = 0;
	float mDuration = 0;
	e3::Animation* mAnimation = nullptr;
};