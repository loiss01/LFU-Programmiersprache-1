# Alois Stöckl - Hü3 - Aufgabe 1

x = [ 1, 2, "drei", "4", [5], (6,7), "Ein Text" ]

G = [x[i] for i in range(len(x)) if i % 2 == 0]
U = [x[i] for i in range(len(x)) if i % 2 == 1]


print("G: ", G)
print("U: ", U)