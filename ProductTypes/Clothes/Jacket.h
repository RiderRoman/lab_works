#pragma once
#include "Clothes.h"

class Jacket : public Clothes{
    double jacket_size;
public:
    Jacket(int i, const std::string& n, const Price& p, const Quantity& q, const Weight& w, ProductCategory c, WareHouse& wh,
    Color col, Fabric fab, Gender gen, double js);

    double get_jacket_size() const { return this->jacket_size; }
    
    void set_jacket_size(double js);

    Product* clone() const override;
    void print_info() const override;
};