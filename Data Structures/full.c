#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *next;
};
struct node *head=NULL;
void create(int n)
{
	struct node *newnode,*temp;
	int data,i;
	for(i=1;i<=n;i++)
	{
		newnode=malloc(sizeof(struct node));
		printf("Enter the info in node %d:",i);
		scanf("%d",&data);
		newnode->info=data;
		newnode->next=NULL;
		if(head==NULL)
		{
			temp=head=newnode;
		}
		else
		{
			temp->next=newnode;
			temp=newnode;
		}
//		newnode->next=head;
//		head=newnode;
	}
	
}
void display()
{
	struct node *temp;
	temp=head;
	int i;
	while(temp!=NULL)
	{
		printf("%d->",temp->info);
		temp=temp->next;
	}
	printf("NULL");
}
void addatbeginning(int data )
{
	struct node *newnode=malloc(sizeof(struct node));
	newnode->info=data;
	newnode->next=head;
	head=newnode;
	printf("inserted at beginning");
}

void addatend(int data)
{
	struct node *newnode=malloc(sizeof(struct node));
	struct node *temp=head;
	newnode->info=data;
	newnode->next=NULL;
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
	    temp->next=newnode;
	}
}

void addafter(int key,int data)
{
	struct node *newnode=malloc(sizeof(struct node));
	newnode->info=data;
	newnode->next=NULL;
	struct node *temp=head;
	while(temp!=NULL)
	{
		if(temp->info==key)
		{
			newnode->next=temp->next;
			temp->next=newnode;
			return;
		}
		else
		{
			temp=temp->next;
		}
	}
}

void addbefore(int key,int data)
{
	struct node *temp=head,*prev=NULL,*newnode;
	newnode=malloc(sizeof(struct node));
	while(temp->info!=key)
	{
		prev=temp;
		temp=temp->next;
	}
	newnode->next=temp;
	prev->next=newnode;	
}

int main()
{
	int n;
	printf("Number of nodes:");
	scanf("%d",&n);
	create(n);
	display();
	return 0;
}

