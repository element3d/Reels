#pragma once

#include "Effect.h"

class EffectZoomOut : public Effect 
{
public:
	EffectZoomOut(float beginZoom, float endZoom, long beginTime, float duration);
	virtual void Start() override;

private:
	float mBeginZoom;
	float mEndZoom;
};