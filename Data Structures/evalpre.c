#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    if(top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = val;
}

int pop() {
    if(top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int peek() {
    if(top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top];
}

int prefixeval(char prefix[])
{
	int n=strlen(prefix);
 	int i;
 	for(i=n-1;i>=0;i--)
 	{
 		char c=prefix[i];
 		if(isdigit(c))
 		{
 			push(c-'0');
		}
		else if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
		{
			int op1=pop();
			int op2=pop();
			
			switch(c){
				case '+':push(op1+op2);break;
				case '-':push(op1-op2);break;
				case '*':push(op1*op2);break;
				case '/':push(op1/op2);break;
				case '^':push((int)pow(op1,op2));break;
				default:printf("Invalid operator");
				exit(1);
				
			}
		}
	}
	return pop();
}

int main() {
    char prefix[MAX];

    printf("Enter a prefix expression(single-digit numbers only): ");
    scanf("%s", prefix);

    int result = prefixeval(prefix);
    printf("Result = %d\n", result);

    return 0;
}

