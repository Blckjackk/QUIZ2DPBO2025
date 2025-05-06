// Saya Ahmad Izzuddin Azzam dengan NIM 2300492 mengerjakan Quiz 2 dalam 
// mata kuliah Desain Pemograman Berorientasi Objek untuk keberkahanNya maka saya tidak melakukan 
// kecurangan seperti yang telah dispesifikasikan. Aamiin.

#pragma once
#include <vector>
#include <map>
#include <iostream>
#include "Fruit.h"
#include "Drink.h"
#include "Customer.h"
#include "../exceptions/InvalidFruitException.h"
#include "../exceptions/OrderException.h"

using namespace std;


class JuiceShop {
private:
    vector<Fruit<double>> available_fruits;
    vector<Customer> customers;
    map<string, double> sales;

public:
    void addCustomer(const Customer& customer) {
        customers.push_back(customer);
    }

    void addFruitToShop(Fruit<double> fruit) {
        available_fruits.push_back(fruit);
    }

    void processOrder(Customer& customer, Drink<Fruit<double>>& drink) {
        if (!checkStock(drink)) throw InvalidFruitException();
        if (drink.getVolume() > 10) throw OrderException();

        customer.orderDrink(drink);
        recordSale(drink);
    }

    bool checkStock(Drink<Fruit<double>>& drink) {
        for (const auto& fruit : available_fruits) {
            if (fruit.getName() == drink.getIngredient().getName()) return true;
        }
        return false;
    }

    void recordSale(Drink<Fruit<double>>& drink) {
        string fruit_name = drink.getIngredient().getName();
        sales[fruit_name] += drink.getVolume();
        cout << "Penjualan: " << fruit_name << " Volume: " << drink.getVolume() << "L" << endl;
    }

    void displaySales() {
        cout << "\nSales Report:" << endl;
        for (const auto& entry : sales) {
            cout << entry.first << " - " << entry.second << "L terjual" << endl;
        }
    }

    void displayAvailableFruits() {
        cout << "\nBuah yang tersedia di JuiceShop:" << endl;
        for (const auto& fruit : available_fruits) {
            cout << fruit.getName() << " - Harga per kg: " << fruit.getPricePerKg() << endl;
        }
    }
};
