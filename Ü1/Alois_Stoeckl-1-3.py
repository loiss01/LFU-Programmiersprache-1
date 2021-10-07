#   Alois Stöckl - Hü 1 - Aufgabe 3

def arithmetic(a, b):
    print(a, "(", type(a), ") + ", b, "(", type(b), ") = ", a + b, "(", type(a+b), ")");
    print(a, "(", type(a), ") - ", b, "(", type(b), ") = ", a - b, "(", type(a-b), ")");
    print(a, "(", type(a), ") * ", b, "(", type(b), ") = ", a * b, "(", type(a*b), ")");
    print(a, "(", type(a), ") / ", b, "(", type(b), ") = ", a / b, "(", type(a/b), ")");
    print(a, "(", type(a), ") // ", b, "(", type(b), ") = ", a // b, "(", type(a//b), ")");
    print(a, "(", type(a), ") %", b, "(", type(b), ") = ", a % b, "(", type(a%b), ")");
    print(a, "(", type(a), ") ** ", b, "(", type(b), ") = ", a ** b, "(", type(a**b), ")");

# 3.a)
arithmetic(2021, 22);
arithmetic(2021., 22);

# 3.b)
a = int( input("Geben Sie eine ganze Zahl für a ein: ") );
b = float( input("Geben Sie noch eine Gleitkomma-Zahl für b ein: ") );

arithmetic(a,b);