#include "Microwave.h"
#include <iostream>

Microwave::Microwave(const std::string& n, const Price& p, const Quantity& q, const Weight& w, ProductCategory c, 
    const Brand br, Color col, int pw, int cv) 
    : Electronics(n, p, q, w, c, br, col), chamber_volume(cv) {
        set_power(pw);
    }

void Microwave::set_power(int pw) {
    if (pw <= 0) throw std::invalid_argument("microwave power must be positive");
    this->power = pw;
}

void Microwave::set_chamber_volume(int cv) {
    if (cv <= 0) throw std::invalid_argument("microwave chamber volume must be positive");
    this->chamber_volume = cv;
}

void Microwave::print_info() const {
    Electronics::print_info();
    std::cout << "Power: " << this->power << " w\n"
    << "Chamber volume: " << this->chamber_volume << " l\n";
}

std::unique_ptr<Product> Microwave::clone() const {
    return std::make_unique<Microwave>(*this);
}