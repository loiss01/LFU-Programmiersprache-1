# Füllen Sie die Liste L mit allen ganzen Zahlen aus [-1000, 1000], die
# durch 11 aber nicht durch 3 teilbar sind.
# Geben Sie die Anzahl der Elemente von L aus.
# Geben Sie aus, wieviel Elemente von L negativ sind.
# Erzeugen Sie aus L die Liste PU der positiven ungeraden Elemente von L.
# Geben Sie die ersten 5 Zahlen von PU aus.

L = [i for i in range(-1000, 1001) if i % 11 == 0 and i % 3 != 0 ]

print(L)

count_negativ = 0
for entry in L:
    if entry < 0:
        count_negativ = count_negativ + 1

PU = [entry for entry in L if entry > 0 and entry % 2 != 0]

for i in range(0,5):
    print(PU[i])