#pragma once
#include "ProductFactory.h"
#include "Shoes.h"

class ShoesFactory : public ProductFactory {
    Color color;
    Fabric fabric;
    Gender gender;
    double shoe_size;
public:
    ShoesFactory(Color col, Fabric fab, Gender gen, double ss);

    std::unique_ptr<Product> create_product(
        const std::string& n, const Price& p,
        const Quantity& q, const Weight& w) const override;
};