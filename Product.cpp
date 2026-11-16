#include "Product.h"
#include "CellPhone.h"
#include <iostream>
using namespace std;

Product::Product(int i, const std::string& n, const Price& p, const Quantity& q, 
    const Weight& w, ProductCategory c, WareHouse* wh) 
    : name(n), price(p), quantity(q), weight(w), category(c) , warehouse(nullptr)
  {
    set_id(i);
    if (wh != nullptr) {
        wh->add_product(this);
    }
  }

void Product::set_id(int i) {
    if (i < 0) throw std::invalid_argument("id must be positive");
    this->id = i;
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

void Product::transfer_to(WareHouse& other) {
    if (this->warehouse == &other) return;
    if (this->warehouse != nullptr) {
        this->warehouse->remove_product(this);
    }
    other.add_product(this);
}