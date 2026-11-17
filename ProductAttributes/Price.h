#pragma once

class Price {
    double value;
public:
    Price(double val);
    Price& operator=(const Price& other);
    
    bool operator==(const Price& other) const;
    double get_price() const { return value; }
    
    void set_price(double val);
};