#include <iostream>
#include <cstdlib>

#include <vector>
#include <algorithm> // (iv)

#include "Vec2.hpp"

using namespace std;

struct Circle {
    Vec2 centre{0, 0};
    double radius{1};

    friend istream& operator>>(istream& is, Circle& c);
    friend ostream& operator<<(ostream& os, const Circle& c);
};

/* (i) */
istream& operator>>(istream& is, Circle& c) {
    Vec2 centre;
    double radius;

    if (cin >> centre >> radius) {
        c = Circle{centre, radius};
    }

    return is;
}

ostream& operator<<(ostream& os, const Circle& c) {
    os << "Kreis{M = "<< c.centre << ", r = " << c.radius << "}";
    return os;
}

/* (iii) */
double area(const Circle& c) {
    return PI*c.radius*c.radius;
}

int main() {
    /* (ii) */
    Circle c{Vec2{3.1, -17}, 5.36};

    cout << c
         << " ist ein Kreis um den Mittelpunkt (3,1, -17) und mit Radius 5,36." << endl << endl;

    /* (iv) */
    // Im PowerShell-Terminal `cmd /c '.\aufgabe_2.exe < .\aufgabe_2_circles.dat'` ausführen
    vector<Circle> cs{Circle{Vec2{0, 0}, 1}, Circle{Vec2{-5, 7}, -15.8}, Circle{Vec2{0, 13}, 57.15}};

    for (Circle c; cin >> c;) {
        cs.push_back(c);
    }

    /* (v) */
    cout << "Anzahl der im Vektor `cs` gespeicherten Kreise = "
         << size(cs) << endl << endl;

    auto max_area_iterator{max_element(begin(cs), end(cs), [](const auto& c_1, const auto& c_2){
        return area(c_1) < area(c_2); })};
    cout << "Der "
         << distance(begin(cs), max_area_iterator) + 1
         << "-te im Vektor `cs` gespeicherte Kreis, "
         << *max_area_iterator
         << ", hat die groesste Flaeche" << endl << endl;

    sort(begin(cs), end(cs), [](const auto& c_1, const auto& c_2){
        return area(c_1) > area(c_2); });
    cout << "Der Kreis "
         << cs[2]
         << " hat die drittgroesste Flaeche aller im Vektor `cs` gespeicherten Kreise" << endl << endl;

    return EXIT_SUCCESS;
}