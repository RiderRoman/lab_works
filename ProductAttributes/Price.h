#pragma once

class Price {
    double value;
public:
    Price(double val);
    
    double get_price() const { return value; }
    
    void set_price(double val);
};