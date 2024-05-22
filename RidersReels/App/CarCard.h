#include <e3/Element.h>

class CarCard : public e3::Element 
{
public:
	CarCard(e3::Element* pParent = nullptr);
	
private:
	e3::Element* mImage1 = nullptr;
	e3::Element* mImage2 = nullptr;
	e3::Element* mImage3 = nullptr;
	e3::Element* mCard = nullptr;
};