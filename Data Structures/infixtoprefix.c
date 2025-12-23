#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define SIZE 100

int stack[SIZE];
int top=-1;

void push(char c)
{
	if(top==SIZE-1)
	{
		printf("Stack overflow\n");
		return;
	}
	stack[++top]=c;
}

char pop()
{
	if(top==-1)
	{
		printf("Stack Underflow\n");
		return '\0';
	}
    return stack[top--];
}

char peek()
{
	return stack[top];
}

int precedence(char c)
{
	switch(c)
	{
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
	}
	return -1;
}

void reverse(char exp[])
{
	int n=strlen(exp);
	for(int i=0;i<n/2;i++)
	{
		char temp=exp[i];
		exp[i]=exp[n - i - 1];
		exp[n - i - 1]=temp;
	}
}

void infixtoprefix(char infix[],char prefix[])
{
	char modified[SIZE];
	strcpy(modified,infix);
	reverse(modified);
	
	int i,k=0;
	
	for(i=0;modified[i];i++)
	{
		if(modified[i]=='(')
		{
			modified[i]=')';
		}
		else if(modified[i]==')')
		{
			modified[i]='(';
		}
	}
	
	char postfix[SIZE];
	for(i=0;modified[i];i++)
	{
		char c=modified[i];
		if(isalnum(c))
		{
			postfix[k++]=c;
		}
		else if (c=='(')
		{
			push(c);
		}
		else if(c==')')
		{
			while(peek()!='(' && top!=-1)
			{
				postfix[k++]=pop();
			}
			pop();
		}
		else
		{
			while(top!=-1 && precedence(peek())>=precedence(c))
			{
				postfix[k++]=pop();
			}
			push(c);
		}
	}
	while(top!=-1)
		{
			postfix[k++]=pop();
		}
		postfix[k]='\0';
		reverse(postfix);
		strcpy(prefix,postfix);	
}

int main() {
    char infix[SIZE], prefix[SIZE];
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixtoprefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);

    return 0;
}

