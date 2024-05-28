#include "MediaCarinfoPanel.h"
#include "CarInfoItem.h"
#include "Timeline.h"
#include "DataManager.h"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <locale>

struct with_dot : std::numpunct<char> {
protected:
	char do_thousands_sep() const override {
		return '.';  // Separator for thousands
	}

	std::string do_grouping() const override {
		return "\3";  // Groups of three digits
	}
};

std::string formatMileage(int mileage) {
	std::ostringstream oss;
	oss.imbue(std::locale(oss.getloc(), new with_dot));
	oss << mileage;
	return oss.str();
}

MediaCarInfoPanel::MediaCarInfoPanel(e3::Element* pParent) 
	: FrameElement(pParent)
{
	e3::Element* pElement = new e3::Element();
	pElement->SetWidth("100%");
	pElement->SetHeight("100%");
	SetElement(pElement, EFrameElementType::Element);

	mFrame = new e3::Element();
	mFrame->SetBackgroundColor(glm::vec4(0,0,0, 150));
	mFrame->SetPositionType(e3::EPositionType::Absolute);
	mFrame->SetTop(200);
	mFrame->SetLeft(40);
	mFrame->SetWidth(400);
	mFrame->SetHeight(400);
	mFrame->SetOrientation(e3::EOrientation::Vertical);
	mFrame->SetAlignItemsVer(e3::EAlignment::Start);
	mFrame->SetPaddingTop(20);
	pElement->AddElement(mFrame);

	/*CarInfoItem* pMileage = new CarInfoItem("MILEAGE", "120.000 KM");
	mFrame->AddElement(pMileage);
	CarInfoItem* pYear = new CarInfoItem("YEAR", "2012");
	mFrame->AddElement(pYear);
	CarInfoItem* pTransmission = new CarInfoItem("TRANSMISSION", "AUTOMATIC");
	mFrame->AddElement(pTransmission);
	CarInfoItem* pLocation = new CarInfoItem("LOCATION", "LORI");
	mFrame->AddElement(pLocation);*/
}

void MediaCarInfoPanel::Render() 
{
	if (mFirstFrame)
	{
		e3::Animation* pA = new e3::Animation(this);
		pA->Start(.4, [this](float v) {
			mFrame->SetHeight(400 * v);
			mFrame->SetOpacity(v);
		}, []() {
			
		});
		mFirstFrame = false;
	}
	double time = Timeline::Get()->GetTime();
	double diff = time - mBeginTime;

	DBCar* pCar = DataManager::Get()->GetCar();
	if (!mMileageAdded && diff >= 200) 
	{
		mMileageAdded = true;
		std::string mileage = formatMileage(pCar->Mileage) + " KM";
		CarInfoItem* pMileage = new CarInfoItem("mileage", mileage, "E906");
		mFrame->AddElement(pMileage);
	}
	if (!mYearAdded && diff >= 250) 
	{
		mYearAdded = true;
		CarInfoItem* pYear = new CarInfoItem("year", std::to_string(pCar->Year), "E900");
		mFrame->AddElement(pYear);
	}
	if (!mTransmissionAdded && diff >= 300) 
	{
		mTransmissionAdded = true;
		CarInfoItem* pTransmission = new CarInfoItem("transmission", "automatic", "E908");
		mFrame->AddElement(pTransmission);
	}
	if (!mLocationAdded && diff >= 350) 
	{
		mLocationAdded = true;
		CarInfoItem* pLocation = new CarInfoItem("location", "lori", "E903");
		mFrame->AddElement(pLocation);
	}
	if (!mDriveTypeAdded && diff >= 400) 
	{
		mDriveTypeAdded = true;
		CarInfoItem* pDriveType = new CarInfoItem("drive_type", "all_wheel_drive", "E90C");
		mFrame->AddElement(pDriveType);
	}
	if (!mBodyTypeAdded && diff >= 450) 
	{
		mBodyTypeAdded = true;
		CarInfoItem* pBodyType = new CarInfoItem("body_type", "suv", "E90D");
		mFrame->AddElement(pBodyType);
	}
	if (!mStWheelAdded && diff >= 500) 
	{
		mStWheelAdded = true;
		CarInfoItem* pStWheel = new CarInfoItem("st_wheel", pCar->StearingWheel == 0 ? "left" : "right", "E901");
		mFrame->AddElement(pStWheel);
	}

	FrameElement::Render();
}