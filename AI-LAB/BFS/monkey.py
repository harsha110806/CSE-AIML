from collections import deque

start = ("door", "window", False)
goal = ("middle", "middle", True)

banana = "middle"

queue = deque([start])
visited = {start}
parent = {start: None}
action = {}

while queue:
    state = queue.popleft()

    monkey, box, on_box = state

    if on_box and box == banana:
        goal_state = state
        break

    next_states = []

    # Move monkey to box
    if not on_box and monkey != box:
        next_states.append((box, box, False, "Move to Box"))

    # Push box under banana
    if monkey == box and not on_box and box != banana:
        next_states.append((banana, banana, False,
                            "Push Box under Banana"))

    # Climb box
    if monkey == box and not on_box:
        next_states.append((monkey, box, True,
                            "Climb onto Box"))

    for m, b, o, act in next_states:
        new_state = (m, b, o)

        if new_state not in visited:
            visited.add(new_state)
            parent[new_state] = state
            action[new_state] = act
            queue.append(new_state)

path = []

while goal_state != start:
    path.append(action[goal_state])
    goal_state = parent[goal_state]

path.reverse()

for step in path:
    print(step)

print("Grab Banana")