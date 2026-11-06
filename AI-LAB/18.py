import random

random.seed(42)

def sample():

    c = random.random() < 0.5

    if c:
        s = random.random() < 0.1
        r = random.random() < 0.8
    else:
        s = random.random() < 0.5
        r = random.random() < 0.2

    if s and r:
        pw = 0.99
    elif s and not r:
        pw = 0.90
    elif not s and r:
        pw = 0.90
    else:
        pw = 0.0

    w = random.random() < pw

    return r, w


def rejection_sampling(n):

    accepted = 0
    rain = 0

    for i in range(n):

        r, w = sample()

        if w:
            accepted = accepted + 1

            if r:
                rain = rain + 1

    if accepted == 0:
        return 0, n

    return rain / accepted, n - accepted


for n in [100, 1000, 10000]:

    result, rejected = rejection_sampling(n)

    print("N =", n)
    print("P(R | W) =", result)
    print("Rejected =", rejected)
    print()