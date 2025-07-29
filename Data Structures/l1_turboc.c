 #include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

int main() {
    struct node *head = NULL, *temp = NULL, *newnode = NULL;
    int n, i, data;

    clrscr();  // Clear the screen (Turbo C specific)

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    i = 0;
    while (i < n) {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);

        newnode->data = data;
        newnode->link = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->link = newnode;
            temp = newnode;
        }

        i++;
    }

    // Displaying the linked list
    printf("\nLinked list contents:\n");
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");

    getch();  // Wait for key press before exiting (Turbo C specific)
    return 0;
}
