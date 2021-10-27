#include <stdio.h>
#include <stdlib.h>
/*
deletion:-  1. Start 2. inbetween 3.Last 4. delete with value
*/
struct node{
    int data;
    struct node *next;
};
void traversal(struct node * head){
    struct node *ptr=head;
    printf("Circular Linked list data:-\n");
    do{
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
    while(ptr!=head);
}
struct node * deletefromstart(struct node *head){
    struct node *ptr=head->next;
    struct node * p=head;
    do{
        p=p->next;
    }
    while(p->next!=head);
    p->next=ptr;
    return ptr;
}
struct node *deleteinbtw(struct node *head,int index){
    struct node * p=head;
    struct node * ptr=p->next;
    for(int i=0;i!=index-1;i++){
        p=p->next;
        ptr=ptr->next;
    }
    p->next=ptr->next;
    free(ptr);
    return head; 
}
struct node * deletefromend(struct node *head){
    struct node * p=head;
    do{
        p=p->next;
    }
    while(p->next->next!=head);
    struct node * ptr=p->next;
    p->next=head;
    free(ptr);
    return head;
}
struct node * deletebyvalue(struct node *head,int value){
    struct node * ptr=(struct node *)malloc(sizeof(struct node));
    struct node *p=head;
    ptr=p->next;
    while(ptr->data!=value && ptr->next!=NULL){
        p=p->next;
        ptr=ptr->next;
    }
    if(ptr->data==value){
        p->next=ptr->next;
        free(ptr);
    }
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
    head->next=second;
    second->data = 20;
    second->next=third;
    third->data= 30;
    third->next=fourth;
    fourth->data =40;
    fourth->next=head;
    //head=deletefromstart(head);
    //head=deleteinbtw(head,2);
    //head=deletefromend(head);
    head=deletebyvalue(head,20);
    traversal(head);
}