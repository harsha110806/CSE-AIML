import random

n = 30

w = 0.7
c1 = 1.5
c2 = 1.5

def f(p):
    value = (p[0]-2)**2 + (p[1]-1)**2
    penalty = 1000 * max(0,p[0]+p[1]-2)**2
    return value + penalty

x = []

for i in range(n):
    x.append([random.uniform(-5,5),
              random.uniform(-5,5)])

v = [[0,0] for i in range(n)]

pbest = [p[:] for p in x]
pbest_val = [f(p) for p in x]

g = pbest_val.index(min(pbest_val))
gbest = pbest[g][:]

for it in range(100):

    for i in range(n):

        for j in range(2):

            v[i][j] = (w*v[i][j]
                       + c1*random.random()*(pbest[i][j]-x[i][j])
                       + c2*random.random()*(gbest[j]-x[i][j]))

            x[i][j] = x[i][j] + v[i][j]

            if x[i][j] < -5:
                x[i][j] = -5

            if x[i][j] > 5:
                x[i][j] = 5

        if f(x[i]) < pbest_val[i]:
            pbest[i] = x[i][:]
            pbest_val[i] = f(x[i])

    g = pbest_val.index(min(pbest_val))
    gbest = pbest[g][:]

print("Best position:", gbest)
print("Best value:", f(gbest))

if gbest[0] + gbest[1] <= 2:
    print("Constraint satisfied")
else:
    print("Constraint violated")