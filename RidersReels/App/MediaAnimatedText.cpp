#include "MediaAnimatedText.h"
#include "Timeline.h"

MediaAnimatedText::MediaAnimatedText(e3::Element* pParent)
	: FrameElement(pParent)
{
	e3::Element* pElement = new e3::Element();
	pElement->SetWidth(400);
	pElement->SetHeight(50);
	pElement->SetBackgroundColor(glm::vec4(255, 0, 0, 255));
	SetElement(pElement, EFrameElementType::Element);

	
}

void MediaAnimatedText::Render()
{
	if (mFirstFrame) 
	{
		mFirstFrame = false;
		e3::Animation* pStart = new e3::Animation(this);
		pStart->Start(0.2, [this](float v) {
			mElement->SetScale(glm::vec3(v, 1, 1), e3::ETransformAlignment::Left);
		}, []() {

		});

		e3::Animation* pMove = new e3::Animation(this);
		pMove->Start(0.4, [this](float v) {
			mElement->SetTranslation(glm::vec3(v *30, 60, 0));
		}, []() {

		});
	}
	double time = Timeline::Get()->GetTime();
	if (!mEndAnimationIsRunning && mBeginTime + 200 < time) 
	{
		mEndAnimationIsRunning = true;
		e3::Animation* end = new e3::Animation(this);
		end->Start(.2, [this](float v) {
			mElement->SetScale(glm::vec3(1 - v, 1, 1), e3::ETransformAlignment::Right);
		}, []() {

		});
	}
	FrameElement::Render();
}