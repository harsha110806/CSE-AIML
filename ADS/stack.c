#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int stack[MAX];
int top = -1;

void push(int val)
{
if (top == MAX - 1)
{
printf("Stack Overflow\n");
return;
}

top++;
stack[top] = val;

printf("Element pushed successfully.\n");
}

void pop()
{
if (top == -1)
{
printf("Stack Underflow\n");
return;
}

printf("Deleted element: %d\n", stack[top]);
top--;
}

void peek()
{
if (top == -1)
{
printf("Stack is empty.\n");
return;
}

printf("Top element: %d\n", stack[top]);
}

void display()
{
int i;

if (top == -1)
{
printf("Stack is empty.\n");
return;
}

printf("Stack elements:\n");
printf("---\n");

for (i = top; i >= 0; i--)
{
printf(" %d \n", stack[i]);
printf("---\n");
}
}

int main()
{
int choice, val;

while (1)
{
printf("\n----- Stack Operations -----\n");
printf("1. Push\n");
printf("2. Pop\n");
printf("3. Peek\n");
printf("4. Display\n");
printf("5. Exit\n");

printf("Enter your choice: ");
scanf("%d", &choice);

switch (choice)
{
case 1:
printf("Enter value: ");
scanf("%d", &val);
push(val);
break;

case 2:
pop();
break;

case 3:
peek();
break;

case 4:
display();
break;

case 5:
printf("Program Terminated.\n");
exit(0);

default:
printf("Invalid Choice\n");
}
}

return 0;
}
