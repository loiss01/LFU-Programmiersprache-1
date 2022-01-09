// Bruch.hpp

#ifndef BRUCH_HPP_WAS_INCLUDED      // Include-Guard
#define  BRUCH_HPP_WAS_INCLUDED

#include <iostream>
#include <cstdlib>
#include <utility>

constexpr int ggt(int a, int b) noexcept
{
    if (a < 0)
        a = -a;             // jetzt ist sicher a >= 0
    if (b < 0)
        b = -b;             // jetzt ist sicher b >= 0
    if (a < b)              // vertausche a und b mit std::swap()
        std::swap(a, b);    // jetzt ist sicher a >= b >= 0
    
// hier gilt sicher  a >= b >= 0
    for (int r{}; b; a = b, b = r)
        r = a % b;
    return a;
}

struct Bruch {
    int z;
    int n;

    Bruch(int a = 0)    : z{a}, n{1}    {}   // Auch Umwandlung int -> Bruch
    Bruch(int a, int b) : z{a}, n{b}    { normalize(); }

    void normalize() 
    {   if (n == 0) {
            std::cout << "Bruch mit Nenner 0\n";
            exit(1);
        }
        if (n < 0) {
            n = -n;
            z = -z;
        }
        if (auto d = ggt(z, n); d > 1) {
            z /= d;
            n /= d;
        }
    }
};

std::ostream& operator<<(std::ostream& os, Bruch b)
{   if (b.n == 1)
        os << b.z;
    else
        os << '(' << b.z << '/' << b.n << ')'; 
    return os;
}

std::istream& operator>>(std::istream& is, Bruch& b)
{   
    if (int z, n; is >> z >> n)
        b = {z, n};
    return is;
}

Bruch operator+(Bruch a, Bruch b)
{   return {a.z*b.n + a.n*b.z, a.n*b.n}; }  // da Bruch return-Typ ist, genügt die Initialisierung

Bruch operator-(Bruch a, Bruch b)
{   return {a.z*b.n - a.n*b.z, a.n*b.n}; }

Bruch operator-(Bruch a)
{   return {-a.z, a.n}; }

Bruch operator*(Bruch a, Bruch b)
{   return {a.z*b.z, a.n*b.n}; }

Bruch operator/(Bruch a, Bruch b)
{   return {a.z*b.n, a.n*b.z}; }

double to_double(Bruch a)
{   return static_cast<double>(a.z)/a.n; }

#endif  //  BRUCH_HPP_WAS_INCLUDED
