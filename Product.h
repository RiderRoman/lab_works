#pragma once

#include "Price.h"
#include "Quantity.h"
#include "Weight.h"
#include <string>
#include <cstdint>
#include <memory>
#include "ProductCategory.h"

class Product {
protected:
    std::uint64_t id;
    std::string name;
    Price price;
    Quantity quantity;
    Weight weight;
    ProductCategory category;
private:
    static inline std::uint64_t next_id = 1;
public:
    Product(const std::string& n, const Price& p, const Quantity& q, 
        const Weight& w, ProductCategory c);

    virtual ~Product() = default;
    virtual std::unique_ptr<Product> clone() const = 0;

    int get_id() const { return id; }
    const std::string& get_name() const { return name; }
    Price get_price() const { return price; }
    Quantity get_quantity() const { return quantity; }
    Weight get_weight() const { return weight; }
    const ProductCategory get_category() const { return category; }

    void set_price(const Price& new_price);
    void set_quantity(int new_quantity);
    void set_weight(double new_weight);
    int change_quantity(int delta) { return this->quantity.change_quantity(delta); };

    virtual void print_info() const = 0;
};