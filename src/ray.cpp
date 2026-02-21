#include "ray.h"

Ray::Ray(Vector3 origin, Vector3 direction)
{
    this->m_direction = direction;
    this->m_origin = origin;
}

Vector3 Ray::at(double t) const{
    return this->origin() + (t * this->direction());
}