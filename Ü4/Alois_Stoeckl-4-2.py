#   Alois Stöckl - Hü 4 - Aufgabe 2

from random import randint

g = 0
playerIWinns = 0
playerIIWinns = 0

def wurfel():
    return randint(1,6)

def game():
    playerI = wurfel() + wurfel()
    playerII = wurfel()

    global playerIWinns
    global playerIIWinns
    global g

    if (playerI > playerII) :
        # Spieler I gewinnt
        playerIWinns += 1
        g = g +1
    else:
        # Spieler II gewinnt
        playerIIWinns += 1
        g = g - 5

for i in range(0, 10000):
    game()

print("Spieler I hat {} mal gewonnen!".format(playerIWinns))
print("Spieler II hat {} mal gewonnen!".format(playerIIWinns))

if g > 0 :
    print("Spieler I hat {} Geld gewonnen!".format(g))
else:
    print("Spieler II hat {} Geld gewonnen!".format(g*-1))