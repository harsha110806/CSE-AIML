#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

struct node *head = NULL;

void create(int n) {
    int i, info;
    struct node *temp = NULL;

    for (i = 1; i <= n; i++) {
        struct node *newnode = malloc(sizeof(struct node));
        printf("Enter the info in node %d: ", i);
        scanf("%d", &info);

        newnode->info = info;

        if (head == NULL) {
            head = temp=newnode;
            newnode->next = head;
        } else {
            temp->next = newnode;
            newnode->next = head;
            temp = newnode;
        }
    }
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = head;
    do {
        printf("%d -> ", temp->info);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

void search(int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    int pos = 1;
    struct node *temp = head;

    do {
        if (temp->info == key) {
            printf("%d found at position %d\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    printf("%d not found in the list.\n", key);
}

void insertatbeginning(int data) {
    struct node *newnode = malloc(sizeof(struct node));
    newnode->info = data;

    if (head == NULL) {
        head = newnode;
        head->next = head;
        return;
    }

    struct node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    newnode->next = head;
    temp->next = newnode;
    head = newnode;

    printf("%d inserted at beginning\n", data);
}

void insertatend(int data) {
    struct node *newnode = malloc(sizeof(struct node));
    newnode->info = data;

    if (head == NULL) {
        head = newnode;
        head->next = head;
        return;
    }

    struct node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->next = head;

    printf("%d inserted at end\n", data);
}

void insertafter(int key, int data) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = head;
    do {
        if (temp->info == key) {
            struct node *newnode = malloc(sizeof(struct node));
            newnode->info = data;
            newnode->next = temp->next;
            temp->next = newnode;

            printf("%d inserted after %d\n", data, key);
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Key %d not found.\n", key);
}

void insertbefore(int key, int data) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *newnode = malloc(sizeof(struct node));
    newnode->info = data;
    // If inserting before head
    if (head->info == key) {
        struct node *temp = head;
        while (temp->next != head) {   // find last node
            temp = temp->next;
        }
        newnode->next = head;
        temp->next = newnode;
        head = newnode;  // new node becomes the new head
        printf("%d inserted before %d (at beginning)\n", data, key);
        return;
    }


    struct node *temp = head, *prev = NULL;

    do {
        prev = temp;
        temp = temp->next;

        if (temp->info == key) {
            
            prev->next = newnode;
            newnode->next = temp;

            printf("%d inserted before %d\n", data, key);
            return;
        }
    } while (temp != head);

    printf("Key %d not found.\n", key);
}

void deleteatbeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == head) {
        printf("Deleted %d (only node)\n", head->info);
        free(head);
        head = NULL;
        return;
    }

    struct node *last = head;
    while (last->next != head) {
        last = last->next;
    }

    struct node *temp = head;
    head = head->next;
    last->next = head;

    printf("Deleted %d from beginning\n", temp->info);
    free(temp);
}

void deleteatend() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == head) {
        printf("Deleted %d (only node)\n", head->info);
        free(head);
        head = NULL;
        return;
    }

    struct node *temp = head, *prev = NULL;

    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    printf("Deleted %d from end\n", temp->info);
    free(temp);
}

void deleteafter(int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = head;

    do {
        if (temp->info == key) {
            struct node *del = temp->next;

            if (del == head) {
                printf("No node exists after %d.\n", key);
                return;
            }

            temp->next = del->next;
            printf("Deleted %d after %d\n", del->info, key);
            free(del);
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Key %d not found.\n", key);
}
void deletebefore(int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == head) {
        printf("Only one node, nothing to delete.\n");
        return;
    }

    if (head->info == key) {
        struct node *last = head;
        while (last->next->next != head) {
            last = last->next;
        }

        printf("Deleted %d (before head)\n", last->next->info);
        free(last->next);
        last->next = head;
        return;
    }

    struct node *temp = head, *prev = NULL, *beforeprev = NULL;

    do {
        beforeprev = prev;
        prev = temp;
        temp = temp->next;
    } while (temp != head && temp->info != key);

    if (temp == head) {
        printf("Key %d not found.\n", key);
        return;
    }

    beforeprev->next = temp;
    printf("Deleted %d before %d\n", prev->info, key);
    free(prev);
}

int main() {
    int choice, n, data, key;

    while (1) {
        printf("\n--- Circular Linked List Menu ---\n\n");
        printf("1. Create List\n");
        printf("2. Display List\n");
        printf("3. Search\n");
        printf("4. Insert at Beginning\n");
        printf("5. Insert at End\n");
        printf("6. Insert Before a Node\n");
        printf("7. Insert After a Node\n");
        printf("8. Delete at Beginning\n");
        printf("9. Delete at End\n");
        printf("10. Delete Before a Node\n");
        printf("11. Delete After a Node\n");
        printf("0. Exit\n\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting program.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                create(n);
                break;

            case 2:
                display();
                break;

            case 3:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(key);
                break;

            case 4:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertatbeginning(data);
                break;

            case 5:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertatend(data);
                break;

            case 6:
                printf("Enter the key to insert before: ");
                scanf("%d", &key);
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertbefore(key, data);
                break;

            case 7:
                printf("Enter the key to insert after: ");
                scanf("%d", &key);
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertafter(key, data);
                break;

            case 8:
                deleteatbeginning();
                break;

            case 9:
                deleteatend();
                break;

            case 10:
                printf("Enter the key before which to delete: ");
                scanf("%d", &key);
                deletebefore(key);
                break;

            case 11:
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


