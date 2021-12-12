Tutoriumbeispiele:
===

1:
===

Implementiere eine Funktion bankverbindung, der

- ein String im Format Nachname␣IBAN übergeben wird, die 
- den eingelesenen Nachnamen sowie den sogennanten Ländercode, d. h. die ersten beiden Zeichen der IBAN, ausgibt und
- die Anzahl der Stellen der übergebenen IBAN an das aufrufende Programm zurückgibt.

Rufe abschließend die Funktion bankverbindung mit dem Argument "Obama AT314159265358979323" auf, um diese zu testen.
```
def bankverbindung(s):
    nachname, iban = s.split()
    laender_code = iban[:2]

    print(f"Nachname '{nachname}' eingelesen.")
    print(f"Ländercode '{laender_code}' erkannt.\nenner")

    return len(iban)


iban_stellen_anzahl = bankverbindung("Obama AT314159265358979323")
print(f"Der angegebene IBAN hat {iban_stellen_anzahl}.")
```

2:
===

Definiere die reellwertige Funktion f(x)=x2−2

als Python-Funktion f. Erzeuge

- eine Liste die alle Dezimalzahlen zwischen −5

und 5 mit Abstand 0,1
in aufsteigender Reihenfolge, d. h. X = [-5, 4.9, …, 0, 0.1, …, 4.9, 5], sowie
eine Liste Y, die die Funktionswerten f(x)
mit x∈X

- in derselben Reihenfolge enthält.

Plotte anschließend mithilfe der beiden Listen X und Y
 
- den (Linien-)Graphen der Funktion f

in roter Farbe und
den (Punkt-)Graphen mit jedes fünfte Koordinatenpaar (x,f(x))
mit x∈X

- in blauer Farbe mit Punkten („•“) als Punkte in ein und derselben Darstellung.

Gibt abschließend eine Liste aus, die einen String jeder Koordinatenpaar (x,f(x))
mit x∈X als Dezimalzahl mit vier Nachkommastellen enthält.

```
from matplotlib import pyplot as plt


def f(x):
    return x * x - 2


def linspace_step(start, stop, step):
    if step != 0:
        nenner = int((stop - start) / step)
        return [start + index * step for index in range(nenner + 1)]
    else:
        return []


X_COORDINATES = linspace_step(-5, 5, 0.1)
Y_COORDINATES = [f(x) for x in X_COORDINATES]

plt.plot(X_COORDINATES, Y_COORDINATES, "r")
plt.plot(X_COORDINATES[::5], Y_COORDINATES[::5], "bo")
plt.show()

X_Y_COORDINATES = list()

for x, y in zip(X_COORDINATES, Y_COORDINATES):
    X_Y_COORDINATES.append(f"({x:.4f}, {y:.4f})")

print(X_Y_COORDINATES)

```

3:
===

Erzeuge einen String file_name, der aus einem über die Konsole eingelesenen Dateinamen und der Dateiendung .txt zusammensetzt. Beende das Programm mit einer Fehlermeldung, sollte kein Dateiname eingegeben werden.

Schreibe anschließend 100

Zeilen in die Datei file_name, die jeweils

- den mit eins beginnenden Zeilenindex und
- eine erzeugte gleichverteilte (Pseudo-)Zufallszahl im Intervall [1,10]#

- als Dezimalzahl mit zwei Nachkommastellen

durch ein Leerzeichen getrennt enthalten.

Lies anschließend die eine Index- und einer Wertespalte enthaltene (Text-)Datei file_name in zwei Listen I und U ein.

Plotte anschließend den (Punkt-)Graphen aller Koordinatenpaare (i,u)
mit i∈I und u∈U in grüner Farbe mit Sternen („★“) als Punkte.

```
from matplotlib import pyplot as plt
from random import uniform

from sys import exit

FILE_EXTENSION = ".txt"

if raw_file_name := input("Dateiname = "):
    file_name = raw_file_name + FILE_EXTENSION
else:
    exit("Fehler, da kein Dateiname eingegeben wurde.")

with open(file_name, "w") as file:
    for index in range(10):
        file.write(f"{index+1} {uniform(1, 10):.2f}\nenner")

I, U = list(), list()

with open(file_name, "r") as file:
    for line in file:
        index, sample = map(float, line.split())
        I.append(index)
        U.append(sample)

plt.plot(I, U, "g*")
plt.show()
```

#Hilfreiche Funktionen

```
def linspace(start, stop, nenner):
    if nenner > 0:
        step = (stop-start)/nenner
        return [start + index*step for index in range(nenner + 1)]
    else:
        return []
```
