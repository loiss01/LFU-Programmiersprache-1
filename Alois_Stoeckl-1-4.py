#   Alois Stöckl - Hü 1 - Aufgabe 4

# a.)
a = "hi"
b = "ho"

print(a, " + ", b, " = ", a+b , "(", type(a+b),")")
print("5 * ", a, " = ", 5*a, "(", type(5*a), ")")
print("2 * ", a, " + 2 * ", b , " = ", 2*a+2*b, "(", type(2*a+2*b), ")")
print("2 * (", a, " + ", b, ") = ", 2*(a,b), type(2*(a,b)))

# b.)

a = [1, 2]
b = [-99]

print(a, " + ", b, " = ", a+b , "(", type(a+b),")")
print("5 * ", a, " = ", 5*a, "(", type(5*a), ")")
print("2 * ", a, " + 2 * ", b , " = ", 2*a+2*b, "(", type(2*a+2*b), ")")
print("2 * (", a, " + ", b, ") = ", 2*(a,b), type(2*(a,b)))

# c.)

a = (1, 2)
b = (-99,)

print(a, " + ", b, " = ", a+b , "(", type(a+b),")")
print("5 * ", a, " = ", 5*a, "(", type(5*a), ")")
print("2 * ", a, " + 2 * ", b , " = ", 2*a+2*b, "(", type(2*a+2*b), ")")
print("2 * (", a, " + ", b, ") = ", 2*(a,b), type(2*(a,b)))

# d.)

a = 1, 2
b = -99,

print(a, " + ", b, " = ", a+b , "(", type(a+b),")")
print("5 * ", a, " = ", 5*a, "(", type(5*a), ")")
print("2 * ", a, " + 2 * ", b , " = ", 2*a+2*b, "(", type(2*a+2*b), ")")
print("2 * (", a, " + ", b, ") = ", 2*(a,b), type(2*(a,b)))