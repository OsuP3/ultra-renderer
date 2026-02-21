#ifndef CAMERA_H
#define CAMERA_H

#include "vector3.h"

class Camera 
{
private:
    Vector3 m_origin;
    double m_viewport_height;
    double m_viewport_width;
    double m_focal_length;
    
    Vector3 m_horizontal;
    Vector3 m_vertical;
    Vector3 m_lower_left_corner;


public:
    Camera(const Vector3 &origin, double viewport_height, double viewport_width, double focal_length)
    {
        this->m_origin = origin;
        this->m_viewport_height = viewport_height;
        this->m_viewport_width = viewport_width;
        this->m_focal_length = focal_length;

        this->m_horizontal = Vector3(viewport_width, 0.0, 0.0);
        this->m_vertical = Vector3(0.0, viewport_height, 0.0);
        this->m_lower_left_corner = origin - m_horizontal/2.0 - m_vertical/2.0 - Vector3(0.0, 0.0, focal_length);
    }

    Vector3 direction(double u, double v)
    {
        return m_lower_left_corner + u*m_horizontal + v*m_vertical - m_origin;
    }

};


#endif