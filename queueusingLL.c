#include <stdio.h>
#include <stdlib.h>
// Queue Using Linked List
struct Queue {
    int data;
    struct Queue *next;
};
int isfull(struct Queue *ptr){
    struct Queue *n=(struct Queue *)malloc(sizeof(struct Queue));
    if(n==NULL){
        free(n);
        return 1;
    }
    else{
        return 0;
    }
}
int isempty(struct Queue *ptr){
    if(ptr==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
struct Queue *Enqueue(struct Queue *ptr){
    int data;
    if(isfull(ptr)){
        printf("Queue Overflow\n");
    }
    else{
        struct Queue *p=(struct Queue *)malloc(sizeof(struct Queue));
        printf("Enter the data:- ");
        scanf("%d",&data);
        p->data=data;
        p->next=ptr;
        ptr=p;
    } 
return ptr;
}
struct Queue *Dequeue(struct Queue *ptr){
    if(isempty(ptr)){
        printf("Queue Underflow\n");
    }
    else if(ptr->next==NULL){
        struct Queue *p=ptr;
        ptr=NULL;
        free(p);
    }
    else{
        struct Queue *p=ptr;
        struct Queue *pp=p->next;
        for(int i=0;pp->next!=NULL;i++){
            p=p->next;
            pp=pp->next;
        }
        p->next=NULL;
        free(pp);
    }
return ptr;
}
void Display(struct Queue *ptr){
    if(isempty(ptr)){
        printf("Queue Underflow\n");
    }
    else{
    printf("Queue elements are:-\n");
    struct Queue *p=ptr;
    for(int i=0;p!=NULL;i++){
        printf("%d\n",p->data);
        p=p->next;
    }
    }
}
int main(){
    int choice,exit=1;
    struct Queue *S=(struct Queue *)malloc(sizeof(struct Queue));
    S=NULL;
    while(exit){
    printf("Main Menu\n");
    printf("1.Enqeueu\n");
    printf("2.Dequeue\n");
    printf("3.Display\n");
    printf("4.Exit\n");
    printf("Enter your choice:- ");
    scanf("%d",&choice);
    if(choice==1)
        S=Enqueue(S);
    else if(choice==2){
        S=Dequeue(S);
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