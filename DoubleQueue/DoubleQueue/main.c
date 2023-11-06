#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

struct queue{
    struct node *front,*rear;
};

struct node *new(int val){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}

struct queue* creation(){
    struct queue* temp=(struct queue*)malloc(sizeof(struct queue));
    temp->front=temp->rear=NULL;
    return temp;
}

void insertatfront(struct queue* q,int val){
    struct node* temp=new(val);
    if(q->front==NULL){
        q->front=q->rear=temp;
    }
    temp->next=q->front;
    q->front->prev=temp;
    q->front=temp;
}

void insertatend(struct queue* q,int val){
    struct node* temp=new(val);
    if(q->rear==NULL){
        q->front=q->rear=temp;
    }
    temp->prev=q->rear;
    q->rear->next=temp;
    q->rear=temp;
}

void deleteatfirst(struct queue* q){
    if(q->front==NULL){
        printf("Queue empty");
        return;
    }
    struct node* temp=q->front;
    q->front=q->front->next;
    if(q->front==NULL){
        q->rear=NULL;
    }
    else
    q->front->prev=NULL;
    free(temp);
}

void deleteatend(struct queue* q){
    if(q->rear==NULL){
        printf("Queue empty");
        return;
    }
    struct node* temp=q->rear;
    q->rear=q->rear->prev;
    if(q->rear==NULL){
        q->front=NULL;
    }
    else
    q->rear->next=NULL;
    free(temp);
}

int main()
{
    struct queue* q = creation();
    insertatfront(q, 10);
    insertatend(q, 20);
    deleteatend(q);
    deleteatfirst(q);
    insertatfront(q, 30);
    insertatend(q, 40);
    insertatfront(q, 50);
    printf("Queue Front : %d \n", ((q->front != NULL) ? (q->front)->data : -1));
    printf("Queue Rear : %d", ((q->rear != NULL) ? (q->rear)->data : -1));
    return 0;
}
