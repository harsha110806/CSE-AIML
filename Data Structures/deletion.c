#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};
struct node *head = NULL;

void create(int n) {
    int i, info;
    struct node *newnode,*temp;
    for (i = 1; i <= n; i++) {
        newnode = malloc(sizeof(struct node));
        printf("Enter the info in node %d: ", i);
        scanf("%d", &info);
        newnode->info=info;
        newnode->next=NULL;
        if (head==NULL)
        {
        	head=temp=newnode;
		}
		else
		{
			temp->next=newnode;
			temp=newnode;
		}
//        newnode->info = info;
//        newnode->next = head;
//        head = newnode;
    }
}

void display() {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    printf("Deleted %d from beginning\n", temp->info);
    free(temp);
}

void deleteAtEnd() 
    {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == NULL) {
        printf("Deleted %d from end\n", head->info);
        free(head);
        head = NULL;
        return;
    }

    struct node *temp = head, *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    printf("Deleted %d from end\n", temp->info);
    prev->next = NULL;
    free(temp);
}
int main()
{
	int n;
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	create(n);
	display();
	deleteAtBeginning();
	deleteAtEnd();
	display();
	
	
}
