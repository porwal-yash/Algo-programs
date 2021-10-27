#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * prev;
    struct Node * next;
};

void printingelements(struct Node * ptr){
    struct Node * p = ptr->next;
    printf("Printing elements in the forward order:\n");
    while(ptr!=NULL){
        printf("Elements are: %d\n",ptr->data);
        ptr=ptr->next;
    }
    while(p->next!=NULL){
        p=p->next;
    }
    printf("Printing elements in the reverse order:\n");
    while(p!=NULL){
        printf("Elements are: %d\n",p->data);
        p=p->prev;
    }
}
void main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;

    head=(struct Node *)malloc(sizeof(struct Node));
    second=(struct Node *)malloc(sizeof(struct Node));
    third=(struct Node *)malloc(sizeof(struct Node));

    head->data = 10;
    head->prev = NULL;
    head->next = second;
    second->data = 100;
    second->prev = head;
    second->next = third;
    third->data = 1000;
    third->prev = second;
    third->next = NULL;
    
    printingelements(head);
   

    
}