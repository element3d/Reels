#pragma once

#include <string>
#include <vector>
#include <rapidjson/rapidjson.h>
#include <rapidjson/document.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>

struct DBImage
{
    unsigned char* Data;
    int Width;
    int Height;
    bool IsAvatar;
    int Id;
    int Index;
    std::string Filename;
    std::string Url;
    bool IsRemote = false;
};

class DBCar;
struct DBCarsResponse
{
    int TotalNumCars = 0;
    std::vector<DBCar*> Cars;
};

class DBCar {
public:
    int Id;
    int UserId;
    std::string Make;
    std::string Class;
    std::string Model;
    std::string Submodel;
    int Country;
    int Province = -1;
    int SubProvince;
    int Price;
    int BodyType = -1;
    int Year;
    int EngineType;
    double EngineSize = -1;
    int EnginePower;
    int DriveType = -1;
    int Transmission = -1;
    int StearingWheel;
    int Exchange;
    int CustomsCleared;
    int Color = -1;
    int Mileage;
    std::string Description;
    int AvatarImageId;
    int OnSale;
    int OnTop;
    double RefreshTs;
    int Rank;
    int Views;
    std::string Avatar;
    std::vector<DBImage> Images;
    bool IsNew = false;

    static DBCarsResponse ParseCarsFromJson(const std::string& json)
    {
        DBCarsResponse res;

        rapidjson::Document document;
        document.Parse(json.c_str());

        if (!document.IsObject() || !document.HasMember("cars")) {
            // std::cout << "Invalid JSON format." << std::endl;
            return res;
        }

        res.TotalNumCars = document["totalNumCars"].GetInt();

        const rapidjson::Value& carsArray = document["cars"];
        for (rapidjson::SizeType i = 0; i < carsArray.Size(); ++i) {
            const rapidjson::Value& carJson = carsArray[i];
            DBCar* car = new DBCar();
            car->Id = carJson["id"].GetInt();
            car->UserId = carJson["user_id"].GetInt();
            car->Make = carJson["make"].GetString();
            car->Class = carJson["class"].GetString();
            car->Model = carJson["model"].GetString();
            car->Submodel = carJson["submodel"].GetString();
            car->Country = carJson["country"].GetInt();
            car->Province = carJson["province"].GetInt();
            car->SubProvince = carJson["sub_province"].GetInt();
            car->Price = carJson["price"].GetInt();
            car->BodyType = carJson["body_type"].GetInt();
            car->Year = carJson["year"].GetInt();
            car->EngineType = carJson["engine_type"].GetInt();
            car->EngineSize = carJson["engine_size"].GetDouble();
            car->EnginePower = carJson["engine_power"].GetInt();
            car->DriveType = carJson["drive_type"].GetInt();
            car->Transmission = carJson["transmission"].GetInt();
            car->StearingWheel = carJson["stearing_wheel"].GetInt();
            car->Exchange = carJson["exchange"].GetInt();
            car->CustomsCleared = carJson["customs_cleared"].GetInt();
            car->Color = carJson["color"].GetInt();
            car->Mileage = carJson["mileage"].GetInt();
            car->Description = carJson["description"].GetString();
            car->AvatarImageId = carJson["avatar_image_id"].GetInt();
            car->OnSale = carJson["on_sale"].GetInt();
            car->OnTop = carJson["on_top"].GetInt();
            car->RefreshTs = carJson["refresh_ts"].GetDouble();
            car->Rank = carJson["rank"].GetInt();
            if (carJson.HasMember("views")) car->Views = carJson["views"].GetInt();

            const rapidjson::Value& imagesArray = carJson["images"];
            for (rapidjson::SizeType j = 0; j < imagesArray.Size(); ++j) 
            {
                const rapidjson::Value& imageJson = imagesArray[j];
                int id = imageJson["id"].GetInt();
                if (car->AvatarImageId == id) car->Avatar = imageJson["uri"].GetString();
                DBImage im;
                im.Url = imageJson["uri"].GetString();
                im.Index = imageJson["id"].GetInt();
                im.Id = imageJson["id"].GetInt();
                car->Images.push_back(im);
            }

            res.Cars.push_back(car);
        }

        return res;
    }

    std::string ToJson() const {
        rapidjson::StringBuffer s;
        rapidjson::Writer<rapidjson::StringBuffer> writer(s);

        writer.StartObject();
     
        writer.Key("UserId");
        writer.Int(UserId);
        writer.Key("make");
        writer.String(Make.c_str());
        writer.Key("class");
        writer.String(Class.c_str());
        writer.Key("model");
        writer.String(Model.c_str());
        writer.Key("submodel");
        writer.String(Submodel.c_str());
        writer.Key("country");
        writer.Int(Country);
        writer.Key("province");
        writer.Int(Province);
        writer.Key("sub_province");
        writer.Int(SubProvince);
        writer.Key("price");
        writer.Int(Price);
        writer.Key("body_type");
        writer.Int(BodyType);
        writer.Key("year");
        writer.Int(Year);
        writer.Key("engine_type");
        writer.Int(EngineType);
        writer.Key("engine_size");
        writer.Double(EngineSize);
        writer.Key("engine_power");
        writer.Int(EnginePower);
        writer.Key("drive_type");
        writer.Int(DriveType);
        writer.Key("transmission");
        writer.Int(Transmission);
        writer.Key("stearing_wheel");
        writer.Int(StearingWheel);
        writer.Key("exchange");
        writer.Int(Exchange);
        writer.Key("customs_cleared");
        writer.Int(CustomsCleared);
        writer.Key("color");
        writer.Int(Color);
        writer.Key("mileage");
        writer.Int(Mileage);
        writer.Key("description");
        writer.String(Description.c_str());
        writer.Key("on_sale");
        writer.Int(OnSale);
        writer.Key("on_top");
        writer.Int(OnTop);
     
        writer.EndObject();

        return s.GetString();
    }
};


