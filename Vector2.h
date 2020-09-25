#pragma once
class Vector2 {
    private:
    public:
        double x;
        double y;

        Vector2(double x = 0, double y = 0);

        Vector2& operator = (const Vector2& v);
        const Vector2 operator + (const Vector2& v) const;
        const Vector2 operator - (const Vector2& v) const;
        const Vector2 operator * (const Vector2& v) const;
        const Vector2 operator / (const Vector2& v) const;
        const Vector2 operator * (const double& n) const;
        const Vector2 operator / (const double& n) const;
        Vector2& operator += (const Vector2& v);
        Vector2& operator -= (const Vector2& v);
        Vector2& operator *= (const Vector2& v);
        Vector2& operator /= (const Vector2& v);
        Vector2& operator *= (const double& n);
        Vector2& operator /= (const double& n);
};

