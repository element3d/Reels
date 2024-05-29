#pragma once

#include <string>

class EDriveType 
{
public:
    static const int None = -2;
    static const int All = -1;
    static const int RearWheelDrive = 0;
    static const int FrontWheelDrive = 1;
    static const int AllWheelDrive = 2;
    static const int End = EDriveType::AllWheelDrive;

    static std::string ToString(int driveType) 
    {
        switch (driveType) {
        case All:
            return "all";
        case RearWheelDrive:
            return "rear_wheel_drive";
        case FrontWheelDrive:
            return "front_wheel_drive";
        case AllWheelDrive:
            return "all_wheel_drive";
        }

        return "???";
    }
};
