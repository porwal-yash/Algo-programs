#include <stdio.h>
#include <conio.h>

void deletion(int array[20],int n,int pos){
        for(int i=pos;i<n;i++){
            array[i]=array[i+1];
        }
        printf("Updated array is:-\n");
        for(int i=0;i<n-1;i++){
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
   int pos;
   printf("Enter the positon of the element:- ");
   scanf("%d",&pos);
   deletion(array,n,pos);
}