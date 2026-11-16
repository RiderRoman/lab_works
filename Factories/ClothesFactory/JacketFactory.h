#pragma once
#include "ProductFactory.h"
#include "Jacket.h"

class JacketFactory : public ProductFactory {
    Color color;
    Fabric fabric;
    Gender gender;
    double jacket_size;
public:
    JacketFactory(Color col, Fabric fab, Gender gen, double js);

    std::unique_ptr<Product> create_product(
        int i, const std::string& n, const Price& p,
        const Quantity& q, const Weight& w, WareHouse& wh) const override;
};