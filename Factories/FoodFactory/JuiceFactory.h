#pragma once
#include "ProductFactory.h"
#include "Juice.h"

class JuiceFactory : public ProductFactory {
    int calories;
    double protein;
    double fats;
    double carbohydrates;
    double sugar;
    int volume;
public:
    JuiceFactory(int cal, double prot, double fat, double carb, double sug, int vol);

    std::unique_ptr<Product> create_product(
        int i, const std::string& n, const Price& p,
        const Quantity& q, const Weight& w, WareHouse& wh) const override;
};