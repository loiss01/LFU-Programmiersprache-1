# Alois Stöckl - Hü2 - Aufgabe 1

x = [ 1, 2, "drei", "4", [5], (6,7), "Ein Text" ]

# a

for i in range(len(x)):
    print(i + 1, "=", x[i])

# b

G = [];
U = [];

for i in range(len(x)):
    if (i % 2):
        G.append(x[i])
    else:
        U.append(x[i])

print(G)
print(U)

# c

G = x[1::2]
U = x[0::2]

print(G)
print(U)