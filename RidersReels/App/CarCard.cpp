#include "CarCard.h"
#include <e3/Text.h>
#include "DataManager.h"

#define CARD_SPEED 180

CarCard::CarCard(e3::Element* pParent)
	: e3::Element(pParent)
{
	SetWidth(280);
	SetHeight(340);
	SetMarginLeft(10);
	SetBackgroundColor(glm::vec4(255));

	mImage1 = new e3::Element();
	mImage1->SetWidth("100%");
	mImage1->SetHeight("100%");
	mImage1->SetBackgroundImageAsset("RidersReels/img4.jpeg");
	mImage1->SetBackgroundImageFit(e3::EBackgroundSize::Cover);
	mImage1->SetBorderSize(2);
	mImage1->SetBorderColor(glm::vec4(255));
	AddElement(mImage1);

	mImage2 = new e3::Element();
	mImage2->SetWidth("100%");
	mImage2->SetHeight("100%");
	mImage2->SetBackgroundImageAsset("RidersReels/img3.jpeg");
	mImage2->SetBorderSize(2);
	mImage2->SetBorderColor(glm::vec4(255));
	mImage2->SetPositionType(e3::EPositionType::Absolute);
	mImage2->SetTop(-5);
	mImage2->SetLeft(-5);
	mImage2->SetBackgroundImageFit(e3::EBackgroundSize::Cover);
	AddElement(mImage2);
	mImage2->SetVisibility(e3::EVisibility::Gone);

	e3::ShadowParams sh;
	sh.BlurSize = 10;
	sh.Color = glm::vec4(0, 0, 0, 255);
	sh.Offset = glm::vec2(2);
	sh.Opacity = 1;
	sh.Scale = 1;
	mImage2->SetShadow(sh);

	mImage3 = new e3::Element();
	mImage3->SetWidth("100%");
	mImage3->SetHeight("100%");
	mImage3->SetBackgroundImageAsset("RidersReels/img2.jpeg");
	mImage3->SetBorderSize(2);
	mImage3->SetBorderColor(glm::vec4(255));
	mImage3->SetPositionType(e3::EPositionType::Absolute);
	mImage3->SetTop(-10);
	mImage3->SetLeft(-10);
	mImage3->SetBackgroundImageFit(e3::EBackgroundSize::Cover);
	AddElement(mImage3);
	mImage3->SetVisibility(e3::EVisibility::Gone);

	mCard = new e3::Element();
	mCard->SetWidth("100%");
	mCard->SetHeight("100%");
	mCard->SetBackgroundImageAsset("RidersReels/img.jpeg");
	mCard->SetBorderSize(2);
	mCard->SetBorderColor(glm::vec4(255));
	mCard->SetPositionType(e3::EPositionType::Absolute);
	mCard->SetTop(-15);
	mCard->SetLeft(-15);
	mCard->SetBackgroundImageFit(e3::EBackgroundSize::Cover);
	AddElement(mCard);
	mCard->SetVisibility(e3::EVisibility::Gone);

	e3::Element* pYearCont = new e3::Element();
	pYearCont->SetBackgroundColor(glm::vec4(255, 0,0, 255));
	pYearCont->SetHeight(26);
	pYearCont->SetWidth(80);
	pYearCont->SetPaddingLeft(8);
	pYearCont->SetPositionType(e3::EPositionType::Absolute);
	pYearCont->SetTop(2);
	pYearCont->SetRight(2);
	pYearCont->BeginPath();
	pYearCont->MoveTo(0,0);
	pYearCont->LineTo("100%", 0);
	pYearCont->LineTo("100%", "100%");
	pYearCont->LineTo("20%", "100%");
	pYearCont->Close();
	pYearCont->EndPath();
	mCard->AddElement(pYearCont);

	e3::Element* pYearContInner = new e3::Element();
	pYearContInner->SetBackgroundColor(glm::vec4(255));
	pYearContInner->SetAlignItemsHor(e3::EAlignment::End);
	pYearContInner->SetHeight(26);
	pYearContInner->SetPaddingRight(5);
	pYearContInner->SetWidth("100%");
	pYearContInner->SetPositionType(e3::EPositionType::Absolute);
	pYearContInner->SetTop(0);
	pYearContInner->SetRight(0);
	pYearContInner->BeginPath();
	pYearContInner->MoveTo(0, 0);
	pYearContInner->LineTo("100%", 0);
	pYearContInner->LineTo("100%", "100%");
	pYearContInner->LineTo("20%", "100%");
	pYearContInner->Close();
	pYearContInner->EndPath();
	pYearCont->AddElement(pYearContInner);

	e3::Text* pYear = new e3::Text();
	pYear->SetText(std::to_string(DataManager::Get()->GetCar()->Year));
	pYear->SetFontSize(17);
	pYear->SetFontFamily("open sans");
	pYear->SetFontStyle(e3::EFontStyle::SemiBold);
	pYear->SetTextColor(glm::vec4(0, 0, 0, 255));
	pYearContInner->AddElement(pYear);

	// Model
	e3::Element* pModelCont = new e3::Element();
	pModelCont->SetBackgroundColor(glm::vec4(255));
	pModelCont->SetHeight(26);
	//pModelCont->SetWidth(80);
	pModelCont->SetPaddingLeft(10);
	pModelCont->SetPaddingRight(40);
	pModelCont->SetPositionType(e3::EPositionType::Absolute);
	pModelCont->SetBottom(2);
	pModelCont->SetLeft(2);
	pModelCont->BeginPath();
	pModelCont->MoveTo(0, 0);
	pModelCont->LineTo("80%", 0);
	pModelCont->LineTo("100%", "100%");
	pModelCont->LineTo(0, "100%");
	pModelCont->Close();
	pModelCont->EndPath();
	mCard->AddElement(pModelCont);

	e3::Text* pModel = new e3::Text();
	pModel->SetText(DataManager::Get()->GetEngine());
	pModel->SetFontSize(20);
	pModel->SetFontFamily("open sans");
	pModel->SetFontStyle(e3::EFontStyle::SemiBold);
	pModel->SetTextColor(glm::vec4(0, 0, 0, 255));
	pModelCont->AddElement(pModel);

	// Make
	e3::Element* pMakeCont = new e3::Element();
	pMakeCont->SetBackgroundColor(glm::vec4(0,0,0,255));
	pMakeCont->SetHeight(24);
	pMakeCont->SetPaddingLeft(10);
	pMakeCont->SetPaddingRight(10);
	pMakeCont->SetPositionType(e3::EPositionType::Absolute);
	pMakeCont->SetBottom(28);
	pMakeCont->SetLeft(2);
	mCard->AddElement(pMakeCont);

	e3::Text* pMake = new e3::Text();
	pMake->SetText(DataManager::Get()->GetMake());
	pMake->SetFontSize(20);
	pMake->SetFontFamily("open sans");
	pMake->SetFontStyle(e3::EFontStyle::SemiBold);
	pMake->SetTextColor(glm::vec4(255));
	pMakeCont->AddElement(pMake);
}

void CarCard::AnimateImage4()
{
	mCard->SetVisibility(e3::EVisibility::Visible);
	e3::Animation* pA = new e3::Animation(this);
		pA->Start(.1, 1.4, 1, [this](float v){
			mCard->SetScale(glm::vec3(v, v, 1), e3::ETransformAlignment::Center);
			mCard->SetRotation(-(v - 1) * 12, glm::vec3(0, 0, 1), e3::ETransformAlignment::BottomRight);
			mCard->SetTranslation(glm::vec3(-(v - 1) * CARD_SPEED, 0, 0));
		}, [](){
			
			
		});
}

void CarCard::AnimateImage3()
{
	mImage3->SetVisibility(e3::EVisibility::Visible);
	e3::Animation* pA = new e3::Animation(this);
		pA->Start(.1, 1.4, 1, [this](float v){
			mImage3->SetScale(glm::vec3(v, v, 1), e3::ETransformAlignment::Center);
			mImage3->SetRotation(-(v - 1) * 12, glm::vec3(0, 0, 1), e3::ETransformAlignment::BottomRight);
			mImage3->SetTranslation(glm::vec3(-(v - 1) * CARD_SPEED, 0, 0));

		}, [this](){
			AnimateImage4();
			
		});
}

void CarCard::AnimateImage2()
{
	mImage2->SetVisibility(e3::EVisibility::Visible);
	e3::Animation* pA = new e3::Animation(this);
		pA->Start(.1, 1.4, 1, [this](float v){
			mImage2->SetScale(glm::vec3(v, v, 1), e3::ETransformAlignment::Center);
			mImage2->SetRotation(-(v - 1) * 12, glm::vec3(0, 0, 1), e3::ETransformAlignment::BottomRight);
			mImage2->SetTranslation(glm::vec3(-(v - 1) * CARD_SPEED, 0, 0));

		}, [this](){
			AnimateImage3();
			
		});
}


void CarCard::Render()
{
	if (mFirstFrame)
	{
		e3::Animation* pA = new e3::Animation(this);
		pA->Start(.1, 1.4, 1, [this](float v){
			mImage1->SetScale(glm::vec3(v, v, 1), e3::ETransformAlignment::Center);
			mImage1->SetRotation(-(v - 1) * 12, glm::vec3(0, 0, 1), e3::ETransformAlignment::BottomRight);
			mImage1->SetTranslation(glm::vec3(-(v - 1) * CARD_SPEED, 0, 0));

		}, [this](){
			AnimateImage2();
		});

		mFirstFrame = false;
	}
	e3::Element::Render();
}