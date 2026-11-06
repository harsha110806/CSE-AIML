
board = ["-"] * 9
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

def computer():
    global nodes

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

    board[move] = "X"

    print("Computer chose position:", move + 1)
    print("Minimax value:", best)
    print("Nodes generated:", nodes)

def human():
    pos = int(input("Enter position (1-9): ")) - 1

    if pos >= 0 and pos < 9 and board[pos] == "-":
        board[pos] = "O"
    else:
        print("Invalid position! Try again.")
        human()

while True:
    computer()
    display()

    if check() != None:
        print("Result:", check())
        break

    human()
    display()

    if check() != None:
        print("Result:", check())
        break
