//  Alois Stöckl - Hü 8 - Aufgabe 3

#include "iostream"
#include "cstdlib"

using namespace std;


struct Bruch{
    int z{};
    int n{1};
};

/**
 * Operator welcher brüche multipliziert a-b
 * @param a
 * @param b
 * @return neuer Bruch
 */
Bruch operator*(Bruch a, Bruch b){
    Bruch summe;
    summe.z = a.z * b.z;
    summe.n = a.n * b.n;
    return summe;
}

/**
 * Operator um bruche zu dividieren a/b
 * @param a
 * @param b
 * @return neuer Bruch
 */
Bruch operator/(Bruch a, Bruch b){
    Bruch s;
    s.z = a.z * b.n;
    s.n = a.n * b.z;
    return s;
}

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
void operator<<(std::ostream&  os, Bruch b){
    if (b.n == 1){
        os << b.z;
    }else{
        os << "(" << b.z << "/" << b.n << ")" << endl;
    }
}

int main(){

    Bruch a, b, c;

    a.z = 4;
    a.n = 3;

    b.z = 2;
    b.n = 3;

    cout << a * b;
    cout << a / b;
    cout << (-a) * (-b);

    cout << "b.)" << endl;

    c.z = 2;

    cout << c;

    return 0;
}
