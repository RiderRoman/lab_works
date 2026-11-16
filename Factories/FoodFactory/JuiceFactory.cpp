#include "JuiceFactory.h"

JuiceFactory::JuiceFactory(int cal, double prot, double fat, double carb, double sug, int vol)
        : calories(cal), protein(prot), fats(fat), carbohydrates(carb), sugar(sug), volume(vol) {}

std::unique_ptr<Product> JuiceFactory::create_product(
        int i, const std::string& n, const Price& p,
        const Quantity& q, const Weight& w, WareHouse& wh) const {
            return std::make_unique<Juice>(
            i, n, p, q, w,
            ProductCategory::food, wh,
            calories, protein, fats, carbohydrates, sugar, volume);
        }