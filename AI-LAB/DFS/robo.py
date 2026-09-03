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

stack = [start]
visited = set()

parent = {start: None}

directions = [
    (1, 0),
    (-1, 0),
    (0, 1),
    (0, -1)
]

while stack:

    current = stack.pop()

    if current in visited:
        continue

    visited.add(current)

    if current == target:
        break

    x, y = current

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
    print("Target not reachable")