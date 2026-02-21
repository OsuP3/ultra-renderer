#include <iostream>
#include <fstream>
#include <cmath>

#include "camera.h"
#include "scene.h"
#include "sphere.h"
#include "ray.h"
#include "vector3.h"


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
    Vector3 origin(0.0, 0.0, -3.0);
    double viewport_height = 2.0;
    double viewport_width = 2.0;
    double focal_length = 1.0;
    
    Camera camera(origin, viewport_height, viewport_width, focal_length);
    // Sphere
    Scene scene;
    scene.add(new Sphere(Vector3(0.0, 0.0, -5.0), 0.5));
    scene.add(new Sphere(Vector3(0.0, 1.5, -8.5), 0.5));

    for (int y = HEIGHT-1; y >= 0; y--) {
        for (int x = 0; x < WIDTH; x++) {
            double u = double(x) / (WIDTH - 1);
            double v = double(y) / (HEIGHT - 1);

            Vector3 direction = camera.direction(u, v);
            Ray ray(origin, direction);

            Vector3 pixel_color;
            HitRecord rec;
            if (scene.hit(ray, 0, INFINITY, rec)) {
                pixel_color = 0.5 * Vector3(rec.normal.x + 1.0, rec.normal.y + 1.0, rec.normal.z + 1.0);
            }
            else {
                Vector3 unit_dir = ray.direction().normalize();
                double t = 0.5*(unit_dir.y + 1.0);
                pixel_color = (1.0 - t) * Vector3(1.0, 1.0, 1.0) + t * Vector3(0.5, 0.7, 1.0);
            }

            write_color(f, pixel_color);
        }
    }

    f.close();
    std::cout << "Rendered test.ppm\n";
}
