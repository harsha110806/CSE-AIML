import math

def floyd(graph, V):
    dist = [[math.inf]*V for _ in range(V)]
    
    # diagonal = 0
    for i in range(V):
        dist[i][i] = 0
    
    # fill edges
    for u in graph:
        for (v, w) in graph[u]:
            dist[u][v] = w   
    
    # main logic
    for k in range(V):
        for i in range(V):
            for j in range(V):
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
    
    return dist


graph = {
    0: [(1,3),(3,5)],
    1: [(0,2),(3,4)],
    2: [(1,6)],
    3: [(2,2)]
}

V = 4

result = floyd(graph, V)

print("Shortest distance matrix:")
for row in result:
    print(row)