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
int partition(int *A,int low,int high){
    int pivot=A[low],i=low+1,j=high,temp;
    do{
    while(A[i]<=pivot){
        i++;
    }
    while(A[j]>pivot){
        j--;
    }
    if(i<j){
        temp=A[i];
        A[i]=A[j];
        A[j]=temp;
    }
    }while(i<j);
    temp=A[low];
    A[low]=A[j];
    A[j]=temp;
    return j;

}
void quick_sort(int *A,int low,int high){
   int partitionindex;  // index of pivot after the partition
   if(low<high){
   partitionindex = partition(A,low,high);  
   quick_sort(A,low,partitionindex-1);     //sorting left subarray
   quick_sort(A,partitionindex+1,high);    //sorting right subarray
   }
}

int main(){
  int A[]={2,4,3,9,1,4,8,7,5,6};
  //int A[]={2,3,7,77,91};
  int n=10;
  printf("Before sorting:-\n");
  printarray(A,n);
  quick_sort(A,0,n-1);
  printf("After sorting\n");
  printarray(A,n);
  return 0;
}