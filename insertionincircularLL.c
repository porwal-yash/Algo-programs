#include <stdio.h>
#include <stdlib.h>
/*

insertion:- 1. Start 2. inbetween 3.last
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
struct node * insertionatstart(struct node *head,int data){
    struct node * ptr=(struct node *) malloc (sizeof(struct node));
    struct node * p=head;
    ptr->data=data;
    do{
        p=p->next;
    }
    while(p->next!=head);
    printf("value of p is %d\n",p->data);
    p->next=ptr;
    ptr->next=head;
    return ptr;

}
struct node *insertinbtw(struct node *head,int data,int index){
    struct node * ptr=(struct node *) malloc(sizeof(struct node));
    struct node * p=head;
    for(int i=0;i!=index-1;i++){
        p=p->next;
    }
    ptr->next=p->next;
    ptr->data=data;
    p->next=ptr;
    return head; 
}
struct node * insertatend(struct node *head,int data){
    struct node * ptr=(struct node *)malloc(sizeof(struct node));
    struct node * p=head;
    do{
        p=p->next;
    }
    while(p->next!=head);
    p->next=ptr;
    ptr->next=head;
    ptr->data=data;
    return head;
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
    //head=insertionatstart(head,0);
    //head=insertinbtw(head,60,1);
    head=insertatend(head,50);
    traversal(head);
}