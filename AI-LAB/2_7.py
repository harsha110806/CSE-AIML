
board = ["X", "X", "-", "O", "O", "-", "-", "-", "-"]

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

def minimax(isMax):
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

best = -100
move = -1

print("Values of all legal moves:")

for i in range(9):
    if board[i] == "-":
        board[i] = "X"
        score = minimax(False)
        board[i] = "-"

        print("Position", i+1, ":", score)

        if score > best:
            best = score
            move = i

print("Best move:", move+1)
print("Best value:", best)
