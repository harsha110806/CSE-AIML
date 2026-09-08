#include <stdio.h>
#include <stdlib.h>

#define MAX 20

struct node
{
int vertex;
struct node *next;
};

struct node *graph[MAX];

int adj[MAX][MAX];
int visit[MAX];
int q[MAX];
int front = -1, rear = -1;
int vertices;

struct node* createNode(int v)
{
struct node *newnode = (struct node *)malloc(sizeof(struct node));
newnode->vertex = v;
newnode->next = NULL;
return newnode;
}

void createList()
{
int i, j;

for(i = 0; i < vertices; i++)
graph[i] = NULL;

for(i = 0; i < vertices; i++)
{
struct node *last = NULL;

for(j = 0; j < vertices; j++)
{
if(adj[i][j] == 1)
{
struct node *newnode = createNode(j);

if(graph[i] == NULL)
{
graph[i] = newnode;
last = newnode;
}
else
{
last->next = newnode;
last = newnode;
}
}
}
}
}

void printMatrix()
{
int i, j;

printf("\nAdjacency Matrix:\n");

for(i = 0; i < vertices; i++)
{
for(j = 0; j < vertices; j++)
{
printf("%d ", adj[i][j]);
}
printf("\n");
}
}

void printList()
{
int i;
struct node *temp;

printf("\nAdjacency List:\n");

for(i = 0; i < vertices; i++)
{
printf("%d -> ", i);

temp = graph[i];

while(temp != NULL)
{
printf("%d ", temp->vertex);
temp = temp->next;
}

printf("\n");
}
}

void bfs(int source)
{
int i, current;

for(i = 0; i < vertices; i++)
visit[i] = 0;

front = rear = -1;

visit[source] = 1;
q[++rear] = source;

printf("BFS Traversal: ");

while(front != rear)
{
current = q[++front];
printf("%d ", current);

for(i = 0; i < vertices; i++)
{
if(adj[current][i] == 1 && visit[i] == 0)
{
visit[i] = 1;
q[++rear] = i;
}
}
}

printf("\n");
}

void dfs(int source)
{
int i;

visit[source] = 1;
printf("%d ", source);

for(i = 0; i < vertices; i++)
{
if(adj[source][i] == 1 && visit[i] == 0)
{
dfs(i);
}
}
}

int main()
{
int i, j;
int choice, source;

printf("Enter number of vertices: ");
scanf("%d", &vertices);

printf("Enter adjacency matrix:\n");

for(i = 0; i < vertices; i++)
{
for(j = 0; j < vertices; j++)
{
scanf("%d", &adj[i][j]);
}
}

createList();

while(1)
{
printf("\n----- GRAPH MENU -----\n");
printf("1. BFS Traversal\n");
printf("2. DFS Traversal\n");
printf("3. Display Adjacency Matrix\n");
printf("4. Display Adjacency List\n");
printf("5. Exit\n");

printf("Enter your choice: ");
scanf("%d", &choice);

switch(choice)
{
case 1:
printf("Enter starting vertex: ");
scanf("%d", &source);
bfs(source);
break;

case 2:
for(i = 0; i < vertices; i++)
visit[i] = 0;

printf("Enter starting vertex: ");
scanf("%d", &source);

printf("DFS Traversal: ");
dfs(source);
printf("\n");
break;

case 3:
printMatrix();
break;

case 4:
printList();
break;

case 5:
printf("Program terminated.\n");
return 0;

default:
printf("Invalid choice.\n");
}
}

return 0;
}
