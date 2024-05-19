#include "TransitionZoomIn.h"
#include "FrameElement.h"

TransitionZoomIn::TransitionZoomIn(float beginZoom, float endZoom, float duratoin)
	: Transition(duratoin)
	, mBeginZoom(beginZoom)
	, mEndZoom(endZoom)
{

}

void TransitionZoomIn::Start() 
{
	mAnimation = new e3::Animation(mFrameElement);
	mAnimation->Start(mDuration, mBeginZoom, mEndZoom, [this](float v) {
		mFrameElement->SetScale(glm::vec3(v, v, 1), e3::ETransformAlignment::Center);
//		mFrameElement->SetRotation(v * 10, glm::vec3(0, 0, 1), e3::ETransformAlignment::Center);
	}, []() {
			
	});
}