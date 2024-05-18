#include "FrameElement.h"

FrameElement::FrameElement(Element* pParent)
    : e3::Element(pParent)
{
    SetWidth("100%");
    SetHeight("100%");
    mImageElement = new e3::Element();
    mImageElement->SetWidth("100%");
    mImageElement->SetHeight("100%");
    mImageElement->SetBackgroundImageFit(e3::EBackgroundSize::Cover);
    e3::Element::AddElement(mImageElement);

    mOverlayElement = new e3::Element();
    mOverlayElement->SetWidth("100%");
    mOverlayElement->SetHeight("100%");
    mOverlayElement->SetPositionType(e3::EPositionType::Absolute);
    e3::Element::AddElement(mOverlayElement);
}

void FrameElement::SetImage(const std::string& path)
{
    mImageElement->SetBackgroundImageAsset(path);
}

void FrameElement::SetScale(const glm::vec3 &direction, e3::ETransformAlignment transformAlignment)
{
    mImageElement->SetScale(direction, transformAlignment);
}

void FrameElement::SetRotation(float degrees, const glm::vec3 &direction, e3::ETransformAlignment transformAlignment)
{
    mImageElement->SetRotation(degrees, direction, transformAlignment);
}

 void FrameElement::AddElement(e3::Element* pElement)
 {
    mOverlayElement->AddElement(pElement);
 }