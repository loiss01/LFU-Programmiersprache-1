CheatSheat für die C++ Prüfung:
===
---
Headerdatein .hpp:
---

Vec2.hpp als reverence:

```cpp
#ifndef VEC2_HPP
#define VEC2_HPP

#include <iostream>
#include <cmath>

#define PI 3.14159265

struct Vec2 {
    double x{0};
    double y{0};
};

std::istream& operator>>(std::istream& is, Vec2& v) {   
    if (double x, y; is >> x >> y) {
        v = Vec2{x, y};
    }

    return is;
}

std::ostream& operator<<(std::ostream& os, Vec2 v) {
    os << "[ " << v.x << " | " << v.y << " ]";
    return os;
}

Vec2 operator+(Vec2 v_1, Vec2 v_2){
    return {v_1.x + v_2.x, v_1.y + v_2.y};
}

Vec2 operator-(Vec2 v) {
    return {-v.x, -v.y};
}

Vec2 operator-(Vec2 v_1, Vec2 v_2) {
    return v_1+(-v_2);
}

Vec2 operator*(double t, Vec2 v) {
    return {t*v.x, t*v.y};
}

Vec2 operator*(Vec2 v, double t) {
    return t*v;
}

double operator*(Vec2 v_1, Vec2 v_2) {
    return v_1.x*v_2.x + v_1.y*v_2.y;
}

double len(Vec2 v) {
    return std::sqrt(v*v);
}

double operator<(Vec2 v_1, Vec2 v_2) {
    return std::acos((v_1*v_2) / std::sqrt((v_1*v_1)*(v_2*v_2))) * 180.0 / PI;
}

#endif
```

Aufbau einer Klasse in C++:
---

```cpp
class Printer {
private:
    std::string name;
    int papier_vorrat;
    int papier_verbraucht;
    int seiten_gedruckt;
    int stoerungen;
    std::vector<Druckjob> log;
    
public:
    Printer(std::string n)
    : name{n}, papier_vorrat(1'000), papier_verbraucht{},
        seiten_gedruckt{}, stoerungen{}, log{}
    {}
    
    ~Printer()  { print_log(); }
    
    void print_log(ostream& os = std::cout) const
    {   os << *this << "\nLogfile\n";
        for (int i{}; auto& j: log)
            os << ++i << ": " << j << '\n';
    }
    
    void reload_paper()
    {   papier_vorrat = 1000; }
    
    void print_job(const Druckjob& pj)
    {   int papier{pj.seiten}; // was ist mit doppelseitig
                
        seiten_gedruckt += pj.seiten;
        papier_verbraucht += papier;
        papier_vorrat -= papier;
        log.push_back(pj);
    }
       
    friend ostream& operator<<(ostream& os, const Printer& p) 
    {   os << "Drucker " << p.name
           << ":\n\tSeiten gedruckt: " << p.seiten_gedruckt
           << "\n\tPapier verbraucht: " << p.papier_verbraucht
           << "\n\tPapiervorrat: " << p.papier_vorrat
           << "\n\tAnzall Druckjobs: " << std::size(p.log)
           << "\n\tStoerungen: " << p.stoerungen;
        return os << '\n';
    }
};
```

---
Wichtige Include Library:
---
Sind meinsten voraussetzung um die Aufgaben zu lösen. 
```cpp
#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include "vector"
#include <cmath> // (i)
#include <vector> // (ii)
#include <numeric> // (v)
#include <algorithm> // (vii)
#include <random>
#include <cstdlib>

```

Wichtige Algorithm:
---

```cpp

//accumulate:
//bsp.:
accumulate(begin(vs), end(vs), 0u, [](const auto sum, const auto& v){
             return sum + len(v); });

accumulate(begin(v), end(v), Bruch{}) << endl;

accumulate(begin(pruefungen), end(pruefungen), 0., [](double sum, const Pruefung& p){ return sum + p.lv.ec; });

accumulate(begin(x), end(x), 0u, [](auto maximum, auto element){ return max(maximum, element); })

//Count_IF:
count_if(begin(vs), end(vs), [](const auto& v){
return v.x < 0 &&  v.y > 0; });

cout << endl << "Der Nenner ist "
<< count_if(begin(v), end(v), [](auto b) {
return b.n == 282; }) << " Mal gleich 282" << endl;

count_if(begin(x), end(x), [](auto element){ return element > 10'000u; })

//Reverse
reverse(c.buchungen.begin(), c.buchungen.end());

//Sort:
sort(begin(v), end(v), [](auto b_1, auto b_2) {
return to_double(b_1) < to_double(b_2); });

//Min / Max Element:
cout << endl << "Kleinster Bruch: "
<< *min_element(begin(v), end(v), [](auto b_1, auto b_2){
return to_double(b_1) < to_double(b_2); });

cout << endl << "Groesster Bruch: "
<< *max_element(begin(v), end(v), [](auto b_1, auto b_2){
return to_double(b_1) < to_double(b_2); }) << endl;




```

Daten aus einer file einlesen:
---

```cpp
istream& operator>>(istream& is, Gemeinde& g) {
     is >> g.name >> g.bezirk >> g.e1981 >> g.e1991 >> g.e2001 >> g.e2011 >> g.e2021;
     return is;
}
// Im PowerShell-Terminal `cmd /c '.\aufgabe_1.exe < .\aufgabe_1_gemeinden.dat'` ausführen
// in der main
vector<Gemeinde> v;

for (Gemeinde i; cin >> i;) {
    v.push_back(i);
}
    
cout << endl << "Anzahl der Gemeinden: " << size(v) << endl;

```
---
Nummereische Aufgaben:
===

Median:
---

```cpp
cout << endl << "Median der eingelesenen Bruche: ";
if (anzahl_bruche % 2 == 0) {
    cout << (v[anzahl_bruche/2-1] + v[anzahl_bruche/2])/2;
} else {
    cout << v[anzahl_bruche/2];
}
```

Mittelwert:
---
```cpp
double mean{s.sum/s.n};
```

Varianz:
---
```cpp
double variance{(s.sum_squares - s.n*mean*mean)/(s.n - 1)};
```

---

Simple Stat Struct:
---

```cpp
struct SimpleStat {
    string title{"SimpleStat ohne Name"};

    int n{0};
    double sum{0};

    double sum_squares{0};
};
```

Normaler osstream:
---

```cpp
ostream& operator<<(ostream& os, const Student& s) {
    os << s.matrikel << "  " << s.name << ':';
    for (auto& p: s.pruefungen) {
        os << endl << "\t" << p;
    }

    return os << endl;
}
```

Aufgabe mit einer Rand funktion:
---

```cpp
#include <iostream>
#include <cstdlib>

#include <iomanip>
#include <random>
#include <array>

/* (a) */
#include "SimpleStat.hpp"

using namespace std;

mt19937_64 g;

SimpleStat multiple_choice_test(double probability_of_success = 0.88, int trails = 10'000, int questions = 12) {
    SimpleStat s{"Multiple-Choice Resultat bei " + to_string(probability_of_success*100) + "%iger Sicherheit"};
    binomial_distribution<int> draw_sample_binomial_distribution{4, probability_of_success};

    for (int index_trails{0}; index_trails < trails; index_trails += 1) {
        int total_points{0};

        for (int index_questions{0}; index_questions < questions; index_questions += 1) {
            auto richtig = draw_sample_binomial_distribution(g);

            if (richtig == 4) {
                total_points += 3;
            } else if (richtig == 3) {
                total_points += 1;
            }
        }

        s += total_points;
    }

    return s;
}
   
int main() {
    for (auto probability_of_success : {0.88, 0.5, 1.0}) {
        cout << multiple_choice_test(probability_of_success) << endl;
    }
    
    return EXIT_SUCCESS;
}
```
