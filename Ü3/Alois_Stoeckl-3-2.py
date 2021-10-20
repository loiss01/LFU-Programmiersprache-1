# Alois Stöckl - Hü 3 - Aufgabe 2

x = [ 1, 2, "drei", "4", [5], (6,7), "Ein Text" ]

NO_Strings = []
Uppercase_Strings = []

# a.)
print("a.)")

for entry in x:
    if (isinstance(entry, str)):
        Uppercase_Strings.append(str(entry).upper())
    else:
        NO_Strings.append(entry)

print("Strings: ", NO_Strings)
print("Uppercase_Strings: ", Uppercase_Strings)

# b.)
print("b.)")

NO_Strings = [entry for entry in x if not isinstance(entry, str)]
Uppercase_Strings = [str(entry).upper() for entry in x if isinstance(entry, str)]

print("Strings: ", NO_Strings)
print("Uppercase_Strings: ", Uppercase_Strings)