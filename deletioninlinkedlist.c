#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void printingelements(struct Node * ptr){
    while(ptr!=NULL){
        printf("Elements are:- %d\n",ptr->data);
        ptr=ptr->next;
    }
}

//Case 1 
struct Node * deletefirst(struct Node * head){
    struct Node * ptr=head;
    head=head->next;
    free(ptr);
    return head;
}
//Case 2
struct Node * deleteinbtw(struct Node * head,int index){
    struct Node * p=head;
    struct Node * q = p->next;
    int i=0;
    while(i!=index-1){
        p=p->next;
        q=q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

//Case 3
struct Node * deleteatlast(struct Node * head){
    struct Node * p=head;
    struct Node * q=p->next;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}
//Case 4
struct Node * deletebyvalue(struct Node * head,int value){
    struct Node * p=head;
    struct Node * q = p->next;
    while(q->data!=value && q->data!=NULL){
        p=p->next;
        q=q->next;
    }
    if(q->data == value){
        p->next = q->next;
        free(q);
    }
    return head;
}


void main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head=(struct Node *)malloc(sizeof(struct Node));
    second=(struct Node *)malloc(sizeof(struct Node));
    third=(struct Node *)malloc(sizeof(struct Node));
    fourth=(struct Node *)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;
    second->data = 100;
    second->next = third;
    third->data = 1000;
    third->next = fourth;
    fourth->data=10000;
    fourth->next=NULL;
    
    printingelements(head);
    //head = deletefirst(head);
    //head = deleteinbtw(head,1);
    //head = deleteatlast(head);
    head = deletebyvalue(head,1000);
    printf("\n");
    printingelements(head);
   

    
}