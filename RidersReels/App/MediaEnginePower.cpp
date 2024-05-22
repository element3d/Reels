#include "MediaEnginePower.h"

MediaEnignePower::MediaEnignePower(e3::Element* pParent)
    : FrameElement(pParent)
{
    e3::Element* pElement = new e3::Element();
    pElement->SetWidth("100%");
    pElement->SetBackgroundColor(glm::vec4(0, 0, 0, 100));
    pElement->SetPaddingBottom(20);
    pElement->SetPaddingTop(20);
    SetElement(pElement, EFrameElementType::Element);

    mIcon = new e3::FontIcon();
    mIcon->SetWidth(40);
    mIcon->SetHeight(40);
    mIcon->SetFont("RidersReels/icons.ttf");
    mIcon->SetColor(glm::vec4(255));
    mIcon->SetCharcode("E902");
    pElement->AddElement(mIcon);

    mTitleWrap = new e3::Element();
    mTitleWrap->SetMarginLeft(10);
    pElement->AddElement(mTitleWrap);
    mTitle = new e3::Text();
    mTitle->SetText("ENGINE POWER");
    mTitle->SetFontSize(30);
    mTitle->SetTextColor(glm::vec4(255));
    mTitleWrap->AddElement(mTitle);

    e3::Element* pValueWrap = new e3::Element();
    pValueWrap->SetMarginLeft(50);
    pElement->AddElement(pValueWrap);

    e3::Text* pValue = new e3::Text();
    pValue->SetText("235");
    pValue->SetFontSize(30);
    pValue->SetTextColor(glm::vec4(255));
    pValueWrap->AddElement(pValue);

    e3::Element* pHpWrap = new e3::Element();
    pHpWrap->SetWidth(30);
    pHpWrap->SetHeight(30);
    pHpWrap->SetBackgroundColor(glm::vec4(0, 0, 0, 255));
    pValueWrap->AddElement(pHpWrap);

    e3::Text* pHp = new e3::Text();
    pHp->SetText("HP");
    pHp->SetFontSize(20);
    pHp->SetTextColor(glm::vec4(255));
    pHpWrap->AddElement(pHp);
}

void MediaEnignePower::Render()
{
    if (mFirstFrame) 
    {
    
        mFirstFrame = false;
    }

    FrameElement::Render();
}