import random
import math

random.seed(2)

piles = [3,4,5]


def moves(state):

    result = []

    for i in range(3):
        for j in range(1,state[i]+1):
            result.append((i,j))

    return result


def winner(state):

    if state == [0,0,0]:
        return True

    return False


class Node:

    def __init__(self,state,parent=None,move=None):
        self.state = state[:]
        self.parent = parent
        self.move = move
        self.children = []
        self.visits = 0
        self.wins = 0


def mcts(root):

    for i in range(5000):

        node = root

        while len(node.children) > 0 and \
              len(node.children) == len(moves(node.state)):

            node = max(node.children,key=lambda x:
                x.wins/x.visits +
                2*math.sqrt(math.log(node.visits)/x.visits))

        available = moves(node.state)

        used = []

        for child in node.children:
            used.append(child.move)

        available = [x for x in available if x not in used]

        if len(available) > 0:

            move = random.choice(available)

            newstate = node.state[:]
            newstate[move[0]] -= move[1]

            child = Node(newstate,node,move)

            node.children.append(child)
            node = child

        state = node.state[:]

        while sum(state) != 0:

            move = random.choice(moves(state))

            state[move[0]] -= move[1]

        while node is not None:

            node.visits += 1
            node.wins += 1

            node = node.parent


root = Node(piles)

mcts(root)

print("Candidate moves:")

for child in root.children:
    print("Remove",child.move[1],
          "from pile",child.move[0]+1,
          "Visits:",child.visits)

best = max(root.children,key=lambda x:x.visits)

print("MCTS best move:")
print("Remove",best.move[1],
      "from pile",best.move[0]+1)

print("Nim-sum:",3 ^ 4 ^ 5)