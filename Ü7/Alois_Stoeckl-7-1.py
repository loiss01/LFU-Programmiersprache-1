#  Alois Stöckl - Hü 7 - Aufgabe 1


def is_sorted(arg):
    x, y, z = arg.split()

    if (x <= y <= z):
        return True
    return False

def is_even(arg):
    x, y, z = arg.split()

    if (int(x) % 2 == 0 and int(y) % 2 == 0 and int(z) % 2 == 0):
        return True
    return False

with open("data_99_3.dat", "r") as fid:
    with open ("even.dat" , "w") as even:
        with open ("sorted.dat", "w") as sort:
            x,y,z = 0,0,0
            for line in fid:
                #Check for a
                if(is_sorted(line)):
                    sort.write(line)
                else :
                    list = line.split()
                    sorted(list)
                    str1 = ""
                    for entry in list:
                        str1 += " " + entry
                    str1 += "\n"
                    sort.write(str1)
                #Check for b
                if (is_even(line)):
                    even.write(line)

