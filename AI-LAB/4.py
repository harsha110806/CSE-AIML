colors = ["Red", "Green", "Blue"]

regions = ["WA", "NT", "SA", "Q", "NSW", "V", "T"]

neighbors = {
    "WA": ["NT", "SA"],
    "NT": ["WA", "SA", "Q"],
    "SA": ["WA", "NT", "Q", "NSW", "V"],
    "Q": ["NT", "SA", "NSW"],
    "NSW": ["SA", "Q", "V"],
    "V": ["SA", "NSW"],
    "T": []
}

assignment = {}
backtracks = 0


def safe(region, color):
    for n in neighbors[region]:
        if n in assignment and assignment[n] == color:
            return False
    return True


def backtracking(index):
    global backtracks

    if index == len(regions):
        return True

    region = regions[index]

    for color in colors:
        if safe(region, color):
            assignment[region] = color

            if backtracking(index + 1):
                return True

            del assignment[region]

    backtracks = backtracks + 1
    return False


backtracking(0)

print("Assignment:")
for region in regions:
    print(region, ":", assignment[region])

print("Backtracks:", backtracks)