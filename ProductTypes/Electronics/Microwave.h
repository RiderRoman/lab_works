#pragma once
#include "Electronics.h"

class Microwave : public Electronics {
    int power;
    int chamber_volume;
public:
    Microwave(int i, const std::string& n, const Price& p, const Quantity& q, const Weight& w, ProductCategory c, 
    const Brand br, Color col, int pw, int cv);

    int get_power() const { return this->power; }
    int get_chamber_volume() const { return this->chamber_volume; }

    void set_power(int pw);
    void set_chamber_volume(int cv);

    void print_info() const override;
    Product* clone() const override;
};