#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// node structure
struct node {
    float coef;          // coefficient
    int expo;            // exponent
    struct node *next;
};

// global head pointer
struct node *head = NULL;

// function to create polynomial
void createPoly(int n) {
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

        if (head == NULL) {
            head = temp = newnode;   // first node
        } else {
            temp->next = newnode;    // attach at end
            temp = newnode;
        }
    }
}

// function to display polynomial
void displayPoly() {
    struct node *temp = head;
    printf("\nP(x) = ");
    while (temp != NULL) {
        printf("%.1f*x^%d", temp->coef, temp->expo);
        temp = temp->next;
        if (temp != NULL)
            printf(" + ");
    }
    printf("\n");
}

// function to differentiate polynomial
void differentiate() {
    struct node *temp = head;

    while (temp != NULL) {
        if (temp->expo != 0) {
            temp->coef = temp->coef * temp->expo;
            temp->expo = temp->expo - 1;
        } else {
            temp->coef = 0;   // derivative of constant
        }
        temp = temp->next;
    }

    printf("Differentiated polynomial: ");
    displayPoly();
}


// function to evaluate polynomial at x
void evaluate(int x) {
    float result = 0;
    struct node *temp = head;

    while (temp != NULL) {
        result += temp->coef * pow(x, temp->expo);
        temp = temp->next;
    }
    printf("\nValue of derivative at x = %d is: %.2f\n", x, result);
}

// main function
int main() {
    int n, x;
    printf("Enter number of terms in polynomial: ");
    scanf("%d", &n);

    createPoly(n);

    printf("\nOriginal Polynomial:");
    displayPoly();

    differentiate();
    printf("\nAfter Differentiation:");
    displayPoly();

    printf("\nEnter value of x to evaluate derivative: ");
    scanf("%d", &x);

    evaluate(x);
    

    return 0;
}

