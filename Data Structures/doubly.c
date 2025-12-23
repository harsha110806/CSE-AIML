#include<stdio.h>
#include<stdlib.h>

struct node{
	int info;
	struct node *next;
	struct node *prev;
};

struct node *head=NULL;

void createdoubly(int n)
{
	struct node *temp=head;
	int i,info;
	for (i=1;i<=n;i++)
	{
		struct node *newnode=malloc(sizeof(struct node));
		printf("enter the data in node %d:",i);
		scanf("%d",&info);
		newnode->info=info;
		newnode->prev=NULL;
		newnode->next=NULL;
		if(head==NULL)
		{
			head=newnode;
			temp=head;	
		}
		else
		{
			temp->next=newnode;
			newnode->prev=temp;
			temp=newnode;
		}	
	}	
}

void display()
{
	struct node *temp=head;
	printf("doubly linked list:");
	while(temp!=NULL)
	{
		printf("%d <-> ",temp->info);
		temp=temp->next;
	}
	printf("NULL\n");
}

void search(int key)
{
	struct node *temp=head;
	int pos=1;
	while(temp!=NULL)
	{
		if(temp->info==key)
		{
			printf("%d found at position %d",key,pos);
			return;
		}
		temp=temp->next;
		pos++;
	}
	printf("%d not found in the list",key);
}

int main()
{
	int n,key;
	printf("enter the number of nodes:");
	scanf("%d",&n);
	createdoubly(n);
	display();
	printf("enter the key value to search:");
	scanf("%d",&key);
	search(key);	
}
