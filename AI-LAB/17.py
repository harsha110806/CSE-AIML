board = ["X", "O", "X",
         "O", "X", "-",
         "-", "-", "O"]

nodes = 0

def display():
    for i in range(0, 9, 3):
        print(board[i], board[i+1], board[i+2])
    print()

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


def alphabeta(alpha, beta, isMax):
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
                score = alphabeta(alpha, beta, False)
                board[i] = "-"

                best = max(best, score)
                alpha = max(alpha, best)

                if alpha >= beta:
                    break

        return best

    else:
        best = 100

        for i in range(9):
            if board[i] == "-":
                board[i] = "O"
                score = alphabeta(alpha, beta, True)
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


print("Initial Board:")
display()

# Alpha-Beta
best = -100
move = -1
nodes = 0

for i in range(9):
    if board[i] == "-":
        board[i] = "X"
        score = alphabeta(-100, 100, False)
        board[i] = "-"

        print("Position", i+1, "Value:", score)

        if score > best:
            best = score
            move = i

print("\nAlpha-Beta Result")
print("Best move:", move+1)
print("Best value:", best)
print("Nodes generated:", nodes)

# Plain Minimax
nodes = 0
best2 = -100
move2 = -1

for i in range(9):
    if board[i] == "-":
        board[i] = "X"
        score = minimax(False)
        board[i] = "-"

        if score > best2:
            best2 = score
            move2 = i

print("\nMinimax Result")
print("Best move:", move2+1)
print("Best value:", best2)
print("Nodes generated:", nodes)
