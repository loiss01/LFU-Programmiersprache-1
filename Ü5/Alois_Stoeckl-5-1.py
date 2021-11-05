#   Alois Stöckl - Hü 5 - Aufgabe 1

from matplotlib import pyplot as pyp
from math import sin, pi
from numpy import linspace

print("a.)")

def f(x):
    return 10 * (sin(x)/(1+x**2))

# x = [-4 * pi + i * (8 * pi) / 100 for i in range(101)]
x = linspace(-4 * pi, 4*pi)
y = [f(x) for x in x]
pyp.plot(x, y, "r")


for i in range(1,7):
    t = 0.5 * i
    y1 = [f(x) - t for x in linspace(-4 * pi, 4*pi)]
    pyp.plot(x, y1, "b")

pyp.show();

print("b.)")

pyp.plot(x, y, "r")

for i in range(1,7):
    t = 0.5 * i
    y1 = [f(x - t) for x in linspace(-4 * pi, 4*pi)]
    pyp.plot(x, y1, "b")

pyp.show()