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
//1.
struct Node * insertionatfirst(struct Node * head,int data ){
    struct Node * ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next=head;
    ptr->data = data;
    return ptr;
}
//2.
struct Node * insertioninindex(struct Node * head,int data,int index){
    struct Node * ptr =  (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->data = data;
    ptr->next= p->next;
    p->next = ptr;
    return head;

}
//3.
struct Node * insertAtEnd(struct Node *head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->next = NULL;
    return head;
}
//4
struct Node * insertAfternode(struct Node *head, int data,struct Node * p){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
void main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;

    head=(struct Node *)malloc(sizeof(struct Node));
    second=(struct Node *)malloc(sizeof(struct Node));
    third=(struct Node *)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;
    second->data = 100;
    second->next = third;
    third->data = 1000;
    third->next = NULL;
    
    printingelements(head);
    //head= insertionatfirst(head,1);
    //head= insertioninindex(head,1,2);
    //head= insertAtEnd(head,10000);
    head = insertAfternode(head,50,second);
    printf("\n");
    printingelements(head);


    
}