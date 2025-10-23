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
    g->adj[v][u] = 1;
}

void DFSUtil(struct Graph *g, int v, int visited[]) {
    visited[v] = 1;
    printf("%d ", v);

    for(int i=0; i<g->vertices; i++) {
        if(g->adj[v][i] && !visited[i])
            DFSUtil(g, i, visited);
    }
}

void DFS(struct Graph *g, int start) {
    int visited[MAX] = {0};
    printf("DFS Traversal starting from vertex %d: ", start);
    DFSUtil(g, start, visited);
    printf("\n");
}

int main() {
    struct Graph g;
    initGraph(&g, 5);

    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 1, 4);

    DFS(&g, 0);

    return 0;
}
