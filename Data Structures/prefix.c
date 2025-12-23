#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
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
switch(c)
{
case '+':
case '-':
return 1;


case'*':
case'/':
return 2;

case'^':
return 3;

default:
return -1;
}
}

void reverse(char exp[])
{
char temp;
int i,n=strlen(exp);
for(i=0;i<n/2;i++)
{
temp=exp[i];
exp[i]=exp[n-i-1];
exp[n-i-1]=temp;
}
}

void infixtoprefix(char infix[],char prefix[])
{
int i,k=0;
char c;
reverse(infix);
for(i=0;i<strlen(infix);i++)
{
if(infix[i]=='(')
{
infix[i]=')';
}
else if(infix[i]==')')
{
infix[i]='(';
}
}
for(i=0;i<strlen(infix);i++)
{
c=infix[i];
if(isalnum(c))
{
prefix[k++]=c;
}
else if(c=='(')
{
push(c);
}
else if(c==')')
{
while(top!=-1&&peek()!='(')
{
prefix[k++]=pop();
}
pop();
}
else
{
while(top!=-1&&precedence(peek())>=precedence(c))
{
prefix[k++]=pop();
}
push(c);
}
}
while(top!=-1)
{
prefix[k++]=pop();
}
prefix[k]='\0';
reverse(prefix);
}

void main()
{
char infix[MAX],prefix[MAX];
clrscr();
printf("Enter the infix expression:");
scanf("%s",infix);
infixtoprefix(infix,prefix);
printf("The prefix expression is %s",prefix);
getch();
}
