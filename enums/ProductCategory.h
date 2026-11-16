#pragma once
#include <iostream>

enum class ProductCategory {
    electronics,
    food,
    clothes
};

inline std::ostream& operator<<(std::ostream& os, ProductCategory category) {
    switch(category) {
        case ProductCategory::electronics: os << "electronics";
        case ProductCategory::food: os << "food";
        case ProductCategory::clothes: os << "clothes";
    }
}