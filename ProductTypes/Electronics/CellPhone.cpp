#include "CellPhone.h"
#include <iostream>

CellPhone::CellPhone(int i, const std::string& n, const Price& p, const Quantity& q, const Weight& w, ProductCategory c, 
    const Brand br, Color col, 
    int mem, Resolution sr, OperatingSystem os) 
    : Electronics(i, n, p, q, w, c, br, col), screen_resolution(sr), operating_system(os) {
        set_memoryMB(mem);
    }

void CellPhone::set_memoryMB(int mem) {
    if (mem <= 0) throw std::invalid_argument("cellphone memory must be positive");
    this->memoryMB = mem;
}

void CellPhone::set_operating_system(const OperatingSystem os) {
    this->operating_system = os;
}

void CellPhone::print_info() const {
    Electronics::print_info();
    std::cout << "Memory: " << this->memoryMB << " MB\n"
    << "Screen resolution: " << screen_resolution.get_screen_resolution() << " px\n"
    << "OperatingSystem: " << this->operating_system << "\n";
}

Product* CellPhone::clone() const {
    return new CellPhone(*this);
}