#   Alois Stöckl - Hü 3 - Aufgabe 6


def isPrime(n):
    return all(n % i for i in range(2, n))


def AllPrimeton(n):
    counter = 1
    output = []

    while(len(output) + 1 <= n):
        counter = counter + 1
        if isPrime(counter):
            output.append(counter)

    return output

def nPrime(n):
    return AllPrimeton(n)[-1]


print("6. Primzahl", nPrime(6))
print("1001. Primzahl", nPrime(1001))
print("10001. Primzahl", nPrime(10001))

