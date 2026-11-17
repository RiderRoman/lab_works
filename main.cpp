#include "Product.h"
#include "Warehouse.h"
#include "CellPhoneFactory.h"
#include <iostream>

int main() {
    Resolution xiomi_resolutuion(1920, 1080);

    WareHouse wh1("WildBerries", "Saint-Petersburg", 100);
    CellPhoneFactory xiomi_factory(Brand::Xiomi, Color::white, 16384, xiomi_resolutuion, OperatingSystem::Android);

    auto p1 = xiomi_factory.create_product(
        1, 
        "Xiomi T17", 
        Price(25000), 
        Quantity(1), 
        Weight(215));
    
        p1->print_info();
        
        return 0;
}