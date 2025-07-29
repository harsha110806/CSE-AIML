#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};
void count(struct node *head)
{
	int c=0;
	if(head==NULL){
		printf("Linked list is empty");
	}
	struct node *ptr=NULL;
	ptr=head;
	while (ptr!=NULL){
		c++;
		ptr=ptr->link;
	}
	printf("%d",c);
	
		
}
int main()
{
	struct node *head= malloc(sizeof(struct node));
	head->data=45;
	head->link=NULL;
	
	struct node *current1=malloc(sizeof(struct node));
	current1->data=98;
	current1->link=NULL;
	head->link=current1;
	
	struct node *current2=malloc(sizeof(struct node));
	current2->data=98;
	current2->link=NULL;
	current1->link=current2;
	
	struct node *cu=malloc(sizeof(struct node));
	cu->data=44;
	cu->link=NULL;
	current2->link=cu;
	
	
	count(head);
	
}
