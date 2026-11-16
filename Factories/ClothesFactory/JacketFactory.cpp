#include "JacketFactory.h"

JacketFactory::JacketFactory(Color col, Fabric fab, Gender gen, double js)
        : color(col), fabric(fab), gender(gen), jacket_size(js) {}

std::unique_ptr<Product> JacketFactory::create_product(
        int i, const std::string& n, const Price& p,
        const Quantity& q, const Weight& w, WareHouse& wh) const {
            return std::make_unique<Jacket>(
            i, n, p, q, w,
            ProductCategory::clothes, wh,
            color, fabric, gender, jacket_size);
        }