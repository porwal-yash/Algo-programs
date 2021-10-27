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
void insertion_sorting(int *A,int n){
    int key,j,temp;
   for(int i=1;i<=n-1;i++){
        printf("No. of passes is %d\n",i);
        key=A[i];
        j=i-1;
        while(j>=0 && A[j]>key){
             A[j+1]=A[j];
             j--;
        }
        A[j+1]=key;
   }
}

int main(){
  //int A[]={7,2,91,77,3};
  int A[]={2,3,7,77,91};
  int n=5;
  printf("Before sorting:-\n");
  printarray(A,n);
  insertion_sorting(A,n);
  printf("After sorting\n");
  printarray(A,n);
   return 0;
}