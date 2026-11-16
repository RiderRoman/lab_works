#pragma once

class Quantity {
    int value;
public:
    Quantity(int val);

    int get_quantity() const { return value; }
    
    void set_quantity(int val);
};