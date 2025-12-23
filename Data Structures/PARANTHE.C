#include<stdio.h>
#include<conio.h>
#include<string.h>

char stack[10];
int top=-1;

void push(char c)
{
	stack[++top]=c;
}

char pop()
{
	return stack[top--];
}

int isbalanced(char exp[])
{
	int i;
	char temp;
	top=-1;
	for(i=0;i<strlen(exp);i++)
	{
		if((exp[i]=='(')||(exp[i]=='[')||(exp[i]=='{'))
		{
			push(exp[i]);
		}
		else if((exp[i]==')')||(exp[i]==']')||(exp[i]=='}'))
		{
			if(top==-1)
			{
				return 0;
			}
			temp=pop();
			if((exp[i]==')'&&temp!='(')||(exp[i]=='}'&&temp!='{')||(exp[i]==']'&&temp!='['))
			{
				return 0;
			}
		}
	}
	return(top==-1);
}

void main()
{
	char exp[10];
	clrscr();
	printf("enter the expression:");
	scanf("%s",exp);
	if(isbalanced(exp)==1)
	{
		printf("Balanced.");
	}
	else
	{
		printf("Not Balanced");
	}
	getch();
}
