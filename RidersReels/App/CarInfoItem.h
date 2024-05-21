#pragma once

#include <e3/Element.h>
#include <e3/Text.h>
#include <e3/FontIcon.h>

class CarInfoItem : public e3::Element 
{
public:
	CarInfoItem(const std::string& title, const std::string& value, e3::Element* pParent = nullptr);
private:
	e3::Text* mTitle = nullptr;
	e3::FontIcon* mIcon = nullptr;
	e3::Text* mValue = nullptr;

};