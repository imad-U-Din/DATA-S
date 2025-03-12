#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

int getHeight(struct Node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return n->height;
}

struct Node *createNode(int key)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // A new node has height 1

    return node;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int getBalanceFactor(struct Node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

struct Node *RightRotation(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    // Rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x; // New root after rotation
}

struct Node *LeftRotation(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    // Rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y; // New root after rotation
}

struct Node *insert(struct Node *node, int key)
{
    if (node == NULL)
    {
        return createNode(key);
    }

    // Normal BST insertion
    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
    else
    {
        return node; // Duplicate keys are not allowed
    }

    // Update height
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // Get Balance Factor
    int BF = getBalanceFactor(node);

    // Perform Rotations if needed
    // LEFT LEFT CASE
    if (BF > 1 && key < node->left->key)
    {
        return RightRotation(node);
    }

    // RIGHT RIGHT CASE
    if (BF < -1 && key > node->right->key)
    {
        return LeftRotation(node);
    }

    // LEFT RIGHT CASE
    if (BF > 1 && key > node->left->key)
    {
        node->left = LeftRotation(node->left);
        return RightRotation(node);
    }

    // RIGHT LEFT CASE
    if (BF < -1 && key < node->right->key)
    {
        node->right = RightRotation(node->right);
        return LeftRotation(node);
    }

    return node;
}

void inorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

int main()
{
    struct Node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("Inorder traversal of the AVL tree: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
