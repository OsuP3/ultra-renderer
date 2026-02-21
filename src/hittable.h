#ifndef HITTABLE_H
#define HITTABLE_H

#include "vector3.h"
#include "ray.h"

struct HitRecord {
    Vector3 point;
    Vector3 normal;
    Vector3 color;
    double t;
};

class Hittable
{
public:
    virtual bool hit(const Ray& ray, double t_min, double t_max, HitRecord& rec) const = 0;
    virtual ~Hittable() = default;
};

#endif