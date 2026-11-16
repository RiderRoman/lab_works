#pragma once
#include "Product.h"

class WareHouse {
    std::string name;
    std::string address;
    std::vector<Product*> products;
    int product_limit;

    void clear() noexcept;
public:
    WareHouse(const std::string& n, const std::string &a, int limit);

    ~WareHouse();
    WareHouse(const WareHouse& other);
    WareHouse& operator=(const WareHouse& other);
    WareHouse(WareHouse&& other) noexcept;
    WareHouse& operator=(WareHouse&& other) noexcept;

    const std::string& get_name() const { return this->name; }
    const std::string& get_address() const { return this->address; }
    const std::vector<Product*>& get_products() const { return this->products; }
    int get_limit() const { return this->product_limit; }

    void set_name(const std::string& new_name);
    void set_address(const std::string& new_address);
    void set_limit(int new_limit);

    void add_product(Product* p);
    bool remove_product(Product* p);
    bool remove_product_by_index(int index);
    bool remove_product_by_id(int id);

    Product* find_product_by_id(int id) const;
    std::vector<Product*> find_product_by_category(ProductCategory c) const;

    auto begin() { return products.begin(); }
    auto end() { return products.end(); }
    auto begin() const { return products.begin(); }
    auto end() const { return products.end(); }
};