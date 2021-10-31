#include <stdio.h>
#include <stdlib.h>

struct node{
    char data;
    struct node *next;
};

int isEmpty(struct node *ptr){
     if(ptr==NULL){
         return 1;
     }
     return 0;
}

int isFull(){
    struct node *n=(struct node *)malloc(sizeof(struct node));
    if(n==NULL){
        free(n);
        return 1;
    }
    return 0;
}

struct node * push(struct node *ptr,char data){
    if(isFull()){ 
         printf("Stack Overflow'\n");
    }
    else{
    struct node *n=(struct node *)malloc(sizeof(struct node));
    n->data=data;
    n->next=ptr;
    ptr=n;
    }
return ptr;
}

struct node * pop(struct node *ptr,char *poped){
        *poped=ptr->data;
        struct node *pp=ptr;
        struct node *p=ptr->next;
        ptr=p;
        free(pp);
return ptr;
}

void display(struct node *ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow\n");
    }
    else{
        struct node *p=ptr;
        for(int i=0;p!=NULL;i++){
            printf("%c\n",p->data);
            p=p->next;
        }
    }
}

void peek(struct node *ptr){
    struct node *pp=ptr;
    int pos;
    printf("Enter the position of the element:- ");
    scanf("%d",&pos);
    for(int i=0;i<pos-1 && pp!=NULL;i++){
        pp=pp->next;
    }
    if(pp!=NULL){
        printf("%d\n",pp->data);
    }
    else{
        printf("Element not found with given index\n");
    }
}

void stackTop(struct node *ptr){
    if(isEmpty(ptr)){
        printf("Stack Overflow\n");
    }
    else{
        printf("Element of the top node is %d\n",ptr->data);
    }
}

void stackBottom(struct node *ptr){
    struct node *pp=ptr;
    while(pp->next!=NULL){
        pp=pp->next;
    }
    printf("Element of the buttom node is %d\n",pp->data);
}

int match(char a,char b){
    if(a=='(' && b==')')
        return 1;
    else if(a=='[' && b==']')
        return 1;
    else if(a=='{' && b=='}')
        return 1;
    else 
        return 0;
}

void main(){
    struct node *top=(struct node *)malloc(sizeof(struct node));
    top=NULL;
    char value[40],popedval;
    int check;
    printf("Enter your Expression:- ");
    scanf("%s",&value);
    for(int i=0;value[i]!='\0';i++){
        if(value[i]=='(' || value[i]=='{' || value[i]=='['){
            top=push(top,value[i]);
        }
        else if(value[i]==')' || value[i]=='}' || value[i]==']'){
            if(isEmpty(top)){
                printf("Not balanced Expression1\n");
                exit(0);
            }
            else{
                top=pop(top,&popedval);
                check=match(popedval,value[i]);
                if(check==0){
                    printf("Not balanced Expression2\n");
                    exit(0);
                }
            }
        }
    }
    
    if(isEmpty(top)){
        printf("Balanced Expression\n");
    }
    else{
        printf("Value of the top value is %c\n",top->data);
        printf("Not balanced Expression3\n");
    }  
}
