#pragma once

#include "FrameElement.h"

class MediaAnimatedText : public FrameElement 
{
public:
	MediaAnimatedText(Element* pParent = nullptr);

	virtual void Render() override;

private:
	bool mFirstFrame = true;
	bool mEndAnimationIsRunning = false;
};