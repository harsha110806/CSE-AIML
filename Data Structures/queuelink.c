#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

// Function prototypes
void enqueue(int data);
void dequeue();
void display();

int main() {
    int choice, value;
    
    while(1) {
        printf("\n--- Queue Menu (Linked List Implementation) ---\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
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
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

void enqueue(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if(front== NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d inserted into queue.\n", data);
}

void dequeue() {
    if(front == NULL) {
        printf("Queue Underflow! Nothing to delete.\n");
    } else {
        struct Node* temp = front;
        printf("Deleted element: %d\n", front->data);
        front = front->next;
        if(front == NULL)
		{
		rear = NULL;
		return;
	    }
        free(temp);
    }
}

void display() {
    if(front == NULL) 
	{
        printf("Queue is empty.\n");
    } 
	else 
	{
        struct Node* temp = front;
        printf("Queue elements: ");
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

