#include <iostream>
#include <string>

using namespace std;

// 1. Definisi node menggunakan class
class Node {
public:
    int data;
    Node* next;

    // Constructor untuk inisialisasi node baru
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// 2. Class single linked list
class LinkedList {
private:
    Node* head;
    int size;

public:
    // Constructor untuk inisialisasi list kosong
    LinkedList() : head(nullptr), size(0) {}

    // Destructor untuk menghapus semua node saat objek dihancurkan
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        cout << ">> Memori list telah dibersihkan." << endl;
    }

    // Insert di depan — O(1)
    void insertDepan(int val) {
        Node* baru = new Node(val);
        baru->next = head;
        head = baru;
        size++;
        cout << ">> Inserted " << val << " di depan" << endl;
    }

    // Insert di belakang — O(n)
    void insertBelakang(int val) {
        Node* baru = new Node(val);
        if (head == nullptr) {
            head = baru;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = baru;
        }
        size++;
        cout << ">> Inserted " << val << " di belakang" << endl;
    }

    // Insert di posisi tertentu — O(n)
    void insertPosisi(int val, int pos) {
        if (pos < 0 || pos > size) {
            cout << "Posisi invalid!" << endl;
            return;
        }
        if (pos == 0) {
            insertDepan(val);
            return;
        }

        Node* baru = new Node(val);
        Node* temp = head;
        // Berhenti di satu node sebelum posisi target
        for (int i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }
        baru->next = temp->next;
        temp->next = baru;
        size++;
        cout << ">> Inserted " << val << " di posisi " << pos << endl;
    }

    // Menampilkan seluruh isi list
    void tampilkan() {
        if (head == nullptr) {
            cout << "List kosong." << endl;
            return;
        }
        Node* temp = head;
        cout << "List (" << size << " node): ";
        while (temp != nullptr) {
            cout << "[" << temp->data << "] -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList listKu;

    listKu.insertDepan(20);     // List: 20
    listKu.insertBelakang(40);  // List: 20 -> 40 
    listKu.insertPosisi(30, 1); // List: 20 -> 30 -> 40
    listKu.insertDepan(10);     // List: 10 -> 20 -> 30 -> 40
    listKu.insertBelakang(50);  // List: 10 -> 20 -> 30 -> 40 -> 50

    listKu.tampilkan();

    return 0;
}