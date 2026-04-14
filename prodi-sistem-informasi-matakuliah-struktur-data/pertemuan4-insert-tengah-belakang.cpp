#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* buatNode(int nilai) {
    struct Node* baru = (struct Node*)malloc(sizeof(struct Node));
    baru->data = nilai;
    baru->next = NULL;
    return baru;
}

void insertDepan(struct Node** head, int nilai) {
    struct Node* baru = buatNode(nilai);
    baru->next = *head;
    *head = baru;
}

// 1. Insert di belakang - O(n)
void insertBelakang(struct Node** head, int nilai) {
    struct Node* baru = buatNode(nilai);
    if (*head == NULL) {
        *head = baru;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = baru;
    printf(">> Inserted %d di belakang\n", nilai);
}

// 2. Insert di tengah (posisi tertentu) - O(n)
void insertTengah(struct Node** head, int nilai, int posisi) {
    if (posisi == 0) {
        insertDepan(head, nilai);
        return;
    }

    struct Node* baru = buatNode(nilai);
    struct Node* temp = *head;

    // Traversal untuk mencari node sebelum posisi target
    for (int i = 0; i < posisi - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Posisi %d di luar jangkauan!\n", posisi);
        free(baru);
        return;
    }

    // Proses penyambungan pointer
    baru->next = temp->next;
    temp->next = baru;
    printf(">> Inserted %d di posisi %d\n", nilai, posisi);
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

    insertBelakang(&head, 10);
    insertBelakang(&head, 20);
    insertBelakang(&head, 40);
    insertBelakang(&head, 50);
    insertTengah(&head, 30, 2);
    
    tampilkan(head);

    return 0;
}