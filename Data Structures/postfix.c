#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>

char stack[100];
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
	if(c=='+'||c=='-'){
		return 1;
	}
	else if(c=='*'||c=='/')
	{
		return 2;
	}
	else if(c=='^')
	{
		return 3;
	}
	return 0;
}

void infixtopostfix(char infix[],char postfix[])
{
	int k=0,i;
	char c;
	for(i=0;i<strlen(infix);i++)
	{
		c=infix[i];
		if(isalnum(c))
		{
			postfix[k++]=c;
		}
		else if(c=='(')
		{
			push(c);
		}
		else if(c==')')
		{
			while(top!=-1&&peek()!='(')
			{
				postfix[k++]=pop();
			}
			pop();
		}
		else
		{
			while(top!=-1&&precedence(peek())>=precedence(c))
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
}

void main()
{
	char infix[100],postfix[100];
	clrscr();
	printf("enter the infix expression:");
	scanf("%s",infix);
	infixtopostfix(infix,postfix);
	printf("postfix expression is:%s",postfix);
	getch();
}
