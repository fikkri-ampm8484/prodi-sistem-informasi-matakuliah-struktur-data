#include <iostream>

using namespace std;

int main() {
    // 1. Deklarasi Matriks A & B Ordo 3x3 secara statis
    int matriksA[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matriksB[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int matriksC[3][3]; // Matriks untuk menampung hasil penjumlahan

    // 2. Logika Penjumlahan Matriks menggunakan Nested Loop
    for(int i = 0; i < 3; i++) {       // Loop Baris (Row)
        for(int j = 0; j < 3; j++) {   // Loop Kolom (Column)
            // Menjumlahkan elemen pada koordinat (i, j) yang sama
            matriksC[i][j] = matriksA[i][j] + matriksB[i][j];
        }
    }

    // 3. Menampilkan Hasil Matriks C ke Konsol
    cout << "Hasil Penjumlahan Matriks A + B (Ordo 3x3):" << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << matriksC[i][j] << "\t"; // Mencetak elemen matriks
        }
        cout << endl; // Baris baru setelah satu baris kolom selesai dicetak
    }

    return 0;
}