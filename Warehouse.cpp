#include "Warehouse.h"
#include <stdexcept>

WareHouse::WareHouse(const std::string& n, const std::string& a, int limit) 
    : name(n), address(a), product_limit(1) {
        set_limit(limit);
    }

// Копирование: каждый товар клонируется, поэтому у копии свои независимые товары
WareHouse::WareHouse(const WareHouse& other) 
    : name(other.name), address(other.address), product_limit(other.product_limit) {
        for (const std::unique_ptr<Product>& p : other.products) {
            products.push_back(std::unique_ptr<Product>(p->clone()));
        }
}

WareHouse& WareHouse::operator=(const WareHouse& other) {
    if (this == &other) return *this;

    // сначала делаем все копии, и только потом меняем себя:
    // если clone() бросит исключение, склад останется как был
    std::vector<std::unique_ptr<Product>> copies;
    for (const std::unique_ptr<Product>& p : other.products) {
        copies.push_back(std::unique_ptr<Product>(p->clone()));
    }
    name = other.name;
    address = other.address;
    product_limit = other.product_limit;
    products = std::move(copies);
    return *this;
}

// Перемещение: забираем товары, у other остаётся пустой, но рабочий склад
WareHouse::WareHouse(WareHouse&& other) noexcept 
    : name(std::move(other.name)), 
    address(std::move(other.address)), 
    products(std::move(other.products)),
    product_limit(other.product_limit) {
        other.products.clear();
}

WareHouse& WareHouse::operator=(WareHouse&& other) noexcept {
    if (this == &other) return *this;

    name = std::move(other.name);
    address = std::move(other.address);
    products = std::move(other.products);
    product_limit = other.product_limit;
    other.products.clear();
    return *this;
}

void WareHouse::set_name(const std::string& n) {
    this->name = n;
}

void WareHouse::set_address(const std::string& a) {
    this->address = a;
}

void WareHouse::set_limit(int lim) {
    if (lim <= 0) 
        throw std::invalid_argument("warehouse limit must be positive.");
    if (static_cast<size_t>(lim) < products.size()) 
        throw std::invalid_argument("the new limit is less than the number of products in the warehouse.");
    this->product_limit = lim;
}

void WareHouse::add_product(std::unique_ptr<Product> p) {
    if (p == nullptr)
        throw std::invalid_argument("product is null.");
    if (is_full()) 
        throw std::invalid_argument("it is not possible to add the product. the warehouse is full.");
    this->products.push_back(std::move(p));
}

// Товар удаляется совсем (unique_ptr сам освободит память)
bool WareHouse::remove_product(Product* p) {
    for (size_t i = 0; i < products.size(); i++) {
        if (products[i].get() == p) {
            products.erase(products.begin() + i);
            return true;
        }
    }
    return false;
}

bool WareHouse::remove_product_by_id(int id) {
    Product* p = find_product_by_id(id);
    return p && remove_product(p);
}

bool WareHouse::remove_product_by_index(int index) {
    if (index < 0 || static_cast<size_t>(index) >= products.size()) return false;
    products.erase(products.begin() + index);
    return true;
}

// Переносит товар с этого склада на другой вместе с владением.
// true - перенесли, false - такого id у нас нет
bool WareHouse::transfer_to(int id, WareHouse& other) {
    for (size_t i = 0; i < products.size(); i++) {
        if (products[i]->get_id() == id) {
            if (this == &other) return true;
            if (other.is_full())
                throw std::invalid_argument("the other warehouse is full.");
            other.products.push_back(std::move(products[i]));
            products.erase(products.begin() + i);
            return true;
        }
    }
    return false;
}

Product* WareHouse::find_product_by_id(int id) const {
    for (const std::unique_ptr<Product>& p : products) {
        if (p->get_id() == id) return p.get();
    }
    return nullptr;
}

std::vector<Product*> WareHouse::find_product_by_category(ProductCategory c) const {
    std::vector<Product*> result;
    for (const std::unique_ptr<Product>& p : products) {
        if (p->get_category() == c) result.push_back(p.get());
    }
    return result;
}

std::vector<Product*> WareHouse::find_product_by_price(const Price& price) const {
    std::vector<Product*> result;
    for (const std::unique_ptr<Product>& p : products) {
        if (p->get_price() == price) result.push_back(p.get());
    }
    return result;
}