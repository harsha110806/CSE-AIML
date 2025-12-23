#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

char stack[MAX];
int top=-1;

void push(char c)
{
	stack[++top]=c;
}

char pop()
{
	return stack[top--];
}

char peek()
{
	return stack[top];
}

int precedence(char c)
{
	if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3; // exponent operator
    return 0;
}

void itp(char infix[],char postfix[])
{
	int k=0;
	for (int i = 0; i < strlen(infix); i++) 
	{
		char c=infix[i];
		if(c=='(')
		{
			push(c);
		}
		else if(isalnum(c))
		{
			postfix[k++]=c;
		}
		else if(c==')')
		{
			while(peek()!='('&& top!=-1)
			{
				postfix[k++]=pop();
			}
			pop();
		}
		else
		{ 
            while (top != -1 && precedence(peek()) >= precedence(c)) 
			{
                postfix[k++] = pop();
            }
            push(c);
        }
	}
	while(top!=-1)
	{
		postfix[k++]=pop();
	}
	postfix[k]='\0';
}
int main() 
{
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    itp(infix, postfix);

    printf("Postfix expression: %s\n", postfix);
    return 0;
}
