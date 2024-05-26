#include "MediaStars.h"

MediaStars::MediaStars(e3::Element* pPartent)
    : FrameElement(pPartent)
{
    e3::Element* pElement = new e3::Element();
    pElement->SetPositionType(e3::EPositionType::Absolute);
    pElement->SetTop(150);
    pElement->SetLeft(220);
    SetElement(pElement, EFrameElementType::Element);

    for (int i = 0; i < 5; i++) 
    {
        e3::Element* pStar = new e3::Element();
        pStar->SetWidth(45);
        pStar->SetHeight(45);
        pStar->SetBackgroundImageAsset("RidersReels/white.png");
        pStar->SetBackgroundImageFit(e3::EBackgroundSize::Cover);
        mStars.push_back(pStar);
        pStar->SetOpacity(0);
        pElement->AddElement(pStar);
    }

    mOverlay = new e3::Element();
    mOverlay->SetWidth("100%");
    mOverlay->SetHeight("100%");
    mOverlay->SetBackgroundColor(glm::vec4(255, 0, 84, 255));
    mOverlay->SetPositionType(e3::EPositionType::Absolute);
    mOverlay->SetOpacity(0);
    pElement->AddElement(mOverlay);
}

void MediaStars::Hide()
{
    mOverlay->SetOpacity(1);
    e3::Animation* pA = new e3::Animation(this);
    pA->Start(.1, 0, 1.0, [this](float v) {
        mOverlay->SetScale(glm::vec3(v, 1, 1), e3::ETransformAlignment::Left);
    }, [this]() {
        for (auto* pStar : mStars) pStar->SetOpacity(0);
        e3::Animation* pA = new e3::Animation(this);
        pA->Start(.1, 1, 0.0, [this](float v) {
            mOverlay->SetScale(glm::vec3(v, 1, 1), e3::ETransformAlignment::Right);
        }, [this]() {
       
        });
    });
}

void MediaStars::AnimateStar(int index)
{
    e3::Animation* pA = new e3::Animation(this);
    pA->Start(.06, 1.1, 1.0, [this, index](float v) {
        e3::Element* pStar = mStars[index];
        pStar->SetOpacity(1);
        pStar->SetScale(glm::vec3(v, v, 1), e3::ETransformAlignment::Center);
    }, [this, index]() {
        if (index == mStars.size() - 1) 
        {
            for (auto pS : mStars) pS->SetBackgroundImageAsset("RidersReels/gold.png");
        }
        if (index + 1 >= mStars.size()) return;
        AnimateStar(index + 1);
    });
}

void MediaStars::Render()
{
    if (mFirstFrame) 
    {
        mFirstFrame = false;
        AnimateStar(0);
    }
    
    FrameElement::Render();
}