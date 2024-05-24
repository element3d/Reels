#include "CarInfoItem.h"

CarInfoItem::CarInfoItem(const std::string& title, const std::string& value, e3::Element* pParent)
	: e3::Element(pParent)
{
	SetWidth("100%");
	SetHeight(50);
	SetAlignItemsHor(e3::EAlignment::SpaceBetween);
	SetPaddingLeft(20);
	SetPaddingRight(20);

	e3::Element* pLeft = new e3::Element();

	mIcon = new e3::FontIcon();
	mIcon->SetFont("RidersReels/icons.ttf");
	mIcon->SetCharcode("E902");
	mIcon->SetColor(glm::vec4(255));
	mIcon->SetWidth(30);
	mIcon->SetHeight(30);
	pLeft->AddElement(mIcon);

	mTitle = new e3::Text();
	mTitle->SetText(title);
	mTitle->SetTextColor(glm::vec4(255));
	mTitle->SetFontSize(16);
	mTitle->SetMarginLeft(10);
	mTitle->SetFontFamily("open sans");
	mTitle->SetFontStyle(e3::EFontStyle::Bold);
	pLeft->AddElement(mTitle);
	AddElement(pLeft);


	mValueWrap = new e3::Element();
	// mValueWrap->SetBackgroundColor(glm::vec4(255));
	mValueWrap->SetBorderRadius(3);
	mValueWrap->SetOverflow(e3::EOverflow::Hidden);
	mValueWrap->SetHeight(35);

	AddElement(mValueWrap);

	mValueOverlay = new e3::Element();
	mValueOverlay->SetBackgroundColor(glm::vec4(255));
	mValueOverlay->SetBorderRadius(3);
	mValueOverlay->SetHeight(35);
//	mValueOverlay->SetPaddingRight(20);
	mValueOverlay->SetWidth("100%");
	mValueOverlay->SetHeight("100%");
	mValueOverlay->SetPositionType(e3::EPositionType::Absolute);
	mValueOverlay->SetOpacity(0);
	mValueWrap->AddElement(mValueOverlay);

	mValue = new e3::Text();
	mValue->SetText(value);
	mValue->SetTextColor(glm::vec4(0, 0, 0, 255));
	mValue->SetFontSize(16);
	// mValue->SetMarginLeft(10);
	mValue->SetFontFamily("open sans");
	mValue->SetFontStyle(e3::EFontStyle::Bold);
	mValueWrap->AddElement(mValue);
		mValue->SetMarginLeft(20);
	mValue->SetMarginRight(20);
	mTitle->SetOpacity(0);
}

void CarInfoItem::AnimateValue()
{
	mValueOverlay->SetOpacity(1);
	e3::Animation* pA = new e3::Animation(this);
	pA->Start(0.1, 0, 1, [this](float v){
		mValueOverlay->SetScale(glm::vec3(v, 1, 1), e3::ETransformAlignment::Left);	
	}, [](){
		
		
	});
}

void CarInfoItem::AnimateTitle()
{
	mTitle->SetOpacity(1);
	e3::Animation* pA = new e3::Animation(this);
	pA->Start(0.1, 30, 0, [this](float v){
		mTitle->SetTranslation(glm::vec3(v, 0, 1));	
	}, [this](){
		AnimateValue();
	});
}

void CarInfoItem::Render()
{
	if (mFirstFrame)
	{
		e3::Animation* pA = new e3::Animation(this);
		pA->Start(0.1, 1.1, 1, [this](float v){
			mIcon->SetScale(glm::vec3(v, v, 1), e3::ETransformAlignment::Center);	
		}, [this](){
			AnimateTitle();
		});
		mFirstFrame = false;
	}

	e3::Element::Render();
}