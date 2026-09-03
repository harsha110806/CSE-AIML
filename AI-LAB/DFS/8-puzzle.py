start = (1, 2, 3,
         4, 0, 6,
         7, 5, 8)

goal = (1, 2, 3,
        4, 5, 6,
        7, 8, 0)

stack = [start]
visited = set()
parent = {start: None}

found = False

while stack:

    state = stack.pop()

    if state in visited:
        continue

    visited.add(state)

    if state == goal:
        found = True
        break

    zero = state.index(0)

    row = zero // 3
    col = zero % 3

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

        if new_state not in visited and new_state not in parent:
            parent[new_state] = state
            stack.append(new_state)

if found:

    path = []

    while goal is not None:
        path.append(goal)
        goal = parent[goal]

    path.reverse()

    for state in path:
        print(state)

else:
    print("Goal not found")
