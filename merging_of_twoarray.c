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
void merge_sort(int *A,int *B,int *C,int n,int m){
    int i,j,k;
    i=j=k=0;
    while(i<n && j<m){
        if(A[i]<B[j]){
           C[k]=A[i];
           i++;
           k++;
        }
        else{
            C[k]=B[j];
            j++;
            k++;
        }
    }
    while(i<n){           
        C[k]=A[i];           
        i++;
        k++;
    }                  // copying all remaining element in the array
    while(j<m){
        C[k]=B[j];
        j++;
        k++;
    }
}
int main(){
  int A[]={2,30,40,90,91};
  int B[]={1,2,3,4,100};
  int a=5;
  int b=5;
  int C[10];
  printf("Before sorting:-\n");
  printf("Array A is\n");
  printarray(A,a);
  printf("Array B is\n");
  printarray(B,b);
  printf("Merge Sort in process...\n");
  merge_sort(A,B,C,a,b);
  printf("After sorting\n");
  printarray(C,10);
  return 0;
}