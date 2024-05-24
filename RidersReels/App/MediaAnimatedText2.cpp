#include "MediaAnimatedText2.h"
#include <e3/Text.h>

MediaAnimatedText2::MediaAnimatedText2(int x, int y, const std::string& text, e3::Element* pParent) 
	: FrameElement(pParent)
{
	e3::Element* pElement = new e3::Element();
	pElement->SetWidth("100%");
	pElement->SetHeight("100%");
	SetElement(pElement, EFrameElementType::Element);

	mTextWrap = new e3::Element();
	mTextWrap->SetPositionType(e3::EPositionType::Absolute);
	mTextWrap->SetOverflow(e3::EOverflow::Hidden);
	mTextWrap->SetAlignItemsHor(e3::EAlignment::Start);
	mTextWrap->SetTop(y);
	mTextWrap->SetLeft(x);
	mTextWrap->SetHeight(30);
	mTextWrap->SetPaddingLeft(5);
	mTextWrap->SetPaddingRight(5);
	mTextWrap->SetBackgroundColor(glm::vec4(255));
	pElement->AddElement(mTextWrap);
	mTextWrap->UpdateGeometry();
	mText = new e3::Text();
	mText->SetText(text);
	mText->SetFontFamily("open sans");
	mText->SetFontSize(20);
	mText->SetFontStyle(e3::EFontStyle::SemiBold);
	mText->SetTextColor(glm::vec4(0, 0, 0, 255));
	mTextWrap->AddElement(mText);
}

void MediaAnimatedText2::Hide() 
{
	e3::Animation* pA = new e3::Animation(this);
	pA->Start(0.2, [this](float v) {
		mTextWrap->SetWidth((mText->GetGeometry().width ) * (1 - v));
		}, [this]() {
			mTextWrap->SetOpacity(0);
		});
}

void MediaAnimatedText2::Render()
{
	if (mFirstFrame) 
	{
		mFirstFrame = false;
		mTextWrap->UpdateGeometry();
		float w = mText->GetGeometry().width;
		e3::Animation* pA = new e3::Animation(this);
		pA->Start(0.5, [this](float v){
			mTextWrap->SetWidth((mText->GetGeometry().width + 10) * v);
		}, [](){
			
		});
		return;
	}
	float w = mText->GetGeometry().width;
	FrameElement::Render();
}
