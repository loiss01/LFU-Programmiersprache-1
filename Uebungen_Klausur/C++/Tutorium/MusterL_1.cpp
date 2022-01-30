#include <iostream>
#include <cstdlib>

#include <cmath> // (i)
#include <vector> // (ii)
#include <numeric> // (v)
#include <algorithm> // (vii)

/* (i) */
#include "Vec2.hpp"

using namespace std;

/* (ii) */
Vec2 rotate(Vec2 v, double phi) {
    return Vec2{v.x*cos(phi)-v.y*sin(phi), v.x*sin(phi)+v.y*cos(phi)};
}

int main() {
    /* (iii) */
    auto v = Vec2{1, 0};

    /* (iv) */
    vector<Vec2> vs;

    for (auto i{0}; i < 8; i += 1) {
        auto phi = i*PI/4.;
        vs.push_back(rotate(v, phi));
    }

    /* (v) */
    for (auto i{0}; i < ssize(vs); i += 2) {
        cout << "vs[" << i << "] = " << vs[i] << endl;
    }

    /* (vi) */
    cout << endl << "Gesamtlaenge aller Vektoren = "
         << accumulate(begin(vs), end(vs), 0u, [](const auto sum, const auto& v){
             return sum + len(v); })
         << endl  << endl;

    /* (vii) */
    Vec2 w{};
    for (auto i{0}; i < 5; i += 1) {
        w = w + vs[i];
    }

    /* (vii)-Alternative für Iterator-Nerds :p*/
    //w = accumulate(begin(vs), next(begin(vs), 5), Vec2{});

    cout << "w = "
         << w
         << endl << endl;

    /* (viii) */
    cout << "Anzahl aller Vektoren mit negativer x- und positiver y-Koordinate = "
         << count_if(begin(vs), end(vs), [](const auto& v){
             return v.x < 0 &&  v.y > 0; }) << endl;

    return EXIT_SUCCESS;
}