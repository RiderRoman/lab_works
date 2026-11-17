#pragma once
#include <memory>
#include <string>
#include <vector>
#include "Product.h"

class WareHouse {
    std::string name;
    std::string address;
    std::vector<std::unique_ptr<Product>> products;   // склад владеет товарами
    int product_limit;
public:
    WareHouse(const std::string& n, const std::string &a, int limit);

    ~WareHouse() = default;
    WareHouse(const WareHouse& other);
    WareHouse& operator=(const WareHouse& other);
    WareHouse(WareHouse&& other) noexcept;
    WareHouse& operator=(WareHouse&& other) noexcept;

    const std::string& get_name() const { return this->name; }
    const std::string& get_address() const { return this->address; }
    const std::vector<std::unique_ptr<Product>>& get_products() const { return this->products; }
    int get_limit() const { return this->product_limit; }
    size_t get_size() const { return this->products.size(); }
    bool is_full() const { return this->products.size() >= static_cast<size_t>(this->product_limit); }

    void set_name(const std::string& new_name);
    void set_address(const std::string& new_address);
    void set_limit(int new_limit);

    void add_product(std::unique_ptr<Product> p);
    bool remove_product(Product* p);
    bool remove_product_by_index(int index);
    bool remove_product_by_id(int id);
    bool transfer_to(int id, WareHouse& other);

    Product* find_product_by_id(int id) const;
    std::vector<Product*> find_product_by_category(ProductCategory c) const;
    std::vector<Product*> find_product_by_price(const Price& price) const;

    auto begin() { return products.begin(); }
    auto end() { return products.end(); }
    auto begin() const { return products.begin(); }
    auto end() const { return products.end(); }
};