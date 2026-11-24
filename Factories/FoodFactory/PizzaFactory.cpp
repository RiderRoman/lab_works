#include "PizzaFactory.h"

PizzaFactory::PizzaFactory(int cal, double prot, double fat, double carb, double sug, double rad)
        : calories(cal), protein(prot), fats(fat), carbohydrates(carb), sugar(sug), radius(rad) {}

std::unique_ptr<Product> PizzaFactory::create_product(
        const std::string& n, const Price& p,
        const Quantity& q, const Weight& w) const {
            return std::make_unique<Pizza>(
            n, p, q, w,
            ProductCategory::food,
            calories, protein, fats, carbohydrates, sugar, radius);
        }