// Saya Ahmad Izzuddin Azzam dengan NIM 2300492 mengerjakan Quiz 2 dalam 
// mata kuliah Desain Pemograman Berorientasi Objek untuk keberkahanNya maka saya tidak melakukan 
// kecurangan seperti yang telah dispesifikasikan. Aamiin.

#pragma once
#include <string>
#include "../exceptions/PriceException.h"

using namespace std;

template <class J>
class Fruit {
private:
    string name;
    J price_per_kg;

public:
    Fruit(string n, J p) : name(n), price_per_kg(p) {
        if (p < 0) throw PriceException();
    }

    string getName() const { return name; }
    void setName(const string& n) { name = n; }

    J getPricePerKg() const { return price_per_kg; }
    void setPricePerKg(J p) {
        if (p < 0) throw PriceException();
        price_per_kg = p;
    }
};
