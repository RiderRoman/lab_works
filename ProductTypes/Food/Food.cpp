#include "Food.h"
#include <iostream>

Food::Food(const std::string& n, const Price& p, const Quantity& q, const Weight& w, ProductCategory c, 
    int cal, double prot, double fat, double carb, double sug) 
    : Product(n, p, q, w, c) 
    {
    set_calories(cal);
    set_protein(prot);
    set_fats(fat);
    set_carbohydrates(carb);
    set_sugar(sug);
    }

void Food::set_calories(int cal) {
    if (cal <= 0) throw std::invalid_argument("calories must be positive");
    this->calories = cal;
}

void Food::set_protein(double prot) {
    if (prot <= 0.0) throw std::invalid_argument("protein must be positive");
    this->protein = prot;
}

void Food::set_fats(double fat) {
    if (fat <= 0.0) throw std::invalid_argument("fats must be positive");
    this->fats = fat;
}

void Food::set_carbohydrates(double carb) {
    if (carb <= 0.0) throw std::invalid_argument("carbohydrates must be positive");
    this->carbohydrates = carb;
}

void Food::set_sugar(double sug) {
    if (sug <= 0.0) throw std::invalid_argument("sugar must be positive");
    this->sugar = sug;
}

void Food::print_info() const {
    Product::print_info();
    std::cout << "Calories: " << this-> calories << " kkal\n"
    << "Protein: " << this->protein << " g\n" 
    << "Fats: " << this->fats << " g\n"
    << "Carbohydrates: " << this->carbohydrates << " g\n"
    << "Sugar: " << this->sugar << " g\n";
}

std::unique_ptr<Product> Food::clone() const {
    return std::make_unique<Food>(*this);
}