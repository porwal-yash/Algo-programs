#include <stdio.h>
#include <conio.h>

void insertion(int array[20],int n,int pos,int element){
      for(int i=n-1;i>=pos;i--){
           array[i+1]=array[i];
      }  
      array[pos]=element;
      n++;
    printf("Updated  array is:-\n");
    for(int i=0;i<n;i++){
       printf("%d\t",array[i]);
   }
}
void main(){
   int array[20];
   int n;
   printf("Enter the size of the array:- ");
   scanf("%d",&n);
   printf("Enter the elements of the array:- ");
   for(int i=0;i<n;i++){
       scanf("%d",&array[i]);
   }
   printf("Entered array is:-\n");
   for(int i=0;i<n;i++){
       printf("%d\t",array[i]);
   }
   int pos,element;
   printf("Enter the position of the element:- ");
   scanf("%d",&pos);
   printf("Enter the element to insert:- ");
   scanf("%d",&element);
   insertion(array,n,pos,element);

 
}