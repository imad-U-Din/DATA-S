#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void doublyLinkedListTraversalForward(struct Node *head)
{
    struct Node *ptr = head;
    printf("Forward Traversal:\n");
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

void doublyLinkedListTraversalBackward(struct Node *tail)
{
    struct Node *ptr = tail;
    printf("\nBackward Traversal:\n");
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->prev;
    }
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;
    head->prev = NULL;

    second->data = 10;
    second->next = third;
    second->prev = head;

    third->data = 13;
    third->next = fourth;
    third->prev = second;

    fourth->data = 16;
    fourth->next = NULL;
    fourth->prev = third;

    doublyLinkedListTraversalForward(head);
    doublyLinkedListTraversalBackward(fourth);

    return 0;
}
