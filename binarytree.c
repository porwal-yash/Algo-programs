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
void preorder(struct node *root){
    if(root!=NULL){
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root){
    if(root!=NULL){
        postorder(root->left);
        posotorder(root->right);
        printf("%d\t",rot->data);
    }
}
void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}
int main(){
   struct node *p=create(2);
   struct node *p1=create(1);
   struct node *p2=create(4);
   struct node *p3=create(11);
   struct node *p4=create(12);
   struct node *p5=create(3);
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
   p2->right=p5;

   p5->left=NULL;
   p5->right=NULL;
   
   //preorder(p);
   //postorder(p);
   inorder(p);
   return 0;
}

