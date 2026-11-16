#include "Clothes.h"
#include <iostream>

Clothes::Clothes(int i, const std::string& n, const Price& p, const Quantity& q, const Weight& w, ProductCategory c, WareHouse& wh,
    Color col, Fabric fab, Gender gen) 
    : Product(i, n, p, q, w, c, wh), color(col), fabric(fab), gender(gen) {}

void Clothes::set_color(const Color col) {
    this->color = col;
}

void Clothes::set_fabric(const Fabric fab) {
    this->fabric = fab;
}

void Clothes::set_gender(const Gender gen) {
    this->gender = gen;
}

void Clothes::print_info() const {
    Product::print_info();
    std::cout << "Color: " << this->color << "\n"
    << "Fabric: " << this->fabric << "\n"
    << "Gender: " << this->gender << "\n";
}

Product* Clothes::clone() const {
    return new Clothes(*this);
}