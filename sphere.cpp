#include "sphere.h"

Sphere::Sphere(Vector3 center, float radius)
{
    this->center = center;
    this->radius = radius;
}
// bool hit_sphere(const Sphere& sphere, const Ray ray, double& t)
// {
//     Vector3 oc = (ray.origin() - sphere.center);
//     Vector3 D = ray.direction();
//     double a = dot(ray.direction(), ray.direction());
//     double b = 2.0f * dot(ray.direction(), oc);
//     double c = dot(oc, oc) - (sphere.radius * sphere.radius);

//     return t > ((-b + sqrt(b*b - 4*a*c))/(2*a));
// }
