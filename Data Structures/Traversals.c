#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node *lchild,*rchild;
	int info;
};

struct node *root=NULL;

struct node* newnode(char data)
{
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->info=data;
	newnode->lchild=NULL;
	newnode->rchild=NULL;
	return newnode;
}

struct node* buildtree(char arr[],int i,int n)
{
	if(i>=n || arr[i]=='-')
	{
		return NULL;
	}
	struct node *node=newnode(arr[i]);
	node->lchild=buildtree(arr,2*i+1,n);
	node->rchild=buildtree(arr,2*i+2,n);
	
	return node;
}

void preorder(struct node* node)
{
	if(node!=NULL)
	{
		printf("%c ",node->info);
	    preorder(node->lchild);
	    preorder(node->rchild);
	}	
}

void inorder(struct node* node)
{
	if(node!=NULL)
	{
		inorder(node->lchild);
		printf("%c ",node->info);
		inorder(node->rchild);
	}
}

void postorder(struct node* node)
{
	if(node!=NULL)
	{
		postorder(node->lchild);
		postorder(node->rchild);
		printf("%c ",node->info);
	}
}

int main()
{

	char arr[]={'a','b','c','d','e','f'};
	int n=sizeof(arr)/sizeof(arr[0]);
	root=buildtree(arr,0,n);
	
	printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}
