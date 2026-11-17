#include "Product.h"
#include <iostream>
#include <stdexcept>

Product::Product(int i, const std::string& n, const Price& p, const Quantity& q, 
    const Weight& w, ProductCategory c) 
    : id(0), name(n), price(p), quantity(q), weight(w), category(c)
  {
    set_id(i);
  }

void Product::set_id(int i) {
    if (i < 0) throw std::invalid_argument("id must be positive");
    id = i;
}

void Product::set_price(const Price& new_price) {
    this->price = new_price;
}

void Product::set_quantity(int new_quantity) {
    this->quantity.set_quantity(new_quantity);
}

void Product::set_weight(double new_weight) {
    this->weight.set_weight(new_weight);
}

void Product::set_category(ProductCategory c) {
    this->category = c;
}

void Product::print_info() const {
    std::cout << "ID: " << id << "\n"
    << "Name: " << name << "\n"
    << "Quantity: " << quantity.get_quantity() << "\n";
}