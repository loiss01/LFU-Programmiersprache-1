//  Alois Stöckl - Hü 10 - Aufgabe 3
/*
    SimpleStat:  Einfache statische Auswertung
*/

#include <iostream>

struct SimpleStat {
    std::string title;
    int n{};
    double sum{};

};

void operator+=(SimpleStat& s, double x){   /* bitte programmieren */



}

std::ostream& operator<<(std::ostream& os, const SimpleStat& s){
    /* bitte programmieren */
    return os;
}

using namespace std;

int main(){

    SimpleStat s{"User Input"};     // Statistik definieren und initialisieren

    cout << "Gib einige double ein (Ende mit Buchstabe): ";
    for (double x; cin >> x;)
        s += x;             // wir "speichern" (verarbeiten) die Stichprobe

    cout << s << '\n';              // wir drucken die Auswertung

    return 0;
}
