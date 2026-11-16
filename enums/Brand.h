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
        case Brand::Samsung: return os << "Samsung";
        case Brand::Apple: return os << "Apple";
        case Brand::Honor: return os << "Honor";
        case Brand::Huawei: return os << "Huawei";
        case Brand::Xiomi: return os << "Xiomi";
        case Brand::NothingPhone: return os << "NothingPhone";
        case Brand::OnePlus: return os << "OnePlus";
    }
}