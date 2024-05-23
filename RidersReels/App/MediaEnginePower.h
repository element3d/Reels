#pragma once

#include "FrameElement.h"
#include <e3/FontIcon.h>
#include <e3/Text.h>

class MediaEnignePower : public FrameElement
{
public:
    MediaEnignePower(e3::Element* pParent = nullptr);
    virtual void Render() override;
    void AnimateTitle();
    void AnimateZoomOutValue();
    void AnimateValueText();
private:
    bool mFirstFrame = true;
    e3::FontIcon* mIcon = nullptr;
    e3::Element* mTitleWrap = nullptr;
    e3::Text* mTitle = nullptr;
    e3::Element* mValueWrap = nullptr;
    e3::Text* mValue = nullptr;
};