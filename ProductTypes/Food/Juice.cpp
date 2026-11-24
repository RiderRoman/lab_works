#include "Juice.h"
#include <iostream>

Juice::Juice(const std::string& n, const Price& p, const Quantity& q, const Weight& w, ProductCategory c, 
    int cal, double prot, double fat, double carb, double sug, int vol)
    : Food(n, p, q, w, c, cal, prot, fat, carb, sug) {
        set_volume(vol);
    }

void Juice::set_volume(int vol) {
    if (vol <= 0) throw std::invalid_argument("juice volume must be positive");
    this->volume = vol;
}

void Juice::print_info() const {
    Food::print_info();
    std::cout << "Volume: " << this->volume << " ml\n"; 
}

std::unique_ptr<Product> Juice::clone() const {
    return std::make_unique<Juice>(*this);
}
