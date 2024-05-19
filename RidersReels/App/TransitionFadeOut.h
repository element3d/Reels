#pragma once

#include "Transition.h"

class FrameElement;
class TransitionFadeOut : public Transition 
{
public:
	TransitionFadeOut(float beginOpacity, float endOpacity, float duration);
	virtual void Start() override;

private:
	float mBeginOpacity = 1;
	float mEndOpacity = 1;
};