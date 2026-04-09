import math

def bellman_ford(graph,V,source):
    dist=[math.inf]*V
    dist[source]=0
    
    for i in range(V):
        for u in graph:
            for (v,w) in graph[u]:
                if dist[u]+w< dist[v]:
                    dist[v]=dist[u]+w
    
    for u in graph:
        for (v,w) in graph[u]:
            if dist[u]+w<dist[v]:
                print("Negative Cycle detected.\n")
                return None,None
    return dist
graph = {
    0: [(1,6),(2,7)],
    1: [(2,8),(3,5),(4,4)],
    2: [(3,3),(4,9)],
    3: [(1,2)],
    4: [(0,2),(3,7)]
}
Source=0
V=5
dist=bellman_ford(graph,V,Source)
print("Distances:",dist)





