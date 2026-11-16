#pragma once
#include "Food.h"

class Pizza : public Food {
    double radius;
public:
    Pizza(int i, const std::string& n, const Price& p, const Quantity& q, const Weight& w, ProductCategory c, WareHouse& wh, 
    int cal, double prot, double fat, double carb, double sug, double rad);

    double get_radius() const { return this->radius; }
    
    void set_radius(double radius);

    Product* clone() const override;
    void print_info() const override;
};