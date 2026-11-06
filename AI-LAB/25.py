import random
import math

random.seed(42)

wins = [(0,1,2),(3,4,5),(6,7,8),
        (0,3,6),(1,4,7),(2,5,8),
        (0,4,8),(2,4,6)]


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


def moves(board):

    result = []

    for i in range(9):
        if board[i] == "-":
            result.append(i)

    return result


class Node:

    def __init__(self, board, player, parent=None, move=None):

        self.board = board[:]
        self.player = player
        self.parent = parent
        self.move = move
        self.children = []
        self.visits = 0
        self.wins = 0


def select(node):

    best = None
    best_value = -1000

    for child in node.children:

        if child.visits == 0:
            return child

        value = child.wins / child.visits + \
                2 * math.sqrt(math.log(node.visits) / child.visits)

        if value > best_value:
            best_value = value
            best = child

    return best


def mcts(board, player):

    root = Node(board, player)

    for i in range(200):

        node = root

        # Selection
        while len(node.children) > 0 and \
              len(node.children) == len(moves(node.board)):

            node = select(node)

        # Expansion
        available = moves(node.board)

        used = []

        for child in node.children:
            used.append(child.move)

        available = [x for x in available if x not in used]

        if len(available) > 0:

            move = random.choice(available)

            new_board = node.board[:]
            new_board[move] = node.player

            child = Node(
                new_board,
                other(node.player),
                node,
                move
            )

            node.children.append(child)
            node = child

        # Simulation
        board2 = node.board[:]
        player2 = node.player

        while check(board2) is None:

            move = random.choice(moves(board2))

            board2[move] = player2
            player2 = other(player2)

        result = check(board2)

        # Backpropagation
        while node is not None:

            node.visits += 1

            if result == "X":
                node.wins += 1

            node = node.parent

    return max(root.children, key=lambda x: x.visits).move


def play_game(mcts_player):

    board = ["-"] * 9
    player = "X"

    while True:

        result = check(board)

        if result is not None:
            return result

        if player == mcts_player:

            move = mcts(board, player)

        else:

            move = random.choice(moves(board))

        board[move] = player

        player = other(player)


def play_games(mcts_first):

    wins_count = 0
    draws = 0
    losses = 0

    if mcts_first:
        mcts_player = "X"
    else:
        mcts_player = "O"

    for i in range(20):

        result = play_game(mcts_player)

        if result == mcts_player:
            wins_count += 1

        elif result == "Draw":
            draws += 1

        else:
            losses += 1

    return wins_count, draws, losses


w1, d1, l1 = play_games(True)

w2, d2, l2 = play_games(False)

print("MCTS First")
print("Wins:", w1)
print("Draws:", d1)
print("Losses:", l1)

print()

print("MCTS Second")
print("Wins:", w2)
print("Draws:", d2)
print("Losses:", l2)