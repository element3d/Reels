#include <e3/Element.h>

class CarCard : public e3::Element 
{
public:
	CarCard(e3::Element* pParent = nullptr);
	virtual void Render() override;
	void AnimateImage2();
	void AnimateImage3();
	void AnimateImage4();
	
private:
	bool mFirstFrame = true;
	e3::Element* mImage1 = nullptr;
	e3::Element* mImage2 = nullptr;
	e3::Element* mImage3 = nullptr;
	e3::Element* mCard = nullptr;
};