#pragma once

#include "Transition.h"

class FrameElement;
class TransitionZoomOut : public Transition 
{
public:
	TransitionZoomOut(float beginZoom, float endZoom, float duratoin);
	virtual void Start() override;

private:
	float mBeginZoom = 1;
	float mEndZoom = 1;
	float mDuration = 0;
};