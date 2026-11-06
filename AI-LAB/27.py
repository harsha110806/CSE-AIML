
board = ["-"] * 9
nodes = 0

def check():
    win = [(0,1,2), (3,4,5), (6,7,8),
           (0,3,6), (1,4,7), (2,5,8),
           (0,4,8), (2,4,6)]

    for a,b,c in win:
        if board[a] == board[b] == board[c] != "-":
            return board[a]

    if "-" not in board:
        return "Draw"

    return None


def alphabeta(alpha, beta, isMax, order):
    global nodes
    nodes += 1

    result = check()

    if result == "X":
        return 1
    if result == "O":
        return -1
    if result == "Draw":
        return 0

    if isMax:
        best = -100

        for i in order:
            if board[i] == "-":
                board[i] = "X"
                score = alphabeta(alpha, beta, False, order)
                board[i] = "-"

                best = max(best, score)
                alpha = max(alpha, best)

                if alpha >= beta:
                    break

        return best

    else:
        best = 100

        for i in order:
            if board[i] == "-":
                board[i] = "O"
                score = alphabeta(alpha, beta, True, order)
                board[i] = "-"

                best = min(best, score)
                beta = min(beta, best)

                if alpha >= beta:
                    break

        return best


def minimax(isMax):
    global nodes
    nodes += 1

    result = check()

    if result == "X":
        return 1
    if result == "O":
        return -1
    if result == "Draw":
        return 0

    if isMax:
        best = -100

        for i in range(9):
            if board[i] == "-":
                board[i] = "X"
                score = minimax(False)
                board[i] = "-"
                best = max(best, score)

        return best

    else:
        best = 100

        for i in range(9):
            if board[i] == "-":
                board[i] = "O"
                score = minimax(True)
                board[i] = "-"
                best = min(best, score)

        return best


# Order 1: Row by row
order1 = [0,1,2,3,4,5,6,7,8]

best = -100
move = -1
nodes = 0

for i in order1:
    if board[i] == "-":
        board[i] = "X"
        score = alphabeta(-100, 100, False, order1)
        board[i] = "-"

        if score > best:
            best = score
            move = i

print("Row by row ordering")
print("Best move:", move+1)
print("Best value:", best)
print("Nodes generated:", nodes)


# Order 2: Centre, corners, edges
order2 = [4,0,2,6,8,1,3,5,7]

best = -100
move = -1
nodes = 0

for i in order2:
    if board[i] == "-":
        board[i] = "X"
        score = alphabeta(-100, 100, False, order2)
        board[i] = "-"

        if score > best:
            best = score
            move = i

print("\nCentre first ordering")
print("Best move:", move+1)
print("Best value:", best)
print("Nodes generated:", nodes)


# Plain Minimax comparison
best = -100
move = -1
nodes = 0

for i in range(9):
    if board[i] == "-":
        board[i] = "X"
        score = minimax(False)
        board[i] = "-"

        if score > best:
            best = score
            move = i

print("\nPlain Minimax")
print("Best move:", move+1)
print("Best value:", best)
print("Nodes generated:", nodes)
