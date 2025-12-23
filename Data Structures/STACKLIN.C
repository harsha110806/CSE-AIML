#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>   // Turbo C supports this for exit()

struct node {
    int info;
    struct node *next;
};

struct node *top = NULL;

int isempty() {
    return (top == NULL);
}

int isfull() {
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    if (temp == NULL) {
        return 1;   // memory not available
    }
    free(temp);
    return 0;
}

void push(int val) {
    if (isfull()) {
        printf("Stack overflow.\n");
        return;
    }
    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    newnode->info = val;
    newnode->next = top;
    top = newnode;
    printf("%d pushed into the stack.\n", val);
}

void pop() {
    if (isempty()) {
        printf("Stack underflow.\n");
        return;
    }
    struct node *temp = top;
    printf("%d popped from the stack.\n", top->info);
    top = top->next;
    free(temp);
}

void display() {
    if (isempty()) {
        printf("Stack is empty.\n");
        return;
    }
    struct node *temp = top;
    printf("Stack elements (top to bottom):\n");
    while (temp != NULL) {
        printf("%d\n", temp->info);
        temp = temp->next;
    }
}

void main() {
    int choice, val;

    clrscr();   // clear Turbo C screen at start

    while (1) {
        printf("\n--- STACK MENU (Linked List) ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Check if Empty\n");
        printf("4. Check if Full\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &val);
                push(val);
                break;

            case 2:
                pop();
                break;

            case 3:
                if (isempty())
                    printf("Stack is empty.\n");
                else
                    printf("Stack is not empty.\n");
                break;

            case 4:
                if (isfull())
                    printf("Stack is full.\n");
                else
                    printf("Stack is not full.\n");
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exiting program...\n");
                getch();   // wait for key press before leaving Turbo C output screen
                exit(0);

            default:
                printf("Invalid choice! Please enter a number between 1 and 6.\n");
        }
    }
}

