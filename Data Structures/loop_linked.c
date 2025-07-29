#include <stdio.h>
#include <stdlib.h>
// Define a structure for each node in the linked list
struct node {
    int data;             // The data part of the node
    struct node *link;    // Pointer to the next node
};
int main() {
    // Declare pointers to manage the list
    struct node *head = NULL, *temp = NULL, *ptr = NULL;
    int n, i, data;
    // Ask the user how many nodes to create
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    // If the user enters 0 or less, there's nothing to do
    if (n <= 0) {
        printf("The linked list must have at least one node.\n");
        return 0;
    }
    // Create and initialize the first node
    head = malloc(sizeof(struct node)); // Allocate memory for the first node
    if (head == NULL) {
        printf("Memory allocation failed\n");
        return 1; // Exit the program if memory allocation fails
    }
    // Input data for the first node
    printf("Enter data for node 1: ");
    scanf("%d", &data);
    head->data = data;    // Assign input to the node's data
    head->link = NULL;    // Initially no next node
    temp = head;          // temp will always point to the last node
    // Loop to create and link the remaining n-1 nodes
    for (i = 2; i <= n; i++) {
        ptr = malloc(sizeof(struct node)); // Allocate memory for the next node
        if (ptr == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        // Input data for this node
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        ptr->data = data;
        ptr->link = NULL;   // New node initially doesn't point to any next node

        temp->link = ptr;   // Link the last node to the new node
        temp = ptr;         // Move temp to the last node
    }
    // Print the linked list
    printf("Linked list contents:\n");
    ptr = head;            // Start from the head
    while (ptr != NULL) {  // Traverse till the end
        printf("%d -> ", ptr->data); // Print data of current node
        ptr = ptr->link;   // Move to next node
    }
    printf("NULL\n");      // End of linked list
    return 0;
}
