#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void printingelements(struct Node * ptr){
      struct Node * p= ptr;
      do{
          printf("Elements is:- %d\n",p->data);
          p=p->next;
      }
      while(p!=ptr);
}

struct Node * insertionatfirst(struct Node * head,int data ){
    struct Node * ptr =  (struct Node *)malloc(sizeof(struct Node));
    struct Node * p= head->next;
    ptr->data = data;
    while(p->next != head){
        p= p->next;
    }
    // Now, p is pointing to the last node of the circular linked list
    p->next = ptr;
    ptr->next = head;
    head = ptr;
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
    third->next = head;
    
    printf("Circular linked list:-\n");
    printingelements(head);
    head=insertionatfirst(head,1);
    printf("New Circular linked list:-\n");
    printingelements(head);
   

    
}