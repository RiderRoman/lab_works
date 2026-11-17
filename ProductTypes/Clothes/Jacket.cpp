#include "Jacket.h"
#include <iostream>

Jacket::Jacket(int i, const std::string& n, const Price& p, const Quantity& q, const Weight& w, ProductCategory c,
    Color col, Fabric fab, Gender gen, double js) 
    : Clothes(i, n , p, q, w , c, col, fab, gen) {
        set_jacket_size(js);
    }

void Jacket::set_jacket_size(double js) {
    if (js <= 0) throw std::invalid_argument("jacket size must be positive");
    this->jacket_size = js;
}

void Jacket::print_info() const {
    Clothes::print_info();
    std::cout << "Jacket size: " << this->jacket_size << "\n";
}

Product* Jacket::clone() const {
    return new Jacket(*this);
}
