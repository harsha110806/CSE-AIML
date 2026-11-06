PC = 0.5

total_W = 0
S_W = 0
R_W = 0
S_W_R = 0

for c in [0, 1]:
    for s in [0, 1]:
        for r in [0, 1]:

            # P(C)
            if c == 1:
                pc = PC
            else:
                pc = 1 - PC

            # P(S | C)
            if c == 1:
                ps = 0.1
            else:
                ps = 0.5

            if s == 0:
                ps = 1 - ps

            # P(R | C)
            if c == 1:
                pr = 0.8
            else:
                pr = 0.2

            if r == 0:
                pr = 1 - pr

            # P(W | S,R)
            if s == 1 and r == 1:
                pw = 0.99
            elif s == 1 and r == 0:
                pw = 0.90
            elif s == 0 and r == 1:
                pw = 0.90
            else:
                pw = 0.0

            # Joint probability
            p = pc * ps * pr * pw

            # P(W)
            total_W = total_W + p

            # P(S,W)
            if s == 1:
                S_W = S_W + p

            # P(R,W)
            if r == 1:
                R_W = R_W + p

            # P(S,W,R)
            if s == 1 and r == 1:
                S_W_R = S_W_R + p

print("P(W):", total_W)
print("P(S | W):", S_W / total_W)
print("P(R | W):", R_W / total_W)
print("P(S | W, R):", S_W_R / R_W)