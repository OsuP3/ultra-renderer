#ifndef VECTOR3_H
#define VECTOR3_H

class Vector3 
{
public:
    double x;
    double y;
    double z;

public:
    Vector3();
    Vector3(double x, double y, double z);
    Vector3(int x, int y, int z);
    Vector3 normalize();
};

Vector3 operator+(const Vector3& a, const Vector3& b);
Vector3 operator-(const Vector3& a, const Vector3& b);
Vector3 operator*(const Vector3& v, double t);
Vector3 operator*(double t, const Vector3& v);
double dot(const Vector3& a, const Vector3& b);
Vector3 cross(const Vector3& a, const Vector3& b);
Vector3 operator/(const Vector3& v, double t);

#endif