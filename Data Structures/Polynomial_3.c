#include <stdio.h>
#include <stdlib.h>

struct node {
    float coef;
    int expo;
    struct node *next;
};

struct node *head1 = NULL, *head2 = NULL, *result = NULL;

// Function to create polynomial
void createPoly(struct node **head, int n) {
    struct node *newnode, *temp;
    float coef;
    int expo;

    for (int i = 1; i <= n; i++) {
        newnode = (struct node*) malloc(sizeof(struct node));
        printf("\nEnter coefficient of term %d: ", i);
        scanf("%f", &coef);
        printf("Enter exponent of term %d: ", i);
        scanf("%d", &expo);

        newnode->coef = coef;
        newnode->expo = expo;
        newnode->next = NULL;

        if (*head == NULL) {
            *head = temp = newnode;   // first node
        } else {
            temp->next = newnode;     // attach at end
            temp = newnode;
        }
    }
}

// Function to display polynomial
void displayPoly(struct node *poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }

    while (poly != NULL) {
        printf("%.1fx^%d", poly->coef, poly->expo);
        poly = poly->next;
        if (poly != NULL)
            printf(" + ");
    }
    printf("\n");
}

// Function to add two polynomials
struct node* addPoly(struct node *poly1, struct node *poly2) {
    struct node *p1 = poly1, *p2 = poly2;
    struct node *res = NULL, *temp = NULL, *newnode;

    while (p1 != NULL && p2 != NULL) {
        newnode = (struct node*) malloc(sizeof(struct node));
        newnode->next = NULL;

        if (p1->expo == p2->expo) {
            newnode->coef = p1->coef + p2->coef;
            newnode->expo = p1->expo;
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->expo > p2->expo) {
            newnode->coef = p1->coef;
            newnode->expo = p1->expo;
            p1 = p1->next;
        } else {
            newnode->coef = p2->coef;
            newnode->expo = p2->expo;
            p2 = p2->next;
        }

        if (res == NULL) {
            res = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    // Copy remaining terms
    while (p1 != NULL) {
        newnode = (struct node*) malloc(sizeof(struct node));
        newnode->coef = p1->coef;
        newnode->expo = p1->expo;
        newnode->next = NULL;
        temp->next = newnode;
        temp = newnode;
        p1 = p1->next;
    }

    while (p2 != NULL) {
        newnode = (struct node*) malloc(sizeof(struct node));
        newnode->coef = p2->coef;
        newnode->expo = p2->expo;
        newnode->next = NULL;
        temp->next = newnode;
        temp = newnode;
        p2 = p2->next;
    }

    return res;
}

// Main Function
int main() {
    int n1, n2;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n1);
    createPoly(&head1, n1);

    printf("\nEnter number of terms in second polynomial: ");
    scanf("%d", &n2);
    createPoly(&head2, n2);

    printf("\nFirst Polynomial: ");
    displayPoly(head1);

    printf("Second Polynomial: ");
    displayPoly(head2);

    result = addPoly(head1, head2);

    printf("\nResultant Polynomial after Addition: ");
    displayPoly(result);

    return 0;
}

