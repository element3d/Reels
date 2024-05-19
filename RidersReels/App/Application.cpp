#include "Application.h"
#include <e3/Typography.h>
#include "FrameElement.h"
#include "Timeline.h"
#include "EffectZoomOut.h"
#include "TransitionZoomOut.h"
#include "TransitionZoomIn.h"
#include "TransitionFadeIn.h"
#include "TransitionFadeOut.h"

Application::Application(const std::string& applicationName, e3::EE3OS os, e3::EE3Target target, e3::Size2i windowSize, e3::Size2i resolution) 
	: ApplicationBase(applicationName, os, target, windowSize, resolution)
{
	e3::Typography::AddFont("facon", e3::EFontStyle::Normal, "RidersReels/fonts/facon.ttf");
	mMain = new e3::Element();

	FrameElement* pImage1Frame = new FrameElement();
	e3::Element* pImage1 = new e3::Element();
	pImage1->SetBackgroundImageAsset("RidersReels/img.jpg");
	pImage1->SetBackgroundImageFit(e3::EBackgroundSize::Cover);
	pImage1Frame->SetBeginTime(0);
	pImage1Frame->SetLayer(0);
	pImage1Frame->SetElement(pImage1, EFrameElementType::Image);
	mFrameElementPushMap[0].push_back(pImage1Frame);
	TransitionZoomOut* pTransition1 = new TransitionZoomOut(1.4, 1.1, 0.05);
	pImage1Frame->SetBeginTransition(pTransition1);
	PushElement(mMain);
	EffectZoomOut* pEffectZoomOut1 = new EffectZoomOut(1.1, 1.0, 0.05, 4);
	pImage1Frame->AddEffect(pEffectZoomOut1);

	FrameElement* pImage2Frame = new FrameElement();
	e3::Element* pImage2 = new e3::Element();
	pImage2->SetBackgroundImageAsset("RidersReels/img2.jpg");
	pImage2->SetBackgroundImageFit(e3::EBackgroundSize::Cover);
	pImage2Frame->SetBeginTime(4000);
	pImage2Frame->SetLayer(0);
	pImage2Frame->SetElement(pImage2, EFrameElementType::Image);
	mFrameElementPushMap[4000].push_back(pImage2Frame);
	TransitionZoomOut* pTransition2 = new TransitionZoomOut(1.4, 1.1, 0.05);
	pImage2Frame->SetBeginTransition(pTransition2);
	EffectZoomOut* pEffectZoomOut2 = new EffectZoomOut(1.1, 1.0, 4050, 4);
	pImage2Frame->AddEffect(pEffectZoomOut2);

	FrameElement* pRidersTitleOverlayFrame = new FrameElement();
	pRidersTitleOverlayFrame->SetDuration(2000);
	e3::Element* pRidersTitleOverlay = new e3::Element();
	pRidersTitleOverlay->SetBackgroundColor(glm::vec4(0, 0, 0, 255));
	pRidersTitleOverlay->SetWidth("100%");
	pRidersTitleOverlay->SetHeight("100%");
	pRidersTitleOverlayFrame->SetElement(pRidersTitleOverlay, EFrameElementType::Element);
	pRidersTitleOverlayFrame->SetLayer(1);
	pRidersTitleOverlayFrame->SetBeginTime(1000);
	mFrameElementPushMap[1000].push_back(pRidersTitleOverlayFrame);
	TransitionFadeIn* pFadeInRidersTitle = new TransitionFadeIn(0, 0.3, 0.1);
	pRidersTitleOverlayFrame->SetBeginTransition(pFadeInRidersTitle);
	TransitionFadeOut* pFadeOutRidersTitle = new TransitionFadeOut(0.3, 0.0, 0.1);
	pRidersTitleOverlayFrame->SetEndTransition(pFadeOutRidersTitle);

	FrameElement* pRidersFrame = new FrameElement();
	pRidersFrame->SetDuration(2000);
	e3::Text* t = new e3::Text();
	t->SetText("RIDERS");
	t->SetFontFamily("facon");
	t->SetFontSize(80);
	t->SetTextColor(glm::vec4(195, 251, 18, 255));
	pRidersFrame->SetElement(t, EFrameElementType::Text);
	pRidersFrame->SetLayer(2);
	pRidersFrame->SetBeginTime(1000);
	mFrameElementPushMap[1000].push_back(pRidersFrame);
	TransitionZoomOut* pZoomOutRidersTitle = new TransitionZoomOut(1.4, 1.0, 0.1);
	pRidersFrame->SetBeginTransition(pZoomOutRidersTitle);
	TransitionZoomIn* pZoomInRidersTitle = new TransitionZoomIn(1.0, 1.2, 0.05);
	pRidersFrame->SetEndTransition(pZoomInRidersTitle);
}

void Application::AnimateElement(e3::Element* e, e3::Element* next)
{
	/*e3::Animation* a = new e3::Animation(e);
	a->Start(0.05, 1.4, 1.1, [e](float v){
		e->SetScale(glm::vec3(v, v, 1), e3::ETransformAlignment::Center);
		e->SetRotation(v*10, glm::vec3(0, 0, 1), e3::ETransformAlignment::Center);
	}, [next, e, this](){
		e3::Animation* a = new e3::Animation(e);
		a->Start(4, 1.1, 1, [e](float v){
			e->SetScale(glm::vec3(v, v, 1), e3::ETransformAlignment::Center);
			e->SetRotation(v*10, glm::vec3(0, 0, 1), e3::ETransformAlignment::Center);
		}, [next,e, this](){
			if (next) 
			{
				mLayer1Element->RemoveElement(e);
				mLayer1Element->AddElement(next);
				AnimateElement(next, nullptr);
			}
		});
	});*/
}


void Application::OnResize(float width, float height)
{

}

void Application::Render()
{
	if (mFirstFrame) 
	{
		mFirstFrame = false;
		Timeline::Get()->Begin();
	}
	Timeline::Get()->OnFrame();
	long time = Timeline::Get()->GetTime();
	// FrameElement* pFrame = nullptr;
	if (mFrameElementPushMap.size())
	{
		auto it = mFrameElementPushMap.begin(); 
		long t = it->first;    
		std::vector<FrameElement*>& elements = it->second; 
		if (t <= time) 
		{
			for (auto pFrame : elements)
			{
			
				int layer = pFrame->GetLayer();
				e3::Element* pLayer = nullptr;
				if (mLayers.size() <= layer) 
				{
					pLayer = new e3::Element();
					pLayer->SetWidth("100%");
					pLayer->SetHeight("100%");
					pLayer->SetPositionType(e3::EPositionType::Absolute);
					mLayers.push_back(pLayer);
					mMain->AddElement(pLayer);
				}
				else 
				{
					pLayer = mLayers[layer];
				}
				pLayer->RemoveAllElements();
				pLayer->AddElement(pFrame);

				if (pFrame->GetDuration() > 0) 
				{
					mFrameElementPopMap[pFrame->GetDuration() + time].push_back(pFrame);
				}
			}
			mFrameElementPushMap.erase(it);
		}
	}

	if (mFrameElementPopMap.size())
	{
		auto it = mFrameElementPopMap.begin(); 
		long t = it->first;    
		std::vector<FrameElement*>& elements = it->second; 
		if (t <= time) 
		{
			for (auto pFrame : elements)
			{
			
				int layer = pFrame->GetLayer();
				e3::Element* pLayer = mLayers[layer];
				pLayer->RemoveElement(pFrame);
			}
			mFrameElementPopMap.erase(it);
		}
	}

	e3::Application::Render();
}
