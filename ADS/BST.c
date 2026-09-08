#include <stdio.h>
#include <stdlib.h>

struct node
{
int data;
struct node *left;
struct node *right;
};

struct node* createnode(int value)
{
struct node *newnode;

newnode = (struct node*)malloc(sizeof(struct node));

newnode->data = value;
newnode->left = NULL;
newnode->right = NULL;

return newnode;
}

struct node* insert(struct node *root, int value)
{
if(root == NULL)
{
return createnode(value);
}

if(value < root->data)
{
root->left = insert(root->left, value);
}
else if(value > root->data)
{
root->right = insert(root->right, value);
}

return root;
}

void search(struct node *root, int value)
{
if(root == NULL)
{
printf("Value not found.\n");
return;
}

if(root->data == value)
{
printf("Value found.\n");
return;
}

if(value < root->data)
search(root->left, value);
else
search(root->right, value);
}

struct node *getsuccessor(struct node *curr)
{
curr = curr->right;

while(curr != NULL && curr->left != NULL)
{
curr = curr->left;
}

return curr;
}

struct node* deleteNode(struct node *root, int value)
{
if(root == NULL)
{
return root;
}

if(value < root->data)
{
root->left = deleteNode(root->left, value);
}
else if(value > root->data)
{
root->right = deleteNode(root->right, value);
}
else
{
if(root->left == NULL)
{
struct node *temp = root->right;
free(root);
return temp;
}

else if(root->right == NULL)
{
struct node *temp = root->left;
free(root);
return temp;
}

else
{
struct node *succ = getsuccessor(root);

root->data = succ->data;

root->right = deleteNode(root->right, succ->data);
}
}

return root;
}

void inorder(struct node *root)
{
if(root != NULL)
{
inorder(root->left);
printf("%d ", root->data);
inorder(root->right);
}
}

void preorder(struct node *root)
{
if(root != NULL)
{
preorder(root->left);
printf("%d ", root->data);
preorder(root->right);
}
}

void postorder(struct node *root)
{
if(root != NULL)
{
postorder(root->left);
postorder(root->right);
printf("%d ", root->data);
}
}

int main()
{
struct node *root = NULL;
int choice, value;

while(1)
{
printf("\n======BINARY SEARCH TREE======\n");
printf("1. Insert\n");
printf("2. Delete\n");
printf("3. Search\n");
printf("4. Inorder Traversal\n");
printf("5. Preorder Traversal\n");
printf("6. Postorder Traversal\n");
printf("7. Exit\n");

printf("Enter your choice: ");
scanf("%d", &choice);

switch(choice)
{
case 1:
printf("Enter value to insert: ");
scanf("%d", &value);

root = insert(root, value);
printf("Node inserted successfully.\n");
break;

case 2:
printf("Enter value to delete: ");
scanf("%d", &value);

root = deleteNode(root, value);
printf("Deletion completed.\n");
break;

case 3:
printf("Enter value to search: ");
scanf("%d", &value);

search(root, value);
break;

case 4:
printf("Inorder Traversal: ");
inorder(root);
printf("\n");
break;

case 5:
printf("Preorder Traversal: ");
preorder(root);
printf("\n");
break;

case 6:
printf("Postorder Traversal: ");
postorder(root);
printf("\n");
break;

case 7:
printf("Program terminated.\n");
exit(0);

default:
printf("Invalid choice.\n");
}
}

return 0;
}
