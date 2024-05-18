#pragma once

#include <e3/Element.h>

class FrameElement;
class Transition 
{
public: 
	Transition();

	virtual void Start() = 0;
	void SetFrameElement(FrameElement* pE) { mFrameElement = pE; }

protected:
	FrameElement* mFrameElement = nullptr;
	e3::Animation* mAnimation = nullptr;
};