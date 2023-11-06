#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
}*front=NULL,*rear=NULL;

    


struct node *new(int val){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->next=NULL;
    return temp;
}


void enqueue(struct node* q,int val){
    struct node* temp=new(val);
    if(rear==NULL){
        front=rear=temp;
        return;
    }
    rear->next=temp;
    rear=temp;
}

void dequeue(struct node* q){
    if(front==NULL){
        printf("Queue empty");
        return;
    }
    struct node* temp=NULL;
    temp=front;
    front=front->next;
    if(front==NULL)
        rear=NULL;
    free(temp);
}

int main()
{
    struct node* q = NULL;
    enqueue(q, 10);
    enqueue(q, 20);
    dequeue(q);
    dequeue(q);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    dequeue(q);
    printf("Queue Front : %d \n", ((front != NULL) ? (front)->data : -1));
    printf("Queue Rear : %d", ((rear != NULL) ? (rear)->data : -1));
    return 0;
}
