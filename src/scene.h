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

        for (auto obj : this->m_scene)
        {
            if (obj->hit(ray, t_min, t_max, rec))
            {
                hit_something = true;
                return hit_something;
            }
        }
        return hit_something;
    }
};

#endif