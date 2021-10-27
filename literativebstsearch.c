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
struct node *bstsearch(struct node *root,int value){
   while(root!=NULL){
        if(root->data == value){
            return root;
        }
        else if(root->data > value){
            root=root->left;
        }
        else{
            root=root->right;
        }
   }
   return NULL;
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
   

   struct node *search=bstsearch(p,value);
   if(search!=NULL){
    printf("Element found:- %d\n",search->data);
   }
   else{
    printf("Element Not found\n");
   }

return 0;
}
