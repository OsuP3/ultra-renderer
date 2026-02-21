#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

#include "camera.h"
#include "plane.h"
#include "ray.h"
#include "scene.h"
#include "sphere.h"
#include "vector3.h"


const int WIDTH = 400;
const int HEIGHT = 400;

// Write color to file (0-255)
void write_color(std::ofstream& out, const Vector3& color) 
{
    int ir = static_cast<int>(255.999 * color.x) % 256;
    int ig = static_cast<int>(255.999 * color.y) % 256;
    int ib = static_cast<int>(255.999 * color.z) % 256;
    out << ir << " " << ig << " " << ib << "\n";
}

void renderFrame(std::ofstream &f, Camera &camera, Scene &scene)
{
    for (int y = HEIGHT-1; y >= 0; y--) 
    {
        for (int x = 0; x < WIDTH; x++) 
        {
            double u = double(x) / (WIDTH - 1);
            double v = double(y) / (HEIGHT - 1);

            Vector3 direction = camera.direction(u, v);
            Ray ray(camera.origin(), direction);

            Vector3 pixel_color;
            HitRecord rec;
            if (scene.hit(ray, 0, INFINITY, rec)) {
                pixel_color = rec.color;
            }
            else {
                Vector3 unit_dir = ray.direction().normalize();
                double t = 0.5*(unit_dir.y + 1.0);
                pixel_color = (1.0 - t) * Vector3(1.0, 1.0, 1.0) + t * Vector3(0.5, 0.7, 1.0);
            }

            write_color(f, pixel_color);
            }
        }
}

int main(int argc, char *argv[]) {

    // Camera setup
    Vector3 origin(0.0, 0.0, -3.0);
    double viewport_height = 4.0;
    double viewport_width = 4.0;
    double focal_length = 3.0;
    
    Camera camera(origin, viewport_height, viewport_width, focal_length);

    // Scene setup
    Scene scene;
    //scene.add(new Sphere(Vector3(0.0, 0.0, -5.0), 0.5));
    
    Vector3 startPos = Vector3(0.0, 2.0, -8.5);
    Sphere *sphere2 = new Sphere(startPos, 0.5);
    scene.add(sphere2);

    // Floor plane at y = -1, spanning x and z directions
    scene.add(new Plane(Vector3(0.0, -1.0, -5.0), Vector3(1.0, 0.0, 0.0), Vector3(0.0, 0.0, -1.0)));

    // Viewport preview
    if (argc == 2 && (std::string(argv[1]) == "--preview"))
    {
        std::ofstream f("./frame-preview.ppm");
        f << "P3\n" << WIDTH << " " << HEIGHT << "\n255\n";
        renderFrame(f, camera, scene);
        f.close();
        return f.bad();
    }

    // Ball bounce
    const int nframes = 300;
    for (int fr = 0; fr < nframes; fr++) 
    {
        std::string filename = "./frames/frame-" + std::to_string(fr) + ".ppm";
        std::ofstream f(filename);
        f << "P3\n" << WIDTH << " " << HEIGHT << "\n255\n";

        float t = fr / (float)nframes;
        // Bounce using abs(sin) - 3 bounces with decreasing height
        camera.set_origin(camera.origin() + Vector3(0.01, 0.005, 0.01));
        float bounce_height = fabs(sin(t * 3.14159 * nframes/30)) * (1.0 - t * 0.5);
        sphere2->set_center(Vector3(startPos.x, -0.5 + bounce_height, startPos.z));

        
        renderFrame(f, camera, scene);
    
        f.close();
    }

    // // Camera floating up
    // for (int fr = nframes; fr < nframes*2; fr++) 
    // {
    //     std::string filename = "./frames/frame-" + std::to_string(fr) + ".ppm";
    //     std::ofstream f(filename);
    //     f << "P3\n" << WIDTH << " " << HEIGHT << "\n255\n";

    //     float t = fr/60.0;
    //     camera.set_origin(camera.origin() + Vector3(0.0, 0.05, 0.0));
        
    //     renderFrame(f, camera, scene);
    
    //     f.close();
    // }
    std::cout << "Rendered frames\n";
}
