#include "DataManager.h"
#include <cpr/cpr.h>

DataManager* DataManager::sInstance = nullptr;

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

DataManager* DataManager::Get()
{
	if (!sInstance) sInstance = new DataManager();
	return sInstance;
}

DBCar* DataManager::GetCar(int id) 
{
	if (mCar) return mCar;
	std::string url = "http://riders.am/api/v1/car?car_id=" + std::to_string(id);

	//std::string cacert = AuthManager::Get()->GetCACert();
	cpr::Session session;
	session.SetUrl(cpr::Url{ url });

	// Specify the CA certificate path
	cpr::SslOptions ssl_options;
	//ssl_options.ca_info = cacert;
	//session.SetSslOptions(ssl_options);
	cpr::Response response = session.Get();

	if (response.status_code != 200)
	{
		return nullptr;
	}

	DBCarsResponse r = DBCar::ParseCarsFromJson(response.text);
	DBCar* pCar = r.Cars[0];
	mCar = pCar;
	int userId = pCar->UserId;
	ParseUser(userId);
	ParseMakes();
	ParseGMakes();
	return pCar;
}

std::string DataManager::ToUpperCase(const std::string& input) 
{
	std::string result;
	for (char c : input) {
		result += std::toupper(static_cast<unsigned char>(c));  // Use 'unsigned char' to avoid negative values
	}
	return result;
}

std::string DataManager::GetPrice()
{
	return formatMileage(mCar->Price) + " USD"; 
}

std::string DataManager::GetMileage()
{
	return formatMileage(mCar->Mileage) + " KM"; 
}

void DataManager::ParseUser(int userId)
{
	std::string url = "http://riders.am/api/v1/user?user_id=" + std::to_string(userId);

	//std::string cacert = AuthManager::Get()->GetCACert();
	cpr::Session session;
	session.SetUrl(cpr::Url{ url });

	// Specify the CA certificate path
	cpr::SslOptions ssl_options;
	//ssl_options.ca_info = cacert;
	//session.SetSslOptions(ssl_options);
	cpr::Response response = session.Get();

	if (response.status_code != 200)
	{
		return;
	}

	rapidjson::Document d;
	d.Parse(response.text.c_str());
	mUserName = d["first_name"].GetString();
	mUserPhone = d["phone"].GetString();

	mUserPhone = "0" + mUserPhone.substr(0, 2) + " " + mUserPhone.substr(2);
}

void DataManager::ParseMakes()
{
	std::string url = "http://riders.am/data/makes.json";

	//std::string cacert = AuthManager::Get()->GetCACert();
	cpr::Session session;
	session.SetUrl(cpr::Url{ url });

	// Specify the CA certificate path
	cpr::SslOptions ssl_options;
	//ssl_options.ca_info = cacert;
	//session.SetSslOptions(ssl_options);
	cpr::Response response = session.Get();

	if (response.status_code != 200)
	{
		return;
	}

	mMakes.Parse(response.text.c_str());
}

void DataManager::ParseGMakes()
{
	std::string url = "http://riders.am/data/gmakes.json";

	//std::string cacert = AuthManager::Get()->GetCACert();
	cpr::Session session;
	session.SetUrl(cpr::Url{ url });

	// Specify the CA certificate path
	cpr::SslOptions ssl_options;
	//ssl_options.ca_info = cacert;
	//session.SetSslOptions(ssl_options);
	cpr::Response response = session.Get();

	if (response.status_code != 200)
	{
		return;
	}

	mGMakes.Parse(response.text.c_str());
}

std::string DataManager::GetMake() 
{
	return ToUpperCase(mMakes[mCar->Make.c_str()].GetString()); 
}

std::string removeFirstWord(const std::string& str) {
	// Find the first space in the string
	size_t pos = str.find(' ');
	if (pos != std::string::npos) {
		// Create a substring from the character after the first space
		return str.substr(pos + 1);
	}
	// If no space is found, return an empty string or the original string depending on your use case
	return "";
}

std::string DataManager::GetEngine()
{	
	if (mEngine.IsNull()) mEngine = mGMakes[mCar->Make.c_str()][mCar->Class.c_str()][mCar->Model.c_str()][mCar->Submodel.c_str()];
	std::string engine = removeFirstWord(mEngine["title"].GetString());
	if (mCar->Make == "mercedesbenz") engine = removeFirstWord(engine);
	return ToUpperCase(engine);
}

#include <iomanip>
#include <sstream>
std::string DataManager::GetCyl() 
{
	rapidjson::Value& v = mEngine["engines"][mCar->EngineSize];
	std::ostringstream stream;
	stream << std::fixed << std::setprecision(1) << v["size"].GetFloat();
	std::string s = stream.str();
	return s + "L, " + v["cyl"].GetString();
}

int DataManager::GetPower()
{
	rapidjson::Value& v = mEngine["engines"][mCar->EngineSize];
	return v["power"].GetInt();
}