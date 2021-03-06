//  Alois Stöckl - Hü 10 - Aufgabe 3
/*
    SimpleStat:  Einfache statische Auswertung
*/

#include <iostream>
#include <valarray>
#include "vector"

using namespace std;

struct SimpleStat {
    string title;
    int n{};
    double sum{};
    double sum2{};
    double varianz;
};

void operator+=(SimpleStat& s, double x){   /* bitte programmieren */
    s.n = s.n + 1;
    s.sum = s.sum + x;
    s.sum2 = pow(x,2);
}

double calcVarianz(SimpleStat s){
    double var = 0;
    var = s.sum2 - (s.n - (s.n - pow((s.sum/s.n), 2)));
    var = var / (s.n - 1);
    s.varianz = var;
    return var;
}

ostream& operator<<(ostream& os, const SimpleStat& s){
    os << s.title << ":" << endl;
    os << "Anzahl der Stichproben: " << s.n << endl;
    if (s.n > 0){
        os << "Mittelwert der Stichproben: " << s.sum/s.n << endl;
    }
    if (s.n > 1){
        os << "Varianz: " << calcVarianz(s) << endl;
        os << "Standartabweichung: " << sqrt(s.varianz) << endl;
    }

    return os;
}

int main(){

    SimpleStat s{"User Input"};     // Statistik definieren und initialisieren

    cout << "Gib einige double ein (Ende mit Buchstabe): ";
    for (double x; cin >> x;){
        s += x;             // wir "speichern" (verarbeiten) die Stichprobe
    }

    cout << s << endl;              // wir drucken die Auswertung

    return 0;
}
