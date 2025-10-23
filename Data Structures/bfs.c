#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Graph {
    int vertices;
    int adj[MAX][MAX];
};

void initGraph(struct Graph *g, int v) {
    g->vertices = v;
    for(int i=0;i<v;i++)
        for(int j=0;j<v;j++)
            g->adj[i][j] = 0;
}

void addEdge(struct Graph *g, int u, int v) {
    g->adj[u][v] = 1;
    g->adj[v][u] = 1;  // for undirected graph
}

void BFS(struct Graph *g, int start) {
    int visited[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Traversal starting from vertex %d: ", start);

    while(front != rear) {
        int u = queue[front++];  // dequeue
        printf("%d ", u);

        for(int v=0; v<g->vertices; v++) {
            if(g->adj[u][v] && !visited[v]) {
                visited[v] = 1;
                queue[rear++] = v; // enqueue
            }
        }
    }
    printf("\n");
}

int main() {
    struct Graph g;
    initGraph(&g, 5);

    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 1, 4);

    BFS(&g, 0);

    return 0;
}
