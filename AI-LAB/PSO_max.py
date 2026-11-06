import random
import math

n = 20

w = 0.7
c1 = 1.5
c2 = 1.5

x = []

for i in range(n):
    x.append(random.uniform(-1,2))

v = [0 for i in range(n)]

def f(p):
    return p * math.sin(10*math.pi*p) + 1

pbest = x[:]
pbest_val = [f(p) for p in x]

g = pbest_val.index(max(pbest_val))
gbest = pbest[g]

for it in range(100):

    for i in range(n):

        v[i] = (w*v[i]
                + c1*random.random()*(pbest[i]-x[i])
                + c2*random.random()*(gbest-x[i]))

        x[i] = x[i] + v[i]

        if x[i] < -1:
            x[i] = -1

        if x[i] > 2:
            x[i] = 2

        if f(x[i]) > pbest_val[i]:
            pbest[i] = x[i]
            pbest_val[i] = f(x[i])

    g = pbest_val.index(max(pbest_val))
    gbest = pbest[g]

print("Best position:", gbest)
print("Best value:", f(gbest))