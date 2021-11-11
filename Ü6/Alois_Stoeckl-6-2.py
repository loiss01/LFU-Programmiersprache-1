#   Alois Stöckl - Hü 6 - Aufgabe 2
import statistics
from statistics import median
from random import gauss


print("a.)")

n = int(input("Geben Sie einen Wert für n ein: "))
sigma = float(input("Geben Sie einen Wert für sigma ein: "))
mu = float(input("Gebene Sie einen Wert für mu ein: "))

if (n <= 1 or sigma <= 0):
    print("Programm wird abgebrochen, das die Argumente nicht übereinstimmen!")
    exit(1)

filename = "Normalverteilung.txt"
fid = open(filename, "w")

for i in range(n):
    fid.write("{} \n".format(gauss(mu, sigma)))

fid.close()

print("b.)")

x = []

with open(filename, "r") as fid:
    for line in fid:
        x.append(float(line))

print("Mittelwert: {}".format(median(x)))
print("Varianz: {}".format(statistics.variance(x))) #TODO: Varianz

print("c.)")

print("Maximum: {}".format(max(x)))
print("Minimum: {}".format(min(x)))

print("d.)")

m1 = (1/n) * sum(x)
print("m1: {}".format(m1))

m2 = ((1/n) * sum([entry**2 for entry in x]))**0.5
print("m2: {}".format(m2))
