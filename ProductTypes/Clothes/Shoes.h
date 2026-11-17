#pragma once
#include "Clothes.h"

class Shoes : public Clothes{
    double shoe_size;
public:
    Shoes(int i, const std::string& n, const Price& p, const Quantity& q, const Weight& w, ProductCategory c,
    Color col, Fabric fab, Gender gen, double ss);

    double get_shoe_size() const { return this->shoe_size; }
    
    void set_shoe_size(double ss);

    Product* clone() const override;
    void print_info() const override;
};