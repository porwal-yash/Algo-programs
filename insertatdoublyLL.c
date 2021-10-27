#include <stdio.h>
#include <stdlib.h>
/*
deletion:-  1. Start 2. inbetween 3.Last 4. delete with value
*/
struct node{
    int data;
    struct node *prev;
    struct node *next;
};
void traversal(struct node *head){
    struct node *ptr=head;
    printf("Doubly Linked List Elements:-\n");
    while(ptr!=NULL){
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
}
struct node * insertatstart(struct node *head,int data){
    struct node *ptr=(struct node * )malloc(sizeof(struct node));
    struct node * p=head;
    ptr->data=data;
    ptr->next=head;
    ptr->prev=NULL;
    return ptr;
}
struct node *insertinbtw(struct node *head,int data,int index){
    struct node * ptr=(struct node *)malloc(sizeof(struct node));
    struct node * p=head;
    for(int i=0;i!=index-1;i++){
        p=p->next;
    }
    ptr->data=data;
    ptr->next=p->next;
    ptr->prev=p;
    p->next=ptr;
    return head; 
}
struct node * insertatend(struct node *head,int data){
    struct node * ptr=(struct node *)malloc(sizeof(struct node));
    struct node *p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->data=data;
    ptr->next=NULL;
    ptr->prev=p;
    return head;
}
void main(){
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    //dynamic memory alloacation
    head=(struct node *) malloc(sizeof(struct node));
    second=(struct node *) malloc(sizeof(struct node));
    third=(struct node *) malloc(sizeof(struct node));
    fourth=(struct node *) malloc(sizeof(struct node));
    head->data = 10;
    head->prev=NULL;
    head->next=second;
    second->data = 20;
    second->prev=head;
    second->next=third;
    third->data= 30;
    third->prev=second;
    third->next=fourth;
    fourth->data =40;
    fourth->prev=third;
    fourth->next=NULL;
    //head=insertatstart(head,0);
    //head=insertinbtw(head,60,2);
    head=insertatend(head,50);
    traversal(head);
}