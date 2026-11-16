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
        case OperatingSystem::Android: os << "Android";
        case OperatingSystem::IOS: os << "IOS";
        case OperatingSystem::HarmonyOS: os << "HarmonyOS";
        case OperatingSystem::HyperOS: os << "HyperOS";
    }
}