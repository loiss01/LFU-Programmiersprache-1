//  Alois Stöckl - Hü 9 - Aufgabe 1

#include "iostream"

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

double to_double(Bruch br){
    return (double) br.zaehler / br.nenner;
}

int main(){
    cout << "a.)" << endl;
    Bruch a,b,c,d,e;
    a.nenner = 1;
    b.nenner = 3;
    c.nenner = 5;
    d.nenner = 7;
    e.nenner = 9;

    cout << a + b + c + d + e;

    cout << "b.)" << endl;

    Bruch berechung;
    for (int i = 3; i <= 9; i = i + 2) {
        Bruch f;
        f.zaehler = 1;
        f.nenner = i;
        //cout << f;
        berechung = berechung + f;
    }

    cout << berechung;
    cout << "c.)" << endl;

    cout << to_double(berechung);

    return 0;
}
