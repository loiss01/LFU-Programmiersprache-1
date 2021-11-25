# Definieren Sie die Funktion f(x) mit Resultat 1.01**x.
# Speichern Sie in der Liste L 1000 Glieder der Folge f
# (f(n), n = 1, 2, ..., 1000)
# Geben Sie aus, wieviele Zahlen von L größer als 10 sind.
# Geben Sie die Summe der Zahlen von L, die in (0.99, 1.01) liegen, aus.
# Geben Sie die Folgenglieder Nr. 409 - 400 untereinander mit
# Feldbreite 17 und 10 Nachkommastellen aus.

def f(x):
    return 1.01**x

L = [f(i) for i in range(1,1001)]

list1 = [entry for entry in L if entry > 10]
print(">10: " + str(len(list1)))

summe = 0;
for entry in L:
    if (entry >= 0.99 and entry <= 1.01):
        summe = summe + entry

print("summe: " + str(summe))

for i in range(400, 410):
    print("{:17.12} ".format(L[i]))