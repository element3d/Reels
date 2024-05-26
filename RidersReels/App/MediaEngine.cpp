#include "MediaEngine.h"

MediaEngine::MediaEngine(e3::Element* pParent)
	: FrameElement(pParent)
{
    e3::Element* pElement = new e3::Element();
    pElement->SetWidth("100%");
    pElement->SetBackgroundColor(glm::vec4(0, 0, 0, 150));
    pElement->SetPaddingBottom(20);
    pElement->SetPaddingTop(20);
    SetElement(pElement, EFrameElementType::Element);

    mIcon = new e3::FontIcon();
    mIcon->SetWidth(50);
    mIcon->SetHeight(50);
    mIcon->SetFont("RidersReels/icons.ttf");
    mIcon->SetColor(glm::vec4(255));
    mIcon->SetCharcode("E909");
    pElement->AddElement(mIcon);

    mTitleWrap = new e3::Element();
   // mTitleWrap->SetWidth(0);
    mTitleWrap->SetAlignItemsHor(e3::EAlignment::Start);
    mTitleWrap->SetOverflow(e3::EOverflow::Hidden);
    mTitleWrap->SetPaddingLeft(20);
    pElement->AddElement(mTitleWrap);
    mTitle = new e3::Text();
    mTitle->SetText("engine", true);
    mTitle->SetFontSize(30);
    mTitle->SetFontFamily("open sans");
    mTitle->SetFontStyle(e3::EFontStyle::SemiBold);
    mTitle->SetTextColor(glm::vec4(255));
    mTitleWrap->AddElement(mTitle);


    mValueWrap = new e3::Element();
  //  mValueWrap->SetVisibility(e3::EVisibility::Hidden);
    mValueWrap->SetBackgroundColor(glm::vec4(255));
    // mValueWrap->SetWidth(100);
    mValueWrap->SetHeight(40);
    // mValueWrap->SetWidth(0);
   // mValueWrap->SetOverflow(e3::EOverflow::Hidden);
    mValueWrap->SetMarginLeft(30);
    pElement->AddElement(mValueWrap);

    mValue = new e3::Text();
    mValue->SetWidth(250);
    mValue->SetText("2.4L, L4");
    mValue->SetFontSize(30);
    mValue->SetTextColor(glm::vec4(0, 0, 0, 255));
    mValue->SetFontFamily("open sans");
    mValue->SetFontStyle(e3::EFontStyle::SemiBold);
    mValueWrap->AddElement(mValue);

    e3::Element* pHpWrap = new e3::Element();
    pHpWrap->SetWidth(40);
    pHpWrap->SetHeight(40);
    pHpWrap->SetBackgroundColor(glm::vec4(0, 0, 0, 255));
   // mValueWrap->AddElement(pHpWrap);

    e3::Text* pHp = new e3::Text();
    pHp->SetText("HP");
    pHp->SetFontSize(20);
    pHp->SetTextColor(glm::vec4(255));
    pHp->SetFontFamily("open sans");
    pHp->SetFontStyle(e3::EFontStyle::SemiBold);
    pHpWrap->AddElement(pHp);

    mOverlay = new e3::Element();
    mOverlay->SetHeight(60);
    mOverlay->SetBackgroundColor(glm::vec4(255, 0, 84, 255));
    mOverlay->SetPositionType(e3::EPositionType::Absolute);
    mOverlay->SetWidth("50%");
    mOverlay->SetOpacity(0);
    pElement->AddElement(mOverlay);

    mIcon->SetOpacity(0);
    mTitleWrap->SetOpacity(0);
    mValueWrap->SetOpacity(0);
}

void MediaEngine::Render()
{
    if (mFirstFrame) 
    {
        mOverlay->SetOpacity(1);
        e3::Animation* pA = new e3::Animation(this);
        pA->Start(0.2, 0, 1, [this](float v) {
            mOverlay->SetScale(glm::vec3(v, 1, 1), e3::ETransformAlignment::Left);
            mElement->SetBackgroundColor(glm::vec4(0, 0, 0, 150 * (v)));

            }, [this]() {
                mIcon->SetOpacity(1);
                mTitleWrap->SetOpacity(1);
                mValueWrap->SetOpacity(1);
                e3::Animation* pA = new e3::Animation(this);
                pA->Start(0.2, 1, 0, [this](float v) {
                    mOverlay->SetScale(glm::vec3(v, 1, 1), e3::ETransformAlignment::Right);
                    }, []() {

                    });
            });
        mFirstFrame = false;
    }
    FrameElement::Render();
}