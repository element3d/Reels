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
	mRiders->SetFontSize(80);
	mRiders->SetTextColor(glm::vec4(195, 251, 18, 255));
	mRiders->SetMarginBottom(50);
	mRiders->SetOpacity(0);
	pElement->AddElement(mRiders);

	CarCard* pCard = new CarCard();
	pElement->AddElement(pCard);

	mBuyButtonWrap = new e3::Element();
	mBuyButtonWrap->SetWidth(300);
	mBuyButtonWrap->SetHeight(60);
	mBuyButtonWrap->SetAlignItemsHor(e3::EAlignment::Start);
	mBuyButtonWrap->SetOpacity(0);
	pElement->AddElement(mBuyButtonWrap);

	mBuyButton = new e3::Element();
	mBuyButton->SetWidth(300);
	mBuyButton->SetHeight(60);
	mBuyButton->SetBackgroundColor(glm::vec4(195, 251, 18, 255));
	mBuyButton->SetMarginTop(40);
	mBuyButton->SetAlignItemsHor(e3::EAlignment::Start);
	mBuyButton->SetOverflow(e3::EOverflow::Hidden);
	mBuyButtonWrap->AddElement(mBuyButton);

	mBuyButtonOverlay = new e3::Element();
	mBuyButtonOverlay->SetWidth(300);
	mBuyButtonOverlay->SetHeight(60);
	mBuyButtonOverlay->SetPositionType(e3::EPositionType::Absolute);
	mBuyButtonOverlay->SetBackgroundColor(glm::vec4(255));

	e3::Text* pBuyNow = new e3::Text();
	pBuyNow->SetText("17,500 USD");
	pBuyNow->SetTextColor(glm::vec4(0, 0, 0, 255));
	pBuyNow->SetFontFamily("open sans");
	pBuyNow->SetFontSize(40);
	pBuyNow->SetMarginLeft(45);
	pBuyNow->SetFontStyle(e3::EFontStyle::SemiBold);
//	mBuyButton->SetVisibility(e3::EVisibility::Hidden);
	mBuyButton->AddElement(pBuyNow);
	mBuyButton->AddElement(mBuyButtonOverlay);

	mGooglePlay = new e3::Element();
	mGooglePlay->SetBackgroundImageAsset("RidersReels/play2.png");
	mGooglePlay->SetBackgroundImageFit(e3::EBackgroundSize::Cover);
	mGooglePlay->SetHeight(80);
	mGooglePlay->SetPositionType(e3::EPositionType::Absolute);
	mGooglePlay->SetLeft(180);
	mGooglePlay->SetTop(260);
	mGooglePlay->SetOpacity(0);
	pElement->AddElement(mGooglePlay);

	mAppStore = new e3::Element();
	mAppStore->SetBackgroundImageAsset("RidersReels/appstore.png");
	mAppStore->SetBackgroundImageFit(e3::EBackgroundSize::Cover);
	mAppStore->SetHeight(80);
	mAppStore->SetPositionType(e3::EPositionType::Absolute);
	mAppStore->SetLeft(180);
	mAppStore->SetTop(350);
	mAppStore->SetOpacity(0);
	pElement->AddElement(mAppStore);
}

void MediaEnding::AnimateBuyButton()
{
	mBuyButtonWrap->SetOpacity(1);
	e3::Animation* pA = new e3::Animation(this);
	pA->Start(1, [this](float v){
		mBuyButton->SetWidth(300 * v);	
		mBuyButtonOverlay->SetOpacity(1 - v);
	}, [this](){
	
	});
}

void MediaEnding::AnimateGooglePlay()
{
	mGooglePlay->SetOpacity(1);
	e3::Animation* pA = new e3::Animation(this);
	pA->Start(.1, 1.2, 1, [this](float v){
		mGooglePlay->SetScale(glm::vec3(v, v, 1), e3::ETransformAlignment::Center);	
	}, [this](){
		mAppStore->SetOpacity(1);
		e3::Animation* pA = new e3::Animation(this);
		pA->Start(.1, 1.2, 1, [this](float v){
			mAppStore->SetScale(glm::vec3(v, v, 1), e3::ETransformAlignment::Center);	
		}, [this](){
		
		});
	});
}

void MediaEnding::Render()
{
	double time = Timeline::Get()->GetTime();
	if (!mRidersAnimated && time - mBeginTime >= 500) 
	{
		mRidersAnimated = true;
		mRiders->SetOpacity(1);
		e3::Animation* pA = new e3::Animation(this);
		pA->Start(.2, 1.4, 1, [this](float v) {
			mRiders->SetScale(glm::vec3(v, v, 1), e3::ETransformAlignment::Center);
		}, [this]() {
			mUserPanel = new UserPanel();
			mElement->AddElement(mUserPanel);
			AnimateBuyButton();
		});
	}

	if (!mEndAnimated && time - mBeginTime >= 1500) 
	{
		mEndAnimated = true;
		AnimateGooglePlay();
	}

	FrameElement::Render();
}