#include <stdio.h>
 #include <stdlib.h>
 struct node {
    int data;
    struct node *link;
 };
 int main() {
    struct node *head = NULL, *temp = NULL, *newnode = NULL;
    int n, data;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) 
	{
        newnode = (struct node *)malloc(sizeof(struct node));
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
    }
    return 0;
 } //-static-libgcc
