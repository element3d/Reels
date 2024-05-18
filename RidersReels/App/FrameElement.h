#pragma once

#include <e3/Element.h>

class FrameElement : public e3::Element 
{
public:
    FrameElement(Element* pParent = nullptr);
    void SetImage(const std::string& path);
    virtual void SetScale(const glm::vec3 &direction, e3::ETransformAlignment transformAlignment) override;
    virtual void SetRotation(float degrees, const glm::vec3 &direction, e3::ETransformAlignment transformAlignment) override;
    virtual void AddElement(e3::Element* pElement) override;
private:
    e3::Element* mImageElement = nullptr;
    e3::Element* mOverlayElement = nullptr;
};