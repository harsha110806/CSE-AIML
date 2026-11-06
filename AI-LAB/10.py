import math

N = 20
C = 2

children = [
    ["A",6,8],
    ["B",5,7],
    ["C",2,5]
]

best = ""
best_value = -1

for name,wins,visits in children:

    ucb = wins/visits + C * math.sqrt(math.log(N)/visits)

    print(name, "UCB1 =", round(ucb,4))

    if ucb > best_value:
        best_value = ucb
        best = name

print("Selected child:", best)