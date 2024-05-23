#include "MediaAnimatedText.h"
#include "Timeline.h"
#include <e3/Text.h>

MediaAnimatedText::MediaAnimatedText(e3::Element* pParent)
	: FrameElement(pParent)
{
	e3::Element* pElement = new e3::Element();
	pElement->SetWidth("100%");
	pElement->SetHeight("100%");
	SetElement(pElement, EFrameElementType::Element);

	e3::Element* pWrap = new e3::Element();
	pWrap->SetHeight(60);
	pWrap->SetWidth("100%");
	//pWrap->SetBackgroundColor(glm::vec4(0, 0, 255, 222));
	pElement->AddElement(pWrap);

	mTextWrap = new e3::Element();
	mTextWrap->SetBackgroundColor(glm::vec4(0, 0, 0, 255));
	mTextWrap->SetHeight(50);
	mTextWrap->SetPaddingLeft(10);
	mTextWrap->SetPaddingRight(10);
	pWrap->AddElement(mTextWrap);

	e3::Text* pR = new e3::Text();
	pR->SetText("R");
	pR->SetFontSize(40);
	pR->SetFontFamily("facon");
	pR->SetTextColor(glm::vec4(195, 251, 18, 255));
	mTextWrap->AddElement(pR);

	e3::Text* pWWW = new e3::Text();
	pWWW->SetText("WWW.RIDERS.AM");
	pWWW->SetMarginLeft(10);
	pWWW->SetFontFamily("open sans");
	pWWW->SetFontSize(24);
	pWWW->SetFontStyle(e3::EFontStyle::SemiBold);
	pWWW->SetTextColor(glm::vec4(255));
	mTextWrap->AddElement(pWWW);
	mTextWrap->SetOpacity(0);

	mOverlay = new e3::Element();
	mOverlay->SetWidth(400);
	mOverlay->SetHeight("100%");
	mOverlay->SetBackgroundColor(glm::vec4(255, 0, 0, 255));
	mOverlay->SetPositionType(e3::EPositionType::Absolute);
	mOverlay->SetTop(0);

	pWrap->AddElement(mOverlay);

}

void MediaAnimatedText::Render()
{
	if (mFirstFrame)
	{
		mFirstFrame = false;
		e3::Animation* pStart = new e3::Animation(this);
		pStart->Start(0.15, [this](float v) {
			mOverlay->SetScale(glm::vec3(v, 1, 1), e3::ETransformAlignment::Left);
		}, [this]() {
			mTextWrap->SetOpacity(1);
		});

		e3::Animation* pMove = new e3::Animation(this);
		pMove->Start(0.3, [this](float v) {
			mOverlay->SetTranslation(glm::vec3(v *60, 0, 0));
		}, []() {

		});
	}
	double time = Timeline::Get()->GetTime();
	if (!mEndAnimationIsRunning && mBeginTime + 200 < time) 
	{
		mEndAnimationIsRunning = true;
		e3::Animation* end = new e3::Animation(this);
		end->Start(.15, [this](float v) {
			mOverlay->SetScale(glm::vec3(1 - v, 1, 1), e3::ETransformAlignment::Right);
		}, []() {

		});
	}
	FrameElement::Render();
}