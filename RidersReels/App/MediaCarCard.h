#pragma once

#include "FrameElement.h"

class MediaCarCard : public FrameElement 
{
public:
	MediaCarCard(Element* pParent = nullptr);
	virtual void Render() override;
	void Hide();
private:
	bool mFirstFrame = true;
	e3::Element* mCardWrap = nullptr;
	e3::Element* mCardOverlay = nullptr;
};