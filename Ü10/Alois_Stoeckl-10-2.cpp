//  Alois Stöckl - Hü 10 - Aufgabe 1

#include "iostream"
#include "cmath"
#include "vector"

using namespace std;

struct Vec2{
    double x{};
    double y{};
};

Vec2 operator-(Vec2 a, Vec2 b){
    Vec2 out;
    out.x = a.x - b.x;
    out.y = a.y - b.y;
    return out;
}


Vec2 operator+(Vec2 a, Vec2 b){
    Vec2 out;
    out.x = a.x + b.x;
    out.y = a.y + b.y;
    return out;
}

Vec2 operator*(double t, Vec2 a){
    return Vec2{a.x * t, a.y * t};
}

Vec2 operator*(Vec2 a, double t){
    return operator*(t,a);
}

// Skalarprodukt
double operator*(Vec2 a, Vec2 b){
    return (a.x * b.x) + (a.y * b.y);
}

double len(Vec2 a){
    return sqrt(a*a);
}

double operator<(Vec2 a, Vec2 b){
    return acos((a*b) / sqrt((a*a) * (b*b)));
}

void operator<<(ostream& os, Vec2 v){
    os << "[ " << v.x << " | " << v.y << " ]" << endl;
}

bool compareX(Vec2 a, Vec2 b){
    return a.x > b.x;
}

bool compareY(Vec2 a, Vec2 b){
    return a.y > b.y;
}

bool compareLeangth(Vec2 a, Vec2 b){
    return len(a) > len(b);
}

int main(){
    cout << "a)" << endl;
    
    // Hab es nicht geschaft mittels eilesen der Datei also hier:
    vector<Vec2> v;
    v.push_back(Vec2{1, 1});
    v.push_back(Vec2{3, 4});
    v.push_back(Vec2{-5, 7});
    v.push_back(Vec2{-4, -6});
    v.push_back(Vec2{0, 15});
    v.push_back(Vec2{2, 3});
    v.push_back(Vec2{2, 7});
    v.push_back(Vec2{-1, -1});
    v.push_back(Vec2{15, -15});

    cout << "b.1)" << endl;

    sort(v.begin(), v.end(), compareX);

    for (Vec2 i : v){
        cout << i;
    }

    cout << "b.2)" << endl;

    sort(v.begin(), v.end(), compareY);

    for (Vec2 i : v){
        cout << i;
    }

    cout << "c)" << endl;

    sort(v.begin(), v.end(), compareLeangth);

    for (Vec2 i : v){
        cout << i;
    }

    cout << "d)" << endl;

    Vec2 summ{0,0};
    for (Vec2 i : v){
        summ = summ + i;
    }

    cout << "Summe aller Vektoren:" << endl;
    cout << summ;


    return 0;
}

