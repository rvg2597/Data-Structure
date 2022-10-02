#include <stdio.h>
#include<stdlib.h>
void insert();
void delete();
void display();

int front,rear,a[5];
int main()
{
    int choice;
    front=-1;
    rear=-1;
    while(1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter Your Choice :");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                insert();
            break;
            case 2:
                delete();
            break;
            case 3:
                display();
            break;
            case 4:
                printf("Thank You");
                exit(0);
            break;
            default:
                printf("Enter Correct choice");
        }
        
    }
    return 0;
}
void insert()
{
    int n;
    printf("Enter The Number To Be Inserted :");
    scanf("%d",&n);
    if(rear==5 && front>0)
    {
        rear=0;
    }
    printf("rear=%d front=%d\n",rear,front);
    if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
        a[rear]=n;
        rear=rear+1;
    }
    else if(rear==5 && front==0)
    {
        printf("Circular Queue is full");
    }
    else if(rear==front+1 && front>rear)
    {
        printf("Circular Queue is full");
    }
    else
    {
        a[rear]=n;
        rear=rear+1;
    }
}
void display()
{
	int i;
	for(i=front;i<rear;i++)
	{
	    printf("%d ",a[i]);
	}
	if(front>rear)
	{
	   for(i=front;i<5;i++)
	    {
	        printf("%d ",a[i]);
	    } 
	}
	else
	{
	    for(i=rear;i<front;i++)
	    {
	        printf("%d ",a[i]);
	    } 
	}
}
void delete()
{
    if(front==-1)
    {
      printf("Linked List Is Empty");  
    }
    else
    {
        printf("Deleted Element in Circular Queue Is :%d",a[front]);
        front=front+1;
    }
}