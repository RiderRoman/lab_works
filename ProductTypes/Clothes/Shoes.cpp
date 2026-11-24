#include "Shoes.h"
#include <iostream>

Shoes::Shoes(const std::string& n, const Price& p, const Quantity& q, const Weight& w, ProductCategory c,
    Color col, Fabric fab, Gender gen, double ss) 
    : Clothes(n, p, q, w, c, col, fab, gen) {
        set_shoe_size(ss);
    }

void Shoes::set_shoe_size(double ss) {
    if (ss <= 0.0) throw std::invalid_argument("shoe size must be positive");
    this->shoe_size = ss;
}

void Shoes::print_info() const {
    Clothes::print_info();
    std::cout << "Shoe size: " << this->shoe_size << "\n";
}

std::unique_ptr<Product> Shoes::clone() const {
    return std::make_unique<Shoes>(*this);
}
