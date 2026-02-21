#ifndef PLANE_H
#define PLANE_H

#include "ray.h"
#include "hittable.h"

class Plane : public Hittable
{
private:
    Vector3 origin;
    Vector3 v;
    Vector3 w;
public:
    Plane(Vector3 origin, Vector3 v, Vector3 w);
    bool hit(const Ray& ray, double t_min, double t_max, HitRecord& rec) const override;
};

#endif