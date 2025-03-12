#include <stdio.h>
#include <stdlib.h>

#define ORDER 3  // B-Tree of order 3 (Max 2 keys per node)

// Structure of a B-Tree Node
struct BTreeNode {
    int keys[ORDER - 1];
    struct BTreeNode* children[ORDER];
    int numKeys;
    int leaf;
};

// Function to create a new B-Tree node
struct BTreeNode* createNode(int leaf) {
    struct BTreeNode* newNode = (struct BTreeNode*)malloc(sizeof(struct BTreeNode));
    newNode->numKeys = 0;
    newNode->leaf = leaf;
    for (int i = 0; i < ORDER; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

// Function to traverse and print the B-Tree
void traverse(struct BTreeNode* root) {
    if (root != NULL) {
        int i;
        for (i = 0; i < root->numKeys; i++) {
            if (!root->leaf) traverse(root->children[i]);  
            printf("%d ", root->keys[i]); 
        }
        if (!root->leaf) traverse(root->children[i]);
    }
}

// Function to split a full child node
void splitChild(struct BTreeNode* parent, int i, struct BTreeNode* fullChild) {
    struct BTreeNode* newChild = createNode(fullChild->leaf);
    newChild->numKeys = (ORDER - 1) / 2;

    // Copy keys from fullChild to newChild
    for (int j = 0; j < newChild->numKeys; j++)
        newChild->keys[j] = fullChild->keys[j + (ORDER / 2)];

    // Copy children if not a leaf
    if (!fullChild->leaf) {
        for (int j = 0; j < (ORDER / 2); j++)
            newChild->children[j] = fullChild->children[j + (ORDER / 2)];
    }

    fullChild->numKeys = (ORDER - 1) / 2;

    // Shift parent's children
    for (int j = parent->numKeys; j >= i + 1; j--)
        parent->children[j + 1] = parent->children[j];

    parent->children[i + 1] = newChild;

    // Shift parent's keys
    for (int j = parent->numKeys - 1; j >= i; j--)
        parent->keys[j + 1] = parent->keys[j];

    // Move middle key up to parent
    parent->keys[i] = fullChild->keys[(ORDER - 1) / 2];
    parent->numKeys++;
}

// Function to insert a key into a non-full node
void insertNonFull(struct BTreeNode* node, int key) {
    int i = node->numKeys - 1;

    if (node->leaf) {
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->numKeys++;
    } else {
        while (i >= 0 && key < node->keys[i])
            i--;

        i++;  

        if (node->children[i]->numKeys == ORDER - 1) {
            splitChild(node, i, node->children[i]);

            if (key > node->keys[i])
                i++;
        }

        insertNonFull(node->children[i], key);
    }
}

// Function to insert a key into the B-Tree
struct BTreeNode* insert(struct BTreeNode* root, int key) {
    if (root->numKeys == ORDER - 1) {
        struct BTreeNode* newRoot = createNode(0);
        newRoot->children[0] = root;
        splitChild(newRoot, 0, root);
        insertNonFull(newRoot, key);
        return newRoot;
    } else {
        insertNonFull(root, key);
        return root;
    }
}

// Main function
int main() {
    struct BTreeNode* root = createNode(1);

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 12);

    printf("B-Tree Elements: ");
    traverse(root);
    printf("\n");

    return 0;
}
