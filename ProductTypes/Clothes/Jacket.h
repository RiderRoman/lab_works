#pragma once
#include "Clothes.h"

class Jacket : public Clothes{
    double jacket_size;
public:
    Jacket(const std::string& n, const Price& p, const Quantity& q, const Weight& w, ProductCategory c,
    Color col, Fabric fab, Gender gen, double js);

    double get_jacket_size() const { return this->jacket_size; }
    
    void set_jacket_size(double js);

    std::unique_ptr<Product> clone() const override;
    void print_info() const override;
};