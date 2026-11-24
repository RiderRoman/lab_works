#include "Price.h"
#include <iostream>

Price::Price(std::int64_t val) {
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

void Price::set_price(std::int64_t val) {
    if (val <= 0) throw std::invalid_argument("price of product must be positive");
    this->value = val;
}