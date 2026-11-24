#include "Product.h"
#include <iostream>
#include <stdexcept>

Product::Product(const std::string& n, const Price& p, const Quantity& q, 
    const Weight& w, ProductCategory c) 
    : name(n), price(p), quantity(q), weight(w), category(c) { 
        this->id = next_id++;
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

void Product::print_info() const {
    std::cout << "ID: " << id << "\n"
    << "Name: " << name << "\n"
    << "Quantity: " << quantity.get_quantity() << "\n"
    << "Price: " << price.get_price() / 100 << " RUB\n" // копейки в рубли
    << "Weight: " << weight.get_weight() << " g\n"
    << "Item category: " << category << "\n";
}