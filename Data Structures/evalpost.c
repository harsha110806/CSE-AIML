#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

int stack[MAX];
int top=-1;
void push(int val)
{
	if(top==MAX-1)
	{
		printf("Stack overflow\n");
		return;
	}
	stack[++top]=val;
}

int pop()
{
	if(top==-1)
	{
		printf("Stack underflow\n");
		return -1;
	}
	return stack[top--];
}

int eval(char postfix[])
{
	int n=strlen(postfix);
	for(int i=0;i<n;i++)
	{
		char c=postfix[i];
		if(isdigit(c))
		{
			push(c-'0');
		}
		else
		{
			int val2 = pop();
            int val1 = pop();
            switch(c) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
                case '^': push((int)pow(val1,val2));break;
            }
		}
	}
	return pop();
}
int main() {
    char postfix[MAX];
    printf("Enter postfix expression (single-digit numbers only): ");
    scanf("%s", postfix);

    int result = eval(postfix);
    printf("Result = %d\n", result);
    return 0;
}
