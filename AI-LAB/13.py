PP = 0.1
PS = 0.3

total_C = 0
C_X_S = 0
C_X_D = 0

for p in [0, 1]:
    for s in [0, 1]:
        for c in [0, 1]:

            # P(P)
            if p == 1:
                pp = PP
            else:
                pp = 1 - PP

            # P(S)
            if s == 1:
                ps = PS
            else:
                ps = 1 - PS

            # P(C | P,S)
            if p == 1 and s == 1:
                pc = 0.05
            elif p == 1 and s == 0:
                pc = 0.02
            elif p == 0 and s == 1:
                pc = 0.03
            else:
                pc = 0.001

            # Probability of actual C value
            if c == 1:
                cancer = pc
            else:
                cancer = 1 - pc

            # P(X | C)
            if c == 1:
                px = 0.9
            else:
                px = 0.2

            # P(D | C)
            if c == 1:
                pd = 0.65
            else:
                pd = 0.3

            # Joint probability
            prob = pp * ps * cancer * px * pd

            # Prior P(C)
            if c == 1:
                total_C = total_C + prob

            # P(C,X,S)
            if c == 1 and s == 1:
                C_X_S = C_X_S + prob

            # P(C,X,D)
            if c == 1:
                C_X_D = C_X_D + prob

print("P(C):", total_C)