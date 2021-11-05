#   Alois Söckl - Hü 5 - Aufgabe 3

from matplotlib import pyplot as plot
from math import sin, pi, cos
from numpy import linspace

v = 0
a = 1

def fRot(x):
    return sin(x) * cos(x)

def fBlau(x):
    return a * sin(x+v)

def drawPlot():
    x = [-2 * pi + i * (4 * pi) / 100 for i in range(101)]
    y = [fRot(x) for x in x]
    plot.plot(x,y,"r");

    y1 = [fBlau(x) for x in x]
    plot.plot(x,y1,"b")
    plot.draw()

drawPlot()
plot.title("Versuche die Kurven dekungsgleich zu machen!")
plot.show()


while(True):
    a = float(input("Geben Sie einen neuen Wert für die Amplitude an:"))
    v_new = float(input("Geben Sie einen neuen Wert für die Verschiebung an: "))
    if v == v_new:
        print("Goodbye!")
        break
    else:
        v = v_new
    drawPlot()
    plot.title("Versuche die Kurven dekungsgleich zu machen!")
    plot.show()

#c ist noch zu machen