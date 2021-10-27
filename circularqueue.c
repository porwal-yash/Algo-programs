#include <stdio.h>
#include <stdlib.h>
// circular queue using linked list
struct Queue{
    int data;
    struct Queue *next;
};
int isfull(struct Queue *ptr){
    struct Queue *n=(struct Queue *)malloc(sizeof(struct Queue));
    if(n==NULL){
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
struct Queue * Enqueue(struct Queue *head,int data){
    struct Queue * ptr=(struct Queue *) malloc (sizeof(struct Queue));
    struct Queue * p=head;
    ptr->data=data;

    if(head==NULL){
        ptr->next=ptr;
        head=ptr;
        return head;
    }
    else{
       do{
        p=p->next;
        }
        while(p->next!=head);
        p->next=ptr;
        ptr->next=head;
        return head;
    }
}
struct Queue *Dequeue(struct Queue *head,int *val,int *val1){
    if(isempty(head)){
        printf("Queue Underflow\n");
        *val1=0;
    }
    else{
        if(head->next==head){
            struct Queue *p=head;
            *val=p->data;
            head=NULL;
            free(p);
            return head;
        }
        else{
            struct Queue *pp=head;
            struct Queue *ptr=head;
            struct Queue *p=ptr->next;
            *val=ptr->data;
            do{
                pp=pp->next;
            }
            while(pp->next!=head);
            pp->next=p;
            head=p;
            free(ptr);
            return head;
        }
    }
}
void Display(struct Queue *ptr){
    if(isempty(ptr)){
        printf("Queue Underflow\n");
    }
    else{
        struct Queue *p=ptr;
        do{
            printf("%d\n",p->data);
            p=p->next;
        }
        while(p!=ptr);
    }
}
int main(){
    int choice,exit=1,val,data,val1=1;
    struct Queue *head=(struct Queue *)malloc(sizeof(struct Queue));
    head=NULL;
    while(exit){
    printf("Main Menu\n");
    printf("1.Enqeueu\n");
    printf("2.Dequeue\n");
    printf("3.Display\n");
    printf("4.Exit\n");
    printf("Enter your choice:- ");
    scanf("%d",&choice);
    if(choice==1){
        printf("Enter the element:- ");
        scanf("%d",&data);
        head=Enqueue(head,data);
    }
    else if(choice==2){
        head=Dequeue(head,&val,&val1);
        if(val1)
        printf("You deleted %d\n",val);
    }
    else if(choice==3)
        Display(head);
    else if(choice==4)
        exit=0;
    else{
       printf("You entered invalid number\n");
    }
}
return 0; 
}