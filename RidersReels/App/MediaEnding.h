#pragma once

#include "FrameElement.h"
#include <e3/Text.h>

class MediaEnding : public FrameElement 
{
public:
	MediaEnding(e3::Element* pParent = nullptr);

private:
	e3::Text* mRiders = nullptr;
	e3::Element* mBuyButton;
};