#include <stdio.h>
#include <stdlib.h>

#define V 5
#define E 7

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    struct Edge* edge;
};

struct subset {
    int parent;
    int rank;
};

int find(struct subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int compare(const void* a, const void* b) {
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight > b1->weight;
}

void KruskalMST(struct Graph* graph) {
    int V = graph->V;
    struct Edge result[V];
    int e = 0; 
    int i = 0;

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compare);

    struct subset* subsets = (struct subset*)malloc(V * sizeof(struct subset));

    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < graph->E) {
        struct Edge next_edge = graph->edge[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    printf("Edge \tWeight\n");
    for (i = 0; i < e; ++i)
        printf("%d - %d \t%d \n", result[i].src, result[i].dest, result[i].weight);
}

int main() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;

    graph->edge = (struct Edge*)malloc(E * sizeof(struct Edge));

    // Graph edges
    graph->edge[0] = (struct Edge){0, 1, 2};
    graph->edge[1] = (struct Edge){0, 3, 6};
    graph->edge[2] = (struct Edge){1, 2, 3};
    graph->edge[3] = (struct Edge){1, 3, 8};
    graph->edge[4] = (struct Edge){1, 4, 5};
    graph->edge[5] = (struct Edge){2, 4, 7};
    graph->edge[6] = (struct Edge){3, 4, 9};

    KruskalMST(graph);

    return 0;
}
kruskals
