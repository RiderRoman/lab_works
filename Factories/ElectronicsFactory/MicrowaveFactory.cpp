#include "MicrowaveFactory.h"

MicrowaveFactory::MicrowaveFactory(Brand b, Color c, int pw, int cv)
        : brand(b), color(c), power(pw), chamber_volume(cv) {}

std::unique_ptr<Product> MicrowaveFactory::create_product(
        const std::string& n, const Price& p,
        const Quantity& q, const Weight& w) const {
            return std::make_unique<Microwave>(
        n, p, q, w,
            ProductCategory::electronics,
            brand, color, power, chamber_volume);
        }