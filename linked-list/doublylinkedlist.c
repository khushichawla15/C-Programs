#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

struct node *head = NULL;

void insert() 
{
    int value;
    struct node *newNode, *temp;

    newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL)
        head = newNode;
    else 
	{
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void delete() 
{
    int value;
    struct node *temp = head;

    printf("Enter value to delete: ");
    scanf("%d", &value);

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) 
	{
        printf("Element not found\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

void display() 
{
    struct node *temp = head;
    printf("List: ");
    while (temp != NULL) 
	{
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() 
{
    int choice;
    while (1) 
	{
        printf("\n1.Insert  2.Delete  3.Display  4.Exit\n");
        scanf("%d", &choice);

        switch (choice) 
		{
            case 1: insert(); 
			break;
            case 2: delete(); 
			break;
            case 3: display(); 
			break;
            case 4: exit(0);
        }
    }
}
