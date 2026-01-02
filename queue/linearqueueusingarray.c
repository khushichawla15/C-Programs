#include<stdio.h>
#include<stdlib.h>
#define max 3
int q[max];
int front=-1, rear=-1;

void enqueue()
{
	int item;
	if(rear==max-1)
	{
		printf("overflow");
	}
	printf("enter elemnents");
	scanf("%d",&item);
	if(front==-1)
	{
		front=0;
		rear=0;
	}
	else
	{
		rear++;
	}
	q[rear]=item;
	printf("enqueued item %d",item);
}

void dequeue()
{
	if((front=-1)||(front>rear))
	{
		printf("underflow");
	}
	int item =q[front];
	if(front==rear)
	{
		front=0;
		rear=0;
	}
	else
	{
		front++;
	}
	printf("dequeued item",item);
}
void display()
{
	int item;
	if((rear= max-1)||(front>rear))
	{
		printf("underflow");
	}
	for(int i =front ;i<rear;i++)
	{
		printf("elements %d",item);
	}
}
void main()
{
	int choice;
	do 
	{
		printf("1 . enqueue \n");
		printf("2 . dequeue \n");
		printf("3 . display \n");
		printf("4 . exit \n");
		printf("enter your choice");
		scanf("%d",&choice);
	
		switch(choice)
		{
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
			exit(0);
			default:
				printf("enter valid choice");
				break;
		}
	}
	while(choice!=0);
}