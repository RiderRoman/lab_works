#pragma once
#include "ProductFactory.h"
#include "Microwave.h"

class MicrowaveFactory : public ProductFactory {
    Brand brand;
    Color color;
    int power;
    int chamber_volume;
public:
    MicrowaveFactory(Brand b, Color c, int pw, int cv);

    std::unique_ptr<Product> create_product(
        int i, const std::string& n, const Price& p,
        const Quantity& q, const Weight& w) const override;
};