# Lösungsversuch der Tutorium Bsp
from random import uniform

filename = input("Filname: ")

if not filename:
    exit(0)

filename = filename + ".dat"

with open(filename, "w") as fid:
    for i in range(1,101):
        fid.write("{} {:.2f} \n".format(i, uniform(1,10)))

I = []
U = []

with open(filename, "r") as fid:
    for line in fid:
        sp = line.split(" ")
        I.append(sp[0])
        U.append(sp[1])

print(I)
print(U)