#include "MediaCarCard.h"

MediaCarCard::MediaCarCard(e3::Element* pParent)
{
	e3::Element* pElement = new e3::Element();
	pElement->SetWidth("100%");
	pElement->SetHeight("100%");
	SetElement(pElement, EFrameElementType::Element);

	mCardWrap = new e3::Element();
	mCardWrap->SetWidth(135);
	mCardWrap->SetHeight(150);
	mCardWrap->SetAlignItemsVer(e3::EAlignment::Start);
	mCardWrap->SetPositionType(e3::EPositionType::Absolute);
	mCardWrap->SetLeft(60);
	mCardWrap->SetTop(60);
	mCardWrap->SetOverflow(e3::EOverflow::Hidden);
	pElement->AddElement(mCardWrap);

	e3::Element* pCarCard = new e3::Element();
	pCarCard->SetWidth(135);
	pCarCard->SetHeight(150);
	pCarCard->SetBackgroundColor(glm::vec4(255, 0, 0, 255));
	mCardWrap->AddElement(pCarCard);
	pCarCard->SetBackgroundImageAsset("RidersReels/img.jpg");
	pCarCard->SetBackgroundImageFit(e3::EBackgroundSize::Cover);
	pCarCard->SetBorderSize(2);
	pCarCard->SetBorderColor(glm::vec4(255));
	
	mCardOverlay = new e3::Element();
	mCardOverlay->SetWidth("100%");
	mCardOverlay->SetHeight("100%");
	mCardOverlay->SetBackgroundColor(glm::vec4(255));
	mCardOverlay->SetPositionType(e3::EPositionType::Absolute);
	mCardWrap->AddElement(mCardOverlay);

}

void MediaCarCard::Hide() 
{
	mFirstFrame = false;
	e3::Animation* pA = new e3::Animation(this);
	pA->Start(.4, [this](float v) {
		mCardWrap->SetHeight(150 * (1 - v));
		mCardOverlay->SetOpacity(v);
		}, []() {

	});
}

void MediaCarCard::Render()
{
	if (mFirstFrame) 
	{
		mFirstFrame = false;
		e3::Animation* pA = new e3::Animation(this);
		pA->Start(.4, [this](float v) {
			mCardWrap->SetHeight(150 * v);
			mCardOverlay->SetOpacity(1 - v);
		}, []() {
			
		});
	}
	FrameElement::Render();
}
