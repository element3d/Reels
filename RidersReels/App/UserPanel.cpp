#include "UserPanel.h"
#include <e3/FontIcon.h>

UserPanel::UserPanel(e3::Element* pParent) 
	: e3::Element(pParent)
{
	SetOrientation(e3::EOrientation::Vertical);
	SetPositionType(e3::EPositionType::Absolute);
	SetRight(200);
	SetTop(200);
	SetWidth(240);

	mAvatarWrap = new e3::Element();
	mAvatarWrap->SetWidth(150);
	mAvatarWrap->SetHeight(150);
	mAvatarWrap->SetOverflow(e3::EOverflow::Hidden);
	mAvatarWrap->SetAlignItemsVer(e3::EAlignment::Start);
	AddElement(mAvatarWrap);

	mAvatar = new e3::Element();
	mAvatar->SetWidth(150);
	mAvatar->SetHeight(150);
	mAvatar->SetBackgroundImageAsset("RidersReels/avatar.png");
	mAvatar->SetBackgroundImageFit(e3::EBackgroundSize::Cover);
	mAvatar->SetBorderSize(2);
	mAvatar->SetBorderColor(glm::vec4(255));
	mAvatar->SetBorderRadius(glm::vec4(6));
	mAvatarWrap->AddElement(mAvatar);

	mAvatarOverlay = new e3::Element();
	mAvatarOverlay->SetWidth(150);
	mAvatarOverlay->SetHeight(150);
	mAvatarOverlay->SetBackgroundColor(glm::vec4(255));
	mAvatarOverlay->SetPositionType(e3::EPositionType::Absolute);
	mAvatarWrap->AddElement(mAvatarOverlay);

	mNameWrap = new e3::Element();
	mNameWrap->SetMarginTop(20);
	mNameWrap->SetOpacity(0);
	AddElement(mNameWrap);

	mName = new e3::Text();
	mName->SetText("SERYOZHA");
	mName->SetTextColor(glm::vec4(255));
	mName->SetFontFamily("open sans");
	mName->SetFontSize(30);
	mName->SetOpacity(0);
	mName->SetFontStyle(e3::EFontStyle::SemiBold);
	mNameWrap->AddElement(mName);

	mNameOverlay = new e3::Element();
	mNameOverlay->SetWidth(200);
	mNameOverlay->SetHeight(40);
	mNameOverlay->SetBackgroundColor(glm::vec4(255, 0, 84, 255));
	mNameOverlay->SetPositionType(e3::EPositionType::Absolute);
	mNameWrap->AddElement(mNameOverlay);

	mPhoneWrap = new e3::Element();
	mPhoneWrap->SetWidth(240);
	mPhoneWrap->SetMarginTop(20);
	mPhoneWrap->SetHeight(40);
	mPhoneWrap->SetOverflow(e3::EOverflow::Hidden);
	mPhoneWrap->SetOpacity(0);
	mPhoneWrap->SetAlignItemsHor(e3::EAlignment::Start);
	AddElement(mPhoneWrap);

	mPhoneCont = new e3::Element();
	mPhoneCont->SetWidth(240);
	mPhoneCont->SetHeight(40);
	mPhoneCont->SetBackgroundColor(glm::vec4(255));
	mPhoneCont->SetBorderRadius(3);
	mPhoneWrap->AddElement(mPhoneCont);

	e3::FontIcon* pPhoneIcon = new e3::FontIcon();
	pPhoneIcon->SetFont("RidersReels/icons.ttf");
	pPhoneIcon->SetCharcode("E942");
	pPhoneIcon->SetWidth(30);
	pPhoneIcon->SetHeight(30);
	pPhoneIcon->SetColor(glm::vec4(0, 0, 0, 255));
	pPhoneIcon->SetMarginRight(10);
	mPhoneCont->AddElement(pPhoneIcon);

	e3::Text* pPhone = new e3::Text();
	pPhone->SetText("098 445878");
	pPhone->SetFontFamily("open sans");
	pPhone->SetFontSize(28);
	pPhone->SetFontStyle(e3::EFontStyle::SemiBold);
	pPhone->SetTextColor(glm::vec4(0,0,0,255));
	mPhoneCont->AddElement(pPhone);
}

void UserPanel::Render() 
{
	if (mFirstFrame) 
	{
		e3::Animation* pA = new e3::Animation(this);
		pA->Start(0.2, [this](float v){
			mAvatarWrap->SetHeight(150 * v);
			mAvatarOverlay->SetOpacity(1-v);
		}, [this](){
			mNameWrap->SetOpacity(1);
			e3::Animation* pA = new e3::Animation(this);
			pA->Start(0.2, [this](float v){
				mNameOverlay->SetScale(glm::vec3(v, 1, 1), e3::ETransformAlignment::Left);
			}, [this](){
				mName->SetOpacity(1);
				e3::Animation* pA = new e3::Animation(this);
				pA->Start(0.2, 1, 0, [this](float v){
					mNameOverlay->SetScale(glm::vec3(v, 1, 1), e3::ETransformAlignment::Right);
				}, [this](){
					mPhoneWrap->SetOpacity(1);
					e3::Animation* pA = new e3::Animation(this);
					pA->Start(.2, 0, 1, [this](float v){
						mPhoneWrap->SetWidth(v * 240);
					}, [this](){
		
		
					});
		
				});
		
			});
		
		});
		mFirstFrame = false;
	}
	e3::Element::Render();
}
