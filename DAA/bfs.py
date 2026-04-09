from collections import deque

def bfs(graph, start):
    visited = set()
    queue = deque()

    queue.append(start)
    visited.add(start)

    while queue:
        node = queue.popleft()
        print(node, end=" ")

        for neighbor in graph[node]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)


# Graph representation (Adjacency List)
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

# Start BFS
bfs(graph, 0)