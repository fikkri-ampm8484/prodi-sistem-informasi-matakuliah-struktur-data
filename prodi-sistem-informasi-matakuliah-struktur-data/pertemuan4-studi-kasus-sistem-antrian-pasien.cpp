#include <iostream>
#include <string>

using namespace std;

// 1. Definisi Node untuk Pasien
class Pasien {
public:
    string nama;
    int nomorAntrian;
    Pasien* next;

    // Constructor untuk inisialisasi data pasien baru
    Pasien(string namaPasien, int noAntrian) {
        nama = namaPasien;
        nomorAntrian = noAntrian;
        next = nullptr;
    }
};

// 2. Class untuk Manajemen Antrian (Queue)
class AntrianKlinik {
private:
    Pasien* head;      // Menunjuk ke pasien paling depan (yang akan dipanggil)
    Pasien* tail;      // Menunjuk ke pasien paling belakang (yang baru masuk)
    int nomorUrutGlobal; // Counter untuk menghasilkan nomor antrian otomatis

public:
    // Inisialisasi antrian kosong
    AntrianKlinik() {
        head = nullptr;
        tail = nullptr;
        nomorUrutGlobal = 0;
    }

    // Enqueue: Menambah pasien di belakang antrian
    void daftar(string nama) {
        nomorUrutGlobal++;
        Pasien* baru = new Pasien(nama, nomorUrutGlobal);

        // Jika antrian masih kosong
        if (head == nullptr) {
            head = baru;
            tail = baru; // Head dan Tail menunjuk ke orang yang sama
        } 
        // Jika sudah ada orang di antrian
        else {
            tail->next = baru; // Pasien terakhir saat ini "menggandeng" pasien baru
            tail = baru;       // Pindahkan label "terakhir" ke pasien baru
        }
        cout << ">> Pasien '" << nama << "' masuk antrian (No. " << nomorUrutGlobal << ")" << endl;
    }

    // Dequeue: Memanggil dan mengeluarkan pasien dari depan antrian
    void panggil() {
        if (head == nullptr) {
            cout << ">> Info: Antrian saat ini kosong." << endl;
            return;
        }

        Pasien* pasienDipanggil = head;
        cout << ">> MENGHUBUNGI: " << pasienDipanggil->nama 
             << " (No. " << pasienDipanggil->nomorAntrian << ") silahkan ke ruang dokter." << endl;

        head = head->next; // Geser antrian maju satu langkah

        // Jika setelah dipanggil antrian menjadi kosong, pastikan tail juga di-reset
        if (head == nullptr) {
            tail = nullptr;
        }

        delete pasienDipanggil; // Bebaskan memori
    }

    // Traversal: Menampilkan daftar antrian saat ini
    void tampilAntrian() {
        if (head == nullptr) {
            cout << "\n--- Antrian Saat Ini ---" << endl;
            cout << "  (Antrian Kosong)" << endl;
            cout << "------------------------\n" << endl;
            return;
        }

        cout << "\n--- Antrian Saat Ini ---" << endl;
        int posisi = 1;
        Pasien* temp = head;
        
        while (temp != nullptr) {
            cout << "  " << posisi << ". " << temp->nama 
                 << " (No. " << temp->nomorAntrian << ")" << endl;
            temp = temp->next;
            posisi++;
        }
        cout << "------------------------\n" << endl;
    }

    // Destructor: Mencegah memory leak saat program selesai
    ~AntrianKlinik() {
        while (head != nullptr) {
            Pasien* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    AntrianKlinik klinik;

    // Skenario
    klinik.daftar("Andi");    // Andi masuk
    klinik.daftar("Budi");    // Budi masuk
    klinik.daftar("Citra");   // Citra masuk
    
    // Tampilkan: Andi -> Budi -> Citra
    klinik.tampilAntrian();   

    // Panggil pasien pertama
    klinik.panggil();         // Andi dipanggil
    
    // Pasien baru datang
    klinik.daftar("Dina");    // Dina masuk
    
    // Tampilkan: Budi -> Citra -> Dina
    klinik.tampilAntrian();   

    return 0;
}