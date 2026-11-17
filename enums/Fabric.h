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
        case Fabric::cotton: return os << "cotton"; break;
        case Fabric::synthetic: return os << "synthetic"; break;
        case Fabric::polyester: return os << "polyester"; break;
        case Fabric::wool: return os << "wool"; break;
        case Fabric::leather: return os << "leather"; break;
    }
    return os;
}