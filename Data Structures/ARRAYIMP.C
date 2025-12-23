#include<stdio.h>
#include<conio.h>

#define SIZE 5

int stack[SIZE];
int top=-1;

int isfull()
{
	return top==SIZE-1;
}

int isempty()
{
	return top==-1;
}

void push(int value)
{
	if (isfull())
	{
		printf("Stack overflow! cannot push %d",value);
	}
	else
	{
	top++;
	stack[top]=value;
	printf("pushed %d into the stack.\n",value);
    }
}

void pop()
{
	if (isempty())
	{
		printf("Stack underflow! no element to pop.\n");
	}
	else
	{
		int poppedvalue=stack[top];
		top--;
		printf("Popped %d from the stack.\n",poppedvalue);
	}
}

void display()
{       int i;
	if (isempty())
	{
		printf("Stack underflow! no element to pop.\n");
	}
	else
	{
		for(i=top;i>=0;i--)
		{
			printf("-----------\n");
			printf("     %d    \n",stack[i]);
		}
		printf("-----------");
	}
}
void main() {
    int choice, value;
    clrscr();
    while (1) {
	printf("\n--- STACK MENU (Array Implementation) ---\n");
	printf("1. Push\n");
	printf("2. Pop\n");
	printf("3. Display\n");
	printf("4. Check if Empty\n");
	printf("5. Check if Full\n");
	printf("6. Exit\n");
	printf("\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);

	switch (choice) {
	    case 1:
		printf("Enter the value to push: ");
		scanf("%d", &value);
		push(value);
		break;
	    case 2:
		pop();
		break;
	    case 3:
		display();
		break;
	    case 4:
		if (isempty()) {
		    printf("Stack is empty.\n");
		} else {
		    printf("Stack is not empty.\n");
		}
		break;
	    case 5:
		if (isfull()) {
		    printf("Stack is full.\n");
		} else {
		    printf("Stack is not full.\n");
		}
		break;
	    case 6:
			    reverseStack();
			    break;
	    case 7:
		printf("Exiting program.\n");
		exit(0);
	    default:
		printf("Invalid choice! Please enter a number between 1 and 6.\n");
	}
    }
}
