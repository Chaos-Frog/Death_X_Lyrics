#include "Vector2.h"
#include <iostream>
using namespace std;
Vector2::Vector2(double x, double y) {
    Vector2::x = x;
    Vector2::y = y;
}

Vector2& Vector2::operator = (const Vector2& v) {
    x = v.x;
    y = v.y;
    return *this;
}
const Vector2 Vector2::operator + (const Vector2& v) const {
    Vector2 addv;
    addv.x = this->x + v.x;
    addv.y = this->y + v.y;
    return addv;
}
const Vector2 Vector2::operator - (const Vector2& v) const {
    Vector2 subv;
    subv.x = this->x - v.x;
    subv.y = this->y - v.y;
    return subv;
}
const Vector2 Vector2::operator * (const Vector2& v) const {
    Vector2 mulv;
    mulv.x = this->x * v.x;
    mulv.y = this->y * v.y;
    return mulv;
}
const Vector2 Vector2::operator / (const Vector2& v) const {
    Vector2 divv;
    divv.x = this->x / v.x;
    divv.y = this->y / v.y;
    return divv;
}
const Vector2 Vector2::operator * (const double& n) const {
    Vector2 mulv;
    mulv.x = this->x * n;
    mulv.y = this->y * n;
    return mulv;
}
const Vector2 Vector2::operator / (const double& n) const {
    Vector2 divv;
    divv.x = this->x / n;
    divv.y = this->y / n;
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
Vector2& Vector2::operator *= (const double& n) {
    x *= n;
    y *= n;
    return *this;
}
Vector2& Vector2::operator /= (const double& n) {
    x /= n;
    y /= n;
    return *this;
}