//  Alois Stöckl - Hü 9 - Aufgabe 2

#include "iostream"
#include "cmath"

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

int main(){
    cout << "a.)" << endl;

    Vec2 a,b;
    a.x = 1;
    a.y = 2;
    b.y = 1;
    b.x = 2;

    cout << a*b;

    cout << "b.)" << endl;

    a = {3, 4}, b = {-8,6};
    //2 ∗ a, a∗2, ⟨a,b⟩, len(a), Winkel zwischen a und b ausgeben

    cout << 2 * a;
    cout << a * 2;
    cout << a * b << endl;
    cout << len(a) << endl;
    cout << (a < b);

    return 0;
}
