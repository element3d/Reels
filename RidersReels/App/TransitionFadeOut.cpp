#include "TransitionFadeOut.h"
#include "FrameElement.h"

TransitionFadeOut::TransitionFadeOut(float beginOpacity, float endOpacity, float duration)
	: Transition(duration)
	, mBeginOpacity(beginOpacity)
	, mEndOpacity(endOpacity)
{

}

void TransitionFadeOut::Start() 
{
	mAnimation = new e3::Animation(mFrameElement);
	mAnimation->Start(mDuration, mBeginOpacity, mEndOpacity, [this](float v) {
		mFrameElement->SetOpacity(v);
		printf("Opacity: %f\n", v);
	}, []() {
			
	});
}