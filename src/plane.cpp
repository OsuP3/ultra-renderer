#include "plane.h"

#include <math.h>

Plane::Plane(Vector3 origin, Vector3 v, Vector3 w, Vector3 color)
{
    this->origin = origin;
    this->v = v;
    this->w = w;
    this->color = color;
}

bool Plane::hit(const Ray& ray, double t_min, double t_max, HitRecord& rec) const
{
    // r = r0 + sv + tw
    // Solve for s and t, if real solution, hit
    Vector3 n = cross(this->v, this->w);

    if (fabs(dot(n, ray.direction())) < 1e-8)
    {
        return false;
    }

    double t = dot(n, (origin - ray.origin())) / dot(n, ray.direction());

    if (t < t_min || t > t_max)
    {
        return false;
    }

    rec.t = t;
    rec.point = ray.at(t);
    rec.normal = n.normalize();
    
    // Checkerboard pattern
    int check = (int(floor(rec.point.x)) + int(floor(rec.point.z))) % 2;
    rec.color = check ? Vector3(0.9, 0.9, 0.9) : Vector3(0.4, 0.4, 0.4);

    return true;
}
