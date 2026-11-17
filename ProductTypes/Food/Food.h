#pragma once
#include "Product.h"

class Food : public Product {
    int calories;
    double protein;
    double fats;
    double carbohydrates;
    double sugar;
public:
    Food(int i, const std::string& n, const Price& p, const Quantity& q, const Weight& w, ProductCategory c, 
    int cal, double prot, double fat, double carb, double sug);

    int get_calories() const { return this->calories; }
    double get_protein() const { return this->protein; }
    double get_fats() const { return this->fats; }
    double get_carbohydrates() const { return this->carbohydrates; }
    double get_sugar() const { return this->sugar; }

    void set_calories(int cal);
    void set_protein(double prot);
    void set_fats(double fat);
    void set_carbohydrates(double carb);
    void set_sugar(double sug);

    void print_info() const override;
    Product* clone() const override;
};