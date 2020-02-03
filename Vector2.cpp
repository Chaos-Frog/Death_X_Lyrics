#include "Vector2.h"
#include <iostream>
using namespace std;
Vector2::Vector2(double x, double y) {
    Vector2::x = x;
    Vector2::y = y;
}

Vector2 Vector2::operator + (const Vector2& v) {
    Vector2 addv;
    addv.x = this->x + v.x;
    addv.y = this->y + v.y;
    return addv;
}
Vector2 Vector2::operator - (const Vector2& v) {
    Vector2 subv;
    subv.x = this->x - v.x;
    subv.y = this->y - v.y;
    return subv;
}
Vector2 Vector2::operator * (const Vector2& v) {
    Vector2 mulv;
    mulv.x = this->x * v.x;
    mulv.y = this->y * v.y;
    return mulv;
}
Vector2 Vector2::operator / (const Vector2& v) {
    Vector2 divv;
    divv.x = this->x / v.x;
    divv.y = this->y / v.y;
    return divv;
}
Vector2& Vector2::operator += (const Vector2& v) {
    x += v.x;
    y += v.y;
    return *this;
}
Vector2& Vector2::operator -= (const Vector2& v) {
    x -= v.x;
    y -= v.y;
    return *this;
}
Vector2& Vector2::operator *= (const Vector2& v) {
    x *= v.x;
    y *= v.y;
    return *this;
}
Vector2& Vector2::operator /= (const Vector2& v) {
    x /= v.x;
    y /= v.y;
    return *this;
}