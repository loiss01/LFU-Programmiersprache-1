#   Alois Söckl - Hü 5 - Aufgabe 1

from matplotlib import pyplot as plot
from math import sin, pi
from numpy import linspace

def f(x):
    return 10 * (sin(x)/1+x**2)

x = [-4 * pi + i * (8 * pi) / 100 for i in range(101)]
y = [f(x) for x in x]

plot.plot(x, y, "r")

# nicht fertig



plot.show();