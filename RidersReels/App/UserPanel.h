#pragma once

#include <e3/Element.h>
#include <e3/Text.h>

class UserPanel : public e3::Element 
{
public:
	UserPanel(e3::Element* pParent = nullptr);
	virtual void Render() override;

private:
	bool mFirstFrame = true;

	e3::Element* mAvatarWrap = nullptr;
	e3::Element* mAvatar = nullptr;
	e3::Element* mAvatarOverlay = nullptr;

	e3::Element* mNameWrap = nullptr;
	e3::Text* mName = nullptr;
	e3::Element* mNameOverlay = nullptr;

	e3::Element* mPhoneWrap = nullptr;
	e3::Element* mPhoneCont = nullptr;

};