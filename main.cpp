#include "Product.h"
#include "Warehouse.h"
#include "CellPhoneFactory.h"
#include <iostream>

int main() {
    Resolution xiomi_resolutuion(1920, 1080);

    WareHouse wh1("WildBerries", "Saint-Petersburg", 100);
    CellPhoneFactory redmi_Note15_factory(Brand::Xiomi, Color::white, 16384, xiomi_resolutuion, OperatingSystem::Android);

    
    
    for (int i = 0; i < 20; i++) {
        auto p1 = redmi_Note15_factory.create_product(
            1, 
            "redmi Note 15", 
            Price(25000), 
            Quantity(1), 
            Weight(215)
        );
        
        wh1.add_product(std::move(p1));
    }
    wh1.print_info();
    return 0;
}