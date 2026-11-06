import random

random.seed(42)

n = 8

board = [0,0,0,0,0,0,0,0]


def conflicts(col, row):

    count = 0

    for c in range(n):

        if c == col:
            continue

        r = board[c]

        if r == row:
            count = count + 1

        if abs(r - row) == abs(c - col):
            count = count + 1

    return count


def total_conflicts():

    total = 0

    for c in range(n):
        total = total + conflicts(c, board[c])

    return total // 2


for step in range(1000):

    if total_conflicts() == 0:
        break

    conflicted = []

    for col in range(n):
        if conflicts(col, board[col]) > 0:
            conflicted.append(col)

    col = random.choice(conflicted)

    values = []

    minimum = 100

    for row in range(n):

        c = conflicts(col, row)

        if c < minimum:
            minimum = c
            values = [row]

        elif c == minimum:
            values.append(row)

    board[col] = random.choice(values)


print("Steps:", step)

print("Board:")

for row in range(n):

    for col in range(n):

        if board[col] == row:
            print("Q", end=" ")
        else:
            print(".", end=" ")

    print()