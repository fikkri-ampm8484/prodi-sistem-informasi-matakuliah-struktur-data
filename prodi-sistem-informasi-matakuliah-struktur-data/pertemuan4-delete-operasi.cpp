#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Fungsi untuk menambah data
void insertDepan(struct Node** head, int nilai) {
    struct Node* baru = (struct Node*)malloc(sizeof(struct Node));
    baru->data = nilai;
    baru->next = *head;
    *head = baru;
}

// 1. Delete di depan — O(1)
void deleteDepan(struct Node** head) {
    if (*head == NULL) {
        printf("List kosong!\n");
        return;
    }
    struct Node* temp = *head; // Simpan alamat head lama
    *head = (*head)->next;     // Pindahkan head ke node kedua
    printf(">> Deleted %d dari depan\n", temp->data);
    free(temp);                // Hapus node dari memori
}

// 2. Delete di belakang — O(n)
void deleteBelakang(struct Node** head) {
    if (*head == NULL) {
        printf("List kosong!\n");
        return;
    }
    
    // Jika hanya ada 1 node
    if ((*head)->next == NULL) {
        printf(">> Deleted %d dari belakang\n", (*head)->data);
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* temp = *head;
    // Traversal mencari node kedua terakhir
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    
    printf(">> Deleted %d dari belakang\n", temp->next->data);
    free(temp->next);   // Hapus node terakhir
    temp->next = NULL;  // Node kedua terakhir sekarang menjadi ujung (NULL)
}

// 3. Delete berdasarkan nilai — O(n)
void deleteNilai(struct Node** head, int nilai) {
    if (*head == NULL) return;

    // Jika nilai yang dicari ada di Head
    if ((*head)->data == nilai) {
        deleteDepan(head);
        return;
    }

    struct Node* temp = *head;
    // Mencari node sebelum node yang akan dihapus
    while (temp->next != NULL && temp->next->data != nilai) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Nilai %d tidak ditemukan!\n", nilai);
        return;
    }

    struct Node* hapus = temp->next;
    temp->next = hapus->next; // Melompati node yang dihapus
    printf(">> Deleted %d\n", hapus->data);
    free(hapus);
}

void tampilkan(struct Node* head) {
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("[%d] -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    
    insertDepan(&head, 40);
    insertDepan(&head, 30);
    insertDepan(&head, 20);
    insertDepan(&head, 10);
    tampilkan(head);

    deleteDepan(&head);    // Hapus 10
    deleteBelakang(&head); // Hapus 40
    tampilkan(head);       // Sisa 20 30

    return 0;
}