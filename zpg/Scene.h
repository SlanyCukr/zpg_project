#ifndef SCENE_H
#define SCENE_H
#include "Camera.h"
#include "DrawableObject.h"
#include "DrawableObjectFactory.h"
#include "MovingObjectFactory.h"

class MovingObject;
class Skybox;
class Scene
{
private:
	std::vector<Light*> lights;
	Camera* camera;
	std::vector<DrawableObject*> drawable_objects;
	std::vector<MovingObject*> moving_objects;
	Skybox* skybox;
public: 
	Scene(Camera* camera, std::vector<Light*> lights, std::vector<DrawableObject*> drawable_objects, Skybox* skybox, std::vector<MovingObject*> moving_objects);
	std::vector<DrawableObject*> get_drawable_objects();
	std::vector<MovingObject*> get_moving_objects();
	void add_drawable_object(DrawableObject* drawable_object);
	Skybox* get_skybox();
	static Scene* create_forest(Camera* camera, std::vector<Light*> lights, DrawableObjectFactory* factory1, DrawableObjectFactory* factory2, Skybox* skybox, MovingObjectFactory* moving_object_factory);
};
#endif
