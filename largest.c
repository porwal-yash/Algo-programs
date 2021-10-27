#include <stdio.h>
#include <conio.h>

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
   int largest=0;
   for(int i=0;i<n;i++){
       if(array[largest]<array[i]){
           largest=i;
       }
   }
   for(int i=largest;i<n;i++){
       array[i]=array[i+1];
   }
   int slargest=0;
      for(int i=0;i<n;i++){
       if(array[slargest]<array[i]){
           slargest=i;
       }
   }
   printf("Second largest element in the array is %d",array[slargest]);
   printf("First largest element in the array is %d ", array[slargest+1]);

}
