#include "Price.h"
#include <iostream>

Price::Price(double val) {
    set_price(val);
}

void Price::set_price(double val) {
    if (val <= 0.0) throw std::invalid_argument("price of product must be positive");
    this->value = val;
}