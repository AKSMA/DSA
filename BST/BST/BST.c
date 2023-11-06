#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node* lchild;
    int data;
    struct node* rchild;
}*root=NULL;

struct node *create(int val){
    struct node* temp=NULL;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->rchild=temp->lchild=NULL;
    return temp;
}

void insertbst(int val){
    struct node* t=root;
    struct node* r=NULL,*p;
    if(t==NULL){
        p=create(val);
        root=p;
        return;
    }
    while (t!=NULL) {
        r=t;
        if(t->data>val)
            t=t->lchild;
        else if(val>t->data)
            t=t->rchild;
        else{
            printf("Number already exist");
            return;
        };
    }
    p=create(val);
    if(r->data>val)
        r->lchild=p;
    else r->rchild=p;
    
}

int height(struct node* q){
    int x,y;
    if(q==NULL)return 0;
    x=height(q->lchild);
    y=height(q->rchild);
    return x>y?x+1:y+1;
}

struct node* inpre(struct node* q){
    while (q && q->rchild!=NULL) {
        q=q->rchild;
    }
    return q;
}

struct node* insuc(struct node* q){
    while (q && q->lchild!=NULL) {
        q=q->lchild;
    }
    return q;
}

struct node* deletebst(struct node* q,int val){
    struct node* p=NULL;
    if(q==NULL){
        return q;
    }
    if(q->lchild==NULL && q->rchild==NULL){
        if(q==root)
            root= NULL;
        free(q);
        return NULL;
    }
    
    if(q->data>val)
        deletebst(q->lchild, val);
    else if(q->data<val)
        deletebst(q->rchild, val);
    else{
        if(height(q->lchild)>height(q->rchild)){
            p=inpre(q->lchild);
            q->data=p->data;
            q->lchild=deletebst(q->lchild, p->data);
        }
        else{
            p=insuc(q->rchild);
            q->data=p->data;
            q->rchild=deletebst(q->rchild, p->data);
        }
    }
    return q;
}

void inorderbst(struct node*q){
    if(q){
        inorderbst(q->lchild);
        printf("%d ",q->data);
        inorderbst(q->rchild);
    }
}

void preorderbst(struct node*q){
    if(q){
        printf("%d",q->data);
        preorderbst(q->lchild);
        preorderbst(q->rchild);
    }
}

void postorderbst(struct node*q){
    if(q){
        postorderbst(q->lchild);
        postorderbst(q->rchild);
        printf("%d",q->data);
    }
}



struct node* search(int val){
    struct node*t=root;
    while (t!=NULL) {
        if(val==t->data)
            return t;
        if(val>t->data)
            t=t->rchild;
        if(val<t->data)
            t=t->lchild;
    }
    return NULL;
}

int main(){
    insertbst(10);
    insertbst(20);
    insertbst(15);
    insertbst(35);
    insertbst(40);
    deletebst(root, 10);
    inorderbst(root);
    printf("\n");
    if(search(20))
        printf("in\n");
    else printf("out\n");
}
