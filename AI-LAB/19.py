letters = ["S", "E", "N", "D", "M", "O", "R", "Y"]

assignment = {}
used = set()


def check():

    S = assignment["S"]
    E = assignment["E"]
    N = assignment["N"]
    D = assignment["D"]

    M = assignment["M"]
    O = assignment["O"]
    R = assignment["R"]
    Y = assignment["Y"]

    SEND = 1000*S + 100*E + 10*N + D
    MORE = 1000*M + 100*O + 10*R + E
    MONEY = 10000*M + 1000*O + 100*N + 10*E + Y

    return SEND + MORE == MONEY


def solve(index):

    if index == len(letters):
        return check()

    letter = letters[index]

    for digit in range(10):

        if digit in used:
            continue

        if (letter == "S" or letter == "M") and digit == 0:
            continue

        assignment[letter] = digit
        used.add(digit)

        if solve(index + 1):
            return True

        del assignment[letter]
        used.remove(digit)

    return False


solve(0)

print("Solution:")

for letter in letters:
    print(letter, "=", assignment[letter])