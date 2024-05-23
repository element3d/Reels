#include "UserPanel.h"

UserPanel::UserPanel(e3::Element* pParent) 
	: e3::Element(pParent)
{
	SetOrientation(e3::EOrientation::Vertical);
	SetPositionType(e3::EPositionType::Absolute);
	SetRight(200);

	mAvatar = new e3::Element();
	mAvatar->SetWidth(150);
	mAvatar->SetHeight(150);
	mAvatar->SetBackgroundColor(glm::vec4(0,0,0,255));
	mAvatar->SetBorderSize(2);
	mAvatar->SetBorderColor(glm::vec4(255));
	mAvatar->SetBorderRadius(glm::vec4(6));
	AddElement(mAvatar);

	mNameWrap = new e3::Element();
	mNameWrap->SetMarginTop(20);
	AddElement(mNameWrap);

	mName = new e3::Text();
	mName->SetText("NAREK");
	mName->SetTextColor(glm::vec4(255));
	mName->SetFontFamily("open sans");
	mName->SetFontSize(30);
	mName->SetFontStyle(e3::EFontStyle::SemiBold);
	mNameWrap->AddElement(mName);

	mPhoneWrap = new e3::Element();
	mPhoneWrap->SetHeight(40);
	AddElement(mPhoneWrap);

	e3::Element* pPhoneCont = new e3::Element();
	pPhoneCont->SetWidth(200);
	pPhoneCont->SetHeight(40);
	pPhoneCont->SetBackgroundColor(glm::vec4(255));
	pPhoneCont->SetBorderRadius(3);
	pPhoneCont->SetMarginTop(20);
	mPhoneWrap->AddElement(pPhoneCont);

	e3::Text* pPhone = new e3::Text();
	pPhone->SetText("098 828482");
	pPhone->SetFontFamily("open sans");
	pPhone->SetFontStyle(e3::EFontStyle::SemiBold);
	pPhone->SetTextColor(glm::vec4(0,0,0,255));
	pPhoneCont->AddElement(pPhone);
}

void UserPanel::Render() 
{
	e3::Element::Render();
}
