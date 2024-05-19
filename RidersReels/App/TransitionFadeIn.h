#pragma once

#include "Transition.h"

class FrameElement;
class TransitionFadeIn : public Transition 
{
public:
	TransitionFadeIn(float beginOpacity, float endOpacity, float duration);
	virtual void Start() override;

private:
	float mBeginOpacity = 1;
	float mEndOpacity = 1;
};