//  Alois Stöckl - Hü 10 - Aufgabe 1

#include <fstream>
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
auto apply = [](auto lamb, auto in){
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

    apply([](auto& in){ cout << in;}, v);

    //
    // -------------------------------------------------------
    //

    cout << "b.)" << endl;
    //ToDo: does not work

    fstream datei;
    datei.open("zahlenpaare.txt", ios::in);

    if (datei.is_open()){
        cout << datei.is_open() << endl;
        string line;
        while (getline(datei, line)){
            cout << line << endl;
        }
        datei.close();
    }else cout << "Fehler beim öffnen der Datei!";


    //Assertion
    vector<Bruch> brueche;
    brueche.push_back(Bruch{1,1});
    brueche.push_back(Bruch{3,4});
    brueche.push_back(Bruch{-5,7});
    brueche.push_back(Bruch{-4,-6});
    brueche.push_back(Bruch{0,15});
    brueche.push_back(Bruch{2,3});
    brueche.push_back(Bruch{2,7});
    brueche.push_back(Bruch{-1,-1});
    brueche.push_back(Bruch{15,-15});


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

    return 0;
}
