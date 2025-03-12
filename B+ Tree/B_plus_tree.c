#include <stdio.h>
#include <stdlib.h>

#define MAX 3  // Maximum keys in a node (Order = MAX+1)

// Structure for B+ Tree Node
struct BPlusNode {
    int keys[MAX];
    struct BPlusNode* children[MAX + 1];
    struct BPlusNode* next;  // Next pointer for leaf nodes
    int numKeys;
    int leaf;
};

// Function to create a new B+ Tree node
struct BPlusNode* createNode(int leaf) {
    struct BPlusNode* newNode = (struct BPlusNode*)malloc(sizeof(struct BPlusNode));
    newNode->numKeys = 0;
    newNode->leaf = leaf;
    newNode->next = NULL;
    for (int i = 0; i <= MAX; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

// Function to insert a key in a sorted manner
struct BPlusNode* insert(struct BPlusNode* root, int key) {
    int i = root->numKeys - 1;
    
    // Find position to insert
    while (i >= 0 && root->keys[i] > key) {
        root->keys[i + 1] = root->keys[i];
        i--;
    }

    root->keys[i + 1] = key;  // Insert key at correct position
    root->numKeys++;

    return root;
}

// Function to traverse leaf nodes (prints all stored keys)
void traverseLeaves(struct BPlusNode* root) {
    while (!root->leaf) {
        root = root->children[0];  // Move to first leaf node
    }
    
    printf("B+ Tree Leaf Nodes: ");
    while (root) {
        for (int i = 0; i < root->numKeys; i++) {
            printf("%d ", root->keys[i]);
        }
        root = root->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct BPlusNode* root = createNode(1);  // Start with an empty leaf node

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 5);
    root = insert(root, 6);  

    traverseLeaves(root);  

    return 0;
}
