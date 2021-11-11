from math import sin
from random import gauss

from matplotlib import pyplot

X = [0.1 * i for i in range(21)]

print("a.) reinschreiben")

filename = "Tabelle.txt"
fid = open(filename, "w")

for i in range(len(X)):
    fid.write("{:2.1f}, {:5.4f}, {:2.4f} \n".format(X[i], sin(X[i]), sin(X[i]) + gauss(0.0, 0.01)))
fid.close()


print("b.) Auslesen")

fid = open(filename, "r")

xr = []
yr = []
zr = []

for line in fid:
    x,y,z = line.split(", ")

    xr.append(float(x))
    yr.append(float(y))
    zr.append(float(z))

pyplot.plot(xr,yr)
pyplot.show(block=False)

pyplot.plot(xr,zr)
pyplot.show(block=False)

fid.close()