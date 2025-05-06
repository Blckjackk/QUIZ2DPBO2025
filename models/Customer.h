// Saya Ahmad Izzuddin Azzam dengan NIM 2300492 mengerjakan Quiz 2 dalam 
// mata kuliah Desain Pemograman Berorientasi Objek untuk keberkahanNya maka saya tidak melakukan 
// kecurangan seperti yang telah dispesifikasikan. Aamiin.

#pragma once
#include <string>
#include <iostream>
#include "Drink.h"

using namespace std;

class Customer {
private:
    string name;

public:
    Customer(string n) : name(n) {}

    void orderDrink(Drink<Fruit<double>>& drink) {
        cout << name << " memesan minuman: " << drink.getIngredient().getName() << endl;
    }

    string getName() const { return name; }
    void setName(const string& n) { name = n; }

    friend class JuiceShop;
};
