#ifndef SCENE_H
#define SCENE_H

#include "hittable.h"
#include <vector>


class Scene : public Hittable
{
private:
    std::vector<Hittable*> m_scene;
public:
    void add(Hittable *obj) { this->m_scene.push_back(obj);}
    bool hit(const Ray& ray, double t_min, double t_max, HitRecord& rec) const override
    {
        bool hit_something = false;
        double closest_so_far = t_max;

        for (auto obj : this->m_scene)
        {
            if (obj->hit(ray, t_min, closest_so_far, rec))
            {
                hit_something = true;
                closest_so_far = rec.t;  // only accept closer hits
            }
        }
        return hit_something;
    }
};

#endif