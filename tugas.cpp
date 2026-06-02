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

// fungsi create
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

// Fungsi Update
void ubahBarang() {
    ifstream fileIn(NAMA_FILE);
    vector<string> daftarBarang;
    string line;
    
    while (getline(fileIn, line)) {
        daftarBarang.push_back(line);
    }
    fileIn.close();

    if (daftarBarang.empty()) {
        cout << "Tidak ada barang yang bisa diubah!\n";
        return;
    }

    cout << "Masukkan nomor urut barang yang ingin diubah: ";
    int pilihan;
    cin >> pilihan;

    if (pilihan < 1 || pilihan > daftarBarang.size()) {
        cout << "Nomor barang tidak valid!\n";
        return;
    }

    cout << "Masukkan nama barang yang baru: ";
    cin.ignore();
    string namaBaru;
    getline(cin, namaBaru);
    
    daftarBarang[pilihan - 1] = namaBaru;

    ofstream fileOut(NAMA_FILE);
    for (const auto& barang : daftarBarang) {
        fileOut << barang << "\n";
    }
    fileOut.close();
    cout << "Data barang berhasil diperbarui!\n";
}

// Fungsi Delete
void hapusBarang() {
    ifstream fileIn(NAMA_FILE);
    vector<string> daftarBarang;
    string line;
    
    while (getline(fileIn, line)) {
        daftarBarang.push_back(line);
    }
    fileIn.close();

    if (daftarBarang.empty()) {
        cout << "Tidak ada barang yang bisa dihapus!\n";
        return;
    }

    cout << "Masukkan nomor urut barang yang ingin dihapus: ";
    int pilihan;
    cin >> pilihan;

    if (pilihan < 1 || pilihan > daftarBarang.size()) {
        cout << "Nomor barang tidak valid!\n";
        return;
    }

    daftarBarang.erase(daftarBarang.begin() + pilihan - 1);

    ofstream fileOut(NAMA_FILE);
    for (const auto& barang : daftarBarang) {
        fileOut << barang << "\n";
    }
    fileOut.close();
    cout << "Barang berhasil dihapus dari gudang!\n";
}
// 4. Simulasi Etalase (Exception Handling)
void simulasiEtalase(TokoElektronik& toko) {
    cout << "\n=== Menjalankan Simulasi Etalase ===\n";
    
    // Skenario 1 (Sukses)
    cout << "\n[Skenario 1] Pengambilan barang di rak indeks ke-1...\n";
    try {
        string barang = toko.ambilBarang(1);
        cout << "Status: SUKSES -> Mengambil " << barang << "\n";
    } catch (const exception& e) {
        cout << e.what() << "\n";
    }

    // Skenario 2 (Gagal)
    cout << "\n[Skenario 2] Pengambilan barang di rak indeks ke-5...\n";
    try {
        string barang = toko.ambilBarang(5);
        cout << "Status: SUKSES -> Mengambil " << barang << "\n";
    } catch (const runtime_error& e) {
        // Menangkap error kustom yang dilempar oleh method ambilBarang
        cout << e.what() << "\n";
    }
    
    cout << "====================================\n";
}