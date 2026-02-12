#include <iostream>
#include <fstream>
#include <cmath>
#include "vector3.h"
#include "ray.h"
#include "sphere.h"

// Hit record
struct HitRecord {
    Vector3 point;
    Vector3 normal;
    double t;
};

// hit_sphere with hit record
bool hit_sphere(const Sphere& sphere, const Ray& r, HitRecord& rec) {
    Vector3 oc = r.origin() - sphere.center;
    double a = dot(r.direction(), r.direction());
    double b = 2.0 * dot(oc, r.direction());
    double c = dot(oc, oc) - sphere.radius * sphere.radius;
    double discriminant = b*b - 4*a*c;

    if (discriminant < 0.0) return false;

    double t = (-b - std::sqrt(discriminant)) / (2.0*a);
    if (t < 0.0) t = (-b + std::sqrt(discriminant)) / (2.0*a);
    if (t < 0.0) return false;

    rec.t = t;
    rec.point = r.at(t);
    rec.normal = (rec.point - sphere.center).normalize();
    return true;
}

// Write color to file (0-255)
void write_color(std::ofstream& out, const Vector3& color) {
    int ir = static_cast<int>(255.999 * color.x);
    int ig = static_cast<int>(255.999 * color.y);
    int ib = static_cast<int>(255.999 * color.z);
    out << ir << " " << ig << " " << ib << "\n";
}

int main() {
    const int WIDTH = 400;
    const int HEIGHT = 400;

    std::ofstream f("test.ppm");
    f << "P3\n" << WIDTH << " " << HEIGHT << "\n255\n";

    // Camera setup
    Vector3 origin(0.0, 0.0, 0.0);
    double viewport_height = 2.0;
    double viewport_width = 2.0;
    double focal_length = 1.0;

    Vector3 horizontal(viewport_width, 0.0, 0.0);
    Vector3 vertical(0.0, viewport_height, 0.0);
    Vector3 lower_left_corner = origin - horizontal/2.0 - vertical/2.0 - Vector3(0.0, 0.0, focal_length);

    // Sphere
    Sphere sphere(Vector3(0.0, 0.0, -1.0), 0.5);

    for (int y = HEIGHT-1; y >= 0; y--) {
        for (int x = 0; x < WIDTH; x++) {
            double u = double(x) / (WIDTH - 1);
            double v = double(y) / (HEIGHT - 1);

            Vector3 direction = lower_left_corner + u*horizontal + v*vertical - origin;
            Ray r(origin, direction);

            Vector3 pixel_color;
            HitRecord rec;

            if (hit_sphere(sphere, r, rec)) {
                pixel_color = 0.5 * Vector3(rec.normal.x + 1.0, rec.normal.y + 1.0, rec.normal.z + 1.0);
            } else {
                Vector3 unit_dir = r.direction().normalize();
                double t = 0.5*(unit_dir.y + 1.0);
                pixel_color = (1.0 - t) * Vector3(1.0, 1.0, 1.0) + t * Vector3(0.5, 0.7, 1.0);
            }

            write_color(f, pixel_color);
        }
    }

    f.close();
    std::cout << "Rendered test.ppm\n";
}
