#pragma once
#include "Product.h"
#include "Fabric.h"
#include "Color.h"
#include "Gender.h"

class Clothes : public Product {
    Color color;
    Fabric fabric;
    Gender gender;
public:
    Clothes(int i, const std::string& n, const Price& p, const Quantity& q, const Weight& w, ProductCategory c,
    Color col, Fabric fab, Gender gen);

    const Color get_color() const { return this->color; }
    const Fabric get_fabric() const { return this->fabric; }
    const Gender get_gender() const { return this->gender; }

    void set_color(const Color col);
    void set_fabric(const Fabric fab);
    void set_gender(const Gender gen);

    void print_info() const override;
    Product* clone() const override;
};