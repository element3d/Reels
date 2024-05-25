#pragma once

#include <e3/Element.h>
#include <e3/Text.h>
#include <e3/FontIcon.h>

class CarInfoItem : public e3::Element 
{
public:
	CarInfoItem(const std::string& title, const std::string& value, const std::string& charcode, e3::Element* pParent = nullptr);
	virtual void Render() override;
	void AnimateTitle();
	void AnimateValue();

private:
	bool mFirstFrame = true;
	e3::Text* mTitle = nullptr;
	e3::FontIcon* mIcon = nullptr;
	e3::Text* mValue = nullptr;
	e3::Element* mValueWrap = nullptr;
	e3::Element* mValueOverlay = nullptr;
};