#pragma once
#include "ProductFactory.h"
#include "CellPhone.h"

class CellPhoneFactory : public ProductFactory {
    Brand brand;
    Color color;
    int memoryMB;
    Resolution resolution;
    OperatingSystem os;
public:
    CellPhoneFactory(Brand b, Color c, int mem, Resolution r, OperatingSystem o);

    std::unique_ptr<Product> create_product(
        int i, const std::string& n, const Price& p,
        const Quantity& q, const Weight& w) const override;
};