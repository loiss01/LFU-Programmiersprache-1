#   Alois Stöckl - Hü 5 - Aufgabe 2
from math import sin, pi

from matplotlib import pyplot as pyp
from numpy import linspace

def f(x):
    return 10 * (sin(x)/(1+x**2))

print("a.)")

x = linspace(-4 * pi, 4*pi)
y = [f(x) for x in x]
pyp.plot(x, y, "r")


for i in range(1,7):
    t = 1.5+i*0.25
    y1 = [t * f(x) for x in linspace(-4 * pi, 4*pi)]
    pyp.plot(x, y1, "b")

pyp.show()

print("b.)")

pyp.plot(x, y, "r")


for i in range(1,7):
    t = 1.5+i*0.25
    y1 = [f(t*x) for x in linspace(-4 * pi, 4*pi)]
    pyp.plot(x, y1, "b")

pyp.show()

print("c.)")

pyp.plot(x, y, "r")


for i in range(1,7):
    t = 1.5+i*0.25
    y1 = [f(x)/t for x in linspace(-4 * pi, 4*pi)]
    pyp.plot(x, y1, "b")

pyp.show()

print("d.)")

pyp.plot(x, y, "r")


for i in range(1,7):
    t = 1.5+i*0.25
    y1 = [f(x/t) for x in linspace(-4 * pi, 4*pi)]
    pyp.plot(x, y1, "b")

pyp.show()