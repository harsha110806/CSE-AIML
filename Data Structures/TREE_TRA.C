#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>

struct node{
struct node *lchild,*rchild;
char info;
};

struct node *root=NULL;

struct node* newnode(char info)
{
struct node *node=(struct node*)malloc(sizeof(struct node));
node->info=info;
node->lchild=NULL;
node->rchild=NULL;

return node;
}

struct node* buildtree(char arr[],int i,int n)
{
struct node *node;
if(i>=n || arr[i]=='-')
{
return NULL;
}
node=newnode(arr[i]);
node->lchild=buildtree(arr,2*i+1,n);
node->rchild=buildtree(arr,2*i+2,n);
return node;
}

void preorder(struct node* node)
{if(node!=NULL)
{
printf("%c ",node->info);
preorder(node->lchild);
preorder(node->rchild);
}
}

void inorder(struct node* node)
{
if(node!=NULL){
inorder(node->lchild);
printf("%c ",node->info);
inorder(node->rchild);
}
}

void postorder(struct node* node)
{if(node!=NULL)
{
postorder(node->lchild);
postorder(node->rchild);
printf("%c ",node->info);
}
}

void main()
{
char arr[]={'A','B','C','D','E','F'};

int n=sizeof(arr)/sizeof(arr[0]);
root=buildtree(arr,0,n);

clrscr();
printf("Preorder traversal:");
preorder(root);
printf("\n");

printf("Inorder traversal:");
inorder(root);
printf("\n");

printf("Postorder traversal:");
postorder(root);
printf("\n");

getch();
}
