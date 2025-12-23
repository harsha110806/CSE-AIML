#include<stdio.h>
#include<string.h>
int stk[10];
int top=-1;
void push(char c)
{
	stk[++top]=c;
}
char pop()
{
	return(stk[top--]);
}
int isBalanced(char exp[])
{
	char temp;
	for(int i=0;i<strlen(exp);i++)
	{
		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
        	if(top==-1)
        	{
        		return 0;
			}
			temp=pop();
			if((exp[i] == ']' && temp != '[')||
              (exp[i] == '}' && temp != '{')||
              (exp[i] == ']' && temp != '['))
              {
              	return 0;
			  }
		}
	}
	return(top==-1);
}
int main()
{
	char exp[10];
    printf("Enter an expression: ");
    scanf("%s", exp);

    if (isBalanced(exp)) {
        printf("Valid expression\n");
    } else {
        printf("Invalid expression\n");
    }
    return 0;
}
