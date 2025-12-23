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
struct node *newnode,*temp;

for(i=1;i<=n;i++)
{
newnode=(struct node*)malloc(sizeof(struct node));
printf("Enter the info in node %d:",i);
scanf("%d",&info);
newnode->info=info;
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
while(temp!=NULL)
{
printf("%d ->",temp->info);
temp=temp->next;
}
printf("NULL\n");
}

void insertatbeginning(int data)
{
struct node *newnode=(struct node *)malloc(sizeof(struct node));
newnode->info=data;
if(head==NULL)
{
newnode->next=NULL;
head=newnode;
printf("Inserted as head(empty list).\n");
display();
return;
}
newnode->next=head;
head=newnode;
display();
}

void deletepos(int pos){
struct node*temp=head,*prev=NULL;
int i;
if(head==NULL){
printf("List empty\n");
return;
}
if(pos==1){
head=head->next;
free(temp);
display();
return;
}
for(i=1;temp!=NULL&&i<pos;i++){
prev=temp;
temp=temp->next;
}
if(temp==NULL){
printf("Invalid position\n");
return;
}
prev->next=temp->next;
free(temp);
display();
}

void main()
{
int n,info,pos,choice;
clrscr();
while(1)
{
printf("1.create.\n");
printf("2.Insert at beginning.\n");
printf("3.Delete at a position.\n");
printf("4.Display.\n");
printf("5.Exit.\n");
printf("Enter the choice:");
scanf("%d",&choice);
switch(choice){
case 1:printf("Enter number of nodes:");
       scanf("%d",&n);
       create(n);
       break;
case 2:printf("Enter value:");
       scanf("%d",&info);
       insertatbeginning(info);
       break;
case 3:printf("Enter position:");
       scanf("%d",&pos);
       deletepos(pos);
       break;
case 4:display();
       break;
case 5:exit(0);
default:printf("Invalid choice\n");
}
}
}