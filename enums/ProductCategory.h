#pragma once
#include <iostream>

enum class ProductCategory {
    electronics,
    food,
    clothes
};

inline std::ostream& operator<<(std::ostream& os, ProductCategory category) {
    switch(category) {
        case ProductCategory::electronics: os << "electronics"; break;
        case ProductCategory::food: os << "food"; break;
        case ProductCategory::clothes: os << "clothes"; break;
    }
    return os;
}