#pragma once

#include "Price.h"
#include "Quantity.h"
#include "Weight.h"
#include <vector>
#include <string>
#include "ProductCategory.h"
#include "Warehouse.h"

class Product {
    friend class WareHouse;
protected:
    int id;
    std::string name;
    Price price;
    Quantity quantity;
    Weight weight;
    ProductCategory category;
    WareHouse* warehouse = nullptr;
public:
    Product(int i, const std::string& n, const Price& p, const Quantity& q, 
        const Weight& w, ProductCategory c, WareHouse* wh = nullptr);

    virtual ~Product() = default;
    virtual Product* clone() const = 0;

    int get_id() const { return id; }
    const std::string& get_name() const { return name; }
    Price get_price() const { return price; }
    Quantity get_quantity() const { return quantity; }
    Weight get_weight() const { return weight; }
    const ProductCategory get_category() const { return category; }
    const WareHouse* get_warehouse() const { return warehouse; }

    void set_id(int i);
    void set_price(const Price& new_price);
    void set_quantity(int new_quantity);
    void set_weight(double new_weight);
    void set_category(const ProductCategory c);
    void transfer_to(WareHouse& other);

    virtual void print_info() const = 0;
};

