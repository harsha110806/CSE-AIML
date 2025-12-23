#include<stdio.h>
#include<malloc.h>
#include<stdio.h>

struct node
{
struct node *next;
struct node *prev;
int info;
};

struct node *head=NULL;

void create(int n)
{
struct node *temp;
struct node *newnode;
int i,info;
for(i=1;i<=n;i++)
{
newnode=(struct node *)malloc(sizeof(struct node));
printf("Enter the data:");
scanf("%d",&info);
newnode->info=info;
newnode->next=NULL;
newnode->prev=NULL;
if(head==NULL)
{
head=temp=newnode;
}
else
{
temp->next=newnode;
newnode->prev=temp;
temp=newnode;
}
}
}

void display()
{
struct node *temp=head;
while(temp!=NULL)
{
printf("%d <-> ",temp->info);
temp=temp->next;
}printf("NULL\n");
}

void insertatbeginning(int data)
{
struct node *newnode=(struct node *)malloc(sizeof(struct node));
newnode->info=data;
newnode->next=NULL;
newnode->prev=NULL;
if(head==NULL)
{
head=newnode;
display();
return;
}
newnode->next=head;
head->prev=newnode;
head=newnode;
display();
}

void insertionatend(int data)
{
struct node *temp=head,*newnode=(struct node *)malloc(sizeof(struct node));
newnode->info=data;
newnode->next=NULL;
newnode->prev=NULL;
if(head==NULL)
{
head=newnode;
display();
return;
}
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=newnode;
newnode->prev=temp;
display();
}

void insertafter(int key,int data)
{
struct node *temp,*newnode;
if(head==NULL)
{
printf("List is empty.\n");
return;
}
newnode=(struct node *)malloc(sizeof(struct node));
newnode->info=data;
temp=head;
while(temp!=NULL && temp->info!=key)
{
temp=temp->next;
}
if(temp==NULL)
{
printf("Key not found.\n");
return;
}
newnode->next=temp->next;
newnode->prev=temp;
if(temp->next!=NULL)
{
temp->next=newnode;
temp->next->prev=newnode;
}
display();
}

void insertbefore(int key,int data)
{
struct node *prev=NULL,*temp=head;
struct node *newnode=(struct node *)malloc(sizeof(struct node));
newnode->info=data;

if(head==NULL)
{
printf("List is empty.\n");
return;
}

if(head->info==key)
{
newnode->next=head;
head->prev=newnode;
head=newnode;
display();
return;
}

while(temp!=NULL && temp->info!=key)
{
prev=temp;
temp=temp->next;
}
if(temp==NULL)
{
printf("Key not found.\n");
free(newnode);
return;
}
prev->next=newnode;
newnode->prev=prev;
newnode->next=temp;
temp->prev=newnode;
display();
}

void deleteatbeginning()
{
struct node *del;
if(head==NULL)
{
printf("List is empty.\n");
return;
}
del=head;
head=head->next;
if(head!=NULL)
{
head->prev=NULL;
}
free(del);
display();
}

void deleteatend()
{
struct node *temp=head;
if(head==NULL)
{
printf("List is empty.\n");
return;
}
if(head->next==NULL)
{
free(head);
head=NULL;
printf("Node deleted(only one)");
return;
}
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->prev->next=NULL;
free(temp);
display();
}

void deleteafter(int key)
{
struct node *del=NULL,*temp=head;
if(head==NULL)
{
printf("List is empty.\n");
return;
}
while(temp!=NULL&& temp->info!=key)
{
temp=temp->next;
}

if(temp==NULL)
{
printf("Key not found.\n");
return;
}

if(temp->next==NULL)
{
printf("No node to delete.\n");
return;
}
del=temp->next;
temp->next=del->next;
if(del->next!=NULL){
del->next->prev=temp;
}
free(del);
display();
}

void deletebefore(int key)
{
struct node *del,*temp=head;
if(head==NULL)
{
printf("List is empty.\n");
return;
}
if(head->info==key)
{
printf("No node to delete before.\n");
return;
}
while(temp!=NULL && temp->info!=key)
{
temp=temp->next;
}

if(temp==NULL)
{
printf("Key not found.\n");
return;
}

del=temp->prev;
if(del==head)
{
head=temp;
head->prev=NULL;
free(del);
}
else
{
temp->prev=del->prev;
del->prev->next=temp;
free(del);
}
display();
}



void main()
{
    int choice, n, data, key;
    clrscr();
    while(1)
    {
        printf("\n--- Menu ---\n");
        printf("1. Create List\n");
        printf("2. Display\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Insert After\n");
        printf("6. Insert Before\n");
        printf("7. Delete at Beginning\n");
        printf("8. Delete at End\n");
        printf("9. Delete After\n");
        printf("10. Delete Before\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d",&n);
                create(n);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d",&data);
                insertatbeginning(data);
                break;
            case 4:
                printf("Enter data: ");
                scanf("%d",&data);
                insertionatend(data);
                break;
            case 5:
                printf("Enter key and data: ");
                scanf("%d%d",&key,&data);
                insertafter(key,data);
                break;
            case 6:
                printf("Enter key and data: ");
                scanf("%d%d",&key,&data);
                insertbefore(key,data);
                break;
            case 7:
                deleteatbeginning();
                break;
            case 8:
                deleteatend();
                break;
            case 9:
                printf("Enter key: ");
                scanf("%d",&key);
                deleteafter(key);
                break;
            case 10:
                printf("Enter key: ");
                scanf("%d",&key);
                deletebefore(key);
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    getch();
}

