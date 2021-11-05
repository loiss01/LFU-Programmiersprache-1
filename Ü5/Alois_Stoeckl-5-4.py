from matplotlib import pyplot as pyp
from math import pi, sin

from numpy import linspace

steps = 1000

def signum(x):
    if (x > 0): return 1
    elif (x < 0): return -1
    else: return 0

def fourierReihe(x, N):
    return sum([(4/(pi*k))*sin(k*x) for k in range(1, N+1) if k % 2])

x = linspace(-pi, pi, steps)
y = [signum(x) for x in x]


print("b.)")

while(True):
    N = input("Geben Sie eine ganze Zahl [3,49] ein:")

    if N is None: break
    N = int(N)
    if (N < 3 or N > 49 or N % 2): break

    pyp.plot(x, y, "b")
    fr = [fourierReihe(x,N) for x in x]
    pyp.plot(x, fr, "r")


    # ff = [sum([(4/(pi*k)*sin(k*x)) for k in range(1,N) if not k % 2]) for x in range(3,50)]
    # pyp.plot([x for x in range(3, 50)], ff, "r")

    pyp.show()
