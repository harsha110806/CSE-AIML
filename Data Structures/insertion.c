#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};
struct node *head = NULL;

void create(int n) {
    int i, info;
    struct node *newnode;
    for (i = 1; i <= n; i++) {
        newnode = malloc(sizeof(struct node));
        printf("Enter the info in node %d: ", i);
        scanf("%d", &info);
        newnode->info = info;
        newnode->next = head;
        head = newnode;
    }
}

void display() {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertatbeginning(int data) {
    struct node *newnode = malloc(sizeof(struct node));
    newnode->info = data;
    newnode->next = head;
    head = newnode;
    printf("Inserted at beginning\n");
}

void insertatend(int data) {
    struct node *newnode = malloc(sizeof(struct node));
    struct node *temp = head;
    newnode->info = data;
    newnode->next = NULL;
    if (head == NULL) {
        head = newnode;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    printf("Inserted at end\n");
}

void insertafter(int key) {
    struct node *newnode, *temp = head;
    int data;
    while (temp != NULL && temp->info != key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node with value %d not found.\n", key);
        return;
    }
    newnode = malloc(sizeof(struct node));
    printf("Enter data to insert after %d: ", key);
    scanf("%d", &data);
    newnode->info = data;
    newnode->next = temp->next;
    temp->next = newnode;
    printf("Inserted %d after %d\n", data, key);
}

void insertbefore(int key) {
    struct node *newnode, *temp = head, *prev = NULL;
    int data;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->info == key) {
        printf("Enter data to insert before %d: ", key);
        scanf("%d", &data);
        newnode = malloc(sizeof(struct node));
        newnode->info = data;
        newnode->next = head;
        head = newnode;
        printf("Inserted %d before %d\n", data, key);
        return;
    }
    while (temp != NULL && temp->info != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node with value %d not found.\n", key);
        return;
    }
    printf("Enter data to insert before %d: ", key);
    scanf("%d", &data);
    newnode = malloc(sizeof(struct node));
    newnode->info = data;
    newnode->next = temp;
    prev->next = newnode;
    printf("Inserted %d before %d\n", data, key);
}

void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    printf("Deleted %d from beginning\n", temp->info);
    free(temp);
}

void deleteAtEnd() 
    {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == NULL) {
        printf("Deleted %d from end\n", head->info);
        free(head);
        head = NULL;
        return;
    }

    struct node *temp = head, *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    printf("Deleted %d from end\n", temp->info);
    prev->next = NULL;
    free(temp);
}


int main() {
    int n, data, key;

    printf("No. of nodes: ");
    scanf("%d", &n);
    create(n);
    printf("Linked list:\n");
    display();

    printf("\nElement to be inserted at end: ");
    scanf("%d", &data);
    insertatend(data);
    display();

    printf("\nElement to be inserted at beginning: ");
    scanf("%d", &data);
    insertatbeginning(data);
    display();

    printf("\nEnter the node after which to insert: ");
    scanf("%d", &key);
    insertafter(key);
    display();

    printf("\nEnter the node before which to insert: ");
    scanf("%d", &key);
    insertbefore(key);
    display();

    return 0;
}

