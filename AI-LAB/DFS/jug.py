jug1 = int(input("Enter capacity of Jug 1: "))
jug2 = int(input("Enter capacity of Jug 2: "))
goal = int(input("Enter goal amount: "))

stack = [(0, 0)]
visited = set()

parent = {(0, 0): None}
goal_state = None

while stack:

    state = stack.pop()

    if state in visited:
        continue

    visited.add(state)

    if state[0] == goal:
        goal_state = state
        break

    x, y = state

    next_states = []

    # Fill Jug 1
    next_states.append((jug1, y))

    # Fill Jug 2
    next_states.append((x, jug2))

    # Empty Jug 1
    next_states.append((0, y))

    # Empty Jug 2
    next_states.append((x, 0))

    # Pour Jug 1 -> Jug 2
    transfer = min(x, jug2 - y)
    next_states.append((x - transfer, y + transfer))

    # Pour Jug 2 -> Jug 1
    transfer = min(y, jug1 - x)
    next_states.append((x + transfer, y - transfer))

    for new_state in next_states:

        if new_state not in visited and new_state not in parent:

            parent[new_state] = state

            stack.append(new_state)


if goal_state:

    path = []

    while goal_state is not None:

        path.append(goal_state)

        goal_state = parent[goal_state]

    path.reverse()

    for state in path:
        print(state)

    print("\nGoal Reached")

else:
    print("Goal cannot be reached")