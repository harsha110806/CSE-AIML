n = 8

board = [-1] * n
domains = [list(range(n)) for i in range(n)]

solutions = []
backtracks = 0


def safe(col, row):
    for c in range(col):
        r = board[c]

        if r == row:
            return False

        if abs(r - row) == abs(c - col):
            return False

    return True


def forward_check(col, row):
    for c in range(col + 1, n):
        for r in domains[c]:
            if r == row or abs(r - row) == abs(c - col):
                domains[c].remove(r)

        if len(domains[c]) == 0:
            return False

    return True


def solve(col):
    global backtracks

    if col == n:
        solutions.append(board[:])
        return

    old_domains = [d[:] for d in domains]

    for row in domains[col]:

        if safe(col, row):

            board[col] = row

            if forward_check(col, row):
                solve(col + 1)

            board[col] = -1

            for i in range(n):
                domains[i] = old_domains[i][:]

    if len(solutions) == 0:
        backtracks = backtracks + 1


solve(0)

print("First solution:")

for row in range(n):
    for col in range(n):
        if solutions[0][col] == row:
            print("Q", end=" ")
        else:
            print(".", end=" ")
    print()

print("Total solutions:", len(solutions))
print("Backtracks:", backtracks)