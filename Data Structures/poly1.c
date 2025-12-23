#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// structure of the polynomial node
struct node {
    float coef;
    int expo;
    struct node *next;
};

// global head pointer
struct node *head = NULL;

// create polynomial
void createPoly(int n) {
    struct node *temp = NULL, *newNode = NULL;

    for(int i = 1; i <= n; i++) {   // ? starts from 1 now
        newNode = (struct node*) malloc(sizeof(struct node));
        printf("\nEnter coefficient of term %d: ", i);
        scanf("%f", &newNode->coef);
        printf("Enter exponent of term %d: ", i);
        scanf("%d", &newNode->expo);

        newNode->next = NULL;

        if(head == NULL) {   // first node
            head = newNode;
            temp = newNode;
        } else {             // attach at end
            temp->next = newNode;
            temp = newNode;
        }
    }
}

// display polynomial
void display() {
    struct node *temp = head;
    printf("\nP(x) = ");
    while(temp != NULL) {
        printf("%.1fx^%d", temp->coef, temp->expo);
        temp = temp->next;
        if(temp != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

// evaluate polynomial
void evaluate() {
    float x, result = 0;
    struct node *temp = head;

    printf("\nEnter value of x: ");
    scanf("%f", &x);

    while(temp != NULL) {
        result += temp->coef * pow(x, temp->expo);
        temp = temp->next;
    }

    display();
    printf("Value of polynomial at x = %.2f is: %.2f\n", x, result);
}

int main() {
    int n;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    createPoly(n);
    evaluate();

    return 0;
}

