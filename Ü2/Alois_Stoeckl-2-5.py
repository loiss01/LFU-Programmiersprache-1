# Alois Stöckl - Hü 2 - Aufgabe 5

def jahressteuer(bmg):
    if(bmg > 1000000):
        return (bmg - 1000000) * 0.55 + 487880
    elif (bmg > 90000):
        return berechung(bmg, 90000, 910000, 455000, 32880)
    elif (bmg > 60000):
        return berechung(bmg, 60000, 30000, 14400, 18480)
    elif (bmg > 31000):
        return berechung(bmg, 31000, 29000, 12180, 6300)
    elif (bmg > 18000):
        return berechung(bmg, 18000, 13000, 4550, 1750)
    elif (bmg > 11000):
        return berechung(bmg, 11000, 7000, 1750, 0)
    if (bmg <= 11000):
        return 0

    return 0

def berechung(einkommen, untergrenze, nenner, arg1, arg2):
    erg = 0
    erg = ((einkommen - untergrenze) * arg1) / nenner + arg2
    return erg;

i = 0
while(i < 1000000):
    i = i + 10000;
    steuer = jahressteuer(i)
    print("JahresSteuersatz:",steuer, " Durchschnittliche Abagben pro Monat (jahr/12)", float(steuer/12).__round__(2))