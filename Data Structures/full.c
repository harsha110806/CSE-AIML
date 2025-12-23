#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

struct node *head = NULL;

void create(int n) {
    struct node *newnode, *temp;
    int data, i;
    for (i = 1; i <= n; i++) {
        newnode = malloc(sizeof(struct node));
        printf("Enter the info in node %d: ", i);
        scanf("%d", &data);
        newnode->info = data;
        newnode->next = NULL;
        if (head == NULL) {
            temp = head = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
}

void display() {
    struct node *temp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

void addatbeginning(int data) {
    struct node *newnode = malloc(sizeof(struct node));
    newnode->info = data;
    newnode->next = head;
    head = newnode;
    printf("Inserted %d at beginning\n", data);
}

void addatend(int data) {
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
    printf("Inserted %d at end\n", data);
}

void addafter(int key, int data) {
    struct node *newnode = malloc(sizeof(struct node));
    struct node *temp = head;
    newnode->info = data;
    while (temp != NULL) {
        if (temp->info == key) {
            newnode->next = temp->next;
            temp->next = newnode;
            printf("Inserted %d after %d\n", data, key);
            return;
        }
        temp = temp->next;
    }
    printf("Key %d not found\n", key);
    free(newnode);
}

void addbefore(int key, int data) {
    struct node *temp = head, *prev = NULL;
    struct node *newnode = malloc(sizeof(struct node));
    newnode->info = data;

    if (head != NULL && head->info == key) {
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
        printf("Key %d not found\n", key);
        free(newnode);
        return;
    }

    newnode->next = temp;
    prev->next = newnode;
    printf("Inserted %d before %d\n", data, key);
}

void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    printf("Deleted %d from beginning\n", temp->info);
    free(temp);
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty\n");
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

void deleteafter(int key) {
    struct node *temp = head;
    while (temp != NULL && temp->info != key) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("No node found to delete after %d\n", key);
        return;
    }
    struct node *del = temp->next;
    temp->next = del->next;
    printf("Deleted %d after %d\n", del->info, key);
    free(del);
}

void deletebefore(int key) {
    if (head == NULL || head->info == key) {
        printf("No node to delete before %d\n", key);
        return;
    }
    struct node *temp = head, *prev = NULL, *beforeprev = NULL;
    while (temp != NULL && temp->info != key) {
        beforeprev = prev;
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Key %d not found\n", key);
        return;
    }
    if (beforeprev == NULL) {
        head = temp;
        printf("Deleted %d before %d\n", prev->info, key);
        free(prev);
    } else {
        beforeprev->next = temp;
        printf("Deleted %d before %d\n", prev->info, key);
        free(prev);
    }
}

int main() {
    int choice, n, data, key;
    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Create List\n");
        printf("2. Display\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Insert After\n");
        printf("6. Insert Before\n");
        printf("7. Delete at Beginning\n");
        printf("8. Delete at End\n");
        printf("9. Delete After\n");
        printf("10. Delete Before\n");
        printf("11. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

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
            printf("Enter data: ");
            scanf("%d", &data);
            addatbeginning(data);
            break;
        case 4:
            printf("Enter data: ");
            scanf("%d", &data);
            addatend(data);
            break;
        case 5:
            printf("Enter key after which to insert: ");
            scanf("%d", &key);
            printf("Enter data: ");
            scanf("%d", &data);
            addafter(key, data);
            break;
        case 6:
            printf("Enter key before which to insert: ");
            scanf("%d", &key);
            printf("Enter data: ");
            scanf("%d", &data);
            addbefore(key, data);
            break;
        case 7:
            deleteAtBeginning();
            break;
        case 8:
            deleteAtEnd();
            break;
        case 9:
            printf("Enter key after which to delete: ");
            scanf("%d", &key);
            deleteafter(key);
            break;
        case 10:
            printf("Enter key before which to delete: ");
            scanf("%d", &key);
            deletebefore(key);
            break;
        case 11:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}

