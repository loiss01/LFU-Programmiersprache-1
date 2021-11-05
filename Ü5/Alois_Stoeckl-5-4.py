from matplotlib import pyplot as plot
from math import pi, sin


def signum(x):
    if (x > 0): return 1
    elif (x < 0): return -1
    else: return 0


x = [-pi + i * (2 * pi) / 100 for i in range(1001)]
y = [signum(x) for x in x]


print("b.)")

while(True):
    N = input("Geben Sie eine ganze Zahl [3,49] ein:")
    if N is None: break
    N = int(N)
    if (N < 3 or N > 49): break

    plot.plot(x, y)

    ff = [sum([(4/(pi*k)*sin(k*x)) for k in range(1,N) if k % 2]) for x in range(3,50)]
    plot.plot([x for x in range(3,50)], ff, "r")
    #lot.plot(x,ff,"r")
    plot.draw()
    plot.show()

# noch nicht fertig