#include <stdio.h>
#define MAX 5

int stack[MAX], top = -1;

void push() 
{
    int item;
    if (top == MAX - 1) 
	{
        printf("Stack Overflow\n");
        return;
    }
    printf("Enter item: ");
    scanf("%d", &item);
    stack[++top] = item;
}

void pop() 
{
    if (top == -1) 
	{
        printf("Stack Underflow\n");
        return;
    }
    printf("Popped element: %d\n", stack[top--]);
}

void display()
{
    int i;
    if (top == -1) 
	{
        printf("Stack is empty\n");
        return;
    }
    for (i = top; i >= 0; i--)
        printf("%d ", stack[i]);
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
