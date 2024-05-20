#pragma once

#include "Effect.h"

class EffectRotation : public Effect 
{
public:
	EffectRotation(float beginAngle, float endAngle, long beginTime, float duration);
	virtual void Start() override;

private:
	float mBeginAngle;
	float mEndAngle;
};