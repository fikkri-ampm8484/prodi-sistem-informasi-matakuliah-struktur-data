#include <iostream>

using namespace std;

int main() {
    // 1. Inisialisasi Array 1D dengan kapasitas statis 10
    int angka[10] = {12, 45, 7, 23, 89, 34, 56, 9, 71, 30};
    int n = 10; // Jumlah elemen

    // --- BAGIAN A: MENCARI MAX & MIN ---
    int maxVal = angka[0], minVal = angka[0]; // Asumsi awal elemen pertama adalah yang terbesar & terkecil
    int idxMax = 0, idxMin = 0; // Menyimpan alamat indeks penemuan

    for(int i = 1; i < n; i++) { // Traversal (pembacaan) dari indeks 1 sampai n
        if(angka[i] > maxVal) { // Jika ditemukan nilai yang lebih besar
            maxVal = angka[i];
            idxMax = i;
        }
        if(angka[i] < minVal) { // Jika ditemukan nilai yang lebih kecil
            minVal = angka[i];
            idxMin = i;
        }
    }

    cout << "Nilai Terbesar: " << maxVal << " (Indeks: " << idxMax << ")" << endl;
    cout << "Nilai Terkecil: " << minVal << " (Indeks: " << idxMin << ")" << endl;

    // --- BAGIAN B: REVERSE ARRAY (IN-PLACE) ---
    // Menggunakan pergeseran titik Swap (tukar) antara batas kiri dan kanan
    int kiri = 0; 
    int kanan = n - 1;

    while(kiri < kanan) {
        // Logika pertukaran nilai tanpa array cadangan
        int temp = angka[kiri];
        angka[kiri] = angka[kanan];
        angka[kanan] = temp;
        
        kiri++;  // Geser batas kiri ke depan
        kanan--; // Geser batas kanan ke belakang
    }

    cout << "\nArray Setelah di-Reverse: ";
    for(int i = 0; i < n; i++) cout << angka[i] << " "; // Cetak hasil traversal
    cout << endl;

    return 0;
}