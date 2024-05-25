#pragma once

#include "FrameElement.h"
#include <e3/Text.h>
#include "UserPanel.h"

class MediaEnding : public FrameElement 
{
public:
	MediaEnding(e3::Element* pParent = nullptr);
	virtual void Render() override;
	void AnimateGooglePlay();
	void AnimateBuyButton();

private:
	e3::Text* mRiders = nullptr;
	bool mRidersAnimated = false;
	bool mEndAnimated = false;

	e3::Element* mBuyButtonWrap;
	e3::Element* mBuyButton;
	e3::Element* mBuyButtonOverlay;
	UserPanel* mUserPanel = nullptr;

	e3::Element* mGooglePlay = nullptr;
	e3::Element* mAppStore = nullptr;

};