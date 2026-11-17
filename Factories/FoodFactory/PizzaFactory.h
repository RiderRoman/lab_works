#pragma once
#include "ProductFactory.h"
#include "Pizza.h"

class PizzaFactory : public ProductFactory {
    int calories;
    double protein;
    double fats;
    double carbohydrates;
    double sugar;
    double radius;
public:
    PizzaFactory(int cal, double prot, double fat, double carb, double sug, double rad);

    std::unique_ptr<Product> create_product(
        int i, const std::string& n, const Price& p,
        const Quantity& q, const Weight& w) const override;
};