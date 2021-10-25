#include "Scene.h"

Scene::Scene(Camera* camera, std::vector<DrawableObject*> drawable_objects)
{
    this->camera = camera;
    this->drawable_objects = drawable_objects;
}

std::vector<DrawableObject*> Scene::get_drawable_objects()
{
    return this->drawable_objects;
}
