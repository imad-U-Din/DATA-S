#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;
    do
    {

        printf("%d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head->next;

    while (p->next != head)
    {
        p = p->next;
    }
    // At this point p points to last node

    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
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

    head->data = 100;
    head->next = second;

    second->data = 200;
    second->next = third;

    third->data = 300;
    third->next = fourth;

    fourth->data = 400;
    fourth->next = head;

    printf("Elements in Linked List: \n");
    linkedListTraversal(head);

    head = insertAtFirst(head, 7);
    // if you want to continue Inserting at beginning
    // head = insertAtFirst(head, 8);
    // head = insertAtFirst(head, 9);
    printf("\nAfter Inserting at beginning: \n");
    linkedListTraversal(head);

    return 0;
}