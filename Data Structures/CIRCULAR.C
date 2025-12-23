#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node {
    int info;
    struct node *next;
};

struct node *head = NULL;

void create(int n)
{
    int info, i;
    struct node *temp;

    for(i = 1; i <= n; i++)
    {
	struct node *newnode = (struct node*) malloc(sizeof(struct node));

	printf("Enter the data in node %d: ", i);
	scanf("%d", &info);

	newnode->info = info;
	newnode->next = NULL;

	if(head == NULL)
	{
	    head = temp = newnode;
	}
	else
	{
	    temp->next = newnode;
	    temp = newnode;
	}
    }
    if(temp!=NULL)
    {
	temp->next=head;
	}
}
void display()
{
    struct node *temp = head;
    if(head==NULL)
    {
    printf("List is empty.\n");
    return;
    }
    printf("\nLinked List: ");
    do
    {
	printf("%d -> ", temp->info);
	temp = temp->next;
    }while(temp != head);
    printf("(head)\n");
}

void insertatbeginning(int data)
{
struct node *temp=head,*newnode=(struct node*)malloc(sizeof(struct node));
if(head==NULL)
{
newnode->info=data;
newnode->next=head;
head=newnode;
return;
}
while(temp->next!=head)
{
temp=temp->next;
}

newnode->info=data;
newnode->next=head;
temp->next=newnode;
head=newnode;
display();
}

void insertatend(int data)
{
struct node *temp=head,*newnode=(struct node*)malloc(sizeof(struct node));
newnode->info=data;
if(head==NULL)
{
newnode->next=newnode;
head=newnode;
return;
}
while(temp->next!=head)
{
temp=temp->next;
}
newnode->next=head;
temp->next=newnode;
display();
}

void insertafter(int key,int data)
{
struct node *temp=head,*newnode=(struct node*)malloc(sizeof(struct node));

if(head==NULL)
{
printf("List is empty.\n");
return;
}
do
{
if(temp->info==key)
{
newnode->info=data;
newnode->next=temp->next;
temp->next=newnode;
display();
return;
}
temp=temp->next;
}while(temp!=head);
printf("Key not found.\n");
}

void insertbefore(int key,int data)
{
struct node *prev=NULL,*temp=head,*newnode=(struct node*)malloc(sizeof(struct node));
if(head==NULL)
{
printf("List is empty.\n");
return;
}
newnode->info=data;
if(head->info==key)
{
while(temp->next!=head)
{
temp=temp->next;
}
newnode->next=head;
temp->next=newnode;
head=newnode;
display();
return;
}
do
{
   prev=temp;
   temp=temp->next;
   if(temp->info==key)
   {
   prev->next=newnode;
   newnode->next=temp;
   display();
   return;
   }
}while(temp!=head);
printf("Key not found.\n");
}

void deleteatbeginning()
{
struct node *del,*temp=head;
if(head==NULL)
{
printf("List is empty.\n");
return;
}

if(head->next==head)
{
free(head);
head=NULL;
printf("Deleted the single node.\n");
return;
}
while(temp->next!=head)
{
temp=temp->next;
}
del=head;
head=head->next;
temp->next=head;
free(del);
display();
}

void deleteatend()
{
struct node *prev,*temp=head;
if(head==NULL)
{
printf("List is empty.\n");
return;
}

if(head->next==head)
{
free(head);
head=NULL;
printf("Deleted the single node.\n");
return;
}

while(temp->next!=head)
{
prev=temp;
temp=temp->next;
}
prev->next=head;
free(temp);
display();
}

void deleteafter(int key)
{
    struct node *del, *temp = head;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    do
    {
        if (temp->info == key)
        {
            del = temp->next;

            // If key is the only node
            if (del == head && head->next == head)
            {
                printf("No node exists to delete.\n");
                return;
            }

            // If the node to delete is head -> update head
            if (del == head)
            {
                head = head->next;
            }

            temp->next = del->next;
            free(del);
            display();
            return;
        }
        temp = temp->next;

    } while (temp != head);

    printf("Key not found.\n");
}

void deletebefore(int key)
{
	struct node *temp=head,*last=head,*beforeprev=NULL,*prev=NULL;
	if(head==NULL)
	{
		printf("list is empty.\n");
		return;
	}
	if(head->info==key)
	{
		if(head->next==head)
		{
			printf("No node exists to delete.\n");
			return;
		}
		else
		{
			while(temp->next!=head)
			{
				prev=temp;
				temp=temp->next;
			}
			prev->next=head;
			free(temp);
			display();
			return;
		}
	}
	do
	{
		beforeprev=prev;
		prev=temp;
		temp=temp->next;
		if(temp->info==key)
		{
			if(prev==head)
			{
				while(last->next!=head)
				{
					last=last->next;
				}
				head=head->next;
				last->next=head;
				free(prev);	
			}
			else
			{
				beforeprev->next=temp;
				free(prev);
			}
			display();
			return;
		}
	}while(temp!=head);
	
	printf("Key not found.\n");
}




void main()
{

int n,key1,key2,key3,key4,insb,inse,insa,insm;
clrscr();
printf("enter the number of nodes:");
scanf("%d",&n);

create(n);

display();

printf("enter the data to insert at beginning:");
scanf("%d",&insb);
insertatbeginning(insb);

printf("enter the data to insert at end:");
scanf("%d",&inse);
insertatend(inse);

printf("enter the node after which to insert:");
scanf("%d",&key1);
printf("enter the node to insert:");
scanf("%d",&insa);
insertafter(key1,insa);

printf("enter the node before which to insert:");
scanf("%d",&key2);
printf("enter the node to insert:");
scanf("%d",&insm);
insertbefore(key2,insm);

deleteatbeginning();

deleteatend();

printf("Enter the key to delete after:");
scanf("%d",&key3);
deleteafter(key3);


getch();
}
