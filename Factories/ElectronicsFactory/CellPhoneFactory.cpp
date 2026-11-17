#include "CellPhoneFactory.h"


CellPhoneFactory::CellPhoneFactory(Brand b, Color c, int mem, Resolution r, OperatingSystem o)
        : brand(b), color(c), memoryMB(mem), resolution(r), os(o) {}

std::unique_ptr<Product> CellPhoneFactory::create_product(
        int i, const std::string& n, const Price& p,
        const Quantity& q, const Weight& w) const {
            return std::make_unique<CellPhone>(
            i, n, p, q, w,
            ProductCategory::electronics,
            brand, color, memoryMB, resolution, os);
        }