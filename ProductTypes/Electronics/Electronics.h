#pragma once
#include "Product.h"
#include "Color.h"

#include "Brand.h"

class Electronics : public Product {
    Brand brand;
    Color color;
public:
    Electronics(const std::string& n, const Price& p, const Quantity& q, const Weight& w, ProductCategory c, 
    const Brand br, Color col);

    const Brand get_brand() const { return this->brand; }
    const Color get_color() const { return this->color; }

    void set_brand(const Brand br);
    void set_color(const Color col);

    void print_info() const override;
    std::unique_ptr<Product> clone() const override;
};