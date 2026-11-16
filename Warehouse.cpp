#include "Warehouse.h"

WareHouse::WareHouse(const std::string& n, const std::string& a, int limit) 
    : name(n), address(a), product_limit(1) {
        set_limit(limit);
    }

void WareHouse::clear() noexcept {
    for (Product* p : products) {
        delete p;
    }
    products.clear();
}

WareHouse::~WareHouse() {
    clear();
}

WareHouse::WareHouse(const WareHouse& other) 
    : name(other.name), address(other.address), product_limit(other.product_limit) {
        for (const Product* p : other.products) {
            Product* copy = p->clone();
            copy->warehouse = this;
            products.push_back(copy);
        }
}

WareHouse& WareHouse::operator=(const WareHouse& other) {
    if (this == &other) return *this;

    clear();
    name = other.name;
    address = other.address;
    product_limit = other.product_limit;

    for (const Product* p : other.products) {
        Product* copy = p->clone();
        copy->warehouse = this;
        products.push_back(copy);
    }
    return *this;
}

WareHouse::WareHouse(WareHouse&& other) noexcept 
    : name(std::move(other.name)), 
    address(std::move(other.address)), 
    products(std::move(other.products)),
    product_limit(other.product_limit) {
        for (Product* p : products) {
            p->warehouse = this;
        }
        other.product_limit = 0;
}

WareHouse& WareHouse::operator=(WareHouse&& other) noexcept {
    if (this == &other) return *this;

    clear();
    name = std::move(other.name);
    address = std::move(other.address);
    products = std::move(other.products);
    product_limit = other.product_limit;

    for (Product* p : products) {
        p->warehouse = this;
    }
    other.product_limit = 0;
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
    if (lim <= products.size()) 
        throw std::invalid_argument("the new limit is less than or equal to the previous one.");
    this->product_limit = lim;
}

void WareHouse::add_product(Product* p) {
    if (products.size() >= get_limit()) 
        throw std::invalid_argument("it is not possible to add the product. the warehouse is full.");
    this->products.push_back(p);
}

bool WareHouse::remove_product(Product* p) {
    if (products.size() == 0) return false;
    size_t before = products.size();
    products.erase(std::remove(products.begin(), products.end(), p), products.end());
    return products.size() != before;
}

bool WareHouse::remove_product_by_id(int id) {
    Product* p = find_product_by_id(id);
    return p && remove_product(p);
}

bool WareHouse::remove_product_by_index(int index) {
    if (products.size() == 0)
        throw std::invalid_argument("there are no items in warehouse.");
    if (index >= products.size() || index < 0) return false;
    return remove_product(products[index]);
}

Product* WareHouse::find_product_by_id(int id) const {
    if (products.size() == 0)
        throw std::invalid_argument("there are no items in warehouse.");
    for (Product* p : products) {
        if (p->get_id() == id) return p;
    }
    return nullptr;
}
