#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{
	int data;
	struct node *link;
};
int main()
{
	struct node *head=NULL, *temp=NULL,*newnode=NULL;
	int i,n,data;
	printf("enter the no. of nodes:");
	scanf("%d",&n);
	
	for (i=1;i<=n;i++)
	{
		newnode=malloc(sizeof (struct node));
		printf("Enter the data in node %d: ",i);
		scanf("%d",&data);
		newnode->data=data;
		newnode->link=NULL;
	if(head==NULL)
	{
		head=temp=newnode;
	}
	else
	{
		temp->link=newnode;
		temp=newnode;
	}
}
printf("linked list: ");
temp=head;
while(temp!=NULL){
	printf("%d ->",temp->data);
	temp=temp->link;
}
printf("NULL");
return 0;
	
}
