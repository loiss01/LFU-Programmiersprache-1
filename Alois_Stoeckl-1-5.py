# Alois Stöckl - Hü 1 - Aufgabe 5

def aufgabe5(a,b, numbering):
    print(numbering, a, " + ", b, " = ", value_and_type(a+b))
    print(numbering, "5 * ", a, " = ", value_and_type(5 * a))
    print(numbering, "2 * ", a, " + 2 * ", b, " = ", value_and_type(2 * a + 2 * b))
    print(numbering, "2 * (", a, " + ", b, ") = ", value_and_type(2 * (a, b)))

def value_and_type(a):
    return a, "(", type(a), ")"


a = "hi"
b = "ho"
c = "5a.)"

aufgabe5(a,b,c)

a = [1, 2]
b = [-99]
c = "5b.)"

aufgabe5(a,b,c)

a = (1, 2)
b = (-99,)
c = "5c.)"

aufgabe5(a,b,c)

a = 1, 2
b = -99,
c = "5d.)"

aufgabe5(a,b,c)