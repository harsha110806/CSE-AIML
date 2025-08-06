#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *prev;
	struct node *next;
};
struct node *head=NULL;
void create(int n)
{
	int i,info;
	struct node *temp=head;
	for(i=1;i<=n;i++)
	{
		struct node *newnode=malloc(sizeof(struct node));
		printf("Enter the info in the node %d:",i);
		scanf("%d", &info); 
        newnode->info = info;
        newnode->next = NULL;
        if(head==NULL)
        {
        	head=newnode;
        	head->next=head;
        	temp=head;
		}
		else
		{
			temp->next=newnode;
			newnode->next=head;
			temp=newnode;
		}   
	}
}
void display()
{
	struct node *temp=head;
	do{
		printf("%d ->",temp->info);
		temp=temp->next;
	}
	while(temp!=head);
	printf("(head)\n");
}
void search(int key)
{
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    int pos = 1;
    struct node *temp = head;
    
    do {
        if (temp->info == key) {
            printf("%d found at position %d\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    printf("%d not found in the list.\n", key);
}

int main()
{
	int n;
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	create(n);
	display();
	printf("enter key to search:");
	int key;
    scanf("%d", &key);
	search(key);
}
