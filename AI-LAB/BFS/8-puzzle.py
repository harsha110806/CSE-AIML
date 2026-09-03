from collections import deque

start = (1, 2, 3,
         4, 0, 6,
         7, 5, 8)

goal = (1, 2, 3,
        4, 5, 6,
        7, 8, 0)

queue = deque([start])
visited = {start}
parent = {start: None}

while queue:
    state = queue.popleft()

    if state == goal:
        break

    zero = state.index(0)
    row, col = zero // 3, zero % 3

    moves = []

    if row > 0:
        moves.append(zero - 3)
    if row < 2:
        moves.append(zero + 3)
    if col > 0:
        moves.append(zero - 1)
    if col < 2:
        moves.append(zero + 1)

    for move in moves:
        new_state = list(state)

        new_state[zero], new_state[move] = \
            new_state[move], new_state[zero]

        new_state = tuple(new_state)

        if new_state not in visited:
            visited.add(new_state)
            parent[new_state] = state
            queue.append(new_state)

path = []

while goal is not None:
    path.append(goal)
    goal = parent[goal]

path.reverse()

for state in path:
    print(state)
