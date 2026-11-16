#pragma once
#include "Food.h"

class Juice : public Food {
    int volume;
public:
    Juice(int i, const std::string& n, const Price& p, const Quantity& q, const Weight& w, ProductCategory c, WareHouse& wh, 
    int cal, double prot, double fat, double carb, double sug, int vol);

    int get_volume() const { return this->volume; }
    void set_volume(int vol);

    Product* clone() const override;
    void print_info() const override;
};