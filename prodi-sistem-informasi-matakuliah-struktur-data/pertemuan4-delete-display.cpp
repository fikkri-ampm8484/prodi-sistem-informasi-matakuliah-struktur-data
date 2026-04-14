#include <iostream>

using namespace std;

// Definisi node menggunakan class
class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Class single linked list
class LinkedList {
private:
    Node* head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    // Fungsi pembantu untuk insert agar bisa diuji
    void insertBelakang(int val) {
        Node* baru = new Node(val);
        if (!head) {
            head = baru;
        } else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = baru;
        }
        size++;
    }

    // 1. Delete di depan — O(1)
    void deleteDepan() {
        if (!head) { 
            cout << "List kosong!" << endl; 
            return; 
        }
        Node* temp = head;
        head = head->next; // Geser head ke node selanjutnya
        cout << ">> Deleted " << temp->data << " dari depan" << endl;
        delete temp; // Hapus dari memori
        size--;
    }

    // 2. Delete di belakang — O(n)
    void deleteBelakang() {
        if (!head) { 
            cout << "List kosong!" << endl; 
            return; 
        }
        
        // Kasus jika hanya ada 1 node
        if (!head->next) {
            cout << ">> Deleted " << head->data << " dari belakang" << endl;
            delete head;
            head = nullptr;
            size--;
            return;
        }

        // Mencari node kedua terakhir
        Node* temp = head;
        while (temp->next->next) {
            temp = temp->next;
        }
        
        cout << ">> Deleted " << temp->next->data << " dari belakang" << endl;
        delete temp->next; // Hapus node terakhir
        temp->next = nullptr; // Node kedua terakhir sekarang jadi ujung
        size--;
    }

    // 3. Delete berdasarkan nilai — O(n)
    void deleteNilai(int val) {
        if (!head) return;

        // Jika nilai ada di head
        if (head->data == val) { 
            deleteDepan(); 
            return; 
        }

        Node* temp = head;
        // Mencari node sebelum node yang ingin dihapus
        while (temp->next && temp->next->data != val) {
            temp = temp->next;
        }

        if (!temp->next) {
            cout << "Nilai " << val << " tidak ditemukan!" << endl;
            return;
        }

        Node* hapus = temp->next;
        temp->next = hapus->next; // Melompati node yang dihapus
        cout << ">> Deleted " << hapus->data << endl;
        delete hapus;
        size--;
    }

    // 4. Display (tampilkan)
    void tampilkan() {
        if (!head) {
            cout << "List kosong." << endl;
            return;
        }
        Node* temp = head;
        cout << "List (" << size << " node): ";
        while (temp) {
            cout << "[" << temp->data << "] -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Destructor — membersihkan semua node saat objek selesai digunakan
    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList listKu;

    listKu.insertBelakang(10);
    listKu.insertBelakang(20);
    listKu.insertBelakang(30);
    listKu.insertBelakang(40);

    listKu.tampilkan(); // 10 -> 20 -> 30 -> 40

    listKu.deleteDepan();    // Hapus 10
    listKu.deleteBelakang(); // Hapus 40
    listKu.deleteNilai(20);  // Hapus 20

    listKu.tampilkan(); // Sisa 30

    return 0;
}