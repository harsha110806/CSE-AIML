grid = [
    [0, 0, 1, 0],
    [0, 1, 0, 0],
    [0, 0, 0, 1],
    [1, 0, 0, 0]
]

start = (0, 0)

rows = len(grid)
cols = len(grid[0])

stack = [start]
visited = set()

directions = [
    (1, 0),
    (-1, 0),
    (0, 1),
    (0, -1)
]

while stack:

    x, y = stack.pop()

    if (x, y) in visited:
        continue

    visited.add((x, y))

    for dx, dy in directions:

        nx = x + dx
        ny = y + dy

        if (0 <= nx < rows and
            0 <= ny < cols and
            grid[nx][ny] == 0 and
            (nx, ny) not in visited):

            stack.append((nx, ny))


print("Reachable cells:")

for cell in visited:
    print(cell)