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
struct node * deletefromstart(struct node *head){
    struct node * p=head;
    struct node * ptr=p->next;
    ptr->prev=NULL;
    free(p);
    return ptr;
}
struct node *deleteinbtw(struct node *head,int index){
    struct node * p=head;
    struct node *ptr=p->next;
    for(int i=0;i!=index-1;i++){
        p=p->next;
        ptr=ptr->next;
    }
    struct node *pp=ptr->next;
    p->next=pp;
    pp->prev=p;
    free(ptr);
    return head; 
}
struct node * deletefromend(struct node *head){
    struct node * p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    struct node * ptr=p->prev;
    ptr->next=NULL;
    free(p);
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
    //head=deletefromstart(head);
    //head=deleteinbtw(head,1);
    head=deletefromend(head);
    traversal(head);
}