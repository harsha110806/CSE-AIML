from collections import deque

grid = [
    [0, 0, 0, 1],
    [1, 1, 0, 0],
    [0, 0, 0, 0],
    [0, 1, 1, 0]
]

start = (0, 0)
target = (3, 3)

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
    position = queue.popleft()

    if position == target:
        break

    x, y = position

    for dx, dy in directions:

        nx = x + dx
        ny = y + dy

        if (0 <= nx < rows and
            0 <= ny < cols and
            grid[nx][ny] == 0 and
            (nx, ny) not in visited):

            visited.add((nx, ny))
            parent[(nx, ny)] = position
            queue.append((nx, ny))

if target in parent:

    path = []

    while target is not None:
        path.append(target)
        target = parent[target]

    path.reverse()

    print("Robot Path:")

    for position in path:
        print(position)

else:
    print("Target cannot be reached")