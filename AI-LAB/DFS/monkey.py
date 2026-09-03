start = ("door", "window", False)

banana = "middle"

stack = [start]
visited = set()

parent = {start: None}
action = {}

goal_state = None

while stack:

    state = stack.pop()

    if state in visited:
        continue

    visited.add(state)

    monkey, box, on_box = state

    # Goal check
    if on_box and box == banana:
        goal_state = state
        break

    next_states = []

    # Move to box
    if not on_box and monkey != box:
        next_states.append(
            ((box, box, False), "Move to Box")
        )

    # Push box under banana
    if monkey == box and not on_box and box != banana:
        next_states.append(
            ((banana, banana, False), "Push Box")
        )

    # Climb box
    if monkey == box and not on_box:
        next_states.append(
            ((monkey, box, True), "Climb onto Box")
        )

    for new_state, act in next_states:

        if new_state not in visited and new_state not in parent:

            parent[new_state] = state
            action[new_state] = act

            stack.append(new_state)


if goal_state:

    path = []

    while goal_state != start:

        path.append(action[goal_state])

        goal_state = parent[goal_state]

    path.reverse()

    for step in path:
        print(step)

    print("Grab Banana")

else:
    print("Goal not reached")