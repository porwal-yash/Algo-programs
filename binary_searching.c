#include <stdio.h>
#include <conio.h>


void searching(int array[20],int n,int pos){
    for(int i=0;i<n;i++){
        if(array[i]==pos){
            printf("element at index:- %d",i);
        }
    }
}

int  binary_searching(int array[20],int element,int low,int high){
      while(low<=high){
      int mid=(low+high)/2;
      if(array[mid]==element){
          return mid;
      }
      else if(array[mid]<element){
          low=mid+1;
      }
      else {
          high=mid-1;
      }
    }
     return -1;
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
   int element,a;
   printf("Enter the search element:- ");
   scanf("%d",&element);
   
    a=binary_searching(array,element,0,n-1);
    printf("index value is %d",a);
}