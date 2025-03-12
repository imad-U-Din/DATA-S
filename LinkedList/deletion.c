#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedlistTraversal(struct Node *ptr)
{
    int index = 1;
    while (ptr != NULL)
    {
        printf("Element %d= %d\n", index, ptr->data);
        ptr = ptr->next;
        index++;
    }
}

struct Node *deleteFirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

struct Node *deleteLast(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

struct Node *deleteAtValue(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
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

    head->data = 30;
    head->next = second;

    second->data = 50;
    second->next = third;

    third->data = 70;
    third->next = fourth;

    fourth->data = 90;
    fourth->next = NULL;

    printf("Elements in Linked list: \n");
    linkedlistTraversal(head);

    head = deleteFirst(head);
    // head = deleteFirst(head); // if i run it twice, next element will be deleted
    printf("After deleting Element at beginning of Linked list: \n");
    linkedlistTraversal(head);

    head = deleteAtIndex(head, 2);
    printf("After deleting Element at given index: \n");
    linkedlistTraversal(head);

    head = deleteLast(head);
    printf("After deleting Element at Last: \n");
    linkedlistTraversal(head);

    head = deleteAtValue(head, 50);
    printf("After deleting Element by Value: \n");
    linkedlistTraversal(head);

    return 0;
}