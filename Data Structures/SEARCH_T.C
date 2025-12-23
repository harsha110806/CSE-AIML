#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node{
struct node *lchild,*rchild;
int info;
};
struct node *root=NULL;

struct node *newnode(int data)
{
struct node *newnode=(struct node*)(malloc(sizeof(struct node)));
newnode->info=data;
newnode->lchild=NULL;
newnode->rchild=NULL;
return newnode;
}

struct node* insert(struct node *node,int data)
{
if(node==NULL)
{
return newnode(data);
}
else if(data<node->info)
{
node->lchild=insert(node->lchild,data);
}
else if(data>node->info)
{
node->rchild=insert(node->rchild,data);
}
return node;
}

struct node* search(struct node *node,int key)
{
if(node==NULL || node->info==key)
{
return node;
}
else if(key>node->info)
{
return search(node->rchild,key);
}
return search(node->lchild,key);
}

void main()
{
struct node *result;
int arr[]={1,2,3,4,5,6,7,8};
int i,n=sizeof(arr)/sizeof(arr[0]),key;
for(i=0;i<n;i++)
{
root=insert(root,arr[i]);
}
clrscr();
printf("Enter the key:");
scanf("%d",&key);
result=search(root,key);
if(result==NULL)
{
printf("Key is not found.\n");
}
else
{
printf("Key is found.\n");
}
getch();
}