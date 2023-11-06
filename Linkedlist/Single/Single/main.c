#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};


struct node* creation(int val){
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = val;
    new_node->next = NULL;
    return new_node;
}

struct node* addbeg(struct node* q,int val){
    struct node* new_node = creation(val);
    new_node->next=q;
    q=new_node;
    new_node=NULL;
    free(new_node);
    return q;
}

void addend(struct node *q,int val){
    struct node* new_node = creation(val);
    while(q->next!=NULL){
        q=q->next;
    }
    q->next=new_node;
    new_node=NULL;
    free(new_node);
}

void addmid(struct node *q,int val){
    printf("Enter position:");
    int p;
    scanf("%d",&p);
    struct node *new_node=creation(val);
    
    while(p!=1){
        q=q->next;
        p--;
    }
    new_node->next=q->next;
    q->next=new_node;
    new_node=NULL;
    free(new_node);
}

struct node* deletefirst(struct node *q){
    struct node *new_node=NULL;
    new_node=q->next;
    free(q);
    q=new_node;
    return q;
}

void deletelast(struct node *q){
    if(q==NULL)
    printf("Empty list");
    else if(q->next==NULL){
        free(q);
        q=NULL;
    }
    else{
    while(q->next->next!=NULL)
    q=q->next;
    free(q->next);
    q->next=NULL;
}
}

void deletemid(struct node *q){
    printf("Enter position:");
    int p;
    scanf("%d",&p);
    if(q==NULL)
    printf("Empty list");
    else if(q->next==NULL){
        free(q);
        q=NULL;
    }
    else{
        p--;
        while(p>1){
            q=q->next;
        }
        struct node *temp=NULL;
        temp=q->next;
        q->next=temp->next;
        free(temp);
        temp=NULL;
    }
}


struct node *deleteall(struct node *q){
    if(q==NULL){
        printf("Empty list");
        return NULL;
    }
    else{
        struct node *temp=NULL;
        while(q!=NULL){
            temp=q;
            q=q->next;
            free(temp);
            
        }
        free(q);
        temp=NULL;
        q=NULL;
        return q;
    }
}

void print(struct node *q){
    while(q!=NULL){
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
    q=deletefirst(q);
    print(q);
    printf("\n");
    deletelast(q);
    print(q);
    printf("\n");
    deletemid(q);
    print(q);
    printf("\n");
    q=deleteall(q);
    print(q);
    printf("\n");


    
    
    
    
    
    
    
    
    
}
