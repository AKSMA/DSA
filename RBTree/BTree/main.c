#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node{
    int *data;
    struct node **key;
    int t;
    int n;
    bool leaf;
};

struct node* create(int order,bool l){
    struct node*q=(struct node*)malloc(sizeof(struct node));
    q->data=(int *)malloc(order);
    q->t=order;
    q->n=0;
    q->key=(struct node **)malloc(order+1);
    q->leaf=l;
    return q;
}


void find(struct node* temp,int t){
   // if (temp->leaf) {
        if (temp->n==0) {
            temp->data[0]=t;
            temp->n++;
            return;
        }
        int pos=temp->n-1;
        for (int i=0; i<temp->n; i++) {
            if (t>temp->data[i]) {
                pos=i+1;
            }
            else break;
        }
        for (int i=temp->n-1; i>=pos; i--) {
            temp->data[i+1]=temp->data[i];
        }
        temp->data[pos]=t;
        temp->n++;
    //}
}


struct node *insert(struct node* root,int t,struct node* temp){
    while (!root->leaf) {
        int k=0;
        if (t<root->data[0]) {
            root=insert(root->key[0], t,root);
            break;
        }
        if (t>root->data[root->n-1]) {
            root=insert(root->key[root->n], t,root);
            break;
        }
        for (int  i=0; i<(root->n)-1; i++) {
           
            if(t>root->data[i]&&t<root->data[i+1]){
                k=i+1;
                break;
            }
           
        }
        root=insert(root->key[k], t,root);
    }
    if (root->leaf) {
        find(root, t);
    }
    
    if(root->n==root->t && root!=temp){
        find(temp, root->data[(root->n-1)/2]);
        struct node *q=create(root->t,root->leaf);
        int i=0;
        for (int j=(root->n+1)/2;j<= root->n; j++) {
            q->data[i]=root->data[j];
            i++;
            q->n++;
        }
        if (!root->leaf) {
            int i=0;
            for (int j=(root->n+1)/2;j<=root->n; j++) {
                q->key[i]=root->key[j];
                i++;
            }
        }
        
        int pos=0;
        for (int i=0; i<temp->n; i++) {
            if (temp->data[i]==root->data[(root->n-1)/2]) {
                pos=i+1;
                break;
            }
        }
        root->n=((root->n-1)/2);
        for (int i=temp->n; i>pos; i--) {
            temp->key[i+1]=temp->key[i];
        }
        temp->key[pos]=q;
    }
    if (root->n==root->t && root==temp) {
        struct node*p=create(root->t, false);
        struct node*s=create(root->t, root->leaf);
        p->data[p->n]=root->data[(root->n-1)/2];
        p->n++;
        int i=0;
        for (int j=(root->n+1)/2; j<=root->n-1; j++) {
            s->data[i]=root->data[j];
            i++;
            s->n++;
        }
        if (!root->leaf) {
            int i=0;
            for (int j=(root->n+1)/2;j<= root->n; j++) {
                s->key[i]=root->key[j];
                i++;
            }
        }
        root->n=((root->n-1)/2);
        p->key[0]=root;
        p->key[1]=s;
        temp=p;
    }
    return temp;
}

int main() {
    struct node *root=create(5, true);
    int n;
    for (int i=1; i<=8; i++) {
        //scanf("%d",&n);
        root=insert(root, i, root);
    }
    printf("%d",root->data[0]);
    printf("%d",root->data[1]);
    printf("%d",root->key[0]->data[0]);
    printf("%d",root->key[0]->data[1]);
    //printf("%d",root->key[1]->data[0]);
    //printf("%d",root->key[1]->data[1]);
    printf("%d",root->key[2]->data[0]);
    printf("%d",root->key[2]->data[1]);
    return 0;
}
