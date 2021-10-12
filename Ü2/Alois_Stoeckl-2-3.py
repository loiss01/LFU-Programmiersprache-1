# Alois Stöckl - Hü2 - Aufgabe 3

# a


while(1):
    i = input("Geben Sie etwas an: ")
    if not i:
        break

    i = int(i)

    if (i < 0):
        print(i, "ist negativ")
    elif (i == 0):
        print("i = 0")
    elif (i > 0):
        print(i, "hat mindestens", len(str(i)) - 1 , "Dezimalziffern und ist", "gerade" if i % 2 else "ungerade")
        if(len(str(i)) == 1):
            print("i hat eine Ziffer")
        elif(len(str(i)) == 2):
            print("i hat zwei Ziffern")
        else :
            print("i hat mindestens drei Ziffern")