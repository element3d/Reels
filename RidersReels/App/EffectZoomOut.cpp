#include "EffectZoomOut.h"
#include "FrameElement.h"

EffectZoomOut::EffectZoomOut(float beginZoom, float endZoom, long beginTime, float duration)
	: Effect(beginTime, duration)
	, mBeginZoom(beginZoom)
	, mEndZoom(endZoom)
{

}

void EffectZoomOut::Start()
{
	mAnimation = new e3::Animation(mFrameElement);
	mAnimation->Start(mDuration, mBeginZoom, mEndZoom, [this](float v) {
		mFrameElement->SetScale(glm::vec3(v, v, 1), e3::ETransformAlignment::Center);
	//	mFrameElement->SetRotation(v * 10, glm::vec3(0, 0, 1), e3::ETransformAlignment::Center);
	}, [this]() {
			
	});
}