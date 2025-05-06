// Saya Ahmad Izzuddin Azzam dengan NIM 2300492 mengerjakan Quiz 2 dalam 
// mata kuliah Desain Pemograman Berorientasi Objek untuk keberkahanNya maka saya tidak melakukan 
// kecurangan seperti yang telah dispesifikasikan. Aamiin.

#include "models/Supplier.h"
#include "models/JuiceShop.h"
#include "models/Drink.h"
#include "models/Customer.h"
#include "exceptions/StockException.h"
#include "exceptions/OrderException.h"
#include "exceptions/PriceException.h"
#include "exceptions/InvalidFruitException.h"

using namespace std;

int main() {
    Supplier supplier;
    supplier.addFruitToStock("Apel", 10.0);
    supplier.addFruitToStock("Jeruk", 9.5);
    supplier.addFruitToStock("Mangga", 12.0);
    supplier.addFruitToStock("Semangka", 7.0);
    supplier.addFruitToStock("Nanas", 8.0);
    supplier.addFruitToStock("Stroberi", 15.0);

    cout << "\n=== SISTEM MULTI JUICE SHOP DIMULAI ===\n" << endl;

    // ================= JuiceShop 1 =================
    JuiceShop shopA;
    shopA.addFruitToShop(supplier.findFruitByName("Apel"));
    shopA.addFruitToShop(supplier.findFruitByName("Jeruk"));

    Customer custA1("Ali");
    Customer custA2("Budi");
    shopA.addCustomer(custA1);
    shopA.addCustomer(custA2);

    Drink<Fruit<double>> drinkA1(supplier.findFruitByName("Apel"), 2.0);
    Drink<Fruit<double>> drinkA2(supplier.findFruitByName("Jeruk"), 3.0);

    cout << "\n[ Juice Shop A - Pemesanan ]" << endl;
    try {
        shopA.processOrder(custA1, drinkA1);
        shopA.processOrder(custA2, drinkA2);
    } catch (exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }

    // ================= JuiceShop 2 =================
    JuiceShop shopB;
    shopB.addFruitToShop(supplier.findFruitByName("Mangga"));
    shopB.addFruitToShop(supplier.findFruitByName("Semangka"));

    Customer custB1("Citra");
    Customer custB2("Dina");
    shopB.addCustomer(custB1);
    shopB.addCustomer(custB2);

    Drink<Fruit<double>> drinkB1(supplier.findFruitByName("Mangga"), 1.5);
    Drink<Fruit<double>> drinkB2(supplier.findFruitByName("Semangka"), 2.5);

    cout << "\n[ Juice Shop B - Pemesanan ]" << endl;
    try {
        shopB.processOrder(custB1, drinkB1);
        shopB.processOrder(custB2, drinkB2);
    } catch (exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }

    // ================= JuiceShop 3 =================
    JuiceShop shopC;
    shopC.addFruitToShop(supplier.findFruitByName("Nanas"));
    shopC.addFruitToShop(supplier.findFruitByName("Stroberi"));

    Customer custC1("Eka");
    Customer custC2("Fajar");
    shopC.addCustomer(custC1);
    shopC.addCustomer(custC2);

    Drink<Fruit<double>> drinkC1(supplier.findFruitByName("Nanas"), 1.0);
    Drink<Fruit<double>> drinkC2(supplier.findFruitByName("Stroberi"), 3.0);
    Drink<Fruit<double>> overVol(supplier.findFruitByName("Stroberi"), 20.0); // Test OrderException

    // try
    // {
    //     Drink<Fruit<double>> overVol(supplier.findFruitByName("Stroberi Mines Harga"), -100); // Price Exception

    // }
    // catch(PriceException& e)
    // {
    //     cerr << "Price Exception: " << e.what() << endl;
    // }
    

    cout << "\n[ Juice Shop C - Pemesanan ]" << endl;
    try {
        shopC.processOrder(custC1, drinkC1);
        shopC.processOrder(custC2, drinkC2);
        shopC.processOrder(custC1, overVol); // akan melempar exception
    } catch (StockException& e) {
        cerr << "Stock Exception: " << e.what() << endl;
    } catch (OrderException& e) {
        cerr << "Order Exception: " << e.what() << endl;
    } catch (PriceException& e) {
        cerr << "Price Exception: " << e.what() << endl;
    } catch (InvalidFruitException& e) {
        cerr << "Invalid Fruit Exception: " << e.what() << endl;
    } catch (exception& e) {
        cerr << "General Exception: " << e.what() << endl;
    }

    // ================= Sales Reports =================
    cout << "\n=== LAPORAN PENJUALAN ===\n" << endl;
    cout << "[ Shop A ]" << endl;
    shopA.displaySales();

    cout << "\n[ Shop B ]" << endl;
    shopB.displaySales();

    cout << "\n[ Shop C ]" << endl;
    shopC.displaySales();

    cout << "\n=== APLIKASINYA SUDAH SELESAI ===" << endl;
    return 0;
}
