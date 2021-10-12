#   Alois Stöckl - Hü 1 - Aufgabe 4

# a

def summe(*number):
    output = 0;
    if len(number) == 0:
        return 0;
    for i in number:
        output = output + i;
    return output;

print(summe(1))
print(summe(1,2,3,4))
print(summe())

# b

def maximum(arg1, *args):
    max = arg1;
    if len(args) == 0:
        return arg1;
    for i in args:
        if (max < i):
            max = i;
    return max

print(maximum(1))
print(maximum(1,2,3,4))