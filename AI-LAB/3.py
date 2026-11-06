
# Given probabilities
PB = 0.001
PE = 0.002

# Task 1: Joint probability
joint = (1-PB) * (1-PE) * 0.001 * 0.90 * 0.70

print("Joint probability:", joint)


# Task 2: P(B | J, M)

total = 0
burglary = 0

for b in [0, 1]:
    for e in [0, 1]:
        for a in [0, 1]:

            # P(B)
            if b == 1:
                pb = PB
            else:
                pb = 1-PB

            # P(E)
            if e == 1:
                pe = PE
            else:
                pe = 1-PE

            # P(A | B, E)
            if b == 1 and e == 1:
                pa = 0.95
            elif b == 1 and e == 0:
                pa = 0.94
            elif b == 0 and e == 1:
                pa = 0.29
            else:
                pa = 0.001

            # P(A) or P(not A)
            if a == 1:
                alarm = pa
            else:
                alarm = 1-pa

            # John and Mary both call
            pj = 0.90 if a == 1 else 0.05
            pm = 0.70 if a == 1 else 0.01

            # Joint probability
            p = pb * pe * alarm * pj * pm

            total = total + p

            if b == 1:
                burglary = burglary + p

# Posterior probability
answer = burglary / total

print("P(J, M):", total)
print("P(B, J, M):", burglary)
print("P(B | J, M):", answer)
