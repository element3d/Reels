#include "Application.h"
#include <e3/Typography.h>
#include "FrameElement.h"

Application::Application(const std::string& applicationName, e3::EE3OS os, e3::EE3Target target, e3::Size2i windowSize, e3::Size2i resolution) 
	: ApplicationBase(applicationName, os, target, windowSize, resolution)
{
	e3::Typography::AddFont("facon", e3::EFontStyle::Normal, "RidersReels/fonts/facon.ttf");


	mMain = new e3::Element();
	FrameElement* e = new FrameElement();
	e->SetImage("RidersReels/img.jpg");
	// e->SetBackgroundImageFit(e3::EBackgroundSize::Cover);
	// e->SetWidth("100%");
	//e->SetHeight("100%");
	mMain->AddElement(e);
	PushElement(mMain);

	e3::Element* e2 = new e3::Element();
	e2->SetBackgroundImageAsset("RidersReels/img2.jpg");
	e2->SetBackgroundImageFit(e3::EBackgroundSize::Cover);

	AnimateElement(e, e2);

	e3::Text* t = new e3::Text();
	t->SetText("RIDERS");
	t->SetFontFamily("facon");
	t->SetFontSize(50);
	t->SetTextColor(glm::vec4(195, 251, 18, 255));
	e->SetAlignItemsHor(e3::EAlignment::Center);
	e->SetAlignItemsVer(e3::EAlignment::Center);

	mLayer2Element = new e3::Element();

	mMain->AddElement(t);

}

void Application::AnimateElement(e3::Element* e, e3::Element* next)
{
	e3::Animation* a = new e3::Animation(e);
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
				mMain->RemoveElement(e);
				mMain->AddElement(next);
				AnimateElement(next, nullptr);
			}
		});
	});
}


void Application::OnResize(float width, float height)
{

}
