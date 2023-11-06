#include <stdio.h>
#include <stdlib.h>

// Linked List Node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert an element at the end of the linked list
void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to extract and insert digits into buckets
void radixSort(struct Node** head, int digit) {
    struct Node* buckets[10] = { NULL };
    while (*head != NULL) {
        int index = ((*head)->data / digit) % 10;
        struct Node* next = (*head)->next;
        (*head)->next = buckets[index];
        buckets[index] = *head;
        *head = next;
    }
    
    for (int i = 0; i < 10; i++) {
        while (buckets[i] != NULL) {
            struct Node* next = buckets[i]->next;
            insert(head, buckets[i]->data);
            free(buckets[i]);
            buckets[i] = next;
        }
    }
}

// Radix sort implementation using linked lists
void linkedListRadixSort(struct Node** head) {
    int max = 0;
    struct Node* temp = *head;
    while (temp != NULL) {
        if (temp->data > max) {
            max = temp->data;
        }
        temp = temp->next;
    }
    
    for (int digit = 1; max / digit > 0; digit *= 10) {
        radixSort(head, digit);
    }
}

// Function to print linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    insert(&head, 136);
    insert(&head, 487);
    insert(&head, 358);
    insert(&head, 469);
    insert(&head, 570);
    insert(&head, 247);
    insert(&head, 598);
    insert(&head, 639);
    insert(&head, 205);
    insert(&head, 609);

    printf("Original linked list: ");
    printList(head);

    linkedListRadixSort(&head);

    printf("Sorted linked list: ");
    printList(head);

    return 0;
}
