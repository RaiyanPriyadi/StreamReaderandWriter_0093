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
// 3. Fitur Manajemen Gudang Berbasis File (File I/O & CRUD)

// Fungsi Bantuan (Read): Menampilkan daftar dari file txt
void tampilkanGudang() {
    ifstream file(NAMA_FILE);
    cout << "\n=== Daftar Barang di Gudang Gibran Jaya ===\n";
    if (!file.is_open()) {
        cout << "(File gudang.txt belum ada. Silakan tambahkan barang)\n";
        return;
    }
    
    string line;
    int indeks = 1;
    bool adaData = false;
    while (getline(file, line)) {
        cout << indeks++ << ". " << line << "\n";
        adaData = true;
    }
    if (!adaData) {
        cout << "(Gudang Kosong)\n";
    }
    file.close();
}

// c
void tambahBarang() {
    ofstream file(NAMA_FILE, ios::app);
    if (!file.is_open()) {
        cout << "Gagal membuka file gudang!\n";
        return;
    }
    cout << "Masukkan nama barang baru: ";
    string nama;
    cin.ignore();
    getline(cin, nama);
    file << nama << "\n";
    cout << "Berhasil menambahkan barang ke gudang!\n";
    file.close();
}