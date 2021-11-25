# Programmieren Sie die Funktion f(x, y) = (x-y)/(x**2+y**2)
# Berechnen Sie die Liste L alle 1000000 = 1000*1000 Funktionswerte f(x, y)
# mit x,y aus [0.001, 0.002, 0.003, ..., 1.000]
# Wie oft kommt der Wert 0 in L vor?
# Wie viele Werte in L liegen in (0,1)?
# Berechnen Sie die Summe der Quadrate dieser Werte in (0,1)!


def f(x,y):
    return (x-y)/(x**2+y**2)

xy = [i/1000 for i in range(1,1001)]

L = [1*b for a in xy for b in xy]

print(L)


print("Anzahl der 0 Werte {}".format(L.count(0)))
print("Es Liegen {} Werte (0,1))".format(len([entry for entry in L if entry >= 0 <= 1])))
print("Summe: {}".format(sum([entry**2 for entry in L if entry >= 0 <= 1])))

