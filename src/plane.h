#ifndef PLANE_H
#define PLANE_H

#include "hittable.h"
#include "ray.h"
#include "vector3.h"

class Plane : public Hittable
{
private:
    Vector3 origin;
    Vector3 v;
    Vector3 w;
    Vector3 color;
public:
    Plane(Vector3 origin, Vector3 v, Vector3 w, Vector3 color = Vector3(0.5, 0.5, 0.5));
    bool hit(const Ray& ray, double t_min, double t_max, HitRecord& rec) const override;
};

#endif