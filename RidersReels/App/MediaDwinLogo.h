#pragma once

#include "FrameElement.h"

class MediaDwinLogo : public FrameElement 
{
public: 
    MediaDwinLogo(e3::Element* pParent = nullptr);
    virtual void Render() override;

private:
    bool mFirstFrame = true;
    e3::Element* mWrap = nullptr;
    e3::Element* mLogo = nullptr;
    e3::Element* mOverlay = nullptr;
};