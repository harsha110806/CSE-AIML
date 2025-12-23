#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    float coef;
    int expo;
    struct Node* next;
};

// Function to create polynomial
struct Node* createPoly(int n) {
    struct Node *head = NULL, *temp = NULL;

    for (int i = 1; i <= n; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("\nEnter coefficient of term %d: ", i);
        scanf("%f", &newNode->coef);
        printf("Enter exponent of term %d: ", i);
        scanf("%d", &newNode->expo);

        newNode->next = NULL;

        if (head == NULL) {         // first term
            head = temp = newNode;
        } else {                    // attach at end
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// Function to display polynomial
void displayPoly(struct Node* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }

    while (poly != NULL) {
        printf("%.1fx^%d", poly->coef, poly->expo);
        poly = poly->next;
        if (poly != NULL) printf(" + ");
    }
    printf("\n");
}

// Function to add two polynomials
struct Node* addPoly(struct Node* p1, struct Node* p2) {
    struct Node *res = NULL, *temp = NULL;

    while (p1 != NULL && p2 != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->next = NULL;

        if (p1->expo == p2->expo) { // same exponent
            newNode->coef = p1->coef + p2->coef;
            newNode->expo = p1->expo;
            p1 = p1->next;
            p2 = p2->next;
        } 
        else if (p1->expo > p2->expo) { // p1 term bigger
            newNode->coef = p1->coef;
            newNode->expo = p1->expo;
            p1 = p1->next;
        } 
        else { // p2 term bigger
            newNode->coef = p2->coef;
            newNode->expo = p2->expo;
            p2 = p2->next;
        }

        if (res == NULL) {  // first result node
            res = temp = newNode;
        } else {            // attach at end
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Remaining terms of p1
    while (p1 != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->coef = p1->coef;
        newNode->expo = p1->expo;
        newNode->next = NULL;

        temp->next = newNode;
        temp = newNode;
        p1 = p1->next;
    }

    // Remaining terms of p2
    while (p2 != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->coef = p2->coef;
        newNode->expo = p2->expo;
        newNode->next = NULL;

        temp->next = newNode;
        temp = newNode;
        p2 = p2->next;
    }

    return res;
}

// Main function
int main() {
    int n1, n2;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n1);
    struct Node* poly1 = createPoly(n1);

    printf("\nEnter number of terms in second polynomial: ");
    scanf("%d", &n2);
    struct Node* poly2 = createPoly(n2);

    printf("\nFirst Polynomial: ");
    displayPoly(poly1);

    printf("Second Polynomial: ");
    displayPoly(poly2);

    struct Node* result = addPoly(poly1, poly2);

    printf("\nResultant Polynomial after Addition: ");
    displayPoly(result);

    return 0;
}

