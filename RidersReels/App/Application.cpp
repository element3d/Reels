#include "Application.h"
#include <e3/Typography.h>
#include "FrameElement.h"
#include "Timeline.h"
#include "EffectZoomOut.h"
#include "TransitionZoomOut.h"
#include "TransitionZoomIn.h"
#include "TransitionFadeIn.h"
#include "TransitionFadeOut.h"
#include "MediaAnimatedText.h"
#include "MediaCarCard.h"
#include "MediaAnimatedText2.h"
#include "MediaStars.h"
#include "EffectRotation.h"
#include "MediaCarinfoPanel.h"
#include <opencv2/opencv.hpp>
#include "MediaEnginePower.h"

cv::VideoWriter* video;

Application::Application(const std::string& applicationName, e3::EE3OS os, e3::EE3Target target, e3::Size2i windowSize, e3::Size2i resolution) 
	: ApplicationBase(applicationName, os, target, windowSize, resolution)
{
	e3::Typography::AddFont("facon", e3::EFontStyle::Normal, "RidersReels/fonts/facon.ttf");
	mMain = new e3::Element();

	FrameElement* pImage1Frame = new FrameElement();
	pImage1Frame->SetDuration(4000);
	e3::Element* pImage1 = new e3::Element();
	pImage1->SetBackgroundImageAsset("RidersReels/img.jpg");
	pImage1->SetBackgroundImageFit(e3::EBackgroundSize::Cover);
	pImage1Frame->SetBeginTime(0);
	pImage1Frame->SetLayer(0);
	pImage1Frame->SetElement(pImage1, EFrameElementType::Image);
	mFrameElementPushMap[0].push_back(pImage1Frame);
	TransitionZoomOut* pTransition1 = new TransitionZoomOut(1.2, 1.1, 0.05);
	pImage1Frame->SetBeginTransition(pTransition1);
	PushElement(mMain);
	EffectZoomOut* pEffectZoomOut1 = new EffectZoomOut(1.12, 1.08, 50, 2);
	pImage1Frame->AddEffect(pEffectZoomOut1);
	EffectZoomOut* pEffectZoomOut12 = new EffectZoomOut(1.08, 1.04, 2000, 0.05);
	pImage1Frame->AddEffect(pEffectZoomOut12);
	EffectZoomOut* pEffectZoomOut13 = new EffectZoomOut(1.04, 1.0, 2100, 2);
	pImage1Frame->AddEffect(pEffectZoomOut13);
	EffectRotation* pEffectRotation1 = new EffectRotation(8, 5, 0, 4);
	pImage1Frame->AddEffect(pEffectRotation1);

	FrameElement* pImage2Frame = new FrameElement();
	pImage2Frame->SetDuration(4000);
	e3::Element* pImage2 = new e3::Element();
	pImage2->SetBackgroundImageAsset("RidersReels/img2.jpg");
	pImage2->SetBackgroundImageFit(e3::EBackgroundSize::Cover);
	pImage2Frame->SetBeginTime(4000);
	pImage2Frame->SetLayer(0);
	pImage2Frame->SetElement(pImage2, EFrameElementType::Image);
	mFrameElementPushMap[4000].push_back(pImage2Frame);
	TransitionZoomOut* pTransition2 = new TransitionZoomOut(1.2, 1.1, 0.1);
	pImage2Frame->SetBeginTransition(pTransition2);
	EffectZoomOut* pEffectZoomOut2 = new EffectZoomOut(1.1, 1.0,4100, 4);
	pImage2Frame->AddEffect(pEffectZoomOut2);
	EffectRotation* pEffectRotation2 = new EffectRotation(8, 5, 4000, 4);
	pImage2Frame->AddEffect(pEffectRotation2);

	FrameElement* pImage3Frame = new FrameElement();
	e3::Element* pImage3 = new e3::Element();
	pImage3->SetBackgroundImageAsset("RidersReels/img3.jpg");
	pImage3->SetBackgroundImageFit(e3::EBackgroundSize::Cover);
	pImage3Frame->SetBeginTime(8000);
	pImage3Frame->SetLayer(0);
	pImage3Frame->SetElement(pImage3, EFrameElementType::Image);
	mFrameElementPushMap[8000].push_back(pImage3Frame);
	TransitionZoomOut* pTransition3 = new TransitionZoomOut(1.2, 1.1, 0.1);
	pImage3Frame->SetBeginTransition(pTransition3);
	EffectZoomOut* pEffectZoomOut3 = new EffectZoomOut(1.1, 1.0, 8100, 4);
	pImage3Frame->AddEffect(pEffectZoomOut3);
	EffectRotation* pEffectRotation3 = new EffectRotation(5, 2, 8000, 4);
	pImage3Frame->AddEffect(pEffectRotation3);

	FrameElement* pRidersTitleOverlayFrame = new FrameElement();
	pRidersTitleOverlayFrame->SetDuration(2000);
	e3::Element* pRidersTitleOverlay = new e3::Element();
	pRidersTitleOverlay->SetBackgroundColor(glm::vec4(0, 0, 0,255));
	pRidersTitleOverlay->SetWidth("100%");
	pRidersTitleOverlay->SetHeight("100%");
	pRidersTitleOverlayFrame->SetElement(pRidersTitleOverlay, EFrameElementType::Element);
	pRidersTitleOverlayFrame->SetLayer(1);
	pRidersTitleOverlayFrame->SetBeginTime(2000);
	mFrameElementPushMap[2000].push_back(pRidersTitleOverlayFrame);
	TransitionFadeIn* pFadeInRidersTitle = new TransitionFadeIn(0, 0.3, 0.1);
	pRidersTitleOverlayFrame->SetBeginTransition(pFadeInRidersTitle);
	TransitionFadeOut* pFadeOutRidersTitle = new TransitionFadeOut(0.7, 0.0, 0.1);
	pRidersTitleOverlayFrame->SetEndTransition(pFadeOutRidersTitle);

	FrameElement* pRidersFrame = new FrameElement();
	pRidersFrame->SetDuration(2000);
	e3::Text* t = new e3::Text();
	t->SetPositionType(e3::EPositionType::Absolute);
	t->SetTop(200);
	//t->SetRotation(-10, glm::vec3(0, 1, 0), e3::ETransformAlignment::Center);
	t->SetText("RIDERS");
	t->SetFontFamily("facon");
	t->SetFontSize(80);
	t->SetTextColor(glm::vec4(195, 251, 18, 255));
	pRidersFrame->SetElement(t, EFrameElementType::Text);
	pRidersFrame->SetLayer(2);
	pRidersFrame->SetBeginTime(2000);
	mFrameElementPushMap[2000].push_back(pRidersFrame);
	TransitionZoomOut* pZoomOutRidersTitle = new TransitionZoomOut(1.4, 1.0, 0.06);
	pRidersFrame->SetBeginTransition(pZoomOutRidersTitle);
	TransitionZoomIn* pZoomInRidersTitle = new TransitionZoomIn(1.0, 1.2, 0.03);
	pRidersFrame->SetEndTransition(pZoomInRidersTitle);

	MediaAnimatedText* pRidersAmText = new MediaAnimatedText();
	pRidersAmText->SetDuration(1900);
	pRidersAmText->SetLayer(3);
	pRidersAmText->SetBeginTime(2100);
	mFrameElementPushMap[2100].push_back(pRidersAmText);

	MediaCarCard* pMediaCarCar = new MediaCarCard();
	pMediaCarCar->SetDuration(4000);
	pMediaCarCar->SetLayer(2);
	pMediaCarCar->SetBeginTime(4000);
	mFrameElementPushMap[4000].push_back(pMediaCarCar);

	MediaAnimatedText2* pMakeMedia = new MediaAnimatedText2(220, 70, "MERCEDES BENZ");
	pMakeMedia->SetDuration(3900);
	pMakeMedia->SetLayer(3);
	pMakeMedia->SetBeginTime(4100);
	mFrameElementPushMap[4100].push_back(pMakeMedia);

	MediaAnimatedText2* pModelMedia = new MediaAnimatedText2(220, 110, "W204 C250");
	pModelMedia->SetDuration(3800);
	pModelMedia->SetLayer(4);
	pModelMedia->SetBeginTime(4200);
	mFrameElementPushMap[4200].push_back(pModelMedia);

	MediaStars* pMediaStars = new MediaStars();
	pMediaStars->SetDuration(3500);
	pMediaStars->SetLayer(5);
	pMediaStars->SetBeginTime(4500);
	mFrameElementPushMap[4500].push_back(pMediaStars);

	MediaCarInfoPanel* pMediaCarInfoPanel = new MediaCarInfoPanel();
	pMediaCarInfoPanel->SetDuration(3300);
	pMediaCarInfoPanel->SetLayer(1);
	pMediaCarInfoPanel->SetBeginTime(4700);
	mFrameElementPushMap[4700].push_back(pMediaCarInfoPanel);

	MediaEnignePower* pMediaEnignePower = new MediaEnignePower();
	pMediaEnignePower->SetDuration(4000);
	pMediaEnignePower->SetLayer(1);
	pMediaEnignePower->SetBeginTime(8000);
	mFrameElementPushMap[8000].push_back(pMediaEnignePower);

	video = new cv::VideoWriter("D://output.avi", cv::VideoWriter::fourcc('M','J','P','G'), 60, cv::Size(GetWindowSize().Width, GetWindowSize().Height));

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

    // Set the desired frame rate for the video
    const int videoFrameRate = 60;
    const double frameDuration = 1.0 / videoFrameRate;
    auto nextFrameTime = std::chrono::steady_clock::now() + std::chrono::duration<double>(frameDuration);
	    auto lastFrameTime = std::chrono::steady_clock::now();

void Application::Render()
{
        auto start = std::chrono::steady_clock::now();

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
			//	pLayer->RemoveAllElements();
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

	return;
	e3::Image* pI = RenderToImage();
	void* pData = pI->GetData();
	int w = pI->GetWidth();
	int h = pI->GetHeight();
	int c = pI->GetNumChannels();

	 cv::Mat img;
    if (c == 3) {
        img = cv::Mat(h, w, CV_8UC3, pData);
    } else if (c == 4) {
        img = cv::Mat(h, w, CV_8UC4, pData);
    } else {
        // Handle other cases if necessary
        std::cerr << "Unsupported number of channels: " << c << std::endl;
        return;
    }

    // Convert from BGRA to BGR if necessary
  //  if (c == 4) {
        cv::cvtColor(img, img, cv::COLOR_BGR2RGB);
    //}
	//cv::imwrite("a.jpg", img);
	      //  video->write(img);

     auto renderEnd = std::chrono::steady_clock::now();

        // Check if enough time has passed to write the next frame
        auto now = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsedTime = now - lastFrameTime;

        if (elapsedTime.count() >= frameDuration) {
            // Write the frame into the video file
         //   video->write(img);
            lastFrameTime = now; // Update last frame time
        }

        auto writeEnd = std::chrono::steady_clock::now();

        // Print profiling information
        std::chrono::duration<double> renderTime = renderEnd - start;
        std::chrono::duration<double> writeTime = writeEnd - renderEnd;
}
