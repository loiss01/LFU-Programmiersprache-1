def f(x,y):
    return (x+y)/(x**2 + y**2)

werte = [0.01*i for i in range(1,101)]
print(werte)

erg = []
for entry in werte:
    for entry2 in werte:
        erg.append(f(entry, entry2))

print(len(erg))


vier = 0;
kleiner = [];

for entry in erg:
    if(entry == 4.0): vier = vier + 1;
    if(entry < 1.2): kleiner.append(entry)

print("c.)")
print(vier)
print("d.)")
print(len(kleiner))
print("e.)")
print(sum(kleiner))