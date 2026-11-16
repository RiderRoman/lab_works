#include "Resolution.h"
#include <iostream>

Resolution::Resolution(int w, int h) {
    set_width(w);
    set_height(h);
}

void Resolution::set_width(int w) {
    if (w <= 0) throw std::invalid_argument("resolution width power must be positive");
    this->width = w;
}

void Resolution::set_height(int h) {
    if (h <= 0) throw std::invalid_argument("resolution height must be positive");
    this->height = h;
}