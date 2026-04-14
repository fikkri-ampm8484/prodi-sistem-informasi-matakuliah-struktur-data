#include <stdio.h>
#include <stdlib.h>

// 1. Definisi struktur node
struct Node {
    int data;
    struct Node* next;
};

// 2. Membuat node baru
struct Node* buatNode(int nilai) {
    struct Node* baru = (struct Node*)malloc(sizeof(struct Node));
    if (baru == NULL) {
        printf("Gagal alokasi memori!\n");
        return NULL;
    }
    baru->data = nilai;
    baru->next = NULL;
    return baru;
}

// 3. Insert depan (awal) - O(1)
void insertDepan(struct Node** head, int nilai) {
    struct Node* baru = buatNode(nilai);
    baru->next = *head;
    *head = baru;
    printf("Berhasil insert %d di depan.\n", nilai);
}

// 4. Menampilkan seluruh isi linked list
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

    insertDepan(&head, 10);
    insertDepan(&head, 20);
    insertDepan(&head, 30);
    insertDepan(&head, 40);

    tampilkan(head);

    return 0;
}