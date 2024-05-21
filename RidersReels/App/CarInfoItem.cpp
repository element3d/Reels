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
	mTitle->SetFontSize(20);
	mTitle->SetMarginLeft(10);
	mTitle->SetFontStyle(e3::EFontStyle::Bold);
	pLeft->AddElement(mTitle);
	AddElement(pLeft);

	mValue = new e3::Text();
	mValue->SetText(value);
	mValue->SetTextColor(glm::vec4(255));
	mValue->SetFontSize(20);
	mValue->SetMarginLeft(10);
	mValue->SetFontStyle(e3::EFontStyle::Bold);
	AddElement(mValue);
}