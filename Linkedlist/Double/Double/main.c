#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *creation(int value){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->next=NULL;
    temp->data=value;
    temp->prev=NULL;
    return temp;
}

struct node * addbeg(struct node *q,int val){
    struct node *temp=creation(val);
    temp->next=q;
    q->prev=temp;
    q=temp;
    return q;
}

void addend(struct node *q,int val){
    struct node *temp=creation(val);
    while (q->next!=NULL) {
        q=q->next;
    }
    q->next=temp;
    temp->prev=q;
}

void addmid(struct node *q,int val){
    printf("enter pos");
    int p;
    scanf("%d",&p);
    p--;
    struct node *temp=creation(val);
    while (p>1) {
        q=q->next;
        p--;
    }
    temp->next=q->next;
    q->next=temp;
    temp->prev=q;
    temp->next->prev=temp;
    
}

struct node *delbeg(struct node *q){
    struct node* temp=NULL;
    temp=q->next;
    free(q);
    q=temp;
    return q;
}

void delend(struct node* q){
    while (q->next!=NULL) {
        q=q->next;
    }
    q->prev->next=NULL;
    free(q);
}

struct node* delmid(struct node *q){
    printf("enter pos");
    int p;
    scanf("%d",&p);
    if(p==1){
        if(q->next==NULL){
            free(q);
            return NULL;}
        else{
            struct node* t=q->next;
            q->next->prev=NULL;
            free(q);
            return t;
        }
    }
    struct node * t=NULL;
    t=q;
    while(p!=1){
        q=q->next;
        p--;
    }
    struct node * temp=NULL;
    
    if(q->next==NULL){
        q->prev->next=NULL;
        free(q);
        return t;
    }
    else{
        temp=q->next;
        q->prev->next=temp;
        temp->prev=q->prev;
        free(q);
        return t;}
}

struct node* delall(struct node *q){
    struct node* temp=NULL;
    while (q!=NULL) {
        temp=q;
        q=q->next;
        free(temp);
    }
    return NULL;
}

void print(struct node* q){
    while (q!=NULL) {
        printf("%d",q->data);
        q=q->next;
    }
}

int main(){
    struct node *q=NULL;
    q=creation(1);
    print(q);
    printf("\n");
    q=addbeg(q,2);
    print(q);
    printf("\n");
    addend(q,3);
    print(q);
    printf("\n");
    addmid(q,4);
    print(q);
    printf("\n");
    q=delbeg(q);
    print(q);
    printf("\n");
    delend(q);
    print(q);
    printf("\n");
    q=delmid(q);
    print(q);
    printf("\n");
    q=delall(q);
    print(q);
    printf("\n");


}
