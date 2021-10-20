# Alois Stöckl - Hü 3 - Aufgabe 3

def sum35(n):
    output = 0;
    for i in range(1,n+1):
        if (i % 3 == 0):
            output = output + i
        elif (i % 5 == 0):
            output = output + i
    return output;

print(sum35(10))

for i in range(1,1001):
    print(sum35(i))