# Lösungsversuch der Tutorium Bsp

def bankverbindung(s):
    print(s)
    nn, iban = s.split(" ")

    print("Nachname: {}".format(nn))
    print("Ländercode: {}".format(iban[0] + iban[1]))

    return len(iban)

print(bankverbindung("lois AT2124"))