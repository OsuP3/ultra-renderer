#include "sphere.h"
#include <cmath>

Sphere::Sphere(const Vector3& center, float radius) : Hittable()
{
    this->m_center = center;
    this->m_radius = radius;
}

bool Sphere::hit(const Ray& ray, double t_min, double t_max, HitRecord& rec) const
{
    Vector3 oc = (ray.origin() - this->m_center);
    Vector3 D = ray.direction();
    double a = dot(ray.direction(), ray.direction());
    double b = dot(ray.direction(), oc);
    double c = dot(oc, oc) - (this->m_radius * this->m_radius);
    double discriminant = b*b - a*c;

    if (discriminant < 0)
    {
        return false;
    }

    double t = (-b - sqrt(discriminant)) / a;

    if (t < t_min || t > t_max)
    {
        t = (-b + sqrt(discriminant)) / a;
        if (t < t_min || t > t_max)
        {
            return false;
        }
    }

    rec.t = t;
    rec.point = ray.at(t);
    rec.normal = (rec.point - this->m_center).normalize();
    
    // Diffuse shading
    Vector3 light_dir = Vector3(1, 1, -1).normalize();
    double diffuse = 0.3 + 0.7 * fmax(0.0, dot(rec.normal, light_dir));  // brighter ambient
    rec.color = diffuse * Vector3(0.984, 0.953, 0.286); 

    return true;
}
