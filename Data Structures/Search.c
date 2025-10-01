#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *left, *right;
};


struct Node* root = NULL;

struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* node, int data) {
    if (node == NULL)
        return createNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    return node;
}

struct Node* search(struct Node* node, int key) {
    if (node == NULL || node->data == key)
        return node;

    if (key < node->data)
        return search(node->left, key);

    return search(node->right, key);
}

int main() {
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);  
    }

    int key;
    printf("Enter the key:");
    scanf("%d",&key);
    struct Node* result = search(root, key);

    if (result != NULL)
        printf("Element %d found in the BST.\n", key);
    else
        printf("Element %d not found in the BST.\n", key);

    return 0;
}

