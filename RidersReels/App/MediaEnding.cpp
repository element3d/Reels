#include "MediaEnding.h"
#include "CarCard.h"
#include "UserPanel.h"
#include "Timeline.h"

MediaEnding::MediaEnding(e3::Element* pParent) 
	: FrameElement(pParent)
{
	e3::Element* pElement = new e3::Element();
	pElement->SetWidth("100%");
	pElement->SetHeight("100%");
	pElement->SetOrientation(e3::EOrientation::Vertical);
	SetElement(pElement, EFrameElementType::Element);

	mRiders = new e3::Text();
	mRiders->SetText("RIDERS");
	mRiders->SetFontFamily("facon");
	mRiders->SetFontSize(50);
	mRiders->SetTextColor(glm::vec4(195, 251, 18, 255));
	mRiders->SetMarginBottom(50);
	mRiders->SetOpacity(0);
	pElement->AddElement(mRiders);

	CarCard* pCard = new CarCard();
	pElement->AddElement(pCard);

	mBuyButton = new e3::Element();
	mBuyButton->SetWidth(200);
	mBuyButton->SetHeight(50);
	mBuyButton->SetBackgroundColor(glm::vec4(195, 251, 18, 255));
	mBuyButton->SetMarginTop(40);
	pElement->AddElement(mBuyButton);

	e3::Text* pBuyNow = new e3::Text();
	pBuyNow->SetText("BUY NOW");
	pBuyNow->SetTextColor(glm::vec4(0, 0, 0, 255));
	pBuyNow->SetFontFamily("open sans");
	pBuyNow->SetFontSize(20);
	pBuyNow->SetFontStyle(e3::EFontStyle::SemiBold);
	mBuyButton->SetVisibility(e3::EVisibility::Hidden);
	mBuyButton->AddElement(pBuyNow);

	UserPanel* pUserPanel = new UserPanel();
	pUserPanel->SetVisibility(e3::EVisibility::Hidden);
	pElement->AddElement(pUserPanel);
}

void MediaEnding::Render()
{
	double time = Timeline::Get()->GetTime();
	if (time - mBeginTime >= 500) 
	{
		mRiders->SetOpacity(1);
		e3::Animation* pA = new e3::Animation(this);
		pA->Start(.2, 1.4, 1, [this](float v) {
			mRiders->SetScale(glm::vec3(v, v, 1), e3::ETransformAlignment::Center);
		}, []() {});
	}

	FrameElement::Render();
}