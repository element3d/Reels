#pragma once

#include "DBCar.h"

class DataManager 
{
public:
	static DataManager* Get();
	DBCar* GetCar(int id = -1);
	std::string GetName() { return mUserName; }
	std::string GetPhone() { return mUserPhone; }

	std::string GetMake();
	std::string GetEngine();
	std::string GetCyl();
	int GetPower();

private:
	void ParseUser(int userId);
	void ParseMakes();
	void ParseGMakes();
	std::string ToUpperCase(const std::string& input);

private:
	DBCar* mCar = nullptr;
	std::string mUserName;
	std::string mUserPhone;
	static DataManager* sInstance;

	rapidjson::Document mMakes;
	rapidjson::Document mGMakes;
	rapidjson::Value mEngine;

};