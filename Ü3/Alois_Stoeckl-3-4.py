# Alois Stöckl - Hü 3 - Aufgabe 4

#a.)
print("a.)")

tuplee = tuple(((i**2) / i+1) - ((i**2)-1) / (i+2) for i in range(1, 1000))

print("tuple: ", tuplee)
print("Die Zahl wird an 3 angenähert!")


#b.)
print("b.)")

summe_1 = 0
for i in range(1,1000000 + 1):
    summe_1 = summe_1 + (1/(i**2))

summe_2 = 0
for i in range(1,1000000 + 1):
    if (i % 2):
        summe_2 = summe_2 + (1/(i**2))

print("summe_1:", summe_1)
print("summe_2:", summe_2)

#c.)
print("c.)")

def minus1power(n):
    return ((-1) ** n)

def factorial(n):
    output = 1
    for i in range(1,n + 1):
        output = output * i
    return output;


summe_3 = 0
for i in range(1, 100 + 1):
    if (i % 2 == 0):
        summe_3 = summe_3 + (minus1power(i/2) / factorial(i))

print("summe_3: ", summe_3)


summe_4 = 0
for i in range(1,100 + 1):
    if (i % 2):
        summe_4 = summe_4 + (minus1power((i-1)/2) / factorial(i))

print("summe_4: ", summe_4)