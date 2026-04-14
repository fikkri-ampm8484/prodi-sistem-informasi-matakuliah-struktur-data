#include <iostream>
#include <string>

using namespace std;

// 1. Definisi node untuk mahasiswa
class Mahasiswa {
public:
    string nim;
    string nama;
    float ipk;
    Mahasiswa* next;

    Mahasiswa(string n, string nm, float i)
        : nim(n), nama(nm), ipk(i), next(nullptr) {}
};

// 2. Class manager untuk linked list
class DaftarMahasiswa {
private:
    Mahasiswa* head;
    int jumlah;

public:
    DaftarMahasiswa() : head(nullptr), jumlah(0) {}

    ~DaftarMahasiswa() {
        while (head) {
            Mahasiswa* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Fungsi tambah tata (sorted dibuat untuk nim)
    void tambah(string nim, string nama, float ipk) {
        Mahasiswa* baru = new Mahasiswa(nim, nama, ipk);

        // Kasus 1: List kosong atau nim baru lebih kecil dari head
        if (!head || nim < head->nim) {
            baru->next = head;
            head = baru;
        } 
        // Kasus 2: Mencari posisi yang tepat di tengah atau akhir
        else {
            Mahasiswa* temp = head;
            while (temp->next && temp->next->nim < nim) {
                temp = temp->next;
            }
            baru->next = temp->next;
            temp->next = baru;
        }
        jumlah++;
        cout << ">> Berhasil menambahkan mahasiswa: " << nama << endl;
    }

    // Fungsi pencarian berdasarkan nim
    Mahasiswa* cari(string nim) {
        Mahasiswa* temp = head;
        while (temp) {
            if (temp->nim == nim) return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    // Fungsi hapus data berdasarkan nim
    void hapus(string nim) {
        if (!head) return;

        // Jika data yang dihapus ada di head
        if (head->nim == nim) {
            Mahasiswa* temp = head;
            head = head->next;
            delete temp;
            jumlah--;
            return;
        }

        Mahasiswa* temp = head;
        while (temp->next && temp->next->nim != nim) {
            temp = temp->next;
        }

        if (temp->next) {
            Mahasiswa* hapusNode = temp->next;
            temp->next = hapusNode->next;
            delete hapusNode;
            jumlah--;
            cout << ">> Data NIM " << nim << " telah dihapus." << endl;
        } else {
            cout << ">> NIM " << nim << " tidak ditemukan." << endl;
        }
    }

    // Fungsi Traversal untuk menampilkan data
    void tampilkan() {
        cout << "\n===== DATA MAHASISWA (" << jumlah << " orang) =====" << endl;
        cout << "NIM\t\tNama\t\tIPK" << endl;
        cout << "----------------------------------------" << endl;
        Mahasiswa* temp = head;
        while (temp) {
            cout << temp->nim << "\t" << temp->nama << "\t\t" << temp->ipk << endl;
            temp = temp->next;
        }
        if (jumlah == 0) cout << "(Daftar Kosong)" << endl;
    }
};

int main() {
    DaftarMahasiswa dm;

    // Input data secara acak
    dm.tambah("2301001", "Andi", 3.75);
    dm.tambah("2301003", "Citra", 3.90);
    dm.tambah("2301002", "Budi", 3.50); // Akan otomatis berada di tengah

    dm.tampilkan();

    // Uji coba pencarian
    string target = "2301002";
    Mahasiswa* m = dm.cari(target);
    if (m) {
        cout << "\n[Pencarian] NIM " << target << " ditemukan: " << m->nama << " (IPK: " << m->ipk << ")" << endl;
    }

    // Uji coba penghapusan
    dm.hapus("2301002");
    dm.tampilkan();

    return 0;
}