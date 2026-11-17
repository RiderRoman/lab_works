#pragma once

#include "Price.h"
#include "Quantity.h"
#include "Weight.h"
#include <vector>
#include <string>
#include "ProductCategory.h"

class Product {
protected:
    int id;
    std::string name;
    Price price;
    Quantity quantity;
    Weight weight;
    ProductCategory category;
public:
    Product(int i, const std::string& n, const Price& p, const Quantity& q, 
        const Weight& w, ProductCategory c);

    virtual ~Product() = default;
    virtual Product* clone() const = 0;

    int get_id() const { return id; }
    const std::string& get_name() const { return name; }
    Price get_price() const { return price; }
    Quantity get_quantity() const { return quantity; }
    Weight get_weight() const { return weight; }
    const ProductCategory get_category() const { return category; }

    void set_id(int i);
    void set_price(const Price& new_price);
    void set_quantity(int new_quantity);
    void set_weight(double new_weight);
    void set_category(const ProductCategory c);

    virtual void print_info() const = 0;
};