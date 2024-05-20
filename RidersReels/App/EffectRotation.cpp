#include "EffectRotation.h"
#include "FrameElement.h"

EffectRotation::EffectRotation(float beginAngle, float endAngle, long beginTime, float duration)
	: Effect(beginTime, duration)
	, mBeginAngle(beginAngle)
	, mEndAngle(endAngle)
{

}

void EffectRotation::Start()
{
	mAnimation = new e3::Animation(mFrameElement);
	mAnimation->Start(mDuration, mBeginAngle, mEndAngle, [this](float v) {
		//mFrameElement->SetScale(glm::vec3(v, v, 1), e3::ETransformAlignment::Center);
		mFrameElement->SetRotation(v, glm::vec3(0, 0, 1), e3::ETransformAlignment::Center);
	}, [this]() {
			
	});
}