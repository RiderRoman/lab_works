#pragma once
#include <memory>
#include "Product.h"

class ProductFactory {
public:
    virtual ~ProductFactory() = default;
    virtual std::unique_ptr<Product> create_product(
        int id, const std::string& name, const Price& price, 
        const Quantity& q, const Weight& weight) const = 0;
};