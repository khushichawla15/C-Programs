#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

void enqueue() {
    int item;
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));

    printf("Enter item: ");
    scanf("%d", &item);

    newNode->data = item;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    struct node *temp;
    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }
    temp = front;
    printf("Deleted element: %d\n", temp->data);
    front = front->next;
    free(temp);

    if (front == NULL)
        rear = NULL;
}

void display() {
    struct node *temp = front;
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1.Enqueue  2.Dequeue  3.Display  4.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueue(); 
			break;
            case 2: dequeue(); 
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
