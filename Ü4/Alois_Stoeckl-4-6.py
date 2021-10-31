#   Alois Stöckl - Hü 4 - Aufgabe 6
from random import randint

cords = [0,0]
ergebnisse = 0


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

def oneWalk(x=10):
    global cords
    for i in range(x):
        walk(cords)
    if isNullNull(cords[0], cords[1]):
        global ergebnisse
        ergebnisse += 1
    cords = [0, 0]


# Rechnet die Summer der Betrag aus
def betrag(arg):
    return (int(arg[0]).__abs__() + int(arg[1]).__abs__())

# Überprüfung ob die Kooridinaten wieder am ursprung sind
def isNullNull(x,y):
    if x == 0 and y == 0:
        return True
    return False


for i in range(10,41,10):
    for i1 in range(0,1000):
        oneWalk(i)
    print("Bei {} Walks von {} Teilstecken kommt er {}x in den Ursprung. Das macht {:2.2f} % pro Walk".format(1000, i, ergebnisse, ergebnisse/1000 * 100))
    ergebnisse = 0