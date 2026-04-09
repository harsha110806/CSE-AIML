import math

def assignment(cost, n, worker, assigned, current_cost):
    global min_cost, best

    # If all workers assigned
    if worker == n:
        if current_cost < min_cost:
            min_cost = current_cost
            best = assigned.copy()
        return

    # Try assigning each job
    for j in range(n):
        if j not in assigned:
            new_cost = current_cost + cost[worker][j]

            # 🔥 BOUND (PRUNING)
            if new_cost < min_cost:
                assigned.append(j)
                assignment(cost, n, worker+1, assigned, new_cost)
                assigned.pop()   # backtrack


# Input cost matrix
cost = [
    [9, 2, 7, 8],
    [6, 4, 3, 7],
    [5, 8, 1, 8],
    [7, 6, 9, 4]
]
min_cost = math.inf
best = []

assignment(cost, len(cost), 0, [], 0)

print("Minimum Cost:", min_cost)
print("Assignment (worker → job):", best)
