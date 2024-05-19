#include "MediaAnimatedText2.h"
#include <e3/Text.h>

MediaAnimatedText2::MediaAnimatedText2(int x, int y, e3::Element* pParent) 
	: FrameElement(pParent)
{
	e3::Element* pElement = new e3::Element();
	pElement->SetWidth("100%");
	pElement->SetHeight("100%");
	SetElement(pElement, EFrameElementType::Element);

	e3::Element* pTextWrap = new e3::Element();
	pTextWrap->SetPositionType(e3::EPositionType::Absolute);
	pTextWrap->SetTop(y);
	pTextWrap->SetLeft(x);
	pTextWrap->SetHeight(30);
	pTextWrap->SetPaddingLeft(5);
	pTextWrap->SetPaddingRight(5);
	pTextWrap->SetBackgroundColor(glm::vec4(255));
	pElement->AddElement(pTextWrap);

	e3::Text* pText = new e3::Text();
	pText->SetText("MERCEDES BENZ");
	pText->SetFontSize(20);
	pText->SetFontStyle(e3::EFontStyle::Bold);
	pText->SetTextColor(glm::vec4(0, 0, 0, 255));
	pTextWrap->AddElement(pText);
}


