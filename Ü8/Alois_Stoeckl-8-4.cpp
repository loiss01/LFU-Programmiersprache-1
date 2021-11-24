//  Alois Stöckl - Hü 8 - Aufgabe 4

#include "iostream"

using namespace std;


struct Vec2{
    int x{};
    int y{};
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


void operator<<(ostream& os, Vec2 v){
    os << "[ " << v.x << " | " << v.y << " ]" << endl;
}


int main(){

    Vec2 a,b,c,d;

    cout << "a.)" << endl;

    a.x = 2;
    a.y = 2;

    b.x = 2;
    b.y = 3;

    cout << a + b;
    cout << a - b;

    cout << "b.)" << endl;

    a.x = 0;
    a.y = 0;

    b.x = 0;
    b.y = 2;

    c.x = 3;
    c.y = 2;

    d.x = 3;
    d.y = 0;


    cout << "AB = " << b - a;
    cout << "BC = " << c - b;
    cout << "CD = " << d - c;
    cout << "DA = " << a - d;

    return 0;
}
