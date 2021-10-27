#include <stdio.h>
#include <stdlib.h>
// double ended queue

struct Queue{
    int data;
    struct Queue *next;
};

int isempty(struct Queue *head){
    if(head=NULL){
         return 1;
    }
    else{
        return 0;
    }
}
int isfull(struct Queue *head){
    struct Queue *n=(struct Queue *)malloc(sizeof(struct Queue));
    if(n==NULL){
        return 1;
    }
    return 0;
}
struct Queue *Enqueue_rear(struct Queue *head,int data){
    if(isfull(head)){
        printf("Queue Overflow\n");
    }
    else{
        struct Queue *ptr=(struct Queue *)malloc(sizeof(struct Queue));
        struct Queue *p=head;
        ptr->data=data;
        if(head==NULL){
            ptr->next=NULL;
            head=ptr;
        }
        else{
            for(int i=0;p->next!=NULL;i++){
                p=p->next;
            }
            ptr->next=NULL;
            p->next=ptr;
            return head;
        }
    }
    return head;
}
struct Queue *Enqueue_front(struct Queue *head,int data){
    if(isfull(head)){
        printf("Queue Overflow\n");
    }
    else{
        struct Queue *ptr=(struct Queue *)malloc(sizeof(struct Queue));
        struct Queue *p=head;
        ptr->data=data;
        if(head==NULL){
            ptr->next=NULL;
            head=ptr;
        }
        else{
            ptr->next=p;
            head=ptr;
        }
    }
    return head;
}
struct Queue *Dequeue_front(struct Queue *head){
    if(isempty(head)){
        printf("Queue Underflow\n");
    }
    else{
        if(head->next==NULL){
            head=NULL;
            return head;
        }
        else{
            struct Queue *pp=head;
            struct Queue *p=pp->next;
            head=p;
            free(pp);
            return head;
        }
        }
    return head;
}
struct Queue *Dequeue_rear(struct Queue *head){
    if(isempty(head)){
        printf("Queue Underflow\n");
    }
    else{
        if(head->next==NULL){
            head=NULL;
            return head;
        }
        else{
           struct Queue *p=head;
           struct Queue *pp=p->next;
           for(int i=0;pp->next!=NULL;i++){
               pp=pp->next;
               p=p->next;
           }
           p->next=NULL;
           free(pp);
        }
    }
    return head;
}

void Display(struct Queue *head){
    if(isempty(head)){
        printf("Queue Underflow\n");
    }
    else{
        struct Queue *p=head;
        printf("Queue elements are:-\n");
        for(int i=0;p!=NULL;i++){
        printf("%d\n",p->data);
        p=p->next;
    }
    }
}
int main(){
    int exit=1,choice,val1=1,val2=1,value1,value2,data;
    struct Queue *head=(struct Queue *)malloc(sizeof(struct Queue));
    head=NULL;
    while(exit){
    printf("Main Menu\n");
    printf("1.Enqeueu from front\n");
    printf("2.Enqueue from rear\n");
    printf("3.Dequeue from front\n");
    printf("4.Dequeue from rear\n");
    printf("5.Display\n");
    printf("6.Exit\n");
    printf("Enter your choice:- ");
    scanf("%d",&choice);
    if(choice==1){
        printf("Enter the element:- ");
        scanf("%d",&data);
        head=Enqueue_front(head,data);
    }
    if(choice==2){
        printf("Enter the element:- ");
        scanf("%d",&data);
        head=Enqueue_rear(head,data);
    }
    else if(choice==3){
        head=Dequeue_front(head);
    }
    else if(choice==4){
        head=Dequeue_rear(head);
    }
    else if(choice==5)
        Display(head);
    else if(choice==6)
        exit=0;
    else{
       printf("You entered invalid number\n");
    }
}
return 0; 
    
}