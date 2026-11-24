#pragma once
#include "Food.h"

class Juice : public Food {
    int volume;
public:
    Juice(const std::string& n, const Price& p, const Quantity& q, const Weight& w, ProductCategory c, 
    int cal, double prot, double fat, double carb, double sug, int vol);

    int get_volume() const { return this->volume; }
    void set_volume(int vol);

    std::unique_ptr<Product> clone() const override;
    void print_info() const override;
};