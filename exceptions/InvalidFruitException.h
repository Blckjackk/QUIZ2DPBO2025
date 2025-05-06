// Saya Ahmad Izzuddin Azzam dengan NIM 2300492 mengerjakan Quiz 2 dalam 
// mata kuliah Desain Pemograman Berorientasi Objek untuk keberkahanNya maka saya tidak melakukan 
// kecurangan seperti yang telah dispesifikasikan. Aamiin.

#pragma once
#include <exception>

using namespace std;

class InvalidFruitException : public exception {
public:
    const char* what() const noexcept override {
        return "Buah tidak valid!";
    }
};
