#include <stdio.h>
#include <stdlib.h>

struct stack{
    int top;
    unsigned size;
    int *arr;
};

struct stack *creation(unsigned val){
    struct stack *q= (struct stack*)malloc(sizeof(struct stack));
    q->size=val;
    q->top=-1;
    q->arr=(int *)malloc(q->size*sizeof(int));
    return q;
}

int empty(struct stack *q){
    if(q->top==-1)
        return 1;
    return 0;
}

int full(struct stack *q){
    return q->top == q->size - 1;
}

void push(struct stack *q, int val){
    if(full(q)){
        printf("Stack Overflow");
        return;}
    else{
        q->arr[++q->top] = val;
        
    }}

int  pop(struct stack *q){
    if(empty(q)){
        printf("Stack Underflow");
        return 0;}
    else{
        return (q->arr[q->top--]);
        
    }
}

struct stack *copy(struct stack *q,struct stack *r,int val){
    struct stack *temp= creation(val);
    while (!empty(q)) {
        push(temp, pop(q));
    }
    while (!empty(temp)) {
        push(r, pop(temp));
    }
    free(temp);
    return r;
}

int main(void){
    printf("Number of elements:");
    int n;
    scanf("%d",&n);
    struct stack *q=creation(n);
    push(q, 1);
    push(q, 2);
    push(q, 3);
    push(q, 4);
    struct stack *r = creation(n);
    r=copy(q,r,n);
    while (!empty(r)) {
        printf("%d",pop(r));
    }
}
