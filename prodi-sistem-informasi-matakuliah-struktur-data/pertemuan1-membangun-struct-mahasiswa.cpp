#include <iostream> // Memasukkan pustaka standar untuk input dan output (cin/cout)
#include <string>   // Memasukkan pustaka untuk menggunakan tipe data string

using namespace std; // Menggunakan namespace standar agar tidak perlu menulis std:: berkali-kali

// 1. Deklarasi tipe bentukan bernama Mahasiswa (Implementasi ADT)
struct Mahasiswa {
    
    // --- DATA ELEMENTS (Atribut) ---
    // 2. Menambahkan variabel Atribut sesuai instruksi
    string Nama;     // Variabel untuk menyimpan Nama (Tipe String)
    string NIM;      // Variabel untuk menyimpan NIM (Tipe String)
    float NilaiIPK;  // Variabel untuk menyimpan Nilai IPK (Tipe Float)

    // --- OPERATIONS (Fungsi Operasi yang Didefinisikan) ---
    
    // 3. Membuat Operasi Void: InputData() untuk meminta masukan pengguna
    void InputData() {
        cout << "--- Form Input Data Mahasiswa ---" << endl;
        
        cout << "Masukkan Nama : ";
        // Menggunakan getline agar input nama yang mengandung spasi bisa terbaca penuh
        getline(cin >> ws, Nama); 
        
        cout << "Masukkan NIM  : ";
        cin >> NIM; // Membaca input NIM dari pengguna
        
        cout << "Masukkan IPK  : ";
        cin >> NilaiIPK; // Membaca input nilai IPK dari pengguna
    }

    // 4. Membuat Operasi Void: TampilData() untuk mencetak ke konsol
    void TampilData() {
        cout << "\n--- Hasil Data Mahasiswa ---" << endl;
        cout << "Nama Mahasiswa : " << Nama << endl;     // Menampilkan atribut Nama
        cout << "Nomor Induk    : " << NIM << endl;      // Menampilkan atribut NIM
        cout << "Nilai IPK      : " << NilaiIPK << endl; // Menampilkan atribut NilaiIPK
        cout << "----------------------------" << endl;
    }
};

// Fungsi utama program tempat eksekusi dimulai
int main() {
    // Memesan alokasi memori (laci) untuk variabel baru bernama mhs1 dengan tipe Mahasiswa
    Mahasiswa mhs1; 

    // Memanggil operasi InputData() yang terikat pada objek mhs1
    mhs1.InputData();

    // Memanggil operasi TampilData() yang terikat pada objek mhs1
    mhs1.TampilData();

    return 0; // Mengakhiri program dengan status sukses
}