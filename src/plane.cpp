#include "plane.h"

Plane::Plane(Vector3 origin, Vector3 v, Vector3 w)
{
    this->origin = origin;
    this->v = v;
    this->w = w;
}

bool Plane::hit(const Ray& ray, double t_min, double t_max, HitRecord& rec) const
{
    // r = r0 + sv + tw
    // Solve for s and t, if real solution, hit


    return false;
}
