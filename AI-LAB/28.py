R = [1,1,1,1,0,0,0,0,0,0]
T = [1,1,0,1,0,1,0,0,1,0]
L = [1,1,0,0,0,1,0,0,0,0]

# P(R)
p_r = sum(R) / len(R)

# P(T | R)
r_true = 0
r_false = 0
t_r_true = 0
t_r_false = 0

for i in range(10):

    if R[i] == 1:
        r_true = r_true + 1
        if T[i] == 1:
            t_r_true = t_r_true + 1
    else:
        r_false = r_false + 1
        if T[i] == 1:
            t_r_false = t_r_false + 1

p_t_r = t_r_true / r_true
p_t_not_r = t_r_false / r_false

# P(L | T)
t_true = 0
t_false = 0
l_t_true = 0
l_t_false = 0

for i in range(10):

    if T[i] == 1:
        t_true = t_true + 1
        if L[i] == 1:
            l_t_true = l_t_true + 1
    else:
        t_false = t_false + 1
        if L[i] == 1:
            l_t_false = l_t_false + 1

p_l_t = l_t_true / t_true
p_l_not_t = l_t_false / t_false

print("P(R) =", p_r)
print("P(T|R) =", p_t_r)
print("P(T|not R) =", p_t_not_r)
print("P(L|T) =", p_l_t)
print("P(L|not T) =", p_l_not_t)

# P(L)
p_l = (p_r * p_t_r * p_l_t) + \
      (p_r * (1-p_t_r) * p_l_not_t) + \
      ((1-p_r) * p_t_not_r * p_l_t) + \
      ((1-p_r) * (1-p_t_not_r) * p_l_not_t)

print("P(L) =", p_l)

# P(R,L)
p_r_l = p_r * p_t_r * p_l_t

print("P(R|L) =", p_r_l / p_l)

# Laplace smoothing for P(L|not T)
p_l_not_t_smooth = (l_t_false + 1) / (t_false + 2)

print("P(L|not T) after smoothing =", p_l_not_t_smooth)

# Recalculate P(L)
p_l_smooth = (p_r * p_t_r * p_l_t) + \
             (p_r * (1-p_t_r) * p_l_not_t_smooth) + \
             ((1-p_r) * p_t_not_r * p_l_t) + \
             ((1-p_r) * (1-p_t_not_r) * p_l_not_t_smooth)

print("P(L) after smoothing =", p_l_smooth)