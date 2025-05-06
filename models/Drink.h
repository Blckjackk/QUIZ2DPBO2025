// Saya Ahmad Izzuddin Azzam dengan NIM 2300492 mengerjakan Quiz 2 dalam 
// mata kuliah Desain Pemograman Berorientasi Objek untuk keberkahanNya maka saya tidak melakukan 
// kecurangan seperti yang telah dispesifikasikan. Aamiin.

#pragma once
#include <iostream>
using namespace std;


template <typename T>
class Drink {
private:
    T ingredient;
    double volume;

public:
    Drink(T fruit, double vol) : ingredient(fruit), volume(vol) {}

    void display() {
        cout << "Minuman: " << ingredient.getName() << " Volume: " << volume << "L" << endl;
    }

    T getIngredient() const { return ingredient; }
    void setIngredient(T f) { ingredient = f; }

    double getVolume() const { return volume; }
    void setVolume(double v) { volume = v; }
};
