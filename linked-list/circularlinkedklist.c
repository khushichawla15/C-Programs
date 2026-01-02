#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
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

    if (head == NULL) 
	{
        head = newNode;
        newNode->next = head;
    } else 
	{
        temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
}

void delete() 
{
    int value;
    struct node *temp = head, *prev = NULL;

    printf("Enter value to delete: ");
    scanf("%d", &value);

    if (head == NULL)
        return;

    do 
	{
        if (temp->data == value) 
		{
            if (prev != NULL)
                prev->next = temp->next;
            else {
                struct node *last = head;
                while (last->next != head)
                    last = last->next;
                head = temp->next;
                last->next = head;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != head);

    printf("Element not found\n");
}

void display() 
{
    struct node *temp = head;
    if (head == NULL)
        return;

    printf("List: ");
    do
	{
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
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
