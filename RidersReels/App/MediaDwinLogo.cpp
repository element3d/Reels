#include "MediaDwinLogo.h"

MediaDwinLogo::MediaDwinLogo(e3::Element* pParent)
{
    e3::Element* pElement = new e3::Element();
    pElement->SetWidth("100%");
    pElement->SetHeight("100%");
    SetElement(pElement, EFrameElementType::Element);

    mWrap = new e3::Element();
    mWrap->SetHeight(100);
    mWrap->SetMarginTop(500);
    mWrap->SetAlignItemsVer(e3::EAlignment::Start);
 //   mWrap->SetBackgroundColor()
    pElement->AddElement(mWrap);

    mLogo = new e3::Element();
    mLogo->SetBackgroundImageAsset("RidersReels/dwin.png");
    mLogo->SetWidth(120);
    mLogo->SetBackgroundImageFit(e3::EBackgroundSize::Cover);
    mWrap->AddElement(mLogo);

    mOverlay = new e3::Element();
    mOverlay->SetWidth("100%");
    mOverlay->SetHeight("100%");
    mOverlay->SetBackgroundColor(glm::vec4(255));
    mOverlay->SetPositionType(e3::EPositionType::Absolute);
    mOverlay->SetTop(0);
    mWrap->AddElement(mOverlay);
}

void MediaDwinLogo::Render() 
{
    if (mFirstFrame)
    {
        e3::Animation* pA = new e3::Animation(this);
        pA->Start(0.5, [this](float v){
            mOverlay->SetHeight((v) * 100);
            mOverlay->SetOpacity(1 - v);
            mLogo->SetOpacity(v);
        }, [](){
                    
        });
        mFirstFrame = false;
    }

    FrameElement::Render();
}