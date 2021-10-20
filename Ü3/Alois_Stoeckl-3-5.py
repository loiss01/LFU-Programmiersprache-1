#   Alois Stöckl - Hü 3 - Aufgabe 5

def calc_armstrong(n):
    zahl = 0
    zifferAnzahl = len(str(n))
    for i in range(zifferAnzahl):
        zahl = zahl + int(str(n)[i]) ** zifferAnzahl
    if(zahl == n): return True;

    return False

output = []
for i in range(1, 999999):
    if calc_armstrong(i):
        output.append(i)

print(output)