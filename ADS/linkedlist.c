#include <stdio.h>
#include <stdlib.h>

struct node
{
int data;
struct node *next;
};

/* Global head */
struct node *head = NULL;


/* Traverse */
void traverse()
{
struct node *temp;

if (head == NULL)
{
printf("List is empty.\n");
return;
}

temp = head;

printf("Linked List: ");

while (temp != NULL)
{
printf("%d -> ", temp->data);
temp = temp->next;
}

printf("NULL\n");
}


/* Insert at a given position */
void insert(int val, int pos)
{
struct node *temp, *newnode;
int i = 1;

if (pos < 1)
{
printf("Invalid Position.\n");
return;
}

newnode = (struct node *)malloc(sizeof(struct node));

if (newnode == NULL)
{
printf("Memory allocation failed.\n");
return;
}

newnode->data = val;

/* Insert at beginning */
if (pos == 1)
{
newnode->next = head;
head = newnode;

printf("Node inserted successfully.\n");
traverse();
return;
}

temp = head;

while (i < pos - 1 && temp != NULL)
{
temp = temp->next;
i++;
}

if (temp == NULL)
{
printf("Cannot insert here.\n");
free(newnode);
return;
}

newnode->next = temp->next;
temp->next = newnode;

printf("Node inserted successfully.\n");
traverse();
}


/* Delete node at a given position */
void deleteNode(int pos)
{
struct node *temp, *del;
int i = 1;

if (pos < 1)
{
printf("Invalid Position.\n");
return;
}

if (head == NULL)
{
printf("List is empty.\n");
return;
}

/* Delete first node */
if (pos == 1)
{
del = head;
head = head->next;
free(del);

printf("Node is deleted.\n");
traverse();
return;
}

temp = head;

while (temp != NULL && i < pos - 1)
{
temp = temp->next;
i++;
}

if (temp == NULL || temp->next == NULL)
{
printf("No node to delete.\n");
return;
}

del = temp->next;
temp->next = del->next;

free(del);

printf("Node is deleted.\n");
traverse();
}


/* Search */
void search(int key)
{
struct node *temp;
int pos = 1;

if (head == NULL)
{
printf("List is empty.\n");
return;
}

temp = head;

while (temp != NULL)
{
if (temp->data == key)
{
printf("Element found at position %d\n", pos);
return;
}

temp = temp->next;
pos++;
}

printf("Element not found.\n");
}


/* Main */
int main()
{
int choice, val, pos;

while (1)
{
printf("\n----- Singly Linked List -----\n");
printf("1. Insert\n");
printf("2. Delete\n");
printf("3. Search\n");
printf("4. Traverse\n");
printf("5. Exit\n");

printf("Enter your choice: ");
scanf("%d", &choice);

switch (choice)
{
case 1:
printf("Enter value to insert: ");
scanf("%d", &val);

printf("Enter position: ");
scanf("%d", &pos);

insert(val, pos);
break;

case 2:
printf("Enter position to delete: ");
scanf("%d", &pos);

deleteNode(pos);
break;

case 3:
printf("Enter value to search: ");
scanf("%d", &val);

search(val);
break;

case 4:
traverse();
break;

case 5:
printf("Program terminated.\n");
exit(0);

default:
printf("Invalid choice.\n");
}
}

return 0;
}
