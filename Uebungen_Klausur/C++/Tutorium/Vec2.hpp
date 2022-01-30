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