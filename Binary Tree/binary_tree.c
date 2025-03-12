#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node * createNode(int data){
    struct node *n; //CREATING A NODE POINTER
    n = (struct node *)malloc(sizeof(struct node)); //ALLOCATING MEMORY IN THE HEAP
    n->data=data;
    n->left = NULL;
    n->right = NULL;
    return n; //RETURNING THE NODE
}

void InOrder(struct  node* root){
    if(root!=NULL){
        InOrder(root->left);
        printf("%d ", root->data);
        InOrder(root->right);
    }
}

void postOrder(struct  node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void preOrder(struct  node* root){
    if(root!=NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    /*(1ST METHOD BUT LENGHTHY)
    // CONSTRUCTING THE ROOT NODE
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data=2;
    p->left = NULL;
    p->right = NULL;
    // CONSTRUCTING THE SECOND NODE
    struct node *p1;
    p1 = (struct node *)malloc(sizeof(struct node));
    p->data=1;
    p1->left = NULL;
    p1->right = NULL;
    // CONSTRUCTING THE THIRD NODE
    struct node *p2;
    p2 = (struct node *)malloc(sizeof(struct node));
    p->data=4;
    p2->left = NULL;
    p2->right = NULL;

    */
   
   //(2ND METHOD) // CONSTRUCTING USING FUNCTION
   struct node *p = createNode(4);
   struct node *p1 = createNode(1);
   struct node *p2 = createNode(6);
   struct node *p3 = createNode(5);
   struct node *p4 = createNode(2);
   
   //LINKING THE ROOT NODE WITH LEFT AND RIGHT CHILDREN
   p->left = p1;
   p->right = p2;
   p1->left = p3;
   p1->right = p4;
    // Finally The tree looks like this:
    //      4
    //     / \
    //    1   6
    //   / \
    //  5   2  

   printf("Inoreder: ");
   InOrder(p);

   printf("\nPostoreder: ");
   postOrder(p);
   
   printf("\nPreoreder: ");
   preOrder(p);

    return 0;
}