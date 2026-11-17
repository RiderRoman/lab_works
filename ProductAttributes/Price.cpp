#include "Price.h"
#include <iostream>

Price::Price(double val) {
    set_price(val);
}

Price& Price::operator=(const Price& other) {
    if (this == &other) return *this;
    this->value = other.value;
    return *this;
}

bool Price::operator==(const Price& other) const {
    return this->value == other.value;
}

void Price::set_price(double val) {
    if (val <= 0.0) throw std::invalid_argument("price of product must be positive");
    this->value = val;
}