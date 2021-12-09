#include "Scene.h"
#include "Skybox.h"
#include "MovingObject.h"

Scene::Scene(Camera* camera, std::vector<Light*> lights, std::vector<DrawableObject*> drawable_objects, Skybox* skybox, std::vector<MovingObject*> movable_objects)
{
    this->camera = camera;
    this->lights = lights;
    this->drawable_objects = drawable_objects;
    this->skybox = skybox;
    this->moving_objects = movable_objects;
}

std::vector<DrawableObject*> Scene::get_drawable_objects()
{
    return this->drawable_objects;
}

std::vector<MovingObject*> Scene::get_moving_objects()
{
    return this->moving_objects;
}

void Scene::add_drawable_object(DrawableObject* drawable_object)
{
    this->drawable_objects.push_back(drawable_object);
}

Skybox* Scene::get_skybox()
{
    return skybox;
}

Scene* Scene::create_forest(Camera* camera, std::vector<Light*> lights, DrawableObjectFactory* factory_tangent, DrawableObjectFactory* factory_blinn, Skybox* skybox, MovingObjectFactory* moving_object_factory)
{
    DrawableObject* plain = factory_blinn->create_object(ObjectType::TERRAIN);
    DrawableObject* house = factory_blinn->create_object(ObjectType::HOUSE);
    //DrawableObject* zombie = factory_blinn->create_object(ObjectType::ZOMBIE);
    // corrupts heap, if we create zombie with casting from DrawableObject to MovingObject
    MovingObject* moving_zombie = moving_object_factory->get_moving_zombie();
    DrawableObject* tangent_box = factory_tangent->create_tangent_sphere();

    plain->get_transformation()->scale(glm::vec3(1, 1, 1))->move(glm::vec3(0, 0, 0));
    house->get_transformation()->move(glm::vec3(0, 0, 0));
    //zombie->get_transformation()->move(glm::vec3(0, 0, 25));
    tangent_box->get_transformation()->move(glm::vec3(0, 0, 15));

    return new Scene(camera, lights, std::vector<DrawableObject*>{plain, house, tangent_box}, skybox, std::vector<MovingObject*>{moving_zombie});
}