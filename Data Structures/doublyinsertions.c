#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void create(int n) {
    int i, info;
    struct node *temp = head;
    for (i = 1; i <= n; i++) {
        struct node *newnode = malloc(sizeof(struct node));
        printf("Enter the info in node %d: ", i);
        scanf("%d", &info); 
        newnode->info = info;
        newnode->next = NULL;
        newnode->prev = NULL;
        if (head == NULL) {
            head = newnode;
            temp = head;
        } else {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }
}

void display() {
    struct node *temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertatbeginning(int data) {
    struct node *newnode = malloc(sizeof(struct node));
    newnode->info = data;
    newnode->next = head;
    newnode->prev = NULL;
    if (head != NULL) {
        head->prev = newnode;
    }
    head = newnode;
    printf("%d is inserted at the beginning.\n", data);
}

void insertatend(int data) {
    struct node *newnode = malloc(sizeof(struct node));
    newnode->info = data;
    newnode->next = NULL;
    if (head == NULL) {
        newnode->prev = NULL;
        head = newnode;
        printf("%d inserted at end (first node).\n", data);
        return;
    }
    struct node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
    printf("%d inserted at end.\n", data);
}

void insertbefore(int data, int key) {
    struct node *temp = head;
    struct node *newnode = malloc(sizeof(struct node));
    newnode->info = data;
    newnode->next = NULL;
    newnode->prev = NULL;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->info == key) {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
        printf("%d inserted before head.\n", data);
        return;
    }
    while (temp != NULL) {
        if (temp->info == key) {
            newnode->next = temp;
            newnode->prev = temp->prev;
            temp->prev->next = newnode;
            temp->prev = newnode;
            printf("%d is inserted before %d.\n", data, key);
            return;
        }
        temp = temp->next;
    }
    printf("Key %d not found.\n", key);
}

void insertafter(int data, int key) {
    struct node *temp = head;
    struct node *newnode = malloc(sizeof(struct node));
    newnode->info = data;
    newnode->prev = NULL;
    newnode->next = NULL;

    if (head == NULL) {
        printf("List is empty.\n");
        free(newnode);
        return;
    }

    while (temp != NULL) {
        if (temp->info == key) {
            newnode->next = temp->next;
            newnode->prev = temp;
            if (temp->next != NULL) {
                temp->next->prev = newnode;
            }
            temp->next = newnode; 
            printf("%d is inserted after %d.\n", data, key);
            return;
        }
        temp = temp->next;
    }
    printf("%d is not found in the list.\n", key);
    free(newnode);
}

void deleteatbeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    printf("Deleted node: %d\n", temp->info);
    free(temp);
}

void deleteatend() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->next == NULL) {
        printf("Deleted last node: %d\n", head->info);
        free(head);
        head = NULL;
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("Deleted last node: %d\n", temp->info);
    temp->prev->next = NULL;
    free(temp);
}

void deleteBefore(int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->info == key) {
        printf("No node exists before the node with key %d.\n", key);
        return;
    }

    struct node *temp = head;

    // Traverse to find the node with given key
    while (temp != NULL && temp->info != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Key %d not found in the list.\n", key);
        return;
    }

    struct node *del = temp->prev;

    if (del == head) {
        head = temp;
        head->prev = NULL;
        printf("Deleted head node (%d).\n", del->info);
        free(del);
    } else {
        del->prev->next = temp;
        temp->prev = del->prev;
        printf("Deleted node (%d) before node with key %d.\n", del->info, key);
        free(del);
    }
}


void deleteafter(int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = head;

    // Find the key
    while (temp != NULL && temp->info != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Key %d not found in the list.\n", key);
        return;
    }

    if (temp->next == NULL) {
        printf("No node exists after %d to delete.\n", key);
        return;
    }

    struct node *del = temp->next;
    int val = del->info;

    // Reconnect links
    temp->next = del->next;
    if (del->next != NULL) {
        del->next->prev = temp;
    }

    free(del);
    printf("Node after %d (value: %d) deleted.\n", key, val);
}


int main() {
    int choice, n, data, key;

    while (1) {
        printf("1. Create List\n");
        printf("2. Display List\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Insert Before a Node\n");
        printf("6. Insert After a Node\n");
        printf("7. Delete at Beginning\n");
        printf("8. Delete at End\n");
        printf("9. Delete Before a Node\n");
        printf("10. Delete After a Node\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting program.\n");
            break;
        }

        switch(choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                create(n);
                break;

            case 2:
                display();
                break;

            case 3:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertatbeginning(data);
                break;

            case 4:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertatend(data);
                break;

            case 5:
                printf("Enter the key to insert before: ");
                scanf("%d", &key);
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertbefore(data, key);
                break;

            case 6:
                printf("Enter the key to insert after: ");
                scanf("%d", &key);
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertafter(data, key);
                break;

            case 7:
                deleteatbeginning();
                break;

            case 8:
                deleteatend();
                break;

            case 9:
                printf("Enter the key before which to delete: ");
                scanf("%d", &key);
                deletebefore(key);
                break;

            case 10:
                printf("Enter the key after which to delete: ");
                scanf("%d", &key);
                deleteafter(key);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
