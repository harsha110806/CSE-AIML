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

stack = [start]

visited = set()

parent = {start: None}

while stack:

    node = stack.pop()

    if node in visited:
        continue

    visited.add(node)

    if node == goal:
        break

    for neighbor in graph[node]:

        if neighbor not in visited and neighbor not in parent:

            parent[neighbor] = node

            stack.append(neighbor)


if goal in parent:

    path = []

    while goal is not None:

        path.append(goal)

        goal = parent[goal]

    path.reverse()

    print("Path:")

    print(" -> ".join(path))

else:
    print("Path not found")