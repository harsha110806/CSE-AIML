
tree = [[3, 12, 8],
        [2, 4, 6],
        [14, 5, 2]]

def alphabeta(node, alpha, beta, isMax, name):

    if type(node) == int:
        return node

    if isMax:
        best = -100

        for i in range(len(node)):
            score = alphabeta(node[i], alpha, beta, False,
                              chr(ord(name) + i))

            best = max(best, score)
            alpha = max(alpha, best)

            if alpha >= beta:
                print("Pruned at", name, ":", node[i+1:])
                break

        print(name, "MAX value:", best, "Alpha:", alpha, "Beta:", beta)
        return best

    else:
        best = 100

        for i in range(len(node)):
            score = alphabeta(node[i], alpha, beta, True,
                              name)

            best = min(best, score)
            beta = min(beta, best)

            if alpha >= beta:
                print("Pruned at", name, ":", node[i+1:])
                break

        print(name, "MIN value:", best, "Alpha:", alpha, "Beta:", beta)
        return best

result = alphabeta(tree, -100, 100, True, "A")

print("Minimax value:", result)
