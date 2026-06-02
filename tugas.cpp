#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <vector>
#include <stdexcept>

using namespace std;

// 1. Struktur Kelas TokoElektronik
class TokoElektronik {
private:
    // Atribut Private: Array berkapasitas 3 elemen
    array<string, 3> etalase;

public:
    // Constructor: Mengisi data awal ke dalam array
    TokoElektronik() {
        etalase[0] = "Laptop Asus ROG";
        etalase[1] = "Monitor Samsung 27 inch";
        etalase[2] = "Keyboard Mechanical";
    }

    // Method Public dengan parameter size_t
    string ambilBarang(size_t nomorRak) 