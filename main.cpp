#include <iostream>
#include <iomanip>
#include <memory>
#include <stdexcept>
#include <string>

#include "Warehouse.h"
#include "Product.h"
#include "ProductAttributes/Price.h"
#include "ProductAttributes/Quantity.h"
#include "ProductAttributes/Weight.h"

#include "enums/Brand.h"
#include "enums/Color.h"
#include "enums/Fabric.h"
#include "enums/Gender.h"
#include "enums/OperatingSystem.h"
#include "enums/ProductCategory.h"

#include "Factories/ElectronicsFactory/CellPhoneFactory.h"
#include "Factories/ElectronicsFactory/MicrowaveFactory.h"
#include "Factories/ClothesFactory/JacketFactory.h"
#include "Factories/ClothesFactory/ShoesFactory.h"
#include "Factories/FoodFactory/JuiceFactory.h"
#include "Factories/FoodFactory/PizzaFactory.h"

void printSection(const std::string& title) {
    std::cout << "\n============================================================\n";
    std::cout << "  " << title << "\n";
    std::cout << "============================================================\n";
}

int main() {
    setlocale(LC_ALL, "RU");

    printSection("Создание склада");
    WareHouse mainWarehouse("WildBerries", "Saint-Petersburg", 6);

    std::cout << "Новый склад:\n";
    mainWarehouse.print_info();

    Resolution samsung_s24_resolution(2380, 1900);

    printSection("Фабричное создание 6 различных товаров и заполнение");
    CellPhoneFactory SamsungS24_factory(Brand::Samsung, Color::white, 16384, samsung_s24_resolution, OperatingSystem::Android);
    MicrowaveFactory Samsung_microwave_factory(Brand::Samsung, Color::black, 2000, 20);
    JacketFactory jacket_factory(Color::green, Fabric::cotton, Gender::male, 46.0);
    ShoesFactory shoes_factory(Color::black, Fabric::leather, Gender::female, 39.5);
    JuiceFactory juice_factory(110, 0.5, 2, 5, 5, 250);
    PizzaFactory pizza_factory(1253, 25, 30, 80, 4, 30.0);

    auto phone = SamsungS24_factory.create_product(
        "Samsung Galaxy S24", Price(6500000), Quantity(5), Weight(215)
    );

    auto microwave = Samsung_microwave_factory.create_product(
        "Микроволновка Samsung cheto-tam", Price(145000), Quantity(6), Weight(11500)
    );

    auto jacket = jacket_factory.create_product(
        "Куртка", Price(1290000), Quantity(8), Weight(1200)
    );

    auto shoes = shoes_factory.create_product(
        "Сапоги из кожи", Price(950000), Quantity(15), Weight(750)
    );

    auto juice = juice_factory.create_product(
        "Сок апельсиновый 250 мл", Price(18900), Quantity(40), Weight(1050)
    );

    auto pizza = pizza_factory.create_product(
        "Пицца пепперони", Price(69900), Quantity(25), Weight(580)
    );

    auto phoneId = phone->get_id();
    auto pizzaId = pizza->get_id();

    mainWarehouse.add_product(std::move(phone));
    mainWarehouse.add_product(std::move(microwave));
    mainWarehouse.add_product(std::move(jacket));
    mainWarehouse.add_product(std::move(shoes));
    mainWarehouse.add_product(std::move(juice));
    mainWarehouse.add_product(std::move(pizza));

    std::cout << "Добавили 6 товаров на склад.\n";
    mainWarehouse.print_info();


    printSection("Проверка двух независимых обходов итератора");
    auto it1 = mainWarehouse.begin();
    auto it2 = mainWarehouse.begin();

    if (it1 != mainWarehouse.end() && it2 != mainWarehouse.end()) {
        ++it1;
        ++it1;
        std::cout << "  Курсор 1 + 2 шага вперед: " << (*it1)->get_name() << " (ID=" << (*it1)->get_id() << ")\n";
        std::cout << "  Курсор 2 позиция не изменилась:    " << (*it2)->get_name() << " (ID=" << (*it2)->get_id() << ")\n";
        std::cout << "Курсоры независимы и не мешают друг другу.\n";
    }

    printSection("Проверка валидации атрибутов и сохранения состояния");

    try {
        std::cout << "price = -5000\n";
        Price bad_price(-5000);
    } catch (const std::exception& e) {
        std::cout << e.what() << "\n";
    }

    try {
        std::cout << "weight = -100\n";
        Weight bad_weight(-100);
    } catch (const std::exception& e) {
        std::cout << e.what() << "\n";
    }

    Quantity quantity(10);
    std::cout << "Кол-во = " << quantity.get_quantity() << ". Меняем на дельта = -15\n";
    try {
        quantity.change_quantity(-15);
    } catch (const std::exception& e) {
        std::cout << "error: " << e.what() << "\n";
    }

    printSection("Поиск, изменение характеристик, удаление и лимиты");

    std::cout << "Поиск товара с нормальным id\n";
    Product* found = mainWarehouse.find_product_by_id(phoneId);
    if (found != nullptr) {
        std::cout << "Найден товар по ID: " << phoneId << ": " << found->get_name() << "\n";
        found->set_price(Price(8499000));
        found->change_quantity(-2);
        std::cout << "После изменения цены и списания 2 шт.\nНовая цена: "
                  << found->get_price().get_price() << " коп.\nКоличество: "
                  << found->get_quantity().get_quantity() << " шт.\n";
    }

    std::cout << "Поиск товара с несуществующим id\n";
    Product* missing = mainWarehouse.find_product_by_id(999999);
    if (missing == nullptr) {
        std::cout << "Товар с ID 999999 не найден.\n";
    }

    try {
        std::cout << "Переполнение склада. +1 товар\n";
        auto extra_product = juice_factory.create_product(
            "Сок Яблочный", Price(15000), Quantity(10), Weight(1000)
        );
        mainWarehouse.add_product(std::move(extra_product));
    } catch (const std::exception& e) {
        std::cout << e.what() << "\n";
    }


    mainWarehouse.remove_product_by_id(pizzaId);
    std::cout << "Товар с ID: " << pizzaId << " (пицца) удален со склада\n";
    mainWarehouse.print_info();

    try {
        std::cout << "Попытка повторно удалить уже удаленный ID: " << pizzaId << "\n";
        mainWarehouse.remove_product_by_id(pizzaId);
    } catch (const std::exception& e) {
        std::cout << "Удаление отсутствующего товара отклонено: " << e.what() << "\n";
    }

    try {
        std::cout << "Попытка добавить клон телефона с уже существующим ID: " << phoneId << "\n";
        if (found != nullptr) {
            mainWarehouse.add_product(found->clone());
        }
    } catch (const std::exception& e) {
        std::cout << "Дубликат ID отклонен: " << e.what() << "\n";
    }
}
