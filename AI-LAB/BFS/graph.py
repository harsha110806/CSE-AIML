from collections import deque

graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': [],
    'E': ['F'],
    'F': []
}

start = 'A'
goal = 'F'

queue = deque([start])
visited = {start}
parent = {start: None}

while queue:
    node = queue.popleft()

    if node == goal:
        break

    for neighbor in graph[node]:

        if neighbor not in visited:
            visited.add(neighbor)
            parent[neighbor] = node
            queue.append(neighbor)

if goal in parent:

    path = []

    while goal is not None:
        path.append(goal)
        goal = parent[goal]

    path.reverse()

    print("Shortest Path:")
    print(" -> ".join(path))

else:
    print("Path not found")