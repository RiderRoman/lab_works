#pragma once

class Weight {
    double value;
public:
    Weight(double val);

    double get_weight() const { return value; }
    
    void set_weight(double val);
};