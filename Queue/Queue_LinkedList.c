#include <stdio.h>
#include <stdlib.h>


struct Node
{
    int data;
    struct Node *next;
};
struct Node *front = NULL;
struct Node *rear = NULL;

void LinkedListTraversal(struct Node * ptr){
    while(ptr!=NULL){
        printf("Element %d\n",ptr->data);
        ptr= ptr->next;
    }
}

void Enqueue(int val){
    struct Node * n=(struct Node *)malloc(sizeof(struct Node));
    if(n==NULL){
        printf("Queue is Full\n");
    }
    else{
        n->data=val;
        n->next=NULL;
        if(front==NULL){
            front = rear = n;
        }
        else{
            rear->next=n;
            rear=n;

        }
    }
}

int dequeue (){
    int val=-1;
    struct Node * ptr=front;
    if(front==NULL){
        printf("Queue is Empty");

    }
    else{
      front=front->next;
      val=ptr->data;
      free(ptr);
    }
    return val;
}


int main()
{
    LinkedListTraversal(front);
    Enqueue(34);
    Enqueue(4);
    Enqueue(7);
    LinkedListTraversal(front);
    printf("Dequeuing Element %d\n",dequeue());
    LinkedListTraversal(front);

    return 0;
}