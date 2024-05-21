#pragma once

#include "FrameElement.h"

class MediaCarInfoPanel : public FrameElement 
{
public:
	MediaCarInfoPanel(e3::Element* pParent = nullptr);
	virtual void Render() override;

private:
	bool mFirstFrame = true;
	e3::Element* mFrame;
};