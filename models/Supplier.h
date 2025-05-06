// Saya Ahmad Izzuddin Azzam dengan NIM 2300492 mengerjakan Quiz 2 dalam 
// mata kuliah Desain Pemograman Berorientasi Objek untuk keberkahanNya maka saya tidak melakukan 
// kecurangan seperti yang telah dispesifikasikan. Aamiin.

#pragma once
#include <vector>
#include <iostream>
#include "Fruit.h"
#include "../exceptions/InvalidFruitException.h"

using namespace std;


class Supplier {
private:
    vector<Fruit<double>> stock;

public:
    void supplyFruit(Fruit<double> fruit) {
        stock.push_back(fruit);
        cout << "Menyuplai buah: " << fruit.getName() << endl;
    }

    vector<Fruit<double>> getStock() const { return stock; }

    void addFruitToStock(const string& name, double price) {
        Fruit<double> fruit(name, price);
        supplyFruit(fruit);
    }

    Fruit<double> findFruitByName(const string& name) {
        for (auto& fruit : stock) {
            if (fruit.getName() == name) return fruit;
        }
        throw InvalidFruitException();
    }
};
