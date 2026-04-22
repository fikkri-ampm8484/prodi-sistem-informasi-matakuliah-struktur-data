#include <iostream>
#include <string>

using namespace std;

// 1. Membentuk struct TrackLagu sesuai instruksi tugas
struct TrackLagu {
    string Judul;       // Data Field: Tempat menyimpan nama lagu
    TrackLagu* Prev;    // Prev Pointer: Mengarah ke lagu sebelumnya
    TrackLagu* Next;    // Next Pointer: Mengarah ke lagu selanjutnya
};

// Deklarasi pointer global untuk navigasi
TrackLagu* head = nullptr;          // Penanda awal playlist
TrackLagu* currentTrack = nullptr;  // Penanda lagu yang sedang diputar saat ini

// Fungsi untuk mengeksekusi Menu [1] Tambah Lagu
void tambahLagu(string judulBaru) {
    // Alokasi memori dinamis untuk node baru
    TrackLagu* newNode = new TrackLagu();
    newNode->Judul = judulBaru;

    if (head == nullptr) {
        // Jika playlist masih kosong, node menunjuk ke dirinya sendiri (Sirkular)
        head = newNode;
        head->Next = head;
        head->Prev = head;
        currentTrack = head; // Otomatis menjadi lagu yang siap diputar
    } else {
        // Jika sudah ada lagu, sisipkan di akhir (sebelum head pada konsep sirkular)
        TrackLagu* tail = head->Prev; // Node terakhir selalu berada di head->Prev
        
        tail->Next = newNode;         // Sambungkan node terakhir ke node baru
        newNode->Prev = tail;         // Node baru menoleh ke belakang (ke node terakhir lama)
        newNode->Next = head;         // Node baru menunjuk head sebagai Next (Rotasi tanpa ujung)
        head->Prev = newNode;         // Head menoleh ke belakang menunjuk node baru
    }
    cout << "[SUKSES] Lagu '" << judulBaru << "' ditambahkan ke playlist." << endl;
}

// Fungsi untuk mengeksekusi Menu [2] Hapus Lagu
void hapusLagu(string judulHapus) {
    if (head == nullptr) {
        cout << "[INFO] Playlist kosong, tidak ada yang bisa dihapus." << endl;
        return;
    }

    TrackLagu* temp = head;
    bool found = false;

    // Traversal mencari lagu. Pada CLL, looping berhenti jika kembali ke titik awal
    do {
        if (temp->Judul == judulHapus) {
            found = true;
            break;
        }
        temp = temp->Next;
    } while (temp != head);

    if (!found) {
        cout << "[ERROR] Lagu '" << judulHapus << "' tidak ditemukan." << endl;
        return;
    }

    // Jika lagu ditemukan, atur ulang pointer untuk mengisolasi node target
    if (temp->Next == temp) { 
        // Kasus khusus: Jika hanya tersisa 1 lagu di playlist
        head = nullptr;
        currentTrack = nullptr;
    } else {
        // Sambungkan node kiri dan kanan dari target untuk melewati target
        temp->Prev->Next = temp->Next; 
        temp->Next->Prev = temp->Prev;
        
        if (temp == head) {
            head = temp->Next; // Geser head jika lagu yang dihapus adalah lagu pertama
        }
        if (temp == currentTrack) {
            currentTrack = temp->Next; // Pindahkan currentTrack agar tidak menunjuk ke memori mati
        }
    }
    
    delete temp; // Dealokasi memori untuk mencegah kebocoran RAM Heap
    cout << "[SUKSES] Lagu '" << judulHapus << "' berhasil dihapus." << endl;
}

// Fungsi untuk mengeksekusi Menu [3] Next Song
void nextSong() {
    if (currentTrack != nullptr) {
        currentTrack = currentTrack->Next; // Bergeser maju satu langkah
        cout << ">>> Memutar: " << currentTrack->Judul << " >>>" << endl;
    } else {
        cout << "[INFO] Playlist kosong." << endl;
    }
}

// Fungsi untuk mengeksekusi Menu [4] Prev Song
void prevSong() {
    if (currentTrack != nullptr) {
        currentTrack = currentTrack->Prev; // Bergeser mundur satu langkah
        cout << "<<< Memutar: " << currentTrack->Judul << " <<<" << endl;
    } else {
        cout << "[INFO] Playlist kosong." << endl;
    }
}

// Fungsi tambahan untuk mencetak seluruh isi playlist
void tampilkanPlaylist() {
    if (head == nullptr) {
        cout << "Playlist: (Kosong)" << endl;
        return;
    }
    
    TrackLagu* temp = head;
    cout << "Daftar Playlist Saat Ini:" << endl;
    do {
        cout << "- " << temp->Judul;
        if (temp == currentTrack) cout << " (Sedang diputar)";
        cout << endl;
        temp = temp->Next;
    } while (temp != head);
}

int main() {
    int pilihan;
    string inputJudul;

    do {
        cout << "\n=== MEDIA PLAYER CLI ===" << endl;
        cout << "[1] Tambah Lagu" << endl;
        cout << "[2] Hapus Lagu" << endl;
        cout << "[3] Next Song" << endl;
        cout << "[4] Prev Song" << endl;
        cout << "[5] Tampilkan Playlist" << endl;
        cout << "[0] Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore(); // Membersihkan buffer enter

        switch (pilihan) {
            case 1:
                cout << "Masukkan Judul Lagu: ";
                getline(cin, inputJudul);
                tambahLagu(inputJudul);
                break;
            case 2:
                cout << "Masukkan Judul Lagu yang akan dihapus: ";
                getline(cin, inputJudul);
                hapusLagu(inputJudul);
                break;
            case 3:
                nextSong();
                break;
            case 4:
                prevSong();
                break;
            case 5:
                tampilkanPlaylist();
                break;
            case 0:
                cout << "Menutup Media Player..." << endl;
                break;
            default:
                cout << "[ERROR] Menu tidak valid!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}