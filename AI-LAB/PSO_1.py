n = 3

w = 0.7
c1 = 1.5
c2 = 1.5

x = [[3,4], [-2,1], [1,-1]]
v = [[0,0], [0,0], [0,0]]


def f(p):
    return p[0]**2 + p[1]**2


pbest = [p[:] for p in x]
pbest_val = [f(p) for p in x]

g = pbest_val.index(min(pbest_val))
gbest = pbest[g][:]


for it in range(50):

    for i in range(n):

        for j in range(2):

            v[i][j] = (w*v[i][j]
                       + c1*0.5*(pbest[i][j]-x[i][j])
                       + c2*0.5*(gbest[j]-x[i][j]))

            x[i][j] = x[i][j] + v[i][j]

        if f(x[i]) < pbest_val[i]:
            pbest[i] = x[i][:]
            pbest_val[i] = f(x[i])

    g = pbest_val.index(min(pbest_val))
    gbest = pbest[g][:]


print("Best position:", gbest)
print("Best value:", f(gbest))
