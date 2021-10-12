# Alois Stöckl - Hü2 - Aufgabe 3

x = [ 1, 2, "drei", "4", [5], (6,7), "Ein Text" ]

Strings = []
No_String = []

for entry in x:
    if (isinstance(entry, str)):
        Strings.append(entry)
    else:
        No_String.append(entry)

print(Strings)
print(No_String)