#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *link;
};


void insertend(struct node *head){
    int d;
    printf("Enter Data:");
    scanf("%d",&d);
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data=d;
    ptr->link=NULL;
    while (head->link!=NULL) {
        head=head->link;
    }
    head->link=ptr;
}


void printlist(struct node *head){
    while (head!=NULL) {
        printf("%d\n",head->data);
        head=head->link;
    }
}



int main(){
    struct node *head=NULL;
    head = (struct node*)malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;
    
    struct node *ptr=NULL;
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data=60;
    ptr->link=NULL;
    head->link=ptr;
    
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data=80;
    ptr->link=NULL;
    head->link->link=ptr;
    insertend(head);
    printlist(head);
    
}
