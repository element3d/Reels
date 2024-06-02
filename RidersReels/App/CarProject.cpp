#include "CarProject.h"
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
#include "MediaEnding.h"
#include "MediaDwinLogo.h"
#include "MediaEngine.h"
#include <e3/i18n.h>
#include <e3/AssetManager.h>
#include "DBCar.h"
#include "DataManager.h"
#include <SDL2/SDL.h>
#include <e3/Application.h>

CarProject::CarProject() 
{
	bool isPortrait = false;
	std::string imgPath = e3::Element::GetApplication()->GetAssetManager()->GetAssetPath("RidersReels/img.jpeg");
	cv::Mat testImg = cv::imread(imgPath);
	if (testImg.size().width < testImg.size().height)
	{
		isPortrait = true;
	}

	std::vector<std::string> images =
	{
		"RidersReels/img.jpeg",
		"RidersReels/img2.jpeg",
		"RidersReels/img3.jpeg",
		"RidersReels/img4.jpeg",
		"RidersReels/img5.jpeg",
		"RidersReels/img6.jpeg",
		"RidersReels/img7.jpeg",
		"RidersReels/img8.jpeg",
	};

	mMain = new e3::Element();
	mMain->SetBackgroundColor(glm::vec4(7, 19, 45, 255));

	int currentImage = 0;

	FrameElement* pImage1Frame = new FrameElement();
	pImage1Frame->SetDuration(4000);
	pImage1Frame->SetBeginTime(0);
	pImage1Frame->SetLayer(0);

	e3::Element* pImage1 = new e3::Element();
	pImage1->SetWidth("100%");
	pImage1->SetBackgroundImageAsset(images[currentImage++]);
	pImage1->SetBackgroundImageFit(e3::EBackgroundSize::Cover);

	if (isPortrait)
	{
		pImage1->SetWidth("55%");
		e3::Element* pImageWrap = new e3::Element();
		pImageWrap->AddElement(pImage1);

		e3::Element* pDiv = new e3::Element();
		pDiv->SetWidth(4);
		pDiv->SetHeight(1000);
		pDiv->SetBackgroundColor(glm::vec4(255));
		pImageWrap->AddElement(pDiv);

		e3::Element* pNewImage1 = new e3::Element();
		pNewImage1->SetBackgroundImageAsset(images[currentImage++]);
		pNewImage1->SetBackgroundImageFit(e3::EBackgroundSize::Cover);
		pNewImage1->SetWidth("55%");

		pImageWrap->AddElement(pNewImage1);

		pImage1Frame->SetElement(pImageWrap, EFrameElementType::Image);
	}
	else
	{
		pImage1Frame->SetElement(pImage1, EFrameElementType::Image);
	}
	mFrameElementPushMap[0].push_back(pImage1Frame);
	/*TransitionZoomOut* pTransition1 = new TransitionZoomOut(1.2, 1.1, 0.05);
	pImage1Frame->SetBeginTransition(pTransition1);*/
	// PushElement(mMain);
	EffectZoomOut* pEffectZoomOut1 = new EffectZoomOut(1.4, 1.3, 0, 2);
	pImage1Frame->AddEffect(pEffectZoomOut1);
	EffectZoomOut* pEffectZoomOut12 = new EffectZoomOut(1.3, 1.04, 2000, 0.05);
	pImage1Frame->AddEffect(pEffectZoomOut12);
	EffectZoomOut* pEffectZoomOut13 = new EffectZoomOut(1.04, 1.0, 2100, 2);
	pImage1Frame->AddEffect(pEffectZoomOut13);
	EffectRotation* pEffectRotation1 = new EffectRotation(4, 1, 0, 4);
	pImage1Frame->AddEffect(pEffectRotation1);

	FrameElement* pImage2Frame = new FrameElement();
	pImage2Frame->SetDuration(4000);
	e3::Element* pImage2 = new e3::Element();
	pImage2Frame->SetBeginTime(4000);
	pImage2Frame->SetLayer(0);
	pImage2->SetBackgroundImageAsset(images[currentImage++]);
	pImage2->SetBackgroundImageFit(e3::EBackgroundSize::Cover);
	pImage2->SetWidth("100%");
	if (isPortrait)
	{
		pImage2->SetWidth("50%");
		e3::Element* pImageWrap = new e3::Element();
		pImageWrap->AddElement(pImage2);

		e3::Element* pDiv = new e3::Element();
		pDiv->SetWidth(4);
		pDiv->SetHeight(1000);
		pDiv->SetBackgroundColor(glm::vec4(255));
		pImageWrap->AddElement(pDiv);

		e3::Element* pNewImage2 = new e3::Element();
		pNewImage2->SetBackgroundImageAsset(images[currentImage++]);
		pNewImage2->SetBackgroundImageFit(e3::EBackgroundSize::Cover);
		pNewImage2->SetWidth("50%");

		pImageWrap->AddElement(pNewImage2);

		pImage2Frame->SetElement(pImageWrap, EFrameElementType::Image);
	}
	else
	{
		pImage2Frame->SetElement(pImage2, EFrameElementType::Image);
	}
	mFrameElementPushMap[4000].push_back(pImage2Frame);
	TransitionZoomOut* pTransition2 = new TransitionZoomOut(1.2, 1.1, 0.1);
	pImage2Frame->SetBeginTransition(pTransition2);
	EffectZoomOut* pEffectZoomOut2 = new EffectZoomOut(1.1, 1.0, 4100, 4);
	pImage2Frame->AddEffect(pEffectZoomOut2);
	EffectRotation* pEffectRotation2 = new EffectRotation(4, 1, 4000, 4);
	pImage2Frame->AddEffect(pEffectRotation2);

	FrameElement* pImage3Frame = new FrameElement();
	pImage3Frame->SetDuration(3500);
	e3::Element* pImage3 = new e3::Element();
	pImage3->SetBackgroundImageAsset(images[currentImage++]);
	pImage3->SetBackgroundImageFit(e3::EBackgroundSize::Cover);
	pImage3->SetWidth("100%");
	pImage3Frame->SetBeginTime(8000);
	pImage3Frame->SetLayer(0);

	if (isPortrait)
	{
		pImage3->SetWidth("50%");
		e3::Element* pImageWrap = new e3::Element();
		pImageWrap->AddElement(pImage3);

		e3::Element* pDiv = new e3::Element();
		pDiv->SetWidth(4);
		pDiv->SetHeight(1000);
		pDiv->SetBackgroundColor(glm::vec4(255));
		pImageWrap->AddElement(pDiv);

		e3::Element* pNewImage3 = new e3::Element();
		pNewImage3->SetBackgroundImageAsset(images[currentImage++]);
		pNewImage3->SetBackgroundImageFit(e3::EBackgroundSize::Cover);
		pNewImage3->SetWidth("50%");

		pImageWrap->AddElement(pNewImage3);

		pImage3Frame->SetElement(pImageWrap, EFrameElementType::Image);
	}
	else
	{
		pImage3Frame->SetElement(pImage3, EFrameElementType::Image);
	}

	mFrameElementPushMap[8000].push_back(pImage3Frame);
	TransitionZoomOut* pTransition3 = new TransitionZoomOut(1.2, 1.1, 0.1);
	pImage3Frame->SetBeginTransition(pTransition3);
	EffectZoomOut* pEffectZoomOut3 = new EffectZoomOut(1.1, 1.0, 8100, 4);
	pImage3Frame->AddEffect(pEffectZoomOut3);
	EffectRotation* pEffectRotation3 = new EffectRotation(4, 1, 8000, 4);
	pImage3Frame->AddEffect(pEffectRotation3);

	FrameElement* pImage4Frame = new FrameElement();
	pImage4Frame->SetDuration(3300);
	e3::Element* pImage4 = new e3::Element();
	pImage4->SetBackgroundImageAsset(images[currentImage++]);
	pImage4->SetBackgroundImageFit(e3::EBackgroundSize::Cover);
	pImage4->SetWidth("100%");
	pImage4Frame->SetBeginTime(11500);
	pImage4Frame->SetLayer(0);

	if (isPortrait)
	{
		pImage4->SetWidth("50%");
		e3::Element* pImageWrap = new e3::Element();
		pImageWrap->AddElement(pImage4);

		e3::Element* pDiv = new e3::Element();
		pDiv->SetWidth(4);
		pDiv->SetHeight(1000);
		pDiv->SetBackgroundColor(glm::vec4(255));
		pImageWrap->AddElement(pDiv);

		e3::Element* pNewImage4 = new e3::Element();
		pNewImage4->SetBackgroundImageAsset(images[currentImage++]);
		pNewImage4->SetBackgroundImageFit(e3::EBackgroundSize::Cover);
		pNewImage4->SetWidth("50%");

		pImageWrap->AddElement(pNewImage4);

		pImage4Frame->SetElement(pImageWrap, EFrameElementType::Image);
	}
	else
	{
		pImage4Frame->SetElement(pImage4, EFrameElementType::Image);
	}

	mFrameElementPushMap[11500].push_back(pImage4Frame);
	TransitionZoomOut* pTransition4 = new TransitionZoomOut(1.2, 1.1, 0.1);
	pImage4Frame->SetBeginTransition(pTransition4);
	EffectZoomOut* pEffectZoomOut4 = new EffectZoomOut(1.1, 1.0, 11600, 4);
	pImage4Frame->AddEffect(pEffectZoomOut4);
	EffectRotation* pEffectRotation4 = new EffectRotation(4, 1, 11500, 4);
	pImage4Frame->AddEffect(pEffectRotation4);

	FrameElement* pImage5Frame = new FrameElement();
	e3::Element* pImage5 = new e3::Element();
	pImage5->SetBackgroundImageAsset("RidersReels/img5.jpg");
	pImage5->SetBackgroundImageFit(e3::EBackgroundSize::Cover);
	pImage5Frame->SetBeginTime(14800);
	pImage5Frame->SetLayer(0);
	pImage5Frame->SetElement(pImage5, EFrameElementType::Image);
	mFrameElementPushMap[14800].push_back(pImage5Frame);
	TransitionZoomOut* pTransition5 = new TransitionZoomOut(1.2, 1.1, 0.1);
	pImage5Frame->SetBeginTransition(pTransition5);
	EffectZoomOut* pEffectZoomOut5 = new EffectZoomOut(1.1, 1.0, 16100, 4);
	pImage5Frame->AddEffect(pEffectZoomOut5);
	//EffectRotation* pEffectRotation5 = new EffectRotation(4, 1, 16000, 4);
	//pImage5Frame->AddEffect(pEffectRotation5);

	FrameElement* pRidersTitleOverlayFrame = new FrameElement();
	pRidersTitleOverlayFrame->SetDuration(2000);
	e3::Element* pRidersTitleOverlay = new e3::Element();
	pRidersTitleOverlay->SetBackgroundColor(glm::vec4(0, 0, 0, 255));
	pRidersTitleOverlay->SetWidth("100%");
	pRidersTitleOverlay->SetHeight("100%");
	pRidersTitleOverlayFrame->SetElement(pRidersTitleOverlay, EFrameElementType::Element);
	pRidersTitleOverlayFrame->SetLayer(1);
	pRidersTitleOverlayFrame->SetBeginTime(2000);
	mFrameElementPushMap[2000].push_back(pRidersTitleOverlayFrame);
	TransitionFadeIn* pFadeInRidersTitle = new TransitionFadeIn(0, 0.5, 0.1);
	pRidersTitleOverlayFrame->SetBeginTransition(pFadeInRidersTitle);
	TransitionFadeOut* pFadeOutRidersTitle = new TransitionFadeOut(0.5, 0.0, 0.1);
	pRidersTitleOverlayFrame->SetEndTransition(pFadeOutRidersTitle);

	FrameElement* pRidersFrame = new FrameElement();
	pRidersFrame->SetDuration(2000);
	e3::Text* t = new e3::Text();
	t->SetPositionType(e3::EPositionType::Absolute);
	t->SetTop(240);
	t->SetMarginLeft(50);
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

	MediaDwinLogo* pMediaDwinLogo = new MediaDwinLogo();
	pMediaDwinLogo->SetDuration(1700);
	pMediaDwinLogo->SetLayer(4);
	pMediaDwinLogo->SetBeginTime(2300);
	mFrameElementPushMap[2300].push_back(pMediaDwinLogo);

	mMediaCarCard = new MediaCarCard();
	mMediaCarCard->SetDuration(4000);
	mMediaCarCard->SetLayer(2);
	mMediaCarCard->SetBeginTime(4000);
	mFrameElementPushMap[4000].push_back(mMediaCarCard);

	mMakeMedia = new MediaAnimatedText2(220, 70, DataManager::Get()->GetMake());
	mMakeMedia->SetDuration(3900);
	mMakeMedia->SetLayer(3);
	mMakeMedia->SetBeginTime(4100);
	mFrameElementPushMap[4100].push_back(mMakeMedia);

	mModelMedia = new MediaAnimatedText2(220, 110, DataManager::Get()->GetEngine());
	mModelMedia->SetDuration(3800);
	mModelMedia->SetLayer(4);
	mModelMedia->SetBeginTime(4200);
	mFrameElementPushMap[4200].push_back(mModelMedia);

	mMediaStars = new MediaStars();
	mMediaStars->SetDuration(3500);
	mMediaStars->SetLayer(5);
	mMediaStars->SetBeginTime(4500);
	mFrameElementPushMap[4500].push_back(mMediaStars);

	MediaCarInfoPanel* pMediaCarInfoPanel = new MediaCarInfoPanel();
	pMediaCarInfoPanel->SetDuration(3300);
	pMediaCarInfoPanel->SetLayer(1);
	pMediaCarInfoPanel->SetBeginTime(4700);
	mFrameElementPushMap[4700].push_back(pMediaCarInfoPanel);

	MediaEngine* pMediaEngine = new MediaEngine();
	pMediaEngine->SetDuration(2800);
	pMediaEngine->SetLayer(1);
	pMediaEngine->SetBeginTime(8000);
	mFrameElementPushMap[8000].push_back(pMediaEngine);

	MediaEnignePower* pMediaEnignePower = new MediaEnignePower();
	pMediaEnignePower->SetDuration(3200);
	pMediaEnignePower->SetLayer(1);
	pMediaEnignePower->SetBeginTime(10800);
	mFrameElementPushMap[10800].push_back(pMediaEnignePower);

	MediaEnding* pMediaEnding = new MediaEnding();
	pMediaEnding->SetDuration(8000);
	pMediaEnding->SetLayer(1);
	pMediaEnding->SetBeginTime(14500);
	mFrameElementPushMap[14500].push_back(pMediaEnding);
}

void CarProject::Render() 
{
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

	if (!mMediaCarCardHidden && time >= 7200)
	{
		mMediaCarCardHidden = true;
		mMediaCarCard->Hide();
	}

	if (!mModelMedialHidden && time >= 7300)
	{
		mModelMedialHidden = true;
		mModelMedia->Hide();
	}

	if (!mMakeMedialHidden && time >= 7350)
	{
		mMakeMedialHidden = true;
		mMakeMedia->Hide();
	}

	if (!mMediaStarsHidden && time >= 7400)
	{
		mMediaStarsHidden = true;
		mMediaStars->Hide();
	}
}