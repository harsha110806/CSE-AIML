#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct node {
    int data;            // Data part
    struct node *link;   // Pointer to the next node
};

int main()
{
    // Create the first node (head)
    struct node *head = malloc(sizeof(struct node)); // allocate memory for node
    head->data = 45;     // set data for first node
    head->link = NULL;   // currently points to nothing

    // Create the second node
    struct node *current = malloc(sizeof(struct node));
    current->data = 98;  // set data for second node
    current->link = NULL; // points to nothing yet
    head->link = current; // link first node to second node

    // Create the third node
    struct node *current2 = malloc(sizeof(struct node));
    current2->data = 3;  // set data for third node
    current2->link = NULL; // third node ends the list
    current->link = current2; // link second node to third node

    // Traverse and print the linked list
    struct node *ptr = head;  // start from head
    while (ptr != NULL) {
        printf("%d\n", ptr->data); // print current node data
        ptr = ptr->link;           // move to next node
    }

    return 0;    
}

