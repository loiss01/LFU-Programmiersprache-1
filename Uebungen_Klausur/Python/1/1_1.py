# https://www.bauboard.at/board/wbb4/index.php?thread/1538-python-1-klausur-mit-l%C3%B6sungen-und-l%C3%B6sungsversuchen/
# Aufgabe 1:
# Fordern Sie den Benutzer in einer Endlosschleife auf, eine ganze Zahl n einzugeben.
# Die Schleife soll enden, wenn nichts eingegeben wurde.
# Geben Sie aus, ob die eingelesene Zahl n positiv, negativ oder 0 ist.
# Geben Sie aus ob die Zahl n durch 7 teilbar ist oder nicht.
# Falls die Zahl n positiv und einstellig ist: Geben Sie alle Zahlen
# von 1 bis n in einer Zeile aus.


while(True):
    n = input("Geben Sie eine Ganze Zahl an: ")
    if n == "":
        break

    n = int(n)

    if n < 0:
        print("Die Zahl ist negativ")
    elif n > 0:
        print("Die Zahl ist positiv")
    else:
        print("Die Zahl ist 0")

    if n % 7 == 0:
        print("Die Zahl ist durch 7 Teilbar")

    if len(str(n)) == 1:
        out = ""
        for i in range(1, n+1):
            out = out + str(i) + " "
        print(out)