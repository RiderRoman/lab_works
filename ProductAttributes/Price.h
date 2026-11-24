#pragma once
#include <cstdint>

class Price {
    std::int64_t value;
public:
    Price(std::int64_t val);
    Price& operator=(const Price& other);
    
    bool operator==(const Price& other) const;
    std::int64_t get_price() const { return this->value; }
    
    void set_price(std::int64_t val);
};