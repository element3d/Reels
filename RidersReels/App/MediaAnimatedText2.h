#pragma once

#include "FrameElement.h"
#include <e3/Text.h>

class MediaAnimatedText2 : public FrameElement 
{
public:
	MediaAnimatedText2(int x, int y, const std::string& text, e3::Element* pParent = nullptr);
	virtual void Render() override;

private:
	e3::Element* mTextWrap = nullptr;
	e3::Element* mTextOverlay = nullptr;
	e3::Text* mText = nullptr;
	bool mFirstFrame = true;
};