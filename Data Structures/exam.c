#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
int data;
struct node*next;
};
struct node*head=NULL;

void create(int n){
int i,val;
struct node*newnode,*temp;
head=NULL;
for(i=1;i<=n;i++){
newnode=(struct node*)malloc(sizeof(struct node));
printf("Enter value for node %d:",i);
scanf("%d",&val);
newnode->data=val;
newnode->next=NULL;
if(head==NULL){
head=newnode;
temp=newnode;
}else{
temp->next=newnode;
temp=newnode;
}
}
}

void insertbeg(int val){
struct node*newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=val;
newnode->next=head;
head=newnode;
}

void deletepos(int pos){
struct node*temp=head,*prev=NULL;
int i=1;
if(head==NULL){
printf("List empty\n");
return;
}
if(pos==1){
head=temp->next;
free(temp);
return;
}
while(temp!=NULL&&i<pos){
prev=temp;
temp=temp->next;
i++;
}
if(temp==NULL){
printf("Invalid position\n");
return;
}
prev->next=temp->next;
free(temp);
}

void display(){
struct node*temp=head;
if(head==NULL){
printf("List empty\n");
return;
}
while(temp!=NULL){
printf("%d ",temp->data);
temp=temp->next;
}
printf("\n");
}

void main(){
int ch,val,pos,n;
clrscr();
while(1){
printf("\n1.Create\n2.Insert at beginning\n3.Delete at position\n4.Display\n5.Exit\nEnter choice:");
scanf("%d",&ch);
switch(ch){
case 1:printf("Enter number of nodes:");scanf("%d",&n);create(n);break;
case 2:printf("Enter value:");scanf("%d",&val);insertbeg(val);break;
case 3:printf("Enter position:");scanf("%d",&pos);deletepos(pos);break;
case 4:display();break;
case 5:exit(0);
default:printf("Invalid choice\n");
}
}
getch();
}

