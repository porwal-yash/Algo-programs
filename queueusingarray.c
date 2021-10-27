#include <stdio.h>
#include <stdlib.h>
struct array{
    int size;
    int lend;
    int fend;
    int *data;
};
int isfull(struct array *ptr){
    if(ptr->lend==ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isempty(struct array *ptr){
    if(ptr->fend==ptr->lend){
        return 1;
    }
    else{
        return 0;
    }
}
int Enqueue(struct array *ptr){
    int data1;
     if(isfull(ptr)){
         printf("Queue Overflow\n");
     }
     else{
        printf("Enter the data:- ");
        scanf("%d",&data1);
        ptr->lend=ptr->lend+1;
        ptr->data[ptr->lend]=data1;
     }
    return ptr->lend;
}
int Dequeue(struct array *ptr,int *val){
    int delete;
    if(isempty(ptr)){
        printf("Queue Underflow\n");
        *val=0;
    }
    else{
        delete=ptr->data[0];
        for(int i=0;i!=ptr->lend;i++){
            ptr->data[i]=ptr->data[i+1];
        }
        ptr->lend=ptr->lend-1;
    }
    return delete;
}
void Display(struct array *ptr){
    printf("Queue elements are:-\n");
    for(int i=0;i<ptr->lend+1;i++){
        printf("%d\n",ptr->data[i]);
    }
}
int main(){
    int value,exit=1,choice,val;
    struct array *S=(struct array *)malloc(sizeof(struct array));
    S->size=40;
    S->lend=-1;
    S->fend=-1;
    S->data=(int *)malloc(S->size*sizeof(struct array));
    while(exit){
    printf("Main Menu\n");
    printf("1.Enqueue\n");
    printf("2.Dequeue\n");
    printf("3.Display\n");
    printf("4.Exit\n");
    printf("Enter your choice:- ");
    scanf("%d",&choice);
    if(choice==1)
        S->lend=Enqueue(S);
    else if(choice==2){
        value=Dequeue(S,&val);
        if(val==0){
            continue;
        }
        else{
             printf("Element %d is sucessfully Deleted\n",value);
        }
    }
    else if(choice==3)
        Display(S);
    else if(choice==4)
        exit=0;
    else{
       printf("You entered invalid number\n");
    }
}
    return 0;
}