#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node{
	float coef;
	int expo;
	struct node *next;
};

struct node *head=NULL;

void create(int n)
{
	struct node *temp=NULL;
	int i;
	for(i=1;i<=n;i++)
	{
		struct node *newnode=malloc(sizeof(struct node));
		printf("enter the coef in term %d:",i);
		scanf("%f",&newnode->coef);
		printf("enter the expo in term %d:",i);
		scanf("%d",&newnode->expo);
		newnode->next=NULL;
		if(head==NULL)
		{
			head=temp=newnode;
		}
		else
		{
			temp->next=newnode;
			temp=newnode;
		}
	}
}

void display()
{
	struct node *temp=head;
	printf("\nP(x)= ");
	while(temp!=NULL)
	{
		printf("%.1fx^%d ",temp->coef,temp->expo);
		temp=temp->next;
		if(temp!=NULL)
		{
			printf("+");
		}
		
	}
	printf("\n");
}

void evaluate()
{
	int result=0;
	int x;
	printf("provide the value of x:");
	scanf("%d",&x);
	struct node *temp=head;
	while(temp!=NULL)
	{
		result+=temp->coef*pow(x,temp->expo);
		temp=temp->next;
	}
	printf("The result after evaluation is: %d\n",result);
}
void differentiate()
{
	struct node *temp=head;
	while(temp!=NULL)
	{
		if(temp->expo!=0)
		{
			temp->coef=temp->expo*temp->coef;
			temp->expo=temp->expo-1;
		}
		else
		{
			temp->coef=0;
		}
		temp=temp->next;
	}
	display();
}

int main()
{
	int n;
	printf("Enter the number of terms:");
	scanf("%d",&n);
	create(n);
	display();
	evaluate();
	printf("polynomial after differentiation:");
	differentiate();
}
