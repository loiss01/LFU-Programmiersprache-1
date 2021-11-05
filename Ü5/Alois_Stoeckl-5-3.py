#   Alois Stöckl - Hü 5 - Aufgabe 3

from matplotlib import pyplot as pyp
from math import sin, pi, cos
from numpy import linspace

v = 0
a = 1

def fRot(x):
    return sin(x) * cos(x)

def fBlau(x):
    return a * sin(x+v)

def drawPlot():
    x = linspace(-2*pi,2*pi, 100)
    y = [fRot(x) for x in x]
    pyp.plot(x, y, "r");

    y1 = [fBlau(x) for x in x]
    pyp.plot(x, y1, "b")
    pyp.show()

drawPlot()

print("b.)")
while(True):
    v_new = float(input("Geben Sie einen neuen Wert für die Verschiebung an: "))
    a = float(input("Geben Sie einen neuen Wert für die Amplitude an:"))
    if v == v_new:
        print("Goodbye!")
        break
    else:
        v = v_new
    drawPlot()

# TODO: c.)