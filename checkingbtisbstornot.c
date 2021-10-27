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
        postorder(root->right);
        printf("%d\t",root->data);
    }
}

int inbst(struct node *root){
   static struct node *prev=NULL;
   if(root!=NULL){
       if(!inbst(root->left)){
        return 0;
       }
       if(prev!=NULL && root->data <= prev->data){
        return 0;
       }
       prev=root;
       return inbst(root->right);
   }
   else{
      return 1;
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
   printf("Preorder Traversal:-\n");
   preorder(p);
   printf("\npostorder Traversal:-\n");
   postorder(p);
   printf("\ninorder traversal:-\n");
   inorder(p);
   printf("\n");
   if(inbst(p)){
    printf("It is bst\n");
   }
   else{
    printf("It is not bst\n");
   }
   
return 0;

}
