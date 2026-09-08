#include<stdio.h>
#define MAX 10

int front=-1;
int rear=-1;
int q[MAX];

void enque(int val)
{
if(rear==MAX-1)
{
printf("Queue is full.\n");
return;
}

if(rear==-1 && front==-1)
{
rear=front=0;
}
else
{
rear++;
}
q[rear]=val;
}

void deque()
{
int val;
if(front==-1)
{
printf("Underflow.\n");
return;
}

val=q[front];

if(front==rear)
{
front=rear=-1;
}
else
{
front++;
}
printf("Deleted element:%d",val);
}

void count()
{
if(front==-1)
{
printf("Underflow.\n");
return;
}
int count=0,i=front;
while(i<=rear)
{
count++;
i++;
}
printf("%d",count);
}

void print()
{
if(front==-1)
{
printf("Underflow.\n");
return;
}
int i=front;
while(i<=rear)
{
printf("%d ",q[i]);
i++;
}
printf("\n");
}

int main()
{
int choice, val;

while(1)
{
printf("\n-----QUEUE USING ARRAY-----\n");
printf("1. Enqueue\n");
printf("2. Dequeue\n");
printf("3. Count\n");
printf("4. Display\n");
printf("5. Exit\n");

printf("Enter your choice: ");
scanf("%d", &choice);

switch(choice)
{
case 1:
printf("Enter value: ");
scanf("%d", &val);
enque(val);
break;

case 2:
deque();
break;

case 3:
count();
break;

case 4:
print();
break;

case 5:
printf("Program terminated.\n");
return 0;

default:
printf("Invalid Choice.\n");
}
}
}
