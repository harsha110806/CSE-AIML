#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *next;
};
struct node *head=NULL;
void create(int n)
{
	struct node *newnode,*temp;
	int info,i;
	for (i=1;i<=n;i++)
	{
	newnode=malloc(sizeof(struct node));
	if (newnode==NULL)
	{
		printf("failed");
		return ;
	}
	printf("Enter the data of node %d: ",i);
	scanf("%d",&info);
	newnode->info=info;
	newnode->next=NULL;
	if(head==NULL){
		head=temp=newnode;
	}
	else{
		temp->next=newnode;
		temp=newnode;
	}
  }
}
void display()
{
	struct node *temp;
	temp=head;
	while(temp!=NULL){
		printf("%d -> ",temp->info);
		temp=temp->next;
	}
	printf("NULL");
}
int main(){
	int n;
	printf("enter number of nodes: ");
	scanf("%d",&n);
	create(n);
	display();
	return 0;
}
