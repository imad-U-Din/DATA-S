#include <stdio.h>
#include <stdlib.h>

#define SIZE 10  // Hash table size

// Node structure for linked list
struct Node {
    int data;
    struct Node* next;
};

// Hash table (Array of Linked Lists)
struct Node* hashTable[SIZE];

// Hash function (Simple Modulo)
int hashFunction(int key) {
    return key % SIZE;
}

// Insert function using Chaining
void insert(int key) {
    int index = hashFunction(key);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->next = hashTable[index];  // Insert at beginning of the linked list
    hashTable[index] = newNode;
}

// Search function
int search(int key) {
    int index = hashFunction(key);
    struct Node* temp = hashTable[index];

    while (temp != NULL) {
        if (temp->data == key)
            return 1;  // Key found
        temp = temp->next;
    }
    return 0;  // Key not found
}

// Delete function
void deleteKey(int key) {
    int index = hashFunction(key);
    struct Node* temp = hashTable[index];
    struct Node* prev = NULL;

    while (temp != NULL) {
        if (temp->data == key) {
            if (prev == NULL)
                hashTable[index] = temp->next;  // Delete first node
            else
                prev->next = temp->next;

            free(temp);
            printf("Key %d deleted\n", key);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Key %d not found\n", key);
}

// Display function
void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("Index %d: ", i);
        struct Node* temp = hashTable[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Main function
int main() {
    // Initialize hash table with NULL
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = NULL;
    }

    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insert(21); // Causes collision with 10 (21 % 10 == 1)

    display();

    // Search for a key
    int key = 30;
    if (search(key))
        printf("\nKey %d found in hash table\n", key);
    else
        printf("\nKey %d not found\n", key);

    // Delete a key
    deleteKey(20);
    display();

    return 0;
}
