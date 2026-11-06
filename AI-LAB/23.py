import random

random.seed(42)

PB = 0.001
PE = 0.002


def likelihood_weighting(n):

    total_weight = 0
    burglary_weight = 0

    for i in range(n):

        # Sample Burglary
        b = random.random() < PB

        # Sample Earthquake
        e = random.random() < PE

        # P(A | B,E)
        if b and e:
            pa = 0.95
        elif b and not e:
            pa = 0.94
        elif not b and e:
            pa = 0.29
        else:
            pa = 0.001

        # Sample Alarm
        a = random.random() < pa

        # Evidence J = True
        if a:
            wj = 0.90
        else:
            wj = 0.05

        # Evidence M = True
        if a:
            wm = 0.70
        else:
            wm = 0.01

        weight = wj * wm

        total_weight = total_weight + weight

        if b:
            burglary_weight = burglary_weight + weight

    return burglary_weight / total_weight


for n in [1000, 10000]:

    result = likelihood_weighting(n)

    print("N =", n)
    print("P(B | J,M) =", result)
    print()