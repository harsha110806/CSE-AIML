#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};
struct node *head=NULL;
void create(int n)
{
	int i,info;
	struct node *temp,*newnode;
	for(i=1;i<=n;i++)
	{
		newnode=malloc(sizeof(struct node));
		printf("enter the info in node %d:",i);
		scanf("%d",&info);
		newnode->info=info;
		newnode->next=head;
		head=newnode;
		
//		if(head==NULL){
//			head=temp=newnode;
//		}
//		else{
//			temp->next=newnode;
//			temp=newnode;
//		}
	}
}
void display()
{
	struct node *temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("%d -> ",temp->info);
		temp=temp->next;
	}
	printf("NULL");
}
void search(int key)
{
	struct node *temp=head;
	int pos=1;
	while(temp!=NULL){
		if(temp->info==key){
			printf("element %d is found at the position %d",key,pos);
			return;
		}
		temp=temp->next;
		pos++;
	}
}
int main(){
	int n,key;
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	create(n);
	display();
	printf("\nenter key:");
	scanf("%d",&key);
	search(key);
	return 0;
}
