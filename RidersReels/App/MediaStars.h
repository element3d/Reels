#pragma once

#include "FrameElement.h"

class MediaStars : public FrameElement 
{
public:
    MediaStars(e3::Element* pPartent = nullptr);
    virtual void Render() override;
    void AnimateStar(int index);
    void Hide();

private:
    bool mFirstFrame = true;
    std::vector<e3::Element*> mStars;
    e3::Element* mOverlay = nullptr;
};