#include "Quantity.h"
#include <iostream>

Quantity::Quantity(int val) {
    set_quantity(val);
}

void Quantity::set_quantity(int val) {
    if (val <= 0) throw std::invalid_argument("quantity of product must be positive");
    this->value = val;
}

int Quantity::change_quantity(int delta) {
    if (delta < 0 && value < -delta) 
        throw std::invalid_argument("delta cannot be greater than the quantity");
    if (delta == 0) 
        throw std::invalid_argument("delta must be non‑zero.");
    this->value += delta;
    return this->value;
}