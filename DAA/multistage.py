import math

def multistage(graph,source,destination):
    n=len(graph)
    cost=[math.inf]*n
    path=[-1]*n
    cost[destination]=0
    
    for u in range(n-1,-1,-1):
        for (v,w) in graph[u]:
            if cost[v]+w<cost[u]:
                cost[u]=cost[v]+w
                path[u]=v
    current=source
    result_path=[]
    
    while current!=-1:
        result_path.append(current)
        current=path[current]
    
    return cost[source],result_path

graph = {
    0: [(1,3),(3,5)],
    1: [(0,2),(3,4)],
    2: [(1,6)],
    3: [(2,2)]
}

cost,path=multistage(graph,0,3)
print(cost,path)