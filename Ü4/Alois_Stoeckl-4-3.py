#   Alois Stöckl - Hü 4 - Aufgabe 3

from random import gauss, uniform
from math import pi

print("a.)")

def game(cords):
    if ((cords[0]**2 + cords[1]**2) <1):
        return True
    return False

n = int(input("Geben Sie die Anzahl an Spielen an: "))
#n = 1000
print([game((gauss(0.,1.), gauss(0.,1.))) for i in range(0, n)])

print("b.)")
ergebniss = [game((uniform(-1.,1.), uniform(-1.,1.))) for i in range(0, n)]
print(ergebniss)

prozente = [ergebniss.count(bool(i)) / len(ergebniss) * 100 for i in range(0,2)]

print("Ergebnisse", prozente)
print("pi/4: ", pi/4)