#include "ShoesFactory.h"

ShoesFactory::ShoesFactory(Color col, Fabric fab, Gender gen, double ss)
        : color(col), fabric(fab), gender(gen), shoe_size(ss) {}

std::unique_ptr<Product> ShoesFactory::create_product(
        int i, const std::string& n, const Price& p,
        const Quantity& q, const Weight& w, WareHouse& wh) const {
            return std::make_unique<Shoes>(
            i, n, p, q, w,
            ProductCategory::clothes, wh,
            color, fabric, gender, shoe_size);
        }