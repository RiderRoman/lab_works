#pragma once
#include <iostream>

enum class Fabric {
    cotton,
    synthetic,
    polyester,
    wool,
    leather,
};

inline std::ostream& operator<<(std::ostream& os, Fabric fabric) {
    switch(fabric) {
        case Fabric::cotton: return os << "cotton";
        case Fabric::synthetic: return os << "synthetic";
        case Fabric::polyester: return os << "polyester";
        case Fabric::wool: return os << "wool";
        case Fabric::leather: return os << "leather";
    }
}