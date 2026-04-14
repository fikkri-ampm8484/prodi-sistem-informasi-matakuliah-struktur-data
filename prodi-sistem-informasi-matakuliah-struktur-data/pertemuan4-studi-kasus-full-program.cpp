#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. Definisi struktur node (barang)
struct Barang {
    char nama[50];
    int jumlah;
    int harga;
    struct Barang* next;
};

// 2. Fungsi untuk membuat node baru
struct Barang* buatBarang(char* nama, int jumlah, int harga) {
    struct Barang* b = (struct Barang*)malloc(sizeof(struct Barang));
    if (b == NULL) {
        printf("Gagal alokasi memori!\n");
        return NULL;
    }
    strcpy(b->nama, nama);
    b->jumlah = jumlah;
    b->harga = harga;
    b->next = NULL;
    return b;
}

// 3. Operasi insert depan (tambah barang)
void tambahBarang(struct Barang** head, char* nama, int jml, int hrg) {
    struct Barang* baru = buatBarang(nama, jml, hrg);
    baru->next = *head; // Node baru menunjuk ke head lama
    *head = baru;       // Head pindah ke node baru
}

// 4. Operasi traversal
void tampilDaftar(struct Barang* head) {
    int total = 0, no = 1;
    struct Barang* temp = head; // Menggunakan temp agar head asli tidak hilang

    printf("\n====== DAFTAR BELANJA ======\n");
    printf("%-4s %-15s %-6s %-12s %-12s\n", "No", "Nama", "Jml", "Harga", "Subtotal");
    printf("-----------------------------------------------------------\n");

    while (temp != NULL) {
        int sub = temp->jumlah * temp->harga;
        printf("%-4d %-15s %-6d Rp%-10d Rp%-10d\n",
               no++, temp->nama, temp->jumlah, temp->harga, sub);
        total += sub;
        temp = temp->next; // Pindah ke barang berikutnya
    }

    printf("-----------------------------------------------------------\n");
    printf("TOTAL BELANJA: Rp%d\n", total);
}

// 5. Fungsi pembersih memori (penyimpanan)
void hapusSemua(struct Barang** head) {
    struct Barang* temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main() {
    struct Barang* daftar = NULL; // Inisialisasi list kosong

    // Menambah data belanja
    tambahBarang(&daftar, "Beras 5kg", 4, 65000);
    tambahBarang(&daftar, "Telur 1kg", 2, 28000);
    tambahBarang(&daftar, "Minyak 1L", 2, 18000);
    tambahBarang(&daftar, "Gula 1kg", 2, 14000);
    tambahBarang(&daftar, "Sabun", 4, 5000);

    // Menampilkan hasil
    tampilDaftar(daftar);

    // Membersihkan memori sebelum program selesai
    hapusSemua(&daftar);

    return 0;
}