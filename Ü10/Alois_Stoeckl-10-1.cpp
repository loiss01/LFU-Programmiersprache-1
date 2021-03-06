//  Alois Stöckl - Hü 10 - Aufgabe 1

#include <fstream>
#include <algorithm>
#include "iostream"
#include "vector"

using namespace std;

struct Bruch{
    int zaehler{1};
    int nenner{1};
};

Bruch operator-(Bruch a, Bruch b){
    Bruch summe;
    summe.zaehler = a.zaehler * b.nenner - a.nenner * b.zaehler;
    summe.nenner = a.nenner * b.nenner;
    return summe;
}

Bruch operator+(Bruch a, Bruch b){
    Bruch summe;
    summe.zaehler = a.zaehler * b.nenner + a.nenner * b.zaehler;
    summe.nenner = a.nenner * b.nenner;
    return summe;
}

void operator<<(std::ostream&  os, Bruch b){
    if (b.nenner == 1){
        os << b.zaehler << endl;
    }else{
        os << "(" << b.zaehler << "/" << b.nenner << ")" << endl;
    }
}

/**
 * Apply Lambda from lecture
 */
auto applylamb = [](auto lamb, auto in){
    for_each(begin(in), end(in), lamb);
};

double to_double(Bruch br){
    return (double) br.zaehler / br.nenner;
}

bool vergleichNenner(Bruch b1, Bruch b2){
    return (b1.nenner < b2.nenner);
}

bool vergleichZaehler(Bruch b1, Bruch b2){
    return (b1.zaehler < b2.zaehler);
}

int main(){

    vector<Bruch> v;

    cout << "a.)" << endl;

    while (true){
        Bruch a;

        cout << "Geben Sie einen Nenner ein (Bei 0 wird kein neuer Bruch angelegt!):";
        cin >> a.nenner;

        if (a.nenner == 0){
            break;
        }

        cout << "Geben Sie einen Zähler ein: ";
        cin >> a.zaehler;

        v.push_back(a);
    }

    applylamb([](auto& in){ cout << in;}, v);

    //
    // -------------------------------------------------------
    //

    cout << endl;
    cout << "b.)" << endl << endl;

    vector<Bruch> brueche;

    fstream datei;
    datei.open("zahlenpaare.txt", ios::in);

    if (datei.is_open()){
        string line;
        while (getline(datei, line)){
            Bruch i{
                stoi(line.substr(0, ' ')),
                stoi(line.substr(1, ' '))};

            brueche.push_back(i);
            cout << line << endl;
        }
        datei.close();
    }else cout << "Fehler beim öffnen der Datei!";


    cout << endl;
    cout << "c.)" << endl;

    vector<Bruch> nenner, zaehler;

    nenner = brueche;
    zaehler = brueche;

    sort(nenner.begin(), nenner.end(), vergleichNenner);
    sort(zaehler.begin(), zaehler.end(), vergleichZaehler);

    cout << "Nenner: " << endl;
    for (Bruch b : nenner){
        cout << b.nenner << " ";
    }
    cout << endl;

    cout << "Zähler: " << endl;
    for (Bruch b : zaehler){
        cout << b.zaehler << " ";
    }

    cout << endl;
    cout << endl;
    cout << "d.)" << endl;

    nenner = brueche;
    zaehler = brueche;

    std::ranges::sort(brueche, greater<>{}, &Bruch::zaehler);
    std::ranges::sort(brueche, {}, &Bruch::nenner);

    for (Bruch b : brueche){
        cout << b;
    }
    cout << endl;

    cout << endl;
    cout << "e.)" << endl;

    double wert = 0;
    for (Bruch b : brueche){
        wert = wert + to_double(b);
    }

    cout << "Wert der Brüche ist: " << wert << endl;

    return 0;
}
