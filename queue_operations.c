#include<stdio.h>
#include<stdlib.h>
# define MAX 10
int QUEUE[MAX];
int rear=-1;
int front=-1;
void queue_insert(int);
void queue_delete();
void queue_display();
void main()
{
    int ch, item;
    while(1)
    {
        printf("\n1.INSERT\n");
        printf("2.DELETE from front\n");
        printf("3.DIPLAY\n");
        printf("4.EXIT\n");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter an element to insert: ");
            scanf("%d",&item);
            queue_insert(item);
            break;
            case 2: queue_delete();
            break;
            case 3: queue_display();
            break;
            case 4:
            exit(0);
            break;
            default:
            printf("\n ENTER CORRECT CHOICE!!!\n");
        }
    }
}
void queue_insert(int item)
{
    if(rear==MAX-1)
    {
        printf("QUEUE FULL");
        return;
    }
    if(front==-1 && rear==-1)
    front=rear=0;
    else
    rear=rear+1;
    QUEUE[rear]=item;
}
void queue_delete()
{
    int e;
    if(front==-1)
    {
        printf("QUEUE IS EMPTY");
        return;
    }
    e=QUEUE[front];
    if(front==rear)
    front=rear=-1;
    else
    front=front+1;
    printf("The deleted element=%d", e);
}
void queue_display()
{
    int i=front;
    while(i<=rear)
    {
        printf("%d\t",QUEUE[i]);
        i=i+1;
    }
}
