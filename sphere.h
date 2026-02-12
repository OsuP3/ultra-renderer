#ifndef SPHERE_H
#define SPHERE_H

#include "ray.h"
#include <math.h>

class Sphere
{
public:
    Vector3 center;
    float radius;
public:
    Sphere(Vector3 center, float radius);

};

//bool hit_sphere(const Sphere& sphere, const Ray ray, double& t);

#endif