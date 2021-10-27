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
void merging_sort(int *A,int low,int high,int mid){
    int i,j,k;
    int C[high+1];
    i=low;
    k=low;
    j=mid+1;
    while(i<=mid && j<=high){
        if(A[i]<A[j]){
           C[k]=A[i];
           i++;
           k++;
        }
        else{
            C[k]=A[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        C[k]=A[i];           
        i++;
        k++;
    }                  // copying all remaining element in the array
    while(j<=high){
        C[k]=A[j];
        j++;
        k++;
    }
    for(i=low;i<=high;i++){
        A[i]=C[i];
    }
}
void merg_sort(int *A,int low,int high){
    int mid;
    if(low<high){
       mid=(low+high)/2;
       merg_sort(A,low,mid);
       merg_sort(A,mid+1,high);
       merging_sort(A,low,high,mid);
    }
}
int main(){
  int A[]={12,5,7,9,2,1};
  int a=6;
  printf("Before sorting:-\n");
  printf("Array A is\n");
  printarray(A,a);
  printf("Merge Sort in process...\n");
  merg_sort(A,0,a-1);
  printf("After sorting\n");
  printarray(A,a);
  return 0;
}


//hello guys my name is vinay chandola 
