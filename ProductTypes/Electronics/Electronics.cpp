#include "Electronics.h"
#include <iostream>

Electronics::Electronics(const std::string& n, const Price& p, const Quantity& q, const Weight& w, ProductCategory c, 
    const Brand br, Color col) 
    : Product(n, p, q, w, c), 
    brand(br), 
    color(col) {}

void Electronics::set_brand(Brand br) {
    this->brand = br;
}

void Electronics::set_color(Color col) {
    this->color = col;
}

void Electronics::print_info() const {
    Product::print_info();
    std::cout << "Brand: " << this->brand << "\n"
    << "Color: " << this->color << "\n";
}

std::unique_ptr<Product> Electronics::clone() const {
    return std::make_unique<Electronics>(*this);
}