#   Alois Stöckl - Hü 4 - Aufgabe 1


from random import randint
from matplotlib import pyplot as plt

print("a.)")

def wuerfel():
    return randint(1,6)

def serie(n):
    return [wuerfel() for i in range(n)]

def plotCreate(list, prozente):
    plt.bar(list, prozente)
    plt.ylabel("Haufikeiten in Prozent")
    plt.title("Ergebnisse von 1000x Würfeln")
    plt.show()

def printProcentage(serie):
    n = len(serie)

    moeglWerte = [i for i in range(1,7)]

    h = [serie.count(wert) for wert in moeglWerte]

    hProzent = [serie.count(wert) / n * 100 for wert in moeglWerte]

    for i in range(len(h)):
        print("Ergebnis {:4}: in {:3d} Faellen ({:5.2f} %)".format(moeglWerte[i], h[i], hProzent[i]))

    return hProzent

plotCreate([i for i in range(1,7)],printProcentage(serie(1000)))

print("b.)")
