#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node{
    int row;
    int col;
    struct node* next;
};

struct node* insert(struct node* q,int r,int c){
    if (q==NULL) {
        q=(struct node*)malloc(sizeof(struct node));
        q->row=r;
        q->col=c;
        q->next=NULL;
        return q;}
    else{
        struct node*t =q;
        while((t->next!=NULL)){
            t=t->next;
    }
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->row = r ;
     temp->col = c ;
    temp -> next = NULL;
    t->next=temp;
    temp=NULL;
    free(temp);
    return q;
    }
}
void disp(struct node*q){
    while ((q != NULL)){
        printf("%d%d->",q->row,q->col);
        q=q->next;
    }
}

void search(struct node*q){
    int count=0;
    
    while(q!=NULL){
        struct node*t=q->next;
        while(t!=NULL){
            int l=0;
            if(t->row-q->row<=1 && t->row-q->row>=-1 && t->col-q->col<=1 && t->col-q->col>=-1){
                printf("%d%d-",q->row,q->col);
                printf("%d%d-",t->row,t->col);
                l++;
                int tr,tc;
                tr=t->row-q->row;
                tc=t->col-q->col;
                struct node*temp=t->next;
                struct node*k=t;
                while(temp!=NULL){
                    
                    if(temp->row-k->row==tr&& temp->col-k->col==tc){
                        l++;
                        k=temp;
                        temp=temp->next;
                        printf("%d%d-",k->row,k->col);
                    }
                    else
                    temp=temp->next;
                }
            }
            if(l>=2){
                count++;
            }
            if(l>2)
                count--;
            t=t->next;
            printf("\n");
        }
        q=q->next;
    }
    printf("\n%d",count);
}





int main(){
    int n;
    printf("enter number of non zero elements");
    scanf("%d",&n);
    struct node* q=NULL;
    int i;
    for( i=0;i<n;i++){
        int r,c;
        printf("\n enter the element %d ",i+1);
        scanf("%1d%1d",&r,&c);
        q=insert(q,r,c);
    }

    search(q);
}
