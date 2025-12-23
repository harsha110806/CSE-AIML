#include <stdio.h>
#include <stdlib.h>
#define MAX 5   // maximum size of queue

int queue[MAX];
int front = -1, rear = -1;

// Function prototypes
void enqueue(int data);
void dequeue();
void display();

int main() {
    int choice, value;
    
    while(1) {
        printf("\n--- Queue Menu (Array Implementation) ---\n");
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
    if(rear == MAX - 1) {
        printf("Queue Overflow! Cannot insert %d\n", data);
    } else {
        if(front == -1) {
		front = 0;
	    }
        rear++;
        queue[rear] = data;
        printf("%d inserted into queue.\n", data);
    }
}

void dequeue() {
    if(front == -1 || front > rear) {
        printf("Queue Underflow! Nothing to delete.\n");
    } else {
        printf("Deleted element: %d\n", queue[front]);
        front++;
    }
}

void display() {
    if(front == -1 || front > rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for(int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

