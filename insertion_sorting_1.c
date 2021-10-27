#include <stdio.h>
#include <stdlib.h>
// Sorting algorithm

void printarray(int *A,int n){
    for(int i=0;i<n;i++){
        printf("%d\t",A[i]);
    }
    printf("\n");
}
void insertion_sorting(int *A,int n){
    int temp,a=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j>0;j--){
            if(A[j]<A[j-1]){
                 temp=A[j];
                 A[j]=A[j-1];
                 A[j-1]=temp;
            }
        }
    }
}
int main(){
   
  int A[]={7,2,91,77,3};
  int n=5;
  printf("Before sorting:-\n");
  printarray(A,n);
  insertion_sorting(A,n);
  printf("After sorting\n");
  printarray(A,n);
   return 0;
}