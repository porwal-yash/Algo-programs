#include <stdio.h>
#include <stdlib.h>
// Sorting algorithm
// insertion sorting
void printarray(int *A,int n){
    for(int i=0;i<n;i++){
        printf("%d\t",A[i]);
    }
    printf("\n");
}
void selection_sort(int *A,int n){
   int min,temp;
   printf("Running selection sorting...\n");
   for (int i = 0; i<n-1;i++)
   {
       min=i;
       for (int j=i+1;j<=n-1;j++)
       {
         if(A[j]<A[min]){
            min=j;
         }
       }
       temp=A[i];
       A[i]=A[min];
       A[min]=temp;
   }
}

int main(){
  int A[]={3,5,2,13,12};
  //int A[]={2,3,7,77,91};
  int n=5;
  printf("Before sorting:-\n");
  printarray(A,n);
  selection_sort(A,n);
  printf("After sorting\n");
  printarray(A,n);
  return 0;
}