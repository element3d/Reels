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
        pElement->AddElement(pStar);
    }
}
