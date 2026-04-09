def dfs(graph, node, visited):
    visited.add(node)
    print(node, end=" ")

    for neighbor in graph[node]:
        if neighbor not in visited:
            dfs(graph, neighbor, visited)


graph = {
    0: [1,2],
    1: [0,3,4],
    2: [0,5,6],
    3: [1,7],
    4: [1,7],
    5: [2,7],
    6: [2,7],
    7: [3,4,5,6]
}

visited = set()
dfs(graph, 0, visited)