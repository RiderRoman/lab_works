#pragma once
#include <iostream>

enum class OperatingSystem {
    Android,
    IOS,
    HarmonyOS,
    HyperOS
};

inline std::ostream& operator<<(std::ostream& os, OperatingSystem operating_system) {
    switch(operating_system) {
        case OperatingSystem::Android: os << "Android"; break;
        case OperatingSystem::IOS: os << "IOS"; break;
        case OperatingSystem::HarmonyOS: os << "HarmonyOS"; break;
        case OperatingSystem::HyperOS: os << "HyperOS"; break;
    }
    return os;
}