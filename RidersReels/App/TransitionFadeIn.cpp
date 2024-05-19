#include "TransitionFadeIn.h"
#include "FrameElement.h"

TransitionFadeIn::TransitionFadeIn(float beginOpacity, float endOpacity, float duration)
	: Transition(duration)
	, mBeginOpacity(beginOpacity)
	, mEndOpacity(endOpacity)
{

}

void TransitionFadeIn::Start() 
{
	mAnimation = new e3::Animation(mFrameElement);
	mAnimation->Start(mDuration, mBeginOpacity, mEndOpacity, [this](float v) {
		mFrameElement->SetOpacity(v);
	}, []() {
			
	});
}