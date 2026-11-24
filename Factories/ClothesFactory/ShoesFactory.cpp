#include "ShoesFactory.h"

ShoesFactory::ShoesFactory(Color col, Fabric fab, Gender gen, double ss)
        : color(col), fabric(fab), gender(gen), shoe_size(ss) {}

std::unique_ptr<Product> ShoesFactory::create_product(
        const std::string& n, const Price& p,
        const Quantity& q, const Weight& w) const {
            return std::make_unique<Shoes>(
            n, p, q, w,
            ProductCategory::clothes,
            color, fabric, gender, shoe_size);
        }