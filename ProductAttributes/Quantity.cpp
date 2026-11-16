#include "Quantity.h"
#include <iostream>

Quantity::Quantity(int val) {
    set_quantity(val);
}

void Quantity::set_quantity(int val) {
    if (val <= 0) throw std::invalid_argument("quantity of product must be positive");
    this->value = val;
}