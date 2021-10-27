#include <stdio.h>
#include <conio.h>

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
   

    
}