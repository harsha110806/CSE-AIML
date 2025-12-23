#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *top=NULL;
int isfull()
{
	struct node *temp=malloc(sizeof(struct node));
	if(temp==NULL)
	{
		return 1;
	}
	free(temp);
	return 0;
}

int isempty()
{
	return top==NULL;
}

void push(int value)
{
	if(isfull())
	{
		printf("Stack Overflow");
		return;
	}
	else
	{
		struct node *newnode=malloc(sizeof(struct node));
		newnode->data=value;
		newnode->next=top;
		top=newnode;
		printf("%d pushed into stack.\n",value);
	}
}

void pop()
{
	if (isempty())
	{
		printf("Stack underflow");
		return;
	}
	else
	{
		struct node *temp=top;
		int poppedvalue= temp->data;
		top=top->next;
		free(temp);
		printf("%d popped stack.\n",poppedvalue);
	}
}

void display()
{
	if (isempty())
	{
		printf("Stack underflow");
		return;
	}
	else
	{
		struct node *current=top;
		printf("Stack elements(from top to bottom): \n");
		
		while(current!=NULL)
		{
			printf("-----------\n");
			printf("     %d     \n",current->data);
			current=current->next;
		}
		printf("-----------");	
	}
}

int main() {
    int choice, value;

    // The menu will loop forever until the user chooses to exit
    while (1) {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Check if Empty\n");
        printf("5. Exit\n");
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
                printf("Exiting program.\n");
                exit(0); // Exits the program
            default:
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }
    }

    return 0; // This line is never reached but is good practice
}
