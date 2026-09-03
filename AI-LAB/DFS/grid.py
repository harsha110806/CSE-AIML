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

stack = [start]
visited = set()

parent = {start: None}

while stack:

    current = stack.pop()

    if current in visited:
        continue

    visited.add(current)

    if current == goal:
        break

    x, y = current

    directions = [
        (1, 0),
        (-1, 0),
        (0, 1),
        (0, -1)
    ]

    for dx, dy in directions:

        nx = x + dx
        ny = y + dy

        if (0 <= nx < rows and
            0 <= ny < cols and
            grid[nx][ny] == 0 and
            (nx, ny) not in visited and
            (nx, ny) not in parent):

            parent[(nx, ny)] = current

            stack.append((nx, ny))


if goal in parent:

    path = []

    while goal is not None:

        path.append(goal)

        goal = parent[goal]

    path.reverse()

    print("Path:")

    for cell in path:
        print(cell)

else:
    print("Path not found")