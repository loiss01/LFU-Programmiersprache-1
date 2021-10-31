#   Alois Stöckl - Hü 4 - Aufgabe 4
from random import uniform
from math import e

def game(cords):
    calc = e**(-cords[0]**2)
    y = cords[1]

    if (y <= calc):
        return True
    return False

n = int(input("Geben Sie die Anzahl an Spielen an: "))

ergebniss = [game((uniform(0.,1.), uniform(0.,1.))) for i in range(0,n)]

print(ergebniss)

prozente = [ergebniss.count(True) / len(ergebniss)]
print(prozente)