#include "Pizza.h"
#include <iostream>

Pizza::Pizza(int i, const std::string& n, const Price& p, const Quantity& q, const Weight& w, ProductCategory c, 
    int cal, double prot, double fat, double carb, double sug, double rad) 
    : Food(i, n, p, q, w, c, cal, prot, fat, carb, sug) {
        set_radius(rad);
    }

void Pizza::set_radius(double rad) {
    if (rad <= 0.0) throw std::invalid_argument("pizza radius must be positive");
    this->radius = rad;
}

void Pizza::print_info() const {
    Food::print_info();
    std::cout << "Pizza radius: " << this->radius << " cm\n";
}

Product* Pizza::clone() const {
    return new Pizza(*this);
}
