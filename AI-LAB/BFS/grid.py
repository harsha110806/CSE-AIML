from collections import deque

grid = [
    [0, 0, 1, 0],
    [1, 0, 0, 0],
    [0, 0, 1, 0],
    [0, 0, 0, 0]
]

start = (0, 0)
goal = (3, 3)

rows = len(grid)
cols = len(grid[0])

queue = deque([start])
visited = {start}
parent = {start: None}

directions = [
    (1, 0),
    (-1, 0),
    (0, 1),
    (0, -1)
]

while queue:
    current = queue.popleft()

    if current == goal:
        break

    x, y = current

    for dx, dy in directions:
        nx = x + dx
        ny = y + dy

        if (0 <= nx < rows and
            0 <= ny < cols and
            grid[nx][ny] == 0 and
            (nx, ny) not in visited):

            visited.add((nx, ny))
            parent[(nx, ny)] = current
            queue.append((nx, ny))

if goal in parent:
    path = []

    while goal is not None:
        path.append(goal)
        goal = parent[goal]

    path.reverse()

    print("Shortest Path:")
    for cell in path:
        print(cell)

else:
    print("Path not found")