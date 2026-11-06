grid = [
    [5,3,0,0,7,0,0,0,0],
    [6,0,0,1,9,5,0,0,0],
    [0,9,8,0,0,0,0,6,0],
    [8,0,0,0,6,0,0,0,3],
    [4,0,0,8,0,3,0,0,1],
    [7,0,0,0,2,0,0,0,6],
    [0,6,0,0,0,0,2,8,0],
    [0,0,0,4,1,9,0,0,5],
    [0,0,0,0,8,0,0,7,9]
]

domains = {}

for r in range(9):
    for c in range(9):

        if grid[r][c] != 0:
            domains[(r,c)] = [grid[r][c]]
        else:
            domains[(r,c)] = list(range(1,10))


def neighbors(cell):
    r, c = cell
    result = []

    for i in range(9):

        if i != c:
            result.append((r,i))

        if i != r:
            result.append((i,c))

    sr = (r // 3) * 3
    sc = (c // 3) * 3

    for i in range(sr, sr+3):
        for j in range(sc, sc+3):
            if (i,j) != cell:
                result.append((i,j))

    return list(set(result))


def revise(x, y):
    changed = False

    for a in domains[x][:]:

        found = False

        for b in domains[y]:

            if a != b:
                found = True
                break

        if not found:
            domains[x].remove(a)
            changed = True

    return changed


def ac3():

    queue = []

    for x in domains:
        for y in neighbors(x):
            queue.append((x,y))

    while queue:

        x,y = queue.pop(0)

        if revise(x,y):

            if len(domains[x]) == 0:
                return False

            for z in neighbors(x):
                if z != y:
                    queue.append((z,x))

    return True


def backtracking():

    if not ac3():
        return False

    complete = True

    for cell in domains:
        if len(domains[cell]) > 1:
            complete = False
            break

    if complete:
        return True

    cell = None
    smallest = 10

    for x in domains:
        if 1 < len(domains[x]) < smallest:
            smallest = len(domains[x])
            cell = x

    old_domains = {x: domains[x][:] for x in domains}

    for value in domains[cell]:

        domains[cell] = [value]

        if backtracking():
            return True

        for x in old_domains:
            domains[x] = old_domains[x][:]

    return False


backtracking()

print("Sudoku solution:")

for r in range(9):
    for c in range(9):
        print(domains[(r,c)][0], end=" ")
    print()