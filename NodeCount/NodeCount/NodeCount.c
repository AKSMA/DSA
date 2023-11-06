#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *link;
};

int countnodes(struct node *head){
    int count=0;
    while (head!=NULL) {
        count++;
        head=head->link;
    }
    return count;
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
    
    printf("There are %d nodes\n",countnodes(head));
}
