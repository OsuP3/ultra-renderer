#include "vector3.h"

#include <cmath>

Vector3::Vector3()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Vector3::Vector3(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3 Vector3::normalize()
{
    float length = static_cast<float>(sqrt(x*x + y*y + z*z));
    return Vector3(x/length, y/length, z/length);
}

Vector3 operator+(const Vector3& lhs, const Vector3& rhs)
{
    return Vector3(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}

Vector3 operator-(const Vector3& lhs, const Vector3 &rhs)
{
    return Vector3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}

Vector3 operator*(const Vector3& lhs, const float k)
{
    return Vector3(lhs.x * k, lhs.y * k, lhs.z * k);
}
Vector3 operator*(const float k, const Vector3& rhs)
{
    return rhs * k;
}

Vector3 operator*(const Vector3& lhs, double k)
{
    float fk = static_cast<float>(k);
    return Vector3(lhs.x * fk, lhs.y * fk, lhs.z * fk);
}
Vector3 operator*(double k, const Vector3& rhs)
{
    return rhs * k;
}
double dot(const Vector3 &lhs, const Vector3 &rhs)
{
    return (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z);
}

Vector3 operator/(const Vector3& lhs, double t)
{
    return Vector3(lhs.x / t, lhs.y / t, lhs.z / t);
}