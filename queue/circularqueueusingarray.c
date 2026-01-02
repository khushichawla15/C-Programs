#include<stdio.h>
#include<stdlib.h>
#define size 3
int rear=-1;
int front=-1;
int q[size];
int item;
void enqueue()
{
	if(front==0&&rear==size-1||front==rear+1)
	{
		printf("overflow \n");
		return;
	}
	printf("enter elements");
	scanf("%d",&item);
	if(front==-1)
	{
		front=0;
		rear=0;
	}
	else
	{
		rear=(rear+1)%size;
	}
	q[rear]=item;
	printf("Enqueued item %d",item);
}

void dequeue()
{
	if(front==-1)
	{
		printf("underflow \n");
		return;
	}
	item=q[front];
	if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else
	{
		front=(front+1)%size;
	}
	printf("Dequeued item %d",item);
}

void display()
{
	int i;
	if(front==-1)
	{
		printf("underflow");
		return;
	}
	else
	{
		if(front<=rear)
		{
			for(i=front;i<=rear;i++)
		{
			printf("%d",q[i]);
		}
		}	
		else
	{
		for(i=front;i<size;i++)
			printf("%d",q[i]);
		for(int i=0;i<rear;i++)
			printf("%d",q[i]);		
	}
}
}
void main()
{
	int ch ;
	do
	{
		printf("\n1.enqueue \n");
		printf("2.dequeue\n");
		printf("3.display\n");
		printf("4.exit \n ");
		printf("Enter your choice");
		scanf("%d",&ch);
		switch(ch)
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
			break;
			default:
				printf("enter valid choice");
		}
	}
	while(ch!=0);
}