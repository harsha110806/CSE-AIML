import random
import math

random.seed(42)

board = ["X","X","-",
         "O","O","-",
         "-","-","-"]

wins = [(0,1,2),(3,4,5),(6,7,8),
        (0,3,6),(1,4,7),(2,5,8),
        (0,4,8),(2,4,6)]

class Node:
    def __init__(self, board, player, parent=None, move=None):
        self.board = board[:]
        self.player = player
        self.parent = parent
        self.move = move
        self.children = []
        self.visits = 0
        self.score = 0


def check(board):
    for a,b,c in wins:
        if board[a] != "-" and board[a] == board[b] == board[c]:
            return board[a]

    if "-" not in board:
        return "Draw"

    return None


def other(player):
    if player == "X":
        return "O"
    return "X"


def mcts(root, iterations):

    for i in range(iterations):

        node = root

        while len(node.children) > 0 and \
              len(node.children) == len([x for x in node.board if x == "-"]):

            node = max(node.children, key=lambda x:
                x.score/x.visits +
                2 * math.sqrt(math.log(node.visits)/x.visits))

        moves = []

        for i in range(9):
            if node.board[i] == "-":
                moves.append(i)

        if len(moves) > len(node.children):

            used = []

            for child in node.children:
                used.append(child.move)

            available = [x for x in moves if x not in used]

            move = random.choice(available)

            newboard = node.board[:]
            newboard[move] = node.player

            child = Node(
                newboard,
                other(node.player),
                node,
                move
            )

            node.children.append(child)
            node = child

        board2 = node.board[:]
        player = node.player

        while check(board2) is None:

            moves = []

            for i in range(9):
                if board2[i] == "-":
                    moves.append(i)

            move = random.choice(moves)
            board2[move] = player
            player = other(player)

        result = check(board2)

        while node is not None:

            node.visits += 1

            if result == "X":
                node.score += 1
            elif result == "Draw":
                node.score += 0.5

            node = node.parent


root = Node(board, "X")

mcts(root, 1000)

print("Root child statistics:")

for child in root.children:
    print("Move:", child.move,
          "Visits:", child.visits,
          "Win Rate:", round(child.score/child.visits,4))

best = max(root.children, key=lambda x: x.visits)

print("Selected move:", best.move)