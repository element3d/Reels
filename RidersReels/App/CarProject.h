#pragma once

#include <e3/Element.h>
#include "FrameElement.h"
#include <map>
#include "MediaCarCard.h"
#include "MediaAnimatedText2.h"
#include "MediaStars.h"

class CarProject
{
public:
	CarProject();
	e3::Element* GetElement() { return  mMain; }
    void Render();

private:
	e3::Element* mMain = nullptr;
	std::map<long, std::vector<FrameElement*>> mFrameElementPushMap;
	std::map<long, std::vector<FrameElement*>> mFrameElementPopMap;
    std::vector<e3::Element*> mLayers;

    MediaCarCard* mMediaCarCard = nullptr;
    bool mMediaCarCardHidden = false;
    MediaAnimatedText2* mMakeMedia = nullptr;
    bool mMakeMedialHidden = false;
    MediaAnimatedText2* mModelMedia = nullptr;
    bool mModelMedialHidden = false;
    MediaStars* mMediaStars = nullptr;
    bool mMediaStarsHidden = false;
};