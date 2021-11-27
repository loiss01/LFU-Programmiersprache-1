# Fordern Sie den Benutzer auf, seinen ersten Vornamen einzugeben.
# Wenn mehr als ein Vorname eingegeben wurden, geben Sie aus:
# Zuviele Vornamen
# Andernfalls zählen Sie die Anzahl der Vokale "aeiou"
# im Vornamen und geben Sie deren Gesamtanzahl aus.

vorname = input("Geben Sie ihren ersten Vornamen ein: ")

if len(vorname.split(" ")) != 1:
    print("Zuviele Vornamen")
    exit(0)

vokale = "aeiou"

count = 0
for entry in vorname:
    if vokale.__contains__(entry):
        count = count + 1;

print("Der Name hat " + str(count) + " Vokale!")