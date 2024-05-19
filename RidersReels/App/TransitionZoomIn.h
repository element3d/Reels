#pragma once

#include "Transition.h"

class FrameElement;
class TransitionZoomIn : public Transition 
{
public:
	TransitionZoomIn(float beginZoom, float endZoom, float duratoin);
	virtual void Start() override;

private:
	float mBeginZoom = 1;
	float mEndZoom = 1;
};