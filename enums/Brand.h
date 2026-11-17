#pragma once
#include <iostream>

enum class Brand {
    Samsung,
    Apple,
    Honor,
    Huawei,
    Xiomi,
    NothingPhone,
    OnePlus
};

inline std::ostream& operator<<(std::ostream& os, Brand brand) {
    switch(brand) {
        case Brand::Samsung: return os << "Samsung"; break;
        case Brand::Apple: return os << "Apple"; break;
        case Brand::Honor: return os << "Honor"; break;
        case Brand::Huawei: return os << "Huawei"; break;
        case Brand::Xiomi: return os << "Xiomi"; break;
        case Brand::NothingPhone: return os << "NothingPhone"; break;
        case Brand::OnePlus: return os << "OnePlus"; break;
    }
    return os;
}