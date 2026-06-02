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
    string ambilBarang(size_t nomorRak) {
        try {
            // 2. Mekanisme Exception Handling menggunakan .at()
            return etalase.at(nomorRak);
        } 
        catch (const out_of_range& e) {
            // Menangkap error bawaan out_of_range dan melempar pesan error kustom
            string errorMsg = "Gagal Mengambil Barang : Rak nomor " + to_string(nomorRak) + " kosong atau tidak tersedia!";
            throw runtime_error(errorMsg);
        }
    }
};

const string NAMA_FILE = "gudang.txt";