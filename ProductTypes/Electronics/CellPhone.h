#pragma once
#include <string>
#include "Electronics.h"
#include "Resolution.h"
#include "OperatingSystem.h"

class CellPhone : public Electronics {
    int memoryMB;
    Resolution screen_resolution;
    OperatingSystem operating_system;
public:
    CellPhone(int i, const std::string& n, const Price& p, const Quantity& q, const Weight& w, ProductCategory c, WareHouse& wh, 
    const Brand br, Color col, 
    int mem, Resolution sr, OperatingSystem os);
    
    const Resolution& get_screen_resolution() const { return this->screen_resolution; }
    std::string get_screen_resolution_str() const { return this->screen_resolution.get_screen_resolution(); }
    int get_memoryMB() const { return this->memoryMB; }
    const OperatingSystem get_operating_system() const { return this->operating_system; }

    void set_screen_resolution(size_t width, size_t height);
    void set_memoryMB(int mem);
    void set_operating_system(const OperatingSystem os);

    void print_info() const override;
    Product* clone() const override;
};