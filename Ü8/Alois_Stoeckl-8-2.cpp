//  Alois Stöckl - Hü 8 - Aufgabe 2

#include "iostream"

using namespace std;


struct Bruch{
    int z{};
    int n{1};
};

/**
 * Operator welcher brüche subtrahiert a-b
 * @param a
 * @param b
 * @return neuer Bruch
 */
Bruch operator-(Bruch a, Bruch b){
    Bruch summe;
    summe.z = a.z * b.n - a.n * b.z;
    summe.n = a.n * b.n;
    return summe;
}

/**
 * Operator welcher brüche addiert a+b
 * @param a
 * @param b
 * @return neuer Bruch
 */
Bruch operator+(Bruch a, Bruch b){
    Bruch summe;
    summe.z = a.z * b.n + a.n * b.z;
    summe.n = a.n * b.n;
    return summe;
}

/**
 * Macht aus einen Positiven Bruch einene Negativ
 * @param a Bruch zum umstellen
 * @return neuer Bruch
 */
Bruch operator-(Bruch a){
    return Bruch{-a.z, a.n};
}

/**
 * senden eine ausgabe von einen Bruch an die console
 * @param b bruch to print
 */
void print(Bruch b){
    cout << "(" << b.z << "/" << b.n << ")" << endl;
}

/**
 * senden eine ausgabe von einen Bruch an die console
 * @param b bruch to print
 */
void operator<<(std::ostream&  os, Bruch b){
    os << "(" << b.z << "/" << b.n << ")" << endl;
}


int main(){
    Bruch a, b, c, d;

    a.z = 4;
    a.n = 3;

    b.z = 2;
    b.n = 3;

    print(a);
    print(b);

    print(a - b);

    cout << "b.)" << endl;

    cout << -a;
    cout << -b;
    cout << -(a+b);
    cout << (-a) + (-b);



    return 0;
}
