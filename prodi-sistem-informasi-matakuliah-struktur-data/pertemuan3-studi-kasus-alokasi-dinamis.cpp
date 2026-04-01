#include <iostream> // Memasukkan library standar iostream untuk operasi input (cin) dan output (cout)

using namespace std; // Mengizinkan penggunaan fungsi standar C++ tanpa perlu menulis awalan std:: terus menerus

int main() { // Deklarasi fungsi utama (main), dii sini lah eksekusi program dimulai
    int ukuran; // Mendeklarasikan variabel integer biasa di stack memory untuk menyimpan jumlah data

    // 1. MENDAPATKAN UKURAN DARI USER SAAT RUN TIME
    cout << "Masukkan jumlah data yang ingin diproses: "; // Mencetak instruksi ke layar konsol agar user memasukkan angka
    cin >> ukuran; // Membaca input angka dari keyboard dan menyimpannya ke dalam variabel (ukuran)

    // 2. ALOKASI MEMORI DINAMIS
    // Meminjam blok memori di area heap sebesar (ukuran) yang diminta user
    int* dataset = new int[ukuran]; // Pointer (dataset) dii stack ini menyimpan alamat awal dari array dinamis di heap

    // 3. MENGGUNAKAN MEMORI DINAMIS
    cout << "\nSilakan masukkan " << ukuran << " buah angka:" << endl; // Mencetak instruksi untuk pengisian array
    for (int i = 0; i < ukuran; i++) { // Memulai perulangan dari indeks ke 0 hingga batas (ukuran)
        cout << "Angka ke-" << (i + 1) << ": "; // Mencetak label penunjuk urutan data (ditambah 1 agar mulai dari 1)
        cin >> dataset[i]; // Membaca input dari keyboard dan menyimpannya ke dalam array dinamis di heap pada indeks ke i
    }

    cout << "\nDataset yang anda masukkan adalah: "; // Mencetak teks pengantar sebelum menampilkan hasil array
    for (int i = 0; i < ukuran; i++) { // Memulai perulangan kembali untuk membaca isi array
        cout << dataset[i] << " "; // Mengambil nilai dari memori dinamis pada indeks ke i dan mencetaknya ke layar
    }
    cout << endl; // Mencetak baris baru (enter) untuk merapikan tampilan konsol

    // 4. DEALOKASI MEMORI (PENCEGAHAN MEMORY LEAK SANGAT PENTING)
    delete[] dataset; // Mengembalikan seluruh blok memori array yang tadi dipinjam
    
    // 5. MENCEGAH DANGLING POINTER
    dataset = nullptr; // Mengosongkan nilai pointer agar tidak lagi menunjuk ke alamat ram

    return 0; // Mengakhiri program dengan mengembalikan status 0
} // Penutup blok fungsi main