#include "JuiceFactory.h"

JuiceFactory::JuiceFactory(int cal, double prot, double fat, double carb, double sug, int vol)
        : calories(cal), protein(prot), fats(fat), carbohydrates(carb), sugar(sug), volume(vol) {}

std::unique_ptr<Product> JuiceFactory::create_product(
        const std::string& n, const Price& p,
        const Quantity& q, const Weight& w) const {
            return std::make_unique<Juice>(
            n, p, q, w,
            ProductCategory::food,
            calories, protein, fats, carbohydrates, sugar, volume);
        }