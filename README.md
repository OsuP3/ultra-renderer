# Ray Tracer

A simple ray tracer written in C++ that renders 3D scenes with spheres and planes.

![Ball bounce animation](demo.gif)

## Features

- Sphere and plane primitives
- Diffuse shading with directional light
- Checkerboard floor texture
- Animation support (frame sequence rendering)
- PPM image output

## Building

Requires `g++` and `ffmpeg`.

```bash
make build      # Compile
make run        # Render animation frames
make video      # Convert frames to MP4
make preview    # Render single preview image
make            # Do all of the above
```

## Usage

```bash
./main.exe              # Render all animation frames to ./frames/
./main.exe --preview    # Render single preview frame
```

## Project Structure

```
src/
├── main.cpp      # Entry point and render loop
├── camera.h      # Camera and viewport
├── scene.h       # Scene container
├── hittable.h    # Base class for hittable objects
├── sphere.cpp/h  # Sphere primitive
├── plane.cpp/h   # Plane primitive
├── ray.cpp/h     # Ray class
└── vector3.cpp/h # 3D vector math
```

## Output

- `frames/` - Animation frames (PPM format)
- `output.mp4` - Rendered video
- `frame-preview.png` - Single frame preview