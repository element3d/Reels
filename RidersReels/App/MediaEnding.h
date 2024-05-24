#pragma once

#include "FrameElement.h"
#include <e3/Text.h>

class MediaEnding : public FrameElement 
{
public:
	MediaEnding(e3::Element* pParent = nullptr);
	virtual void Render() override;

private:
	e3::Text* mRiders = nullptr;
	bool mRidersAnimated = false;
	e3::Element* mBuyButton;
};