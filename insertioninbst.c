#include <stdio.h>
#include <stdlib.h>
// Binary Tree represtation 
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *create(int data){
    struct node *n=(struct node *)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}

void insertion(struct node *root,int data){
   struct node *prev=NULL;
   while(root!=NULL){
    prev=root;
    if(root->data==data){
        printf("Element %d is already in the bst\n",data);
        exit(1);
    }
    else if(root->data>data){
        root=root->left;
    }
    else{
        root=root->right;
    }
   }
   struct node *hello=create(data);
   if(prev->data>data){
    prev->left=hello;
   }
   else{
    prev->right=hello;
   }
}
int main(){
   int value;
   scanf("%d",&value);
   struct node *p=create(5);
   struct node *p1=create(3);
   struct node *p2=create(6);
   struct node *p3=create(1);
   struct node *p4=create(4);
// linking nodes to one another.
   p->left=p1;
   p->right=p2;

   p1->left=p3;
   p1->right=p4;

   p3->left=NULL;
   p3->right=NULL;

   p4->left=NULL;
   p4->right=NULL;

   p2->left=NULL;
   p2->right=NULL;
   
   insertion(p,value);
   
return 0;
}
