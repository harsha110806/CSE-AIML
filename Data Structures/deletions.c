#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Insert at end
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// Display list
void displayList(struct Node* head) {
    printf("List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Delete from beginning
struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    struct Node* temp = head;
    head = head->next;
    if (head != NULL) head->prev = NULL;
    printf("Deleted %d from beginning.\n", temp->data);
    free(temp);
    return head;
}

// Delete from end
struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    struct Node* temp = head;
    if (temp->next == NULL) {
        printf("Deleted %d from end.\n", temp->data);
        free(temp);
        return NULL;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    printf("Deleted %d from end.\n", temp->data);
    free(temp);
    return head;
}

// Delete after a given key
struct Node* deleteAfterKey(struct Node* head, int key) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("No node found after key %d.\n", key);
        return head;
    }

    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    if (toDelete->next != NULL)
        toDelete->next->prev = temp;

    printf("Deleted %d after key %d.\n", toDelete->data, key);
    free(toDelete);
    return head;
}

// Delete before a given key
struct Node* deleteBeforeKey(struct Node* head, int key) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL || temp->prev == NULL) {
        printf("No node found before key %d.\n", key);
        return head;
    }

    struct Node* toDelete = temp->prev;
    if (toDelete->prev != NULL) {
        toDelete->prev->next = temp;
        temp->prev = toDelete->prev;
    } else {
        head = temp;
        head->prev = NULL;
    }

    printf("Deleted %d before key %d.\n", toDelete->data, key);
    free(toDelete);
    return head;
}

// Main function: Direct function calls (no input, no menu)
int main() {
    struct Node* head = NULL;

    // Inserting data
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);
    head = insertAtEnd(head, 50);

    printf("Initial list:\n");
    displayList(head);

    // Delete from beginning
    head = deleteFromBeginning(head);
    displayList(head);

    // Delete from end
    head = deleteFromEnd(head);
    displayList(head);

    // Delete after key 20 (removes 30)
    head = deleteAfterKey(head, 20);
    displayList(head);

    // Delete before key 40 (should now delete 20)
    head = deleteBeforeKey(head, 40);
    displayList(head);

    return 0;
}
