#include "Weight.h"
#include <iostream>

Weight::Weight(double val) {
    set_weight(val);
}

void Weight::set_weight(double val) {
    if (val <= 0.0) throw std::invalid_argument("weight of product must be positive");
    this->value = val;
}