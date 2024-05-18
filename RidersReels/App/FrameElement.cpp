#include "FrameElement.h"
#include "Timeline.h"

FrameElement::FrameElement(Element* pParent)
    : e3::Element(pParent)
    , mType(EFrameElementType::Element)
{
    SetWidth("100%");
    SetHeight("100%");
    /*mImageElement = new e3::Element();
    mImageElement->SetWidth("100%");
    mImageElement->SetHeight("100%");
    mImageElement->SetBackgroundImageFit(e3::EBackgroundSize::Cover);
    e3::Element::AddElement(mImageElement);*/
}

void FrameElement::SetScale(const glm::vec3 &direction, e3::ETransformAlignment transformAlignment)
{
    if (mElement)
        mElement->SetScale(direction, transformAlignment);
}

void FrameElement::SetRotation(float degrees, const glm::vec3 &direction, e3::ETransformAlignment transformAlignment)
{
    if (mElement)
        mElement->SetRotation(degrees, direction, transformAlignment);
}

void FrameElement::SetElement(e3::Element* pElement, EFrameElementType type)
{
    mType = type;
    mElement = pElement;
    AddElement(mElement);
}

void FrameElement::SetBeginTransition(Transition* pT) 
{
    pT->SetFrameElement(this);
    mBeginTransition = pT; 
}

void FrameElement::AddEffect(Effect* pE)
{
    pE->SetFrameElement(this);
    mEffects[pE->GetBeginTime()] = pE;
}

void FrameElement::Render() 
{
    if (mFirstFrame) 
    {
        mFirstFrame = false;
        if (mBeginTransition) mBeginTransition->Start();
    }

    long time = Timeline::Get()->GetTime();
    Effect* pEffect = nullptr;
    if (mEffects.size())
    {
        auto it = mEffects.begin();
        long t = it->first;
        pEffect = it->second;
        if (t <= time) 
        {
            pEffect->Start();
            mEffects.erase(it);
        }
    }

    e3::Element::Render();
}