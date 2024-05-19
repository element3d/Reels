#pragma once

#include <e3/Element.h>

class FrameElement;
class Transition 
{
public: 
	Transition(float duration) { mDuration = duration; }

	virtual void Start() = 0;
	void SetFrameElement(FrameElement* pE) { mFrameElement = pE; }
	float GetDuration() { return mDuration * 1000; }

protected:
	FrameElement* mFrameElement = nullptr;
	e3::Animation* mAnimation = nullptr;
	float mDuration = 0;

};