#ifndef __Application_H__
#define __Application_H__

#include "private/ApplicationBase.h"
#include "FrameElement.h"
#include <map>
#include "MediaCarCard.h"
#include "MediaAnimatedText2.h"
#include "MediaStars.h"
#include "CarProject.h"

class Application : public ApplicationBase
{
public:
    Application(const std::string& applicationName, e3::EE3OS os, e3::EE3Target target, e3::Size2i windowSize, e3::Size2i resolution);

    void AnimateElement(e3::Element* e, e3::Element* next);
public:
	void OnResize(float width, float height) override;
    virtual void Render() override;

  //  e3::Element* mLayer1Element = nullptr;
   // e3::Element* mLayer2Element = nullptr;
   
    bool mFirstFrame = true;
    CarProject* mCarProject = nullptr;

    
};

#endif // __Application_H__
