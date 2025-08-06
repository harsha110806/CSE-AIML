#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

struct node *head = NULL;

//Create List 
void create(int n) {
    struct node *temp = NULL;
    int info, i;

    for (i = 1; i <= n; i++) {
        struct node *newnode = malloc(sizeof(struct node));
        printf("Enter the data in node %d: ", i);
        scanf("%d", &info);
        newnode->info = info;
        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
}

//Display
void display() {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Delete at Beginning
void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    printf("Deleted %d from beginning\n", temp->info);
    free(temp);
    display();
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
    display();
}

// Delete After
void deleteafter(int key) {
    struct node *temp = head;
    while (temp != NULL && temp->info != key) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("No node found to delete\n");
        return;
    }
    struct node *del = temp->next;
    temp->next = del->next;
    free(del);
    printf("Node after %d deleted successfully\n", key);
}

// Delete Before
void deletebefore(int key) {
    struct node *temp = head, *prev = NULL, *beforeprev = NULL;

    if (head == NULL || head->info == key) {
        printf("No node to delete before %d\n", key);
        return;
    }

    while (temp != NULL && temp->info != key) {
        beforeprev = prev;
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with value %d not found\n", key);
        return;
    }

    if (beforeprev == NULL) {
        head = temp;
        free(prev);
    } else {
        beforeprev->next = temp;
        free(prev);
    }

    printf("Node before %d deleted successfully\n", key);
}

// Reverse List 
void reverse() {
    struct node *prev = NULL, *current = head, *forward = NULL;
    while (current != NULL) {
        forward = current->next;
        current->next = prev;
        prev = current;
        current = forward;
    }
    head = prev;
    printf("Reversed list:\n");
    display();
}

// Find nth Node from End 
void findfromback(int n) {
    struct node *refp = head, *mainp = head;
    int count = 0;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (count < n) {
        if (refp == NULL) {
            printf("n is greater than the list size\n");
            return;
        }
        refp = refp->next;
        count++;
    }

    while (refp != NULL) {
        refp = refp->next;
        mainp = mainp->next;
    }

    printf("The %d node from the end is: %d\n", n, mainp->info);
}

//Find Middle
void middle() {
    struct node *fast = head, *slow = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    printf("Middle node is: %d\n", slow->info);
}

// Check Palindrome 
struct node* reverseCopy(struct node *start) {
    struct node *prev = NULL, *current = start, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void isPalindrome() {
    if (head == NULL || head->next == NULL) {
        printf("List is a palindrome\n");
        return;
    }

    struct node *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct node *second_half = reverseCopy(slow->next);
    struct node *first_half = head;

    struct node *temp2 = second_half;
    int palindrome = 1;
    while (temp2 != NULL) {
        if (first_half->info != temp2->info) {
            palindrome = 0;
            break;
        }
        first_half = first_half->next;
        temp2 = temp2->next;
    }

    if (palindrome)
        printf("The linked list is a palindrome.\n");
    else
        printf("The linked list is NOT a palindrome.\n");

    
    slow->next = reverseCopy(second_half);
}

// Main
int main() {
    int n, key;

    printf("Enter number of nodes to create: ");
    scanf("%d", &n);
    create(n);

    printf("\nLinked list created:\n");
    display();

    printf("\nFinding middle node:\n");
    middle();

    printf("\nFinding 2nd node from end:\n");
    findfromback(2);

    printf("\nReversing the list:\n");
    reverse();

    printf("\nChecking if list is palindrome:\n");
    isPalindrome();

    printf("\nDeleting node at beginning:\n");
    deleteAtBeginning();
    display();

    printf("\nDeleting node at end:\n");
    deleteAtEnd();

    printf("\nEnter the key to delete the node *before* it: ");
    scanf("%d", &key);
    deletebefore(key);
    display();

    printf("\nEnter the key to delete the node *after* it: ");
    scanf("%d", &key);
    deleteafter(key);
    display();

    return 0;
}

