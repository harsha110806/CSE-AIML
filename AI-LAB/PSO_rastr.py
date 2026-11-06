import random
import math

n = 30

w = 0.7
c1 = 1.5
c2 = 1.5

x = []

for i in range(n):
    x.append([random.uniform(-5.12,5.12),
              random.uniform(-5.12,5.12)])

v = [[0,0] for i in range(n)]

def f(p):
    return 20 + p[0]**2 + p[1]**2 - 10*(math.cos(2*math.pi*p[0]) + math.cos(2*math.pi*p[1]))

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

            if x[i][j] < -5.12:
                x[i][j] = -5.12

            if x[i][j] > 5.12:
                x[i][j] = 5.12

        if f(x[i]) < pbest_val[i]:
            pbest[i] = x[i][:]
            pbest_val[i] = f(x[i])

    g = pbest_val.index(min(pbest_val))
    gbest = pbest[g][:]

print("Best position:", gbest)
print("Best value:", f(gbest))