#pragma once

#include <e3/Element.h>
#include "Transition.h"
#include "Effect.h"

enum class EFrameElementType 
{
    Image,
    Text,
    Element
};

class FrameElement : public e3::Element 
{
public:
    FrameElement(Element* pParent = nullptr);
    virtual void SetScale(const glm::vec3 &direction, e3::ETransformAlignment transformAlignment) override;
    virtual void SetRotation(float degrees, const glm::vec3 &direction, e3::ETransformAlignment transformAlignment) override;
    void SetElement(e3::Element* pElement, EFrameElementType type);
    void SetBeginTime(long time) { mBeginTime = time; }
    void SetDuration(long ms) { mDuration = ms; }
    long GetDuration() { return mDuration; }
    void SetLayer(int l) { mLayer = l; }
    int GetLayer() { return mLayer; }
    void SetBeginTransition(Transition* pT);
    void SetEndTransition(Transition* pT);
    void AddEffect(Effect* pE);
    virtual void Render() override;

protected:
    e3::Element* mElement = nullptr;
    EFrameElementType mType;
    long mBeginTime = 0;
    long mDuration = 0;
    int mLayer = 0;
    Transition* mBeginTransition = nullptr;
    Transition* mEndTransition = nullptr;
    bool mFirstFrame = true;
    std::map<long, Effect*> mEffects;
};