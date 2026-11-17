#include "Juice.h"
#include <iostream>

Juice::Juice(int i, const std::string& n, const Price& p, const Quantity& q, const Weight& w, ProductCategory c, 
    int cal, double prot, double fat, double carb, double sug, int vol)
    : Food(i, n, p, q, w, c, cal, prot, fat, carb, sug) {
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

Product* Juice::clone() const {
    return new Juice(*this);
}
