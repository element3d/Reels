#include "MediaEnding.h"
#include "CarCard.h"

MediaEnding::MediaEnding(e3::Element* pParent) 
	: FrameElement(pParent)
{
	e3::Element* pElement = new e3::Element();
	pElement->SetWidth("100%");
	pElement->SetHeight("100%");
	SetElement(pElement, EFrameElementType::Element);

	CarCard* pCard = new CarCard();
	pElement->AddElement(pCard);
}
