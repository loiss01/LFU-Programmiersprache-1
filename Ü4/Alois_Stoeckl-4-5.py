#   Alois Stöckl - Hü 4 -Aufgabe 5

from random import randint
from matplotlib import pyplot as plt

cords = [0,0]
ergebnisse = []


def walk(cords):
    # 0 = Norden 1 = Osten, 2 = Süden, 3 = Westen
    direction = randint(0,3)

    if (direction == 0):
        cords[1] = cords[1] + 1
    elif (direction == 1):
        cords[0] = cords[0] + 1
    elif (direction == 2):
        cords[0] = cords[0] - 1
    else:
        cords[1] = cords[1] - 1

def oneWalk():
    global cords
    for i in range(10):
        walk(cords)
    ergebnisse.append(betrag(cords))
    cords = [0, 0]

# Rechnet die Summer der Betrag aus
def betrag(arg):
    return (int(arg[0]).__abs__() + int(arg[1]).__abs__())

# Erstellt das Diagramm
def plotCreate(list, prozente):
    plt.bar(list, prozente)
    plt.ylabel("Häufigkeit in %")
    plt.title("Ergebnisse von 10000x Walks")
    plt.show()

# Definirt und printet die prozente
def printProcentage(serie):
    n = len(serie)
    moeglWerte = [i for i in range(11)]
    h = [serie.count(wert) for wert in moeglWerte]
    hProzent = [serie.count(wert) / n * 100 for wert in moeglWerte]
    #print (hProzent)
    for i in range(len(h)):
        print("Ergebnis {:4}: in {:3d} Faellen ({:5.2f} %)".format(moeglWerte[i], h[i], hProzent[i]))
    return hProzent


for i in range(10000):
    oneWalk()


#print(ergebnisse)
plotCreate([i for i in range(11)], printProcentage(ergebnisse))
print("Die Abstände 1,3,5,7 und 9 (ungerade Zahlen) werden nie erreicht")