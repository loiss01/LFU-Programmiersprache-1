# Lösungsversuch der Tutorium Bsp
from matplotlib import pyplot as plt

def f(x):
    return x**2 - 2

X = [i / 10 for i in range(-50, 51)]
Y = [f(x) for x in X]

print(X)
print(Y)

plt.plot(X,Y, "r")
plt.plot(X[::5],Y[::5], "bo")
plt.show()

out = ["({:.4f},{:.4f})".format(x,f(x)) for x in X]
print(out)