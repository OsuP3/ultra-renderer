#ifndef SPHERE_H
#define SPHERE_H

#include "ray.h"
#include "hittable.h"

class Sphere : public Hittable
{
private:
    Vector3 m_center;
    float m_radius;
public:
    Sphere(const Vector3& center, float radius);
    Vector3 center() { return m_center;};
    float radius() { return m_radius;};
    bool hit(const Ray& ray, double t_min, double t_max, HitRecord& rec) const override;
};

#endif