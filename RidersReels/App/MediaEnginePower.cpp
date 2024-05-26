#include "MediaEnginePower.h"
#include "Timeline.h"

MediaEnignePower::MediaEnignePower(e3::Element* pParent)
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
    mIcon->SetCharcode("E902");
    pElement->AddElement(mIcon);

    mPowerWrap = new e3::Element();
    mPowerWrap->SetOrientation(e3::EOrientation::Vertical);
    mPowerWrap->SetPaddingLeft(10);
    mPowerWrap->SetAlignItemsHor(e3::EAlignment::Start);
    pElement->AddElement(mPowerWrap);

    mTitleWrap = new e3::Element();
    mTitleWrap->SetWidth(0);
    mTitleWrap->SetAlignItemsHor(e3::EAlignment::Start);
    mTitleWrap->SetOverflow(e3::EOverflow::Hidden);
    mPowerWrap->AddElement(mTitleWrap);
    mTitle = new e3::Text();
    mTitle->SetText("power", true);
    mTitle->SetFontSize(26);
    mTitle->SetFontFamily("open sans");
    mTitle->SetFontStyle(e3::EFontStyle::SemiBold);
    mTitle->SetTextColor(glm::vec4(255));
    mTitleWrap->AddElement(mTitle);

    e3::Element* pPowerLine = new e3::Element();
    pPowerLine->SetHeight(10);
    pPowerLine->SetMarginTop(4);
    pPowerLine->SetWidth("80%");
    pPowerLine->SetBackgroundColor(glm::vec4(255, 255, 255, 150));
    pPowerLine->SetAlignItemsHor(e3::EAlignment::Start);
    mPowerWrap->AddElement(pPowerLine);

    mPower = new e3::Element();
    mPower->SetHeight(10);
    // pPower->SetWidth("20%");
    mPower->SetBackgroundColor(glm::vec4(255, 0, 84, 255));
    mPower->SetOpacity(0);
    pPowerLine->AddElement(mPower);


    mValueWrap = new e3::Element();
    mValueWrap->SetVisibility(e3::EVisibility::Hidden);
    mValueWrap->SetBackgroundColor(glm::vec4(255));
   // mValueWrap->SetWidth(100);
    mValueWrap->SetHeight(40);
   // mValueWrap->SetWidth(0);
    mValueWrap->SetOverflow(e3::EOverflow::Hidden);
   // pValueWrap->SetMarginLeft(50);
    pElement->AddElement(mValueWrap);

    mValue = new e3::Text();
    mValue->SetWidth(80);
    mValue->SetText("150");
    mValue->SetFontSize(30);
    mValue->SetTextColor(glm::vec4(0, 0, 0, 255));
    mValue->SetFontFamily("open sans");
    mValue->SetFontStyle(e3::EFontStyle::SemiBold);
    mValueWrap->AddElement(mValue);

    e3::Element* pHpWrap = new e3::Element();
    pHpWrap->SetWidth(40);
    pHpWrap->SetHeight(40);
    pHpWrap->SetBackgroundColor(glm::vec4(0, 0, 0, 255));
    mValueWrap->AddElement(pHpWrap);

    e3::Text* pHp = new e3::Text();
    pHp->SetText("HP");
    pHp->SetFontSize(20);
    pHp->SetTextColor(glm::vec4(255));
    pHp->SetFontFamily("open sans");
    pHp->SetFontStyle(e3::EFontStyle::SemiBold);
    pHpWrap->AddElement(pHp);

    mEndOverlay = new e3::Element();
    mEndOverlay->SetHeight(60);
    mEndOverlay->SetBackgroundColor(glm::vec4(255, 0, 84, 255));
    mEndOverlay->SetPositionType(e3::EPositionType::Absolute);
    mEndOverlay->SetWidth("50%");
    mEndOverlay->SetOpacity(0);
    pElement->AddElement(mEndOverlay);
}

void MediaEnignePower::AnimateEnding()
{
    mEndOverlay->SetOpacity(1);
    e3::Animation* pA = new e3::Animation(this);
    pA->Start(0.2, 0, 1, [this](float v){
        mEndOverlay->SetScale(glm::vec3(v, 1, 1), e3::ETransformAlignment::Left);

    }, [this](){
        mIcon->SetOpacity(0);
        mPowerWrap->SetOpacity(0);
        mValueWrap->SetOpacity(0);
        e3::Animation* pA = new e3::Animation(this);
        pA->Start(0.2, 1, 0, [this](float v){
            mEndOverlay->SetScale(glm::vec3(v, 1, 1), e3::ETransformAlignment::Right);
            mElement->SetBackgroundColor(glm::vec4(0, 0, 0, 150 * (v)));
        }, [](){
            
        });
    });
}

void MediaEnignePower::AnimateValueText()
{
    mPower->SetOpacity(1);
    e3::Animation* pA = new e3::Animation(this);
    pA->Start(0.4, 150, 180, [this](float v){
        mValue->SetText(std::to_string(int(v)));
        mPower->SetWidth((v - 150) * 1);
    }, [](){
            
    });
}

void MediaEnignePower::AnimateZoomOutValue()
{
    mValueWrap->SetVisibility(e3::EVisibility::Visible);
    e3::Animation* pA = new e3::Animation(this);
    pA->Start(0.2, 1.5, 1.0, [this](float v){
        mValueWrap->SetScale(glm::vec3(v, v, 1), e3::ETransformAlignment::Center);

    }, [this](){
        AnimateValueText();
    });
}

void MediaEnignePower::AnimateTitle()
{
    e3::Animation* pA = new e3::Animation(this);
    pA->Start(0.4, 0.0, 240.0, [this](float v){
        mTitleWrap->SetWidth(v);

    }, [this](){
            AnimateZoomOutValue();
    });
}

void MediaEnignePower::Render()
{
    if (mFirstFrame) 
    {
        e3::Animation* pA = new e3::Animation(this);
        pA->Start(0.1, 4.0, 1.0, [this](float v){
            mIcon->SetScale(glm::vec3(v, v, 1), e3::ETransformAlignment::Center);        
      //      mElement->SetBackgroundColor(glm::vec4(0, 0, 0, (1-v/4) * 120));

        }, [this](){
            AnimateTitle();
        });
        mFirstFrame = false;
    }

    double time = Timeline::Get()->GetTime();
    if (!mEndingAnimated && time - mBeginTime >= 2200)
    {
        mEndingAnimated = true;
        AnimateEnding();
    }

    FrameElement::Render();
}