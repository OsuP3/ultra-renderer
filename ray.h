#ifndef RAY_H
#define RAY_H

#include "vector3.h"
#include "time.h"

class Ray
{
private:
    Vector3 m_origin;
    Vector3 m_direction;
    
public:
    Ray();
    Ray(Vector3 origin, Vector3 direction);
    Vector3 direction() const { return m_direction;};
    Vector3 origin() const { return m_origin;};
    Vector3 at(double t) const; // at(t) → origin + t * direction
};

#endif