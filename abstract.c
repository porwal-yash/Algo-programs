//Dynamic memory allocation of the array 
#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Class{       //defining  structure 
    int total_size;
    int used_size;
    int *ptr;
};

void createarray(struct Class *a,int tsize,int usize){
    a->total_size = tsize;
    a->used_size = usize;
    a->ptr =(int *)malloc(tsize * sizeof(int));
}

void setvalue(struct Class *a){     //inserting values of the arrays
      int n;
      for(int i=0;i<a->used_size;i++){
        printf("Enter the element %d:- ",i);
        scanf("%d",&n);
        (a->ptr)[i]=n;
      }
}

void showvalue(struct Class *a){      //showing values of the arrays
    printf("Elements of the arrays are:-\n");
    for(int i=0;i<a->used_size;i++){
        printf("%d\n",(a->ptr)[i]);
    }
}
void main(){        //main function
    int n1;
    struct Class marks;
    printf("Enter the no. of elements of the array:- ");
    scanf("%d",&n1);
    createarray(&marks,10,n1);
    setvalue(&marks);
    showvalue(&marks);
}