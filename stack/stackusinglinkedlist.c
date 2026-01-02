#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

void push() 
{
    int item;
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));

    printf("Enter item: ");
    scanf("%d", &item);

    newNode->data = item;
    newNode->next = top;
    top = newNode;
}

void pop() 
{
    struct node *temp;
    if (top == NULL) 
	{
        printf("Stack Underflow\n");
        return;
    }
    temp = top;
    printf("Popped element: %d\n", temp->data);
    top = top->next;
    free(temp);
}

void display() 
{
    struct node *temp = top;
    if (top == NULL) 
	{
        printf("Stack is empty\n");
        return;
    }
    while (temp != NULL) 
	{
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() 
{
    int choice;
    while (1) 
	{
        printf("\n1.Push  2.Pop  3.Display  4.Exit\n");
        scanf("%d", &choice);

        switch (choice) 
		{
            case 1: push(); 
			break;
            case 2: pop(); 
			break;
            case 3: display(); 
			break;
            case 4: 
			return 0;
			default:
				printf("ENTER VALID CHOICE");
			break;
        }
    }
}
